#ifndef POINT_H
#define POINT_H

#include <vector>

struct Point
{
    int x;
    int y;
    Point(int X, int Y) : x(X), y(Y) {}
    Point Up()    {Point p{x, y+1}; return p;}
    Point Down()  {Point p{x, y-1}; return p;}
    Point Left()  {Point p{x-1, y}; return p;}
    Point Right() {Point p{x+1, y}; return p;}
    std::vector<Point> AdjPoints()
    {
		std::vector<Point> ret;
		ret.push_back(Up());
		ret.push_back(Right());
		ret.push_back(Down());
		ret.push_back(Left());
		return ret;
	}
	std::vector<Point> DiagPoints()
    {
		std::vector<Point> ret;
		ret.push_back(Up().Right());
		ret.push_back(Right().Down());
		ret.push_back(Down().Left());
		ret.push_back(Left().Up());
		return ret;
	}
    friend bool operator<(const Point& lhs, const Point& rhs)
    {
        return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));
    }
};

#endif
