#ifndef __BASE_H
#define __BASE_H

#define SRC 0x80000000
#define DST 0x90000000
#define HSL 0xA0000000
#define CNV 0xB0000000
#define STD 0xC0000000
#define NOR 0xD0000000

#define ORIG_ROW_SZ 1080
#define ORIG_COL_SZ (1920*3)
#define COL_UNIT (2048*3)

#define ROW_SZ 1080
#define COL_SZ 1920

void _sys_exit(int return_code);

int sendchar (int ch);						/* Write character to Serial Port    */
int getkey (void);						    /* Read character from Serial Port   */

void sendhex (int hex);                   	/* Write Hex Digit to Serial Port  */
void sendstr (char *p);                   	/* Write string */

void printArr(int arr[], int n);
void printDecimal(int num);

#endif
