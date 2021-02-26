#include "global.h"
#include "gba/eeprom.h"

typedef struct EEPROMConfig {
    u32 unk_00;
    u16 size;
    u16 waitcnt;
    u8 address_width;
    // u8 filler[3];
} EEPROMConfig;
const char EEPROM_V124[] = "EEPROM_V124";
extern const EEPROMConfig* gEEPROMConfig;
const EEPROMConfig gEEPROMConfig512 = { 0x200, 0x40, 0x300, 0x6 };
const EEPROMConfig gEEPROMConfig8k = { 0x2000, 0x400, 0x300, 0xe };

u16 EEPROMWrite(u16, u16*, u8);

u32 EEPROMConfigure(u16 unk_1) {
    u32 ret;

    ret = 0;
    if (unk_1 == 4) {
        gEEPROMConfig = &gEEPROMConfig512;
    } else {
        if (unk_1 == 0x40) {
            gEEPROMConfig = &gEEPROMConfig8k;
        } else {
            gEEPROMConfig = &gEEPROMConfig512;
            ret = 1;
        }
    }
    return ret;
}

static void DMA3Transfer(void* src, void* dest, u16 count) {
    u32 temp;

    u16 IME_save;

    IME_save = REG_IME;
    REG_IME = 0; // disable all interrupts
    temp = REG_WAITCNT & 0xf8ff;
    temp |= gEEPROMConfig->waitcnt; // configure wait state 2
    REG_WAITCNT = temp;
    REG_DMA3SAD = (u32)src;
    REG_DMA3DAD = (u32)dest;
    REG_DMA3CNT = count | 0x80000000;        // enable dma
    while ((REG_DMA3CNT_H & 0x8000) != 0) {} // wait for dma to finish
    REG_IME = IME_save;
}

/**
 * reads 64 bit (8 byte) from eeprom
 *
 * @param address 6/14 bit depending on eeprom size
 * @param data u16[4]
 * @return errorcode, 0 on success
 */
u32 EEPROMRead(u16 address, u16* data) {
    u16 buffer[0x44];

    u16* ptr;
    u8 t1, t2;
    u16 value;

    if (address >= gEEPROMConfig->size) {
        return EEPROM_OUT_OF_RANGE;
    } else {
        ptr = buffer;
        // setup address
        (u8*)ptr += (gEEPROMConfig->address_width << 1) + 1;
        ((u8*)ptr)++;
        for (t1 = 0; t1 < gEEPROMConfig->address_width; t1++) {
            *(ptr--) = address;
            address >>= 1;
        }
        // read request
        *(ptr--) = 1;
        *ptr = 1;
        // send address to eeprom
        DMA3Transfer(buffer, (u16*)0xd000000, gEEPROMConfig->address_width + 3);
        // recieve data
        DMA3Transfer((u16*)0xd000000, buffer, 0x44);
        // 4 bit junk
        ptr = buffer + 4;
        data += 3;
        // copy data into output buffer
        for (t1 = 0; t1 < 4; t1++) {
            value = 0;
            for (t2 = 0; t2 < 0x10; t2++) {
                value <<= 1;
                value |= (*ptr++) & 1;
            }
            *(data--) = value;
        }
        return 0;
    }
}

u16 EEPROMWrite1(u16 address, u16* data) {
    return EEPROMWrite(address, data, 1);
}

