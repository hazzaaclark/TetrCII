#pragma once
#ifndef TETRIS_MAIN_H
#define TETIRS_MAIN_H

#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>

using std::vector;

typedef struct SCREEN_VARIABLES
{
	static const int WIDTH = 100;
	static const int HEIGHT = 50;
	unsigned char* POINTER_FILED = nullptr;

} SCREEN;

typedef struct GAME_LOGIC
{
	static const int PI = 3.142;
	int FIELD_WIDTH = 12;
	int FIELD_HEIGHT = 18;
	int CURRENT_PIECE = 0;
	int CURRENT_ROTATION = 0;
	int CURRENT_X_POS = FIELD_WIDTH /= 2;
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
