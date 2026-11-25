// Funciones del juego sin fuente admitida: 0x80169094 a 0x801a45b0. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A8016805c();
__attribute__((weak)) void A8016808c();
__attribute__((weak)) void A8016857c();
__attribute__((weak)) void A8016a21c();
__attribute__((weak)) void A8016b9ec();
__attribute__((weak)) void A80172050();
__attribute__((weak)) void A801720c0();
__attribute__((weak)) void A80174074();
__attribute__((weak)) void A80178b5c();
__attribute__((weak)) void A80185af0();
__attribute__((weak)) void A8018ca1c();
__attribute__((weak)) void A80196cf0();
__attribute__((weak)) void A8019a2a8();
__attribute__((weak)) void A801a1250();
__attribute__((weak)) void A801a1460();
__attribute__((weak)) void A801a15f8();
__attribute__((weak)) void A801a2350();
__attribute__((weak)) void A801ea470();
__attribute__((weak)) void A801ef048();
__attribute__((weak)) void A801f69a8();
__attribute__((weak)) void A801fe2a8();
__attribute__((weak)) void A8020b680();
__attribute__((weak)) void A8020bb2c();
__attribute__((weak)) void A8020bcc0();
__attribute__((weak)) void A8020c5c0();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A80210afc();
__attribute__((weak)) void A80210b90();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A802ce30c();
__attribute__((weak)) void A802e82c0();
__attribute__((weak)) void A802e8b7c();
__attribute__((weak)) void A802eee50();
__attribute__((weak)) void A802fa95c();
__attribute__((weak)) void A802fa988();
__attribute__((weak)) void A802fb7ac();
__attribute__((weak)) void A80307d88();
__attribute__((weak)) void A803081d0();
__attribute__((weak)) void A803095c0();
__attribute__((weak)) void A8030bcb8();
__attribute__((weak)) void A803413d8();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A80341884();
__attribute__((weak)) void A80343584();
__attribute__((weak)) void A80343808();
__attribute__((weak)) void A8034435c();
__attribute__((weak)) void A8034bef8();
__attribute__((weak)) void A8034bf50();
__attribute__((weak)) void A8034c148();
__attribute__((weak)) void A8034c340();
__attribute__((weak)) void A8034c538();
__attribute__((weak)) void A8034c730();
__attribute__((weak)) void A8034c928();

// 0x80169094 FUN_80169094 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_position_array_skinned. Llama a cache_flush, temp_alloc, skin, sol35f7a_pool_allocate, sol35f8b_allocation_fallback. Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A80169094(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[104];
    w3d_u32 r1 = h2g(frame) + 88;
    w3d_u32 r0 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, ctr = 0, lr = 0;
    { w3d_u32 t_ = r1 - 88; S32(t_, r1); r1 = t_; }
    r31 = r1;
    r3 = r3; cr0 = CMPS(r3, 0);
    r28 = 0x0u;
    if ((cr0 & 2)) goto L_801690b8;
    r28 = r3 - 4;
L_801690b8:
    r9 = L32(r4 + 20);
    r26 = L32(r9 + 24);
    r24 = r9 + 32;
    cr0 = CMPS(r26, 0);
    if ((cr0 & 2)) goto L_80169380;
    r30 = r9;
    r4 = (w3d_s32)r26 * 12;
    r0 = L16(r30 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801690f0;
    r3 = r24;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r30 + 28, r0);
L_801690f0:
    r30 = L32(r28 + 124);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80169358;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x80363654u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_80169138;
L_80169120:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_80169208;
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_80169120;
L_80169138:
    r0 = 0x1u;
L_8016913c:
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80169148;
    r30 = 0x0u;
L_80169148:
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80169210;
    r4 = (w3d_s32)r26 * 12;
    r9 = L32(r30 + 28);
    r11 = L32(r30 + 20);
    r3 = r28;
    r25 = r9 + 32;
    r27 = r11 + 32;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8016a21c)(W(r3), W(r4));
    r0 = L32(r28 + 132);
    r8 = 0x0u;
    r9 = L32(r1);
    r29 = r3;
    r0 = r0 << 6;
    r0 = r0 | 0x8u;
    r0 = 0u - r0;
    { char *p_ = (char *)__builtin_alloca((w3d_u32)(0u - r0) + 16); w3d_u32 t_ = h2g(p_); S32(t_, r9); r1 = t_; }
    r0 = L32(r28 + 132);
    r7 = r1 + 16;
    cr0 = CMPU(r8, r0);
    if (!(cr0 & 8)) goto L_801691c4;
    r10 = 0x0u;
L_801691a0:
    r9 = L32(r28 + 128);
    r8 = r8 + 1;
    r11 = L32(r10 + r9);
    r11 = r11 + 48;
    S32(r10 + r7, r11);
    r10 = r10 + 4;
    r0 = L32(r28 + 132);
    cr0 = CMPU(r8, r0);
    if ((cr0 & 8)) goto L_801691a0;
L_801691c4:
    r0 = 0xcu;
    r4 = L16(r30 + 24);
    S32(r1 + 8, r0);
    r9 = r26;
    r5 = r27;
    r6 = r25;
    r8 = r29;
    r10 = 0xcu;
    r3 = r24;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801a1460)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10), W(L32(r1 + 8)));
    r3 = L32(D(0x804b1884u));
    ((void (*)(w3d_oarg))A8016805c)(W(r3));
    r4 = (w3d_s32)r26 * 12;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r4 = r29;
    goto L_8016935c;
L_80169208:
    r0 = 0x0u;
    goto L_8016913c;
L_80169210:
    r11 = L32(r28 + 124);
    r4 = (w3d_s32)r26 * 12;
    r3 = r28;
    r9 = L32(r11 + 20);
    r27 = r31 + 16;
    r23 = r9 + 32;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8016a21c)(W(r3), W(r4));
    r29 = L32(r28 + 132);
    r25 = r3;
    S32(r31 + 16, r30);
    S32(r27 + 4, r30);
    cr0 = CMPS(r29, 0);
    S32(r31 + 28, r30);
    if ((cr0 & 2)) goto L_8016926c;
    r0 = r29 << 2;
    r3 = r0;
    r30 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80169274;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
    goto L_80169274;
L_8016926c:
    r3 = 0x0u;
    r30 = 0x0u;
L_80169274:
    r0 = r3 + r30;
    r9 = 0x0u;
    S32(r27 + 12, r0);
    S32(r27, r3);
    r0 = r29; cr0 = CMPS(r0, 0);
    S32(r27 + 4, r3);
    ctr = r0;
    S32(r31 + 40, r9);
    r9 = r31 + 40;
    if ((cr0 & 2)) goto L_801692ac;
L_8016929c:
    r0 = L32(r9);
    S32(r3, r0);
    r3 = r3 + 4;
    --ctr; if (ctr != 0) goto L_8016929c;
L_801692ac:
    S32(r27 + 4, r3);
    r7 = 0x0u;
    r0 = L32(r28 + 132);
    cr0 = CMPU(r7, r0);
    if (!(cr0 & 8)) goto L_801692ec;
    r8 = 0x0u;
L_801692c4:
    r11 = L32(r28 + 128);
    r7 = r7 + 1;
    r10 = L32(r31 + 16);
    r9 = L32(r8 + r11);
    r9 = r9 + 48;
    S32(r10 + r8, r9);
    r8 = r8 + 4;
    r0 = L32(r28 + 132);
    cr0 = CMPU(r7, r0);
    if ((cr0 & 8)) goto L_801692c4;
L_801692ec:
    r6 = L32(r31 + 16);
    r5 = r23;
    r4 = L32(r28 + 132);
    r7 = r25;
    r8 = r26;
    r3 = r24;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801a1250)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(D(0x804b1884u));
    ((void (*)(w3d_oarg))A8016805c)(W(r3));
    r4 = (w3d_s32)r26 * 12;
    r3 = r25;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r3 = 0x9u;
    r4 = r25;
    r5 = 0xcu;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r28 + 288);
    r9 = L32(r28 + 284);
    r0 = r0 | 0x1u;
    r9 = r9 + 1;
    S32(r28 + 288, r0);
    S32(r28 + 284, r9);
    r3 = L32(r31 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80169380;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
    goto L_80169380;
L_80169358:
    r4 = r24;
L_8016935c:
    r3 = 0x9u;
    r5 = 0xcu;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r28 + 288);
    r9 = L32(r28 + 284);
    r0 = r0 | 0x1u;
    r9 = r9 + 1;
    S32(r28 + 288, r0);
    S32(r28 + 284, r9);
L_80169380:
    r3 = 0x0u;
    r11 = L32(r1);
    r0 = L32(r11 + 4);
    lr = r0;
    r1 = r11;
    return r3;
}

// 0x8016939c FUN_8016939c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_position_short3_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A8016939c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r29 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r31 = 0x0u;
    if ((cr0 & 2)) goto L_801693c0;
    r31 = r3 - 4;
L_801693c0:
    r9 = L32(r29 + 20);
    r4 = L32(r9 + 24);
    r28 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80169434;
    r30 = r9;
    r4 = (w3d_s32)r4 * 6;
    r0 = L16(r30 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801693f8;
    r3 = r28;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r30 + 28, r0);
L_801693f8:
    r0 = L32(r31 + 124);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80169434;
    r4 = r28;
    r3 = 0x9u;
    r5 = 0x6u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r31 + 288);
    r9 = L32(r31 + 284);
    r11 = L8(r29 + 24);
    r0 = r0 | 0x2u;
    r9 = r9 + 1;
    S32(r31 + 288, r0);
    S32(r31 + 284, r9);
    S8(r31 + 316, r11);
