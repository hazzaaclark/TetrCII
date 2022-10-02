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

} SCREEN;

#endif
