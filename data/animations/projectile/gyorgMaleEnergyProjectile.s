	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_0812A9FC:: @ 0812A9FC
	.incbin "projectile23/gUnk_0812A9FC.bin"

gUnk_0812AA31:: @ 0812AA31
	.incbin "projectile23/gUnk_0812AA31.bin"

gSpriteAnimations_GyorgMaleEnergyProjectile:: @ 0812AA50
	.4byte gUnk_0812A9FC
	.4byte gUnk_0812AA31
	.4byte 00000000
