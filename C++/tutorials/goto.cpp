#include <stdio.h>
#include <curses.h>

#define gotoxy(x,y) wmove(stdscr,y-1,x-1)

int main()
{
    int x, y;
    initscr();

    for(x=2;x<79;x++)
    {
        gotoxy(x,1);
        printw("%c",'-');
        gotoxy(x,13);
        printw("%c",'-');
        gotoxy(x,25);
        printw("%c",'-');
    }
    refresh();
    getchar();
    endwin();
    return 0;
}