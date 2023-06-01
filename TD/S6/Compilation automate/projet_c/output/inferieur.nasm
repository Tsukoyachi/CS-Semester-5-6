%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	1
	push	0
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jge	e0		 ; Jump si supérieur ou égal
	push	1		 ; Push Vrai si inférieur
	jmp	e1		 ; Va a la suite du code
e0 :	push	0		 ; Push Faux si supérieur ou égal
e1 :	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jge	e2		 ; Jump si supérieur ou égal
	push	1		 ; Push Vrai si inférieur
	jmp	e3		 ; Va a la suite du code
e2 :	push	0		 ; Push Faux si supérieur ou égal
e3 :	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
