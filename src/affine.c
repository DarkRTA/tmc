#include "global.h"
#include "structures.h"
#include "main.h"
#include "room.h"
#include "screen.h"

extern u32 gFrameObjLists[];

extern void ram_sub_080B23F0(void);
extern void ram_sub_080B2828(OAMCommand*, void*);
extern void ram_sub_080B280C(OAMCommand*, u32, u32);

// regalloc
NONMATCH("asm/non_matching/vram/sub_080AD8F0.inc", void* sub_080AD8F0(u32 sprite, u32 frame)) {
    u32 x = gFrameObjLists[sprite];
    u8* y = (u8*)&gFrameObjLists[frame];
    u32 tmp = *(u32*)&y[x];

    return (u8*)gFrameObjLists + tmp;
}
END_NONMATCH

void FlushSprites(void) {
    gOAMControls.updated = 0;
}

void CopyOAM(void) {
    u16* d;
    s32 rem;

    if (gMain.pad == 0) {
        gOAMControls.unk[0x20].unk0 = 0;
        gOAMControls.unk[0x48].unk4 = 0;
        gOAMControls.unk[0x71].unk0 = 0;
        gOAMControls.unk[0x99].unk4 = 0;
    } else {
        gMain.pad--;
    }

    rem = 0x80 - gOAMControls.updated;
    if (rem > 0) {
        d = (u16*)&gOAMControls.oam[gOAMControls.updated];
        for (; rem != 0; rem--) {
            *d = 0x2A0;
            (u8*)d += 8;
        }
    }
    if (gOAMControls.unk[0].unk7) {
        gOAMControls.unk[0].unk7 = 0;
        ObjAffineSet((struct ObjAffineSrcData*)gOAMControls.unk, &gOAMControls.oam[0].affineParam, 32, 8);
    }
    gOAMControls.field_0x0 = 1;
}

void DrawEntities(void) {
    void (*fn)(void);

    gOAMControls._0[6] = gRoomTransition.field_0x2c[3] ? 15 : 0;
    gOAMControls._4 = gRoomControls.aff_x + gRoomControls.scroll_x;
    gOAMControls._6 = gRoomControls.aff_y + gRoomControls.scroll_y;
    gOAMControls.field_0x1++;
    fn = &ram_sub_080B23F0;
    fn();
}

void sub_080ADA04(OAMCommand* cmd, void* dst) {
    void (*fn)(OAMCommand*, void*) = ram_sub_080B2828;
    fn(cmd, dst);
}

void DrawDirect(u32 a1, u32 a2) {
    void (*fn)(OAMCommand*, u32, u32) = ram_sub_080B280C;
    fn(&gOamCmd, a1, a2);
}
