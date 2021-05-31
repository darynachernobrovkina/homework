// File SeaBattle32.h
// Realization of GameField and Game classes
// Done by Daryna Chernobrovkina (group 1)
// Date 18.05.2021
// Headers

#include <iostream>

#ifndef _SEABATTLE32_H_
#define _SEABATTLE32_H_

class GameField
{
private:
    int dimension;
    int **field;
    int playerPosX, playerPosY;
    int maxDistanceToMove;

public:
    GameField();
    // initialization with no parameters

    GameField(int dim, int x, int y, int maxToMove);
    // Initialization with parameters
    // @dim - dimension of field NxN
    // @x - player vertical position
    // @y - player horizontal position
    // @maxToMove - maximum distance that player can move

    ~GameField();
    // Destructor

    int getDimension();
    // @result - field's dimension

    void setDimension(int dim);
    // sets field's dimension
    // @dim - new dimension

    void fieldSetInitial();
    // Creates field and sets on it player's position

    bool canSetPos(int x, int y);
    // Checks if point on field is available
    // @x - vertical position on field
    // @y - horizontal position on field
    // @result - 1 if available, 0 if not

    int setShotPos(int x, int y);
    // Sets point on field as Shot
    // @x - vertical position on field
    // @y - horizontal position on field
    // @result - if point was available, sets point on field
    //           and returs 1, else field stays the same and returns 0

    int setPlayerPos(int x, int y);
    // Sets point on field as Player
    // @x - vertical position on field
    // @y - horizontal position on field
    // @result - if point was available, sets point on field
    //           and returs 1, else field stays the same and returns 0

    void setRandomPlayerPos();
    // Sets any available point on field as Player

    void setRandomShotPos();
    // Sets any available point on field as Shot

    int countMoveDistance(int x, int y);
    // Counts distance to player
    // @x - vertical position on field
    // @y - horizontal position on field
    // @result - int distance from point (x, y) to Player

    bool isPlayerDead();
    // Checks if player is dead
    // @result - 1 if yes, else 0

    void showField(bool hideShip);
    // Shows field on a screen
    // @hideShip - 1 if hide ship, else 0

    // friend std::ostream &operator<<(std::ostream &os, const GameField &field);
    friend std::istream &operator>>(std::istream &is, GameField &field);
    // User enters player position from console
};

class Game
{
private:
    GameField *playerOne;
    GameField *playerTwo;
    int gameMode;
    int maxDistance;

public:
    Game();
    // initialization with no parameters

    Game(int dim, int mode, int maxDistance);
    // Initialization with parameters
    // @dim - dimension of player's fields NxN
    // @mode - game mode -> player vs player(0) | player vs bot(1)
    // @maxDistance - maximum distance that players can move

    ~Game();
    // Destructor

    int getDimension();
    // @result - field's dimension

    void setDimension(int dim);
    // Sets dimensions of fields
    // @dim - new dimension

    void initializePlayerParameters();
    // Asks players to enter the position of their player

    GameField *playerWhoShoot(int counter);
    // @counter - in-game steps counter
    // @result - one of this players
    //           odd - player one
    //           even - player two

    GameField *playerWhoReceive(int counter);
    // @counter - in-game steps counter
    // @result - one of this players
    //           odd - player two
    //           even - player one

    int setShotPos(GameField *player);
    // Asks to enter Shot position until correct input
    // @player - one of this players
    // @result - distance from entered shot pos to actual player posotion

    void setPlayerPos(GameField *player);
    // Asks to enter Player position until correct input
    // @player - one of this players

    bool isGameOver();
    // Checks if game is over
    // @result - 1 if yes, else 0

    void start();
    // Starts a game
    // Doesn't contain initialization of fields and players positions

    void show(bool hiddenPlayer);
    // Shows the fields of both players where one of them is hidden
    // @hiddenPlayer - 0 if first player must be hidden, else 1

    static Game *loadGame(std::string filename);
    // Loads the game from a file
    // @filename - name of file to load from
    // @result - new Game objects with data from file

    void input();
    //  Asks to enter Game dimension
    //  And initializes fields with players positions
};

#endif