L_80169434:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x8016944c FUN_8016944c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_position_float4_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A8016944c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_80169470;
    r30 = r3 - 4;
L_80169470:
    r9 = L32(r11 + 24);
    r4 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_801694d0;
    r31 = r9;
    r4 = r4 << 4;
    r0 = L16(r31 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801694a8;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r31 + 28, r0);
L_801694a8:
    r4 = r29;
    r3 = 0x9u;
    r5 = 0x10u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 288);
    r9 = L32(r30 + 284);
    r0 = r0 | 0x1u;
    r9 = r9 + 1;
    S32(r30 + 288, r0);
    S32(r30 + 284, r9);
L_801694d0:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x801694e8 FUN_801694e8 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_normal_array_skinned. Llama a cache_flush, temp_alloc, skin_normal, finish, GXSetArray. Hace 1 llamada virtual. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A801694e8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[80];
    w3d_u32 r1 = h2g(frame) + 64;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 64; S32(t_, r1); r1 = t_; }
    r31 = r1;
    r3 = r3; cr0 = CMPS(r3, 0);
    r29 = 0x0u;
    if ((cr0 & 2)) goto L_8016950c;
    r29 = r3 - 4;
L_8016950c:
    r9 = L32(r4 + 20);
    r27 = L32(r9 + 24);
    r26 = r9 + 32;
    cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_801696e8;
    r30 = r9;
    r4 = (w3d_s32)r27 * 12;
    r0 = L16(r30 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80169544;
    r3 = r26;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r30 + 28, r0);
L_80169544:
    r0 = L32(r29 + 124);
    r10 = 0x0u;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80169598;
    f12 = LF(r29 + 248);
    r11 = r31 + 16;
    r9 = D(0x803a0000u);
    SF(r31 + 16, f12);
    f11 = LF(D(0x803a5030u));
    f0 = LF(r29 + 264);
    SF(r31 + 20, f0);
    f13 = LF(r29 + 280);
    SF(r31 + 24, f13);
    f0 = LF(r11 + 4);
    f13 = LF(r11 + 8);
    f0 = (float)(f0 * f0);
    f12 = __builtin_fmaf((float)f12, (float)f12, (float)f0);
    f13 = __builtin_fmaf((float)f13, (float)f13, (float)f12);
    cr0 = CMPF(f13, f11);
    if (!(cr0 & 8)) goto L_80169598;
    r10 = 0x1u;
L_80169598:
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801696c0;
    r30 = L32(r29 + 124);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801695f4;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x80363654u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_801695e8;
L_801695d0:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_801696b8;
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_801695d0;
L_801695e8:
    r0 = 0x1u;
L_801695ec:
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_801695f8;
L_801695f4:
    r30 = 0x0u;
L_801695f8:
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801696e8;
    r4 = (w3d_s32)r27 * 12;
    r9 = L32(r30 + 28);
    r11 = L32(r30 + 20);
    r3 = r29;
    r24 = r9 + 32;
    r25 = r11 + 32;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8016a21c)(W(r3), W(r4));
    r0 = L32(r29 + 132);
    r8 = 0x0u;
    r9 = L32(r1);
    r28 = r3;
    r0 = r0 << 6;
    r0 = r0 | 0x8u;
    r0 = 0u - r0;
    { char *p_ = (char *)__builtin_alloca((w3d_u32)(0u - r0) + 16); w3d_u32 t_ = h2g(p_); S32(t_, r9); r1 = t_; }
    r0 = L32(r29 + 132);
    r7 = r1 + 16;
    cr0 = CMPU(r8, r0);
    if (!(cr0 & 8)) goto L_80169674;
    r10 = 0x0u;
L_80169650:
    r9 = L32(r29 + 128);
    r8 = r8 + 1;
    r11 = L32(r10 + r9);
    r11 = r11 + 48;
    S32(r10 + r7, r11);
    r10 = r10 + 4;
    r0 = L32(r29 + 132);
    cr0 = CMPU(r8, r0);
    if ((cr0 & 8)) goto L_80169650;
L_80169674:
    r0 = 0xcu;
    r4 = L16(r30 + 24);
    S32(r1 + 8, r0);
    r9 = r27;
    r5 = r25;
    r6 = r24;
    r8 = r28;
    r10 = 0xcu;
    r3 = r26;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801a15f8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10), W(L32(r1 + 8)));
    r3 = L32(D(0x804b1884u));
    ((void (*)(w3d_oarg))A8016808c)(W(r3));
    r4 = (w3d_s32)r27 * 12;
    r3 = r28;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r4 = r28;
    goto L_801696c4;
L_801696b8:
    r0 = 0x0u;
    goto L_801695ec;
L_801696c0:
    r4 = r26;
L_801696c4:
    r3 = 0xau;
    r5 = 0xcu;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r29 + 288);
    r9 = L32(r29 + 284);
    r0 = r0 | 0x4u;
    r9 = r9 + 1;
    S32(r29 + 288, r0);
    S32(r29 + 284, r9);
L_801696e8:
    r3 = 0x0u;
    r11 = L32(r1);
    r0 = L32(r11 + 4);
    lr = r0;
    r1 = r11;
    return r3;
}

// 0x80169704 FUN_80169704 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_normal_short3_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A80169704(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r29 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r31 = 0x0u;
    if ((cr0 & 2)) goto L_80169728;
    r31 = r3 - 4;
L_80169728:
    r9 = L32(r29 + 20);
    r4 = L32(r9 + 24);
    r28 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8016979c;
    r30 = r9;
    r4 = (w3d_s32)r4 * 6;
    r0 = L16(r30 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80169760;
    r3 = r28;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r30 + 28, r0);
L_80169760:
    r0 = L32(r31 + 124);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8016979c;
    r4 = r28;
    r3 = 0xau;
    r5 = 0x6u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r31 + 288);
    r9 = L32(r31 + 284);
    r11 = L8(r29 + 24);
    r0 = r0 | 0x8u;
    r9 = r9 + 1;
    S32(r31 + 288, r0);
    S32(r31 + 284, r9);
    S8(r31 + 317, r11);
L_8016979c:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x80169854 FUN_80169854 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_color_float4_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A80169854(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_80169878;
    r30 = r3 - 4;
L_80169878:
    r9 = L32(r11 + 20);
    r4 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_801698d8;
    r31 = r9;
    r4 = r4 << 4;
    r0 = L16(r31 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801698b0;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r31 + 28, r0);
L_801698b0:
    r4 = r29;
    r3 = 0xbu;
    r5 = 0x10u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 288);
    r9 = L32(r30 + 284);
    r0 = r0 | 0x10u;
    r9 = r9 + 1;
    S32(r30 + 288, r0);
    S32(r30 + 284, r9);
L_801698d8:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x801698f0 FUN_801698f0 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_color_rgba8_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A801698f0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_80169914;
    r30 = r3 - 4;
L_80169914:
    r9 = L32(r11 + 20);
    r4 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80169974;
    r31 = r9;
    r4 = r4 << 2;
    r0 = L16(r31 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016994c;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r31 + 28, r0);
L_8016994c:
    r4 = r29;
    r3 = 0xbu;
    r5 = 0x4u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 288);
    r9 = L32(r30 + 284);
    r0 = r0 | 0x10u;
    r9 = r9 + 1;
    S32(r30 + 288, r0);
    S32(r30 + 284, r9);
L_80169974:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x8016998c FUN_8016998c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_color_rgb16_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A8016998c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_801699b0;
    r30 = r3 - 4;
L_801699b0:
    r9 = L32(r11 + 20);
    r4 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80169a10;
    r31 = r9;
    r4 = r4 + r4;
    r0 = L16(r31 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801699e8;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r31 + 28, r0);
L_801699e8:
    r4 = r29;
    r3 = 0xbu;
    r5 = 0x2u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 288);
    r9 = L32(r30 + 284);
    r0 = r0 | 0x20u;
    r9 = r9 + 1;
    S32(r30 + 288, r0);
    S32(r30 + 284, r9);
L_80169a10:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x8016aef0 FUN_8016aef0 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: begin_list. Llama a aligned_allocate, cache_invalidate.
__attribute__((weak)) w3d_u32 A8016aef0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r0 = L32(r6 + 180);
    r31 = r3;
    r30 = r5;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 8)) goto L_8016af4c;
    r9 = r4 & 0x3u; cr0 = CMPS(r9, 0);
    r0 = r4 & 0xcu; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016af28;
    r0 = L32(r6 + 180);
    r9 = r0 & 0x10000000u; cr0 = CMPS(r9, 0);
L_8016af28:
    r0 = r4 & 0x30u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016af38;
    r0 = L32(r6 + 180);
    r9 = r0 & 0x8000000u; cr0 = CMPS(r9, 0);
L_8016af38:
    r0 = r4 & 0x180u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016af58;
    r0 = L32(r6 + 180);
    r9 = r0 & 0x4000000u; cr0 = CMPS(r9, 0);
    goto L_8016af58;
L_8016af4c:
    r9 = r0 & 0x40000000u; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8016af58;
    r9 = r4 & 0x180u; cr0 = CMPS(r9, 0);
L_8016af58:
    r0 = L32(D(0x804ab534u));
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8016af74;
    r3 = 0x10000u;
    r4 = 0x20u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801fe2a8)(W(r3), W(r4));
    S32(D(0x804ab534u), r3);
