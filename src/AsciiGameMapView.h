#include <map>
#include <memory>

#include "GameMapView.h"
#include "Display.h"

class AsciiGameMapView : public GameMapView
{
private:
    std::shared_ptr<Display> m_Display;
    std::map<Tile, char> m_TileSymbol;
public:
    AsciiGameMapView(std::shared_ptr<Display> display);
    virtual void DrawMap(const GameMap& gameMap);
    virtual void DrawMapAndPlayer(const GameMap& gameMap, const Player& player);
private:
    void RenderMap(const GameMap& gameMap);
    void RenderPlayer(const Player& player);
};
