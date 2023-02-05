
/*
 * data structure for the game
 */

typedef struct _game {
  int boardSize;       // board size 
  int winLength;       // length of a winning line
  int maxTurns;        // maximum possible moves
  int turns;           // current number of moves
  char board[8][8];    // board for storing the game state
} Game;
