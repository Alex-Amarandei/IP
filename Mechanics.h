#pragma once
#include "Structures.h"
#include "graphics.h"
#include "Initials.h"
#include <time.h>
#include <iostream>

using namespace std;

void play();

void startGame(Board& board, Player& playerOne, Player& playerTwo, OPiece& oPieceOne, OPiece& oPieceTwo);
void takeTurn(Player& player);
void moveOPiece(OPiece& oPiecee);

void upArrowPressed(Player& player, bool trigger); 
void leftArrowPressed(Player& player, bool trigger);
void rightArrowPressed(Player& player, bool trigger); 
void downArrowPressed(Player& player, bool trigger); 

void positionWanted(Player& playerr, int number, bool trigger);

void upArrowPressed(OPiece& oPiece); 
void leftArrowPressed(OPiece& oPiece);
void rightArrowPressed(OPiece& oPiece);
void downArrowPressed(OPiece& oPiece); 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void play() {
	createStartPage();
	while (!goBack) {
		createMenu(); initialTime = time(0);
		startGame(board, player[1], player[2], oPiece[1], oPiece[2]);
		goBack = false;
	}
}

void startGame(Board& boardd, Player& playerOne, Player& playerTwo, OPiece& oPieceOne, OPiece& oPieceTwo) {
	int x = 0, y = 0;

	PlaySound(TEXT("load.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setInitialState();
	setUpBoard(boardd);
	setUpPieces(playerOne.lPiece, playerTwo.lPiece, oPieceOne, oPieceTwo);
	instructions(game.instructionsEnabled);
	createQuitBack(1);

	while (!game.isOver) {
		player[0] = player[1]; playerNames(1, 0); takeTurn(playerOne);
		if (gameWasWon(boardd, 1)) {
			game.isOver = true; break;
		}
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++)
				cout << board.table[i][j].value << ' ';
			cout << '\n';
		}
		if (goBack) {
			cleardevice(); return;
		}

		switch (game.COM) {
		case 0: {
			player[0] = player[2]; playerNames(0, 1); takeTurn(playerTwo);
			if (gameWasWon(boardd, 2)) {
				game.isOver = true; break;
			}
			break;
		}

		case 1: {
			easyCOM();
			if (gameWasWon(boardd, 2)) {
				game.isOver = true; break;
			} break; }
		case 2: {
			mediumCOM();
			if (gameWasWon(boardd, 2)) {
				game.isOver = true; break;
			} break; }
		case 3: {
			hardCOM();
			if (gameWasWon(boardd, 2)) {
				game.isOver = true;
				for (int i = 1; i <= 4; i++) {
					for (int j = 1; j <= 4; j++)
						cout << board.table[i][j].value << ' ';
					cout << '\n';
				}
				break;
			} break; }
		default: break;
		}

		if (goBack) {
			cleardevice(); return;
		}

		playerOne.toMove = !playerOne.toMove;
		playerTwo.toMove = !playerTwo.toMove;
	}

	if (player[1].moves > player[2].moves) winnerMessage(player[1]);
	else winnerMessage(player[2]);
}

