module Main where
import System.Environment
import Text.ParserCombinators.Parsec
import Control.Monad
import Control.Monad.Error
import System.IO hiding (try)

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
eval (List [Atom "if", pred, conseq, alt]) = do
	result <- eval pred
	case result of
	  Bool False -> eval alt
	  otherwise -> eval conseq
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
			  ("reminder", numericBinop rem),
			  ("=", numBoolBinop (==)),
			  ("<", numBoolBinop (<)),
			  (">", numBoolBinop (>)),
			  ("/=", numBoolBinop (/=)),
			  (">=", numBoolBinop (>=)),
			  ("<=", numBoolBinop (<=)),
			  ("&&", boolBoolBinop (&&)),
			  ("||", boolBoolBinop (||)),
			  ("string=?", strBoolBinop (==)),
			  ("string<?", strBoolBinop (<)),
			  ("string>?", strBoolBinop (>)),
			  ("string<=?", strBoolBinop (<=)),
			  ("string>=?", strBoolBinop (>=)),
			  ("car", car),
	          ("cdr", cdr),
	          ("cons", cons),
	          ("eqv", eqv),
	          ("equal", equal)
	          ]

numBoolBinop = boolBinop unpackNum
strBoolBinop = boolBinop unpackStr
boolBoolBinop = boolBinop unpackBool

numericBinop :: (Integer -> Integer -> Integer) -> [LispVal] -> ThrowsError LispVal
numericBinop op singleVal@[_] = throwError $ NumArgs 2 singleVal
numericBinop op params = mapM unpackNum params >>= return  . Number . foldl1 op

boolBinop :: (LispVal -> ThrowsError a) -> (a -> a -> Bool) -> [LispVal] -> ThrowsError LispVal
boolBinop unpacker op args = if length args /= 2
								 then throwError $ NumArgs 2 args
								 else do 
								 	left <- unpacker $ args !! 0
								 	right <- unpacker $ args !! 1
								 	return $ Bool $ left `op` right

unpackNum :: LispVal -> ThrowsError Integer
unpackNum (Number n) = return n
unpackNum (String n) = let parsed = reads n in
							if null parsed 
								then throwError $ TypeMismatch "number" $ String n
								else return $ fst $ parsed !! 0
unpackNum (List [n]) = unpackNum n
unpackNum notNum = throwError $ TypeMismatch "number" notNum

unpackStr :: LispVal -> ThrowsError String
unpackStr (String s) = return s
unpackStr (Number s) = return $ show s 
unpackStr (Bool s) = return $ show s
unpackStr notString = throwError $ TypeMismatch "string" notString

unpackBool :: LispVal -> ThrowsError Bool
unpackBool (Bool b) = return b
unpackBool notBool = throwError $ TypeMismatch "boolean" notBool

readExpr :: String -> ThrowsError LispVal
readExpr input = case parse parseExpr "lisp" input of
	Left err -> throwError $ Parser err
	Right val -> return val

trapError action =  catchError action (return . show)

extractValue :: ThrowsError a -> a
extractValue (Right val) = val

car :: [LispVal] -> ThrowsError LispVal
car [List (x:xs)] = return x
car [DottedList (x:xs) _] = return x
car [badArg] = throwError $ TypeMismatch "pair" badArg
car badArgList = throwError $ NumArgs 1 badArgList

cdr :: [LispVal] -> ThrowsError LispVal
cdr [List (x:xs)] = return  $ List xs
cdr [DottedList (_ : xs) x] = return  $ DottedList xs x
cdr [DottedList [xs] x] = return x
cdr [badArg] = throwError $ TypeMismatch "pair" badArg
cdr badArgList = throwError $ NumArgs 1 badArgList

cons :: [LispVal] -> ThrowsError LispVal
cons [x1, List []] = return $ List [x1]
cons [x, List xs] = return  $ List $ [x] ++ xs
cons [x, DottedList xs xlast] = return  $ DottedList ([x] ++ xs) xlast
cons [x1, x2] = return $ DottedList [x1] x2
cons badArgList = throwError $ NumArgs 2 badArgList

eqv :: [LispVal] -> ThrowsError LispVal
eqv [(Bool arg1), (Bool arg2)] = return  $ Bool $ arg1 == arg2
eqv [(Number arg1), (Number arg2)] = return  $ Bool $ arg1 == arg2
eqv [(String arg1), (String arg2)] = return  $ Bool $ arg1 == arg2
eqv [(Atom arg1), (Atom arg2)] = return $ Bool $ arg1 == arg2
eqv [(DottedList xs x), (DottedList ys y)] = eqv [List $ xs ++ [x], List $ ys ++ [y]]
eqv [(List arg1), (List arg2)] = 
	return  $ Bool $(length arg1 == length arg2) && 
			(and $ map eqvPair $ zip arg1 arg2)
		where eqvPair (x1, x2) = case eqv [x1, x2] of
									Left err -> False
									Right (Bool val) -> val
eqv [_, _] = return $ Bool False
eqv badArgList = throwError $ NumArgs 2 badArgList

data Unpacker = forall a. Eq a => AnyUnpacker (LispVal -> ThrowsError a)

unpackEquals :: LispVal -> LispVal -> Unpacker -> ThrowsError Bool
unpackEquals arg1 arg2 (AnyUnpacker unpacker) =
	do unpacked1 <- unpacker arg1
	   unpacked2 <- unpacker arg2
	   return $ unpacked1 == unpacked2
	`catchError` (const $ return False)

equal :: [LispVal] -> ThrowsError LispVal
equal [arg1, arg2] = do 
	primitiveEquals <- liftM or $ mapM (unpackEquals arg1 arg2)
					   [AnyUnpacker unpackNum,
					   	AnyUnpacker unpackStr,
					   	AnyUnpacker unpackBool]
	eqvEquals <- eqv [arg1, arg2]
	return $ Bool $ (primitiveEquals || let (Bool x) = eqvEquals in x)
equal badArgList = throwError $ NumArgs 2 badArgList

flushStr :: String -> IO ()
flushStr str = putStr str >> hFlush stdout

readPrompt :: String -> IO String
readPrompt prompt = flushStr prompt >> getLine

evalString :: String -> IO String
evalString expr =  return $ extractValue $ trapError (liftM show $ readExpr expr >>= eval)

evalAndPrint :: String -> IO ()
evalAndPrint expr =evalString expr >>=putStrLn

until_ :: Monad m => (a -> Bool) -> m a -> (a -> m ()) -> m ()
until_ pred prompt action = do
	result <- prompt
	if pred result
		then return ()
		else action result >> until_ pred prompt action

runRepl :: IO ()
runRepl = until_ (== "quit") (readPrompt "Lisp>>> ") evalAndPrint

main :: IO ()
main = do 
		args <- getArgs
		case length args of
			0 -> runRepl
			1 -> evalAndPrint $ args !! 0 
			otherwise -> putStrLn "Program take 0 or 1 argument"