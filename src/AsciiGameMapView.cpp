#include <memory>
#include "AsciiGameMapView.h"

AsciiGameMapView::AsciiGameMapView(std::shared_ptr<Display> display) :
    m_Display{display},
    m_TileSymbol{{Tile::Floor , '.'},
                 {Tile::Wall  , '#'},
                 {Tile::Empty , ' '},
                 {Tile::Player, '@'},
                 {Tile::ClosedDoor, '\\'}}
{}

void AsciiGameMapView::DrawMap(const GameMap& gameMap)
{
    m_Display->ClearScreen();
    RenderMap(gameMap);
    m_Display->RefreshScreen();
}

void AsciiGameMapView::DrawMapAndPlayer(const GameMap& gameMap, const Player& player)
{
    m_Display->ClearScreen();
    RenderMap(gameMap);
    RenderPlayer(player);
    m_Display->RefreshScreen();
}

void AsciiGameMapView::RenderMap(const GameMap& gameMap)
{
    for (int x{gameMap.GetMinX()}; x <= gameMap.GetMaxX(); ++x)
        for (int y{gameMap.GetMinY()}; y <= gameMap.GetMaxY(); ++y)
            m_Display->DrawTile(x, y, m_TileSymbol[gameMap.GetTile(x,y)]);
}

void AsciiGameMapView::RenderPlayer(const Player& player)
{
    m_Display->DrawTile(player.GetX(), player.GetY(), m_TileSymbol[Tile::Player]);
}
