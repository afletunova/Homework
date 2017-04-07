validityCheck :: [a] -> (a -> Bool) -> Bool
validityCheck [] f = True
validityCheck (x:xs) f 
			| f x == True = validityCheck xs f
			| otherwise   = False