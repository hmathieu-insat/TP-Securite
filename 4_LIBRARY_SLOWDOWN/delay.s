	.global delay
	.section .text
	
	
delay:
	rdtscp
	shl $0x20,%rdx
	mov %eax,%esi
	mov %edi,%edi
	or  %rdx,%rsi
delayloop:
	rdtscp
	shl $0x20,%rdx
	mov %eax,%eax
	or  %rax,%rdx
	sub %rsi,%rdx
	cmp %rdi,%rdx
	jb  delayloop
	retq
