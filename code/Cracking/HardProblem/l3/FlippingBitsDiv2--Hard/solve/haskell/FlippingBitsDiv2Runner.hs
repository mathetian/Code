import TopCoder
import System.Environment (getArgs)
import System.IO
import FlippingBitsDiv2

getVars :: Parser ([String], Int)
getVars = do s <- spaces >> (parseList parseString) ; next
             m <- spaces >> parseInt
             return (s, m) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (s, m) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ getmin s m
            hClose hOut
    hClose hIn
