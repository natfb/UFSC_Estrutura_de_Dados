; 0,5 us * x = 1ms
; x = 1,0 ms / 0,5us
; x = 2000 
; loop interno 7 + x * (4 + 10) - 3 = 18
; X = 141 8BH
; 1990 + 10 (RET) = 2000


.define
	EndDigito A000h   ; Endere?o em que os valores hex dos dig?tos decimais ser?o salvos
	Digito0 77h	      ; Valor hex para o display mostrar o digito 0
	Digito1 44h		; Valor hex para o display mostrar o digito 1
	Digito2 3Eh		; Valor hex para o display mostrar o digito 2
	Digito3 6Eh		; Valor hex para o display mostrar o digito 3
	Digito4 4Dh		; Valor hex para o display mostrar o digito 4
	Digito5 6Bh		; Valor hex para o display mostrar o digito 5
	Digito6 7Bh		; Valor hex para o display mostrar o digito 6
	Digito7 46h		; Valor hex para o display mostrar o digito 7
	Digito8 7Fh		; Valor hex para o display mostrar o digito 8
	Digito9 4Fh		; Valor hex para o display mostrar o digito 9
	dig 77h	
	atraso1 01H		; Valor para delay. Escolher diferente de 00h
	SegundoU 05h		; Definindo porta de sa?da para digito da unidade do segundo
	SegundoD 04h		; Definindo porta de sa?da para digito da dezena do segundo
	MinutoU 03h		; Definindo porta de sa?da para digito da unidade do minuto
	MinutoD 02h		; Definindo porta de sa?da para digito da dezena do minuto
	HoraU 01h		; Definindo porta de sa?da para digito da unidade da hora
	HoraD 00h		; Definindo porta de sa?da para digito da dezena da hora


.data EndDigito		; Salvando os valores hex no endere?o indicado
	DB Digito0, Digito1, Digito2, Digito3, Digito4
	DB Digito5, Digito6, Digito7, Digito8, Digito9	

	
.org 1000h 			; Iniciar o programa no endere?o 1000h
	LXI B, EndDigito  ; Par de registradores BC utilizado para o d?gito de unidade
	mvi d, 01h      ;CONTADOR DA UNIDADE SEGUNDOS
	mvi e, 01h      ; CONTADOR DA DEZENA SEGUNDOS
	mvi a, 01h       
	sta a01eh        ;CONTADOR DA UNIDADE MINUTOS
	sta a01fh        ;CONTADOR DA DEZENA MINUTOS
	sta a020h       ;CONTADOR DA UNIDADE HORA
	sta a021h        ;CONTADOR DA DEZENA HORA

      LDA EndDigito	; Preenchendo com o d?gito 0 no display
      OUT SegundoU
      OUT SegundoD
	OUT MinutoU
      OUT MinutoD
	OUT HoraU
      OUT HoraD
loop:					; Loop infinito
	CALL delay			; Chamada da sub-rotina de delay
	CALL contador		; Chamada da sub-rotina do contador
      JMP loop
	
.org 2000h			; Endere?o da sub-rotina do contador
contador:
	Lxi b, EndDigito
    	Mov a, d          ; MOVE O CONTADOR DOS SEGUNDOS PARA A

L1:                     ; LOOP USANDO O CONTADOR DA UNIDADE DOS SEGUNDO PARA incrementar b
    	inX b    
    	dcr a        
    	JNZ L1	
     	
	LDAX B
	CPI Digito9		; Comparar com o valor hex para 9
     	JZ digito_dezena
	                     ; Se digito da unidade for 9, ent?o deve-se zerar o digito
	Inr d
    	Mov a, d        
    	Lxi b, EndDigito
L2:           
    	INX b 
    	dcr a        
    	JNZ L2         	
	ldax b	
	OUT SegundoU			
	RET	
		 
digito_dezena:          ; *todos os loops usam a mesma logica*
	LXI B, EndDigito	; Resetar o endere?o apontado pelo par BC
	mvi d, 01h
	mov a, d

L3: 
	inX b    
    	dcr a        
    	JNZ L3	
	LDAX B	
	OUT SegundoU
	
	LXI B, EndDigito
	mov a, e	

