#include "test.h"
#include "AsciiGameMapView.h"
#include "GameMap.h"
#include "Player.h"

class MockDisplay : public Display
{
public:
    MOCK_METHOD0(ClearScreen, void());
    MOCK_METHOD0(RefreshScreen, void());
    MOCK_METHOD3(DrawTile, void(int x, int y, char c));
};

SCENARIO("Drawing a 2x3 Game Map")
{
    GIVEN("A 2x3 Game Map and a AsciiGameMapView")
    {
        GameMap gm{{Tile::Floor, Tile::Wall},
                   {Tile::Floor, Tile::Wall},
                   {Tile::Wall,  Tile::Wall}};
        std::shared_ptr<MockDisplay> display{std::make_shared<MockDisplay>()};
        AsciiGameMapView gmv{display};
        
        THEN("expect the calls")
        {
            EXPECT_CALL(*display, ClearScreen())
                .Times(1);
            EXPECT_CALL(*display, DrawTile(0, 0, '.'))
                .Times(1);
            EXPECT_CALL(*display, DrawTile(1, 0, '#'))
                .Times(1);
            EXPECT_CALL(*display, DrawTile(0, 1, '.'))
                .Times(1);
            EXPECT_CALL(*display, DrawTile(1, 1, '#'))
                .Times(1);
            EXPECT_CALL(*display, DrawTile(0, 2, '#'))
                .Times(1);
            EXPECT_CALL(*display, DrawTile(1, 2, '#'))
                .Times(1);
            EXPECT_CALL(*display, RefreshScreen())
                .Times(1);
                
            WHEN("the map is drawn to the display")
            {
                gmv.DrawMap(gm);
            }
            AND_THEN("if we add a player")
            {
                Player player{Point(0, 1)};
                 EXPECT_CALL(*display, DrawTile(0, 1, '@'))
                    .Times(1);
                WHEN("the map and player are drawn to the display")
                {
                    gmv.DrawMapAndPlayer(gm, player);
                }
            }
        }
    }
}

SCENARIO("Tiles Render As Correct Symbols")
{
    SECTION("Setup")
    {
        std::shared_ptr<MockDisplay> display{std::make_shared<MockDisplay>()};
        AsciiGameMapView gmv{display};
        EXPECT_CALL(*display, ClearScreen())
            .Times(1);
        EXPECT_CALL(*display, RefreshScreen())
            .Times(1);
        GIVEN("A Closed Door")
        {
            GameMap gm{{Tile::ClosedDoor}};
            THEN("Renders as Backslash")
            {
                EXPECT_CALL(*display, DrawTile(0, 0, '\\'))
                    .Times(1);
                WHEN("the map is drawn")
                {
                    gmv.DrawMap(gm);
                }
            }
        }
        GIVEN("A Open Door")
        {
            GameMap gm{{Tile::OpenDoor}};
            THEN("Renders as Underscore")
            {
                EXPECT_CALL(*display, DrawTile(0, 0, '_'))
                    .Times(1);
                WHEN("the map is drawn")
                {
                    gmv.DrawMap(gm);
                }
            }
        }
        
    }
}
