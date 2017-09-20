#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

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

    std::vector<char> getPlayerOutput() const;
    void setPlayerOutput(const std::vector<char> &value);

private:
    int nbLines;
    int nbColumns;
    std::vector<char> playerOutput = {' ', 'o', '#'};

    std::vector<std::vector<int>> gameboard;
};

#endif // GAME_H
