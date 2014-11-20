#include <iostream>

#include "CursesDisplay.h"
#include "GameMap.h"
#include "GameMapView.h"

int main(void)
{
    GameMap gm{
              {Tile::Empty, Tile::Wall , Tile::Wall , Tile::Wall , Tile::Wall , Tile::Wall , Tile::Wall , Tile::Wall , Tile::Empty},
              {Tile::Empty, Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall , Tile::Empty},
              {Tile::Wall , Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall , Tile::Wall },
              {Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall },
              {Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall },
              {Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall },
              {Tile::Wall , Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall , Tile::Wall },
              {Tile::Empty, Tile::Wall , Tile::Wall , Tile::Wall , Tile::Floor, Tile::Wall , Tile::Wall , Tile::Wall , Tile::Empty},
              {Tile::Empty, Tile::Wall , Tile::Wall , Tile::Floor, Tile::Floor, Tile::Floor, Tile::Wall , Tile::Wall , Tile::Empty},
              {Tile::Empty, Tile::Empty, Tile::Wall , Tile::Wall , Tile::Floor, Tile::Wall , Tile::Wall , Tile::Empty, Tile::Empty},
              {Tile::Empty, Tile::Empty, Tile::Empty, Tile::Wall , Tile::Wall , Tile::Wall , Tile::Empty, Tile::Empty, Tile::Empty},
              {Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Wall , Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty}
              };
    std::shared_ptr<CursesDisplay> display{std::make_shared<CursesDisplay>()};
    GameMapView gmv{display};
    gmv.DrawMap(gm);
    int x;
    std::cin >> x;
    return 0;
}