void takeTurn(Player& playerr) {
	char key;
	bool switchTriggered = true, turnOver = false;
	int x, y;

	if (!playerr.toMove) return;

	playerr.lPiece.color = 4; markLPiece(playerr.lPiece, 0); playerr.moves++;

	while (!turnOver) {
		getmouseclick(WM_LBUTTONDOWN, x, y);

		if (x >= 60 && x <= 300 && y >= h - 80 && y <= h - 20) {
			key = 1; cleardevice(); goBack = true; return;
		}

		if (x >= w - 240 && x <= w - 60 && y >= h - 85 && y <= h - 20) {
			key = 1; cleardevice(); exit(0);
		}
		//////////////////////////////////////////////////////
		key = getch();

		tileStyle(board.tileColor); markLPiece(playerr.lPiece, -1, 1);

		if (playerr.lPiece.player == 1) {
			lPieceStyle(player[2].lPiece.color); createLPiece(player[2].lPiece);
		}
		else {
			lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece);
		}

		oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]); oPieceStyle(oPiece[2].color); createOPiece(oPiece[2]);

		switch (key) {
		case 32: switchTriggered = !switchTriggered; break;
		case 49: positionWanted(playerr, 1, switchTriggered); break;
		case 50: positionWanted(playerr, 2, switchTriggered); break;
		case 51: positionWanted(playerr, 3, switchTriggered); break;
		case 52: positionWanted(playerr, 4, switchTriggered); break;
		case 53: positionWanted(playerr, 5, switchTriggered); break;
		case 54: positionWanted(playerr, 6, switchTriggered); break;
		case 55: positionWanted(playerr, 7, switchTriggered); break;
		case 56: positionWanted(playerr, 8, switchTriggered); break;
		case 72: upArrowPressed(playerr, switchTriggered); break;
		case 75: leftArrowPressed(playerr, switchTriggered); break;
		case 77: rightArrowPressed(playerr, switchTriggered); break;
		case 80: downArrowPressed(playerr, switchTriggered); break;
		case 97: leftArrowPressed(playerr, switchTriggered); break;
		case 100: rightArrowPressed(playerr, switchTriggered); break;
		case 115: downArrowPressed(playerr, switchTriggered); break;
		case 119: upArrowPressed(playerr, switchTriggered); break;
		case 99: {
			game.theme = (game.theme + 1) % 4; setColors(game.theme);
			lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece); lPieceStyle(player[2].lPiece.color); createLPiece(player[2].lPiece);
			oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]); createOPiece(oPiece[2]); break;
		}
		case 102: game.isSuddenDeath = !game.isSuddenDeath; break;
		case 105: game.instructionsEnabled = !game.instructionsEnabled; instructions(game.instructionsEnabled); break;
		default: break;
		}

		lPieceStyle(playerr.lPiece.color); createLPiece(playerr.lPiece);

		if (key == 'o' && isPositionValid(board, playerr.lPiece)) {
			turnOver = true;
			playerr.lPiece.color = board.playerColor[playerr.lPiece.player]; markLPiece(playerr.lPiece, playerr.lPiece.player);
			createLPiece(playerr.lPiece);
		}

		//////////////////////////////////////////////////
		
		getmouseclick(WM_LBUTTONDOWN, x, y);

		if (x >= 60 && x <= 300 && y >= h - 80 && y <= h - 20) {
			key = 1; cleardevice(); goBack = true; return;
		}

		if (x >= w - 240 && x <= w - 60 && y >= h - 85 && y <= h - 20) {
			key = 1; cleardevice(); exit(0);
		}
		
		/////////////////////////////////////////////////
	}

	oPiece[0] = oPiece[1]; moveOPiece(oPiece[1]);

	if ((oPiece[0].x == oPiece[1].x && oPiece[0].y == oPiece[1].y) || game.isSuddenDeath)
		moveOPiece(oPiece[2]);
	
	////////////////////////////////////////////////
	
	getmouseclick(WM_LBUTTONDOWN, x, y);

	if (x >= 60 && x <= 300 && y >= h - 80 && y <= h - 20) {
		key = 1; cleardevice(); goBack = true; return;
	}

	if (x >= w - 240 && x <= w - 60 && y >= h - 85 && y <= h - 20) {
		key = 1; cleardevice(); exit(0);
	}
	
	///////////////////////////////////////////
}

void upArrowPressed(Player& playerr, bool trigger) {
	if (trigger) {
		playerr.lPiece.corner.x -= 1;
		if (isOutOfBounds(playerr.lPiece)) playerr.lPiece.corner.x += 1;
	}
	else {
		playerr.lPiece.position = (playerr.lPiece.position + 12) % 8;
		if (playerr.lPiece.position == 0) playerr.lPiece.position = 8;

		nextPositionAvailable(playerr.lPiece);
	}
}

void leftArrowPressed(Player& playerr, bool trigger) {
	if (trigger) {
		playerr.lPiece.corner.y -= 1;
		if (isOutOfBounds(playerr.lPiece)) playerr.lPiece.corner.y += 1;
	}
	else {
		playerr.lPiece.position = (playerr.lPiece.position + 7) % 8;
		if (playerr.lPiece.position == 0) playerr.lPiece.position = 8;

		nextPositionAvailable(playerr.lPiece);
	}
}

