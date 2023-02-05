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
    int count = 1; // count to check how many matches symbol
    for (int i = 0; i < game -> boardSize; i++) {
        for (int j = 0; j < game -> boardSize; j++) {
            if ((game -> board[i][j]) == symbol) { // check if row matches symbol
                if ((game -> board[i][j + 1]) == symbol) { // check if row matches symbol
                    count++;
                } else {
                    count = 1;
                }
            }
            if (count == game -> winLength) { // check if count is same as win length
                return 1; // return 1 if win
            }
        }
        count = 1; // reset count for new row
    }
    return 0; // return 0 since no match is found
}

// checks board vertically
int checkVertical(Game * game, char symbol) {
    int count = 1; // count to check how many matches symbol
    for (int i = 0; i < game -> boardSize; i++) {
        for (int j = 0; j < game -> boardSize; j++) {
            if ((game -> board[j][i]) == symbol) { // check if column matches symbol
                if ((game -> board[j + 1][i]) == symbol) { // check if column matches symbol
                    count++; // increment if matches
                } else {
                    count = 1;
                }
            }
            if (count == game -> winLength) { // check if count is same as win length
                return 1; // return 1 if win
            }
        }
        count = 1; // reset count for new row
    }
    return 0; // return 0 since no match is found
}

// checks board diagonally from left to right
int checkDiagonal(Game * game, char symbol) {
    int col_2 = game -> boardSize - 1; // To initialise for temporary column holder
    int count = 1; // count to check how many matches symbol
    for (int k = 0; k < game -> boardSize; k++) {
        int temp = k; // so i can increment later without changing k
        for (int i = 0; i < game -> boardSize; i++) {
            if (game -> board[temp][i] == symbol) { // checks diagonally from top left to bottom right (Bottom Half)
                if (game -> board[temp + 1][i + 1] == symbol) { // makes sure the occurence of symbol is back to back
                    count++; // increment if matches
                } else {
                    count = 1;
                }
            }
            temp++; // checks for the other diagonals
            if (count == game -> winLength) { // check if count is same as win length 
                return 1; // return 1 if win
            }
        }

        temp = k; // so i can increment later without changing k
        count = 1; // count to check how many matches symbol
        for (int i = 0; i < game -> boardSize; i++) {
            if (game -> board[i][temp] == symbol) { // checks diagonally from top left to bottom right (Top Half)
                if (game -> board[i + 1][temp + 1] == symbol) { // makes sure the occurence of symbol is back to back
                    count++; // increment if matches
                } else {
                    count = 1;
                }
            }
            temp++; // checks for the other diagonals
            if (count == game -> winLength) { // check if count is same as win length 
                return 1; // return 1 if win
            }
        }

        temp = k; // so i can increment later without changing k
        count = 1; // count to check how many matches symbol
        int col = game -> boardSize - 1; // col = 2
        for (int i = 0; i < game -> boardSize; i++) { // i gets incremented to move row from up to down
            if (game -> board[temp][col] == symbol) { // checks diagonally from top right to bottom left (Bottom half)
                if (game -> board[temp + 1][col - 1] == symbol) { // makes sure the occurence of symbol is back to back
                    count++; // increment if matches
                } else {
                    count = 1;
                }
            }
            temp++; // checks for the other diagonals
            col--; // Decrement after each loop to move the column from right to left
            if (count == game -> winLength) { // check if count is same as win length 
                return 1; // return 1 if win
            }
        }

        count = 1; // count to check how many matches symbol
        temp = 0; // temp as 0 because checking diagonals from top right to bottom left , top half where row is always 0
        int temp_col = col_2; // initialise a temp column so i can increment without changing col
        for (int i = 0; i < game -> boardSize; i++) { // i gets incremented to move row from up to down
            if (game -> board[temp][temp_col] == symbol) { // checks diagonally from top right to bottom left
                if (game -> board[temp + 1][temp_col - 1] == symbol) { // makes sure the occurence of symbol is back to back
                    count++; // increment if matches
                } else {
                    count = 1;
                }
            }
            temp++; // checks for the other diagonals
            temp_col--; // Decrement after each loop to move the column from right to left
            if (count == game -> winLength) { // check if count is same as win length 
                return 1; // return 1 if win
            }
        }
        col_2--; // Decrement col_2 so it will check for the top half
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