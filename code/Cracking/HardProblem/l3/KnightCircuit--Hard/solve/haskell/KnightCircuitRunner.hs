import TopCoder
import System.Environment (getArgs)
import System.IO
import KnightCircuit

getVars :: Parser (Int, Int, Int, Int)
getVars = do w <- spaces >> parseInt ; next
             h <- spaces >> parseInt ; next
             a <- spaces >> parseInt ; next
             b <- spaces >> parseInt
             return (w, h, a, b) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (w, h, a, b) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ maxSize w h a b
            hClose hOut
    hClose hIn
