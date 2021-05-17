// File SeaBattle32.h
// Realization of GameField and Game classes
// Done by Daryna Chernobrovkina (group 1)
// Date 18.05.2021
// Implementation

#include <iostream>
#include <string>
#include <fstream>
// #include <cassert>
#include <cmath>
#include "SeaBattle32.h"

// ===================================    GAME FIELD    ====================================================

GameField::GameField()
{
    this->playerPosX = 4;
    this->playerPosY = 4;
    this->maxDistanceToMove = 2;

    this->dimension = 10;

    this->fieldSetInitial();
}

GameField::GameField(int dim, int x, int y, int maxToMove)
{
    this->playerPosX = x;
    this->playerPosY = y;
    this->maxDistanceToMove = maxToMove;

    this->dimension = dim;

    this->fieldSetInitial();
}

GameField::~GameField()
{
    for (int i = 0; i < this->dimension; i++)
    {
        delete[] this->field[i];
    }
    delete this->field;
}

int GameField::getDimension()
{
    return this->dimension;
}

void GameField::setDimension(int dim)
{
    this->dimension = dim;
}

void GameField::fieldSetInitial()
{
    this->field = new int *[this->dimension];

    for (int i = 0; i < this->dimension; i++)
    {
        this->field[i] = new int[this->dimension];

        for (int j = 0; j < this->dimension; j++)
        {
            this->field[i][j] = 0;
        }
    }
    this->field[this->playerPosX][this->playerPosY] = 2;
}

bool GameField::canSetPos(int x, int y)
{
    if (x > this->dimension - 1 || x < 0 || y > this->dimension - 1 || y < 0 || this->field[x][y] == 1)
    {
        return false;
    }

    return true;
}

int GameField::setShotPos(int x, int y)
{
    if (this->canSetPos(x, y))
    {
        this->field[x][y] = 1;
        return 1;
    }

    return 0;
}

int GameField::setPlayerPos(int x, int y)
{
    int distance = this->countMoveDistance(x, y);
    if (this->canSetPos(x, y) && distance <= this->maxDistanceToMove)
    {
        this->field[this->playerPosX][this->playerPosY] = 0;
        this->playerPosX = x;
        this->playerPosY = y;
        this->field[x][y] = 2;
        return 1;
    }
    else
    {
        return 0;
    }
}

void GameField::setRandomPlayerPos()
{
    int randPosX, randPosY;
    do
    {
        randPosX = rand() % this->dimension;
        randPosY = rand() % this->dimension;
    } while (!this->setPlayerPos(randPosX, randPosY));
}

void GameField::setRandomShotPos()
{
    int randPosX, randPosY;
    do
    {
        randPosX = rand() % this->dimension;
        randPosY = rand() % this->dimension;
    } while (!this->setShotPos(randPosX, randPosY));
}

int GameField::countMoveDistance(int x, int y)
{
    return abs(this->playerPosX - x) + abs(this->playerPosY - y);
}

bool GameField::isPlayerDead()
{
    return this->field[this->playerPosX][this->playerPosY] != 2;
}

void GameField::showField(bool hideShip)
{
    std::cout << "     ";
    for (size_t i = 0; i < this->dimension; i++)
    {
        std::cout << i << " | ";
    }

    std::cout << std::endl
              << std::endl;

    for (int i = 0; i < this->dimension; i++)
    {
        for (int j = 0; j < this->dimension; j++)
        {
            if (j == 0)
                std::cout << i << " |  ";

            std::string toDraw;
            int pos = this->field[i][j];
            if (pos == 2 && !hideShip)
                toDraw = "O";
            else if (pos == 1)
                toDraw = "X";
            else
                toDraw = "*";
            std::cout << toDraw << " | ";
        }
        std::cout << std::endl;
    }
}

std::istream &operator>>(std::istream &is, GameField &field)
{
    bool cantSetPos;
    field.fieldSetInitial();
    do
    {
        std::cout << "Enter position - ";
        is >> field.playerPosX >> field.playerPosY;
        cantSetPos = !field.canSetPos(field.playerPosX, field.playerPosY);
        if (cantSetPos)
            std::cout << "Enter right coordinates..." << std::endl;
    } while (cantSetPos);

    field.fieldSetInitial();
    return is;
}

// ===================================    GAME    ====================================================

Game::Game()
{
    this->playerOne = new GameField(10, 0, 0, 2);
    this->playerTwo = new GameField(10, 0, 0, 2);
    this->gameMode = 0;
    this->maxDistance = 2;
}

Game::Game(int dim, int mode, int maxDistance)
{
    this->playerOne = new GameField(dim, 0, 0, maxDistance);
    this->playerTwo = new GameField(dim, 0, 0, maxDistance);
    this->gameMode = mode;
    this->maxDistance = maxDistance;
}

Game::~Game()
{
    delete this->playerOne;
    delete this->playerTwo;
}

int Game::getDimension()
{
    return this->playerOne->getDimension();
}

