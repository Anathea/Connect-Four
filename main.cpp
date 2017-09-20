#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

int main()
{
    Game g;

//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 2);
//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 2);
//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);
//    g.changeStatusSquare(3, g.findFreeSquareInColumn(3), 1);

    int players;
    cout << "How many players are you? ";
    cin >> players;
    g.configMultiplayer(players);

    return 0;
}
