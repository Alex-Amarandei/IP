#pragma once
#include "Structures.h"
#include <time.h>
#include "graphics.h"

void easyCOM();
void mediumCOM();
void hardCOM(); 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void easyCOM() {
	if (!player[2].toMove) return;
	player[2].moves++;

	int i, j, k, nrO;
	bool willMove, ok = true;
	player[0] = player[2];
	time_t t; srand((unsigned)&t);

	tileStyle(board.tileColor); markLPiece(player[2].lPiece, 0, 1);
	lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece);
	oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]); oPieceStyle(oPiece[2].color); createOPiece(oPiece[2]);

	if (rand() % 2)
		for (i = 1; i <= 4 && ok; ++i) {
			player[2].lPiece.corner.x = i;
			for (j = 1; j <= 4 && ok; ++j) {
				player[2].lPiece.corner.y = j;
				for (k = 1; k <= 8; ++k) {
					player[2].lPiece.position = k;
					if (isPositionValid(board, player[2].lPiece)) {
						lPieceStyle(player[2].lPiece.color);
						createLPiece(player[2].lPiece);
						markLPiece(player[2].lPiece, 2);
						ok = false; break;
					}
				}
			}
		}
	else {
		for (i = 4; i >= 1 && ok; --i) {
			player[2].lPiece.corner.x = i;
			for (j = 4; j >= 1 && ok; --j) {
				player[2].lPiece.corner.y = j;
				for (k = 8; k >= 1; --k) {
					player[2].lPiece.position = k;
					if (isPositionValid(board, player[2].lPiece)) {
						lPieceStyle(player[2].lPiece.color);
						createLPiece(player[2].lPiece);
						markLPiece(player[2].lPiece, 2);
						ok = false; break;
					}
				}
			}
		}
	}


	ok = true;

	if (willMove = rand() % 2) {
		nrO = rand() % 2 + 1;

		for (i = 1; i <= 4 && ok; ++i)
			for (j = 1; j <= 4; ++j)
				if (board.table[i][j].value == 0) {
					board.table[oPiece[nrO].x][oPiece[nrO].y].value = 0; fillTile(oPiece[nrO].x, oPiece[nrO].y, 0);
					oPiece[nrO].x = i; oPiece[nrO].y = j;
					board.table[oPiece[nrO].x][oPiece[nrO].y].value = 2 + nrO; oPieceStyle(oPiece[nrO].color); createOPiece(oPiece[nrO]);
					ok = false; break;
				}
	}
}

void mediumCOM() {
	if (!player[2].toMove) return;
	player[2].moves++;

	int i, j, k = 0, nrO;
	bool ok = true;
	player[0] = player[2];
	time_t t; srand((unsigned)&t);

	tileStyle(board.tileColor); markLPiece(player[2].lPiece, 0, 1);
	lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece);
	oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]); oPieceStyle(oPiece[2].color); createOPiece(oPiece[2]);

	nrO = rand() % 2 + 1;

	if (rand() % 2)
		for (k = 1; k <= 8 && ok; ++k) {
			player[2].lPiece.position = k;
			for (i = 1; i <= 4 && ok; ++i) {
				player[2].lPiece.corner.x = i;
				for (j = 1; j <= 4; ++j) {
					player[2].lPiece.corner.y = j;
					if (isPositionValid(board, player[2].lPiece)) {
						lPieceStyle(player[2].lPiece.color);
						createLPiece(player[2].lPiece);
						markLPiece(player[2].lPiece, 2);
						ok = false; break;
					}
				}
			}
		}
	else {
		for (k = 8; k >= 1 && ok; --k) {
			player[2].lPiece.position = k;
			for (i = 4; i >= 1 && ok; --i) {
				player[2].lPiece.corner.x = i;
				for (j = 4; j >= 1; --j) {
					player[2].lPiece.corner.y = j;
					if (isPositionValid(board, player[2].lPiece)) {
						lPieceStyle(player[2].lPiece.color);
						createLPiece(player[2].lPiece);
						markLPiece(player[2].lPiece, 2);
						ok = false; break;
					}
				}
			}
		}
	}

	ok = true;

	for (i = 1; i <= 4 && ok; ++i)
		for (j = 1; j <= 4; ++j)
			if (board.table[i][j].value == 0) {
				board.table[oPiece[nrO].x][oPiece[nrO].y].value = 0; fillTile(oPiece[nrO].x, oPiece[nrO].y, 0);
				oPiece[nrO].x = i; oPiece[nrO].y = j;
				board.table[oPiece[nrO].x][oPiece[nrO].y].value = 2 + nrO; oPieceStyle(oPiece[nrO].color); createOPiece(oPiece[nrO]);
				ok = false; break;
			}

	if (game.isSuddenDeath) {
		nrO = (nrO == 3 ? 4 : 3);
		for (i = 1; i <= 4 && ok; ++i)
			for (j = 1; j <= 4; ++j)
				if (board.table[i][j].value == 0) {
					k++;
					if (k == 3) {
						board.table[oPiece[nrO].x][oPiece[nrO].y].value = 0; fillTile(oPiece[nrO].x, oPiece[nrO].y, 0);
						oPiece[nrO].x = i; oPiece[nrO].y = j;
						board.table[oPiece[nrO].x][oPiece[nrO].y].value = 2 + nrO; oPieceStyle(oPiece[nrO].color); createOPiece(oPiece[nrO]);
						ok = false; break;
					}
				}
	}
}

