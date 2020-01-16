	.file	"cpfile_rfifo.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"tp"
.LC1:
	.string	"open_tp"
.LC2:
	.string	"file.bak"
.LC3:
	.string	"open_file_bak"
	.text
	.globl	_Z15rdfifo_wrTofilev
	.type	_Z15rdfifo_wrTofilev, @function
_Z15rdfifo_wrTofilev:
.LFB1021:
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
	movl	$0, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -1052(%rbp)
	cmpl	$-1, -1052(%rbp)
	jne	.L2
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L2:
	movl	$420, %edx
	movl	$577, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -1048(%rbp)
	cmpl	$-1, -1048(%rbp)
	jne	.L3
	movl	$.LC3, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	leaq	-1040(%rbp), %rdx
	movl	$0, %eax
	movl	$128, %ecx
	movq	%rdx, %rdi
	rep stosq
.L5:
	leaq	-1040(%rbp), %rcx
	movl	-1052(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -1044(%rbp)
	cmpl	$0, -1044(%rbp)
	setg	%al
	testb	%al, %al
	je	.L4
	movl	-1044(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1040(%rbp), %rcx
	movl	-1048(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	jmp	.L5
.L4:
	movl	-1052(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	-1048(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$.LC0, %edi
	call	unlink
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L6
	call	__stack_chk_fail
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1021:
	.size	_Z15rdfifo_wrTofilev, .-_Z15rdfifo_wrTofilev
	.globl	main
	.type	main, @function
main:
.LFB1022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	_Z15rdfifo_wrTofilev
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1023:
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
	jne	.L11
	cmpl	$65535, -8(%rbp)
	jne	.L11
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L11:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1023:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z15rdfifo_wrTofilev, @function
_GLOBAL__sub_I__Z15rdfifo_wrTofilev:
.LFB1024:
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
.LFE1024:
	.size	_GLOBAL__sub_I__Z15rdfifo_wrTofilev, .-_GLOBAL__sub_I__Z15rdfifo_wrTofilev
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z15rdfifo_wrTofilev
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
