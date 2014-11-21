#include <iostream>

#include "CursesDisplay.h"
#include "CursesInput.h"
#include "GameMap.h"
#include "GameEngine.h"
#include "AsciiGameMapView.h"

int main(void)
{
    std::shared_ptr<GameMap> gm{std::make_shared<GameMap>(std::initializer_list<std::initializer_list<Tile>>{
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
              }
              )};
    std::shared_ptr<Player> player{std::make_shared<Player>(4, 4)};
    std::shared_ptr<CursesDisplay> display{std::make_shared<CursesDisplay>()};
    std::shared_ptr<AsciiGameMapView> gmv{std::make_shared<AsciiGameMapView>(display)};
    std::shared_ptr<CursesInput> input{std::make_shared<CursesInput>()};
    GameEngine ge{input, player, gm, gmv};
    gmv->DrawMapAndPlayer(*gm, *player);
    while(ge.ProcessCommand()) {}

    return 0;
}