L_8016af74:
    r0 = 0xaaaa0000u;
    r11 = L32(D(0x804ab534u));
    r0 = 0xaaaaaaabu;
    r9 = 0x10000u;
    r0 = (w3d_u32)(((w3d_u64)r30 * (w3d_u64)r0) >> 32);
    S32(r31 + 4, r9);
    r3 = r11;
    S32(r31 + 12, r11);
    r4 = 0x10000u;
    r0 = ROTL(r0, 31) & 0xffffu;
    S32(r31, r0);
    ((void (*)(w3d_oarg, w3d_oarg))A802fa95c)(W(r3), W(r4));
    r3 = L32(r31 + 12);
    r4 = 0x10000u;
    r3 = CU(A8030bcb8, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = CU(A803081d0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 16;
    return r3;
}

// 0x8016b040 FUN_8016b040 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: finish_streams. Llama a array_ref_lock.
__attribute__((weak)) w3d_u32 A8016b040(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r6 = 0, r9 = 0, r10 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r31 = r5;
    r29 = r3;
    r0 = L32(r31 + 188);
    r9 = r4;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b370;
    r4 = L32(r31 + 180);
    r10 = r4 >> 31;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_8016b2bc;
    r30 = L32(r9 + 92);
    r0 = r29 & 0x3u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b108;
    r4 = ROTL(r4, 3) & 0x1u;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8016b0c0;
    r3 = L32(r30 + 36);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b0b4;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b0e4;
L_8016b0b4:
    r4 = 0x0u;
    r5 = 0x1u;
    goto L_8016b0f8;
L_8016b0c0:
    r3 = L32(r30 + 36);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b0f4;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_8016b0f4;
L_8016b0e4:
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8016b100;
L_8016b0f4:
    r5 = 0x2u;
L_8016b0f8:
    r6 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8016b100:
    r0 = 0x0u;
    S32(r31 + 164, r0);
L_8016b108:
    r0 = r29 & 0xcu; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b198;
    r0 = L32(r31 + 180);
    r4 = ROTL(r0, 4) & 0x1u;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8016b150;
    r3 = L32(r30 + 32);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b144;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b174;
L_8016b144:
    r4 = 0x0u;
    r5 = 0x1u;
    goto L_8016b188;
L_8016b150:
    r3 = L32(r30 + 32);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b184;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_8016b184;
L_8016b174:
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8016b190;
L_8016b184:
    r5 = 0x2u;
L_8016b188:
    r6 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8016b190:
    r0 = 0x0u;
    S32(r31 + 168, r0);
L_8016b198:
    r0 = r29 & 0x30u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b228;
    r0 = L32(r31 + 180);
    r4 = ROTL(r0, 5) & 0x1u;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8016b1e0;
    r3 = L32(r30 + 28);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b1d4;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b204;
L_8016b1d4:
    r4 = 0x0u;
    r5 = 0x1u;
    goto L_8016b218;
L_8016b1e0:
    r3 = L32(r30 + 28);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b214;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_8016b214;
L_8016b204:
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8016b220;
L_8016b214:
    r5 = 0x2u;
L_8016b218:
    r6 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8016b220:
    r0 = 0x0u;
    S32(r31 + 172, r0);
L_8016b228:
    r0 = r29 & 0x180u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b368;
    r0 = L32(r31 + 180);
    r4 = ROTL(r0, 6) & 0x1u;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8016b270;
    r3 = L32(r30 + 24);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b264;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b294;
L_8016b264:
    r4 = 0x0u;
    r5 = 0x1u;
    goto L_8016b2a8;
L_8016b270:
    r3 = L32(r30 + 24);
    r11 = L32(r3 + 24);
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b2a4;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_8016b2a4;
L_8016b294:
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8016b2b0;
L_8016b2a4:
    r5 = 0x2u;
L_8016b2a8:
    r6 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8016b2b0:
    r0 = 0x0u;
    S32(r31 + 176, r0);
    goto L_8016b368;
L_8016b2bc:
    r4 = ROTL(r4, 2) & 0x1u;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8016b310;
    r9 = L32(r9 + 92);
    r11 = L32(r9 + 24);
    r3 = r9 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b2fc;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r10, r0);
    if (!(cr0 & 2)) goto L_8016b2fc;
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8016b368;
L_8016b2fc:
    r4 = r10;
    r5 = 0x1u;
    r6 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    goto L_8016b368;
L_8016b310:
    r3 = L32(r9 + 92);
    r9 = L32(r3 + 24);
    r0 = L32(r9 + 24);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8016b360;
    r11 = r9;
    r3 = r3 + 24;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8016b354;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_8016b354;
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8016b360;
L_8016b354:
    r5 = 0x2u;
    r6 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8016b360:
    r0 = 0x0u;
    S32(r31 + 160, r0);
L_8016b368:
    r0 = 0x0u;
    S32(r31 + 188, r0);
L_8016b370:
    r1 = r1 + 24;
    return r3;
}

// 0x8016bbbc FUN_8016bbbc no verificada: desde bytes PPC
// Llama a transpose4, sqrt, os_report, set_material_colors, enable_slot. Hace 2 llamadas virtuales. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8016bbbc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[120];
    w3d_u32 r1 = h2g(frame) + 104;
    w3d_u32 r0 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 104; S32(t_, r1); r1 = t_; }
    r29 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r11 = 0x0u;
    if ((cr0 & 2)) goto L_8016bbe0;
    r11 = r3 - 4;
L_8016bbe0:
    f13 = LF(r29 + 156);
    r9 = r29 + 156;
    r0 = L32(r29 + 144);
    r31 = r1 + 8;
    f12 = LF(r9 + 8);
    r3 = L32(D(0x804b1884u));
    cr0 = CMPS(r0, 0);
    f0 = LF(r9 + 4);
    SF(r1 + 8, f13);
    r28 = r3 + 264;
    SF(r31 + 4, f0);
    SF(r31 + 8, f12);
    if ((cr0 & 2)) goto L_8016bda4;
    r0 = L32(r11 + 204);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8016bca8;
    r9 = L32(r11);
    r3 = r11;
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = r29 + 44;
    r11 = r3;
    r9 = 0x30u;
L_8016bc40:
    r0 = L32(r11);
    { w3d_u32 t_ = r9; r9 = t_ + (w3d_u32)-24; ca = r9 < t_; cr0 = CMPS(r9, 0); }
    S32(r4, r0);
    r0 = L32(r11 + 4);
    S32(r4 + 4, r0);
    r0 = L32(r11 + 8);
    S32(r4 + 8, r0);
    r0 = L32(r11 + 12);
    S32(r4 + 12, r0);
    r0 = L32(r11 + 16);
    S32(r4 + 16, r0);
    r0 = L32(r11 + 20);
    r11 = r11 + 24;
    S32(r4 + 20, r0);
    r4 = r4 + 24;
    if (!(cr0 & 2)) goto L_8016bc40;
    r0 = L32(r11);
    r3 = 0x0u;
    S32(r4, r0);
    r0 = L32(r11 + 4);
    S32(r4 + 4, r0);
    r0 = L32(r11 + 8);
    S32(r4 + 8, r0);
    r0 = L32(r11 + 12);
    S32(r4 + 12, r0);
    goto L_8016bde4;
L_8016bca8:
    r9 = L32(r3);
    r30 = r1 + 24;
    r4 = r30;
    r0 = L32(r9 + 96);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = r30;
    r3 = r30;
    ((void (*)(w3d_oarg, w3d_oarg))A801f69a8)(W(r3), W(r4));
    f12 = LF(r1 + 40);
    r9 = r1 + 40;
    f11 = LF(r31 + 4);
    r11 = r1 + 56;
    f0 = LF(r1 + 8);
    r10 = r1 + 72;
    f9 = LF(r1 + 24);
    f11 = (float)(f11 * f12);
    f10 = LF(r1 + 56);
    f13 = LF(r31 + 8);
    f0 = __builtin_fmaf((float)f0, (float)f9, (float)f11);
    f12 = LF(r1 + 72);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f0);
    f13 = (float)(f13 + f12);
    SF(r1 + 8, f13);
    f0 = LF(r9 + 4);
    f12 = LF(r31 + 4);
    f9 = LF(r30 + 4);
    f12 = (float)(f12 * f0);
    f11 = LF(r31 + 8);
    f0 = LF(r11 + 4);
    f13 = __builtin_fmaf((float)f13, (float)f9, (float)f12);
    f10 = LF(r10 + 4);
    f0 = __builtin_fmaf((float)f11, (float)f0, (float)f13);
    f0 = (float)(f0 + f10);
    SF(r31 + 4, f0);
    f8 = (float)(f0 * f0);
    f12 = LF(r9 + 8);
    f9 = LF(r30 + 8);
    f13 = LF(r1 + 8);
    f0 = (float)(f0 * f12);
    f10 = LF(r11 + 8);
    f13 = __builtin_fmaf((float)f13, (float)f9, (float)f0);
    f12 = LF(r10 + 8);
    f11 = __builtin_fmaf((float)f11, (float)f10, (float)f13);
    f11 = (float)(f11 + f12);
    SF(r31 + 8, f11);
    f1 = LF(r1 + 8);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f8);
    f1 = __builtin_fmaf((float)f11, (float)f11, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x803a0000u);
    f0 = LF(r1 + 8);
    f12 = LF(D(0x803a5694u));
    f12 = (float)(f12 / f1);
    f0 = (float)(f0 * f12);
    SF(r1 + 8, f0);
    f13 = LF(r31 + 4);
    f0 = LF(r31 + 8);
    f13 = (float)(f13 * f12);
    f0 = (float)(f0 * f12);
    SF(r31 + 4, f13);
    SF(r31 + 8, f0);
    goto L_8016bdb4;
