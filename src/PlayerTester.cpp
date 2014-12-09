#include "test.h"
#include "Player.h"

SCENARIO("Player Positioning")
{
    GIVEN("A Player at position {2,3}")
    {
        Player player{2,3};

        THEN("It can return its position")
        {
            REQUIRE(player.GetX() == 2);
            REQUIRE(player.GetY() == 3);
        }
        WHEN("A Player is moved to position {4,7}")
        {
            player.SetPosition(4, 7);

            THEN("its new position is {4,7}")
            {
                REQUIRE(player.GetX() == 4);
                REQUIRE(player.GetY() == 7);
            }
        }
    }
}
