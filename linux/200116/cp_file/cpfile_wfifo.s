	.file	"cpfile_wfifo.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"tp"
	.text
	.globl	_Z7mk_fifov
	.type	_Z7mk_fifov, @function
_Z7mk_fifov:
.LFB1021:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$420, %esi
	movl	$.LC0, %edi
	call	mkfifo
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1021:
	.size	_Z7mk_fifov, .-_Z7mk_fifov
	.section	.rodata
.LC1:
	.string	"file"
.LC2:
	.string	"open_file"
.LC3:
	.string	"open_tp"
	.text
	.globl	_Z15rdfile_wrTofifov
	.type	_Z15rdfile_wrTofifov, @function
_Z15rdfile_wrTofifov:
.LFB1022:
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
	movl	$.LC1, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -1052(%rbp)
	cmpl	$-1, -1052(%rbp)
	jne	.L3
	movl	$.LC2, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movl	$1, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	open
	movl	%eax, -1048(%rbp)
	cmpl	$-1, -1048(%rbp)
	jne	.L4
	movl	$.LC3, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L4:
	leaq	-1040(%rbp), %rdx
	movl	$0, %eax
	movl	$128, %ecx
	movq	%rdx, %rdi
	rep stosq
.L6:
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
	je	.L5
	movl	-1044(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1040(%rbp), %rcx
	movl	-1048(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	jmp	.L6
.L5:
	movl	-1052(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	-1048(%rbp), %eax
	movl	%eax, %edi
	call	close
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	_Z15rdfile_wrTofifov, .-_Z15rdfile_wrTofifov
	.globl	main
	.type	main, @function
main:
.LFB1023:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	_Z7mk_fifov
	call	_Z15rdfile_wrTofifov
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1023:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1024:
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
	jne	.L12
	cmpl	$65535, -8(%rbp)
	jne	.L12
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L12:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1024:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z7mk_fifov, @function
_GLOBAL__sub_I__Z7mk_fifov:
.LFB1025:
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
.LFE1025:
	.size	_GLOBAL__sub_I__Z7mk_fifov, .-_GLOBAL__sub_I__Z7mk_fifov
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z7mk_fifov
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
