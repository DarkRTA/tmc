	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_081249B8:: @ 081249B8
	.incbin "objectB2/gUnk_081249B8.bin"

gUnk_081249C9:: @ 081249C9
	.incbin "objectB2/gUnk_081249C9.bin"

gUnk_081249DA:: @ 081249DA
	.incbin "objectB2/gUnk_081249DA.bin"

gUnk_081249EB:: @ 081249EB
	.incbin "objectB2/gUnk_081249EB.bin"

gSpriteAnimations_ObjectB2:: @ 081249FC
	.4byte gUnk_081249B8
	.4byte gUnk_081249C9
	.4byte gUnk_081249DA
	.4byte gUnk_081249EB
	.4byte 00000000
