#include "test.h"
#include "GameMap.h"
#include "RoomMaker.h"

SCENARIO("A room request of size 1 makes a room")
{
	GIVEN("A map with a door and a RoomMaker")
	{
	    GameMap gm{2, 2};
	    gm.SetTile({1, 2}, Tile::ClosedDoor);
	    RoomMaker rm(gm);
	    WHEN("We make a room of size 1 at point p")
	    {
			Point p{1, 1};
			rm.MakeRoom(p, 1);
			THEN("Point p is floor")
			{
				REQUIRE(gm.GetTile(p) == Tile::Floor);
			}
			THEN("The door is still a door")
			{
				REQUIRE(gm.GetTile({1, 2}) == Tile::ClosedDoor);
			}
			THEN("The other 3 sides are walls")
			{
				REQUIRE(gm.GetTile({1, 0}) == Tile::Wall);
				REQUIRE(gm.GetTile({0, 1}) == Tile::Wall);
				REQUIRE(gm.GetTile({2, 1}) == Tile::Wall);
			}
	    }
	}
}
