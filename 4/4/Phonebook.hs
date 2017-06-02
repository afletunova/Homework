import System.IO
import Control.Exception
import System.Directory

doLoop :: [(String, Integer)] -> IO ()
doLoop ls = do
    showCommands
    command <- getLine
    case command of
        '0':_ -> return ()
        '1':_ -> do 
            putStrLn "Enter name: "
            name <- getLine
            putStrLn "Enter number: "
            number <- getLine
            doLoop $ (name, (read number :: Integer)) : ls
        '2':_ -> do 
            putStrLn "Enter name: "
            name <- getLine
            putStrLn $ "Number of " ++ name ++ ": " ++ (findByName ls name)
            doLoop ls
        '3':_ -> do 
            putStrLn "Enter number: "
            number <- getLine
            putStrLn $ "Name with " ++ number ++ ": " ++ (findByNumber ls (read number :: Integer))
            doLoop ls
        '4':_ -> do
            putStrLn "Enter file name: "
            fileName <- getLine
            writeToFile fileName ls
            doLoop ls
        '5':_ -> do
            putStrLn "Enter file name: "
            fileName <- getLine
            isExist <- doesFileExist fileName
            if (isExist == True) then do
                readingString <- readFile fileName
                removeFile fileName
                doLoop (fromUnparsedString (lines readingString))
            else putStrLn (show fileName ++ "does not exist") >> doLoop ls
        _ -> doLoop ls

showCommands :: IO()
showCommands = do 
    putStrLn "Enter a command:"
    putStrLn "0 - exit"
    putStrLn "1 - add record (name and number)"
    putStrLn "2 - find number by name"
    putStrLn "3 - find name by number"
    putStrLn "4 - save current data to file"
    putStrLn "5 - read data from file"

findByName :: [([Char], Integer)] -> [Char] -> [Char]
findByName [] _ = "There are no such records"
findByName (l:ls) name = if name == fst l then show $ snd l else findByName ls name

findByNumber :: [([Char], Integer)] -> Integer -> [Char]
findByNumber [] _ = "There are no such records"
findByNumber (l:ls) number = if number == snd l then show $ fst l else findByNumber ls number

writeToFile :: FilePath -> [(String, Integer)] -> IO()
writeToFile fileName ls = do 
    bracket (openFile fileName WriteMode) hClose (\h -> writeList h ls)

writeList :: Handle -> [(String, Integer)] -> IO()
writeList _ [] = return ()
writeList h (l:ls) = do
    hPutStrLn h $ fst l
    hPutStrLn h $ show $ snd l
    writeList h ls

readFromFile :: FilePath -> IO [(String, Integer)]
readFromFile fileName = do
    records <- readFile fileName 
    return $ toList records 

toList :: String -> [(String, Integer)]
toList dt = helper $ lines dt
    where
        helper [] = []
        helper (x:y:ls) | ls == []  = [(x, read y :: Integer)]
                        | otherwise = (x, read y :: Integer) : helper ls

fromUnparsedString :: [String] -> [(String, Integer)]
fromUnparsedString []       = []
fromUnparsedString (s:n:es) = (s,read n) : fromUnparsedString es 

main :: IO()
main = doLoop []