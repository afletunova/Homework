import Foreign.Marshal.Utils

countEven :: [Int] -> Int
countEven = sum . map (\x -> if even x then 1 else 0)

countEven' :: [Int] -> Int
countEven' = length . filter even

countEven'' :: [Int] -> Int
countEven'' = foldr ((+) . (fromBool . even)) 0
