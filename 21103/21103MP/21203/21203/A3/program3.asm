section .data
    array dq -1h, -74h, 24h, -3h, -50h
    n equ 5

    p_msg db "No of positive Elements is: "
    p_len equ $-p_msg
    
    n_msg db "No of negative Elements is: "
    n_len equ $-n_msg

%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

%macro exit 0
    mov rax, 60
    mov rdi, 0
    syscall
%endmacro

section .bss
    p_count: resb 20
    n_count: resb 20

section .text
global _start

_start: 
    mov rsi, array
    mov rcx, n

    mov rbx, 0   ; positive count
    mov rdx, 0   ; negative count

back:
    mov rax, [rsi]
    shl rax, 1
    jc negative

positive:
    inc rbx
    jmp next

negative:
    inc rdx

next:
    add rsi, 8
    dec rcx
    jnz back

    add rbx, 30h
    add rdx, 30h

    mov [p_count], rbx
    mov [n_count], rdx
    
    print p_msg, p_len
    print p_count, 20

    print n_msg, n_len
    print n_count, 20

    exit

