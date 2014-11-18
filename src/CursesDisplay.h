#include <curses.h>

#include "Display.h"

class CursesDisplay : public Display
{
    WINDOW* m_win;

public:
    CursesDisplay();
    virtual ~CursesDisplay();
    virtual void ClearScreen();
    virtual void RefreshScreen();
    virtual void DrawTile(int x, int y, char c);
};


