#include <vector>

enum class Tile
{
    Empty,
    Floor,
    Wall
};

class GameMap
{
    std::vector<std::vector<Tile>> m_Map;
public:
    GameMap();
    GameMap(Tile t);
    GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles);
    Tile GetTile(int x, int y);
};


