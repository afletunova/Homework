searchPos l = searcher l 1 1 0
    where 
        searcher [_] n _ _ = n
        searcher (x:y:xs) n m acc
            | (x + y) > acc = searcher (y:xs) m (m + 1) (x + y)
            | otherwise = searcher (y:xs) n (m + 1) acc