import Control.Monad.Random

randomizeList ls = mapM (const $ getRandomR (1,100)) ls