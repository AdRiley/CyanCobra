#include "test.h"
#include "GameMap.h"
#include "RoomMaker.h"

SCENARIO("A room request of size 1 makes a room")
{
	GIVEN("A map with a build point with a door above and a RoomMaker")
	{
	    GameMap gm{2, 2};
	    Point buildPoint{1, 1};
	    gm.SetTile(buildPoint.Up(), Tile::ClosedDoor);
	    RoomMaker rm(gm);
	    WHEN("We make a room of size 1 at point p")
	    {
			rm.MakeRoom(buildPoint, 1);
			THEN("Point p is floor")
			{
				REQUIRE(gm.GetTile(buildPoint) == Tile::Floor);
			}
			THEN("The door is still a door")
			{
				REQUIRE(gm.GetTile(buildPoint.Up()) == Tile::ClosedDoor);
			}
			THEN("The other 3 sides are walls")
			{
				REQUIRE(gm.GetTile(buildPoint.Left()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Down()) == Tile::Wall);
			}
	    }
	}
	
	GIVEN("A map with a build point with a door below and a RoomMaker")
	{
	    GameMap gm{2, 2};
	    Point buildPoint{1, 1};
	    gm.SetTile(buildPoint.Down(), Tile::ClosedDoor);
	    RoomMaker rm(gm);
	    WHEN("We make a room of size 1 at point p")
	    {
			rm.MakeRoom(buildPoint, 1);
			THEN("Point p is floor")
			{
				REQUIRE(gm.GetTile(buildPoint) == Tile::Floor);
			}
			THEN("The door is still a door")
			{
				REQUIRE(gm.GetTile(buildPoint.Down()) == Tile::ClosedDoor);
			}
			THEN("The other 3 sides are walls")
			{
				REQUIRE(gm.GetTile(buildPoint.Left()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Up()) == Tile::Wall);
			}
	    }
	}
}
