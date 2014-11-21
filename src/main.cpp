#include <iostream>

#include "CursesDisplay.h"
#include "GameMap.h"
#include "AsciiGameMapView.h"

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
    Player player{4, 4};
    std::shared_ptr<CursesDisplay> display{std::make_shared<CursesDisplay>()};
    AsciiGameMapView gmv{display};
    gmv.DrawMapAndPlayer(gm, player);
    int x;
    std::cin >> x;
    return 0;
}

