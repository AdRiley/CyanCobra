#include "test.h"
#include "Player.h"

SCENARIO("Player Positioning")
{
    GIVEN("A Player at position {2,3}")
    {
        Player player{Point(2,3)};

        THEN("It can return its position")
        {
            REQUIRE(player.GetLocation().x == 2);
            REQUIRE(player.GetLocation().y == 3);
        }
        WHEN("A Player is moved to position {4,7}")
        {
            player.SetLocation(Point(4, 7));

            THEN("its new position is {4,7}")
            {
                REQUIRE(player.GetLocation().x == 4);
                REQUIRE(player.GetLocation().y == 7);
            }
        }
    }
}
