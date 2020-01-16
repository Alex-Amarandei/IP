#pragma once
#include "Structures.h"
#include "graphics.h"

void createDirection();
void createQuitBack(bool isBack);
void instructions(bool enabled); 
void playerNames(bool isOne, bool isTwo); 
void winnerMessage(Player player); 

bool isOutOfBounds(LPiece lPiece); 
void nextPositionAvailable(LPiece& lPiece);
bool isPositionValid(Board board, LPiece lPiece); 
bool gameWasWon(Board board, int number); 
bool isInCorner(LPiece lPiece);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void createDirection() {
	direction[1][1].x = -2; direction[1][1].y = 0;
	direction[1][2].x = -1; direction[1][2].y = 0;
	direction[1][3].x = 0; direction[1][3].y = 0;
	direction[1][4].x = 0; direction[1][4].y = 1;

	direction[2][1].x = 0; direction[2][1].y = 2;
	direction[2][2].x = 0; direction[2][2].y = 1;
	direction[2][3].x = 0; direction[2][3].y = 0;
	direction[2][4].x = 1; direction[2][4].y = 0;

	direction[3][1].x = 2; direction[3][1].y = 0;
	direction[3][2].x = 1; direction[3][2].y = 0;
	direction[3][3].x = 0; direction[3][3].y = 0;
	direction[3][4].x = 0; direction[3][4].y = -1;

	direction[4][1].x = 0; direction[4][1].y = -2;
	direction[4][2].x = 0; direction[4][2].y = -1;
	direction[4][3].x = 0; direction[4][3].y = 0;
	direction[4][4].x = -1; direction[4][4].y = 0;

	direction[5][1].x = 2; direction[5][1].y = 0;
	direction[5][2].x = 1; direction[5][2].y = 0;
	direction[5][3].x = 0; direction[5][3].y = 0;
	direction[5][4].x = 0; direction[5][4].y = 1;

	direction[6][1].x = 0; direction[6][1].y = 2;
	direction[6][2].x = 0; direction[6][2].y = 1;
	direction[6][3].x = 0; direction[6][3].y = 0;
	direction[6][4].x = -1; direction[6][4].y = 0;

	direction[7][1].x = -2; direction[7][1].y = 0;
	direction[7][2].x = -1; direction[7][2].y = 0;
	direction[7][3].x = 0; direction[7][3].y = 0;
	direction[7][4].x = 0; direction[7][4].y = -1;

	direction[8][1].x = 0; direction[8][1].y = -2;
	direction[8][2].x = 0; direction[8][2].y = -1;
	direction[8][3].x = 0; direction[8][3].y = 0;
	direction[8][4].x = 1; direction[8][4].y = 0;

	neighbor[0].x = 0; neighbor[0].y = 0;

	neighbor[1].x = -1; neighbor[1].y = 0;
	neighbor[2].x = -1; neighbor[2].y = 1;
	neighbor[3].x = 0; neighbor[3].y = 1;
	neighbor[4].x = 1; neighbor[4].y = 1;
	neighbor[5].x = 1; neighbor[5].y = 0;
	neighbor[6].x = 1; neighbor[6].y = -1;
	neighbor[7].x = 0; neighbor[7].y = -1;
	neighbor[8].x = -1; neighbor[8].y = -1;

	neighbor[9].x = -2; neighbor[9].y = 0;
	neighbor[10].x = -2; neighbor[10].y = 1;
	neighbor[11].x = -2; neighbor[11].y = 2;
	neighbor[12].x = -1; neighbor[12].y = 2;
	neighbor[13].x = 0; neighbor[13].y = 2;
	neighbor[14].x = 1; neighbor[14].y = 2;
	neighbor[15].x = 2; neighbor[15].y = 2;
	neighbor[16].x = 2; neighbor[16].y = 1;
	neighbor[17].x = 2; neighbor[17].y = 0;
	neighbor[18].x = 2; neighbor[18].y = -1;
	neighbor[19].x = 2; neighbor[19].y = -2;
	neighbor[20].x = 1; neighbor[20].y = -2;
	neighbor[21].x = 0; neighbor[21].y = -2;
	neighbor[22].x = -1; neighbor[22].y = -2;
	neighbor[23].x = -2; neighbor[23].y = -2;
	neighbor[24].x = -2; neighbor[24].y = -1;
}

void createQuitBack(bool isBack) {
	if (!isBack)
		readimagefile("quit.jpg", w / 2 - 90, h - 100, w / 2 + 90, h - 20);
	else {
		readimagefile("back.jpg", 60, h - 80, 300, h - 20);
		readimagefile("quit.jpg", w - 240, h - 85, w - 60, h - 20);
	}
}

