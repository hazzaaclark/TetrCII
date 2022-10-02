#pragma once

#ifndef TETRIS_MAIN_H
#define TETIRS_MAIN_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <thread>
#include <Windows.h>

using std::vector;
using std::wstring;
wstring PIECE[7];

typedef struct SCREEN_VARIABLES
{
	static const int WIDTH = 100;
	static const int HEIGHT = 50;
	static const char* P_FIELD;

} SCREEN;

typedef struct GAME_LOGIC
{
	static const int PI = 3.142;
	static const int FI = 0;
	static const int FIELD_WIDTH = 12;
	static const int FIELD_HEIGHT = 18;
	static int CURRENT_PIECE;
	int CURRENT_ROTATION = 0;
	int CURRENT_X_POS;
	int CURRENT_Y_POS;
	static int SPEED;
	static int SPEED_COUNT;
	int PIECE_COUNT = 0;
	int SCORE = 0;
	virtual bool FORCE_DOWN(VOID);
	virtual bool ROTATE_HOLD(VOID);
	virtual bool GAME_END(VOID);
	vector<int*> VECTOR_LINES;

} GAME;

#endif
