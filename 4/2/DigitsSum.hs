digitsSum :: Integer -> Integer

digitsSum x | x >= 0 = helper x
            | otherwise = helper (abs x)
	    where 
	    	helper 0 = 0
		helper x = x `mod` 10 + helper (x `div` 10)
