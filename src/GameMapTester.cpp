#include "test.h"
#include "GameMap.h"

SCENARIO("Empty game map")
{
    GIVEN("An empty game map")
    {
        GameMap gMap{{}};
        THEN("a requested tile is empty")
        {
            REQUIRE(gMap.GetTile({0,0}) == Tile::Empty);
        }
    }
}

SCENARIO("A game map with a single tile returns that tile")
{
    GIVEN("A game map with one floor tile")
    {
        GameMap gMap{{Tile::Floor}};
        THEN("it returns a floor tile")
        {
            REQUIRE(gMap.GetTile({0,0}) == Tile::Floor);
        }
    }
}

SCENARIO("Game Map Getters")
{
    GIVEN("a defined game map")
    {
        GameMap gMap{{Tile::Floor, Tile::Floor},
                     {Tile::Wall,  Tile::Floor},
                     {Tile::Floor, Tile::Wall }};
        THEN("it returns the correct tiles")
        {
            REQUIRE(gMap.GetTile({0,0}) == Tile::Floor);
            REQUIRE(gMap.GetTile({1,0}) == Tile::Floor);
            REQUIRE(gMap.GetTile({0,1}) == Tile::Wall);
            REQUIRE(gMap.GetTile({1,1}) == Tile::Floor);
            REQUIRE(gMap.GetTile({0,2}) == Tile::Floor);
            REQUIRE(gMap.GetTile({1,2}) == Tile::Wall);
        }
        THEN("it returns empty tile for requests off the map")
        {
            REQUIRE(gMap.GetTile({-1, 0}) == Tile::Empty);
            REQUIRE(gMap.GetTile({ 0,-1}) == Tile::Empty);
            REQUIRE(gMap.GetTile({ 1, 3}) == Tile::Empty);
            REQUIRE(gMap.GetTile({ 2, 2}) == Tile::Empty);
        }
        THEN("it returns its bounds")
        {
            REQUIRE(gMap.GetMinX() == 0);
            REQUIRE(gMap.GetMaxX() == 1);
            REQUIRE(gMap.GetMinY() == 0);
            REQUIRE(gMap.GetMaxY() == 2);
        }
    }
}

SCENARIO("Game Map Setters")
{
    GIVEN("a defined game map")
    {
        GameMap gMap{{Tile::Floor, Tile::Floor},
                     {Tile::Wall,  Tile::Floor},
                     {Tile::Floor, Tile::Wall }};
        WHEN("it is set to another map")
        {
            gMap.SetMap({{Tile::Floor}});
            THEN("it returns the new range")
            {
                REQUIRE(gMap.GetMinX() == 0);
                REQUIRE(gMap.GetMaxX() == 0);
                REQUIRE(gMap.GetMinY() == 0);
                REQUIRE(gMap.GetMaxY() == 0);
            }
            THEN("it returns the new tiles")
            {
                REQUIRE(gMap.GetTile({0,0}) == Tile::Floor);
            }
        }
        WHEN("a single tile is set")
        {
            gMap.SetTile({0, 0}, Tile::OpenDoor);
            THEN("That tile is the new tile")
            {
                REQUIRE(gMap.GetTile({0, 0}) == Tile::OpenDoor);
            }
        }
        WHEN("a tile is set off the map")
        {
            gMap.SetTile({5, 5}, Tile::Floor);
            THEN("That tile is the new tile")
            {
                REQUIRE(gMap.GetTile({5, 5}) == Tile::Floor);
            }
        }
    }
}
     
SCENARIO("Empty Map Constructor")
{
    GIVEN("an empty map")
    {
        GameMap gMap{{}};
        THEN("all of its tiles are empty")
        {
            REQUIRE(gMap.GetTile({0,0}) == Tile::Empty);
            REQUIRE(gMap.GetTile({1,0}) == Tile::Empty);
            REQUIRE(gMap.GetTile({0,1}) == Tile::Empty);
            REQUIRE(gMap.GetTile({1,1}) == Tile::Empty);
            REQUIRE(gMap.GetTile({0,2}) == Tile::Empty);
            REQUIRE(gMap.GetTile({1,2}) == Tile::Empty);
        }
        THEN("it returns the correct range")
        {
            REQUIRE(gMap.GetMinX() == 0);
            REQUIRE(gMap.GetMaxX() == 0);
            REQUIRE(gMap.GetMinY() == 0);
            REQUIRE(gMap.GetMaxY() == 0);
        }
    }
}
