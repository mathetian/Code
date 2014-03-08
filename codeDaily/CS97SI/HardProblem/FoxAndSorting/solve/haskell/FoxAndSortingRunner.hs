import TopCoder
import System.Environment (getArgs)
import System.IO
import FoxAndSorting

getVars :: Parser (Integer)
getVars = do idx <- spaces >> parseLong
             return (idx) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (idx) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ get idx
            hClose hOut
    hClose hIn
