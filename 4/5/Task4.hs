data Expression = Const Int
					| Variable
					| Expression :+: Expression
					| Expression :-: Expression
					| Expression :*: Expression
					| Expression :/: Expression
	deriving Show

derivate :: Expression -> Expression
derivate = simplify . derivation

derivation :: Expression -> Expression
derivation (Const _)       = Const 0
derivation Variable        = Const 1
derivation (exp1 :+: exp2) = derivation exp1 :+: derivation exp2
derivation (exp1 :-: exp2) = derivation exp1 :-: derivation exp2
derivation (exp1 :*: exp2) = (derivation exp1 :*: exp2) :+: (exp1 :*: derivation exp2)
derivation (exp1 :*: exp2) = ((derivation exp1 :*: exp2) :-: (exp1 :*: derivation exp2)) :/: (exp2 :*: exp2)

simplify :: Expression -> Expression
simplify (exp1 :+: exp2)        = simplify exp1 :+: simplify exp2
simplify (exp1 :*: exp2)        = simplify exp1 :*: simplify exp2
simplify (exp1 :-: exp2)        = simplify exp1 :-: simplify exp2
simplify (exp1 :/: exp2)        = simplify exp1 :/: simplify exp2
simplify (Const 1 :*: exp)      = exp
simplify (exp :*: Const 1)      = exp
simplify exp                    = exp
simplify (exp :/: Const 1)      = exp
simplify (Const 0 :*: exp) = Const 0
simplify (exp :*: Const 0) = Const 0
