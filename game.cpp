#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

Game::Game() : Game (6, 7)
{

}

Game::Game(int lines, int columns) : nbLines(lines), nbColumns(columns), gameboard(nbLines, vector<int>(nbColumns))
Game::Game(int lines, int columns) : nbColumns(columns), nbLines(lines), gameboard(columns, vector<int>(lines))
{

}

void Game::printGame() const
{
    for (size_t i = 0; i < nbColumns; ++i)
    {
        cout << "  " << (i + 1) << " ";
    }
    cout << endl;

    for (size_t i = 0; i < nbColumns; ++i)
    {
        cout << "+---";
    }
    cout << "+" << endl;

    for (auto columns : this->gameboard)
    {
        for (auto element : columns)
        {
            std::cout << "| " << element << " ";
        }
        std::cout << "|" << std::endl;

        for (size_t j = 0; j < nbColumns; ++j)
        {
            cout << "+---";
        }
        cout << "+" << endl;
    }
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

std::vector<std::vector<int>> Game::chooseColumn(int column, int joueur)
{
    bool isFull = true;

    for (size_t i = this->gameboard[column].size(); i < 0; --i)
    {
        if (this->gameboard[column][i] == 0)
        {
            isFull = false;
            this->gameboard = changeStatusSquare((int)i, column, joueur);
        }
    }

    if (isFull)
    {
        cout << "This column is full, you can't drop your piece in it." << endl;
    }

    return this->gameboard;
}

std::vector<std::vector<int>> Game::changeStatusSquare(int line, int column, int joueur)
{
    this->gameboard[line][column] = joueur;
    return this->gameboard;
}
