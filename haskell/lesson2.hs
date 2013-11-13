module Main where
import System.Environment
import Text.ParserCombinators.Parsec
import Control.Monad
import Control.Monad.Error

symbol :: Parser Char
symbol = oneOf "!$%&|*+-/:<=>?@^_~#"

space1 :: Parser ()
space1 =  skipMany1 space

data LispVal = Atom String
			 | List [LispVal]
			 | DottedList [LispVal] LispVal
			 | Number Integer
			 | String String
			 | Bool Bool

parseString :: Parser LispVal
parseString = do 
				char '"'
				x <- many (noneOf "\"")
				char '"'
				return $ String x

parseAtom :: Parser LispVal
parseAtom =  do 
				first <- letter <|> symbol
				rest <- many(letter <|> digit <|> symbol)
				let atom = [first] ++ rest
				return $ case atom of
					"#t" -> Bool True
					"#f" -> Bool False
					otherwise -> Atom atom

parseNumber :: Parser LispVal
parseNumber = liftM (Number . read) $ many1 digit

parseList :: Parser LispVal
parseList = liftM List $ sepBy parseExpr space1

parseDottedList :: Parser LispVal
parseDottedList = do
	head <- endBy parseExpr space1
	tail <- char '.' >> space1 >> parseExpr
	return $ DottedList head tail

parseQuoted :: Parser LispVal
parseQuoted = do
			char '\''
			x <- parseExpr
			return $ List [Atom "quoted", x]

parseExpr :: Parser LispVal
parseExpr = parseAtom
		<|> parseString
		<|> parseNumber
		<|> parseQuoted
		<|> do
			 char '('
			 x <- (try parseList) <|> parseDottedList
			 char ')'
			 return x

unwordsList :: [LispVal] -> String
unwordsList = unwords . map showVal

showVal :: LispVal -> String
showVal (String contents) = "\"" ++ contents ++ "\""
showVal (Atom name) = name
showVal (Number contents) =  show contents
showVal (Bool True) = "#t"
showVal (Bool False) = "#f"
showVal (List contents) = "(" ++ unwordsList contents ++ ")"
showVal (DottedList head tail) = "(" ++ unwordsList head ++ " ." ++ showVal tail ++ ")"

instance Show LispVal where show = showVal

data LispError = NumArgs Integer [LispVal]
			   | TypeMismatch String LispVal
			   | Parser ParseError
			   | BadSpeciaForm String LispVal
			   | NotFunction String String
			   | UnboundVar String String
			   | Default String

showError :: LispError -> String
showError (UnboundVar message varname) = message ++ ": " ++ varname
showError (BadSpeciaForm message form) = message ++ ": " ++ show form
showError (NotFunction message func) = message ++ ": " ++ show func
showError (NumArgs expected found) = "Expected " ++ show expected ++ " args;found values " ++ unwordsList found 
showError (Parser parseErr) = "Parse error at " ++ show parseErr

instance Show LispError where show = showError

instance Error LispError where
	noMsg =  Default "An error has occurred"
	strMsg = Default

type ThrowsError = Either LispError

eval :: LispVal -> ThrowsError LispVal
eval val@(String _) = return val
eval val@(Number _) = return val
eval val@(Bool _) = return val
eval (List [Atom "quoted", val]) = return val
eval (List (Atom func : args)) = mapM eval args >>= apply func
eval badForm = throwError $ BadSpeciaForm "Unrecognized special form" badForm

apply :: String -> [LispVal] -> ThrowsError LispVal
apply func args = maybe (throwError $ NotFunction "Unrecognized primitives function args" func)
				  		($ args)
				  		(lookup func primitives)

primitives :: [(String, [LispVal] -> ThrowsError LispVal)]
primitives = [("+", numericBinop (+)),
			  ("-", numericBinop (-)),
			  ("*", numericBinop (*)),
			  ("/", numericBinop div),
			  ("mod", numericBinop mod),
			  ("quotient", numericBinop quot),
			  ("reminder", numericBinop rem)]

numericBinop :: (Integer -> Integer -> Integer) -> [LispVal] -> ThrowsError LispVal
numericBinop op singleVal@[_] = throwError $ NumArgs 2 singleVal
numericBinop op params = mapM unpackNum params >>= return  . Number . foldl1 op

unpackNum :: LispVal -> ThrowsError Integer
unpackNum (Number n) = return n
unpackNum (String n) = let parsed = reads n in
							if null parsed 
								then throwError $ TypeMismatch "number" $ String n
								else return $ fst $ parsed !! 0
unpackNum (List [n]) = unpackNum n
unpackNum notNum = throwError $ TypeMismatch "number" notNum

readExpr :: String -> ThrowsError LispVal
readExpr input = case parse parseExpr "lisp" input of
	Left err -> throwError $ Parser err
	Right val -> return val

trapError action =  catchError action (return . show)

extractValue :: ThrowsError a -> a
extractValue (Right val) = val


main = do
		args <- getArgs
		evaled <- return $ liftM show $ readExpr (args !! 0) >>= eval
		putStrLn $ extractValue $ trapError evaled