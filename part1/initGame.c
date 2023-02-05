#include <stdio.h>

#include <stdlib.h>

#include "game.h"

#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game * initGame(int boardSize, int winLength) {

    Game * game; // initialise pointer
    if ((boardSize != 3) || (winLength != 3)) { // check must be a 3 x 3
        // for incorrect boardSize or winLength you should return a NULL pointer
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        game = NULL;
        return game;
    }

    // allocate the Game data structure
    game = (Game * ) malloc(sizeof(Game));
    // intialise the Game data structure values
    game -> maxTurns = boardSize * boardSize;
    game -> turns = 0;
    game -> winLength = winLength;
    game -> boardSize = boardSize;
    // board values should be set to '.' (unused location)
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            game -> board[i][j] = '.'; // loop thru every board value and set to .
        }
    }

    return game; // return the pointer
}