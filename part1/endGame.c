#include <stdio.h>

#include "game.h"

#include "endGame.h"

#include "initGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player

// checks board horizontally
int checkHorizontal(Game * game, char symbol) {
    int count = 0; // count to check how many matches symbol
    for (int i = 0; i < game -> boardSize; i++) {
        for (int j = 0; j < game -> boardSize; j++) {
            if ((game -> board[i][j]) == symbol) { // check if row matches symbol
                count++; // increment if matches
            }
            if (count == game -> winLength) { // check if count is same as win length
                return 1; // return 1 if win
            }
        }
        count = 0; // reset count for new row
    }
    return 0; // return 0 since no match is found
}

// checks board vertically
int checkVertical(Game * game, char symbol) {
    int count = 0; // count to check how many matches symbol
    for (int i = 0; i < game -> boardSize; i++) {
        for (int j = 0; j < game -> boardSize; j++) {
            if ((game -> board[j][i]) == symbol) { // check if column matches symbol
                count++; // increment if matches
            }
            if (count == game -> winLength) { // check if count is same as win length
                return 1; // return 1 if win
            }
        }
        count = 0; // reset count for new row
    }
    return 0; // return 0 since no match is found
}

// checks board diagonally
int checkDiagonal(Game * game, char symbol) {
    int count = 0; // count to check how many matches symbol
    for (int i = 0; i < game -> boardSize; i++) {
        if (game -> board[i][i] == symbol) { // checks diagonally from top left to bottom right
            count++; // increment if matches
        }
    }

    if (count != game -> winLength) { // if above matches, dont need to execute this check
        int col = game -> boardSize - 1; // col = 2
        count = 0; // count to check how many matches symbol
        for (int i = 0; i < game -> boardSize; i++) { // i gets incremented to move row from up to down
            if (game -> board[i][col] == symbol) { // checks diagonally from top right to bottom left
                count++; // increment if matches
            }
            col--; // Decrement after each loop to move the column from right to left
        }
    }

    if (count == game -> winLength) { // check if count is same as win length 
        return 1; // return 1 if win
    }

    return 0; // return 0 since no match is found
}

int winGame(Game * game, char symbol) {
    if (checkHorizontal(game, symbol)) { // if horizontal found return 1
        return 1;
    }
    if (checkVertical(game, symbol)) { // if vertical found return 1
        return 1;
    }
    if (checkDiagonal(game, symbol)) { // if diagonal found return 1
        return 1;
    }

    // return 1(true) if game is won, 0(false) otherwise
    //
    // You may wish to define further functions to test different win conditions
    // Games can be won with horizontal, vertical or diagonal lines

    return 0; // continue
}

// test for a draw
int drawGame(Game * game) {
    int count = 0; // count to check how many matches 'X' or 'O'
    for (int i = 0; i < game -> boardSize; i++) {
        for (int j = 0; j < game -> boardSize; j++) {
            if (game -> board[i][j] != '.') { // anyting apart from empty board, means 'X' or 'O'
                count++; // increment by 1
            }
        }
    }
    if (count == game -> maxTurns) { // if count is same as max turns means board is full
        return 1; // game is drawn
    }
    // return 1(true) if game is drawn, 0(false) otherwise
    return 0; // continue
}