import TopCoder
import System.Environment (getArgs)
import System.IO
import MountainsEasy

getVars :: Parser ([String], Int)
getVars = do picture <- spaces >> (parseList parseString) ; next
             n <- spaces >> parseInt
             return (picture, n) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (picture, n) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ countPlacements picture n
            hClose hOut
    hClose hIn
