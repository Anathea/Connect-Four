#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

int main()
{
    Game g;

    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 2);
    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 2);
    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);

    return 0;
}
