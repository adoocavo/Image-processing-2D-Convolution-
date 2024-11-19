#include "base.h"

void convolution(int IMAGE[][1920], int CONV[][1920], int kernel[][3])
{
	for (int y = 0; y < ROW_SZ; y++) 
    {
		for (int x = 0; x < COL_SZ; x++) 
        {
			CONV[y][x] = 0;
			for (int i = -1; i < 2; i++) 
            {
				for (int j = -1; j < 2; j++) 
                {
					if ((y + i) >= 0 && (y + i) < ROW_SZ && (x + j) >= 0 && (x + j) < COL_SZ)
                    {
                        CONV[y][x] += (IMAGE[y + i][x + j] * kernel[i + 1][j + 1]);
                    }
						
				}
			}

			if (CONV[y][x] < 0)
            {
                CONV[y][x] = 0; // Applied ReLU activation
            }
				
		}
	}
}
