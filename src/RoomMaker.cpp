#include"RoomMaker.h"

RoomMaker::RoomMaker(GameMap& gm) : m_GameMap(gm) {}
void RoomMaker::MakeRoom(Point buildPoint, unsigned int size, unsigned int NumberOfDoors /*= 0*/)
{
	m_GameMap.SetTile(buildPoint, Tile::Floor);

	std::vector<Point> availablePoints;
	for (auto p : buildPoint.AdjPoints())
		if (m_GameMap.GetTile(p) == Tile::Empty)
			availablePoints.push_back(p);

	unsigned int i = 0;
	for (auto p : availablePoints)
	{
		if (i < NumberOfDoors)
		{
			m_GameMap.SetTile(p, Tile::ClosedDoor); 
			++i;
		}
		else
		{
			m_GameMap.SetTile(p, Tile::Wall); 
		}
	}

	for (auto p : buildPoint.DiagPoints())
		m_GameMap.SetTile(p, Tile::Wall); 

}
