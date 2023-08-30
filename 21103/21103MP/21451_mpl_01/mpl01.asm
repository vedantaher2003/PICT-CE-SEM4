section .data				;definition = allocate + initialize
	msg1 db "Enter 5 numbers:", 0xA
	len1 equ $-msg1
	
	msg2 db "Numbers:", 0xA
	len2 equ $-msg2
	
section .bss				;declaration = allocation
	array resb 85			;reserve 85 bytes for 5 elements of array
	
section .text				;actual block of code
global _start				;declare label for main block of code as public

_start:
	
InputCall:				;Ask for input
	mov rax, 01			;01 = write system call
	mov rdi, 01			;01 = file handler set to console for o/p
	mov rsi, msg1			;source to print from
	mov rdx, len1			;no of bytes to print
	syscall			;system call - actual execution
	
	mov r8, array			;set pointer to start of array
	mov rcx, 5			;set counter for 5 iterations
	
ArrayInput:
	mov rax, 00			;00 = read system call
	mov rdi, 00			;00 = file handler set to keyboard for i/p
	mov rsi, r8			;read value into r8
	mov rdx, 17			;read 17 bit = 16 bit num + 1 for enter
	syscall
	
	add r8, 17
	dec byte[rcx]
	jnz ArrayInput
	
OutputCall:				;
	mov rax, 01			;01 = write system call
	mov rdi, 01			;01 = file handler set to console for o/p
	mov rsi, msg2			;source to print from
	mov rdx, len2			;no of bytes to print
	syscall			;system call - actual execution
	
	mov r8, array			;set pointer to start of array
	add rcx, 5
	
ArrayPrint:
	mov rax, 01
	mov rdi, 01
	mov rsi, r8
	mov rdx, 17
	syscall
	
	add r8, 17
	dec byte[rcx]
	jnz ArrayPrint
	
	
_exit:
	mov rax, 60			;60 = exit system call
	mov rdi, 00			;exit code 0
	syscall			;exit from program
