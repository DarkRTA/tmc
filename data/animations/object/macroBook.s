	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08123CB8:: @ 08123CB8
	.incbin "macroBook/gUnk_08123CB8.bin"

gUnk_08123CBD:: @ 08123CBD
	.incbin "macroBook/gUnk_08123CBD.bin"

gUnk_08123CCE:: @ 08123CCE
	.incbin "macroBook/gUnk_08123CCE.bin"

gUnk_08123CEB:: @ 08123CEB
	.incbin "macroBook/gUnk_08123CEB.bin"

gSpriteAnimations_MacroBook:: @ 08123D14
	.4byte gUnk_08123CB8
	.4byte gUnk_08123CBD
	.4byte gUnk_08123CCE
	.4byte gUnk_08123CEB
	.4byte 00000000
