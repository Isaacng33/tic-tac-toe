#include <stdio.h>

#include "game.h"

#include "playGame.h"

#include "endGame.h"

#include <string.h>

#include <stdlib.h>

/*
 * Controls the game logic from start to end
 */

void playGame(Game * game) {

    char symbols[2] = {
        'X',
        'O'
    };
    // player 'X' plays first
    int player = 0;

    // starting board
    printf("New game starting\n");
    showGame(game);

    // Your game should be controlled by an outer loop
    // Each pass through the loop is one completed move by a player
    while (game -> turns < game -> maxTurns) {
        while (1) {
            // Request a move from the next player and check it is valid (an unused square within the board)
            printf("Player %c: Enter your move as row column values:\n", symbols[player]); // use this to request the player move
            if (makeMove(game, symbols[player]) == 0) { // if make move returns false (0) continue to ask for a valid move
                continue;
            }
            break; // if valid break loop
        }

        game -> turns = game -> turns + 1; // increment current turn if valid move is made
        if (winGame(game, symbols[player])) { // check for win with current symbol after move
            showGame(game); // if won show board
            printf("Player %c has won\n", symbols[player]); // use to announce a winner - game is over
            break; // breaks out of loop
        } else if (drawGame(game)) { // check for draw if theres no win
            showGame(game); // print board if draw
            printf("Match is drawn\n"); // use to announce a draw - game is over
            break; // break out of loop
        }
        showGame(game); // if theres no win or draw print board
        player = !player; // swap the player and continue the loop
    }
    return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame(Game * game) {

    printf("\n");
    printf("      0  1  2\n");
    printf("\n");
    printf(" 0    %c  %c  %c\n", game -> board[0][0], game -> board[0][1], game -> board[0][2]);
    printf(" 1    %c  %c  %c\n", game -> board[1][0], game -> board[1][1], game -> board[1][2]);
    printf(" 2    %c  %c  %c\n", game -> board[2][0], game -> board[2][1], game -> board[2][2]);
    printf("\n");

    return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove(Game * game, char symbol) {
    // variables to store moves
    int move_1;
    int move_2;
    char buffer[100];

    // read the players move from the keyboard, expected as two integers coordinates as shown on the board 
    fgets(buffer, 100, stdin); // Reads it as a char
    if (strlen(buffer) != 4) { // Make sure its not bigger than 4 char
        printf("Move rejected. Please try again\n");
        return 0; // returns 0 because input was false
    }

    if (buffer[1] != ' ') { // Make sure middle digit is a space
        printf("Move rejected. Please try again\n");
        return 0; // returns 0 because input was false
    }

    sscanf(buffer, "%d %d", & move_1, & move_2); // Takes it the int argument

    // test that the chosen location is a valid empty space
    if (game -> board[move_1][move_2] != '.') {
        // if we do not accept the move return 0
        printf("Move rejected. Please try again\n");
        return 0;
    } else if (move_1 >= game -> boardSize || move_2 >= game -> boardSize) { // checking for out of bounds input
        printf("Move rejected. Please try again\n");
        return 0;
    } else {
        // if we accept then update the board and return 1
        game -> board[move_1][move_2] = symbol;
        return 1; // move accepted
    }
}