	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08110E9C:: @ 08110E9C
	.incbin "castorWildsStatue/gUnk_08110E9C.bin"

gUnk_08110EA1:: @ 08110EA1
	.incbin "castorWildsStatue/gUnk_08110EA1.bin"

gUnk_08110EA6:: @ 08110EA6
	.incbin "castorWildsStatue/gUnk_08110EA6.bin"

gSpriteAnimations_CastorWildsStatue:: @ 08110EAC
	.4byte gUnk_08110E9C
	.4byte gUnk_08110EA6
	.4byte gUnk_08110E9C
	.4byte gUnk_08110EA6
	.4byte gUnk_08110EA1
	.4byte gUnk_08110EA1
	.4byte gUnk_08110EA1
	.4byte gUnk_08110EA1
	.4byte gUnk_08110E9C
	.4byte gUnk_08110EA6
	.4byte gUnk_08110E9C
	.4byte gUnk_08110EA6
	.4byte gUnk_08110EA1
	.4byte gUnk_08110EA1
	.4byte gUnk_08110EA1
	.4byte gUnk_08110EA1
	.4byte 00000000
