#ifndef POINT_H
#define POINT_H

struct Point
{
    int x;
    int y;
    Point(int X, int Y) : x(X), y(Y) {}
    Point Up()    {Point p{x, y+1}; return p;}
    Point Down()  {Point p{x, y-1}; return p;}
    Point Left()  {Point p{x-1, y}; return p;}
    Point Right() {Point p{x+1, y}; return p;}
};

#endif
