#include <map>
#include <memory>

#include "Display.h"
#include "GameMap.h"
#include "Player.h"

class GameMapView
{
private:
    std::shared_ptr<Display> m_Display;
    std::map<Tile, char> m_TileSymbol;
public:
    GameMapView(std::shared_ptr<Display> display);
    void DrawMap(const GameMap& gameMap);
    void DrawMapAndPlayer(const GameMap& gameMap, const Player& player);
private:
    void RenderMap(const GameMap& gameMap);
    void RenderPlayer(const Player& player);
};
