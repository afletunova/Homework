import Control.Monad

firstMax :: [Integer] -> Maybe Integer
firstMax ls
	| length ls < 3 = Nothing
	| otherwise 	= if (y > x && y > z) then Just y else Nothing `mplus` firstMax (y:z:xs)
		where (x:y:z:xs) = ls