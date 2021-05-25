	.global clflush
	.section .text
	
	
clflush:
	clflush (%rdi)
	retq
	
clflush_rdi:
	clflush (%rdi)
	retq
	
clflush_rbp:
	mov     -0x8(%rbp),%rax
	clflush (%rax)
	retq
