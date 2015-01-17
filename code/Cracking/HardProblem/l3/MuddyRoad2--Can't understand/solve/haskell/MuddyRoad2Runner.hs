import TopCoder
import System.Environment (getArgs)
import System.IO
import MuddyRoad2

getVars :: Parser (Int, Int)
getVars = do n <- spaces >> parseInt ; next
             muddyCount <- spaces >> parseInt
             return (n, muddyCount) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (n, muddyCount) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ theCount n muddyCount
            hClose hOut
    hClose hIn
