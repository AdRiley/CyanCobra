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
            case 115: //s
                return Command::ActionDown;
                break;
            case 97: //a
                return Command::ActionLeft;
                break;
            case 100: //d
                return Command::ActionRight;
                break;
            case 119: //w
                return Command::ActionUp;
                break;
            case KEY_BACKSPACE:
                return Command::Exit;
                break;
            default:
                mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", keyPress, keyPress);
                break;
        }
    }
}
