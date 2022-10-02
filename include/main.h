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
	static int CURRENT_ROTATION = 0;
	static int CURRENT_X_POS;
	static int CURRENT_Y_POS;
	static int SPEED;
	static int SPEED_COUNT;
	int PIECE_COUNT = 0;
	int SCORE = 0;
	static bool KEY[4];
	static bool FORCE_DOWN;
	bool ROTATE_HOLD();
	bool GAME_OVER();
	vector<int*> VECTOR_LINES;

} GAME;

#endif 
