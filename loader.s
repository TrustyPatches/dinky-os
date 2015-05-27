global  loader
extern  kmain

MUST_ALIGN        equ 1<<0
MEMINFO           equ 1<<1
MAGIC_NUMBER      equ 0x1BADB002
FLAGS             equ MEMINFO | MUST_ALIGN
CHECKSUM          equ -(MAGIC_NUMBER + FLAGS)
KERNEL_STACK_SIZE equ 4096

section .bss
align 0x4
kernel_stack:
  resb  KERNEL_STACK_SIZE

section .multiboot
align 0x4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

section .text
loader:
  mov   eax,  0xDEADBEEF
  mov   esp,  kernel_stack + KERNEL_STACK_SIZE
  call  kmain
  cli
.loop:
  jmp   .loop
