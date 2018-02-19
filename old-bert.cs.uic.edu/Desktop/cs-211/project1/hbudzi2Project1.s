	.file	"hbudzi2Project1.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"\n*** inside arrayCopy() function***"
	.text
	.globl	arrayCopy
	.type	arrayCopy, @function
arrayCopy:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	arrayCopy, .-arrayCopy
	.section	.rodata
	.align 8
.LC1:
	.string	"\n*** inside myFavorateSort() function***"
	.text
	.globl	myFavorateSort
	.type	myFavorateSort, @function
myFavorateSort:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC1, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	myFavorateSort, .-myFavorateSort
	.section	.rodata
	.align 8
.LC2:
	.string	"\n*** inside linearSearch() functiont*** "
	.text
	.globl	linSearch
	.type	linSearch, @function
linSearch:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC2, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	linSearch, .-linSearch
	.section	.rodata
	.align 8
.LC3:
	.string	"\n*** inside binarySearch() functiont*** "
	.text
	.globl	binSearch
	.type	binSearch, @function
binSearch:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC3, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	binSearch, .-binSearch
	.section	.rodata
	.align 8
.LC4:
	.string	"Enter in a list of numbers followed by the terminal value of -999"
.LC5:
	.string	"%d"
.LC6:
	.string	" %d"
.LC7:
	.string	"\narraySize: %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$100, -28(%rbp)
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$.LC4, %edi
	call	puts
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-32(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L6
.L9:
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L7
.L8:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-16(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -24(%rbp)
.L7:
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L8
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -28(%rbp)
.L6:
	movl	-32(%rbp), %eax
	cmpl	$-999, %eax
	jne	.L9
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$10, %edi
	call	putchar
	movl	$0, -20(%rbp)
	jmp	.L10
.L11:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -20(%rbp)
.L10:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	-20(%rbp), %eax
	jg	.L11
	movl	$0, %eax
	call	arrayCopy
	movl	$0, %eax
	call	myFavorateSort
	movl	$0, %eax
	call	linSearch
	movl	$0, %eax
	call	binSearch
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-2ubuntu4) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
