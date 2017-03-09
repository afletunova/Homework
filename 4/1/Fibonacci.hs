fibonacci :: Integer -> Integer 
fibonacci n | n == 0    = 0
            | n == 1    = 1
            | otherwise = helper 0 1 n

helper :: Integer -> Integer -> Integer -> Integer                                                                                                                                  
helper a b n | n == 0    = a
             | n > 0     = helper b (b + a) (n - 1)
             | otherwise = helper b (a - b) (n + 1)