section .data
msg1 db "Enter a string :", 0xA
l1:equ $-msg1

msg3: db "The length of the given string is : "
l3: equ $-msg3

section .bss
str: resb 16
len: resb 16
num: resb 2

section .text
global _start
_start:

mov rax, 01
mov rdi, 01
mov rsi, msg1
mov rdx, l1
syscall

mov rax, 00
mov rdi, 00
mov rsi, str
mov rdx, 16
syscall


dec al
add rsi, num
mov cl, 2h
up:
rol al,4
mov bl,al
and bl, 0Fh
cmp bl,09h
jle up1
add bl,07h
up1:
add bl,30h
mov byte[rsi],bl
inc rsi
dec cl
jnz up

mov rax,01
mov rdi,01
mov rsi, msg3
mov rdx, l3
syscall

mov rax,01
mov rdi,01
mov rsi,msg3
mov rdx,16
syscall

mov rax,60
mov rdi,00
syscall


