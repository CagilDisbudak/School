;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
			.data
segm			.byte	0x7e, 0x30, 0x6d, 0x79
			.byte	0x33, 0x5b, 0x5f, 0x70
			.byte	0x7f, 0x73, 0x77, 0x1f
			.byte	0x4e, 0x3d, 0x4f, 0x47

;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
			bic.b	#01111111b, &P1SEL
			bic.b	#01111111b, &P1SEL2

			bis.b	#01111111b, &P1DIR
			bic.b	#01111111b, &P1OUT

			bic.b	#01111111b, &P2SEL
			bic.b	#01111111b, &P2SEL2

			bis.b	#01111111b, &P2DIR
			bic.b	#01111111b, &P2OUT


			mov.w	#0, r5
			mov.w   #0, r7

inc_val:
            mov.b segm(r5), r11
			mov.b r11, &P1OUT
			mov.b segm(r7), r11
			mov.b r11, &P2OUT


light:
            cmp #16, r7
		    jeq cont2

			mov.b segm(r5), r11
			mov.b r11, &P1OUT
            mov.b segm(r7), r11
		    mov.b r11, &P2OUT
     		call #delay
			inc r5
			cmp #16, r5
			jne cont
			mov #0, r5
			inc r7

cont:
			jmp light

cont2:
		mov.b #0,r7
		call #delay
		jmp light




delay			push	r6
			mov.w	#0, r6
dloop			add.w	#1, r6
			push	r9
			push	r9
			pop		r9
			pop		r9
			jne		dloop
			pop		r6
			ret

                                            

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global 	__STACK_END
            .sect   	.stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   	".reset"                ; MSP430 RESET Vector
            .short  	RESET
