validation :: String -> Bool

validation xs = check 0 0 0 [] xs == 0
	where 
		check n m k ls [] = abs(n) + abs(m) + abs(k)
		check n m k ls (x:xs)
			| n < 0     = n
			| m < 0     = m
			| k < 0     = k
			| x == ')' && (ls == ['{'] || ls == ['[']) 
						= m + k
			| x == '}' && (ls == ['('] || ls == ['[']) 
						= n + k
			| x == ']' && (ls == ['('] || ls == ['{']) 
						= n + m
			| x == '('  = check (n + 1) m k ['('] xs
			| x == ')'  = check (n - 1) m k [')'] xs
			| x == '['  = check n (m + 1) k ['['] xs
			| x == ']'  = check n (m - 1) k [']'] xs
			| x == '{'  = check n m (k + 1) ['{'] xs
			| x == '}'  = check n m (k - 1) ['}'] xs
			| otherwise = check n m k ls xs  