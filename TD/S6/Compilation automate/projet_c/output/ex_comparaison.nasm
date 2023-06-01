%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	6
	push	1
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	je	e0		 ; Jump si égaux
	push	1		 ; Push Vrai si différents
	jmp	e1		 ; Va a la suite du code
e0 :	push	0		 ; Push Faux si égaux
e1 :	pop	eax
	call	iprintLF
	push	7
	push	4
	push	3
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx		 ; Compare les opérandes
	je	e2		 ; Jump si égaux
	push	0		 ; Push Faux si différents
	jmp	e3		 ; Va a la suite du code
e2 :	push	1		 ; Push Vrai si égaux
e3 :	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
