#include "base.h"

// 1. reduce func call overhead 
// 2. loop unrolling
// 3. division -> multiply
// 4. Branch minimization

void hslConvert(void *dst, void *src) 
{
    int (*hsl)[ORIG_COL_SZ / 3] = (int(*)[ORIG_COL_SZ / 3]) dst;
	char (*rgb)[COL_UNIT] = (char(*)[COL_UNIT]) src;
	
	int max;
	int min;

	int i;
	int j;
	
	for (i = 0; i < ORIG_ROW_SZ; ++i) 
	{
		for (j = 0; j < ORIG_COL_SZ; j += 18) 
		{
            // 1 loop :  6 pixel -> 6 HSL
            
            ////pixel 1
            ////GetMinMax -> max, min
            max = rgb[i][j]; min = rgb[i][j + 1];
            if(rgb[i][j] < rgb[i][j + 1]) { max = rgb[i][j + 1]; min = rgb[i][j]; }
            if(min > rgb[i][j + 2]) { min = rgb[i][j + 2]; }
            if(max < rgb[i][j + 2]) { max = rgb[i][j + 2]; }
            
            hsl[i][j / 3] = (max + min) / 2;
            
            ////pixel 2
            ////GetMinMax -> max, min
            max = rgb[i][j+3]; min = rgb[i][j + 4];
            if(rgb[i][j+3] < rgb[i][j + 4]) { max = rgb[i][j + 4]; min = rgb[i][j + 3]; }
            if(min > rgb[i][j + 5]) { min = rgb[i][j + 5]; }
            if(max < rgb[i][j + 5]) { max = rgb[i][j + 5]; }
            
            hsl[i][(j + 3) / 3] = (max + min) / 2;
            
            ////pixel 3
            ////GetMinMax -> max, min
            max = rgb[i][j+6]; min = rgb[i][j + 7];
            if(rgb[i][j+6] < rgb[i][j + 7]) { max = rgb[i][j + 7]; min = rgb[i][j + 6]; }
            if(min > rgb[i][j + 8]) { min = rgb[i][j + 8]; }
            if(max < rgb[i][j + 8]) { max = rgb[i][j + 8]; }
            
            hsl[i][(j + 6) / 3] = (max + min) / 2;
            
            ////pixel 4
            ////GetMinMax -> max, min
            max = rgb[i][j+9]; min = rgb[i][j + 10];
            if(rgb[i][j+9] < rgb[i][j + 10]) { max = rgb[i][j + 10]; min = rgb[i][j + 9]; }
            if(min > rgb[i][j + 11]) { min = rgb[i][j + 11]; }
            if(max < rgb[i][j + 11]) { max = rgb[i][j + 11]; }
            
            hsl[i][(j + 9) / 3] = (max + min) / 2;
            
            ////pixel 5
            ////GetMinMax -> max, min
            max = rgb[i][j+12]; min = rgb[i][j + 13];
            if(rgb[i][j+12] < rgb[i][j + 13]) { max = rgb[i][j + 13]; min = rgb[i][j + 12]; }
            if(min > rgb[i][j + 14]) { min = rgb[i][j + 14]; }
            if(max < rgb[i][j + 14]) { max = rgb[i][j + 14]; }
            
            hsl[i][(j + 12) / 3] = (max + min) / 2;
            
            ////pixel 6
            ////GetMinMax -> max, min
            max = rgb[i][j+15]; min = rgb[i][j + 16];
            if(rgb[i][j+15] < rgb[i][j + 16]) { max = rgb[i][j + 16]; min = rgb[i][j + 15]; }
            if(min > rgb[i][j + 17]) { min = rgb[i][j + 17]; }
            if(max < rgb[i][j + 17]) { max = rgb[i][j + 17]; }
            
            hsl[i][(j + 15) / 3] = (max + min) / 2;
		}
	}
}