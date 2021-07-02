# This Makefile
# gives instructions to the command
# make
# about how and whether to build programs


all: mono  

mono : monopoly_board.cpp
	g++ monopoly_board.cpp -o mono -lsfml-graphics -lsfml-window -lsfml-system


