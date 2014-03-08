import TopCoder
import System.Environment (getArgs)
import System.IO
import LittleElephantAndXor

getVars :: Parser (Int, Int, Int)
getVars = do a <- spaces >> parseInt ; next
             b <- spaces >> parseInt ; next
             c <- spaces >> parseInt
             return (a, b, c) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (a, b, c) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ getNumber a b c
            hClose hOut
    hClose hIn
