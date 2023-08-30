%macro print 2
	mov rax, 01	; system call write
	mov rdi, 01	; write-call handler
	mov rsi, %1	; result
	mov rdx, %2	; bytes to write
	syscall
%endmacro

section .data
	newLine db 0xA
	newLineLen equ $-newLine
	
	msgHex db "HEX = "
	msgHexLen equ $-msgHex
	
	msgDec db "DEC = "
	msgDecLen equ $-msgDec
	
	cnt db 4
	
	;num dq 1234h
	num dq 4660

section .bss
	result: resq 2
	
	
section .text
global _start

_start:
	
	;call HexToBCD
	call BCDTOHex
	
_exit:
	mov rax, 60			;exit system call
	mov rdi, 00
	syscall
	
; ---- SUB-ROUTINES ----

HexToAscii:
	mov byte[cnt], 16           
	mov rdi, result        	 ;pointer at result

	Loop4:
		rol al, 4               ;rotate B by 4 bits to left
		mov bl, al  
		and bl, 0fh             ;mask at lower byte

		cmp bl, 09h
		jbe BELOW_9
		add bl, 07h

	BELOW_9:    
		add bl, 30h
		mov [rdi], bl           ;store hex-ascii value into result

		inc rdi                 ;increment result pointer 
		dec byte[cnt]           ;decrement counter
		jnz Loop4               ;repeat LOOP till cnt becomes zero (16 times)
	ret

BCDToAscii:
	add rbx, 30h
	mov [result], rbx
	
	ret	
	
HexToBCD:
	mov rax, qword[num]
	mov ebx, 0xA
	
	Loop1:
	
	xor rdx, rdx
	
	div ebx
	push rdx
	
	dec byte[cnt]	
	jnz Loop1
	
	mov byte[cnt], 04h
	print msgDec, msgDecLen
	
	Loop2:
	
	pop rbx
	
	call BCDToAscii
	print result, 16
	
	dec byte[cnt]
	jnz Loop2
	
	print newLine, newLineLen
	ret
	
BCDTOHex:
	;get each digit - divide by factor of 10
	;multiply by corresponding factor - mul by factor of 10
	;add to sum	
	
	mov byte[cnt], 04h
	mov rax, qword[num]	;complete number
	mov r8, 00h 		;current digit
	mov bx, 10h		;factor of 10 to obtain digit

	ObtainDigits:
	
	xor rdx, rdx		;refresh rdx
	
	div bx			into stack
	;remainder is the digit stored at rdx
	push rdx		;push digit 
	dec byte[cnt]
	jnz ObtainDigits
	
	xor rax, rax
	xor rdx, rdx
	mov ecx, 10h

	MultiplyWithFactor:
	
	pop rax
	mul ecx
	
	add r8, rdx
	rol r8, 32
	add r8, rax
	rol r8, 32
	
	shl ecx, 4
	
	dec byte[cnt]
	jnz MultiplyWithFactor
	
	mov rax, r8
	call HexToAscii
	print result, 2
	
	ret
	
	
	
