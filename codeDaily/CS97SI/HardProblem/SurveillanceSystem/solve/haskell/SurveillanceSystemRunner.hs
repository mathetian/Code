import TopCoder
import System.Environment (getArgs)
import System.IO
import SurveillanceSystem

getVars :: Parser (String, [Int], Int)
getVars = do containers <- spaces >> parseString ; next
             reports <- spaces >> (parseList parseInt) ; next
             l <- spaces >> parseInt
             return (containers, reports, l) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (containers, reports, l) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ getContainerInfo containers reports l
            hClose hOut
    hClose hIn
