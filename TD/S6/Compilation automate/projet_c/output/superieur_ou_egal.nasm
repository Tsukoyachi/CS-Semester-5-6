%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	1
	push	15
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jge	e0		 ; Jump si supérieur ou égaul
	push	0		 ; Push Faux si incorrect
	jmp	e1		 ; Va a la suite du code
e0 :	push	1		 ; Push Vrai si supérieur ou égal
e1 :	pop	eax
	call	iprintLF
	push	15
	push	15
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jge	e2		 ; Jump si supérieur ou égaul
	push	0		 ; Push Faux si incorrect
	jmp	e3		 ; Va a la suite du code
e2 :	push	1		 ; Push Vrai si supérieur ou égal
e3 :	pop	eax
	call	iprintLF
	push	15
	push	1
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jge	e4		 ; Jump si supérieur ou égaul
	push	0		 ; Push Faux si incorrect
	jmp	e5		 ; Va a la suite du code
e4 :	push	1		 ; Push Vrai si supérieur ou égal
e5 :	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
