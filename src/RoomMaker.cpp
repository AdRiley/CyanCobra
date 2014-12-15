#include"RoomMaker.h"

RoomMaker::RoomMaker(GameMap& gm) : m_GameMap(gm) {}
void RoomMaker::MakeRoom(Point p, unsigned int size)
{
	std::vector<Point> vAvailablePoints;
	m_GameMap.SetTile(p, Tile::Floor);
	m_GameMap.SetTile({p.x+1, p.y}, Tile::Wall);
	m_GameMap.SetTile({p.x, p.y-1}, Tile::Wall);
	m_GameMap.SetTile({p.x-1, p.y}, Tile::Wall);
}
