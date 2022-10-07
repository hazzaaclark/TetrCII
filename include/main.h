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

#define INSTRUCTIONS
bool FORCE_DOWN;
bool ROTATE_HOLD;
bool GAME_END;

#define GAME
unsigned char* P_FIELD = nullptr;
int PI = 0;
int FI = 0;
int FIELD_WIDTH = 12;
int FIELD_HEIGHT = 18;
int CURRENT_PIECE;
int CURRENT_ROTATION;
int CURRENT_X_POS;
int CURRENT_Y_POS;
int SPEED;
int SPEED_COUNT;
int PIECE_COUNT = 0;
int SCORE = 0;
bool KEY[4];
vector<int> VECTOR_LINES;

#define SCREEN
int WIDTH = 80;
int HEIGHT = 50;

#endif
