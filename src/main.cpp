#include "main.h"

/* SWITCH AND CASE INTERATION THAT RETURNS AN INT VALUE */
/* AT THE END OF IT'S EXECUTION */
/* THIS IS AN ITERABLE LOOP THAT DETERMINES THE ROTATION OF THE PIECE */

static int ROTATE_PIECE(int POS_X, int POS_Y, int ROTATE_MATRIX)
{
	unsigned int PI = 3.142;
	switch (ROTATE_MATRIX % 4)
	{
	case 0:
		PI = POS_Y * 4 + POS_X;
		break;

	}
}
