#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
public:
    virtual ~Display() {}
    virtual void ClearScreen() = 0;
    virtual void RefreshScreen() = 0;
    virtual void DrawTile(int x, int y, char c) = 0;
};

#endif
