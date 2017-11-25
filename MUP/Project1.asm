;Code starts here
.model tiny
.data
MLP1	   DW 390; muptiplying individual weighs by .39 to convert the range from 0-255 to 0-100
MLP2   	   DW 390 ; muptiplying individual weighs by .39 to convert the range from 0-255 to 0-100
MLP3	   DW 390 ; muptiplying individual weighs by .39 to convert the range from 0-255 to 0-100
Thousand   DW 1000 
Ten        DB 10	;to seperate the unit and tens digits
THREE	   DB 03
UNITS	   DB ?
TENS       DB ?
Weight1    DB ?
Weight2    DB ?
Weight3    DB ?
AverageWieght      DB ?
porta      equ 00h
portb      equ 02h
portc      equ 04h
creg       equ 06h
stack      dw  100 dup(?)
top_stack  label word ;for calling sub routine

.code
.startup

	LEA 	SP,top_stack	;initialising stack for the sub routine
	MOV 	AL,90h		;10010000b
		  		;port A input 
		  		;port B & C output
	OUT 	creg,AL
	
	;BSR mode to select pins of ADC
	
	
	
	;Selecting IN0
	MOV 	AL,08h      ;00001000b
	OUT 	creg,AL     	;PC4 logic zero
	MOV 	AL,0ah      ;00001010b
	OUT 	creg,AL     ;PC5 logic zero
	;IN0 of ADC is selected
	
	CALL 	delay_on_soc  ;sending low and high pulses with delay to ADC to convert analog to digital

	MOV 	AL,90h      ;10011000b port A input & port B & C output
	OUT 	creg,AL
	;CHECKING FOR END OF CONVERSION	;(whether EOC= LOGIC 1)
	;CHECKING STARTS

X1:	IN 		AL,portc  ;loading in the reults of port c pins
	AND 	AL,80h ; considering only the result of pin 7
	JZ 		X1 
	
	
	IN 		AL,porta	;dig. o/p of ADC is read
	MOV 	Weight1,AL	;store o/p into mem as weight 1


	;Select IN1
	MOV 	AL,09h	;00001001b
	OUT 	creg,AL	;pc4 logic one
	MOV 	AL,0ah	;00001010b
	OUT 	creg,AL	;pc5 logic zero
	;IN1 is selected
	CALL 	delay_on_soc  ;500 ns low to ADC
	MOV AL,90h	;10010000b port A input & port B & C output
	OUT creg,AL

X2:	IN AL,portc ; reading port c results
	AND AL,80h ; considering only  C7.
	JZ X2
	
	MOV AL,90h	;1001000b
	OUT creg,AL
	
	IN AL,porta	;dig o/p. of ADC is read
	MOV Weight2,AL	;store o/p. into mem as weight 2.
	
	
	
	;Select IN2 
	MOV AL,08h	;00001000b
	OUT creg,AL	;set PC4 logic zero
	MOV AL,0bh	;00001011b
	OUT creg,AL	;set PC5 logic one
	;IN2 is selected			
     CALL delay_on_soc  ;500ns low to ADC.
	MOV AL,90h	;10010000b
	OUT creg,AL


X3:	IN AL,portc ; reading port c data
	AND AL,80h ; data of only pin 7 is considered.
	JZ X3
	MOV AL,90h	;10010000b
	OUT creg,AL
	IN AL,porta     ;dig o/p of ADC is read
	MOV Weight3,AL      ;Store o/p into mem as weight 3.
		
		
		
;Calculating converted Weight
	MOV AH,00h		
	MOV AL,Weight1 ; AX register now holds weight 1.
	MUL MLP1
	DIV Thousand ;changing the range of data to 0-100
	MOV Weight1,AL  ;i/p wt of load1 MOVed to Weight1 
	
	MOV AH,00h		
	MOV AL,Weight2; AX register now holds weight 3.
	MUL MLP2
	DIV Thousand	;changing the range of data to 0-100
	MOV Weight2,AL  ;i/p wt of load2 MOVed to Weight2
	
	MOV AH,00h		
	MOV AL,Weight3; AX register now holds weight 3.
	MUL MLP3
	DIV Thousand ;changing the range of data to 0-100
	MOV Weight3,AL   ;i/p wt of load3 MOVed to Weight3
		
		
;Calculating average of Weight1,Weight2 and Weight3
	CLC
	MOV ah,00h
	MOV bh,00h
	MOV Al,Weight1
	MOV bl,Weight2
	ADC AX,BX ; adding Weight1 and Weight2
	MOV bl,Weight3
	ADC AX,BX ; total wt is  now stored in ax
	DIV THREE		;Avg of 3 wts MOVed to AL
	MOV AverageWieght,AL    ;MOVing avg to mem in AverageWieght

	CMP AL,50      ;Check if AVGWT < 50kg
	JB display ;if avg is below 100 then we have to display it on secreen.

BUZZER:    	
	MOV AL,05h	;00000101b
	OUT creg,AL	;alarm if(load>50kg)
	MOV cx,05h
DELAY1:	nop
	loop DELAY1
    JMP BUZZER  ; loop for sounding the buzzer.

	;display (wt<50kg)
		

display:	MOV AH,00h 
			MOV AL,AverageWieght
			DIV Ten  ;Separating two digits of weight		
			;Storing digits in mem
			MOV TENS,AL 
			MOV UNITS,AH
			
			        	
	
disp:	MOV	AL,01h	;00000001b
		OUT	creg,AL	;(pc0)
		;Switch on units digit display
		
		MOV	AL,90h	;10010000b
		OUT creg,AL		
		;Set i/o mode to input 7447

		MOV	AL,UNITS
		OUT	portb,AL
		MOV	AL,00h	;Switch off units digit display
		OUT	creg,AL		
		

		MOV	AL,03h	;00000011b
		OUT	creg,AL	;(pc1)	
		;Switch on tens digit display

		MOV	AL,90h	;10010000b
		OUT	creg,AL		
		;i/o mode to input 7447

		MOV	AL,TENS	
		OUT	portb,AL
		
		MOV	AL,02h	;00000010b
		OUT	creg,AL 
		;Switch off tens digit display
 
		JMP	disp
.exit

delay_on_soc proc near
   MOV 	AL,06h		;00000110b
   OUT	creg,AL	   	 ;set pc3 low
	
	MOV cx,05h
DELAY:	nop
	loop DELAY
   MOV 	AL,07h		;00000111b
   OUT 	creg,AL	    	;set pc3 high
RET
delay_on_soc endp

end
		

	
	
	