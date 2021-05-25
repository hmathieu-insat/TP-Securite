	.global memaccesstime
	.section .text
	
	
memaccesstime:
	mfence
	lfence
	rdtscp
	mov %eax, %esi
	mov (%rdi),%eax
	rdtscp
	sub %esi,%eax
	retq
