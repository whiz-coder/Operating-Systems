section .data
hello: db '.'
hellolen: equ $-hello

section .text 
global _start

_start:
mov ecx , 500000

l1:

    mov ebx , ecx

    mov rdi , 1
    mov rsi,hello
    mov rdx , hellolen
    mov rax,1
    syscall

    mov ecx , ebx

loop l1

mov rdi , 0
mov rax , 60
syscall