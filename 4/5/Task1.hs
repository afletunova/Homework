decompose :: Integer -> [[Integer]]
decompose n = helper n 1 where 
	helper n k | n == 0  = [[]]
			   | n < 0   = error "Not positive number"
               | otherwise = [n] : concatMap (\x -> map (\y -> x : y) (decompose $ n - x)) [1 .. (n - 1)]