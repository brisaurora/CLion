	.file	"main.c"
	.text
	.globl	test
	.def	test;	.scl	2;	.type	32;	.endef
	.seh_proc	test
test:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	addl	$1, 16(%rbp)
	addl	$1, 24(%rbp)
	addl	$1, 32(%rbp)
	addl	$1, 40(%rbp)
	addl	$1, 48(%rbp)
	addl	$1, 56(%rbp)
	addl	$1, 64(%rbp)
	movl	32(%rbp), %edx
	movl	40(%rbp), %eax
	addl	%eax, %edx
	movl	48(%rbp), %eax
	addl	%eax, %edx
	movl	56(%rbp), %eax
	addl	%eax, %edx
	movl	64(%rbp), %eax
	addl	%eax, %edx
	movl	16(%rbp), %eax
	addl	%eax, %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	addl	$1, -4(%rbp)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	test1
	.def	test1;	.scl	2;	.type	32;	.endef
	.seh_proc	test1
test1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	addl	$1, 16(%rbp)
	addl	$1, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	24(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, -8(%rbp)
	movl	16(%rbp), %eax
	imull	24(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	imull	-12(%rbp), %eax
	movl	16(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	addl	$1, -4(%rbp)
	movl	-8(%rbp), %eax
	imull	-12(%rbp), %eax
	movl	-16(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	-4(%rbp), %eax
	addl	%eax, -20(%rbp)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.comm	test2, 8, 3
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d %d %d %d\0"
.LC1:
	.ascii "yes\0"
.LC2:
	.ascii "%lf\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$144, %rsp
	.seh_stackalloc	144
	.seh_endprologue
	call	__main
	movl	$1, -4(%rbp)
	movl	$128, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, -4(%rbp)
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	addl	$1, -12(%rbp)
	movl	$11, 32(%rsp)
	movl	$10, %r9d
	movl	$2147483646, %r8d
	movl	$2147483645, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$7, 48(%rsp)
	movl	$6, 40(%rsp)
	movl	$5, 32(%rsp)
	movl	$4, %r9d
	movl	$3, %r8d
	movl	$2, %edx
	movl	$1, %ecx
	call	test
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	test1
.L4:
	movl	$2, -16(%rbp)
	movl	$3, -16(%rbp)
	cmpl	$0, -16(%rbp)
	jne	.L5
	leaq	.LC1(%rip), %rcx
	call	printf
.L5:
	movl	$268432178, -72(%rbp)
	movl	$-3, -68(%rbp)
	vmovsd	-72(%rbp), %xmm0
	vmovq	%xmm0, %rax
	movq	%rax, %rdx
	vmovq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	vmovsd	.LC3(%rip), %xmm0
	vmovsd	%xmm0, -24(%rbp)
	vmovss	.LC4(%rip), %xmm0
	vmovss	%xmm0, -28(%rbp)
	vcvtsd2ss	-24(%rbp), %xmm2, %xmm2
	vmovss	%xmm2, -28(%rbp)
	vcvtss2sd	-28(%rbp), %xmm0, %xmm0
	vmovsd	%xmm0, -24(%rbp)
	movl	$0, %eax
	addq	$144, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.data
	.align 32
jt.3683:
	.quad	.L4
	.space 48
	.section .rdata,"dr"
	.align 8
.LC3:
	.long	1477468750
	.long	1079960633
	.align 4
.LC4:
	.long	1150874092
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
