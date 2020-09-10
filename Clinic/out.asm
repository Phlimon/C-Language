	.file	"5.c"
	.comm	_New_Patient, 108, 5
	.comm	_New, 4, 2
	.comm	_Last, 4, 2
	.comm	_Mode, 1, 0
	.globl	_Flag_2
	.bss
_Flag_2:
	.space 1
	.globl	_ListLength
	.align 2
_ListLength:
	.space 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "cls\0"
	.align 4
LC1:
	.ascii "\12\11\11\11\11\11\11\11**********Welcome to Our Clinic**********\0"
	.align 4
LC2:
	.ascii "\12\11\11\11\11\11\11\11*****************************************\12\0"
	.align 4
LC3:
	.ascii "\12\11\11\11\11\11\11\11\11You are on Admin Mode\0"
	.align 4
LC4:
	.ascii "\12\12Please, Enter Your Password: \0"
	.align 4
LC5:
	.ascii "\12\11\11\11\11\11\11\11\11  ******Thank you******\0"
	.align 4
LC6:
	.ascii "\12\11\11\11\11\11\11\11 ****************************************\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_system
	movb	$0, 31(%esp)
	jmp	L2
L9:
	call	_Clinic_voidModes
	movzbl	_Mode, %eax
	movzbl	%al, %eax
	cmpl	$2, %eax
	je	L4
	cmpl	$3, %eax
	je	L5
	cmpl	$1, %eax
	jne	L10
	movl	$LC0, (%esp)
	call	_system
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_puts
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_printf
	call	_Clinic_u8AdminModePassword
	movb	%al, 30(%esp)
	cmpb	$1, 30(%esp)
	jne	L7
	call	_Clinic_VoidAdminFunctions
	jmp	L2
L7:
	movb	$1, 31(%esp)
	jmp	L2
L4:
	call	_PrintLinkedList
	jmp	L2
L5:
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC6, (%esp)
	call	_printf
	movb	$1, 31(%esp)
	jmp	L2
L10:
	movzbl	_Flag_2, %eax
	addl	$1, %eax
	movb	%al, _Flag_2
	movl	$LC0, (%esp)
	call	_system
	nop
L2:
	cmpb	$0, 31(%esp)
	je	L9
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
	.section .rdata,"dr"
	.align 4
LC7:
	.ascii "Invailed Choice Please, Try again with right Choice\0"
	.align 4
LC8:
	.ascii "\12Please, Enter the Number of the next Features: \0"
	.align 4
LC9:
	.ascii "\12[1]Admin Mode\12[2]User Mode\12[3]Exit the System\0"
LC10:
	.ascii "\12Your Choice is: \0"
LC11:
	.ascii "%d\0"
	.text
	.globl	_Clinic_voidModes
	.def	_Clinic_voidModes;	.scl	2;	.type	32;	.endef
_Clinic_voidModes:
LFB7:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC0, (%esp)
	call	_system
	nop
	movzbl	_Flag_2, %eax
	testb	%al, %al
	je	L13
	movl	$LC0, (%esp)
	call	_system
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_puts
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC10, (%esp)
	call	_printf
	movl	$_Mode, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	nop
L13:
	nop
	movzbl	_Flag_2, %eax
	testb	%al, %al
	jne	L11
	movl	$LC0, (%esp)
	call	_system
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_puts
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC10, (%esp)
	call	_printf
	movl	$_Mode, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	nop
L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7:
	.section .rdata,"dr"
	.align 4
LC12:
	.ascii "\12\12\11\11\11\11\11\11\11You have Entered the Password 3 Times Wrong\0"
LC13:
	.ascii "\12\11\11\11\11\11\11\11\11\11****BYE BYE****\0"
	.align 4
LC14:
	.ascii "\12****Invalid Password****\12\12Please, Re-Enter the right Password: \0"
	.text
	.globl	_Clinic_u8AdminModePassword
	.def	_Clinic_u8AdminModePassword;	.scl	2;	.type	32;	.endef
