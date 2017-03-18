reverseList = helper []
	where 
		helper acc [] = acc
		helper acc (x:xs) = helper (x:acc) xs