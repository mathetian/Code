import TopCoder
import System.Environment (getArgs)
import System.IO
import FoxPaintingBalls

getVars :: Parser (Integer, Integer, Integer, Int)
getVars = do r <- spaces >> parseLong ; next
             g <- spaces >> parseLong ; next
             b <- spaces >> parseLong ; next
             n <- spaces >> parseInt
             return (r, g, b, n) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (r, g, b, n) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ theMax r g b n
            hClose hOut
    hClose hIn
