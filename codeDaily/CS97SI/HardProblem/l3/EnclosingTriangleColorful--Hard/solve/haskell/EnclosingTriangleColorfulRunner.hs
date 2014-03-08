import TopCoder
import System.Environment (getArgs)
import System.IO
import EnclosingTriangleColorful

getVars :: Parser (Int, [Int], [Int])
getVars = do m <- spaces >> parseInt ; next
             x <- spaces >> (parseList parseInt) ; next
             y <- spaces >> (parseList parseInt)
             return (m, x, y) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (m, x, y) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ getNumber m x y
            hClose hOut
    hClose hIn
