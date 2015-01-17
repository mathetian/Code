import TopCoder
import System.Environment (getArgs)
import System.IO
import WolfInZooDivTwo

getVars :: Parser (Int, [String], [String])
getVars = do n <- spaces >> parseInt ; next
             l <- spaces >> (parseList parseString) ; next
             r <- spaces >> (parseList parseString)
             return (n, l, r) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (n, l, r) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ count n l r
            hClose hOut
    hClose hIn