L_8016bda4:
    r3 = D(0x803a0000u);
    r3 = D(0x803a5678u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, ...))A802fb7ac)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
L_8016bdb4:
    f1 = LF(r1 + 8);
    r3 = r28;
    f2 = LF(r1 + 12);
    f3 = LF(r1 + 16);
    r3 = CU(A803095c0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r28;
    r4 = r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8016b9ec)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(D(0x804b1884u));
    r4 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8016857c)(W(r3), W(r4), W(r5), W(r6));
    r3 = 0x0u;
L_8016bde4:
    r1 = r1 + 104;
    return r3;
}

// 0x8016ece0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8016ece0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 32);
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80172be4 FUN_80172be4 no verificada: desde bytes PPC
// Llama a node_set_type, cast_mesh, get_selected, bitset, sol35f7a_pool_allocate. Hace 4 llamadas virtuales. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A80172be4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[144];
    w3d_u32 r1 = h2g(frame) + 128;
    w3d_u32 r0 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr7 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 128; S32(t_, r1); r1 = t_; }
    r31 = r4;
    r28 = r3;
    r18 = r5;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80185af0)(W(r3), W(r4), W(r5));
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_80172c20;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80172c20:
    r3 = L32(r28 + 116);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80172c3c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80172c3c:
    r9 = r1 + 8;
    S32(r28 + 116, r31);
    S32(r1 + 32, r9);
    r3 = r31;
    ((void (*)())A80343808)();
    r25 = r3;
    r4 = r18;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80172050)(W(r3), W(r4));
    r29 = L32(r3 + 48);
    r4 = r18;
    r3 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801720c0)(W(r3), W(r4));
    r6 = L32(r1 + 32);
    r31 = r3;
    r8 = 0x0u;
    r0 = L32(r31 + 4);
    r10 = r28 + 12;
    r9 = L32(r31);
    r11 = r28 + 24;
    r26 = r29 + 100;
    r23 = r29 + 64;
    r0 = r0 - r9;
    r24 = r29 + 88;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r16 = r29 + 96;
    r19 = r29 + 84;
    r15 = r29 + 68;
    cr0 = CMPU(r8, r0);
    r21 = r29 + 4;
    r14 = r28 + 36;
    S32(r1 + 36, r10);
    S32(r1 + 40, r11);
    r17 = r28 + 120;
    if (!(cr0 & 8)) goto L_80172d28;
    r10 = r9;
    r7 = 0x0u;
L_80172ccc:
    r11 = L32(r10);
    r10 = r10 + 4;
    cr0 = CMPS(r11, -1);
    if ((cr0 & 2)) goto L_80172d18;
    r0 = r11;
    r9 = 0x0u;
    r10 = r0 & 0x1u; cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80172cfc;
L_80172cec:
    r0 = r0 >> 1;
    r9 = r9 + 1;
    r11 = r0 & 0x1u; cr0 = CMPS(r11, 0);
    if (!(cr0 & 2)) goto L_80172cec;
L_80172cfc:
    r9 = r7 + r9;
    S32(r6, r9);
    r0 = L32(r31 + 12);
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 8)) goto L_80172d28;
    r10 = 0x1u;
    goto L_80172d34;
L_80172d18:
    r8 = r8 + 1;
    r7 = r7 + 32;
    cr0 = CMPU(r8, r0);
    if ((cr0 & 8)) goto L_80172ccc;
L_80172d28:
    r0 = 0xffffffffu;
    r10 = 0x0u;
    S32(r6, r0);
L_80172d34:
    cr0 = CMPS(r10, 0);
    if (!(cr0 & 2)) goto L_80173154;
    r9 = L32(r31 + 12);
    r8 = L32(r31 + 4);
    r11 = L32(r31);
    r9 = r9 >> 5;
    r9 = r9 + 1;
    r11 = r8 - r11;
    { w3d_u32 t_ = r11; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80172e2c;
    r0 = L32(r31 + 8);
    r27 = r1 + 12;
    S32(r1 + 12, r10);
    cr0 = CMPS(r8, r0);
    if (!(cr0 & 2)) goto L_80172e14;
    r0 = r11 >> 1;
    r9 = r11 + 1;
    r0 = r11 + r0;
    S32(r1 + 16, r9);
    cr0 = CMPS(r9, r0);
    S32(r1 + 20, r0);
    S32(r1 + 28, r11);
    r0 = r1 + 20;
    r9 = r1 + 16;
    if (!(cr0 & 8)) goto L_80172da0;
    r9 = r0;
L_80172da0:
    r0 = L32(r9);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 24, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r31);
    r30 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80172df8;
    r9 = L32(r1 + 24);
    r11 = r1 + 28;
    r0 = L32(r1 + 28);
    r5 = r1 + 24;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80172de0;
    r5 = r11;
L_80172de0:
    r5 = L32(r5);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r31);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80172df8:
    S32(r31, r30);
    r0 = L32(r1 + 28);
    r0 = r30 + r0;
    S32(r31 + 4, r0);
    r9 = L32(r1 + 24);
    r9 = r30 + r9;
    S32(r31 + 8, r9);
L_80172e14:
    r0 = L32(r27);
    r11 = L32(r31 + 4);
    S32(r11, r0);
    r9 = L32(r31 + 4);
    r9 = r9 + 4;
    S32(r31 + 4, r9);
L_80172e2c:
    r9 = L32(r31 + 12);
    r3 = r31;
    r5 = 0x1u;
    r30 = r9;
    r9 = r9 + 1;
    r4 = r30;
    S32(r31 + 12, r9);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8034bef8)(W(r3), W(r4), W(r5));
    S32(r1 + 8, r30);
    r11 = L32(r29 + 100);
    r9 = L32(r11 + 24);
    r0 = L16(r11 + 4);
    r4 = r9 + 1;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80172e84;
    cr0 = CMPS(r4, r9);
    if (!(cr0 & 2)) goto L_80172e84;
    r9 = L16(r11 + 28);
    r22 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80172e98;
L_80172e84:
    r3 = r26;
    r5 = 0x1u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r22 = r3;
L_80172e98:
    r11 = L32(r29 + 64);
    r9 = L32(r11 + 24);
    r0 = L16(r11 + 4);
    r4 = r9 + 1;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80172ecc;
    cr0 = CMPS(r4, r9);
    if (!(cr0 & 2)) goto L_80172ecc;
    r9 = L16(r11 + 28);
    r26 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80172ee0;
L_80172ecc:
    r3 = r23;
    r5 = 0xcu;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r26 = r3;
L_80172ee0:
    r11 = L32(r29 + 88);
    r0 = L16(r11 + 4);
    r27 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80172f04;
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80172f18;
L_80172f04:
    r3 = r24;
    r4 = r27;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_80172f18:
    r11 = L32(r29 + 96);
    r9 = L32(r11 + 24);
    r0 = L16(r11 + 4);
    r4 = r9 + 1;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80172f4c;
    cr0 = CMPS(r4, r9);
    if (!(cr0 & 2)) goto L_80172f4c;
    r9 = L16(r11 + 28);
    r23 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80172f60;
L_80172f4c:
    r3 = r16;
    r5 = 0x1u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r23 = r3;
L_80172f60:
    r11 = L32(r29 + 84);
    r0 = L16(r11 + 4);
    r31 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80172f84;
    r9 = L16(r11 + 28);
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80172f98;
L_80172f84:
    r3 = r19;
    r4 = r31;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_80172f98:
    r11 = L32(r29 + 68);
    r9 = L32(r11 + 24);
    r0 = L16(r11 + 4);
    r4 = r9 + 1;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80172fcc;
    cr0 = CMPS(r4, r9);
    if (!(cr0 & 2)) goto L_80172fcc;
    r9 = L16(r11 + 28);
    r30 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80172fe0;
L_80172fcc:
    r3 = r15;
    r5 = 0x8u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r30 = r3;
L_80172fe0:
    r0 = L8(r21 + 4);
    cr7 = CMPS(r27, 0);
    r27 = r30;
    r0 = r0 & 0xfbu; cr0 = CMPS(r0, 0);
    S8(r21 + 4, r0);
    if ((cr7 & 2)) goto L_80173050;
    r11 = L32(r29 + 88);
    r9 = L32(r11 + 24);
    r0 = L16(r11 + 4);
    r4 = r9 + 1;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8017302c;
    cr0 = CMPS(r4, r9);
    if (!(cr0 & 2)) goto L_8017302c;
    r9 = L16(r11 + 28);
    r3 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8017303c;
L_8017302c:
    r3 = r24;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8017303c:
    r0 = L32(r1 + 8);
    r9 = D(0x803a0000u);
    f0 = LF(D(0x803a66f4u));
    r0 = r0 << 2;
    SF(r3 + r0, f0);
L_80173050:
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_801730c0;
    r10 = L32(r29 + 84);
    r9 = L32(r10 + 24);
    r0 = L16(r10 + 4);
    r4 = r9 + 1;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8017308c;
    cr0 = CMPS(r4, r9);
    if (!(cr0 & 2)) goto L_8017308c;
    r9 = L16(r10 + 28);
    r3 = r10 + 32;
    r9 = r9 + 1;
    S16(r10 + 28, r9);
    goto L_8017309c;
