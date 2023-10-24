	.file	"psc03_code_compilation_stages.c"
	.text
	.globl	dirName
	.data
	.align 16
	.type	dirName, @object
	.size	dirName, 17
dirName:
	.string	"IntermediateFile"
	.text
	.globl	makeDirectory
	.type	makeDirectory, @function
makeDirectory:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$511, %esi
	leaq	dirName(%rip), %rax
	movq	%rax, %rdi
	call	mkdir@PLT
	movl	%eax, -4(%rbp)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	makeDirectory, .-makeDirectory
	.section	.rodata
.LC0:
	.string	"cldir"
.LC1:
	.string	"rm -rf %s"
.LC2:
	.string	"Preprocessing"
	.align 8
.LC3:
	.string	"gcc -E %s -o ./IntermediateFile/%.*si"
.LC4:
	.string	"Compiling"
	.align 8
.LC5:
	.string	"gcc -S %s -o ./IntermediateFile/%.*ss"
.LC6:
	.string	"Assembling"
	.align 8
.LC7:
	.string	"gcc -c %s -o ./IntermediateFile/%.*so"
.LC8:
	.string	"Linking"
	.align 8
.LC9:
	.string	"gcc ./IntermediateFile/%.*so -o ./IntermediateFile/%.*sout"
.LC10:
	.string	"Error"
	.text
	.globl	executeCmd
	.type	executeCmd, @function
