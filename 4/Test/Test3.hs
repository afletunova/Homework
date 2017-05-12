import Data.List

square n = [replicate n 'x'] ++ (replicate (n-2) helper) ++ [replicate n 'x'] where
  helper = "x" ++ (replicate (n-2) '_') ++ "x"
    

main = putStrLn  $ intercalate "\n" $ square 5