section .data
arr dq 0xAACBFF401689F207, 0xCC01F301F89F207, 0xBC401F309EFF200, 0xEC44801801E89F207
neg;db 00h
pos; db 00h
cnt; db 5h


section text
gobal_start
strt:
mov rsi,arr
mov raxbyte [rsi]
jnc 11
inc neg
jmp12
l1;
inc pos
l2;
dec cnt
cmp cnt,00h

 mov rax,01
 mov rdi 01
 mov rsi, pos
 mov rdx,2
 sycll 
 
 mov rax,01
 mov rdi,01
 mov rsi,neg
 mov rdx,1
 syscall
 
 mov rax,60
 mov rdi,00
 syscall
 
 
 
 

