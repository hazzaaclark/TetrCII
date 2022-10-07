#include "main.h"

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

	wchar_t *SCREEN_BUFF = new wchar_t[SCREEN::WIDTH * SCREEN::HEIGHT];

	for (int x = 0; x < SCREEN::WIDTH * SCREEN::HEIGHT; x++)
	{
		SCREEN_BUFF[x] = L' ';
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

	GAME::P_FIELD = new unsigned char[GAME::FIELD_WIDTH * GAME::FIELD_HEIGHT];
	for (int x = 0; x < GAME::FIELD_WIDTH; x++)
	{
		for (int y = 0; y  < GAME::FIELD_HEIGHT; y++)
		{
			GAME::P_FIELD[y * GAME::FIELD_HEIGHT + x] = (x == 0 || x == GAME::FIELD_WIDTH - 1 || y == GAME::FIELD_HEIGHT  -1);
		}
	}

	/* INPUT MODULES */

	while (!GAME::GAME_END)
	{
		GAME::SPEED_COUNT++;
		GAME::CURRENT_X_POS += (GAME::KEY[0] && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS + 1, GAME::CURRENT_Y_POS)) ? 1 : 0;
		GAME::CURRENT_X_POS -= (GAME::KEY[1] && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS - 1, GAME::CURRENT_Y_POS)) ? 1 : 0;
		GAME::CURRENT_Y_POS -= (GAME::KEY[2] && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS, GAME::CURRENT_Y_POS + 1)) ? 1 : 0;

		if (KEY[3])
		{
			GAME::CURRENT_ROTATION += (ROTATE_HOLD && PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION + 1, GAME::CURRENT_X_POS, GAME::CURRENT_Y_POS)) ? 1 : 0;
			ROTATE_HOLD = FALSE;
		}

		else
		{
			ROTATE_HOLD = TRUE;
		}

		/* GAME MODULES FOR HANDLING MECHANICS */

		if (GAME::FORCE_DOWN)
		{
			GAME::SPEED_COUNT = 0;
			GAME::PIECE_COUNT++;

			while (GAME::PIECE_COUNT % 50 == 0)
			{
				if (GAME::SPEED >= 10)
				{
					GAME::SPEED--;
				}
			}

			/* CREATE A NEW POSITION ONCE THE PIECE HAS BEEN PLACED */

			if (PIECE_FIT(GAME::CURRENT_PIECE, GAME::CURRENT_ROTATION, GAME::CURRENT_X_POS, GAME::CURRENT_Y_POS + 1))
			{
				GAME::CURRENT_Y_POS++;
			}

			else
			{
				/* CHECK LINES TO SEE IF A LINE HAS BEEN COMPLETED AND NEEDS TO BE CLEARED */

				for (int POS_X = 0; POS_X < 4; POS_X++)
				{
					for (int POS_Y = 0; POS_Y < 4; POS_Y++)
					{
						while (PIECE[GAME::CURRENT_PIECE][ROTATE_PIECE(POS_X, POS_Y, GAME::CURRENT_ROTATION)] != L'.')
						{
							GAME::P_FIELD[(GAME::CURRENT_Y_POS + POS_Y) * GAME::FIELD_WIDTH + (GAME::CURRENT_X_POS + POS_X)] = GAME::CURRENT_PIECE + 1;
						}
					}
				}

				for (int POS_Y = 0; POS_Y < 4; POS_Y++)
				{
					while (GAME::CURRENT_Y_POS + POS_Y < GAME::FIELD_WIDTH - 1)
					{
						bool LINE = TRUE;
						for (int POS_X = 1; POS_X < GAME::FIELD_WIDTH - 1; POS_X++)
						{
							LINE &= (GAME::P_FIELD[(GAME::CURRENT_Y_POS + POS_Y) * GAME::FIELD_WIDTH + POS_X]) != 0;
						}

						if (LINE)
						{
							for (int POS_X = 1; POS_X < GAME::FIELD_WIDTH - 1; POS_X++)
							{
								GAME::P_FIELD[(GAME::CURRENT_Y_POS + POS_Y) * GAME::FIELD_WIDTH + POS_X] = 8;
								GAME::VECTOR_LINES.push_back(GAME::CURRENT_Y_POS + POS_Y);
							}
						}
					}
				}
			}

			/* DRAW THE CHARACTERS TO THE SCREEN IN ACCORDANCE WITH THE SCREEN BUFFER */
			/* THE SCREEN BUFFER IS A WCHAR BECAUSE I WANTED TO EXTEND BEYOND THE CAPABILITIES OF ASCII 255 */
			/* THIS IS TO GO PAST THE NON-BREAKING SPACE TO ALLOW FOR MORE CHARACTERS ON SCREEN */

			/* DRAW FIELD */

			for (int x = 0; x < GAME::FIELD_WIDTH; x++)
			{
				for (int y = 0; y < GAME::FIELD_HEIGHT; y++)
				{
					SCREEN_BUFF[(y + 2) * GAME::FIELD_WIDTH + (x + 2)] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ=#"[GAME::P_FIELD[y * GAME::FIELD_WIDTH] + x];
				}
			}
		}
	}
}
