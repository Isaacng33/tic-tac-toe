#include <stdio.h>

#include <stdlib.h>

#include "game.h"

#include "initGame.h"

#include "playGame.h"

/*
 * main function: program entry point
 */

int main(int argc, char * argv[]) {
    Game * game; // pointer for the game structure
    if (argc != 3) {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return 1;
    }

    int boardSize = atoi(argv[1]); // variable for board size
    int winLength = atoi(argv[2]); // variable for winning length

    // conditions to check for valid board size and win length
    if ((boardSize < 3 || boardSize > 8)) {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return 1;
    }
    if ((winLength < 3 || winLength > boardSize)) {
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return 1;
    }

    game = initGame(boardSize, winLength); // initalise the board size and win length

    playGame(game); // play a full game

    free(game); // free heap memory that was used

    return 0;
}