import qualified Data.Set as S


data Vehicle = ACar Car | ATruck Truck
data Car   = Car {model::String, color::String, cbrand::String, cprice::Int}
data Truck = Truck {tbrand::String, weight::Int, tprice::Int}

sumPrice vehicles = sum $ map getPrice vehicles where
    getPrice vehicle = 
      case vehicle of
        ACar car ->  cprice car
        ATruck truck -> tprice truck

getBrands vehicles =  (S.toList . S.fromList) $ map getBrand vehicles where
    getBrand vehicle = 
      case vehicle of
        ACar car ->  cbrand car
        ATruck truck -> tbrand truck