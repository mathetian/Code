import TopCoder
import System.Environment (getArgs)
import System.IO
import DengklekPaintingSquares

getVars :: Parser (Int, Int)
getVars = do n <- spaces >> parseInt ; next
             m <- spaces >> parseInt
             return (n, m) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (n, m) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ numSolutions n m
            hClose hOut
    hClose hIn
