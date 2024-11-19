	PRESERVE8
    AREA   alignment, CODE, READONLY

ORIG_ROW_SZ 		DCD (1080)	; 1080 can't be represented as 0~255 shift
								; to fix this prob, memory Load is used. 
ORIG_COL_SZ 		EQU (1920*3)
COL_UNIT 			EQU (2048*3)

	EXPORT dataAlign
	ENTRY
	
dataAlign
	MOV 	r2, #0				; r2 = 0
	LDR		r10, ORIG_ROW_SZ	; r10 = ORIG_ROW_SZ
	MOV		r11, #(ORIG_COL_SZ)	; r11 = ORIG_COL_SZ
	MOV		r12, #(COL_UNIT)	; r12 = COL_UNIT
	
LOOP_ROW
    CMP 	r2, r10				; if (r2 > ORIG_ROW_SZ)
    BGE 	LOOP_ROW_END		; 	LOOP_ROW_END();
    
    MOV 	r3, #0				; r3 = 0
    
LOOP_COL
	CMP 	r3, r11 	 		; if (r3 > ORIG_COL_SZ)
	BGE 	LOOP_COL_END 		; 	break

	MLA		r4, r2, r12, r3		; r2*COL_UNIT + r3
	ADD 	r4, a2, r4 			; a2 + r2*COL_UNIT + r3
	
	MLA		r5, r2, r11, r3		; r2*ORIG_COL_SZ + r3
	ADD		r5, a1, r5			; a1 + r2*ORIG_COL_SZ + r3

	LDM		r5,{r6,r7,r8,r9}	; 4 char * 4 = 16 char LOAD
	STM		r4,{r6,r7,r8,r9}	; 4 char * 4 = 16 char STORE
	
	ADD 	r3, r3, #16  		; r3 += 16
	B 		LOOP_COL      

LOOP_COL_END
	ADD 	r2, r2, #1  		; r2 += 1
	B 		LOOP_ROW      

LOOP_ROW_END
	BX   lr
    END
