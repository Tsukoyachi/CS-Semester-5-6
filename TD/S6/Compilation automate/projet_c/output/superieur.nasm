%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jg	e0		 ; Jump si supérieur
	push	0		 ; Push Faux si inférieur ou égal
	jmp	e1		 ; Va a la suite du code
e0 :	push	1		 ; Push Vrai si supérieur
e1 :	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	jg	e2		 ; Jump si supérieur
	push	0		 ; Push Faux si inférieur ou égal
	jmp	e3		 ; Va a la suite du code
e2 :	push	1		 ; Push Vrai si supérieur
e3 :	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
