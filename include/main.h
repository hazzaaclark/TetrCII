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

typedef struct SCREEN_VARIABLES
{
	static const wstring PIECE[7];
	static const int WIDTH = 100;
	static const int HEIGHT = 50;
	static const char* POINTER_FIELD;

} SCREEN;

typedef struct GAME_LOGIC
{
	static const int PI = 3.142;
	static const int FI = 0;
	static const int FIELD_WIDTH = 12;
	static const int FIELD_HEIGHT = 18;
	int CURRENT_PIECE = 0;
	int CURRENT_ROTATION = 0;
	int CURRENT_X_POS;
	int CURRENT_Y_POS;
	int SPEED = 20;
	int PIECE_COUNT = 0;
	int SCORE = 0;
	virtual bool FORCE_DOWN(VOID);
	virtual bool ROTATE_HOLD(VOID);
	virtual bool GAME_END(VOID);
	vector<int*> VECTOR_LINES;

} GAME;

#endif 
