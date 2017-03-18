findNumPos :: [Int] -> Int -> Int

findNumPos xs n = finder xs n 1
	where
		finder [] n p = error "This list does not contain this number."
		finder (x:xs) n p 
			| x == n = p
			| otherwise = finder xs n (p + 1)