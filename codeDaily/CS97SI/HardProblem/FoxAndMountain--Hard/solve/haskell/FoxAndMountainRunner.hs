import TopCoder
import System.Environment (getArgs)
import System.IO
import FoxAndMountain

getVars :: Parser (Int, String)
getVars = do n <- spaces >> parseInt ; next
             history <- spaces >> parseString
             return (n, history) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (n, history) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ count n history
            hClose hOut
    hClose hIn
