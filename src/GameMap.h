enum class Tile
{
    Empty,
    Floor
};

class GameMap
{
    Tile m_Map;
public:
    GameMap();
    GameMap(Tile t);
    Tile GetTile(int x, int y);
};
