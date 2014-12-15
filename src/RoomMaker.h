#include "GameMap.h"
#include "Point.h"

class RoomMaker
{
private:
	GameMap& m_GameMap;
public:
	RoomMaker(GameMap& gm);
	void MakeRoom(Point p, unsigned int size);
};
