#include "base.h"
#include "InputDataAlignment.h"
#include "hslConvert.h"
#include "2D_convolution.h"
#include "maxPooling.h"
#include "nomalization.h"

int main(void) 
{
    float flt_kernel[3][3] = {
                {0.125, -0.14, 0.05},
                {-0.14, 0, -0.075},
                {0.05, -0.075, 0.125}
                };
	
	// multiply 100 of each elements of kernel to convert form of integer
	int int_kernel[3][3] = {
                {125, -140, 50},
				{-140, 0, -75}, 
				{50, -75, 125}
                };
													
// LOAD florence_80000000.hex 

//  ===== data align
//  SAVE align.hex 0x90000000, 0x90000000+(2048*1080*3)  // LOAD align.hex
	dataAlign((void *)SRC, (char(*)[COL_UNIT])DST);

//  ===== HSL convert
//  SAVE hsl.hex 0xA0000000, 0xA0000000+(1920*1080*4)-1 // LOAD hsl.hex
	hslConvert((int(*)[ORIG_COL_SZ / 3])HSL, (char(*)[COL_UNIT])DST);                
									
//  ===== convolution
//  SAVE conv.hex 0xB0000000, 0xB0000000+(1920*1080*4)-1  // LOAD conv.hex
    convolution((int(*)[1920])HSL, (int(*)[1920])CNV, int_kernel);

//  ===== maxPool (v0: float, v1: int)
//  SAVE maxpool.hex 0xC0000000, 0xC0000000+(960*540*4)-1  // LOAD maxpool.hex
	getMaxPooled((int(*)[1920])CNV, (int(*)[960])STD);
  
//  ===== normalize  (v0: float, v1: int)
//  SAVE normalize.hex 0xD0000000, 0xD0000000+(960*540)-1  // LOAD normalize.hex
	nomalizing((int(*)[960])STD, (char(*)[960])NOR);

	_sys_exit(0);
}
