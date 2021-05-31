// File SeaBattle32.h
// Realization of GameField and Game classes
// Done by Daryna Chernobrovkina (group 1)
// Date 18.05.2021
// Tests

#include <iostream>
#include <fstream>
#include "SeaBattle32.cpp"

using namespace std;

int main()
{
    // ===================================    Game Load   ====================================================

    string filename = "game.txt";
    Game *game = Game::loadGame(filename);

    game->start();

    // ===================================    Full game 1 player ====================================================

    // Game *game = new Game(1, 1, 2);

    // game->input();

    // game->start();

    // ===================================    Full game 2 players ====================================================

    // Game *game = new Game();

    // game->input();

    // game->start();

    // ===================================    Game init and hiding players  ====================================================

    // Game game;

    // cout << "Player 0 is hidden" << endl
    //      << endl;
    // game.show(0);

    // ===================================    Test on distance and canSetPos    ====================================================

    // GameField field(6, 3, 2, 2); // (dim, x, y, maxDist)

    // cout << endl
    //      << "Start position (3, 2): " << endl
    //      << endl;

    // field.showField(0);

    // cout << endl
    //      << "Setting (3, 3): " << endl
    //      << endl;

    // field.setPlayerPos(3, 3);

    // field.showField(0);

    // cout << endl
    //      << "Setting (3, 4): " << endl
    //      << endl;

    // field.setPlayerPos(3, 4);

    // field.showField(0);

    // cout << endl
    //      << "Setting (5, 6): " << endl
    //      << endl;

    // field.setPlayerPos(5, 6);

    // field.showField(0);

    // cout << endl
    //      << "Setting (2, 1): " << endl
    //      << endl;

    // field.setPlayerPos(2, 1);

    // field.showField(0);

    // cout << endl
    //      << "Setting X on (3, 3) and Player on (3, 3): " << endl
    //      << endl;

    // field.setShotPos(3, 3);
    // field.setPlayerPos(3, 3);

    // field.showField(0);

    // ===================================    Test is player dead    ====================================================

    // GameField field(6, 3, 2, 2); // (dim, x, y, maxDist)

    // field.setShotPos(3, 1);
    // field.showField(0);
    // cout << endl;

    // field.setPlayerPos(2, 1);
    // field.showField(0);

    // cout << "Dead? - " << field.isPlayerDead() << endl;
    // field.setShotPos(2, 1);
    // field.showField(0);
    // cout << "Dead? - " << field.isPlayerDead() << endl;

    return 0;
}