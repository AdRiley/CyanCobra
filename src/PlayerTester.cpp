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