void Game::setDimension(int dim)
{
    this->playerOne->setDimension(dim);
    this->playerTwo->setDimension(dim);
}

void Game::initializePlayerParameters()
{
    if (this->gameMode == 0)
    {
        for (size_t i = 1; i < 3; i++)
        {
            GameField *player = this->playerWhoShoot(i);
            std::cout << "Player " << i << std::endl;
            std::cin >> *player;
        }
    }
    else
    {
        int randX = rand() % this->getDimension();
        int randY = rand() % this->getDimension();
        std::cin >> *this->playerOne;
        this->playerTwo = new GameField(this->getDimension(), randX, randY, this->maxDistance);
    }
}

GameField *Game::playerWhoShoot(int counter)
{
    if (counter % 2)
    {
        return this->playerOne;
    }
    else
    {
        return this->playerTwo;
    }
}

GameField *Game::playerWhoReceive(int counter)
{
    if (counter % 2)
    {
        return this->playerTwo;
    }
    else
    {
        return this->playerOne;
    }
}

int Game::setShotPos(GameField *player)
{
    int x, y;
    bool cantSetPos;
    do
    {
        std::cout << "Shoot at position - ";
        std::cin >> x >> y;
        cantSetPos = !player->setShotPos(x, y);
        if (cantSetPos)
            std::cout << "Enter right coordinates..." << std::endl;
    } while (cantSetPos);
    return player->countMoveDistance(x, y);
}

void Game::setPlayerPos(GameField *player)
{
    int x, y;
    bool cantSetPos;
    do
    {
        std::cout << "Set new player's position - ";
        std::cin >> x >> y;
        cantSetPos = !player->setPlayerPos(x, y);
        if (cantSetPos)
            std::cout << "Enter right coordinates..." << std::endl;
    } while (cantSetPos);
}

bool Game::isGameOver()
{
    return this->playerOne->isPlayerDead() || this->playerTwo->isPlayerDead();
}

void Game::start()
{
    int counter = 1;
    // this->initializePlayerParameters();
    std::cout << std::endl;

    while (!this->isGameOver())
    {
        system("CLS");
        this->show(counter % 2);
        GameField *playerWhoShoot = this->playerWhoShoot(counter);
        GameField *playerWhoReceive = this->playerWhoReceive(counter);

        std::cout << "  Step " << floor(counter / 2) << std::endl;
        int distance = this->setShotPos(playerWhoReceive);
        std::cout << "Distance was - " << distance << std::endl;
        this->setPlayerPos(playerWhoShoot);

        if (this->gameMode != 0)
        {
            // To set next step again to PLAYER | in sum counter += 2, so player will shoot again
            counter += 1;
            if (this->isGameOver())
                break;

            // Bot does his operations
            playerWhoShoot->setRandomShotPos();
            playerWhoReceive->setRandomPlayerPos();
        }

        counter += 1;
        std::cout << std::endl;
    }
    if (this->gameMode == 0)
        std::cout << "  Game over, player " << (counter % 2) + 1 << " won!!" << std::endl;
    else
    {
        if (counter % 2 == 0)
            std::cout << "  Game over, player won!!" << std::endl;
        else
            std::cout << "  Game over, bot won!!" << std::endl;
    }
}

void Game::show(bool hiddenPlayer)
{
    if (hiddenPlayer)
    {
        std::cout << "  Your field:" << std::endl;
    }
    else
        std::cout << "  Enemie's field:" << std::endl;
    this->playerOne->showField(!hiddenPlayer);
    std::cout << std::endl;
    if (hiddenPlayer)
    {
        std::cout << "  Enemie's field:" << std::endl;
    }
    else
        std::cout << "  Your field:" << std::endl;
    this->playerTwo->showField(hiddenPlayer);
    std::cout << std::endl;
}

Game *Game::loadGame(std::string filename)
{
    int dimension, gamemode, maxDist, x, y;
    std::ifstream file(filename);
    file >> dimension >> gamemode >> maxDist;
    std::cout << dimension << gamemode << maxDist;
    Game *game = new Game(dimension, gamemode, maxDist);
    file >> x >> y;
    std::cout << x << y;
    game->playerOne = new GameField(dimension, x, y, maxDist);
    file >> x >> y;
    std::cout << x << y;
    game->playerTwo = new GameField(dimension, x, y, maxDist);
    int counter = 1;
    while (!file.eof())
    {
        file >> x >> y;
        game->playerWhoReceive(counter)->setShotPos(x, y);
        file >> x >> y;
        game->playerWhoShoot(counter)->setPlayerPos(x, y);
        counter += 1;
    }
    std::cout << x << y;
    file.close();

    return game;
}

void Game::input()
{
    int dim;
    do
    {
        std::cout << "Enter dimension (NxN) - ";
        std::cin >> dim;
        if (dim <= 0)
            std::cout << "Enter right dimension..." << std::endl;

    } while (dim <= 0);

    this->setDimension(dim);
    this->initializePlayerParameters();
}