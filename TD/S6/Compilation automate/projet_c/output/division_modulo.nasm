%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	1
	push	3
	push	3
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cdq		 ; initialise edx à 0 si eax est > 0 et à -1 sinon
	idiv	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	4
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	5
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	mov	edx, 0		 ; prepare edx pour la division
	idiv	ebx		 ; effectue l'opération
	mov	eax, edx		 ; prepare edx pour la division
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
