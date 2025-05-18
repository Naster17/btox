#include <ncurses.h>

int main() {
    int ch;
    
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("Type any character, or 'q' to quit the program!\n");

    ch = getch();

    if (ch != 'q') {
        printw("You typed %c\n", ch);
        getch();
    }
    else printw("Quite...");
    endwin();

    return 0;
}


// gcc tests/test.c -lncurses -lmenu