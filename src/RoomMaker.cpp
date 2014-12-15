#include"RoomMaker.h"

RoomMaker::RoomMaker(GameMap& gm) : m_GameMap(gm) {}
void RoomMaker::MakeRoom(Point p, unsigned int size)
{
	std::vector<Point> vAvailablePoints;
	m_GameMap.SetTile(p, Tile::Floor);
	m_GameMap.SetTile(p.Down(), Tile::Wall);
	m_GameMap.SetTile(p.Left(), Tile::Wall);
	m_GameMap.SetTile(p.Right(), Tile::Wall);
}