// this is the furthest I could get
// 0x080B16AC
NONMATCH("asm/non_matching/code_080B1520/EEPROMWrite.inc", u16 EEPROMWrite(u16 unk_1, u16* unk_2, u8 unk_3)) {
    u16 stack[0x52];
    vu16 stack_a4;
    vu16 stack_a6;
    vu16 stack_a8;
    vu32 stack_ac;

    u32 r0, r1, r2;

    u8 i, j;
    u16* ptr;

    r1 = unk_1;
    if (unk_1 >= gEEPROMConfig->size)
        return EEPROM_OUT_OF_RANGE;

    ptr = stack + gEEPROMConfig->address_width + 0x42;
    *ptr = 0;
    ptr--;
    for (i = 0; i <= 3; i++) {
        r2 = *unk_2;
        unk_2++;
        for (j = 0; j <= 0xf; j++) {
            *ptr = r2;
            ptr--;
            r2 = r2 >> 1;
        }
    }
    for (i = 0; i < gEEPROMConfig->address_width; i++) {
        *ptr = r1;
        ptr--;
        r1 = r1 >> 1;
    }
    *ptr = 0;
    ptr--;
    *ptr = 1;
    DMA3Transfer(stack, (u16*)0xd000000, gEEPROMConfig->address_width + 0x43);
    stack_a4 = 0;
    stack_a6 = REG_VCOUNT;
    stack_ac = 0;
    if (stack_a4 == 0) {
        r0 = *(u16*)0xd000000;
        r0 &= 1;
        if (r0 != 0)
            goto bad;
    }
    do {
        do {
            do {
                stack_a8 = REG_VCOUNT;
                if (stack_a8 != stack_a6) {
                    if (stack_a8 > stack_a6) {
                        r1 = stack_a8;
                        r0 = stack_a6;
                        r1 = r1 - r0;
                        r0 = stack_ac;
                        r1 = r1 + r0;
                        stack_ac = r1;
                    } else {
                        r0 = stack_a8 + 0xe4;
                        r1 = stack_a6;
                        r0 = r0 - r1;
                        r1 = stack_ac;
                        r0 = r0 + r1;
                        stack_ac = r0;
                    }
                    if (stack_ac > 0x88) {
                        if (stack_a4 != 0)
                            return 0;
                        r0 = *(u16*)0xd000000;
                        r0 &= 1;
                        if (r0 != 0)
                            return 0;
                        return 0xc001;
                    }
                    stack_a6 = stack_a8;
                }
            } while (stack_a4 != 0);
            r1 = 1;
            r0 = *(u16*)0xd000000;
            r1 &= r0;
        } while (r1 != 0);
    bad:
        stack_a4++;
    } while (unk_3 != 0);
    return 0;
}
END_NONMATCH

u16 EEPROMCompare(u16 address, u16* data) {
    u16 ret;

    u16 buffer[4];
    u16* ptr;

    u8 i;

    ret = 0;
    if (address >= gEEPROMConfig->size) {
        return EEPROM_OUT_OF_RANGE;
    }
    EEPROMRead(address, buffer);
    ptr = buffer;
    for (i = 0; i < ARRAY_COUNT(buffer); i++) {
        if (*data++ != *ptr++) {
            ret = EEPROM_COMPARE_FAILED;
            break;
        }
    }
    return ret;
}

const char EEPROM_NOWAIT[] = "EEPROM_NOWAIT";

u32 EEPROMWrite1_check(u16 address, u16* data) {
    u8 i;
    u32 ret;

    for (i = 0; i < 3; i++) {
        ret = EEPROMWrite1(address, data);
        if (ret == 0) {
            ret = EEPROMCompare(address, data);
            if (ret == 0)
                break;
        }
    }
    return ret;
}

u16 EEPROMWrite0_8k(u16 address, u16* data) {
    u16 ret;

    if (gEEPROMConfig->unk_00 != 0x200) {
        ret = EEPROMWrite(address, data, 0);
    } else {
        ret = EEPROM_UNSUPPORTED_TYPE;
    }
    return ret;
}

u32 EEPROMWrite0_8k_Check(u16 address, u16* data) {
    u8 i;
    u32 ret;

    for (i = 0; i < 3; i++) {
        ret = EEPROMWrite0_8k(address, data);
        if (ret == 0) {
            ret = EEPROMCompare(address, data);
            if (ret == 0) {
                break;
            }
        }
    }
    return ret;
}

const char thing[0x1c] = "\xff\xff\xff\xff";
