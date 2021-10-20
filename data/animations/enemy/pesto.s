	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnk_080CBF30:: @ 080CBF30
	.incbin "pesto/gUnk_080CBF30.bin"

gUnk_080CBF39:: @ 080CBF39
	.incbin "pesto/gUnk_080CBF39.bin"

gUnk_080CBF42:: @ 080CBF42
	.incbin "pesto/gUnk_080CBF42.bin"

gUnk_080CBF4B:: @ 080CBF4B
	.incbin "pesto/gUnk_080CBF4B.bin"

gUnk_080CBF54:: @ 080CBF54
	.incbin "pesto/gUnk_080CBF54.bin"

gUnk_080CBF5D:: @ 080CBF5D
	.incbin "pesto/gUnk_080CBF5D.bin"

gUnk_080CBF66:: @ 080CBF66
	.incbin "pesto/gUnk_080CBF66.bin"

gUnk_080CBF6F:: @ 080CBF6F
	.incbin "pesto/gUnk_080CBF6F.bin"

gSpriteAnimations_Pesto:: @ 080CBF78
	.4byte gUnk_080CBF30
	.4byte gUnk_080CBF39
	.4byte gUnk_080CBF42
	.4byte gUnk_080CBF4B
	.4byte gUnk_080CBF54
	.4byte gUnk_080CBF5D
	.4byte gUnk_080CBF66
	.4byte gUnk_080CBF6F
	.4byte 00000000
