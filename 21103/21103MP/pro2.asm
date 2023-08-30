section .data
msg: db "Enter a string:-" , 0xA
l1:equ $-msg

msg2: db " The len of given string :- "
l2:equ $-msg2

section .bss
str: resb 16
len: resb 16
num: resb 2

section .text
global _start
_start:

mov rax, 1
mov rdi, 1
mov rsi, msg
mov rdx, l1
syscall


mov rax, 0
mov rdi, 0
mov rsi, str
mov rdx, 16
syscall

dec al
mov rsi , num
mov cl , 02h

j1:
rol al , 4
mov bl , al
and bl , 0Fh
cmp bl , 09h
jle j2
add bl , 07h
j2:
add bl , 30h
mov byte[rsi],bl
inc rsi
dec cl
jnz j1

mov rax, 1
mov rdi, 1
mov rsi, msg2
mov rdx, l2
syscall

mov rax, 1
mov rdi, 1
mov rsi, num
mov rdx, 2
syscall

mov rax , 60
mov rdi,0
syscall

