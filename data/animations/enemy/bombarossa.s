	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_080CEB60:: @ 080CEB60
	.incbin "bombarossa/gUnk_080CEB60.bin"

gSpriteAnimations_Bombarossa:: @ 080CEB6C
	.4byte gUnk_080CEB60
	.4byte 00000000
