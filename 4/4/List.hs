add :: Integer -> [Integer] -> [Integer]
add a [] = [a]
add a (x:xs)
	| a >= x    = (x:(add a xs))
	| otherwise = (a:x:xs)

remove :: Integer -> [Integer] -> [Integer]
remove a [] = []
remove a (x:xs) 
	| a == x    = xs
	| otherwise = (x:(remove a xs))

doLoop :: [Integer] -> IO ()
doLoop ls = do
	putStrLn "Enter a command: "
	command <- getLine
	case command of
		'0':_ -> return ()
		'1':_ -> do 
			putStrLn "Enter a value: "
			v <- readLn
			doLoop $ add v ls
		'2':_ -> do 
			putStrLn "Enter a value: "
			v <- readLn
			doLoop $ remove v ls
		'3':_ -> do 
			putStrLn $ show ls
			doLoop ls
		_ : _ -> doLoop ls

main = do 
	putStrLn "0 - exit"
	putStrLn "1 - add value to sorted list"
	putStrLn "2 - remove value from list"
	putStrLn "3 - print list"
	doLoop []
