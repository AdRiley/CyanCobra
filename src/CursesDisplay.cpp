#include <string>

#include "CursesDisplay.h"

CursesDisplay::CursesDisplay() :
    m_win{initscr()}
{
    if (!m_win)
        throw "Error initialising ncurses.";

    noecho();              // Turn off key echoing
    keypad(m_win, TRUE);   // Enable the keypad for non-char keys
    curs_set(0);	   // Hide the cursor
}

CursesDisplay::~CursesDisplay()
{
    curs_set(1);
    echo();

    delwin(m_win);
    endwin();
    refresh();
}

/*virtual*/ void CursesDisplay::ClearScreen()
{
    clear();
}

/*virtual*/ void CursesDisplay::RefreshScreen()
{
    refresh();
}

/*virtual*/ void CursesDisplay::DrawTile(int x, int y, char c)
{
    std::string s(1, c);
    mvaddstr(y, x, &s[0]);
}