L_8017308c:
    r3 = r19;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8017309c:
    r9 = L32(r1 + 8);
    r0 = 0xffffffffu;
    r11 = r3;
    r9 = r9 << 2;
    S8(r9 + r11, r0);
    r9 = r9 + r11;
    S8(r9 + 3, r0);
    S8(r9 + 1, r0);
    S8(r9 + 2, r0);
L_801730c0:
    r9 = L32(r1 + 8);
    r0 = 0x0u;
    r11 = D(0x803a0000u);
    r6 = 0x1u;
    S8(r22 + r9, r0);
    f0 = LF(D(0x803a66f4u));
    r5 = 0x43300000u;
    r9 = L32(r1 + 8);
    r7 = r8;
    r11 = D(0x803a0000u);
    r10 = D(0x803a0000u);
    r9 = (w3d_s32)r9 * 12;
    f12 = LD(D(0x803a66f8u));
    f11 = LF(D(0x803a6700u));
    { w3d_u32 t_ = r9 + r26; SF(t_, f0); r9 = t_; }
    SF(r9 + 8, f0);
    SF(r9 + 4, f0);
    r0 = L32(r1 + 8);
    S8(r23 + r0, r6);
    r9 = L16(r25 + 40);
    r0 = L16(r25 + 42);
    r9 = r9 ^ 0x80000000u;
    r11 = L32(r1 + 8);
    S32(r1 + 52, r9);
    r0 = r0 ^ 0x80000000u;
    r11 = r11 << 3;
    S32(r1 + 48, r5);
    r9 = r11 + r30;
    f13 = LDS(r1 + 48);
    S32(r1 + 52, r0);
    f13 = f13 - f12;
    S32(r1 + 48, r5);
    f13 = (float)f13;
    f13 = (float)(f13 * f11);
    f0 = LDS(r1 + 48);
    SF(r11 + r30, f13);
    goto L_801733c8;
L_80173154:
    r9 = L32(r1 + 8);
    r11 = 0x1u;
    r8 = L32(r31);
    r10 = ROTL(r9, 29) & 0x1ffffffcu;
    r0 = L32(r8 + r10);
    r9 = r9 & 0x1fu;
    r11 = SLW(r11, r9);
    r0 = r0 | r11;
    S32(r8 + r10, r0);
    r11 = L32(r29 + 100);
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801731a0;
    r9 = L16(r11 + 28);
    r20 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801731b4;
L_801731a0:
    r3 = r26;
    r5 = 0x1u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r20 = r3;
L_801731b4:
    r11 = L32(r29 + 64);
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801731dc;
    r9 = L16(r11 + 28);
    r31 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801731f0;
L_801731dc:
    r3 = r23;
    r5 = 0xcu;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r31 = r3;
L_801731f0:
    r11 = L32(r29 + 88);
    r0 = L16(r11 + 4);
    r23 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80173218;
    r9 = L16(r11 + 28);
    r24 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_80173230;
L_80173218:
    r3 = r24;
    r4 = r23;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r24 = r3;
L_80173230:
    r11 = L32(r29 + 96);
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80173258;
    r9 = L16(r11 + 28);
    r22 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8017326c;
L_80173258:
    r3 = r16;
    r5 = 0x1u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r22 = r3;
L_8017326c:
    r11 = L32(r29 + 84);
    r0 = L16(r11 + 4);
    r26 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80173294;
    r9 = L16(r11 + 28);
    r30 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801732ac;
L_80173294:
    r3 = r19;
    r4 = r26;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r30 = r3;
L_801732ac:
    r11 = L32(r29 + 68);
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801732d4;
    r9 = L16(r11 + 28);
    r3 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801732e4;
L_801732d4:
    r3 = r15;
    r5 = 0x8u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_801732e4:
    r0 = L8(r21 + 4);
    r27 = r3;
    cr7 = CMPS(r23, 0);
    r0 = r0 & 0xfbu; cr0 = CMPS(r0, 0);
    S8(r21 + 4, r0);
    if ((cr7 & 2)) goto L_80173310;
    r0 = L32(r1 + 8);
    r9 = D(0x803a0000u);
    f0 = LF(D(0x803a66f4u));
    r0 = r0 << 2;
    SF(r24 + r0, f0);
L_80173310:
    cr0 = CMPS(r26, 0);
    if ((cr0 & 2)) goto L_80173338;
    r9 = L32(r1 + 8);
    r0 = 0xffffffffu;
    r9 = r9 << 2;
    S8(r9 + r30, r0);
    r9 = r9 + r30;
    S8(r9 + 3, r0);
    S8(r9 + 1, r0);
    S8(r9 + 2, r0);
L_80173338:
    r9 = L32(r1 + 8);
    r0 = 0x0u;
    r11 = D(0x803a0000u);
    S8(r20 + r9, r0);
    r6 = 0x43300000u;
    f0 = LF(D(0x803a66f4u));
    r0 = 0x1u;
    r9 = L32(r1 + 8);
    r11 = D(0x803a0000u);
    f12 = LD(D(0x803a66f8u));
    r7 = r8;
    r9 = (w3d_s32)r9 * 12;
    r10 = D(0x803a0000u);
    f11 = LF(D(0x803a6700u));
    { w3d_u32 t_ = r9 + r31; SF(t_, f0); r9 = t_; }
    SF(r9 + 8, f0);
    SF(r9 + 4, f0);
    r11 = L32(r1 + 8);
    S8(r22 + r11, r0);
    r9 = L16(r25 + 40);
    r0 = L16(r25 + 42);
    r9 = r9 ^ 0x80000000u;
    r11 = L32(r1 + 8);
    S32(r1 + 52, r9);
    r0 = r0 ^ 0x80000000u;
    r11 = r11 << 3;
    S32(r1 + 48, r6);
    r9 = r11 + r27;
    f13 = LDS(r1 + 48);
    S32(r1 + 52, r0);
    f13 = f13 - f12;
    S32(r1 + 48, r6);
    f13 = (float)f13;
    f13 = (float)(f13 * f11);
    f0 = LDS(r1 + 48);
    SF(r11 + r27, f13);
L_801733c8:
    f0 = f0 - f12;
    f0 = (float)f0;
    f0 = (float)(f0 * f11);
    SF(r9 + 4, f0);
    r0 = L8(r21 + 4);
    r9 = D(0x803a0000u);
    f0 = LF(D(0x803a66f4u));
    r3 = r25;
    r0 = r0 & 0xfbu; cr0 = CMPS(r0, 0);
    r4 = r18;
    S8(r21 + 4, r0);
    r9 = L32(r1 + 8);
    r10 = L32(r1 + 32);
    r9 = r9 << 3;
    f12 = LF(r9 + r27);
    r9 = r9 + r27;
    r11 = L16(r10); /* PPC lee la mitad baja del índice en +2: en el anfitrión está en +0 */
    f13 = LF(r9 + 4);
    SF(r28 + 36, f12);
    SF(r14 + 4, f13);
    SF(r14 + 8, f0);
    SF(r28 + 12, f0);
    r9 = L32(r1 + 36);
    SF(r9 + 8, f0);
    SF(r9 + 4, f0);
    SF(r28 + 24, f0);
    r10 = L32(r1 + 40);
    SF(r10 + 8, f0);
    SF(r10 + 4, f0);
    S32(r28 + 124, r11);
    r0 = L32(r28 + 8);
    r0 = r0 | 0x1u;
    S32(r28 + 8, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80172050)(W(r3), W(r4));
    r31 = r3; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_8017346c;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8017346c:
    r3 = L32(r28 + 128);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80173488;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80173488:
    r0 = 0xffffffffu;
    S32(r28 + 128, r31);
    S8(r28 + 120, r0);
    r11 = 0x0u;
    S8(r17 + 3, r0);
    r9 = 0x0u;
    S8(r17 + 1, r0);
    r3 = 0x0u;
    S8(r17 + 2, r0);
    S32(r28 + 48, r9);
    S8(r28 + 132, r11);
    r1 = r1 + 128;
    return r3;
}

// 0x80174050 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80174050(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80174074)(W(r3));
    r3 = L32(r3 + 60);
    r1 = r1 + 8;
    return r3;
}

// 0x80175974 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80175974(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034bf50)(W(r3), W(r4), W(r5), W(r6), W(r7));
    r1 = r1 + 8;
    return r3;
}

// 0x80175994 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80175994(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034c148)(W(r3), W(r4), W(r5), W(r6), W(r7));
    r1 = r1 + 8;
    return r3;
}

// 0x801759b4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801759b4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, float s1) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, float, w3d_oarg, w3d_oarg))A8034c340)(W(r3), W(r4), (float)f1, W(r5), W(r6));
    r1 = r1 + 8;
    return r3;
}

// 0x801759d4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801759d4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034c538)(W(r3), W(r4), W(r5), W(r6), W(r7));
    r1 = r1 + 8;
    return r3;
}

// 0x801759f4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801759f4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034c730)(W(r3), W(r4), W(r5), W(r6), W(r7));
    r1 = r1 + 8;
    return r3;
}

// 0x80175a14 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80175a14(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034c928)(W(r3), W(r4), W(r5), W(r6), W(r7));
    r1 = r1 + 8;
    return r3;
}

