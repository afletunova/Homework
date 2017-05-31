data Polynomial = Polynomial [Integer]

instance Show Polynomial where
	show (Polynomial []) = "" 
	show (Polynomial (a:as))
		| as == [] && a == 0 = ""
		| as == []           = show a
		|  a == 0            = "" ++ show (Polynomial as)
		|  a == 1  			 = "x" ++ degree as ++ "+" ++ show (Polynomial as)
		|  otherwise  		 = show a ++ "x" ++ degree as ++ "+" ++ show (Polynomial as)

degree ls 
    | length ls == 1 = ""
    | otherwise      = "^" ++ show (length ls)

multiPol :: [Integer] -> [Integer] -> [Integer]
multiPol [] (_:bs) = 0 : multiPol [] bs
multiPol _ [] = []
multiPol (a:as) bs = zipWith (+) (map (a *) bs ++ replicate (length as) 0) (0 : multiPol as bs)

instance Num Polynomial where
    (+) (Polynomial a) (Polynomial b) = Polynomial (zipWith (+) a b)
    (-) (Polynomial a) (Polynomial b) = Polynomial (zipWith (-) a b)
    (*) (Polynomial a) (Polynomial b) = Polynomial (multiPol a b)

    abs (Polynomial a) = Polynomial (map abs a)
    signum = error "There is no sign"
    fromInteger = error "There is no possibility"
