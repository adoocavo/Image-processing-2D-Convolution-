#include "base.h"

int getMax(int *arr, int size) 
{
    int max = 0;
    for (int i = 0; i < size; i++) 
    {
        if (max < arr[i]) max = arr[i];
    }
    
    return max;
}

void getMaxPooled(int CONV[][1920], int STRIDE[][960])
{
    for (int y = 0; y < ROW_SZ; y += 2) 
    {
        for (int x = 0; x < COL_SZ; x += 2) 
        {
            int arr[4] = {CONV[y][x], CONV[y + 1][x], CONV[y][x + 1], CONV[y + 1][x + 1]};
            STRIDE[y/2][x/2] = getMax(arr, 4);
        }
    }
}
