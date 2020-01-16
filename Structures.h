#pragma once

int w = getmaxwidth(), h = getmaxheight();
time_t initialTime, finalTime;
bool goBack = false;

struct Point {
	int x, y;
} direction[9][5], neighbor[25]; 

struct Tile {
	int left, top, right, bottom;
	int size = 127, value = 0; 
};

struct OPiece {
	Tile piece; 
	int color = 7, x, y, number; 
} oPiece[3];

struct LPiece {
	int color, position, player; 
	Point corner; 
};

struct Player {
	LPiece lPiece; 
	int moves = 0; 
	bool toMove = false; 
} player[3];

struct ColorScheme {
	int playerOne, playerTwo, oPieces;
} theme[4];

struct Board {
	int size = 510, left = 510, top = 162, right = 1020, bottom = 672;
	int borderColor = 3, tileColor = 15, backgroundColor = 0;
	int oPieceColor[3] = { 0, 7, 15 }, playerColor[3] = { 0, 1, 2 };
	Tile table[5][5];
} board;

struct Game {
	bool isOver = false, isSuddenDeath = false, instructionsEnabled = true;
	int theme = 0, COM = 3;
} game;