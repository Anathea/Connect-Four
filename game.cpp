#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

Game::Game() : Game (6, 7)
{

}

Game::Game(int lines, int columns) : nbColumns(columns), nbLines(lines), nbPlayers(2), gameboard(columns, vector<int>(lines))
{
    playerOutput = {' ', 'o', '#'};
}

int Game::getNbLines() const
{
    return nbLines;
}

void Game::setNbLines(int value)
{
    nbLines = value;
}

int Game::getNbColumns() const
{
    return nbColumns;
}

void Game::setNbColumns(int value)
{
    nbColumns = value;
}

int Game::getNbPlayers() const
{
    return nbPlayers;
}

void Game::setNbPlayers(int value)
{
    nbPlayers = value;
}

std::vector<char> Game::getPlayerOutput() const
{
    return playerOutput;
}

void Game::setPlayerOutput(const std::vector<char> &value)
{
    playerOutput = value;
}

void Game::printGame() const
{
    cout << endl;

    for (int i = 0; i < nbColumns; ++i)
    {
        cout << "  " << i << " ";
    }
    cout << endl;

    for (int i = 0; i < nbColumns; ++i)
    {
        cout << "+---";
    }
    cout << "+" << endl;

    for (int lines = 0; lines < nbLines; ++lines)
    {
        for (int columns = 0; columns < nbColumns; ++columns)
        {
            cout << "| " << playerOutput[gameboard[columns][lines] % playerOutput.size()] << " ";
        }
        cout << "|" << endl;
        for (int i = 0; i < nbColumns; ++i)
        {
            cout << "+---";
        }
        cout << "+" << endl;
    }
}

void Game::header() const
{
    cout << " #####                                              #      " << endl;
    cout << "#     #  ####  #    # #    # ######  ####  #####    #    # " << endl;
    cout << "#       #    # ##   # ##   # #      #    #   #      #    # " << endl;
    cout << "#       #    # # #  # # #  # #####  #        #      #    # " << endl;
    cout << "#       #    # #  # # #  # # #      #        #      #######" << endl;
    cout << "#     # #    # #   ## #   ## #      #    #   #           # " << endl;
    cout << " #####   ####  #    # #    # ######  ####    #           # " << endl;
    cout << endl;
    cout << "Hello and welcome to Connect 4!" << endl;
    cout << endl;
}

int Game::printMenu() const
{
    int action;

    cout << endl;
    cout << "Home menu" << endl;
    cout << endl;
    cout << "1 - Play! (Classic 2 players)" << endl;
    cout << "2 - Configure multiplayer" << endl;
    cout << "3 - Configure multiplayer" << endl;
    cout << "4 - How to play" << endl;
    cout << endl;
    cout << "What do you want to do? ";
    cin >> action;

    return action;
}

void Game::menu(int action)
{
    // TODO : well, basically everything...
}

int Game::findFreeSquareInColumn(const int column)
{
    // If column is full, no need to do operations
    if (this->gameboard[column][0] != 0)
    {
        cout << endl;
        cout << "This column is full, you can't drop your coin in it." << endl;
        cout << endl;

        return -1;
    }

    int line = nbLines - 1;
    while (line >= 0)
    {
        if (this->gameboard[column][line] == 0)
        {
            return line;
        }
        --line;
    }

    return -1;
}

std::vector<std::vector<int>> Game::changeSquareStatus(const int column, const int line, const int player)
{
    if (line >= 0)
    {
        this->gameboard[column][line] = player;
        printGame();
    }

    return this->gameboard;
}

void Game::configMultiplayer(const int totalPlayer)
{
    char symbol;

    playerOutput.clear();
    playerOutput.push_back(' ');

    for (int i = 0; i < totalPlayer; ++i)
    {
        cout << "What is player " << (i + 1) << "'s symbol? ";
        cin >> symbol;
        playerOutput.push_back(symbol);
    }

    cout << endl;
    cout << "Symbols per player are :" << endl;

    for (int i = 1; i < playerOutput.size(); ++i)
    {
        cout << "Player " << i << ": " << playerOutput[i] << endl;
    }

    cout << endl;
    cout << "Multiplayer is now ready." << endl;
    cout << endl;
}
