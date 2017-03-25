import Data.List (transpose)

sumThreeLists :: Num a => [a] -> [a] -> [a] -> [a]
sumThreeLists x y z = map sum $ transpose [x,y,z]