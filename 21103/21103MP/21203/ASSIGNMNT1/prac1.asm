Section .data
m1 db "hello",10,"world",10
Section .text
global _start
_start:
mov rax,01
mov rdi,01
mov rsi,m1
mov rdx,12
syscall
mov rax,60
mov rdx,0
syscall
