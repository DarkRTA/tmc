	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2


gUnk_080CEF7C:: @ 080CEF7C
	.incbin "mazaalHand/gUnk_080CEF7C.bin"

gUnk_080CEF9D:: @ 080CEF9D
	.incbin "mazaalHand/gUnk_080CEF9D.bin"

gUnk_080CEFA5:: @ 080CEFA5
	.incbin "mazaalHand/gUnk_080CEFA5.bin"

gUnk_080CEFAE:: @ 080CEFAE
	.incbin "mazaalHand/gUnk_080CEFAE.bin"

gUnk_080CEFB2:: @ 080CEFB2
	.incbin "mazaalHand/gUnk_080CEFB2.bin"

gUnk_080CEFB6:: @ 080CEFB6
	.incbin "mazaalHand/gUnk_080CEFB6.bin"

gUnk_080CEFCB:: @ 080CEFCB
	.incbin "mazaalHand/gUnk_080CEFCB.bin"

gUnk_080CEFE0:: @ 080CEFE0
	.incbin "mazaalHand/gUnk_080CEFE0.bin"

gUnk_080CEFE9:: @ 080CEFE9
	.incbin "mazaalHand/gUnk_080CEFE9.bin"

gUnk_080CF002:: @ 080CF002
	.incbin "mazaalHand/gUnk_080CF002.bin"

gSpriteAnimations_MazaalHand:: @ 080CF014
	.4byte gUnk_080CEF7C
	.4byte gUnk_080CEF9D
	.4byte gUnk_080CEFA5
	.4byte gUnk_080CEFAE
	.4byte gUnk_080CEFB2
	.4byte gUnk_080CEFB6
	.4byte gUnk_080CEFCB
	.4byte gUnk_080CEFE0
	.4byte gUnk_080CEFE9
	.4byte gUnk_080CF002
	.4byte 00000000
