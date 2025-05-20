#include <ncurses.h>
#include <string.h>

int main()
{
    char msg[] = "Just a string";
    int row, col;

    initscr();
<<<<<<< HEAD
    while (1)
    {
        clear();
        initscr();

        getmaxyx(stdscr, row, col);
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);

        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window(if possible) and then run this program again");
        refresh();
    }
=======
    // while (1)
    // {
        // clear();
        initscr();
        // getmaxex() is a func to get max horizontal and vertical size of window...
        getmaxyx(stdscr, row, col);
        // equal to move(row / 2, (col - strlen(msg)) / 2); printw("%s", msg); in one func.
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
        // 
        // All this func take y, x cordinate NOT x, y. It's a common mistake by beginners.
        // 
        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window(if possible) and then run this program again");

        refresh();
    // }

>>>>>>> c033e74 (add inputFunc.c, and using user input ncurses..)
    getch();
    endwin();

    return 0;
}