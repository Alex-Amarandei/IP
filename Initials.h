#pragma once
#include "Structures.h"
#include "graphics.h"
#include <mmsystem.h>
#include "Miscellaneous.h"
#include "Visuals.h"
#include "Computer.h"

void createStartPage();
void createMenu(); 
void selectDifficulty();

void setInitialState(); 

void setUpBoard(Board& board); 
void createBorder(Board& board); 
void setUpPieces(LPiece lPiece1, LPiece lPiece2, OPiece oPiece1, OPiece oPiece2);

/////////////////////////////////////////////////////////////////////////////////

void createStartPage() {
	initwindow(w + 20, h + 10, "L-Game", -12);
	PlaySound(TEXT("begin.wav"), NULL, SND_FILENAME | SND_ASYNC);
	readimagefile("poza1.jpg", 140, 140, 240, 280); // lungimea L-ului este de 140, latimea este de 100
	readimagefile("poza2.jpg", 520, 60, 660, 160);
	readimagefile("poza3.jpg", 880, 140, 980, 280);
	readimagefile("poza4.jpg", 1240, 60, 1380, 160);

	readimagefile("poza5.jpg", 140, h - 240, 240, h - 380);
	readimagefile("poza6.jpg", 520, h - 160, 660, h - 260);
	readimagefile("poza7.jpg", 880, h - 240, 980, h - 380);
	readimagefile("poza8.jpg", 1240, h - 160, 1380, h - 260);

	readimagefile("lgame.jpg", w / 2 - 200, h / 2 - 40, w / 2 + 200, h / 2 + 40);

	delay(4000);

	cleardevice();
}

void createMenu() {
	int x, y;
	PlaySound(TEXT("difficulty.wav"), NULL, SND_FILENAME | SND_ASYNC);
	readimagefile("poza1.jpg", 60, 60, 160, 200); 
	readimagefile("poza2.jpg", 260, 280, 400, 380);
	readimagefile("poza3.jpg", 60, 460, 160, 600);
	readimagefile("poza4.jpg", 260, 680, 400, 780);

	readimagefile("poza5.jpg", w - 160, 60, w - 60, 200); 
	readimagefile("poza6.jpg", w - 400, 280, w - 260, 380);
	readimagefile("poza7.jpg", w - 160, 460, w - 60, 600);
	readimagefile("poza8.jpg", w - 400, 680, w - 260, 780);

	readimagefile("lgame.jpg", w / 2 - 200, 40, w / 2 + 200, 120);

	readimagefile("player.jpg", w / 2 - 260, h / 4 + 60, w / 2 - 60, h / 4 + 400);
	readimagefile("computer.jpg", w / 2 + 60, h / 4 + 60, w / 2 + 260, h / 4 + 400);

	createQuitBack(0);

	while (1) {
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (x >= (w / 2 - 260) && x <= (w / 2 - 60) && y >= (h / 4 + 60) && y <= (h / 4 + 400)) {
			game.COM = 0; cleardevice(); break;
		}

		if (x >= (w / 2 + 60) && x <= (w / 2 + 260) && y >= (h / 4 + 60) && y <= (h / 4 + 400)) {
			cleardevice(); selectDifficulty(); break;
		}

		if (x >= (w / 2 - 90) && x <= (w / 2 + 90) && y >= (h - 100) && y <= (h - 20)) {
			exit(0);
		}
	}
}

void selectDifficulty() {
	int x, y;
	PlaySound(TEXT("difficulty.wav"), NULL, SND_FILENAME | SND_ASYNC);
	readimagefile("poza1.jpg", 60, 60, 160, 200); // lungimea L-ului este de 140, latimea este de 100
	readimagefile("poza2.jpg", 260, 280, 400, 380);
	readimagefile("poza3.jpg", 60, 460, 160, 600);
	readimagefile("poza4.jpg", 260, 680, 400, 780);

	readimagefile("poza5.jpg", w - 160, 60, w - 60, 200); // lungimea L-ului este de 140, latimea este de 100
	readimagefile("poza6.jpg", w - 400, 280, w - 260, 380);
	readimagefile("poza7.jpg", w - 160, 460, w - 60, 600);
	readimagefile("poza8.jpg", w - 400, 680, w - 260, 780);

	readimagefile("lgame.jpg", w / 2 - 200, 40, w / 2 + 200, 120);

	readimagefile("easy.jpg", w / 2 - 250, h / 2 - 200, w / 2 + 250, h / 2 - 50);
	readimagefile("medium.jpg", w / 2 - 250, h / 2, w / 2 + 270, h / 2 + 150);
	readimagefile("hard.jpg", w / 2 - 250, h / 2 + 200, w / 2 + 260, h / 2 + 350);

	while (1) {
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (x >= (w / 2 - 250) && x <= (w / 2 + 250) && y >= (h / 2 - 200) && y <= (h / 2 - 50)) {
			game.COM = 1; cleardevice(); break;
		}

		if (x >= (w / 2 - 250) && x <= (w / 2 + 270) && y >= (h / 2) && y <= (h / 2 + 150)) {
			game.COM = 2; cleardevice(); break;
		}

		if (x >= (w / 2 - 250) && x <= (w / 2 + 260) && y >= (h / 2 + 200) && y <= (h / 2 + 350)) {
			game.COM = 3; cleardevice(); break;
		}
	}
}

void setInitialState() {
	createTheme(); setColors(0); game.isOver = false;
	game.isSuddenDeath = false; game.instructionsEnabled = true;

	player[1].lPiece.color = board.playerColor[1];
	player[1].lPiece.corner.x = 4;
	player[1].lPiece.corner.y = 2;
	player[1].lPiece.position = 1;
	player[1].lPiece.player = 1;
	player[1].toMove = true;
	player[1].moves = 0;

	player[2].lPiece.color = board.playerColor[2];
	player[2].lPiece.corner.x = 1;
	player[2].lPiece.corner.y = 3;
	player[2].lPiece.position = 3;
	player[2].lPiece.player = 2;
	player[2].moves = 0;

	oPiece[1].number = 3; oPiece[2].number = 4;
	oPiece[1].x = oPiece[1].y = 1;
	oPiece[2].x = oPiece[2].y = 4;

	createDirection();
}

void setUpBoard(Board& board) {
	createBorder(board);
	createTiles(board);
}

void createBorder(Board& board) {
	borderStyle(board.borderColor);
	rectangle(board.left, board.top, board.right, board.bottom);
}

void setUpPieces(LPiece lPiece1, LPiece lPiece2, OPiece oPiece1, OPiece oPiece2) {
	lPieceStyle(lPiece1.color); createLPiece(lPiece1); markLPiece(lPiece1, lPiece1.player);
	lPieceStyle(lPiece2.color);	createLPiece(lPiece2); markLPiece(lPiece2, lPiece2.player);
	oPieceStyle(oPiece1.color); createOPiece(oPiece1); board.table[oPiece1.x][oPiece1.y].value = 3;
	oPieceStyle(oPiece2.color); createOPiece(oPiece2); board.table[oPiece2.x][oPiece2.y].value = 4;
}