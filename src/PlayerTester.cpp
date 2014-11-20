#include "gmock/gmock.h"
#include "Player.h"

using namespace ::testing;

class APlayer: public Test
{
public:
    Player player;

    APlayer() :
        player{2, 3}
    {}
};

TEST_F(APlayer, ReturnsItsXPosition)
{
    ASSERT_THAT(2, Eq(player.GetX()));
}

TEST_F(APlayer, ReturnsItsYPosition)
{
    ASSERT_THAT(3, Eq(player.GetY()));
}

TEST_F(APlayer, CanBeMoved)
{
    player.SetPosition(4, 7);
    ASSERT_THAT(4, Eq(player.GetX()));
    ASSERT_THAT(7, Eq(player.GetY()));
}

