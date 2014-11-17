#include "gmock/gmock.h"
#include "GameMapView.h"
#include "GameMap.h"

using namespace ::testing;

class MockDisplay : public Display
{
public:
    MOCK_METHOD0(ClearScreen, void());
    MOCK_METHOD3(DrawTile, void(int x, int y, char c));
};

TEST(AGameMapView, DrawsA2x3GameMap)
{
    GameMap gm{{Tile::Floor, Tile::Wall},
               {Tile::Floor, Tile::Wall},
               {Tile::Wall,  Tile::Wall}};
    std::shared_ptr<MockDisplay> display{std::make_shared<MockDisplay>()};
    GameMapView gmv{display};

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

    gmv.DrawMap(gm);
}