// 0x80176814 FUN_80176814 no verificada: desde bytes PPC
// Llama a sol35f7a_pool_allocate, native_forward_copy, handle_storage_release. Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A80176814(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r30 = r4;
    r29 = r3;
    r9 = L16(r30 + 8);
    r11 = 0xaaaa0000u;
    r10 = L32(r29 + 24);
    r11 = 0xaaaaaaabu;
    r9 = r9 << 2;
    r0 = L32(r29 + 2096);
    r3 = L32(r9 + r10);
    r0 = r30 - r0;
    r27 = r1 + 8;
    r9 = L32(r3);
    r0 = (w3d_s32)r0 * (w3d_s32)r11;
    r31 = r29 + 2104;
    r9 = L32(r9 + 60);
    lr = r9;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 3); ca = SRAWCA(t_, 3); }
    S32(r1 + 8, r0);
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = 0x0u;
    r9 = 0xffffffffu;
    S32(r30 + 16, r0);
    r28 = r3;
    S16(r30 + 8, r9);
    S32(r30 + 4, r0);
    S32(r30 + 12, r0);
    r11 = L32(r31 + 4);
    r0 = L32(r31 + 8);
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_80176944;
    r9 = L32(r29 + 2104);
    r8 = r1 + 16;
    r10 = r1 + 12;
    r9 = r11 - r9;
    r0 = r9 >> 1;
    r11 = r9 + 1;
    r0 = r9 + r0;
    S32(r1 + 24, r9);
    cr0 = CMPS(r11, r0);
    S32(r1 + 12, r11);
    S32(r1 + 16, r0);
    if (!(cr0 & 8)) goto L_801768d0;
    r10 = r8;
L_801768d0:
    r0 = L32(r10);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 20, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r29 + 2104);
    r30 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80176928;
    r9 = L32(r1 + 20);
    r11 = r1 + 24;
    r0 = L32(r1 + 24);
    r5 = r1 + 20;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80176910;
    r5 = r11;
L_80176910:
    r5 = L32(r5);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r29 + 2104);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80176928:
    r9 = L32(r1 + 24);
    S32(r31, r30);
    r9 = r30 + r9;
    S32(r31 + 4, r9);
    r0 = L32(r1 + 20);
    r0 = r30 + r0;
    S32(r31 + 8, r0);
L_80176944:
    r0 = L32(r27);
    r3 = r28;
    r11 = L32(r31 + 4);
    S32(r11, r0);
    r9 = L32(r31 + 4);
    r9 = r9 + 4;
    S32(r31 + 4, r9);
    r1 = r1 + 56;
    return r3;
}

// 0x801792a4 FUN_801792a4 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: update_kind6. Llama a fetch, item_refresh. Hace 7 llamadas virtuales.
__attribute__((weak)) w3d_u32 A801792a4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r31 = r4;
    r9 = L32(r29 + 4);
    r3 = L32(r9 + 28);
    S32(r1 + 8, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801792e0;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801792e0:
    r4 = L32(r31);
    r0 = L32(r1 + 8);
    cr0 = CMPS(r0, r4);
    if (!(cr0 & 2)) goto L_80179304;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8017938c;
    r9 = L32(r4);
    r3 = r4;
    goto L_80179380;
L_80179304:
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80179318;
    r30 = L32(r29 + 4);
    r3 = r4;
    goto L_8017939c;
L_80179318:
    cr0 = CMPS(r4, 0);
    if (!(cr0 & 2)) goto L_8017933c;
    r9 = L32(r29 + 4);
    r3 = L32(r9 + 28);
    S32(r9 + 28, r4);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801793dc;
    r9 = L32(r3);
    goto L_801793d0;
L_8017933c:
    r3 = L32(D(0x804b015cu));
    r9 = L32(r3);
    r0 = L32(r9 + 48);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(D(0x804b015cu));
    r4 = L32(r1 + 8);
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80179394;
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8017938c;
    r9 = L32(r3);
L_80179380:
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8017938c:
    r3 = 0x1u;
    goto L_80179408;
L_80179394:
    r3 = L32(r31);
    r30 = L32(r29 + 4);
L_8017939c:
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801ea470)(W(r3));
    r31 = L32(r30 + 28);
    cr0 = CMPS(r3, 0);
    S32(r30 + 28, r3);
    if ((cr0 & 2)) goto L_801793c0;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801793c0:
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_801793dc;
    r9 = L32(r31);
    r3 = r31;
L_801793d0:
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801793dc:
    r3 = r29;
    r3 = CU(A80178b5c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r31 = r3;
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80179404;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80179404:
    r3 = r31;
L_80179408:
    r1 = r1 + 32;
    return r3;
}

// 0x80179aec heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80179aec(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r0 = 0, r30 = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80185af0)(W(r3), W(r4), W(r5));
    r0 = 0x1u;
    r3 = 0x0u;
    S32(r30 + 164, r0);
    r1 = r1 + 16;
    return r3;
}

// 0x8017d288 FUN_8017d288 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A8017d288(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x8017d288u);
    r3 = 0x0u;
    return r3;
}

// 0x801817e0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801817e0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 196);
    r9 = L32(r3);
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x80181d00 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80181d00(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 196);
    r9 = L32(r3);
    r0 = L32(r9 + 52);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8018d660 FUN_8018d660 no verificada: desde bytes PPC
// Llama a task_deferred_clear, sol35f7a_pool_header_release, handle_object, large_reserve_string_init, large_reserve_string_header. Hace 35 llamadas virtuales.
__attribute__((weak)) w3d_u32 A8018d660(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[136];
    w3d_u32 r1 = h2g(frame) + 120;
    w3d_u32 r0 = 0, r11 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 120; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r29 = r4;
    r3 = L32(r31 + 196);
    r30 = 0x0u;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d698;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d698:
    r3 = r31 + 224;
    S32(r31 + 196, r30);
    r23 = r3;
    ((void (*)(w3d_oarg))A80210afc)(W(r3));
    r3 = r31 + 212;
    r24 = r3;
    ((void (*)(w3d_oarg))A80210afc)(W(r3));
    r3 = r31 + 200;
    r25 = r3;
    ((void (*)(w3d_oarg))A80210afc)(W(r3));
    r11 = L32(r29);
    r0 = L16(r11 - 4);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8018d718;
    r30 = D(0x804b0000u);
    r10 = L32(D(0x804b06a0u));
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r31 + 248);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8018d708;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_8018d708:
    r0 = L32(D(0x804b06a0u));
    r3 = 0x0u;
    S32(r31 + 248, r0);
    goto L_8018dc84;
L_8018d718:
    r9 = L16(r11 - 6);
    r9 = r9 + 1;
    S16(r11 - 6, r9);
    r11 = L32(r31 + 248);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8018d748;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_8018d748:
    r0 = L32(r29);
    r4 = r29;
    S32(r1 + 8, r30);
    r5 = r1 + 8;
    S32(r31 + 248, r0);
    r6 = 0xffu;
    r3 = L32(D(0x804ab5fcu));
    r9 = L32(r3);
    r0 = L32(r9 + 136);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 8)) goto L_8018dba4;
    r3 = L32(r1 + 8);
    ((void (*)())A80343584)();
    S32(r1 + 16, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d7a0;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d7a0:
    r30 = L32(r1 + 16);
    r3 = L32(r30 + 188);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d7c0;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d7c0:
    r3 = L32(r31 + 196);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d7dc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d7dc:
    r9 = L32(r30 + 188);
    S32(r31 + 196, r9);
    r3 = r9;
    r11 = L32(r9);
    r0 = L32(r11 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r3 + 8);
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_8018d8ac;
    r3 = r1 + 24;
    r30 = r3;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r29);
    r3 = r1 + 24;
    S32(r1 + 24, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 24;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 24;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r4 = 0x0u;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bcc0)(W(r3), W(r4));
    r4 = r30;
    r3 = r31;
    r3 = A8018d660(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d884;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d884:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d8a0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d8a0:
    r3 = 0x80000000u;
    r3 = 0x80004005u;
    goto L_8018dc84;
L_8018d8ac:
    r3 = r31;
    r26 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8018ca1c)(W(r3));
    r27 = r3;
    r3 = r23;
    r4 = r27;
    ((void (*)(w3d_oarg, w3d_oarg))A80210b90)(W(r3), W(r4));
    r3 = r24;
    r4 = r27;
    ((void (*)(w3d_oarg, w3d_oarg))A80210b90)(W(r3), W(r4));
    r3 = r25;
    r4 = r27;
    ((void (*)(w3d_oarg, w3d_oarg))A80210b90)(W(r3), W(r4));
    cr0 = CMPU(r26, r27);
    if (!(cr0 & 8)) goto L_8018dc48;
    r28 = r1 + 56;
    r29 = 0x0u;
    r19 = D(0x80410000u);
    r21 = D(0x80410000u);
    r20 = D(0x80410000u);
    r22 = D(0x80410000u);