executeCmd:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%rdi, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-152(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L4
	leaq	-112(%rbp), %rax
	leaq	dirName(%rip), %rdx
	movq	%rdx, %rcx
	leaq	.LC1(%rip), %rdx
	movl	$100, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	shellExecution
	movl	%eax, -116(%rbp)
	movl	$0, %eax
	jmp	.L10
.L4:
	movq	-152(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L6
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -120(%rbp)
	movl	-120(%rbp), %eax
	leal	-1(%rax), %esi
	movq	-160(%rbp), %rcx
	movq	-160(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rcx, %r9
	movl	%esi, %r8d
	movq	%rdx, %rcx
	leaq	.LC3(%rip), %rdx
	movl	$100, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	shellExecution
	jmp	.L10
.L6:
	movq	-152(%rbp), %rax
	leaq	.LC4(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L7
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -124(%rbp)
	movl	-124(%rbp), %eax
	leal	-1(%rax), %esi
	movq	-160(%rbp), %rcx
	movq	-160(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rcx, %r9
	movl	%esi, %r8d
	movq	%rdx, %rcx
	leaq	.LC5(%rip), %rdx
	movl	$100, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	shellExecution
	jmp	.L10
.L7:
	movq	-152(%rbp), %rax
	leaq	.LC6(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L8
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -128(%rbp)
	movl	-128(%rbp), %eax
	leal	-1(%rax), %esi
	movq	-160(%rbp), %rcx
	movq	-160(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rcx, %r9
	movl	%esi, %r8d
	movq	%rdx, %rcx
	leaq	.LC7(%rip), %rdx
	movl	$100, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	shellExecution
	jmp	.L10
.L8:
	movq	-152(%rbp), %rax
	leaq	.LC8(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L9
	movq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -132(%rbp)
	movl	-132(%rbp), %eax
	leal	-1(%rax), %esi
	movl	-132(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-160(%rbp), %rcx
	leaq	-112(%rbp), %rax
	subq	$8, %rsp
	pushq	-160(%rbp)
	movl	%esi, %r9d
	movq	%rcx, %r8
	movl	%edx, %ecx
	leaq	.LC9(%rip), %rdx
	movl	$100, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	addq	$16, %rsp
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	shellExecution
	jmp	.L10
.L9:
	call	__errno_location@PLT
	movl	$22, (%rax)
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
.L10:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	executeCmd, .-executeCmd
	.section	.rodata
.LC11:
	.string	"fork"
.LC12:
	.string	"/dev/null"
.LC13:
	.string	" "
.LC14:
	.string	"execvp"
.LC15:
	.string	"\nGenerated...\n"
	.align 8
.LC16:
	.string	"\n\ncode_comp: Compilation Failed\nClearing the files and Aborting...\n"
	.text
	.globl	shellExecution
	.type	shellExecution, @function
shellExecution:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp
	movq	%rdi, -136(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -120(%rbp)
	call	fork@PLT
	movl	%eax, -112(%rbp)
	cmpl	$0, -112(%rbp)
	jns	.L13
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	jmp	.L12
.L13:
	cmpl	$0, -112(%rbp)
	jne	.L15
	movl	$2, %edi
	call	close@PLT
	movl	$1, %esi
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movq	-136(%rbp), %rax
	leaq	.LC13(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -104(%rbp)
	movl	$0, -116(%rbp)
	jmp	.L16
.L17:
	movl	-116(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -116(%rbp)
	cltq
	movq	-104(%rbp), %rdx
	movq	%rdx, -96(%rbp,%rax,8)
	leaq	.LC13(%rip), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -104(%rbp)
.L16:
	cmpq	$0, -104(%rbp)
	jne	.L17
	movl	-116(%rbp), %eax
	cltq
	movq	$0, -96(%rbp,%rax,8)
	movq	-96(%rbp), %rax
	leaq	-96(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	execvp@PLT
	movl	%eax, -108(%rbp)
	cmpl	$0, -108(%rbp)
	jns	.L18
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	jmp	.L12
.L18:
	jmp	.L12
.L15:
	leaq	-120(%rbp), %rcx
	movl	-112(%rbp), %eax
	movl	$0, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	waitpid@PLT
	movl	-120(%rbp), %eax
	testl	%eax, %eax
	jne	.L19
	movl	$15, %edx
	leaq	.LC15(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	movl	-120(%rbp), %eax
	jmp	.L12
.L19:
	leaq	dirName(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	executeCmd
	movl	$0, %eax
	call	makeDirectory
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$67, %edx
	movl	$1, %esi
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L12:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L21
	call	__stack_chk_fail@PLT
.L21:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	shellExecution, .-shellExecution
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fileCheck
	movq	-16(%rbp), %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	codeCompilation
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.section	.rodata
.LC17:
	.string	"\nCreating the %s's Directory\n"
	.align 8
.LC18:
	.string	"\nGenerating the Preprocessing %.*si file"
	.align 8
.LC19:
	.string	"\nGenerating the Compiling %.*ss file"
	.align 8
.LC20:
	.string	"\nGenerating the Assembling %.*so file"
	.align 8
.LC21:
	.string	"\nGenerating the Linking %.*sout file"
.LC22:
	.string	"\nExecuting the %.*sout file"
.LC23:
	.string	"./IntermediateFile/%.*sout"
	.text
	.globl	codeCompilation
	.type	codeCompilation, @function
codeCompilation:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movl	%edi, -164(%rbp)
	movq	%rsi, -176(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$7234308714536398409, %rax
	movabsq	$7308332046386225513, %rdx
	movq	%rax, -144(%rbp)
	movq	%rdx, -136(%rbp)
	movb	$0, -128(%rbp)
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	call	makeDirectory
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -148(%rbp)
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	-148(%rbp), %eax
	leal	-1(%rax), %esi
	movq	stderr(%rip), %rax
	movq	%rdx, %rcx
	movl	%esi, %edx
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	executeCmd
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	-148(%rbp), %eax
	leal	-1(%rax), %esi
	movq	stderr(%rip), %rax
	movq	%rdx, %rcx
	movl	%esi, %edx
	leaq	.LC19(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	executeCmd
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	-148(%rbp), %eax
	leal	-1(%rax), %esi
	movq	stderr(%rip), %rax
	movq	%rdx, %rcx
	movl	%esi, %edx
	leaq	.LC20(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	executeCmd
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	-148(%rbp), %eax
	leal	-1(%rax), %esi
	movq	stderr(%rip), %rax
	movq	%rdx, %rcx
	movl	%esi, %edx
	leaq	.LC21(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	executeCmd
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	-148(%rbp), %eax
	leal	-1(%rax), %esi
	movq	stderr(%rip), %rax
	movq	%rdx, %rcx
	movl	%esi, %edx
	leaq	.LC22(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-176(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rcx
	movl	-148(%rbp), %eax
	leal	-1(%rax), %edx
	leaq	-112(%rbp), %rax
	movq	%rcx, %r8
	movl	%edx, %ecx
	leaq	.LC23(%rip), %rdx
	movl	$100, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	shellExecution
	nop
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L25
	call	__stack_chk_fail@PLT
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	codeCompilation, .-codeCompilation
	.section	.rodata
	.align 8
.LC24:
	.string	"Error: file operand missing\nAborting...\n"
.LC25:
	.string	"Error: %s\nAborting...\n"
.LC26:
	.string	".c"
.LC27:
	.string	".C"
.LC28:
	.string	"%s\nAborting...\n"
.LC29:
	.string	"open"
.LC30:
	.string	"Aborting...\n"
	.text
	.globl	fileCheck
	.type	fileCheck, @function
fileCheck:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L27
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$40, %edx
	movl	$1, %esi
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L27:
	cmpl	$2, -20(%rbp)
	jle	.L28
	call	__errno_location@PLT
	movl	$7, (%rax)
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	leaq	.LC25(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$1, %edi
	call	exit@PLT
.L28:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC26(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr@PLT
	testq	%rax, %rax
	jne	.L29
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC27(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr@PLT
	testq	%rax, %rax
	jne	.L29
	call	__errno_location@PLT
	movl	$2, (%rax)
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	leaq	.LC28(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$1, %edi
	call	exit@PLT
.L29:
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L30
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$12, %edx
	movl	$1, %esi
	leaq	.LC30(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$1, %edi
	call	exit@PLT
.L30:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	fileCheck, .-fileCheck
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