_Clinic_u8AdminModePassword:
LFB8:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, _i.2230
	jmp	L19
L24:
	movzwl	-10(%ebp), %eax
	cmpw	$1234, %ax
	jne	L20
	movb	$1, _Password.2231
	jmp	L21
L20:
	leal	-10(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movzwl	-10(%ebp), %eax
	cmpw	$1234, %ax
	jne	L22
	movb	$1, _Password.2231
	jmp	L21
L22:
	movzbl	_i.2230, %eax
	cmpb	$2, %al
	jne	L23
	movl	$LC12, (%esp)
	call	_printf
	movl	$LC13, (%esp)
	call	_printf
	movb	$0, _Password.2231
	jmp	L21
L23:
	movl	$LC14, (%esp)
	call	_printf
	movzbl	_i.2230, %eax
	addl	$1, %eax
	movb	%al, _i.2230
L19:
	movzbl	_i.2230, %eax
	cmpb	$2, %al
	jbe	L24
L21:
	movzbl	_Password.2231, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8:
	.section .rdata,"dr"
	.align 4
LC15:
	.ascii "\12Please, Choose one of this Features:- \0"
LC16:
	.ascii "\12[1]Add New Patient Record\0"
LC17:
	.ascii "[2]Edit Patient Record\0"
	.align 4
LC18:
	.ascii "[3]Reserve a Slot with the Doctor\0"
LC19:
	.ascii "[4]Cancel Reservation\0"
	.align 4
LC20:
	.ascii "Exit Admin Mode Press any number else\0"
	.align 4
LC21:
	.ascii "\12\12Please, Enter the number of the Feature: \0"
	.text
	.globl	_Clinic_VoidAdminFunctions
	.def	_Clinic_VoidAdminFunctions;	.scl	2;	.type	32;	.endef
_Clinic_VoidAdminFunctions:
LFB9:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC0, (%esp)
	call	_system
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_puts
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC15, (%esp)
	call	_puts
	movl	$LC16, (%esp)
	call	_puts
	movl	$LC17, (%esp)
	call	_puts
	movl	$LC18, (%esp)
	call	_puts
	movl	$LC19, (%esp)
	call	_puts
	movl	$LC20, (%esp)
	call	_printf
	movl	$LC21, (%esp)
	call	_printf
	leal	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movzbl	-9(%ebp), %eax
	movzbl	%al, %eax
	cmpl	$5, %eax
	ja	L26
	movl	L29(,%eax,4), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L29:
	.long	L26
	.long	L28
	.long	L26
	.long	L26
	.long	L26
	.long	L33
	.text
L28:
	call	_Clinic_voidAddNewPatient
	jmp	L26
L33:
	call	_Clinic_voidModes
	nop
L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE9:
	.section .rdata,"dr"
LC22:
	.ascii "\12Please, Enter Your ID: \0"
LC23:
	.ascii "Please, Enter Your Name: \0"
LC24:
	.ascii "%s\0"
LC25:
	.ascii "Please, Enter the your Age: \0"
	.align 4
LC26:
	.ascii "Please, Enter Your Gender: [1]Male\11\11[2]Female\0"
LC27:
	.ascii "Gender is: \0"
	.align 4
LC28:
	.ascii "\12You to Choose between : [1]Male\11\11[2]Female\0"
LC29:
	.ascii "ID Is NOT Repeated\0"
	.align 4
LC30:
	.ascii "ID Is Repeated Please try another ID: \0"
	.align 4
LC31:
	.ascii "\12Do you want to add another new patient ?\12[1]yes          [2]No\0"
LC32:
	.ascii "-------------------\0"
LC33:
	.ascii "{You must choose [1] OR [2]}\0"
	.text
	.globl	_Clinic_voidAddNewPatient
	.def	_Clinic_voidAddNewPatient;	.scl	2;	.type	32;	.endef
_Clinic_voidAddNewPatient:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, -11(%ebp)
	movb	$0, -9(%ebp)
	movl	$LC0, (%esp)
	call	_system
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_puts
	movl	$LC3, (%esp)
	call	_printf
	movzwl	_ListLength, %eax
	testw	%ax, %ax
	jne	L35
	movl	$LC22, (%esp)
	call	_printf
	movl	$_New_Patient+100, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	$LC23, (%esp)
	call	_printf
	movl	$_New_Patient, 4(%esp)
	movl	$LC24, (%esp)
	call	_scanf
	movl	$LC25, (%esp)
	call	_printf
	movl	$_New_Patient+102, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
L37:
	movl	$LC26, (%esp)
	call	_puts
	movl	$LC27, (%esp)
	call	_printf
	movl	$_New_Patient+103, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movzbl	_New_Patient+103, %eax
	cmpb	$1, %al
	je	L36
	movzbl	_New_Patient+103, %eax
	cmpb	$2, %al
	je	L36
	movl	$LC28, (%esp)
	call	_puts
	jmp	L37
L36:
	movzwl	_ListLength, %eax
	addl	$1, %eax
	movw	%ax, _ListLength
	jmp	L48
L35:
	movb	$0, -11(%ebp)
	movl	$108, (%esp)
	call	_malloc
	movl	%eax, _New
	movl	$LC22, (%esp)
	call	_printf
	movb	$0, -10(%ebp)
	jmp	L39
L43:
	leal	-14(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movzwl	-14(%ebp), %eax
	movzwl	%ax, %eax
	movl	%eax, (%esp)
	call	_Clinic_u8IDChecking
	movb	%al, -12(%ebp)
	cmpb	$1, -12(%ebp)
	jne	L40
	movl	$LC29, (%esp)
	call	_puts
	movl	_New, %eax
	movzwl	-14(%ebp), %edx
	movw	%dx, 100(%eax)
	jmp	L41
L40:
	cmpb	$0, -12(%ebp)
	jne	L42
	movl	$LC30, (%esp)
	call	_printf
L42:
	movzbl	-10(%ebp), %eax
	addl	$1, %eax
	movb	%al, -10(%ebp)
L39:
	cmpb	$2, -10(%ebp)
	jbe	L43
L41:
	movl	$LC23, (%esp)
	call	_printf
	movl	_New, %eax
	movl	%eax, 4(%esp)
	movl	$LC24, (%esp)
	call	_scanf
	movl	$LC25, (%esp)
	call	_printf
	movl	_New, %eax
	addl	$102, %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
L45:
	movl	$LC26, (%esp)
	call	_puts
	movl	$LC27, (%esp)
	call	_printf
	movl	_New, %eax
	addl	$103, %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	_New, %eax
	movzbl	103(%eax), %eax
	cmpb	$1, %al
	je	L44
	movl	_New, %eax
	movzbl	103(%eax), %eax
	cmpb	$2, %al
	je	L44
	movl	$LC28, (%esp)
	call	_puts
	jmp	L45
L44:
	movl	_New, %eax
	movl	$0, 104(%eax)
	movl	$_New_Patient, _Last
	jmp	L46
L47:
	movl	_Last, %eax
	movl	104(%eax), %eax
	movl	%eax, _Last
L46:
	movl	_Last, %eax
	movl	104(%eax), %eax
	testl	%eax, %eax
	jne	L47
	movl	_Last, %eax
	movl	_New, %edx
	movl	%edx, 104(%eax)
	movzwl	_ListLength, %eax
	addl	$1, %eax
	movw	%ax, _ListLength
	movb	$0, -11(%ebp)
	jmp	L48
L52:
	movl	$LC31, (%esp)
	call	_puts
	leal	-15(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movzbl	-15(%ebp), %eax
	cmpb	$1, %al
	jne	L49
	movl	$LC32, (%esp)
	call	_puts
	call	_Clinic_voidAddNewPatient
	jmp	L50
L49:
	movzbl	-15(%ebp), %eax
	cmpb	$2, %al
	jne	L51
	movb	$1, -9(%ebp)
	jmp	L48
L51:
	movl	$LC33, (%esp)
	call	_puts
L48:
	cmpb	$1, -9(%ebp)
	jne	L52
L50:
	movb	$0, -9(%ebp)
	call	_Clinic_VoidAdminFunctions
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
LC34:
	.ascii "\12-------------------------\0"
LC35:
	.ascii "User Name %d = %s\12\0"
LC36:
	.ascii "User Number %d = %d\12\0"
LC37:
	.ascii "User Number %d = %d\12\12\0"
LC38:
	.ascii "Node Number %d = %d\12\0"
LC39:
	.ascii "Node Number %d = %d\12\12\0"
LC40:
	.ascii "-------------------------\0"
	.text
	.globl	_PrintLinkedList
	.def	_PrintLinkedList;	.scl	2;	.type	32;	.endef
_PrintLinkedList:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC34, (%esp)
	call	_puts
	movzwl	_ListLength, %eax
	testw	%ax, %ax
	je	L53
	movl	$_New_Patient, _Last
	movw	$1, -10(%ebp)
	movl	_Last, %eax
	movl	%eax, %edx
	movzwl	-10(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC35, (%esp)
	call	_printf
	movl	_Last, %eax
	movzwl	100(%eax), %eax
	movzwl	%ax, %edx
	movzwl	-10(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	_printf
	movl	_Last, %eax
	movzbl	102(%eax), %eax
	movzbl	%al, %edx
	movzwl	-10(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC37, (%esp)
	call	_printf
	jmp	L55
L56:
	movl	_Last, %eax
	movl	104(%eax), %eax
	movl	%eax, _Last
	movl	_Last, %eax
	movzwl	-10(%ebp), %edx
	addl	$1, %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC35, (%esp)
	call	_printf
	movl	_Last, %eax
	movzwl	100(%eax), %eax
	movzwl	%ax, %eax
	movzwl	-10(%ebp), %edx
	addl	$1, %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC38, (%esp)
	call	_printf
	movl	_Last, %eax
	movzbl	102(%eax), %eax
	movzbl	%al, %eax
	movzwl	-10(%ebp), %edx
	addl	$1, %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC39, (%esp)
	call	_printf
	movzwl	-10(%ebp), %eax
	addl	$1, %eax
	movw	%ax, -10(%ebp)
L55:
	movl	_Last, %eax
	movl	104(%eax), %eax
	testl	%eax, %eax
	jne	L56
	movl	$LC40, (%esp)
	call	_puts
L53:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_Clinic_u8IDChecking
	.def	_Clinic_u8IDChecking;	.scl	2;	.type	32;	.endef
_Clinic_u8IDChecking:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	8(%ebp), %eax
	movw	%ax, -20(%ebp)
	movb	$1, -1(%ebp)
	movzwl	_ListLength, %eax
	testw	%ax, %ax
	je	L58
	movl	$_New_Patient, _Last
	movl	_Last, %eax
	movzwl	100(%eax), %eax
	cmpw	-20(%ebp), %ax
	jne	L59
	movb	$0, -1(%ebp)
	movzbl	-1(%ebp), %eax
	jmp	L60
L59:
	jmp	L61
L62:
	movl	_Last, %eax
	movl	104(%eax), %eax
	movl	%eax, _Last
	movl	_Last, %eax
	movzwl	100(%eax), %eax
	cmpw	-20(%ebp), %ax
	jne	L61
	movb	$0, -1(%ebp)
	jmp	L58
L61:
	movl	_Last, %eax
	movl	104(%eax), %eax
	testl	%eax, %eax
	jne	L62
L58:
	movzbl	-1(%ebp), %eax
L60:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
.lcomm _Input.2210,2,2
.lcomm _Flag_1.2207,1,1
.lcomm _i.2230,1,1
.lcomm _Password.2231,1,1
	.ident	"GCC: (GNU) 4.8.1"
	.def	_system;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