void instructions(bool enabled) {
	if (enabled) {
		readimagefile("positions.jpg", 0, 80, 360, 320);
		readimagefile("instructions.jpg", w - 360, 80, w, 320);
	}
	else {
		int poly[8];

		poly[0] = 0; poly[1] = 80;
		poly[2] = 360; poly[3] = 80;
		poly[4] = 360; poly[5] = 320;
		poly[6] = 0; poly[7] = 320;


		setfillstyle(1, 0);	setcolor(0); fillpoly(4, poly);

		poly[0] = w - 360; poly[1] = 80;
		poly[2] = w; poly[3] = 80;
		poly[4] = w; poly[5] = 320;
		poly[6] = w - 360; poly[7] = 320;

		fillpoly(4, poly);
	}
}

void playerNames(bool isOne, bool isTwo) {
	setcolor(15); settextstyle(3, 0, 0);

	if (isOne) outtextxy(160, 600, "Player One");
	else {
		int poly[8];
		setcolor(0); setfillstyle(1, 0);
		poly[0] = 160; poly[1] = 600;
		poly[2] = 360; poly[3] = 600;
		poly[4] = 360; poly[5] = 640;
		poly[6] = 160; poly[7] = 640;
		fillpoly(4, poly);
	}

	setcolor(15); settextstyle(3, 0, 0);

	if (isTwo) outtextxy(1160, 600, "Player Two");
	else {
		int poly[8];
		setcolor(0); setfillstyle(1, 0);
		poly[0] = 1160; poly[1] = 600;
		poly[2] = 1360; poly[3] = 600;
		poly[4] = 1360; poly[5] = 640;
		poly[6] = 1160; poly[7] = 640;
		fillpoly(4, poly);
	}
}

void winnerMessage(Player player) {
	int minutes, seconds, extra = 0;
	char aux[5], message[40] = {};

	PlaySound(TEXT("winner.wav"), NULL, SND_FILENAME | SND_ASYNC);

	playerNames(0, 0); setcolor(player.lPiece.color);

	if (player.lPiece.player == 2) extra = 1000;

	finalTime = time(0); minutes = (finalTime - initialTime) / 60; seconds = (finalTime - initialTime) % 60;
	itoa(minutes, aux, 10); strcat(message, aux); strcat(message, " minutes, "); strcpy(aux, "");
	itoa(seconds, aux, 10); strcat(message + strlen(message), aux); strcat(message + strlen(message), " seconds"); strcpy(aux, "");

	settextstyle(3, 0, 30); outtextxy(160 + extra, 500, "WINNER!");
	settextstyle(3, 0, 4); outtextxy(110 + extra, 600, message); strcpy(message, "");

	itoa(player.moves, aux, 10); strcat(message + strlen(message), aux); strcat(message + strlen(message), " moves!");

	outtextxy(220 + extra, 650, message);

	delay(7000); cleardevice();
}

bool isOutOfBounds(LPiece lPiece) {
	int i;

	for (i = 1; i <= 4; i++) {
		if (lPiece.corner.x + direction[lPiece.position][i].x < 1 || lPiece.corner.x + direction[lPiece.position][i].x > 4 ||
			lPiece.corner.y + direction[lPiece.position][i].y < 1 || lPiece.corner.y + direction[lPiece.position][i].y > 4)
			return true;
	}

	return false;
}

void nextPositionAvailable(LPiece& lPiece) {
	int i;

	for (i = 0; i <= 24; ++i) {
		lPiece.corner.x += neighbor[i].x;
		lPiece.corner.y += neighbor[i].y;

		if (!isOutOfBounds(lPiece))
			return;

		lPiece.corner.x -= neighbor[i].x;
		lPiece.corner.y -= neighbor[i].y;
	}
}

bool isPositionValid(Board board, LPiece lPiece) {
	int i;

	if (isOutOfBounds(lPiece)) return false;

	if (lPiece.corner.x == player[0].lPiece.corner.x && lPiece.corner.y == player[0].lPiece.corner.y && lPiece.position == player[0].lPiece.position)
		return false;

	for (i = 1; i <= 4; ++i) {
		if (board.table[lPiece.corner.x + direction[lPiece.position][i].x][lPiece.corner.y + direction[lPiece.position][i].y].value != 0)
			return false;
	}

	return true;
}

bool gameWasWon(Board board, int number) {
	int i, j, k, other;
	Player test;
	Board table = board;
	if (number == 1) other = 2;
	else other = 1;
	test = player[other]; player[0] = test;

	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
			if (table.table[i][j].value == other)
				table.table[i][j].value = 0;

	for (k = 1; k <= 8; k++) {
		test.lPiece.position = k;
		for (i = 1; i <= 4; i++) {
			test.lPiece.corner.x = i;
			for (j = 1; j <= 4; j++) {
				test.lPiece.corner.y = j;
				if (isPositionValid(table, test.lPiece))
					return false;
			}
		}
	}

	return true;
}

bool isInCorner(LPiece lPiece) {
	if ((lPiece.corner.x == 1 && (lPiece.corner.y == 1 || lPiece.corner.y == 4)) ||
		(lPiece.corner.x == 4 && (lPiece.corner.y == 1 || lPiece.corner.y == 4)))
		return true;
	return false;
}
