#include"RoomMaker.h"

RoomMaker::RoomMaker(GameMap& gm) : m_GameMap(gm) {}
void RoomMaker::MakeRoom(Point buildPoint, unsigned int size)
{
	m_GameMap.SetTile(buildPoint, Tile::Floor);

	for (auto p : buildPoint.AdjPoints())
		if (m_GameMap.GetTile(p) == Tile::Empty)
			m_GameMap.SetTile(p, Tile::Wall); 
			
	for (auto p : buildPoint.DiagPoints())
		m_GameMap.SetTile(p, Tile::Wall); 

}
