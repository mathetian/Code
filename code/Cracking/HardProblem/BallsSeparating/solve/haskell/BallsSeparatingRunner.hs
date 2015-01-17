import TopCoder
import System.Environment (getArgs)
import System.IO
import BallsSeparating

getVars :: Parser ([Int], [Int], [Int])
getVars = do red <- spaces >> (parseList parseInt) ; next
             green <- spaces >> (parseList parseInt) ; next
             blue <- spaces >> (parseList parseInt)
             return (red, green, blue) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (red, green, blue) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ minOperations red green blue
            hClose hOut
    hClose hIn
