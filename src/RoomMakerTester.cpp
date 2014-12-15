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
			THEN("The other 3 sides and the corners are walls")
			{
				REQUIRE(gm.GetTile(buildPoint.Left()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Down()) == Tile::Wall);
				
				REQUIRE(gm.GetTile(buildPoint.Left().Down()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right().Down()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Left().Up()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right().Up()) == Tile::Wall);
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
				
				REQUIRE(gm.GetTile(buildPoint.Left().Down()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right().Down()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Left().Up()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right().Up()) == Tile::Wall);
			}
	    }
	}
}

SCENARIO("A room request of size 1 makes a room with doors")
{
	GIVEN("A map with a build point with a door left and a RoomMaker")
	{
	    GameMap gm{2, 2};
	    Point buildPoint{1, 1};
	    gm.SetTile(buildPoint.Left(), Tile::ClosedDoor);
	    RoomMaker rm(gm);
	    WHEN("We make a room of size 1 at point p with 1 door")
	    {
			rm.MakeRoom(buildPoint, 1, 1);
			THEN("Point p is floor")
			{
				REQUIRE(gm.GetTile(buildPoint) == Tile::Floor);
			}
			THEN("The door is still a door")
			{
				REQUIRE(gm.GetTile(buildPoint.Left()) == Tile::ClosedDoor);
			}
			THEN("The other 3 sides and the corners are walls")
			{
				REQUIRE(gm.GetTile(buildPoint.Up()) == Tile::ClosedDoor);
				REQUIRE(gm.GetTile(buildPoint.Right()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Down()) == Tile::Wall);
				
				REQUIRE(gm.GetTile(buildPoint.Left().Down()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right().Down()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Left().Up()) == Tile::Wall);
				REQUIRE(gm.GetTile(buildPoint.Right().Up()) == Tile::Wall);
			}
	    }
	}
}
