#include <ncurses.h>

int main()
{
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    addstr("Gay\n");
    printw("Type any character, or 'q' to quit the program!\n");

    ch = getch();

    if (ch != 'q')
    {
        printw("You typed %c\n", ch);
        getch();
    }

    endwin();
    return 0;
}