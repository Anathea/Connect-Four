#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>


class Game
{
public:
    Game();
    Game(int lines, int columns);

    void printGame() const;

    int getNbLines() const;
    void setNbLines(int value);

    int getNbColumns() const;
    void setNbColumns(int value);

    int findFreeSquareInColumn(int column);
    std::vector<std::vector<int>> changeStatusSquare(int column, int line, int player);

private:
    int nbLines;
    int nbColumns;

    std::vector<std::vector<int>> gameboard;
};

#endif // GAME_H
