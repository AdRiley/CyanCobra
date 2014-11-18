#include <memory>
#include "GameMapView.h"

GameMapView::GameMapView(std::shared_ptr<Display> display) :
    m_Display{display},
    m_TileSymbol{{Tile::Floor, '.'},
                 {Tile::Wall , '#'},
                 {Tile::Empty, ' '}}
{}

void GameMapView::DrawMap(const GameMap& gameMap)
{
    m_Display->ClearScreen();

    for (int x{gameMap.GetMinX()}; x <= gameMap.GetMaxX(); ++x)
        for (int y{gameMap.GetMinY()}; y <= gameMap.GetMaxY(); ++y)
            m_Display->DrawTile(x, y, m_TileSymbol[gameMap.GetTile(x,y)]);

    m_Display->RefreshScreen();
}
