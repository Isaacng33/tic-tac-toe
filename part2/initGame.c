#include <stdio.h>

#include <stdlib.h>

#include "game.h"

#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game * initGame(int boardSize, int winLength) {

    Game * game; // initialise pointer

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