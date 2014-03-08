import TopCoder
import System.Environment (getArgs)
import System.IO
import PolygonTraversal2

getVars :: Parser (Int, [Int])
getVars = do n <- spaces >> parseInt ; next
             points <- spaces >> (parseList parseInt)
             return (n, points) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (n, points) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ count n points
            hClose hOut
    hClose hIn
