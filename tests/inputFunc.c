#include <ncurses.h>
#include <string.h>

int main() 
{
    // Func getch(); can read a SINGLE character from the terminal, BUT if you dont USE func cbreak(); getch(); DOESN'T work!

    // Func scanw(); its equal to scanf(), BUT can get input from ANY location on the screen.

    // Func getstr(); used to get strings from the terminal. This function performs the same task as getch(), until a newline, carriage return, or end-of-file is received.

    // Some exemples...

    char msg[] = "Enter a string: ";
    char str[80];
    int row, col;

    initscr();

    getmaxyx(stdscr, row, col);
    mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);

    getstr(str);
    mvprintw(LINES - 2, 0, "You Entered: %s", str);
    getch();
    endwin();

    return 0;
}