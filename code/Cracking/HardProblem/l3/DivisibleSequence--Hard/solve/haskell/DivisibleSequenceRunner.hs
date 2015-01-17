import TopCoder
import System.Environment (getArgs)
import System.IO
import DivisibleSequence

getVars :: Parser (Int, Int)
getVars = do n <- spaces >> parseInt ; next
             h <- spaces >> parseInt
             return (n, h) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (n, h) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ count n h
            hClose hOut
    hClose hIn
