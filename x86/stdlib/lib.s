.intel_syntax noprefix
.global _start
.text

_start:
  mov rdi, 1337
  lea rsi, [buffer + 32]
  call itoa
  mov rdi, rax
  call print

  mov rdi, 557
  lea rsi, [buffer + 32]
  call itoa
  mov rdi, rax
  call print

  call exit

itoa:
  mov rbx, 10
  mov rax, rdi

  mov byte ptr [rsi], 0x0
  dec rsi
  mov byte ptr [rsi], '\n'

  _itoa_loop:
    xor rdx, rdx
    dec rsi
    div rbx
    add rdx, '0'
    mov [rsi], dl
    cmp rax, 0
    jne _itoa_loop

  mov rax, rsi
  ret

exit:
  mov rax, 60
  xor rdi, rdi
  syscall

print:
  call strlen
  mov rcx, rax

  mov rax, 1
  lea rsi, [rdi]
  mov rdi, 1
  mov rdx, rcx
  syscall
  ret
  
strlen:
  xor rcx, rcx
  mov rax, rdi

  _loop:
    mov bl, [rax]
    cmp bl, 0
    je _strlen_exit
    inc rcx
    inc rax
    jmp _loop

  _strlen_exit:
    mov rax, rcx
    ret

.data
  buffer: .zero 4096
