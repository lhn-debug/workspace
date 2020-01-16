	.file	"clientPipe.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"mypipe"
.LC1:
	.string	"open_wfd"
.LC2:
	.string	"Enter#"
.LC3:
	.string	"read_wfd"
	.text
	.globl	_Z10clientPipev
	.type	_Z10clientPipev, @function
_Z10clientPipev:
.LFB1026:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1056, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -1052(%rbp)
	cmpl	$0, -1052(%rbp)
	jns	.L2
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L2:
	leaq	-1040(%rbp), %rdx
	movl	$0, %eax
	movl	$128, %ecx
	movq	%rdx, %rdi
	rep stosq
.L4:
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	leaq	-1040(%rbp), %rax
	movl	$1024, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read
	movq	%rax, -1048(%rbp)
	cmpq	$0, -1048(%rbp)
	jne	.L3
	movl	$.LC3, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	leaq	-1040(%rbp), %rdx
	movq	-1048(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	leaq	-1040(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, %rdx
	leaq	-1040(%rbp), %rcx
	movl	-1052(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	jmp	.L4
	.cfi_endproc
.LFE1026:
	.size	_Z10clientPipev, .-_Z10clientPipev
	.globl	main
	.type	main, @function
main:
.LFB1027:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	_Z10clientPipev
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1027:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1031:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L10
	cmpl	$65535, -8(%rbp)
	jne	.L10
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L10:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1031:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z10clientPipev, @function
_GLOBAL__sub_I__Z10clientPipev:
.LFB1032:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1032:
	.size	_GLOBAL__sub_I__Z10clientPipev, .-_GLOBAL__sub_I__Z10clientPipev
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z10clientPipev
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
