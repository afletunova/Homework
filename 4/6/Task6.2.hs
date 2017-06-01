data Tree a = Nil | Node (Tree a) a (Tree a) 
	deriving Show

insert :: (Ord a) => Tree a -> a -> Tree a
insert Nil x = Node Nil x Nil
insert (Node l v r) x 
    | v == x = Node l v r
    | v  < x = Node l v (insert r x)
    | v  > x = Node (insert l x) v r

delete :: (Ord a) => Tree a -> a -> Tree a
delete Nil _ = Nil
delete (Node l v r) x  
    | x == v = deleteRoot (Node l v r)
    | x  < v = Node (delete l x) v r
    | x  > v = Node l v (delete r x)

deleteRoot :: (Ord a) => Tree a -> Tree a 
deleteRoot (Node Nil v r) = r
deleteRoot (Node l v Nil) = l
deleteRoot (Node l v r) = (Node l w r)
    where 
        w = leftistElement r

leftistElement :: (Ord a) => Tree a -> a
leftistElement (Node Nil v _) = v
leftistElement (Node l _ _) = leftistElement l

contains :: (Ord a) => (Tree a) -> a -> Bool
contains Nil _ = False
contains (Node l v r) x 
    | x == v = True
    | x  < v = contains l x 
    | x  > v = contains r x

size :: Tree a -> Int 
size Nil = 0
size (Node l _ r) = 1 + (size l) + (size r)

height :: Tree a -> Int
height Nil = 0 
height (Node l _ r) = 1 + max (height l) (height r)

preorder :: (Ord a) => Tree a -> [a]
preorder Nil = []
preorder (Node l v r) = [v] ++ preorder l ++ preorder r

tree = Node (Node (Node (Node Nil 4 Nil) 5 (Node Nil 6 Nil)) 7 Nil) 8 (Node Nil 9 Nil)