void hardCOM() {
	if (!player[2].toMove) return;
	player[2].moves++;

	int i, j, k = 0, nrO;
	bool ok = true, s = false;
	player[0] = player[2];
	time_t t; srand((unsigned)&t);

	tileStyle(board.tileColor); markLPiece(player[2].lPiece, 0, 1);
	lPieceStyle(player[1].lPiece.color); createLPiece(player[1].lPiece);
	oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]); oPieceStyle(oPiece[2].color); createOPiece(oPiece[2]);

	if (isInCorner(player[1].lPiece)) {
		player[2].lPiece.corner.x = (player[1].lPiece.corner.x + 2) % 4;
		if (player[1].lPiece.corner.y == 4) {
			player[2].lPiece.position = player[1].lPiece.position - 2;
		}
		else {
			player[2].lPiece.position = player[1].lPiece.position + 2;
		}
		player[2].lPiece.corner.y = (player[1].lPiece.corner.y + 2) % 4;
		if (isPositionValid(board, player[2].lPiece)) {
			lPieceStyle(player[2].lPiece.color);
			createLPiece(player[2].lPiece);
			markLPiece(player[2].lPiece, 2);
			if (player[1].lPiece.position % 2) {
				if (player[1].lPiece.corner.x == 1) { 
					if (oPiece[1].x == 4 && oPiece[1].y == player[1].lPiece.corner.y) { 
						tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (player[1].lPiece.corner.y == 1 && board.table[4][4].value == 0) {
							board.table[4][4].value = 4;
							oPiece[2].x = 4; oPiece[2].y = 4;
						}
						else if (board.table[4][1].value == 0) {
							board.table[4][1].value = 4;
							oPiece[2].x = 4; oPiece[2].y = 1;
						}
					}
					else if (oPiece[2].x == 4 && oPiece[2].y == player[1].lPiece.corner.y) { 
						tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (player[1].lPiece.corner.y == 1 && board.table[4][4].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[4][4].value = 3;
							oPiece[1].x = 4; oPiece[1].y = 4;
						}
						else if (board.table[4][1].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[4][1].value = 3;
							oPiece[1].x = 4; oPiece[1].y = 1;
						}
					}
					else { 
						if (player[1].lPiece.corner.y == 1) {
							if (oPiece[1].x == 4) {
								if (oPiece[1].y == 3 || oPiece[1].y == 4) {
									tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[4][1].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[4][1].value = 4;
										oPiece[2].x = 4; oPiece[2].y = 1;
									}
								}
							}
							else if (oPiece[1].x == 3 && oPiece[1].y == 4) {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][1].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 1;
								}
							}
							else if (oPiece[2].x == 4) {
								if (oPiece[2].y == 3 || oPiece[2].y == 4) {
									tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[4][1].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[4][1].value = 3;
										oPiece[1].x = 4; oPiece[1].y = 1;
									}
								}
							}
							else if (oPiece[2].x == 3 && oPiece[2].y == 4) {
								tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[4][1].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[4][1].value = 3;
									oPiece[1].x = 4; oPiece[1].y = 1;
								}
							}
							else {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][1].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 1;
								}
							}
						}
						else {
							if (oPiece[1].x == 4) {
								if (oPiece[1].y == 1 || oPiece[1].y == 2) {
									tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[4][4].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[4][4].value = 4;
										oPiece[2].x = 4; oPiece[2].y = 4;
									}
								}
							}
							else if (oPiece[1].x == 3 && oPiece[1].y == 1) {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][4].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 4;
								}
							}
							else if (oPiece[2].x == 4) {
								if (oPiece[2].y == 1 || oPiece[2].y == 1) {
									tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[4][4].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[4][4].value = 3;
										oPiece[1].x = 4; oPiece[1].y = 4;
									}
								}
							}
							else if (oPiece[2].x == 3 && oPiece[2].y == 1) {
								tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[4][4].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[4][4].value = 3;
									oPiece[1].x = 4; oPiece[1].y = 4;
								}
							}
							else {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][4].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 4;
								}
							}
						}
					}
				}
				else {
					if (oPiece[1].x == 1 && oPiece[1].y == player[1].lPiece.corner.y) { 
						tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (player[1].lPiece.corner.y == 1 && board.table[1][4].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[1][4].value = 4;
							oPiece[2].x = 1; oPiece[2].y = 4;
						}
						else if (board.table[1][1].value == 0) {
							board.table[1][1].value = 4;
							oPiece[2].x = 1; oPiece[2].y = 1;
						}
					}
					else if (oPiece[2].x == 1 && oPiece[2].y == player[1].lPiece.corner.y) { 
						tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (player[1].lPiece.corner.y == 1 && board.table[1][4].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[1][4].value = 3;
							oPiece[1].x = 1; oPiece[1].y = 4;
						}
						else if (board.table[1][1].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[1][1].value = 3;
							oPiece[1].x = 1; oPiece[1].y = 1;
						}
					}
					else { 
						if (player[1].lPiece.corner.y == 1) {
							if (oPiece[1].x == 1) {
								if (oPiece[1].y == 3 || oPiece[1].y == 4) {
									tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[1][1].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[1][1].value = 4;
										oPiece[2].x = 1; oPiece[2].y = 1;
									}
								}
							}
							else if (oPiece[1].x == 2 && oPiece[1].y == 4) {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][1].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 1;
								}
							}
							else if (oPiece[2].x == 1) {
								if (oPiece[2].y == 3 || oPiece[2].y == 4) {
									tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[1][1].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[1][1].value = 3;
										oPiece[1].x = 1; oPiece[1].y = 1;
									}
								}
							}
							else if (oPiece[2].x == 2 && oPiece[2].y == 4) {
								tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[1][1].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[1][1].value = 3;
									oPiece[1].x = 1; oPiece[1].y = 1;
								}
							}
							else {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][1].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 1;
								}
							}
						}
						else {
							if (oPiece[1].x == 1) {
								if (oPiece[1].y == 1 || oPiece[1].y == 2) {
									tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[1][4].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[1][4].value = 4;
										oPiece[2].x = 1; oPiece[2].y = 4;
									}
								}
							}
							else if (oPiece[1].x == 2 && oPiece[1].y == 1) {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][4].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 4;
								}
							}
							else if (oPiece[2].x == 1) {
								if (oPiece[2].y == 1 || oPiece[2].y == 2) {
									tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[1][4].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[1][4].value = 3;
										oPiece[1].x = 1; oPiece[1].y = 4;
									}
								}
							}
							else if (oPiece[2].x == 2 && oPiece[2].y == 1) {
								tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[1][4].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[1][4].value = 3;
									oPiece[1].x = 1; oPiece[1].y = 4;
								}
							}
							else {
								tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][4].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 4;
								}
							}
						}
					}
				}
			}
			else {
				if (player[1].lPiece.corner.y == 1) { 
					if (oPiece[1].y == 4 && oPiece[1].x == player[1].lPiece.corner.x) { 
						tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (player[1].lPiece.corner.x == 1 && board.table[4][4].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[4][4].value = 4;
							oPiece[2].x = 4; oPiece[2].y = 4;
						}
						else if (board.table[1][4].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[1][4].value = 4;
							oPiece[2].x = 1; oPiece[2].y = 4;
						}
					}
					else if (oPiece[2].y == 4 && oPiece[2].x == player[1].lPiece.corner.x) { 
						tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (player[1].lPiece.corner.x == 1 && board.table[4][4].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[4][4].value = 3;
							oPiece[1].x = 4; oPiece[1].y = 4;
						}
						else if (board.table[1][4].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[1][4].value = 3;
							oPiece[1].x = 1; oPiece[1].y = 4;
						}
					}
					else { 
						if (player[1].lPiece.corner.x == 1) {
							if (oPiece[1].x == 4) {
								if (oPiece[1].y == 3 || oPiece[1].y == 4) {
									tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[1][4].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[1][4].value = 4;
										oPiece[2].x = 1; oPiece[2].y = 4;
									}
								}
							}
							else if (oPiece[1].x == 3 && oPiece[1].y == 4) {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][4].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 4;
								}
							}
							else if (oPiece[2].x == 4) {
								if (oPiece[2].y == 3 || oPiece[2].y == 4) {
									tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[1][4].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[1][4].value = 3;
										oPiece[1].x = 1; oPiece[1].y = 4;
									}
								}
							}
							else if (oPiece[2].x == 3 && oPiece[2].y == 4) {
								tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[1][4].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[1][4].value = 3;
									oPiece[1].x = 1; oPiece[1].y = 4;
								}
							}
							else {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][4].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 4;
								}
							}
						}
						else {
							if (oPiece[1].x == 1) {
								if (oPiece[1].y == 3 || oPiece[1].y == 4) {
									tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[4][4].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[4][4].value = 4;
										oPiece[2].x = 4; oPiece[2].y = 4;
									}
								}
							}
							else if (oPiece[1].x == 2 && oPiece[1].y == 4) {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][4].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 4;
								}
							}
							else if (oPiece[2].x == 1) {
								if (oPiece[2].y == 3 || oPiece[2].y == 4) {
									tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[4][4].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[4][4].value = 3;
										oPiece[1].x = 4; oPiece[1].y = 4;
									}
								}
							}
							else if (oPiece[2].x == 2 && oPiece[2].y == 4) {
								tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[4][4].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[4][4].value = 3;
									oPiece[1].x = 4; oPiece[1].y = 4;
								}
							}
							else {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][4].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][4].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 4;
								}
							}
						}
					}
				}
				else {
					if (oPiece[1].y == 1 && oPiece[1].x == player[1].lPiece.corner.x) { 
						tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (player[1].lPiece.corner.x == 1 && board.table[4][1].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[4][1].value = 4;
							oPiece[2].x = 4; oPiece[2].y = 1;
						}
						else if (board.table[1][1].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[1][1].value = 4;
							oPiece[2].x = 1; oPiece[2].y = 1;
						}
					}
					else if (oPiece[2].x == 1 && oPiece[2].y == player[1].lPiece.corner.y) { 
						tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (player[1].lPiece.corner.y == 1 && board.table[1][4].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[1][4].value = 3;
							oPiece[1].x = 1; oPiece[1].y = 4;
						}
						else if (board.table[1][1].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[1][1].value = 3;
							oPiece[1].x = 1; oPiece[1].y = 1;
						}
					}
					else { 
						if (player[1].lPiece.corner.x == 1) {
							if (oPiece[1].x == 4) {
								if (oPiece[1].y == 1 || oPiece[1].y == 2) {
									tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[1][1].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[1][1].value = 4;
										oPiece[2].x = 1; oPiece[2].y = 1;
									}
								}
							}
							else if (oPiece[1].x == 3 && oPiece[1].y == 1) {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][1].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 1;
								}
							}
							else if (oPiece[2].x == 4) {
								if (oPiece[2].y == 1 || oPiece[2].y == 2) {
									tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[1][1].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[1][1].value = 3;
										oPiece[1].x = 1; oPiece[1].y = 1;
									}
								}
							}
							else if (oPiece[2].x == 3 && oPiece[2].y == 1) {
								tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[1][1].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[1][1].value = 3;
									oPiece[1].x = 1; oPiece[1].y = 1;
								}
							}
							else {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[1][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[1][1].value = 4;
									oPiece[2].x = 1; oPiece[2].y = 1;
								}
							}
						}
						else {
							if (oPiece[1].x == 1) {
								if (oPiece[1].y == 1 || oPiece[1].y == 2) {
									tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
									if (board.table[4][1].value == 0) {
										board.table[oPiece[2].x][oPiece[2].y].value = 0;
										board.table[4][1].value = 4;
										oPiece[2].x = 4; oPiece[2].y = 1;
									}
								}
							}
							else if (oPiece[1].x == 2 && oPiece[1].y == 1) {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][1].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 1;
								}
							}
							else if (oPiece[2].x == 1) {
								if (oPiece[2].y == 1 || oPiece[2].y == 2) {
									tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
									if (board.table[4][1].value == 0) {
										board.table[oPiece[1].x][oPiece[1].y].value = 0;
										board.table[4][1].value = 3;
										oPiece[1].x = 4; oPiece[1].y = 1;
									}
								}
							}
							else if (oPiece[2].x == 2 && oPiece[2].y == 1) {
								tileStyle(board.tileColor); fillTile(oPiece[1].x, oPiece[1].y, 0);
								if (board.table[4][1].value == 0) {
									board.table[oPiece[1].x][oPiece[1].y].value = 0;
									board.table[4][1].value = 3;
									oPiece[1].x = 4; oPiece[1].y = 1;
								}
							}
							else {
								tileStyle(board.tileColor); fillTile(oPiece[2].x, oPiece[2].y, 0);
								if (board.table[4][1].value == 0) {
									board.table[oPiece[2].x][oPiece[2].y].value = 0;
									board.table[4][1].value = 4;
									oPiece[2].x = 4; oPiece[2].y = 1;
								}
							}
						}

					}
				}
			}
		}
		else player[2] = player[0];
	}
	else {
		if (player[1].lPiece.corner.y % 2 == 0) {
			if (player[1].lPiece.corner.x == 2 || player[1].lPiece.corner.x == 3) {
				player[2].lPiece.corner.x = (player[1].lPiece.corner.x == 2) ? 3 : 2;
				player[2].lPiece.corner.y = player[1].lPiece.corner.y - 2;
				player[2].lPiece.position = player[1].lPiece.position - 2;
				if (isPositionValid(board, player[2].lPiece)) {
					lPieceStyle(player[2].lPiece.color);
					createLPiece(player[2].lPiece);
					markLPiece(player[2].lPiece, 2);
					if (player[1].lPiece.corner.x == 2) {
						if (oPiece[1].x == 1 && oPiece[1].y == 2) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][1].value = 4; oPiece[2].x = 2; oPiece[2].y = 1;
							}
						}
						else if (oPiece[1].x == 2 && oPiece[1].y == 1) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][2].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][2].value = 4; oPiece[2].x = 1; oPiece[2].y = 2;
							}
						}
						else if (oPiece[2].x == 1 && oPiece[2].y == 2) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[2][1].value = 3; oPiece[1].x = 2; oPiece[1].y = 1;
							}
						}
						else if (oPiece[2].x == 2 && oPiece[2].y == 1) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][2].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][2].value = 3; oPiece[1].x = 1; oPiece[1].y = 2;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][2].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][2].value = 3; oPiece[1].x = 1; oPiece[1].y = 2;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][1].value = 4;
								oPiece[2].x = 2; oPiece[2].y = 1;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][1].value = 4; oPiece[2].x = 2; oPiece[2].y = 1;
							}
						}
					}
					else if (oPiece[1].x == 4 && oPiece[1].y == 2) {
						tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (board.table[3][1].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[3][1].value = 4; oPiece[2].x = 3; oPiece[2].y = 1;
						}
					}
					else if (oPiece[1].x == 3 && oPiece[1].y == 1) {
						tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (board.table[4][2].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[4][2].value = 4; oPiece[2].x = 4; oPiece[2].y = 2;
						}
					}
					else if (oPiece[2].x == 4 && oPiece[2].y == 2) {
						tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (board.table[3][1].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[3][1].value = 3; oPiece[1].x = 3; oPiece[1].y = 1;
						}
					}
					else if (oPiece[2].x == 3 && oPiece[2].y == 1) {
						tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (board.table[4][2].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[4][2].value = 3; oPiece[1].x = 4; oPiece[1].y = 2;
						}
					}
					else if (game.isSuddenDeath) {
						tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
						if (board.table[4][2].value == 0) {
							board.table[oPiece[1].x][oPiece[1].y].value = 0;
							board.table[4][2].value = 3; oPiece[1].x = 4; oPiece[1].y = 2;
						}
						fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (board.table[3][1].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[3][1].value = 4;
							oPiece[2].x = 3; oPiece[2].y = 1;
						}
					}
					else {
						tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
						if (board.table[4][2].value == 0) {
							board.table[oPiece[2].x][oPiece[2].y].value = 0;
							board.table[4][2].value = 4; oPiece[2].x = 4; oPiece[2].y = 2;
						}
					}
				}
				else player[2] = player[0];
			}
			else {
				player[2].lPiece.corner.x = (player[1].lPiece.corner.x + 2) % 4;
				player[2].lPiece.corner.y = player[1].lPiece.corner.y + 1;
				player[2].lPiece.position = player[1].lPiece.position - 2;
				if (isPositionValid(board, player[2].lPiece)) {
					lPieceStyle(player[2].lPiece.color);
					createLPiece(player[2].lPiece);
					markLPiece(player[2].lPiece, 2);
					if (player[1].lPiece.corner.x == 1) {
						if (oPiece[1].x == 4 && oPiece[1].y == 2) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[3][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[3][1].value = 4; oPiece[2].x = 3; oPiece[2].y = 1;
							}
						}
						else if (oPiece[1].x == 3 && oPiece[1].y == 1) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[4][2].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[4][2].value = 4; oPiece[2].x = 4; oPiece[2].y = 2;
							}
						}
						else if (oPiece[2].x == 4 && oPiece[2].y == 2) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[3][1].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[3][1].value = 3; oPiece[1].x = 3; oPiece[1].y = 1;
							}
						}
						else if (oPiece[2].x == 3 && oPiece[2].y == 1) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][2].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[4][2].value = 3; oPiece[1].x = 4; oPiece[1].y = 2;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][2].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[4][2].value = 3; oPiece[1].x = 4; oPiece[1].y = 2;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[3][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[3][1].value = 4; oPiece[2].x = 3; oPiece[2].y = 1;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[4][2].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[4][2].value = 4; oPiece[2].x = 4; oPiece[2].y = 2;
							}
						}
					}
					else {
						if (oPiece[1].x == 1 && oPiece[1].y == 2) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][1].value = 4; oPiece[2].x = 2; oPiece[2].y = 1;
							}
						}
						else if (oPiece[1].x == 2 && oPiece[1].y == 1) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][2].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][2].value = 4; oPiece[2].x = 1; oPiece[2].y = 2;
							}
						}
						else if (oPiece[2].x == 1 && oPiece[2].y == 2) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[2][1].value = 3; oPiece[1].x = 2; oPiece[1].y = 1;
							}
						}
						else if (oPiece[2].x == 2 && oPiece[2].y == 1) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][2].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][2].value = 3; oPiece[1].x = 1; oPiece[1].y = 2;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][2].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][2].value = 3; oPiece[1].x = 1; oPiece[1].y = 2;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][1].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][1].value = 4; oPiece[2].x = 2; oPiece[2].y = 1;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][2].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][2].value = 4; oPiece[2].x = 1; oPiece[2].y = 2;
							}
						}
					}
				}
				else player[2] = player[0];
			}
		}
		else {
			if (player[1].lPiece.corner.x == 2 || player[1].lPiece.corner.x == 3) {
				player[2].lPiece.corner.x = (player[1].lPiece.corner.x == 2) ? 3 : 2;
				player[2].lPiece.corner.y = player[1].lPiece.corner.y + 2;
				player[2].lPiece.position = player[1].lPiece.position + 2;
				if (isPositionValid(board, player[2].lPiece)) {
					lPieceStyle(player[2].lPiece.color);
					createLPiece(player[2].lPiece);
					markLPiece(player[2].lPiece, 2);
					if (player[1].lPiece.corner.x == 2) {
						if (oPiece[1].x == 1 && oPiece[1].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][4].value = 4; oPiece[2].x = 2; oPiece[2].y = 4;
							}
						}
						else if (oPiece[1].x == 2 && oPiece[1].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][3].value = 4; oPiece[2].x = 1; oPiece[2].y = 3;
							}
						}
						else if (oPiece[2].x == 1 && oPiece[2].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[2][4].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[2][4].value = 3; oPiece[1].x = 2; oPiece[1].y = 4;
							}
						}
						else if (oPiece[2].x == 2 && oPiece[2].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][3].value = 3; oPiece[1].x = 1; oPiece[1].y = 3;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][3].value = 3; oPiece[1].x = 1; oPiece[1].y = 3;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][4].value = 4; oPiece[2].x = 2; oPiece[2].y = 4;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][3].value = 4; oPiece[2].x = 1; oPiece[2].y = 3;
							}
						}
					}
					else {
						if (oPiece[1].x == 4 && oPiece[1].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[3][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[3][4].value = 4; oPiece[2].x = 3; oPiece[2].y = 4;
							}
						}
						else if (oPiece[1].x == 3 && oPiece[1].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[4][3].value = 4; oPiece[2].x = 4; oPiece[2].y = 3;
							}
						}
						else if (oPiece[2].x == 4 && oPiece[2].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[3][4].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[3][4].value = 3; oPiece[1].x = 3; oPiece[1].y = 4;
							}
						}
						else if (oPiece[2].x == 3 && oPiece[2].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[4][3].value = 3; oPiece[1].x = 4; oPiece[1].y = 3;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[4][3].value = 3; oPiece[1].x = 4; oPiece[1].y = 3;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[3][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[3][4].value = 4; oPiece[2].x = 3; oPiece[2].y = 4;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[4][3].value = 4; oPiece[2].x = 4; oPiece[2].y = 3;
							}
						}
					}
				}
				else player[2] = player[0];
			}
			else {
				player[2].lPiece.corner.x = (player[1].lPiece.corner.x + 2) % 4;
				player[2].lPiece.corner.y = player[1].lPiece.corner.y - 1;
				player[2].lPiece.position = player[1].lPiece.position + 2;
				if (isPositionValid(board, player[2].lPiece)) {
					lPieceStyle(player[2].lPiece.color);
					createLPiece(player[2].lPiece);
					markLPiece(player[2].lPiece, 2);
					if (player[1].lPiece.corner.x == 1) {
						if (oPiece[1].x == 4 && oPiece[1].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[3][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[3][4].value = 4; oPiece[2].x = 3; oPiece[2].y = 4;
							}
						}
						else if (oPiece[1].x == 3 && oPiece[1].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[4][3].value = 4; oPiece[2].x = 4; oPiece[2].y = 3;
							}
						}
						else if (oPiece[2].x == 4 && oPiece[2].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[3][4].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[3][4].value = 3; oPiece[1].x = 3; oPiece[1].y = 4;
							}
						}
						else if (oPiece[2].x == 3 && oPiece[2].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[4][3].value = 3; oPiece[1].x = 4; oPiece[1].y = 3;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[4][3].value = 3; oPiece[1].x = 4; oPiece[1].y = 3;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[3][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[3][4].value = 4; oPiece[2].x = 3; oPiece[2].y = 4;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[4][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[4][3].value = 4; oPiece[2].x = 4; oPiece[2].y = 3;
							}
						}
					}
					else {
						if (oPiece[1].x == 1 && oPiece[1].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][4].value = 4; oPiece[2].x = 2; oPiece[2].y = 4;
							}
						}
						else if (oPiece[1].x == 2 && oPiece[1].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][3].value = 4; oPiece[2].x = 1; oPiece[2].y = 3;
							}
						}
						else if (oPiece[2].x == 1 && oPiece[2].y == 3) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[2][4].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[2][4].value = 3; oPiece[1].x = 2; oPiece[1].y = 4;
							}
						}
						else if (oPiece[2].x == 2 && oPiece[2].y == 4) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][3].value = 3; oPiece[1].x = 1; oPiece[1].y = 3;
							}
						}
						else if (game.isSuddenDeath) {
							tileStyle(board.tileColor);	fillTile(oPiece[1].x, oPiece[1].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[1].x][oPiece[1].y].value = 0;
								board.table[1][3].value = 3; oPiece[1].x = 1; oPiece[1].y = 3;
							}
							fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[2][4].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[2][4].value = 4; oPiece[2].x = 2; oPiece[2].y = 4;
							}
						}
						else {
							tileStyle(board.tileColor);	fillTile(oPiece[2].x, oPiece[2].y, 0);
							if (board.table[1][3].value == 0) {
								board.table[oPiece[2].x][oPiece[2].y].value = 0;
								board.table[1][3].value = 4; oPiece[2].x = 1; oPiece[2].y = 3;
							}
						}
					}
				}
				else player[2] = player[0];
			}
		}
	}

	if ((player[2].lPiece.corner.x == player[0].lPiece.corner.x && player[2].lPiece.corner.y == player[0].lPiece.corner.y
		&& player[2].lPiece.position == player[0].lPiece.position) || player[2].lPiece.position == 0) {
		nrO = rand() % 2 + 1; player[2] = player[0];

		if (rand() % 2)
			for (k = 1; k <= 8 && ok; ++k) {
				player[2].lPiece.position = k;
				for (i = 1; i <= 4 && ok; ++i) {
					player[2].lPiece.corner.x = i;
					for (j = 1; j <= 4; ++j) {
						player[2].lPiece.corner.y = j;
						if (isPositionValid(board, player[2].lPiece)) {
							lPieceStyle(player[2].lPiece.color);
							createLPiece(player[2].lPiece);
							markLPiece(player[2].lPiece, 2);
							ok = false; break;
						}
					}
				}
			}
		else {
			for (k = 8; k >= 1 && ok; --k) {
				player[2].lPiece.position = k;
				for (i = 4; i >= 1 && ok; --i) {
					player[2].lPiece.corner.x = i;
					for (j = 4; j >= 1; --j) {
						player[2].lPiece.corner.y = j;
						if (isPositionValid(board, player[2].lPiece)) {
							lPieceStyle(player[2].lPiece.color);
							createLPiece(player[2].lPiece);
							markLPiece(player[2].lPiece, 2);
							ok = false; break;
						}
					}
				}
			}
		}

		ok = true;

		for (i = 1; i <= 4 && ok; ++i)
			for (j = 1; j <= 4; ++j)
				if (board.table[i][j].value == 0) {
					board.table[oPiece[nrO].x][oPiece[nrO].y].value = 0; fillTile(oPiece[nrO].x, oPiece[nrO].y, 0);
					oPiece[nrO].x = i; oPiece[nrO].y = j;
					board.table[oPiece[nrO].x][oPiece[nrO].y].value = 2 + nrO; oPieceStyle(oPiece[nrO].color); createOPiece(oPiece[nrO]);
					ok = false; break;
				}

		if (game.isSuddenDeath) {
			nrO = (nrO == 3 ? 4 : 3);
			for (i = 1; i <= 4 && ok; ++i)
				for (j = 1; j <= 4; ++j)
					if (board.table[i][j].value == 0) {
						k++;
						if (k == 3) {
							board.table[oPiece[nrO].x][oPiece[nrO].y].value = 0; fillTile(oPiece[nrO].x, oPiece[nrO].y, 0);
							oPiece[nrO].x = i; oPiece[nrO].y = j;
							board.table[oPiece[nrO].x][oPiece[nrO].y].value = 2 + nrO; oPieceStyle(oPiece[nrO].color); createOPiece(oPiece[nrO]);
							ok = false; break;
						}
					}
		}
	}

	oPieceStyle(oPiece[1].color); createOPiece(oPiece[1]);
	oPieceStyle(oPiece[2].color); createOPiece(oPiece[2]);
}