L4:   inX b    
    	dcr a        
    	JNZ L4	
	LDAX B
	
	CPI Digito5	; Comparar com o valor hex do d?gito 5
	JZ minuto	; Caso o d?gito da dezena seja 5, PULA PARA O LOOP DOS MINUTOS.	
	
	Lxi b, EndDigito
	inr e
	mov a, e	

L5:           
    	INX b   
    	dcr a        
    	JNZ L5        

	LDAX B		
	OUT SegundoD				
	RET			

minuto:
	LXI B, EndDigito	; Resetar o endere?o apontado pelo par BC
	mvi e, 01h
	mov a, e

L6:   inX b    
    	dcr a        
    	JNZ L6	
	
	LDAX B	
	OUT SegundoD	
	
	LXI B, EndDigito
	lxi h, a01eh
	mov a, m
		
L7: inX b    
    	dcr a        
    	JNZ L7	
	LDAX B
	
	CPI Digito9	    ; Comparar com o valor hex do d?gito 9
	JZ minuto_dezena	;	
	
	Lxi b, EndDigito
	lxi h, a01eh
	mov a, m	
	inr a
	sta a01eh

L8:           
    	INX b   
    	dcr a       
    	JNZ L8         

	LDAX B		
	OUT MinutoU				
	RET
				
minuto_dezena:
	LXI B, EndDigito	; Resetar o endere?o apontado pelo par BC	
	lxi h, a01eh
	mvi m, 01h
	mov a, m

L9:   inX b    
    	dcr a        
    	JNZ L9	
	
	LDAX B	
	OUT MinutoU	
	
	LXI B, EndDigito
	lxi h, a01fh
	mov a, m
	
L10:  inX b    
    	dcr a        
    	JNZ L10	
	
	LDAX B
	CPI Digito5	
	JZ hora		
	
	Lxi b, EndDigito
	lxi h, a01fh
	mov a, m	
	inr a
	mov m, a

L11:           
    	INX b   
    	dcr a       
    	JNZ L11         

	LDAX B		
	OUT MinutoD				
	RET

hora:
	LXI B, EndDigito	; Resetar o endere?o apontado pelo par BC	
	lxi h, a01fh
	mvi m, 01h
	mov a, m

L12: inX b    
    	dcr a        
    	JNZ L12	
	
	LDAX B	
	OUT MinutoD	
	
	LXI B, EndDigito
	lxi h, a020h
	mov a, m
	
L13:  inX b    
    	dcr a        
    	JNZ L13	
	
	LDAX B
	CPI Digito9	; Comparar com o valor hex do d?gito 9
	JZ hora_dezena	;	
	CPI Digito4
	jz ZERAR_HORA
zerarr:
	Lxi b, EndDigito
	lxi h, a020h
	mov a, m	
	inr a
	mov m, a

L14:           
    	INX b   
    	dcr a       
    	JNZ L14         

	LDAX B			
	OUT HoraU				
	RET

hora_dezena:
	LXI B, EndDigito	; Resetar o endere?o apontado pelo par BC	
	lxi h, a020h
	mvi m, 01h
	mov a, m

L15:  inX b    
    	dcr a        
    	JNZ L15	
	
	LDAX B	
	OUT HoraU		

	Lxi b, EndDigito
	lxi h, a021h
	mov a, m
	inr a
	mov m, a

L17:           
    	INX b   
    	dcr a        
    	JNZ L17        

	LDAX B		
	OUT HoraD	
			
	RET

ZERAR_HORA:
	lxi h, a023h
	MOV A, M
	inr a
	sta a023h
	cpi 03
	jnz zerarr
	
	mvi m, 01h
	mov a, m

	LXI B, EndDigito	; Resetar o endere?o apontado pelo par BC	
	lxi h, a021h
	mvi m, 01h
	mov a, m

L19:  inX b    
    	dcr a        
    	JNZ L19
	
	LDAX B	
	OUT HoraD	
	
	RET
	
.org 2200h			; Endere?o da sub-rotina de delay
delay:			; Rotina de Delay
	MVI H, atraso1	
loop1:
	DCR H
	JNZ loop1
	RET

