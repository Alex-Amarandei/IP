#pragma once
#include "Structures.h"
#include "graphics.h"

void createTheme(); 
void setColors(int number); 

void borderStyle(int borderColor); 
void tileStyle(int tileColor); 
void oPieceStyle(int color); 
void lPieceStyle(int color); 

void createOPiece(OPiece oPiece); 
void createLPiece(LPiece lPiece); 
void createTiles(Board& board); 
Tile setTile(int x, int y); 
void fillTile(int x, int y, int color); 
void markLPiece(LPiece lPiece, int number, bool clear = 0); 

//////////////////////////////////////////////////////////////////////////////////////////////////

void createTheme() {
	theme[0].playerOne = 1; theme[0].playerTwo = 2; theme[0].oPieces = 7;
	theme[1].playerOne = 11; theme[1].playerTwo = 12; theme[1].oPieces = 10;
	theme[2].playerOne = 3; theme[2].playerTwo = 5; theme[2].oPieces = 14;
	theme[3].playerOne = 14; theme[3].playerTwo = 8; theme[3].oPieces = 11;
}

void setColors(int number) {
	board.playerColor[1] = theme[number].playerOne;
	board.playerColor[2] = theme[number].playerTwo;
	board.oPieceColor[1] = theme[number].oPieces;
	board.oPieceColor[2] = theme[number].oPieces;

	if (player[1].lPiece.color != 4) player[1].lPiece.color = theme[number].playerOne;
	if (player[2].lPiece.color != 4) player[2].lPiece.color = theme[number].playerTwo;
	if (oPiece[1].color != 4) oPiece[1].color = theme[number].oPieces;
	if (oPiece[1].color != 4) oPiece[2].color = theme[number].oPieces;
}

void borderStyle(int borderColor) {
	setlinestyle(1, 0, 3);
	setcolor(borderColor);
}

void tileStyle(int tileColor) {
	setlinestyle(0, 0, 1);
	setcolor(tileColor);
}

void oPieceStyle(int color) {
	setlinestyle(0, 0, 1);
	setcolor(color);
	setfillstyle(1, color);
}

void lPieceStyle(int color) {
	setlinestyle(0, 0, 1);
	setcolor(color);
}

void createOPiece(OPiece oPiece) {
	setfillstyle(1, oPiece.color);
	fillellipse((board.table[oPiece.x][oPiece.y].right + board.table[oPiece.x][oPiece.y].left) / 2,
		(board.table[oPiece.x][oPiece.y].top + board.table[oPiece.x][oPiece.y].bottom) / 2,
		board.table[oPiece.x][oPiece.y].size / 3, board.table[oPiece.x][oPiece.y].size / 3);
}

void createLPiece(LPiece lPiece) {
	int i;

	for (i = 1; i <= 4; i++) {
		fillTile(lPiece.corner.x + direction[lPiece.position][i].x, lPiece.corner.y + direction[lPiece.position][i].y, lPiece.color);
	}
}

void createTiles(Board& board) {
	int i, j;
	tileStyle(board.tileColor);

	for (i = 1; i <= 4; ++i)
		for (j = 1; j <= 4; ++j) {
			board.table[i][j] = setTile(i, j);
			rectangle(board.table[i][j].left, board.table[i][j].top, board.table[i][j].right, board.table[i][j].bottom);
		}
}

Tile setTile(int x, int y) {
	Tile tile;

	switch (x) {
	case 1:	tile.top = board.top; break;
	case 2: tile.top = board.top + tile.size; break;
	case 3:	tile.top = board.top + board.size / 2; break;
	case 4: tile.top = board.bottom - tile.size; break;
	}

	switch (y) {
	case 1: tile.left = board.left; break;
	case 2: tile.left = board.left + tile.size; break;
	case 3: tile.left = board.left + board.size / 2; break;
	default: tile.left = board.right - tile.size; break;
	}

	tile.right = tile.left + tile.size;
	tile.bottom = tile.top + tile.size;

	return tile;
}

void fillTile(int x, int y, int color) {
	setfillstyle(1, color);

	int poly[8] = { board.table[x][y].left, board.table[x][y].top,
		board.table[x][y].left,	board.table[x][y].top + board.table[x][y].size,
		board.table[x][y].right, board.table[x][y].bottom,
		board.table[x][y].left + board.table[x][y].size, board.table[x][y].top };

	fillpoly(4, poly);
}

void markLPiece(LPiece lPiece, int number, bool clear) {
	int i;

	for (i = 1; i <= 4; ++i) {
		if (number > -1)
			board.table[lPiece.corner.x + direction[lPiece.position][i].x][lPiece.corner.y + direction[lPiece.position][i].y].value = number;
		if (clear)
			fillTile(lPiece.corner.x + direction[lPiece.position][i].x, lPiece.corner.y + direction[lPiece.position][i].y, 0);
	}
}
