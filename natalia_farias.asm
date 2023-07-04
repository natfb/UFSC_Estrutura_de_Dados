; 0,5 us * x = 1ms
; x = 1,0 ms / 0,5us
; x = 2000 
; loop interno 7 + y * (4 + 10) - 3 = 1990
; y = 141 8BH
; 1990 + 10 (RET) = 2000


.define
	EndDigito A000h   ; Endereço em que serão salvos os digitos hexa correspondentes aos decimais
	Digito0 77h	      ; Número hexadecimal para o display mostrar 0
	Digito1 44h		; Número hexadecimal para o display mostrar 1
	Digito2 3Eh		; Número hexadecimal para o display mostrar 2
	Digito3 6Eh		; Número hexadecimal para o display mostrar 3
	Digito4 4Dh		; Número hexadecimal para o display mostrar 4
	Digito5 6Bh		; Número hexadecimal para o display mostrar 5
	Digito6 7Bh		; Número hexadecimal para o display mostrar 6
	Digito7 46h		; Número hexadecimal para o display mostrar 7
	Digito8 7Fh		; Número hexadecimal para o display mostrar 8
	Digito9 4Fh		; Número hexadecimal para o display mostrar 9
	dig 77h	
	atraso1 01H		; Valor para delay
	SegundoU 05h	; Definindo porta de saída para a unidade do segundo
	SegundoD 04h	; Definindo porta de saída para a dezena do segundo
	MinutoU 03h		; Definindo porta de saída para a unidade do minuto
	MinutoD 02h		; Definindo porta de saída para a dezena do minuto
	HoraU 01h		; Definindo porta de saída para a unidade da hora
	HoraD 00h		; Definindo porta de saída para a dezena da hora


.data EndDigito		; Salvando os valores hexacimais no endereço indicado
	DB Digito0, Digito1, Digito2, Digito3, Digito4
	DB Digito5, Digito6, Digito7, Digito8, Digito9	

	
.org 1000h 			; salva o programa no endereço 1000h
	LXI B, EndDigito  ; Move EndDigito para BC
	mvi d, 0h         ; CONTADOR DA UNIDADE SEGUNDOS
	mvi e, 0h         ; CONTADOR DA DEZENA SEGUNDOS
	mvi a, 0h       
	sta a01eh         ; CONTADOR DA UNIDADE MINUTOS
	sta a01fh         ; CONTADOR DA DEZENA MINUTOS
	sta a020h         ; CONTADOR DA UNIDADE HORA
	sta a021h         ; CONTADOR DA DEZENA HORA

      LDA EndDigito	; mostrar 0 no display
      OUT SegundoU
      OUT SegundoD
	OUT MinutoU
      OUT MinutoD
	OUT HoraU
      OUT HoraD
loop:					; Loop infinito
	CALL delay			; Chamada do delay
	CALL contador		; Chamada do contador
      JMP loop
	
.org 2000h			; Endereço do contador
contador:
	Lxi b, EndDigito  ; Move EndDigito para BC
    	Mov a, d          ; MOVE O CONTADOR DOS SEGUNDOS PARA A
	
L1:                     ; LOOP USANDO O CONTADOR DA UNIDADE DOS SEGUNDO PARA incrementar b    
    	dcr a      
	inX b	
     	jnz L1

	LDAX B
	CPI Digito9		; compara com o número 9
     	JZ digito_dezena  ; Se for 9, zerar a unidade e incrementar dezena
	                  ; se nao for incremenatar unidade   
	Inr d
    	Mov a, d        
    	Lxi b, EndDigito
             
L2:           
    	INX b 
    	dcr a        
    	JNZ L2 
       	
	ldax b	
	OUT SegundoU     ; mostrar o digito			
	RET	
		 
digito_dezena:          ; *todos os loops usam a mesma logica*
	LXI B, EndDigito	
	mvi d, 00h
	mov a, d
	cpi 00h	
	jz L03       ; QUANDO ZERAR FAZER ESTE LOOP
L3: 
	inX b    
    	dcr a        
    	JNZ L3
L03:	
	LDAX B	
	OUT SegundoU
	
	LXI B, EndDigito
	mov a, e	

L4:   inX b    
    	dcr a        
    	JNZ L4

	LDAX B
	CPI Digito5	; compara com o número 5
	JZ minuto	; Se for 5, zerar a dezena e incrementar unidade dos minutos
	            ; se nao for 5, incrementa

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
	LXI B, EndDigito	
	mvi e, 00h
	mov a, e
	inr a
	cpi 00H
	jz L06

L6:   inX b    
    	dcr a        
    	JNZ L6	
L06:	
	LDAX B	
	OUT SegundoD	
	
	LXI B, EndDigito
	lxi h, a01eh
	mov a, m
		
L7:   inX b    
    	dcr a        
    	JNZ L7	
	LDAX B
	
	CPI Digito9	    
	JZ minuto_dezena	; Se for 9, zerar a unidade do minuto e incrementar dezena do minuto
	                  ; se nao for 9 incrementa	
	
	Lxi b, EndDigito
	lxi h, a01eh
	mov a, m	
	inr a
	sta a01eh

L8:           
    	INX b   
    	dcr a     
    	JNZ L8  
      sta a014h  
	
	LDAX B
	sta a015h		
	OUT MinutoU				
	RET
				
minuto_dezena:
	LXI B, EndDigito		
	lxi h, a01eh
	mvi m, 0h
	mov a, m
	inr a 
	CPI 00
	JZ L09

L9:   inX b    
    	dcr a        
    	JNZ L9	

L09:
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
	JZ hora		; Se for 5, zerar a dezena do minuto e incrementar unidade da hora
	                  ; se nao for 5 incrementa	
	
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
	LXI B, EndDigito	
	lxi h, a01fh
	mvi m, 0h
	mov a, m
	CPI 00H
	JZ L012
L12: inX b    
    	dcr a        
    	JNZ L12	
L012:	
	LDAX B	
	OUT MinutoD	
	
	LXI B, EndDigito
	lxi h, a020h
	mov a, m
	
L13:  inX b    
    	dcr a        
    	JNZ L13	
	
	LDAX B
	CPI Digito9	   
	JZ hora_dezena	; Se for 9, zerar a unidade da hora e incrementar dezena da hora
	                  ; se nao for 5 incrementa	
	CPI Digito3       ; compara com número 3
	jz ZERAR_HORA     ; loop para verificar se são 23 horas
resume:
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
	jnz resume   ; se não for 3 volta para o loop
	             ; se a unidade da hora for 3 pela terceira vez, reseta
	mvi m, 01h
	mov a, m

	LXI B, EndDigito   ; zerar unidade das horas
	lxi h, a020h
	mvi m, 01h
	mov a, m

L18:  inX b    
    	dcr a        
    	JNZ L18
	
	LDAX B	   ; zerar dezena das horas
	OUT HoraU

	LXI B, EndDigito		
	lxi h, a021h
	mvi m, 01h
	mov a, m

L19:  inX b    
    	dcr a        
    	JNZ L19
	
	LDAX B	
	OUT HoraD	
	
	RET

.org 2200h			; Endereço do delay
delay:			; Rotina de Delay
	MVI H, atraso1	
loop1:
	DCR H
	JNZ loop1
	RET

