#include "base.h"

void nomalizing(int STRIDE[][960], char NORM[][960])
{
	int max = 0;
	for(int i = 0; i < 2; i++)
    {
        for (int y = 0; y < ROW_SZ/2; y ++)
        {
            for (int x = 0; x < COL_SZ/2; x ++) 
            {
                if(i == 0)
                {
                    if(max < STRIDE[y][x]) max = STRIDE[y][x];
				}
                else
                {
                    NORM[y][x] = (char)((float)STRIDE[y][x] / max * 255.0f);
                } 
		    }
		}
	}
}