L_8018d900:
    r3 = D(0x804144f8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    S32(r1 + 24, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d924;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d924:
    r3 = D(0x80414940u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    S32(r1 + 32, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d948;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d948:
    r3 = D(0x80413368u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    S32(r1 + 40, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d96c;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d96c:
    r3 = D(0x80413418u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    S32(r1 + 48, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d990;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d990:
    r3 = L32(r1 + 32);
    r30 = L32(r25 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d9b0;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d9b0:
    r3 = L32(r29 + r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d9cc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d9cc:
    r0 = L32(r1 + 32);
    S32(r29 + r30, r0);
    r3 = L32(r1 + 40);
    r30 = L32(r24 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018d9f4;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018d9f4:
    r3 = L32(r29 + r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018da10;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018da10:
    r0 = L32(r1 + 40);
    S32(r29 + r30, r0);
    r3 = L32(r1 + 48);
    r30 = L32(r23 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018da38;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018da38:
    r3 = L32(r29 + r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018da54;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018da54:
    r0 = L32(r1 + 48);
    S32(r29 + r30, r0);
    r9 = L32(r1 + 24);
    r3 = L32(r1 + 32);
    r30 = L32(r9 + 48);
    cr0 = CMPS(r3, 0);
    S32(r9 + 48, r3);
    if ((cr0 & 2)) goto L_8018da84;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018da84:
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_8018daa0;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018daa0:
    r3 = L32(r1 + 40);
    r4 = L32(r31 + 196);
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 48);
    r4 = L32(r1 + 40);
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 40);
    r4 = L32(r1 + 24);
    r9 = L32(r3);
    r0 = L32(r9 + 40);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3; cr0 = CMPS(r30, 0);
    if (!(cr0 & 8)) goto L_8018dbc8;
    r4 = 0x0u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bcc0)(W(r3), W(r4));
    r4 = r28;
    r3 = r31;
    r3 = A8018d660(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r28;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r28;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 48);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018db34;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018db34:
    r3 = L32(r1 + 40);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018db50;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018db50:
    r3 = L32(r1 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018db6c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018db6c:
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018db88;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018db88:
    r3 = L32(r1 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dba4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dba4:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dbc0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dbc0:
    r3 = r30;
    goto L_8018dc84;
L_8018dbc8:
    r3 = L32(r1 + 48);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dbe4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dbe4:
    r3 = L32(r1 + 40);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dc00;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dc00:
    r3 = L32(r1 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dc1c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dc1c:
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dc38;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dc38:
    r26 = r26 + 1;
    r29 = r29 + 4;
    cr0 = CMPU(r26, r27);
    if ((cr0 & 8)) goto L_8018d900;
L_8018dc48:
    r3 = L32(r1 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dc64;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dc64:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8018dc80;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8018dc80:
    r3 = 0x0u;
L_8018dc84:
    r1 = r1 + 120;
    return r3;
}

// 0x8018dc98 FUN_8018dc98 no verificada: desde bytes PPC
// Llama a array_ref_lock, as_font. Hace 1 llamada virtual. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8018dc98(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[152];
    w3d_u32 r1 = h2g(frame) + 136;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 136; S32(t_, r1); r1 = t_; }
    r27 = r3;
    r9 = L32(r27 + 172);
    r0 = L32(r27 + 224);
    r11 = L32(r9 + 64);
    r3 = r9 + 64;
    r25 = L32(r27 + 232);
    r0 = r0 << 2;
    r9 = L16(r11 + 4);
    r23 = L32(r11 + 24);
    r22 = r25 + r0;
    r24 = L32(r27 + 208);
    cr0 = CMPS(r9, 1);
    r26 = L32(r27 + 252);
    r29 = L32(r27 + 264);
    if (!(cr0 & 2)) goto L_8018dd00;
    r9 = L16(r11 + 28);
    r3 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8018dd10;
L_8018dd00:
    r4 = r23;
    r5 = 0xcu;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8018dd10:
    r9 = L32(r27 + 172);
    r31 = r3;
    r10 = L32(r9 + 68);
    r3 = r9 + 68;
    r0 = L16(r10 + 4);
    r4 = L32(r10 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8018dd44;
    r9 = L16(r10 + 28);
    r3 = r10 + 32;
    r9 = r9 + 1;
    S16(r10 + 28, r9);
    goto L_8018dd50;
L_8018dd44:
    r5 = 0x8u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_8018dd50:
    r9 = L32(r27 + 172);
    r30 = r3;
    r11 = L32(r9 + 76);
    r3 = r9 + 76;
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8018dd84;
    r9 = L16(r11 + 28);
    r0 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_8018dd94;
L_8018dd84:
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r0 = r3;
L_8018dd94:
    r11 = L32(r27);
    r9 = D(0x803a0000u);
    f12 = LF(D(0x803a7e98u));
    r3 = r27;
    r9 = L32(r11 + 64);
    r28 = r0;
    f0 = LF(r27 + 36);
    lr = r9;
    f13 = LF(r27 + 40);
    f30 = (float)(f12 / f0);
    f31 = (float)(f12 / f13);
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    ((void (*)())A8034435c)();
    f12 = LF(r3 + 44);
    r9 = D(0x803a0000u);
    f0 = LF(r3 + 48);
    r10 = r1 + 8;
    f13 = LF(D(0x803a7e9cu));
    r4 = r23 >> 1;
    SF(r1 + 8, f12);
    cr0 = CMPS(r25, r22);
    SF(r10 + 4, f0);
    SF(r10 + 8, f13);
    if ((cr0 & 2)) goto L_8018df84;
    r23 = r10;
    r21 = r4 << 2;
    r12 = r4 << 3;
    r3 = r1 + 24;
L_8018de04:
    r7 = L32(r24);
    r0 = L32(r27 + 240);
    r6 = r7 + 84;
    r8 = r7 + 96;
    r5 = r7 + 72;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8018df08;
    r9 = (w3d_s32)r4 * 12;
    f13 = LF(r26);
    f12 = LF(r7 + 96);
    r10 = r12 + r30;
    f11 = LF(r8 + 8);
    f12 = __builtin_fmaf((float)f12, (float)f30, (float)f13);
    f0 = LF(r8 + 4);
    f13 = LF(r26 + 4);
    r11 = r9;
    { w3d_u32 t_ = r9 + r31; SF(t_, f12); r9 = t_; }
    f0 = __builtin_fmaf((float)f0, (float)f31, (float)f13);
    SF(r9 + 8, f11);
    SF(r9 + 4, f0);
    { w3d_u32 t_ = r11 + r31; f12 = LF(t_); r11 = t_; }
    f13 = LF(r1 + 8);
    f0 = LF(r23 + 4);
    f11 = LF(r23 + 8);
    f12 = (float)(f12 + f13);
    SF(r1 + 40, f12);
    f13 = LF(r11 + 4);
    f13 = (float)(f13 + f0);
    SF(r1 + 44, f13);
    f0 = LF(r11 + 8);
    SF(r1 + 24, f12);
    f0 = (float)(f0 + f11);
    SF(r1 + 28, f13);
    SF(r1 + 32, f0);
    SF(r1 + 48, f0);
    r0 = L32(r1 + 24);
    r9 = L32(r3 + 4);
    r11 = L32(r3 + 8);
    S32(r31, r0);
    S32(r31 + 4, r9);
    S32(r31 + 8, r11);
    r31 = r31 + 12;
    f0 = LF(r6 + 8);
    SF(r21 + r28, f0);
    f13 = LF(r6 + 8);
    SF(r28, f13);
    r28 = r28 + 4;
    f12 = LF(r29);
    f0 = LF(r7 + 72);
    f11 = LF(r29 + 4);
    f13 = LF(r5 + 4);
    f0 = (float)(f0 * f12);
    SF(r12 + r30, f0);
    f13 = (float)(f13 * f11);
    SF(r10 + 4, f13);
    f0 = LF(r7 + 72);
    f13 = LF(r5 + 4);
    f12 = LF(r29);
    f11 = LF(r29 + 4);
    f0 = (float)(f0 * f12);
    f13 = (float)(f13 * f11);
    SF(r30, f0);
    SF(r30 + 4, f13);
    r30 = r30 + 8;
    goto L_8018df6c;
L_8018df08:
    f12 = LF(r26 + 4);
    r9 = r31;
    f0 = LF(r7 + 96);
    r11 = r30;
    f10 = LF(r26);
    r31 = r31 + 12;
    f13 = LF(r8 + 4);
    r30 = r30 + 8;
    f11 = LF(r8 + 8);
    f0 = __builtin_fmaf((float)f0, (float)f30, (float)f10);
    f13 = __builtin_fmaf((float)f13, (float)f31, (float)f12);
    SF(r9, f0);
    SF(r9 + 8, f11);
    SF(r9 + 4, f13);
    f0 = LF(r6 + 8);
    SF(r28, f0);
    r28 = r28 + 4;
    f0 = LF(r7 + 72);
    f13 = LF(r5 + 4);
    f12 = LF(r29);
    f11 = LF(r29 + 4);
    f0 = (float)(f0 * f12);
    f13 = (float)(f13 * f11);
    SF(r11, f0);
    SF(r11 + 4, f13);
L_8018df6c:
    r25 = r25 + 4;
    r24 = r24 + 4;
    r26 = r26 + 8;
    r29 = r29 + 8;
    cr0 = CMPS(r25, r22);
    if (!(cr0 & 2)) goto L_8018de04;
L_8018df84:
    r1 = r1 + 136;
    return r3;
}

// 0x80196a54 FUN_80196a54 no verificada: desde bytes PPC
// Llama a modff, curve_evaluate_nearest. Mucho cálculo en coma flotante.
__attribute__((weak)) float A80196a54(w3d_u32 r3, w3d_u32 r4, float s1) {
    alignas(16) char frame[104];
    w3d_u32 r1 = h2g(frame) + 88;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f11 = 0, f12 = 0, f13 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0;
    { w3d_u32 t_ = r1 - 88; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r9 = D(0x803b0000u);
    r11 = L32(r31);
    f28 = f1;
    r30 = r4;
    f11 = LF(D(0x803a84e4u));
    cr0 = CMPS(r11, 0);
    if ((cr0 & 2)) goto L_80196cc8;
    r9 = L16(r11 + 8);
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_80196cc8;
    r9 = (w3d_s32)r9 * 24;
    r11 = L32(r11 + 4);
    f29 = LF(r11);
    r9 = r9 - 24;
    f30 = LF(r11 + r9);
    f31 = (float)(f30 - f29);
    cr0 = CMPF(f31, f11);
    if (!(cr0 & 2)) goto L_80196ac8;
    f1 = LF(r11 + 4);
    goto L_80196ccc;
L_80196ac8:
    cr0 = CMPF(f28, f30);
    if (!(cr0 & 4)) goto L_80196ad8;
    f1 = (float)(f28 - f30);
    goto L_80196adc;
L_80196ad8:
    f1 = (float)(f28 - f29);
L_80196adc:
    r3 = r1 + 8;
    f1 = (float)(f1 / f31);
    f1 = ((float (*)(float, w3d_oarg))A802e8b7c)((float)f1, W(r3));
    f1 = __builtin_fabs(f1);
    f0 = LF(r1 + 8);
    r9 = D(0x803b0000u);
    f13 = LF(D(0x803a84e8u));
    cr0 = CMPS(r30, 0);
    f0 = __builtin_fabs(f0);
    r30 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    f0 = (float)(f0 + f13);
    f31 = (float)(f31 * f1);
    SF(r1 + 8, f0);
    if ((cr0 & 2)) goto L_80196b98;
    r11 = L32(r31);
    r0 = L32(r11);
    r9 = ROTL(r0, 7) & 0x7u;
    cr0 = CMPS(r9, 4);
    if (!(cr0 & 2)) goto L_80196b50;
    r9 = D(0x803b0000u);
    r3 = r1 + 12;
    f1 = LF(D(0x803a84ecu));
    f1 = (float)(f0 * f1);
    f1 = ((float (*)(float, w3d_oarg))A802e8b7c)((float)f1, W(r3));
    r9 = D(0x803b0000u);
    f0 = LF(D(0x803a84e4u));
    cr0 = CMPF(f1, f0);
    if (!(cr0 & 2)) goto L_80196be4;
    goto L_80196bd0;
L_80196b50:
    r0 = r9 - 2;
    cr0 = CMPU(r0, 0x1u);
    if (!(cr0 & 4)) goto L_80196bd0;
    cr0 = CMPS(r9, 1);
    if (!(cr0 & 2)) goto L_80196c38;
    r9 = L32(r11 + 4);
    f31 = (float)(f29 - f28);
    r11 = D(0x803b0000u);
    f0 = LF(D(0x803a84e4u));
    f1 = LF(r9 + 8);
    f11 = LF(r9 + 4);
    cr0 = CMPF(f1, f0);
    f0 = LF(r9 + 12);
    if ((cr0 & 2)) goto L_80196cc8;
    f0 = (float)(f31 * f0);
    f0 = (float)(f0 / f1);
    f11 = (float)(f11 - f0);
    goto L_80196cc8;
L_80196b98:
    r11 = L32(r31);
    r0 = L32(r11);
    r9 = ROTL(r0, 10) & 0x7u;
    cr0 = CMPS(r9, 4);
    if (!(cr0 & 2)) goto L_80196bd8;
    r9 = D(0x803b0000u);
    r3 = r1 + 12;
    f1 = LF(D(0x803a84ecu));
    f1 = (float)(f0 * f1);
    f1 = ((float (*)(float, w3d_oarg))A802e8b7c)((float)f1, W(r3));
    r9 = D(0x803b0000u);
    f0 = LF(D(0x803a84e4u));
    cr0 = CMPF(f1, f0);
    if ((cr0 & 2)) goto L_80196be4;
L_80196bd0:
    f31 = (float)(f30 - f31);
    goto L_80196c38;
L_80196bd8:
    r0 = r9 - 2;
    cr0 = CMPU(r0, 0x1u);
    if ((cr0 & 4)) goto L_80196bec;
L_80196be4:
    f31 = (float)(f31 + f29);
    goto L_80196c38;
L_80196bec:
    cr0 = CMPS(r9, 1);
    if (!(cr0 & 2)) goto L_80196c38;
    r9 = L16(r11 + 8);
    r10 = D(0x803b0000u);
    r11 = L32(r11 + 4);
    f31 = (float)(f28 - f30);
    r9 = (w3d_s32)r9 * 24;
    f0 = LF(D(0x803a84e4u));
    r9 = r9 - 24;
    r11 = r11 + r9;
    f1 = LF(r11 + 16);
    f11 = LF(r11 + 4);
    cr0 = CMPF(f1, f0);
    f0 = LF(r11 + 20);
    if ((cr0 & 2)) goto L_80196cc8;
    f0 = (float)(f31 * f0);
    f0 = (float)(f0 / f1);
    f11 = (float)(f11 + f0);
    goto L_80196cc8;
L_80196c38:
    f1 = f31;
    r3 = r31;
    f1 = ((float (*)(w3d_oarg, float))A80196cf0)(W(r3), (float)f1);
    f11 = f1;
    cr0 = (r30 >> 28) & 15;
    if ((cr0 & 2)) goto L_80196c90;
    r3 = L32(r31);
    r0 = L32(r3);
    r0 = ROTL(r0, 7) & 0x7u;
    cr0 = CMPS(r0, 3);
    if (!(cr0 & 2)) goto L_80196cc8;
    r9 = L16(r3 + 8);
    r11 = L32(r3 + 4);
    r9 = (w3d_s32)r9 * 24;
    f13 = LF(r1 + 8);
    f12 = LF(r11 + 4);
    r9 = r9 + r11;
    f0 = LF(r9 - 20);
    f0 = (float)(f0 - f12);
    f13 = (float)(f13 * f0);
    f11 = (float)(f11 - f13);
    goto L_80196cc8;
L_80196c90:
    r3 = L32(r31);
    r0 = L32(r3);
    r0 = ROTL(r0, 10) & 0x7u;
    cr0 = CMPS(r0, 3);
    if (!(cr0 & 2)) goto L_80196cc8;
    r9 = L16(r3 + 8);
    r11 = L32(r3 + 4);
    r9 = (w3d_s32)r9 * 24;
    f12 = LF(r1 + 8);
    f13 = LF(r11 + 4);
    r9 = r9 + r11;
    f0 = LF(r9 - 20);
    f0 = (float)(f0 - f13);
    f11 = __builtin_fmaf((float)f12, (float)f0, (float)f11);
L_80196cc8:
    f1 = f11;
L_80196ccc:
    r1 = r1 + 88;
    return (float)f1;
}

// 0x80199ff0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80199ff0(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8019a2a8)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x8019fdd8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 802ce30c en 8019fdf8
__attribute__((weak)) w3d_u32 A8019fdd8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r30 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r3 = A8019fe48(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = L32(r30 + 24);
    r4 = 0xffffd8f0u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802ce30c)(W(r3), W(r4), W(r5));
    r1 = r1 + 16;
    return r3;
}

// 0x8019fe10 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 802ce30c en 8019fe30
__attribute__((weak)) w3d_u32 A8019fe10(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r30 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r3 = A8019fe48(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = L32(r30 + 28);
    r4 = 0xffffd8f0u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802ce30c)(W(r3), W(r4), W(r5));
    r1 = r1 + 16;
    return r3;
}

// 0x8019fe48 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8019fe48(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 36);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801a3628 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801a3628(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801a2350)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x801a45b0 FUN_801a45b0 no verificada: desde bytes PPC
// Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A801a45b0(w3d_u32 r3, w3d_u32 r4, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = L32(r4 + 24);
    r7 = 0x1u;
    r6 = r3;
    r9 = ROTL(r11, 9) & 0xffu;
    { w3d_u32 t_ = r11; r5 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r9 = r9 - 127;
    r11 = r11 & 0x7fffffu;
    { w3d_u32 t_ = r9; r8 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r10 = r11 | 0x800000u;
    r8 = ~(r8 | r8);
    r10 = r10 << 8;
    r0 = r9 & r8;
    r11 = r11 << 8;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)31 - t_; ca = ((w3d_u32)31 >= t_); }
    { w3d_u32 t_ = r9; r9 = (w3d_u32)31 - t_; ca = ((w3d_u32)31 >= t_); }
    r7 = SLW(r7, r0);
    r10 = SRW(r10, r9);
    r8 = r10 & r8;
    r7 = r7 - 1;
    r8 = r8 ^ r5;
    r0 = r11 & r7; cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_801a4618;
    r8 = r8 - r5;
L_801a4618:
    r0 = 0x0u;
    r10 = r8;
    S32(r1 + 12, r0);
    cr0 = CMPS(r10, 0);
    S32(r1 + 8, r10);
    r0 = r1 + 12;
    r9 = r1 + 8;
    if (!(cr0 & 8)) goto L_801a463c;
    r9 = r0;
L_801a463c:
    r10 = L32(r9);
    r11 = L32(r6 + 20);
    S32(r1 + 16, r10);
    r9 = L32(r11 + 44);
    r8 = r9 + 32;
    r9 = L32(r9 + 24);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801a4664;
    r3 = 0x0u;
    goto L_801a46ac;
L_801a4664:
    r0 = r9 - 1;
    r11 = r1 + 20;
    cr0 = CMPU(r10, r0);
    S32(r1 + 20, r0);
    r9 = r1 + 16;
    if (!(cr0 & 4)) goto L_801a4680;
    r9 = r11;
L_801a4680:
    r0 = L32(r9);
    r3 = r6;
    r11 = L32(r6 + 24);
    S32(r1 + 16, r0);
    r0 = r0 << 2;
    r4 = L32(r8 + r0);
    r9 = L16(r4 + 6);
    r9 = r9 << 2;
    r0 = L32(r9 + r11);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801a46ac:
    r1 = r1 + 24;
    return r3;
}

}
