multiPairs :: Integer -> [Integer]

multiPairs n = [1..n] >>= (\x -> map (x *) [1..n])