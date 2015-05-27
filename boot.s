MUST_ALIGN        equ 1<<0
MEMINFO           equ 1<<1
MAGIC_NUMBER      equ 0x1BADB002
FLAGS             equ MEMINFO | MUST_ALIGN
CHECKSUM          equ -(MAGIC_NUMBER + FLAGS)
KERNEL_STACK_SIZE equ 4096

section .multiboot
align 0x4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

section .bss
align 0x4
kernel_stack:
  resb  KERNEL_STACK_SIZE

section .text
global  _start
_start:
  mov   eax,  0xDEADBEEF
  mov   esp,  kernel_stack + KERNEL_STACK_SIZE
  extern  kmain
  call  kmain
  cli

.loop:
  hlt
  jmp   .loop
