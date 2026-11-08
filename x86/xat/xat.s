.intel_syntax noprefix
.global _start
.text

_start:
  lea rdi, [filename]
  call _fopen

  ;# Read
  mov rdi, rax
  lea rsi, [buffer]
  mov rdx, 4096
  xor rax, rax
  syscall

  ;# Print buffer from read
  lea rdi, [buffer]
  call _print

_exit:
  mov rax, 60
  xor rdi, rdi
  syscall

_fopen:
  mov rax, 2
  xor rsi, rsi
  xor rdx, rdx
  syscall
  ret

_print:
  call _strlen
  mov rcx, rax

  mov rax, 1
  lea rsi, [rdi]
  mov rdi, 1
  mov rdx, rcx
  syscall
  ret
  
_strlen:
  xor rcx, rcx
  mov rax, rdi

  loop:
    mov bl, [rax]
    cmp bl, 0
    je _strlen_exit
    inc rcx
    inc rax
    jmp loop

  _strlen_exit:
    mov rax, rcx
    ret

.data
  buffer: .skip 4096
  filename: .string  "/home/birk/dev/learn/clang/x86/xat/testing.txt"

