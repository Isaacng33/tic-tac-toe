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

    game = initGame(3, 3); // initalise the board size and win length

    playGame(game); // play a full game

    free(game); // free heap memory that was used

    return 0;
}