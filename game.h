#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Game
{
public:
    Game();
    Game(int lines, int columns);

    int getNbLines() const;
    void setNbLines(int value);

    int getNbColumns() const;
    void setNbColumns(int value);

    int getNbPlayers() const;
    void setNbPlayers(int value);

    std::vector<char> getPlayerOutput() const;
    void setPlayerOutput(const std::vector<char> &value);

    void printGame() const;
    void header() const;

    int printMenu() const;
    void menu(int action);

    int findFreeSquareInColumn(const int column);
    std::vector<std::vector<int>> changeSquareStatus(const int column, const int line, const int player);

    void configMultiplayer(const int totalPlayer);

private:
    int nbLines;
    int nbColumns;
    int nbPlayers;
    std::vector<char> playerOutput;

    std::vector<std::vector<int>> gameboard;
};

#endif // GAME_H
