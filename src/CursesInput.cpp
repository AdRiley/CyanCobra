#include <curses.h>
#include "CursesInput.h"

Command CursesInput::GetCommand()
{
    while (true)
    {
        int keyPress = getch();

        switch( keyPress )
        {
            case KEY_DOWN:
                return Command::Down;
                break;
            case KEY_LEFT:
                return Command::Left;
                break;
            case KEY_RIGHT:
                return Command::Right;
                break;
            case KEY_UP:
                return Command::Up;
                break;
            case KEY_BACKSPACE:
                return Command::Exit;
                break;
            default:
                break;
        }
    }
}
