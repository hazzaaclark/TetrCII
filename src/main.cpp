#include "main.h"

#define INSTRUCTIONS
bool FORCE_DOWN;
bool ROTATE_HOLD;
bool GAME_END;

#define GAME
static int PI = 3.142;
static const int FI = 0;
static const int FIELD_WIDTH = 12;
static const int FIELD_HEIGHT = 18;
static int CURRENT_PIECE;
static int CURRENT_ROTATION;
static int CURRENT_X_POS;
static int CURRENT_Y_POS;
static int SPEED;
static int SPEED_COUNT;
int PIECE_COUNT = 0;
int SCORE = 0;
static bool KEY[4];
vector<int*> VECTOR_LINES;


/* SWITCH AND CASE INTERATION THAT RETURNS AN INT VALUE */
/* AT THE END OF IT'S EXECUTION */
/* THIS IS AN ITERABLE LOOP THAT DETERMINES THE ROTATION OF THE PIECE */
static int ROTATE_PIECE(int POS_X, int POS_Y, int ROTATE_MATRIX)
{
	switch (ROTATE_MATRIX % 4)
	{
	case 0:
		GAME::PI == POS_Y * 4 + POS_X;
		break;
	case 1:
		GAME::PI == 12 + POS_Y - (POS_X * 4);
		break;
	case 2:
		GAME::PI == 15 - (POS_Y * 4) - POS_X;
		break;
	case 3:
		GAME::PI == 3 - POS_Y + (POS_X * 4);
		break;
	}

	return GAME::PI;
}

/* ITERATION BETWEEN EACH DEGREE OF ROTATION */
/* TO DETERMINE WHETHER OR NOT THE PIECE CAN FIT */
/* IN CORRESPONDENCE TO IT'S SURROUDINGS */
static bool PIECE_FIT(int NTH_PIECE, int ROTATION, int POS_X_NTH, int POS_Y_NTH)
{
	for (int POS_X = 0; POS_X < 4; POS_X++)
	{
		for (int POS_Y = 0; POS_Y < 4; POS_Y++)
		{
			GAME::PI == ROTATE_PIECE(POS_X, POS_Y, ROTATION);
			GAME::FI == (POS_X, +POS_Y) * GAME::FIELD_WIDTH + (POS_X_NTH, +POS_Y);
			GAME::FI == (POS_X, +POS_Y) * GAME::FIELD_WIDTH + (POS_X_NTH, +POS_Y);

			while (POS_X_NTH + POS_X >= 0 && POS_X_NTH < GAME::FIELD_WIDTH)
			{
				if (POS_Y_NTH + POS_Y >= 0 && POS_Y_NTH < GAME::FIELD_HEIGHT)
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	/* SCREEN BUFFER INIT */

	wchar_t SCREEN_BUFF = SCREEN::WIDTH * SCREEN::HEIGHT;

	for (int x = 0; x < SCREEN::WIDTH * SCREEN::HEIGHT; x++)
	{
		SCREEN_BUFF = L' ';
	}
	/* BASIC CONSOLE WRITE AND READ ALGORITHM */
	/* THIS JUST USES A BASIC POINTER NOTATION TO ALLOCATE MEMORY ON THE HEAP TO RENDER THE CONSOLE */

	HANDLE CONSOLE = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(CONSOLE);
	DWORD BYTES_WRITTEN = 0;

	/* TETROMINOE PIECE ARRANGEMENTS */

	PIECE[0].append(L"..X...X...X...X.");
	PIECE[1].append(L"..X..XX...X.....");
	PIECE[2].append(L".....XX..XX.....");
	PIECE[3].append(L"..X..XX..X......");
	PIECE[4].append(L".X...XX...X.....");
	PIECE[5].append(L".X...X...XX.....");
	PIECE[6].append(L"..X...X..XX.....");

	/* INTIALISE A NEW PLAYING FIELD ON EACH ITERATION OF THE GAME */

	SCREEN::P_FIELD == new char[GAME::FIELD_WIDTH * GAME::FIELD_HEIGHT];

	for (int x = 0; x < GAME::FIELD_WIDTH; x++)
	{
		for (int y = 0; y  < GAME::FIELD_HEIGHT; y++)
		{
			SCREEN::P_FIELD[y * GAME::FIELD_HEIGHT + x];
		}
	}

	/* INPUT MODULES */

	GAME::CURRENT_X_POS += (GAME::KEY[0] && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS + 1, GAME::CURRENT_Y_POS)) ? 1 : 0;
	GAME::CURRENT_X_POS -= (GAME::KEY[1] && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS - 1, GAME::CURRENT_Y_POS)) ? 1 : 0;
	GAME::CURRENT_Y_POS -= (GAME::KEY[2] && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS, GAME::CURRENT_Y_POS + 1)) ? 1 : 0;
}
