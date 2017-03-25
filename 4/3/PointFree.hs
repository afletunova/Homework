--original 
--func x l = map (\y -> y*x) l 

--eta-conversion
--func x = map (\y -> y*x) 

--functional style 
--func x = map (\y -> (*x) y) 

--eta-conversion 
--func x = map (*x) 

--function composition 
--func x = (map . (*)) x 

--eta-conversion 
--func = map . (*) 

func = map . (*)