void rightArrowPressed(Player& playerr, bool trigger) {
	if (trigger) {
		playerr.lPiece.corner.y += 1;
		if (isOutOfBounds(playerr.lPiece)) playerr.lPiece.corner.y -= 1;
	}
	else {
		playerr.lPiece.position = (playerr.lPiece.position + 9) % 8;
		if (playerr.lPiece.position == 0) playerr.lPiece.position = 8;

		nextPositionAvailable(playerr.lPiece);
	}
}

void downArrowPressed(Player& playerr, bool trigger) {
	if (trigger) {
		playerr.lPiece.corner.x += 1;
		if (isOutOfBounds(playerr.lPiece)) playerr.lPiece.corner.x -= 1;
	}
	else {
		playerr.lPiece.position = (playerr.lPiece.position + 12) % 8;
		if (playerr.lPiece.position == 0) playerr.lPiece.position = 8;

		nextPositionAvailable(playerr.lPiece);
	}
}

void positionWanted(Player& playerr, int number, bool trigger) {
	if (trigger) return;

	playerr.lPiece.position = number;
	nextPositionAvailable(playerr.lPiece);
}

void upArrowPressed(OPiece& oPiecee) {
	if (oPiecee.x - 1 > 0) oPiecee.x -= 1;
}

void leftArrowPressed(OPiece& oPiecee) {
	if (oPiecee.y - 1 > 0) oPiecee.y -= 1;
}

void rightArrowPressed(OPiece& oPiecee) {
	if (oPiecee.y + 1 < 5) oPiecee.y += 1;
}

void downArrowPressed(OPiece& oPiecee) {
	if (oPiecee.x + 1 < 5) oPiecee.x += 1;
}

void moveOPiece(OPiece& oPiecee) {
	bool turnOver = false;
	char key;

	oPiecee.color = 4; oPieceStyle(oPiecee.color); createOPiece(oPiecee); board.table[oPiecee.x][oPiecee.y].value = 0;

	key = getch();

	if (key == 'o') {
		oPiecee.color = board.oPieceColor[1]; createOPiece(oPiecee); board.table[oPiecee.x][oPiecee.y].value = oPiecee.number;
	}
	else {
		while (!turnOver) {
			tileStyle(board.tileColor); fillTile(oPiecee.x, oPiecee.y, 0);

			switch (key) {
			case 72: upArrowPressed(oPiecee); break;
			case 75: leftArrowPressed(oPiecee); break;
			case 77: rightArrowPressed(oPiecee); break;
			case 80: downArrowPressed(oPiecee); break;
			case 97: leftArrowPressed(oPiecee); break;
			case 100: rightArrowPressed(oPiecee); break;
			case 115: downArrowPressed(oPiecee); break;
			case 119: upArrowPressed(oPiecee); break;
			case 99: {
				game.theme = (game.theme + 1) % 4; setColors(game.theme);
				lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece); lPieceStyle(player[2].lPiece.color); createLPiece(player[2].lPiece);
				oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]); createOPiece(oPiece[2]); break;
			}
			case 102: game.isSuddenDeath = !game.isSuddenDeath; break;
			case 105: game.instructionsEnabled = !game.instructionsEnabled; instructions(game.instructionsEnabled); break;
			default: break;
			}

			lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece); markLPiece(player[1].lPiece, 1);
			lPieceStyle(player[2].lPiece.color); createLPiece(player[2].lPiece); markLPiece(player[2].lPiece, 2);

			if (oPiecee.number == 3) {
				oPieceStyle(oPiece[2].color); createOPiece(oPiece[2]);
			}
			else {
				oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]);
			}
			createOPiece(oPiecee);

			if (key == 'o' && board.table[oPiecee.x][oPiecee.y].value == 0) turnOver = true;

			key = getch();
		}

		board.table[oPiecee.x][oPiecee.y].value = oPiecee.number;
		oPiecee.color = board.oPieceColor[1]; setfillstyle(1, oPiecee.color); createOPiece(oPiecee);
	}
}