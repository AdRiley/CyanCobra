#include <map>
#include <memory>

#include "GameMap.h"
#include "Player.h"

class GameMapView
{
public:
    virtual ~GameMapView() {}
    virtual void DrawMap(const GameMap& gameMap) = 0;
    virtual void DrawMapAndPlayer(const GameMap& gameMap, const Player& player) = 0;
};
