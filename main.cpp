#include <iostream>
#include <vector>
#include <windows.h>
#include "game.h"

using namespace std;

int main()
{
    Game g;
    g.printGame();

    g.chooseColumn(1, 1);

    return 0;
}
