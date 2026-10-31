	.intel_syntax noprefix
	.text
	.globl	add
add:
	mov eax, edi
	add eax, esi
	ret

	.globl	sub
sub:
	mov eax, edi
	sub eax, esi
	ret

