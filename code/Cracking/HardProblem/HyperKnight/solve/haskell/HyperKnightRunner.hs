import TopCoder
import System.Environment (getArgs)
import System.IO
import HyperKnight

getVars :: Parser (Int, Int, Int, Int, Int)
getVars = do a <- spaces >> parseInt ; next
             b <- spaces >> parseInt ; next
             numRows <- spaces >> parseInt ; next
             numColumns <- spaces >> parseInt ; next
             k <- spaces >> parseInt
             return (a, b, numRows, numColumns, k) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (a, b, numRows, numColumns, k) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ countCells a b numRows numColumns k
            hClose hOut
    hClose hIn
