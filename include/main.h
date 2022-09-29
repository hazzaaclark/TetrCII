#pragma once
#ifndef TETRIS_MAIN_H
#define TETIRS_MAIN_H

#include <iostream>
#include <vector>
#include <thread>

typedef struct SCREEN_VARIABLES
{
	const int WIDTH = 100;
	const int HEIGHT = 50;
	unsigned char* POINTER_FILED = nullptr;

} SCREEN;

typedef struct GAME_LOGIC
{
	int FIELD_WIDTH = 12;
	int FIELD_HEIGHT = 18;
	const int CURRENT_PIECE = 0;
	const int CURRENT_ROTATION = 0;
	const int CURRENT_X_POS = FIELD_WIDTH /= 2;
	const int CURRENT_Y_POS;

} GAME;


#endif 