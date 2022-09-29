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
			GAME::FI == (POS_X, + POS_Y) * GAME::FIELD_WIDTH + (POS_X_NTH, + POS_Y);

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

}
