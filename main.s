	.file	"main.c"
	.section	.rodata
.LC5:
	.string	"%d %1f %d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -80(%rbp)
	movl	$3, -76(%rbp)
	movl	$5, -72(%rbp)
	movl	$7, -68(%rbp)
	movl	$9, -64(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -40(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, -96(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-96(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-96(%rbp), %rax
	movl	%edx, (%rax)
	movq	-88(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rsi
	movq	-96(%rbp), %rax
	movl	(%rax), %eax
	movq	-88(%rbp), %rcx
	movq	-96(%rbp), %rdx
	movq	%rsi, -104(%rbp)
	movsd	-104(%rbp), %xmm0
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	2576980378
	.long	1072798105
	.align 8
.LC1:
	.long	2576980378
	.long	1074370969
	.align 8
.LC2:
	.long	858993459
	.long	1075131187
	.align 8
.LC3:
	.long	2576980378
	.long	1075681689
	.align 8
.LC4:
	.long	0
	.long	1076035584
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
