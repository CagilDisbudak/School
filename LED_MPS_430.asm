;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
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


	bic.b #00010110b, &P1SEL ; Select Digital I/O for
	bic.b #00010110b, &P1SEL2
	bis.b #00010110b, &P1DIR

main:
	mov.b #35,r5
    bic.b #BIT4, &P1OUT
	bis.b #BIT2, &P1OUT
	jmp delaym
	;burada 1.4 portu sifirlayip 1.2 portunu yakiyor
yesil:
    mov.b #35,r4
	bic.b #BIT2, &P1OUT ; Turn off LED.
	bis.b #BIT1, &P1OUT
	jmp delay
  ;burada 1.2 portu sifirlayip 1.1 i yakiyor
kirmizi:
    mov.b #35,r6
	bic.b #BIT1, &P1OUT ; Turn off LED.
	bis.b #BIT4, &P1OUT
	jmp delayk
  ;burada 1.1 'i sifirlayip 1.4 u yakiyor


delaym:  ;Delay algosu burada calismakda
	mov.b #0,r15
	jmp delayym

delayym:
    dec r15
    jnz delayym
    xor.b #00000100b ,&P1OUT
delayyym:
     dec r5
     jnz delaym
	 jmp yesil


delay:  ;Delay algosu burada calismakda
	mov.b #0,r15
	jmp delayy

delayy:
    dec r15
    jnz delayy
    xor.b #00000010b ,&P1OUT
delayyy:
     dec r4
     jnz delay
	 jmp kirmizi



delayk:  ;Delay algosu burada calismakda
	mov.b #0,r15
	jmp delayyk

delayyk:
    dec r15
    jnz delayyk
    xor.b #00010000b ,&P1OUT
delayyyk:
     dec r6
     jnz delayk
	 jmp main








;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
