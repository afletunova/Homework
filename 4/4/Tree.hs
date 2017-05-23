import Data.Foldable
import Data.Monoid

data Tree a = Nil | Leaf a | Node (Tree a) a (Tree a) deriving Show

instance Foldable Tree where
    foldMap f Nil = mempty
    foldMap f (Leaf x) = f x
    foldMap f (Node l x r) = foldMap f l `mappend` f x `mappend` foldMap f r

traversal :: Tree a -> [a]
traversal = foldMap (\x -> [x])