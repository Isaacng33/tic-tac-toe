
# code details

EXE = ./bin/tictactoe
SRC = endGame.c initGame.c playGame.c main.c                 # ** list source code here **
OBJ = endGame.o initGame.o playGame.o main.o                 # ** list object code here **

# generic build details

CC     = gcc
CFLAGS = -std=c99 -Wall
CLIBS  = 
CLINK  = 

# compile to object code

%.o: %.c
	$(CC) -c $(CFLAGS) $(CLIBS) $< -o $@

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies
endGame.o: endGame.c game.h endGame.h initGame.h
initGame.o: initGame.c game.h initGame.h
main.o: main.c game.h initGame.h playGame.h
playGame.o: playGame.c game.h playGame.h
