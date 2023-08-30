
 

%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

section .data
    array: dq 08h, 2320h, 102h, 65h, 98h
    n: equ 5

    msg: db "The Greatest Number is: "
    len: equ $-msg

    largest: dq 00

section .bss
    result: resb 16
    count: resb 1
    asciiarr resb 02

section .text
    global _start

_start:
    mov rsi, array
    mov rcx, n

up: 
    mov rax, [rsi]
    cmp [largest], rax
    jge down1
    mov [largest], rax

down1:
    add rsi, 08
    dec rcx
    jnz up

    print msg, len
    mov rdx, [largest]
    mov [result], rdx
    call hextoascii

    mov rax,60
    mov rdi,00
    syscall

hextoascii:
    mov rsi,asciiarr
    mov byte[count],0x10
    mov rax, [result]
down:    
    rol rax,04h
    mov bl,al
    and bl,0fh
    cmp bl,09h
    jbe next
    add bl,07h
	
next:      
    add bl,30h
    mov [rsi],bl
    inc rsi
    dec byte[count]
    jnz down
    print asciiarr,16
    ret
    
    
    
    
    
    
    
    
    
    
    
  
