#include "ultra64.h"
#include "structs.h"
#include "variables.h"
#include "functions.h"


void func_800B62D4(char*, char*, u32);                      /* extern */
void func_80049D78(void *);                         /* extern */
void func_80061134(s32, s32);                              /* extern */
void func_800B6B30();                                  /* extern */
void func_8004A34C();                                  /* extern */
s32 func_8007E03C(u32);                             /* extern */
void func_8007E328(s32);                               /* extern */
void func_8004A34C(void);
void func_800B6B30(void);

extern u16 D_800E20B0;
extern u32 D_800CFD40;
extern u32 D_800CFD44;
extern u16 D_800E20B0;
extern s32 D_800E20B8[];
extern u32 D_800E20C0;
extern u32 D_800E20C4;
extern s32 D_800E20C8[];
extern u32 D_800E20D0;
extern u32 D_800E20D4;
extern OSThread D_80103370;
extern s32 D_801076D0;
extern void *D_80110458;
extern OSMesgQueue D_80110558;

void func_80048020(void) {
    register s32 temp_t1;

    if (D_800E20C4 != 0) {
        temp_t1 = (s32) D_800E20C0 - D_800E20B8[D_800E20B0] >> 3;
        if ((u32) D_800CFD40 < (u32) temp_t1) {
            D_800CFD40 = (u32) temp_t1;
        }
    }
    if (D_800E20D4 != 0) {
        temp_t1 = (s32) D_800E20D0 - D_800E20C8[D_800E20B0] >> 4;
        if ((u32) D_800CFD44 < (u32) temp_t1) {
            D_800CFD44 = (u32) temp_t1;
        }
    }
}

void func_800480D8(void) {
}



void func_800480E0(void) {
    char buf[15];

    if (D_800E20C0 > (D_800E20B8[D_800E20B0] + D_800E20C4)) {
        func_800B62D4(buf, "glistEntries %d", (u32) D_800E20C4 >> 3);
        Fault_Assert("glist assert", buf);
    }
}

void func_80048150(void) {
    char buf[15];

    if (D_800E20D0 >  (D_800E20C8[D_800E20B0] + D_800E20D4)) {
        func_800B62D4(buf, "vlistEntries %d", (u32) D_800E20D4 >> 4);
        Fault_Assert("vlist assert", buf);
    }
}


void func_800481C0(s32 arg0, s32 arg1) {
    D_800CFD40 = 0;
    D_800CFD44 = 0;
    D_800E20C4 = arg0 * 8;
    D_800E20D4 = arg1 * 0x10;
    func_8004A34C();
    func_8007E328(D_800E20B8[0]);
    func_8007E328(D_800E20B8[1]);
    func_8007E328(D_800E20C8[0]);
    func_8007E328(D_800E20C8[1]);
    if (D_800E20C4 != 0) {
        D_800E20B8[0] = func_8007E03C(D_800E20C4);
        D_800E20B8[1] = func_8007E03C(D_800E20C4);
    }
    if (D_800E20D4 != 0) {
        D_800E20C8[0] = func_8007E03C(D_800E20D4);
        D_800E20C8[1] = func_8007E03C(D_800E20D4);
    }
    D_800E20C0 = (u32) D_800E20B8[D_800E20B0];
    D_800E20D0 = (u32) D_800E20C8[D_800E20B0];
}

void func_8004831C(s32 arg0) {
    D_800CFD40 = 0;
    D_800E20C4 = arg0 * 8;
    func_8004A34C();
    func_8007E328(D_800E20B8[0]);
    func_8007E328(D_800E20B8[1]);
    if (D_800E20C4 || FALSE) {
        D_800E20B8[0] = func_8007E03C(D_800E20C4);
        D_800E20B8[1] = func_8007E03C(D_800E20C4);
        D_800E20C0 = D_800E20B8[D_800E20B0];
    }
}

void func_800483E8(s32 arg0) {
    D_800CFD44 = 0;
    D_800E20D4 = arg0 * 16;
    func_8004A34C();
    func_8007E328(D_800E20C8[0]);
    func_8007E328(D_800E20C8[1]);
    if (D_800E20D4 || FALSE) {
        D_800E20C8[0] = func_8007E03C(D_800E20D4);
        D_800E20C8[1] = func_8007E03C(D_800E20D4);
        D_800E20D0 = (u32) D_800E20C8[D_800E20B0];
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_800484B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_80048934.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_80048A6C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_80048B64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_800492FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_80049AD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_80049C70.s")

void bootproc(void *arg0) {
    func_800B6B30();
    osCreateMesgQueue(&D_80110558, &D_80110458, 0x40);
    osSetEventMesg(0xEU, &D_80110558, (void *)0x309);
    func_80061134(0x190, 0x12C);
    osCreateThread(&D_80103370, 1, func_80049D78, arg0, &D_801076D0 + 0x800, 0xA);
    osStartThread(&D_80103370);
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_80049D78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_8004A0A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_8004A280.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_8004A34C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_8004A3A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/main/func_8004A5A0.s")
