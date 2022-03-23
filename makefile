build: ttt_game.cpp
	g++ -Wall ttt_game.cpp -o TicTacToe

debug:
	g++ -g -Wall ttt_game.cpp -o TicTacToe

run:
	./TicTacToe
