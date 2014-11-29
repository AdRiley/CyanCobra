#include "gmock/gmock.h"
#include "AsciiGameMapView.h"
#include "GameMap.h"
#include "Player.h"

using namespace ::testing;

class MockDisplay : public Display
{
public:
    MOCK_METHOD0(ClearScreen, void());
    MOCK_METHOD0(RefreshScreen, void());
    MOCK_METHOD3(DrawTile, void(int x, int y, char c));
};

TEST(AnAsciiGameMapView, DrawsA2x3GameMap)
{
    GameMap gm{{Tile::Floor, Tile::Wall},
               {Tile::Floor, Tile::Wall},
               {Tile::Wall,  Tile::Wall}};
    std::shared_ptr<MockDisplay> display{std::make_shared<MockDisplay>()};
    AsciiGameMapView gmv{display};

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

    gmv.DrawMap(gm);
}

TEST(AnAsciiGameMapView, DrawsA2x3GameMapWithPlayer)
{
    GameMap gm{{Tile::Floor, Tile::Wall},
               {Tile::Floor, Tile::Wall},
               {Tile::Wall,  Tile::Wall}};
    Player player{0, 1};
    std::shared_ptr<MockDisplay> display{std::make_shared<MockDisplay>()};
    AsciiGameMapView gmv{display};

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
    EXPECT_CALL(*display, DrawTile(0, 1, '@'))
        .Times(1);
    EXPECT_CALL(*display, RefreshScreen())
        .Times(1);

    gmv.DrawMapAndPlayer(gm, player);
}

TEST(AnAsciiGameMapView, RendersAClosedDoorAsBackslash)
{
    GameMap gm{{Tile::ClosedDoor}};
    std::shared_ptr<MockDisplay> display{std::make_shared<MockDisplay>()};
    AsciiGameMapView gmv{display};

    EXPECT_CALL(*display, ClearScreen())
        .Times(1);
    EXPECT_CALL(*display, DrawTile(0, 0, '\\'))
        .Times(1);
    EXPECT_CALL(*display, RefreshScreen())
        .Times(1);

    gmv.DrawMap(gm);
}



