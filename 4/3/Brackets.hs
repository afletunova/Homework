validation :: String -> Bool

validation xs = check xs []
	where
		check [] s = (length s == 0)
		check ('(':xs) s = check xs ('(':s)
		check ('{':xs) s = check xs ('{':s)
		check ('[':xs) s = check xs ('[':s)
		check (')':xs) ('(':s) = check xs s
		check ('}':xs) ('{':s) = check xs s
		check (']':xs) ('[':s) = check xs s
		check (')':xs) s = False
		check ('}':xs) s = False
		check (']':xs) s = False
		check (x:xs) s = check xs s
