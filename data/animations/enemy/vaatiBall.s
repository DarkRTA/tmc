	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_080D1638:: @ 080D1638
	.incbin "vaatiBall/gUnk_080D1638.bin"

gUnk_080D163D:: @ 080D163D
	.incbin "vaatiBall/gUnk_080D163D.bin"

gUnk_080D166E:: @ 080D166E
	.incbin "vaatiBall/gUnk_080D166E.bin"

gSpriteAnimations_VaatiBall:: @ 080D1694
	.4byte gUnk_080D1638
	.4byte gUnk_080D163D
	.4byte gUnk_080D166E
	.4byte 00000000
