#include "test.h"
#include "Point.h"

SCENARIO("Point Constructor")
{
	WHEN("A Point is constructed")
	{
		Point p{1,3};
		THEN("can retrieve the co-ordinates")
		{
			REQUIRE(p.x == 1);
			REQUIRE(p.y == 3);
		}
	}
}

class PointFixture
{
public:
	Point TestMethodRequiringPoint(Point p) {return p;}
};

TEST_CASE_METHOD(PointFixture, "Method requiring a Point with take a tuple {1,2}")
{
	GIVEN("a method which requires a point")
	{
		THEN("When it is called with a tuple")
		{
			Point temp = TestMethodRequiringPoint({5,2});
			REQUIRE(temp.x == 5);
			REQUIRE(temp.y == 2);
		}
	}
}
