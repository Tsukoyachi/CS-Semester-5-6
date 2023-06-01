%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	0
	pop	eax		 ; depile la permière operande dans eax
	xor	eax, 1		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	pop	eax		 ; depile la permière operande dans eax
	xor	eax, 1		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	0
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	or	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	eax		 ; depile la permière operande dans eax
	xor	eax, 1		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0
	pop	eax		 ; depile la permière operande dans eax
	xor	eax, 1		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	1
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
