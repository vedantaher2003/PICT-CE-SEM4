section .data
display: db "Enter 5 bytes "
len: equ $-display
cnt: db 0

section .bss
str: resb 20

section .text
global _start
_start:

    mov rax, 1
    mov rdi, 1
    mov rsi, display
    mov rdx, len
    syscall


    mov rbx, str
    mov byte[cnt], 05H

    read:
        mov rax, 0
        mov rdi, 0
        mov rsi, rbx
        mov rdx, 17
        syscall
        add rbx, 17
        dec byte[cnt]
        jnz read

    mov rbx, str
    mov byte[cnt], 05H

    print:
        mov rax, 1
        mov rdi, 1
        mov rsi, rbx
        mov rdx, 17
        syscall
        add rbx, 17
        dec byte[cnt]
        jnz print

    mov rax, 60
    mov rdi, 00
    syscall
Footer

