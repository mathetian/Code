import TopCoder
import System.Environment (getArgs)
import System.IO
import ThreeColorabilityEasy

getVars :: Parser ([String])
getVars = do cells <- spaces >> (parseList parseString)
             return (cells) 

main = do 
    args <- getArgs
    hIn <- openFile (head args) ReadMode
    contents <- hGetContents hIn
    case (parse getVars "variables" contents) of
        Left err -> print err
        Right (cells) -> do
            hOut <- openFile (head (tail args)) WriteMode
            hPutStr hOut $ show $ isColorable cells
            hClose hOut
    hClose hIn
