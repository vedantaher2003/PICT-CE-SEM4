section .data				;definition = allocate + initialize
	msg db "Enter your name:", 0xA	;store string in msg variable then go to next line
	len equ $-msg			;store length of msg string as = current cursor position - start of msg string
	
	msg1 db "My name is: ", 0xA
	len1 equ $-msg1
	
	msg2 db "Enter 5 numbers: ", 0xA
	len2 equ $-msg2
	
	msg3 db "Numbers: ", 0xA
	len3 equ $-msg2
	
	counter db 4			;set counter for looping
	c1 db 5			;set counter for array input
	c2 db 5			;set counter for array output
	
section .bss			;declaration = allocation
	name resb 20			;reserve 20 bytes for 'name' variable
	array resb 85			;reserve 85 bytes for 5 elements of array
	
section .text				;actual block of code
global _start				;declare label for main block of code as public

_start:

_HelloWorld:				;print hello world to console
	mov rax, 01			;01 = write system call
	mov rdi, 01			;01 = file handler set to console for o/p
	mov rsi, msg			;source to print from
	mov rdx, len			;no of bytes to print
	syscall			;system call - actual execution
	
_PrintName:				;take name input from user and print on console
	mov rax, 00			;00 = read system call
	mov rdi, 00			;00 = file hanlder set to keyboard for i/p
	mov rsi, name			;variable to store value
	mov rdx, 20			;no of bytes to store
	syscall
	
	mov rax, 01			;print msg1
	mov rdi, 01
	mov rsi, msg1
	mov rdx, len1
	syscall
	
_nameLoop:				;print name 5 times
	mov rax, 01			;print name
	mov rdi, 01
	mov rsi, name
	mov rdx, 20
	syscall
	
	dec byte[counter]
	jnz _nameLoop
	
InputCall:				;Ask for input
	mov rax, 01			;01 = write system call
	mov rdi, 01			;01 = file handler set to console for o/p
	mov rsi, msg2			;source to print from
	mov rdx, len2			;no of bytes to print
	syscall			;system call - actual execution
	
	mov r8, array			;set pointer to start of array
	
ArrayInput:
	mov rax, 00
	mov rdi, 00
	mov rsi, r8
	mov rdx, 17
	syscall
	
	add r8, 17
	dec byte[c1]
	jnz ArrayInput
	
OutputCall:				;Ask for input
	mov rax, 01			;01 = write system call
	mov rdi, 01			;01 = file handler set to console for o/p
	mov rsi, msg3			;source to print from
	mov rdx, len3			;no of bytes to print
	syscall			;system call - actual execution
	
	mov r8, array			;set pointer to start of array
	
ArrayPrint:
	mov rax, 01
	mov rdi, 01
	mov rsi, r8
	mov rdx, 17
	syscall
	
	add r8, 17
	dec byte[c2]
	jnz ArrayPrint
	
	
_exit:
	mov rax, 60			;60 = exit system call
	mov rdi, 00			;exit code 0
	syscall			;exit from program
