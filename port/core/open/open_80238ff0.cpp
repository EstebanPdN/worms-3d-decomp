// Funciones del juego sin fuente admitida: 0x80238ff0 a 0x80299a74. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A800fc110();
__attribute__((weak)) void A800fc43c();
__attribute__((weak)) void A800fc550();
__attribute__((weak)) void A8015adf4();
__attribute__((weak)) void A8015f5a0();
__attribute__((weak)) void A80162024();
__attribute__((weak)) void A80164514();
__attribute__((weak)) void A80171ee0();
__attribute__((weak)) void A80171f90();
__attribute__((weak)) void A80171fa0();
__attribute__((weak)) void A80171ff8();
__attribute__((weak)) void A80173df0();
__attribute__((weak)) void A80173f88();
__attribute__((weak)) void A801790bc();
__attribute__((weak)) void A801797b4();
__attribute__((weak)) void A801e8d9c();
__attribute__((weak)) void A801ebf38();
__attribute__((weak)) void A801ed24c();
__attribute__((weak)) void A8020b680();
__attribute__((weak)) void A8020bb2c();
__attribute__((weak)) void A8020bb54();
__attribute__((weak)) void A8020bd38();
__attribute__((weak)) void A8020c3a0();
__attribute__((weak)) void A8020c510();
__attribute__((weak)) void A8020c5c0();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A8025fd78();
__attribute__((weak)) void A8026026c();
__attribute__((weak)) void A80262a58();
__attribute__((weak)) void A80263608();
__attribute__((weak)) void A80263bb8();
__attribute__((weak)) void A80263e18();
__attribute__((weak)) void A80264348();
__attribute__((weak)) void A802644a8();
__attribute__((weak)) void A8026c96c();
__attribute__((weak)) void A8026cde8();
__attribute__((weak)) void A8026ce2c();
__attribute__((weak)) void A80280370();
__attribute__((weak)) void A80289eec();
__attribute__((weak)) void A8029d07c();
__attribute__((weak)) void A8029d578();
__attribute__((weak)) void A802aba0c();
__attribute__((weak)) void A802aba18();
__attribute__((weak)) void A802aba68();
__attribute__((weak)) void A802b0668();
__attribute__((weak)) void A802b1510();
__attribute__((weak)) void A802ed8c4();
__attribute__((weak)) void A802eefe0();
__attribute__((weak)) void A802ef380();
__attribute__((weak)) void A80341584();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A80341884();
__attribute__((weak)) void A803426b8();
__attribute__((weak)) void A8034357c();
__attribute__((weak)) void A80343744();
__attribute__((weak)) void A80343808();

// 0x80238ff0 FUN_80238ff0 no verificada: desde bytes PPC
// Llama a sol35f2_fill, create_member_binding, sol35e5a_register_string, large_reserve_string_init, large_reserve_string_header. Usa las cadenas "AppVersion".
__attribute__((weak)) w3d_u32 A80238ff0(w3d_u32 r3) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r0 = L32(D(0x804b082cu));
    r28 = r3;
    r31 = D(0x80460000u);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80239090;
    r30 = D(0x80464be4u);
    r4 = 0x0u;
    r3 = D(0x80464be4u);
    r5 = 0x28u;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eefe0)(W(r3), W(r4), W(r5));
    r9 = D(0x803c0000u);
    r10 = 0x1u;
    r9 = D(0x803bb1f4u);
    r11 = D(0x80460000u);
    S32(D(0x80464be4u), r9);
    r8 = 0x8u;
    S8(D(0x80464beau), r10);
    r11 = D(0x8045ed4cu);
    r0 = 0x1cu;
    S8(D(0x80464bebu), r8);
    r9 = 0x80240000u;
    S16(D(0x80464be8u), r0);
    r7 = 0xffffffffu;
    S32(D(0x80464becu), r11);
    r9 = FN(0x80240480u);
    r10 = 0x80240000u;
    r11 = L32(D(0x804af594u));
    r0 = 0x1u;
    S16(D(0x80464bfau), r7);
    r10 = FN(0x80240478u);
    S32(D(0x80464bfcu), r9);
    S32(D(0x804b082cu), r0);
    S16(D(0x80464c02u), r7);
    S32(D(0x80464c08u), r11);
    S32(D(0x80464c04u), r10);
L_80239090:
    r4 = D(0x80460000u);
    r31 = r1 + 8;
    r4 = D(0x80464be4u);
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801ebf38)(W(r3), W(r4));
    r30 = D(0x804b0000u);
    r4 = D(0x803c0000u);
    r3 = r28;
    r4 = D(0x803bb208u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801ed24c)(W(r3), W(r4));
    r29 = r3;
    r3 = r31;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(D(0x804b06a0u));
    r3 = r31;
    S32(r1 + 8, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r9 = L16(r3);
    r9 = r9 + 1;
    S16(r3, r9);
    r10 = L32(r1 + 8);
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r29 + 8);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80239114;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_80239114:
    r0 = L32(r1 + 8);
    r3 = r31;
    S32(r29 + 8, r0);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r31;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r28;
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 32;
    return r3;
}

// 0x80239664 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80239664(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x80239c84 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80239c84(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8023a074 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8023a074(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8023c820 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8023c820(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8023d600 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8023d600(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8023da74 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8023da74(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8025ee60 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8025ee60(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3);
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8025ee94 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8025ee94(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = r4;
    r5 = 0x0u;
    r11 = L32(r9);
    r4 = L32(r3);
    r0 = L32(r11 + 92);
    r3 = r9;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8025f064 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8025f064(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3);
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8025f524 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8025f524(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r3 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b0668)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x802602fc FUN_802602fc no verificada: desde bytes PPC
// Llama a large_reserve_string_init, large_reserve_string_header, text_default, sol35f7a_pool_header_release, strcspn. Hace 4 llamadas virtuales. Usa las cadenas "ERROR: Could not find resour".
// aviso: lee r3 tras void 80341588 en 802606d4
__attribute__((weak)) w3d_u32 A802602fc(w3d_u32 r3) {
    alignas(16) char frame[160];
    w3d_u32 r1 = h2g(frame) + 144;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f12 = 0, f13 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 144; S32(t_, r1); r1 = t_; }
    r30 = r1 + 8;
    r29 = r3;
    r20 = L32(r29 + 40);
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r23 = r30;
    r0 = L32(r20 + 124);
    r3 = r30;
    S32(r1 + 8, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r9 = L16(r3);
    r9 = r9 + 1;
    S16(r3, r9);
    r11 = L32(r1 + 8);
    r0 = L16(r11 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8026048c;
    r31 = r1 + 16;
    r30 = 0x2u;
    r22 = r31;
    r17 = r1 + 28;
L_80260368:
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r31 = r31 + 4;
    cr0 = CMPS(r30, 0);
    r30 = r30 - 1;
    if (!(cr0 & 2)) goto L_80260368;
    r9 = L32(r1 + 8);
    r24 = 0x0u;
    r0 = L16(r9 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80260454;
    r21 = D(0x803d0000u);
    r27 = r22 - 4;
    r25 = 0x0u;
    r28 = r23 + 8;
L_802603a4:
    r10 = L32(r1 + 8);
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r28);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802603d8;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_802603d8:
    r0 = L32(r1 + 8);
    cr0 = CMPS(r24, 3);
    S32(r28, r0);
    if ((cr0 & 2)) goto L_80260454;
    r9 = r1 + 12;
    r25 = r25 + 4;
    r31 = L32(r9 + r25);
    r4 = D(0x803cab9cu);
    r27 = r27 + 4;
    r28 = r28 + 4;
    r3 = r31;
    r24 = r24 + 1;
    r3 = CU(A802ef380, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3;
    r0 = L8(r31 + r30);
    cr0 = CMPS(r0, 44);
    if (!(cr0 & 2)) goto L_8026042c;
    r4 = r30;
    r3 = r27;
    ((void (*)(w3d_oarg, w3d_oarg))A8020c3a0)(W(r3), W(r4));
    r30 = r30 + 1;
L_8026042c:
    r31 = L32(r1 + 8);
    r3 = r23;
    r4 = r31 + r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r9 = L32(r1 + 8);
    r0 = L16(r9 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80260454;
    cr0 = CMPU(r24, 0x2u);
    if (!(cr0 & 4)) goto L_802603a4;
L_80260454:
    cr0 = CMPU(r24, 0x1u);
    if ((cr0 & 4)) goto L_802604a0;
    r3 = r29;
    r30 = r17;
    ((void (*)(w3d_oarg))A8025fd78)(W(r3));
    cr0 = CMPS(r22, r30);
    if ((cr0 & 2)) goto L_8026048c;
L_80260470:
    r30 = r30 - 4;
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    cr0 = CMPS(r22, r30);
    if (!(cr0 & 2)) goto L_80260470;
L_8026048c:
    r3 = r23;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r23;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_802606d8;
L_802604a0:
    r25 = 0x0u;
    cr0 = CMPU(r25, r24);
    if (!(cr0 & 8)) goto L_80260698;
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f30 = LF(D(0x803caba0u));
    r18 = r20 + 4;
    f31 = LF(D(0x803caba4u));
    r19 = r23 + 16;
    r31 = r1 + 32;
    r30 = r29 + 232;
    r21 = 0x0u;
    r28 = r23 + 8;
L_802604d4:
    cr0 = CMPS(r25, 1);
    r27 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    if ((cr0 & 2)) goto L_80260510;
    cr0 = CMPU(r25, 0x1u);
    if ((cr0 & 8)) goto L_802604f4;
    cr0 = CMPS(r25, 2);
    if ((cr0 & 2)) goto L_80260534;
    goto L_80260594;
L_802604f4:
    r0 = L32(r29 + 216);
    r3 = r29 + 28;
    r4 = L32(r28);
    r5 = r30;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80260574;
    goto L_80260580;
L_80260510:
    r0 = L32(r29 + 216);
    r3 = r29 + 28;
    r4 = L32(r1 + 20);
    r5 = r29 + 236;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80260574;
    r9 = L8(r29 + 32);
    r6 = r9 + 30;
    goto L_80260588;
L_80260534:
    r0 = L8(r18 + 4);
    r0 = r0 ^ 0x4u;
    r9 = r0 & 0x4u; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_8026055c;
    r6 = L8(r29 + 32);
    r3 = r29 + 28;
    r4 = L32(r19);
    r5 = r29 + 240;
    r6 = r6 + 32;
    goto L_80260588;
L_8026055c:
    r0 = L32(r29 + 216);
    r3 = r29 + 28;
    r4 = L32(r28);
    r5 = r30;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80260580;
L_80260574:
    r9 = L8(r29 + 32);
    r6 = r9 + 31;
    goto L_80260588;
L_80260580:
    r9 = L8(r29 + 32);
    r6 = r9 + 29;
L_80260588:
    r6 = r6 & 0xffu;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b1510)(W(r3), W(r4), W(r5), W(r6));
    r26 = r3;
L_80260594:
    cr0 = CMPS(r26, 0);
    if (!(cr0 & 8)) goto L_802605b8;
    r4 = D(0x803d0000u);
    r5 = L32(r1 + 8);
    r4 = D(0x803cab14u);
    r3 = r29 + 108;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    goto L_80260680;
L_802605b8:
    r3 = L32(r29 + 112);
    r5 = 0x0u;
    r4 = L32(r30);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = (r27 >> 28) & 15;
    if (!(cr0 & 2)) goto L_80260644;
    f12 = LF(r20 + 116);
    cr0 = CMPF(f12, f30);
    if (!(cr0 & 2)) goto L_80260600;
    r3 = L32(r29 + 236);
    r5 = 0x0u;
    r4 = L32(r29 + 40);
    r9 = L32(r3);
    r4 = r4 + 20;
    goto L_80260634;
L_80260600:
    r9 = L32(r29 + 40);
    r4 = r31;
    r11 = L32(r29 + 236);
    r5 = 0x0u;
    f0 = LF(r9 + 24);
    f13 = LF(r9 + 20);
    r3 = r11;
    f0 = (float)(f0 * f12);
    f13 = (float)(f13 * f12);
    SF(r1 + 36, f0);
    SF(r1 + 32, f13);
    SF(r31 + 8, f31);
    r9 = L32(r11);
L_80260634:
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_80260668;
L_80260644:
    r9 = r21 + r29;
    r4 = L32(r29 + 40);
    r3 = L32(r9 + 232);
    r5 = 0x0u;
    r4 = r4 + 20;
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80260668:
    r3 = L32(r30);
    r4 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80260680:
    r25 = r25 + 1;
    r30 = r30 + 4;
    r21 = r21 + 4;
    r28 = r28 + 4;
    cr0 = CMPU(r25, r24);
    if ((cr0 & 8)) goto L_802604d4;
L_80260698:
    r3 = r29;
    r30 = r17;
    ((void (*)(w3d_oarg))A8026026c)(W(r3));
    cr0 = CMPS(r22, r30);
    if ((cr0 & 2)) goto L_802606c8;
L_802606ac:
    r30 = r30 - 4;
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    cr0 = CMPS(r22, r30);
    if (!(cr0 & 2)) goto L_802606ac;
L_802606c8:
    r3 = r23;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r23;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
L_802606d8:
    r1 = r1 + 144;
    return r3;
}

// 0x802622fc FUN_802622fc no verificada: desde bytes PPC
// Llama a resource_property, identity, item_rename, cached_message_id, service_subscribe. Hace 11 llamadas virtuales. Usa las cadenas "FE.NextMenu", "FE.CurrentMenu", "FE.AnimSpeed".
// aviso: lee r3 tras void 80262a58 en 802629a4
__attribute__((weak)) w3d_u32 A802622fc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[176];
    w3d_u32 r1 = h2g(frame) + 160;
    w3d_u32 r0 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 160; S32(t_, r1); r1 = t_; }
    r9 = D(0x803d0000u);
    r4 = r1 + 8;
    r9 = D(0x803caeb8u);
    r31 = r3;
    r29 = 0x0u;
    r28 = r4;
    S32(r1 + 64, r9);
    r3 = r1 + 64;
    S32(r1 + 8, r29);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 8);
    ((void (*)())A80343744)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80262358;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80262358:
    r3 = L32(r31 + 36);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80262374;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80262374:
    r3 = L32(r1 + 8);
    S32(r31 + 36, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80262394;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80262394:
    r9 = D(0x803d0000u);
    r4 = r28;
    r9 = D(0x803caec4u);
    S32(r1 + 8, r29);
    S32(r1 + 68, r9);
    r3 = r1 + 68;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 8);
    ((void (*)())A80343744)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_802623d4;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802623d4:
    r3 = L32(r31 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802623f0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802623f0:
    r3 = L32(r1 + 8);
    S32(r31 + 32, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80262410;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80262410:
    r3 = L32(r31 + 32);
    r4 = D(0x803d0000u);
    r4 = D(0x803cac08u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801790bc)(W(r3), W(r4));
    r9 = L32(D(0x804aac54u));
    r4 = 0x1u;
    r3 = D(0x804b0984u);
    r0 = L32(r9 + 96);
    r0 = (ROTL(r29, 24) & 0x1000000u) | (r0 & 0xfeffffffu);
    S32(r9 + 96, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 72, r3);
    r4 = r1 + 72;
    r5 = r31 + 40;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b097cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 74, r3);
    r4 = r1 + 74;
    r5 = r31 + 44;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09acu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 76, r3);
    r4 = r1 + 76;
    r5 = r31 + 80;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b098cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 78, r3);
    r4 = r1 + 78;
    r5 = r31 + 48;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0994u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 80, r3);
    r4 = r1 + 80;
    r5 = r31 + 52;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b099cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 82, r3);
    r4 = r1 + 82;
    r5 = r31 + 56;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09a4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 84, r3);
    r4 = r1 + 84;
    r5 = r31 + 60;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09ccu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 86, r3);
    r4 = r1 + 86;
    r5 = r31 + 64;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09d4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 88, r3);
    r4 = r1 + 88;
    r5 = r31 + 68;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09bcu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 90, r3);
    r4 = r1 + 90;
    r5 = r31 + 72;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09c4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 92, r3);
    r4 = r1 + 92;
    r5 = r31 + 76;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a34u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 94, r3);
    r4 = r1 + 94;
    r5 = r31 + 84;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a2cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 96, r3);
    r4 = r1 + 96;
    r5 = r31 + 88;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a14u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 98, r3);
    r4 = r1 + 98;
    r5 = r31 + 124;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a1cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 100, r3);
    r4 = r1 + 100;
    r5 = r31 + 128;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a24u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 102, r3);
    r4 = r1 + 102;
    r5 = r31 + 132;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09dcu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 104, r3);
    r4 = r1 + 104;
    r5 = r31 + 112;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a04u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 106, r3);
    r4 = r1 + 106;
    r5 = r31 + 172;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a4cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 108, r3);
    r4 = r1 + 108;
    r5 = r31 + 136;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a54u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 110, r3);
    r4 = r1 + 110;
    r5 = r31 + 140;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a5cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 112, r3);
    r4 = r1 + 112;
    r5 = r31 + 144;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a64u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 114, r3);
    r4 = r1 + 114;
    r5 = r31 + 148;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b09e4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 116, r3);
    r4 = r1 + 116;
    r5 = r31 + 108;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a6cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 118, r3);
    r4 = r1 + 118;
    r5 = r31 + 152;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a74u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 120, r3);
    r4 = r1 + 120;
    r5 = r31 + 156;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a84u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 122, r3);
    r4 = r1 + 122;
    r5 = r31 + 160;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a7cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 124, r3);
    r4 = r1 + 124;
    r5 = r31 + 164;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r4 = 0x1u;
    r3 = D(0x804b0a8cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r1 + 126, r3);
    r4 = r1 + 126;
    r5 = r31 + 168;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80162024)(W(r3), W(r4), W(r5));
    r9 = D(0x803d0000u);
    r3 = r1 + 128;
    r9 = D(0x803caed4u);
    r4 = r31 + 192;
    S32(r1 + 128, r9);
    r3 = A800fc270(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(D(0x804b1788u));
    r0 = L32(r9 + 188);
    r9 = r0 & 0x40000000u; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_802627f4;
    r3 = D(0x80420000u);
    r3 = D(0x8041be70u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    r4 = r3;
    r5 = L32(r31 + 20);
    r3 = L32(D(0x804b178cu));
    r3 = CU(A80164514, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802627f4:
    r9 = D(0x803d0000u);
    r3 = r1 + 132;
    r9 = D(0x803caee4u);
    r4 = r1 + 136;
    S32(r1 + 132, r9);
    r3 = A800fc1f0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r1 + 136);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8026289c;
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f0 = LF(D(0x803caf24u));
    r10 = D(0x803d0000u);
    f13 = LF(D(0x803caf28u));
    r30 = r1 + 16;
    f12 = LF(D(0x803caf2cu));
    r4 = D(0x803d0000u);
    SF(r1 + 16, f0);
    r4 = D(0x803caef8u);
    SF(r30 + 4, f13);
    r3 = r28;
    SF(r30 + 8, f12);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r5 = L8(D(0x804abb60u));
    r4 = r31 + 180;
    r3 = r28;
    r5 = r5 + 26;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r31 + 180);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026289c;
    r9 = L32(r3);
    r4 = r30;
    r5 = 0x0u;
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026289c:
    r3 = r31;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A80263e18)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r9 = L32(D(0x804b1788u));
    r3 = L32(r9 + 108);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802629a0;
    r9 = L32(r3);
    r5 = D(0x803f0000u);
    r5 = D(0x803f2c28u);
    r4 = L32(D(0x804aa840u));
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r11 = L32(D(0x804b1788u));
    r5 = D(0x803f0000u);
    r5 = D(0x803f3328u);
    r4 = L32(D(0x804aa83cu));
    r3 = L32(r11 + 108);
    r9 = L32(r3);
    r0 = L32(r9 + 64);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(D(0x804aaabcu));
    r0 = L32(r9 + 208);
    cr0 = CMPS(r0, 6);
    if (!(cr0 & 2)) goto L_802629a0;
    r0 = L32(D(0x804aa858u));
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80262920;
    r4 = D(0x803d0000u);
    r3 = r31;
    r4 = D(0x803caf0cu);
    ((void (*)(w3d_oarg, w3d_oarg))A802644a8)(W(r3), W(r4));
L_80262920:
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f12 = LF(D(0x803caf30u));
    r30 = r1 + 48;
    f0 = LF(D(0x803caf2cu));
    r9 = r1 + 32;
    SF(r28 + 8, f12);
    r11 = D(0x803d0000u);
    SF(r1 + 8, f0);
    r5 = r9;
    SF(r28 + 4, f0);
    r4 = r28;
    SF(r1 + 32, f0);
    SF(r9 + 4, f12);
    SF(r9 + 8, f0);
    f13 = LF(D(0x803caf34u));
    SF(r1 + 48, f0);
    SF(r30 + 4, f0);
    SF(r30 + 8, f13);
    r9 = L32(D(0x804b1788u));
    r3 = L32(r9 + 112);
    r11 = L32(r3);
    r0 = L32(r11 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(D(0x804b1788u));
    r4 = r30;
    r3 = L32(r9 + 112);
    r11 = L32(r3);
    r0 = L32(r11 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802629a0:
    r3 = r31;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80262a58)(W(r3));
    r1 = r1 + 160;
    return r3;
}

// 0x802672cc FUN_802672cc no verificada: desde bytes PPC
// Llama a string_from_text, handle_load_node, large_reserve_string_finish, large_reserve_string_release, border_name. Hace 48 llamadas virtuales. Usa las cadenas "NULL", "FE.Box.Highlight", "FE.AudioBar". Mucho cálculo en coma flotante.
// aviso: lee r3 tras void 80341588 en 80267fac
__attribute__((weak)) w3d_u32 A802672cc(w3d_u32 r3) {
    alignas(16) char frame[440];
    w3d_u32 r1 = h2g(frame) + 424;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f23 = 0, f24 = 0, f25 = 0, f26 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 424; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r4 = D(0x803d0000u);
    r3 = r1 + 8;
    r4 = D(0x803cb6c4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r28 = 0x0u;
    r29 = r1 + 8;
    r4 = r31 + 212;
    r5 = 0xffu;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r30 = r1 + 16;
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r27 = r1 + 72;
    r3 = r29;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r16 = r27;
    r3 = L32(r31 + 112);
    r5 = 0x0u;
    r4 = L32(r31 + 212);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f31 = LF(D(0x803cb6ecu));
    r4 = r30;
    f0 = LF(D(0x803cb6f0u));
    r5 = 0x0u;
    SF(r1 + 16, f31);
    SF(r30 + 8, f0);
    SF(r30 + 4, f0);
    r3 = L32(r31 + 212);
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f0 = LF(r31 + 704);
    r11 = r1 + 32;
    r10 = L32(r31 + 212);
    r4 = r11;
    SF(r1 + 32, f0);
    r5 = 0x0u;
    SF(r11 + 4, f31);
    r3 = r10;
    SF(r11 + 8, f31);
    r9 = L32(r10);
    r0 = L32(r9 + 80);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r31 + 40);
    r5 = 0x0u;
    r4 = r30;
    S32(r1 + 192, r9);
    r9 = D(0x803d0000u);
    f13 = LF(r31 + 548);
    f12 = LF(D(0x803cb6f4u));
    r11 = L32(r1 + 192);
    f13 = (float)(f13 / f12);
    f0 = LF(r11 + 20);
    r11 = L32(r31 + 212);
    r3 = r11;
    f0 = (float)(f0 * f13);
    SF(r1 + 16, f0);
    SF(r30 + 8, f31);
    SF(r30 + 4, f31);
    r9 = L32(r11);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r31 + 40);
    r11 = r9 + 20;
    f13 = LF(r9 + 20);
    f12 = LF(r11 + 8);
    f0 = LF(r11 + 4);
    r9 = L32(r1 + 192);
    SF(r1 + 48, f13);
    SF(r1 + 52, f0);
    SF(r1 + 56, f12);
    r3 = L32(r9 + 132);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80263bb8)(W(r3));
    r4 = r3;
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r4 = D(0x803d0000u);
    r3 = r1 + 64;
    r4 = D(0x803cb6ccu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = r1 + 72;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 8);
    r3 = r1 + 72;
    S32(r1 + 72, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r4 = 0x0u;
    r9 = L16(r11);
    r3 = r27;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A80263608)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = r27;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 64);
    r3 = r27;
    S32(r1 + 72, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r4 = 0x0u;
    r9 = L16(r11);
    r3 = r27;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A80263608)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r5 = L8(r31 + 32);
    r4 = r1 + 80;
    S32(r1 + 80, r28);
    r3 = r29;
    r5 = r5 + 29;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 80);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267510;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267510:
    r3 = L32(r31 + 456);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026752c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026752c:
    r3 = L32(r1 + 80);
    S32(r31 + 456, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026754c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026754c:
    r5 = L8(r31 + 32);
    r0 = 0x0u;
    S32(r1 + 72, r0);
    r4 = r16;
    r5 = r5 + 29;
    r3 = r1 + 8;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267590;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267590:
    r3 = L32(r31 + 464);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802675ac;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802675ac:
    r3 = L32(r1 + 72);
    S32(r31 + 464, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802675cc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802675cc:
    r5 = L8(r31 + 32);
    r0 = 0x0u;
    S32(r1 + 72, r0);
    r4 = r16;
    r5 = r5 + 29;
    r3 = r1 + 8;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267610;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267610:
    r3 = L32(r31 + 472);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026762c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026762c:
    r3 = L32(r1 + 72);
    S32(r31 + 472, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026764c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026764c:
    r5 = L8(r31 + 32);
    r0 = 0x0u;
    S32(r1 + 72, r0);
    r4 = r16;
    r5 = r5 + 29;
    r3 = r1 + 8;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267690;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267690:
    r3 = L32(r31 + 480);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802676ac;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802676ac:
    r3 = L32(r1 + 72);
    S32(r31 + 480, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802676cc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802676cc:
    r5 = L8(r31 + 32);
    r29 = 0x0u;
    r4 = r27;
    S32(r1 + 72, r29);
    r5 = r5 + 29;
    r3 = r1 + 64;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267710;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267710:
    r3 = L32(r31 + 460);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026772c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026772c:
    r3 = L32(r1 + 72);
    S32(r31 + 460, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8026774c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026774c:
    r5 = L8(r31 + 32);
    r4 = r16;
    S32(r1 + 72, r29);
    r3 = r1 + 64;
    r5 = r5 + 29;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_8026778c;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8026778c:
    r3 = L32(r31 + 468);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802677a8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802677a8:
    r3 = L32(r1 + 72);
    S32(r31 + 468, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802677c8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802677c8:
    r5 = L8(r31 + 32);
    r4 = r16;
    S32(r1 + 72, r29);
    r3 = r1 + 64;
    r5 = r5 + 29;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267808;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267808:
    r3 = L32(r31 + 476);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80267824;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267824:
    r3 = L32(r1 + 72);
    S32(r31 + 476, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80267844;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267844:
    r5 = L8(r31 + 32);
    r4 = r16;
    S32(r1 + 72, r29);
    r3 = r1 + 64;
    r5 = r5 + 29;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 72);
    ((void (*)())A8034357c)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80267884;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80267884:
    r3 = L32(r31 + 484);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802678a0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802678a0:
    r3 = L32(r1 + 72);
    S32(r31 + 484, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802678c0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802678c0:
    r9 = r1 + 152;
    r11 = r1 + 188;
    S32(r1 + 196, r9);
    r27 = 0x0u;
    S32(r1 + 200, r11);
    r17 = r1 + 176;
    r18 = r1 + 177;
    r19 = r1 + 178;
    r20 = r1 + 179;
    r21 = r1 + 88;
    r22 = r1 + 104;
    r23 = r1 + 120;
    r14 = r1 + 136;
    r15 = r1 + 184;
    r24 = r1 + 168;
    r25 = 0x8u;
    r26 = 0xau;
    r29 = r1 + 180;
    r28 = 0xffffffc8u;
    r30 = r31 + 480;
L_80267910:
    r3 = L32(r30 - 24);
    r4 = r17;
    S8(r1 + 176, r25);
    r27 = r27 + 1;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r3 = L32(r30 - 16);
    r4 = r18;
    S8(r1 + 177, r25);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r3 = L32(r30 - 8);
    r4 = r19;
    S8(r1 + 178, r26);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r3 = L32(r30);
    r4 = r20;
    S8(r1 + 179, r26);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r3 = L32(r31 + 212);
    r5 = 0x0u;
    r4 = L32(r30 - 24);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r31 + 212);
    r5 = 0x0u;
    r4 = L32(r30 - 16);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r31 + 212);
    r5 = 0x0u;
    r4 = L32(r30 - 8);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r31 + 212);
    r5 = 0x0u;
    r4 = L32(r30);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    S8(r1 + 180, r28);
    r0 = 0xffffffffu;
    r4 = r29;
    r3 = L32(r30 - 24);
    S8(r29 + 3, r0);
    S8(r29 + 1, r28);
    S8(r29 + 2, r28);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r30 - 16);
    r4 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r30 - 8);
    r4 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r30);
    r4 = r29;
    r30 = r30 + 4;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    cr0 = CMPU(r27, 0x1u);
    if (!(cr0 & 4)) goto L_80267910;
    f3 = LF(r31 + 560);
    r9 = D(0x803d0000u);
    f12 = LF(r31 + 536);
    r11 = D(0x803d0000u);
    f30 = LF(r31 + 548);
    f0 = (float)(f3 + f3);
    f9 = LF(D(0x803cb6f4u));
    f12 = (float)(f12 - f0);
    f13 = LF(D(0x803cb6fcu));
    r9 = D(0x803d0000u);
    f9 = (float)(f30 / f9);
    f6 = LF(D(0x803cb700u));
    r11 = D(0x803d0000u);
    r9 = D(0x803d0000u);
    f10 = LF(D(0x803cb6f8u));
    r11 = L32(r1 + 192);
    f11 = LF(D(0x803cb704u));
    f0 = LF(r1 + 48);
    r9 = D(0x803d0000u);
    f8 = LF(r11 + 20);
    f7 = LF(D(0x803cb6ecu));
    r11 = D(0x803d0000u);
    SF(r1 + 184, f3);
    r9 = r15;
    SF(r16 + 8, f7);
    SF(r31 + 536, f12);
    f4 = LF(D(0x803cb6f0u));
    f13 = (float)(f12 / f13);
    f0 = (float)(f0 * f9);
    f13 = (float)(f13 * f6);
    f13 = __builtin_fmaf((float)f13, (float)f11, (float)f0);
    f8 = (float)(f8 * f9);
    f9 = (float)(f3 * f10);
    f6 = (float)(f13 * f10);
    f11 = -f12;
    f0 = (float)(f6 - f8);
    f11 = __builtin_fmaf((float)f11, (float)f10, -(float)f9);
    SF(r1 + 88, f0);
    f5 = (float)(f9 * f10);
    SF(r1 + 72, f0);
    f12 = __builtin_fmaf((float)f12, (float)f10, (float)f9);
    SF(r1 + 92, f11);
    SF(r1 + 76, f12);
    f13 = (float)(f13 + f5);
    SF(r21 + 8, f7);
    f13 = (float)(f13 - f8);
    SF(r1 + 108, f12);
    SF(r1 + 104, f13);
    SF(r22 + 8, f7);
    SF(r1 + 120, f13);
    SF(r1 + 124, f11);
    SF(r23 + 8, f7);
    SF(r1 + 136, f6);
    SF(r1 + 140, f9);
    SF(r14 + 8, f4);
    SF(r1 + 152, f5);
    r11 = L32(r1 + 196);
    SF(r1 + 156, f9);
    SF(r11 + 8, f4);
    f0 = LF(r1 + 48);
    cr0 = CMPF(f3, f0);
    if (!(cr0 & 8)) goto L_80267b10;
    r9 = r1 + 48;
L_80267b10:
    f13 = LF(r9);
    f0 = LF(r1 + 52);
    r9 = r15;
    SF(r1 + 48, f13);
    cr0 = CMPF(f3, f0);
    if (!(cr0 & 8)) goto L_80267b2c;
    r9 = r1 + 52;
L_80267b2c:
    f0 = LF(r9);
    r28 = r14;
    r8 = L32(r31 + 40);
    r30 = r31 + 480;
    SF(r1 + 52, f0);
    r27 = 0x2u;
    r11 = L32(r1 + 48);
    r9 = r8 + 20;
    r29 = L32(r1 + 196);
    r10 = L32(r1 + 52);
    r0 = L32(r1 + 56);
    S32(r8 + 20, r11);
    S32(r9 + 8, r0);
    S32(r9 + 4, r10);
L_80267b64:
    r3 = L32(r30 - 24);
    r4 = r16;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30 - 16);
    r4 = r21;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30 - 8);
    r4 = r22;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30);
    r4 = r23;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30 - 24);
    r4 = r28;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30 - 16);
    r4 = r28;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30 - 8);
    r4 = r29;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30);
    r4 = r29;
    r5 = 0x0u;
    r30 = r30 + 4;
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    { w3d_u32 t_ = r27; r27 = t_ + (w3d_u32)-1; ca = r27 < t_; cr0 = CMPS(r27, 0); }
    if (!(cr0 & 2)) goto L_80267b64;
    r0 = L32(r31 + 176);
    r27 = 0x0u;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80267c64;
    r27 = 0x1u;
L_80267c64:
    r28 = 0x0u;
    r29 = r31 + 480;
L_80267c6c:
    r3 = L32(r29 - 24);
    r30 = r27 ^ r28;
    { w3d_u32 t_ = r30; r0 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r0 + r30 + ca; r30 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r30;
    r28 = r28 + 1;
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r29 - 16);
    r4 = r30;
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r29 - 8);
    r4 = r30;
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r29);
    r4 = r30;
    r29 = r29 + 4;
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPU(r28, 0x1u);
    if (!(cr0 & 4)) goto L_80267c6c;
    r11 = D(0x803d0000u);
    r9 = L32(r1 + 192);
    f0 = LF(D(0x803cb6f4u));
    r4 = r1 + 16;
    f13 = LF(r9 + 20);
    r5 = 0x0u;
    f0 = (float)(f30 / f0);
    r9 = D(0x803d0000u);
    f31 = LF(D(0x803cb6ecu));
    r11 = L32(r31 + 212);
    SF(r1 + 20, f31);
    SF(r1 + 24, f31);
    r3 = r11;
    f13 = (float)(f13 * f0);
    SF(r1 + 16, f13);
    r9 = L32(r11);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = D(0x803d0000u);
    r3 = r24;
    r4 = D(0x803cb6e0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = r24;
    r3 = A8015ae3c(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    ((void (*)())A80343808)();
    r30 = r3;
    r3 = r24;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r24;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80171f90)(W(r3));
    cr0 = CMPS(r3, 1);
    if ((cr0 & 2)) goto L_80267d80;
    r3 = r30;
    r4 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80171ee0)(W(r3), W(r4));
L_80267d80:
    r3 = r30;
    f24 = f31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80171fa0)(W(r3));
    r25 = r24;
    r29 = r3;
    r26 = r1 + 16;
    r3 = r30;
    r23 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80171ff8)(W(r3));
    r30 = r3;
    r4 = 0x0u;
    r5 = 0x8u;
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eefe0)(W(r3), W(r4), W(r5));
    r3 = r30;
    r4 = 0x0u;
    r5 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eefe0)(W(r3), W(r4), W(r5));
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f12 = LF(D(0x803cb708u));
    r10 = D(0x803d0000u);
    f0 = LF(D(0x803cb70cu));
    r9 = D(0x803d0000u);
    f9 = LF(D(0x803cb714u));
    r11 = D(0x803d0000u);
    f13 = LF(D(0x803cb710u));
    r9 = D(0x803d0000u);
    SF(r29 + 4, f0);
    r10 = D(0x803d0000u);
    SF(r29, f12);
    r8 = D(0x803d0000u);
    SF(r30, f13);
    r7 = 0x0u;
    SF(r30 + 4, f9);
    f13 = LF(D(0x803cb6f0u));
    f12 = LF(r29 + 4);
    f23 = f13;
    f0 = LF(D(0x803cb6fcu));
    f13 = (float)(f13 - f12);
    f11 = LF(D(0x803cb6f8u));
    f13 = (float)(f13 - f9);
    f10 = LF(D(0x803cb718u));
    SF(r29 + 4, f13);
    f26 = f11;
    f13 = LF(r31 + 536);
    f12 = LF(r31 + 556);
    f30 = (float)(f13 / f0);
    SF(r1 + 184, f12);
    f0 = (float)(f30 * f0);
    f0 = (float)(f0 * f11);
    f27 = (float)(f30 * f10);
    f0 = (float)(f31 - f0);
    f31 = __builtin_fmaf((float)f30, (float)f11, (float)f0);
    f28 = (float)(f27 * f11);
L_80267e5c:
    r9 = (w3d_s32)r7 * 28;
    r24 = r7 + 1;
    r28 = 0x0u;
    f25 = (float)(f28 + f27);
    r29 = r9 + r31;
    r9 = r9 + 216;
    r27 = r31 + r9;
L_80267e78:
    r9 = D(0x803d0000u);
    r3 = r25;
    r4 = D(0x803cb6e0u);
    r30 = r28 << 2;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    f29 = (float)(f30 * f26);
    r5 = L8(r31 + 32);
    r4 = r27 + r30;
    r3 = r25;
    r5 = r5 + 29;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = r25;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r25;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    SF(r1 + 20, f31);
    r11 = r30 + r29;
    SF(r1 + 16, f28);
    r4 = r26;
    SF(r26 + 8, f24);
    r5 = 0x0u;
    f31 = (float)(f31 + f30);
    r3 = L32(r11 + 216);
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f0 = (float)(f27 * f26);
    SF(r1 + 20, f29);
    SF(r1 + 16, f0);
    r11 = r30 + r29;
    SF(r26 + 8, f23);
    r5 = 0x0u;
    r4 = r26;
    r3 = L32(r11 + 216);
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = r30 + r29;
    r3 = L32(r9 + 216);
    ((void (*)())A8034357c)();
    r4 = L32(r1 + 200);
    S8(r1 + 188, r23);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r3 = L32(r31 + 212);
    r30 = r30 + r29;
    r4 = L32(r30 + 216);
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = r28 + 1;
    r28 = r0 & 0xffu;
    cr0 = CMPU(r28, 0x6u);
    if (!(cr0 & 4)) goto L_80267e78;
    r9 = D(0x803d0000u);
    r7 = r24;
    f0 = LF(D(0x803cb6fcu));
    f28 = f25;
    cr0 = CMPU(r7, 0x5u);
    f0 = (float)(f30 * f0);
    f0 = (float)(f0 * f26);
    f0 = (float)(f24 - f0);
    f31 = (float)(f0 + f29);
    if (!(cr0 & 4)) goto L_80267e5c;
    r0 = 0x1u;
    r3 = r1 + 64;
    S32(r31 + 500, r0);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 8;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 424;
    return r3;
}

// 0x8026c8a8 FUN_8026c8a8 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: seed_set. Llama a assign__20d24d_String_803426b8PCc, atol, hash_string, decode_radices.
__attribute__((weak)) w3d_u32 A8026c8a8(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r0 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r31 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r11 = L32(r30);
    r8 = 0x0u;
    r0 = L16(r11 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8026c91c;
    r0 = L8(r11);
    r9 = D(0x803e0000u);
    r9 = D(0x803db449u);
    r10 = r11;
    goto L_8026c908;
L_8026c8ec:
    r0 = L16(r10 - 4);
    r8 = r8 + 1;
    cr0 = CMPU(r8, r0);
    if (!(cr0 & 8)) goto L_8026c91c;
    r0 = L8(r10 + r8);
    r9 = D(0x803e0000u);
    r9 = D(0x803db449u);
L_8026c908:
    r0 = (w3d_u32)(w3d_s32)(signed char)r0;
    r11 = L8((r9 + r0) ^ 3u);
    r0 = r11 & 0x4u; cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8026c8ec;
    r31 = 0x0u;
L_8026c91c:
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_8026c930;
    r3 = L32(r30);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A802ed8c4)(W(r3));
    goto L_8026c93c;
L_8026c930:
    r4 = L32(r30);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8026cde8)(W(r3), W(r4));
L_8026c93c:
    r31 = r3;
    r4 = r31;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8026ce2c)(W(r3), W(r4));
    r4 = r3;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8026c96c)(W(r3), W(r4));
    r1 = r1 + 16;
    return r3;
}

// 0x802707bc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802707bc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3 + 208);
    r3 = r3 + 28;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x802814c4 FUN_802814c4 no verificada: desde bytes PPC
// Llama a string_from_text, text_default, string_property_write, string_property, assign__20d24d_String_803426b8PCc. Hace 3 llamadas virtuales. Usa las cadenas ">%s<", "FE.I.Unlocked:%d", "MCa.LockImage".
// aviso: lee r3 tras void 80341588 en 8028190c
__attribute__((weak)) w3d_u32 A802814c4(w3d_u32 r3) {
    alignas(16) char frame[168];
    w3d_u32 r1 = h2g(frame) + 152;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 152; S32(t_, r1); r1 = t_; }
    r9 = D(0x803d0000u);
    r11 = r1 + 8;
    r0 = L32(D(0x803cef8cu));
    r8 = D(0x803d0000u);
    r9 = D(0x803cef8cu);
    r10 = D(0x803cefccu);
    r5 = L32(D(0x803cef98u));
    r25 = r11;
    r7 = L32(D(0x803cef90u));
    r30 = r1 + 24;
    r6 = L32(D(0x803cef94u));
    r21 = r3;
    S32(r1 + 8, r0);
    r4 = D(0x803d0000u);
    S32(r11 + 4, r7);
    r29 = r1 + 48;
    S32(r11 + 8, r6);
    r4 = D(0x803ceb40u);
    S32(r11 + 12, r5);
    r3 = r1 + 40;
    r28 = L32(D(0x803cefccu));
    r24 = 0x0u;
    r0 = L32(D(0x803cefd0u));
    r27 = r30;
    r11 = L32(D(0x803cefd8u));
    r20 = r29;
    r9 = L32(D(0x803cefd4u));
    r22 = 0x0u;
    S32(r1 + 24, r28);
    r23 = D(0x803d0000u);
    S32(r30 + 4, r0);
    r28 = 0x0u;
    S32(r30 + 8, r9);
    S32(r30 + 12, r11);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r0 = L32(r30 + r24);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80281594;
    r31 = r27;
L_80281578:
    r3 = r30;
    r4 = D(0x803ceb40u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r30 = r30 + 4;
    { w3d_u32 t_ = r31 + 4; r0 = L32(t_); r31 = t_; }
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80281578;
L_80281594:
    r9 = r28 << 2;
    r3 = r25;
    r0 = L32(r25 + r9);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80281818;
    r0 = r24 << 2;
    r30 = r1 + 72;
    r26 = r0 + r27;
    r27 = r0 + r25;
L_802815b8:
    r3 = r3 + r9;
    r4 = r1 + 80;
    r3 = A800fc2b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r28 = r28 + 1;
    r4 = L32(r1 + 80);
    r3 = r20;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r9 = L32(r1 + 48);
    r0 = L16(r9 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80281804;
    r0 = 0x0u;
    S32(r1 + 84, r9);
    S32(r1 + 56, r0);
    r3 = r1 + 84;
    r4 = r1 + 56;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 8)) goto L_802817b0;
    r3 = L32(r1 + 56);
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 5);
    if (!(cr0 & 2)) goto L_80281774;
    r3 = L32(r1 + 56);
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x80366208u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_80281664;
L_8028164c:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_8028176c;
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_8028164c;
L_80281664:
    r0 = 0x1u;
L_80281668:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80281774;
    r3 = L32(r1 + 56);
    r31 = r1 + 64;
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r29 = r3;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r10 = L32(r29 + 24);
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r1 + 64);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802816c0;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_802816c0:
    r0 = L32(r29 + 24);
    r3 = r1 + 88;
    r4 = r1 + 92;
    S32(r1 + 88, r0);
    S32(r1 + 64, r0);
    r3 = A800fc2b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 8)) goto L_80281700;
    r4 = D(0x803d0000u);
    r5 = L32(r29 + 24);
    r4 = D(0x803cefdcu);
    r3 = r31;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 64);
    S32(r1 + 92, r0);
L_80281700:
    r4 = L32(r1 + 92);
    r3 = r27;
    r27 = r27 + 4;
    r24 = r24 + 1;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r22 = 0x1u;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r5 = L32(r29 + 20);
    r4 = D(0x803d0000u);
    r4 = D(0x803cefe4u);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r4 = L32(r1 + 72);
    r3 = r26;
    r26 = r26 + 4;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r31;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r31;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_802817e8;
L_8028176c:
    r0 = 0x0u;
    goto L_80281668;
L_80281774:
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 48);
    r3 = r1 + 64;
    S32(r1 + 64, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 64;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_802817e8;
L_802817b0:
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 48);
    r3 = r1 + 64;
    S32(r1 + 64, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 64;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_802817e8:
    r3 = L32(r1 + 56);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80281804;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80281804:
    r9 = r28 << 2;
    r3 = r25;
    r0 = L32(r25 + r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802815b8;
L_80281818:
    cr0 = CMPS(r22, 0);
    if (!(cr0 & 2)) goto L_8028187c;
    r9 = D(0x803d0000u);
    r4 = D(0x803d0000u);
    r9 = D(0x803cf060u);
    r4 = D(0x803ceb40u);
    S32(r1 + 96, r9);
    r3 = r1 + 96;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r29 = r25;
    r0 = L32(r29);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802818f0;
    r31 = 0x0u;
    r28 = 0x0u;
L_80281854:
    r3 = r29 + r28;
    r4 = D(0x803ceb40u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r30 = r29;
    r31 = r31 + 4;
    r28 = r28 + 4;
    r0 = L32(r30 + r31);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80281854;
    goto L_802818f0;
L_8028187c:
    r30 = 0x0u;
    r3 = r25;
    r0 = L32(r3 + r30);
    r31 = r1 + 100;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802818cc;
    r28 = 0x0u;
    r29 = 0x0u;
L_8028189c:
    cr0 = CMPU(r30, r24);
    if ((cr0 & 8)) goto L_802818b0;
    r3 = r3 + r29;
    r4 = D(0x803ceb40u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
L_802818b0:
    r28 = r28 + 4;
    r3 = r25;
    r0 = L32(r3 + r28);
    r29 = r29 + 4;
    r30 = r30 + 1;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8028189c;
L_802818cc:
    r9 = D(0x803d0000u);
    r4 = D(0x803d0000u);
    r9 = D(0x803cf060u);
    r3 = r31;
    S32(r1 + 100, r9);
    r4 = D(0x803cf070u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r3 = r21;
    r3 = CU(A80280370, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802818f0:
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 40;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 40;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 152;
    return r3;
}

// 0x8028496c FUN_8028496c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: team_value_lookup. Llama a resource_property, resource_identity, weapon_resource, large_reserve_string_init, large_reserve_string_header. Hace 4 llamadas virtuales.
__attribute__((weak)) w3d_u32 A8028496c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r11 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r30 = r4;
    r11 = L32(r30);
    r0 = L16(r11 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80284af8;
    r9 = L32(D(0x804b1788u));
    r0 = L32(r9 + 188);
    r9 = r0 & 0x10u; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_802849ac;
    goto L_80284af8;
L_802849a4:
    r0 = 0x0u;
    goto L_80284a30;
L_802849ac:
    r0 = 0x0u;
    S32(r1 + 24, r11);
    S32(r1 + 8, r0);
    r3 = r1 + 24;
    r4 = r1 + 8;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 8)) goto L_80284aa4;
    r3 = L32(r1 + 8);
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 5);
    if (!(cr0 & 2)) goto L_80284a68;
    r3 = L32(r1 + 8);
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x80366208u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_80284a2c;
L_80284a14:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_802849a4;
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_80284a14;
L_80284a2c:
    r0 = 0x1u;
L_80284a30:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80284a68;
    r3 = L32(r1 + 8);
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r31 = L32(r3 + 28);
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80284afc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_80284afc;
L_80284a68:
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r30);
    r3 = r1 + 16;
    S32(r1 + 16, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 16;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_80284adc;
L_80284aa4:
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r30);
    r3 = r1 + 16;
    S32(r1 + 16, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 16;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_80284adc:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80284af8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80284af8:
    r31 = 0x0u;
L_80284afc:
    r3 = r31;
    r1 = r1 + 40;
    return r3;
}

// 0x80285b00 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80285b00(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r3 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b0668)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x80289d70 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 800fc110 en 80289d90
__attribute__((weak)) w3d_u32 A80289d70(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    S32(r1 + 8, r4);
    r3 = r1 + 8;
    r4 = r5;
    r6 = 0x5u;
    r5 = 0xffu;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800fc110)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 16;
    return r3;
}

// 0x8028a570 FUN_8028a570 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: card_begin. Llama a card_guide_step, load_game_data, read_int_property. Usa las cadenas "SAVE.Language".
__attribute__((weak)) w3d_u32 A8028a570(w3d_u32 r3) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r4 = 0x1u;
    r30 = r31 + 120;
    r3 = r30;
    r29 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802aba18)(W(r3), W(r4));
    r28 = r1 + 8;
    r3 = r30;
    r27 = r1 + 12;
    ((void (*)(w3d_oarg))A802aba0c)(W(r3));
L_8028a5a8:
    r0 = L32(r31 + 140);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8028a5d4;
    r3 = r31 + 120;
    r4 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802aba68)(W(r3), W(r4));
    cr0 = CMPS(r3, -1);
    if ((cr0 & 2)) goto L_8028a5a8;
    cr0 = CMPS(r3, 1);
    if (!(cr0 & 2)) goto L_8028a5d4;
    r29 = 0x1u;
L_8028a5d4:
    cr0 = CMPS(r29, 0);
    if ((cr0 & 2)) goto L_8028a64c;
    r30 = r31 + 120;
    r4 = 0x2u;
    r3 = r30;
    r29 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802aba18)(W(r3), W(r4));
    r3 = r30;
    ((void (*)(w3d_oarg))A802aba0c)(W(r3));
L_8028a5f8:
    r0 = L32(r31 + 140);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8028a64c;
    r3 = r29;
    r4 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802aba68)(W(r3), W(r4));
    cr0 = CMPS(r3, -1);
    if (!(cr0 & 2)) goto L_8028a628;
    r0 = L32(r31 + 124);
    cr0 = CMPS(r0, 161);
    if ((cr0 & 2)) goto L_8028a64c;
    goto L_8028a5f8;
L_8028a628:
    cr0 = CMPS(r3, -34);
    if ((cr0 & 2)) goto L_8028a5f8;
    cr0 = CMPS(r3, -37);
    if (!(cr0 & 2)) goto L_8028a64c;
    r9 = L32(r31 + 136);
    r3 = r31;
    r4 = L32(r9 + 36);
    r4 = r4 + 8268;
    r3 = CU(A80289eec, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8028a64c:
    r0 = L32(r31 + 120);
    r6 = 0x0u;
    r5 = L32(r31 + 136);
    r9 = D(0x803d0000u);
    r11 = 0xb0u;
    r10 = 0xd0u;
    r8 = 0xc0u;
    S32(r31 + 140, r6);
    S32(r31 + 156, r11);
    r9 = D(0x803cfb34u);
    S32(r31 + 184, r10);
    r7 = 0xau;
    S32(r31 + 548, r8);
    r3 = r28;
    S32(r31 + 536, r0);
    r4 = r27;
    S32(r31 + 540, r5);
    S32(r1 + 12, r7);
    S32(r1 + 8, r9);
    S32(r31 + 144, r0);
    S32(r31 + 172, r0);
    S32(r31 + 288, r6);
    S32(r31 + 176, r5);
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 40;
    return r3;
}

// 0x80294398 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80294398(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3);
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802943cc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802943cc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = r4;
    r5 = 0x0u;
    r11 = L32(r9);
    r4 = L32(r3);
    r0 = L32(r11 + 92);
    r3 = r9;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8029459c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8029459c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3);
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802958d8 FUN_802958d8 no verificada: desde bytes PPC
// Llama a node_set_colour, store_byte_value, large_reserve_string_init, large_reserve_string_header, pool_write_scaled_entry. Hace 4 llamadas virtuales. Mucho cálculo en coma flotante.
// aviso: lee r3 tras void 80264348 en 80295cc4
__attribute__((weak)) w3d_u32 A802958d8(w3d_u32 r3) {
    alignas(16) char frame[160];
    w3d_u32 r1 = h2g(frame) + 144;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 144; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r11 = 0x1u;
    r0 = L32(r31 + 60);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80295910;
    r11 = 0x0u;
L_80295910:
    r0 = L32(r31 + 56);
    r9 = 0x1u;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80295924;
    r9 = 0x0u;
L_80295924:
    r0 = r11 & r9; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80295cc8;
    f0 = LF(r31 + 84);
    r27 = D(0x803d0000u);
    f13 = LF(r31 + 80);
    r28 = 0x0u;
    f31 = LF(r31 + 88);
    f0 = (float)(f0 - f13);
    f28 = LF(D(0x803d07e0u));
    cr0 = CMPF(f31, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_80295978;
    r0 = 0xffffffffu;
    r30 = r1 + 32;
    S8(r1 + 32, r0);
    r4 = r30;
    r3 = L32(r31 + 144);
    S8(r30 + 2, r0);
    S8(r30 + 1, r0);
    S8(r30 + 3, r28);
    goto L_80295a40;
L_80295978:
    r29 = 0xffffffffu;
    r30 = r1 + 32;
    S8(r1 + 32, r29);
    r4 = r30;
    r3 = L32(r31 + 144);
    S8(r30 + 1, r29);
    S8(r30 + 2, r29);
    S8(r30 + 3, r29);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r31 + 148);
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r31 + 152);
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r0 = L32(r31 + 64);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_802959dc;
    f0 = LF(r31 + 84);
    f12 = LF(r31 + 80);
    f13 = LF(r31 + 52);
    f0 = (float)(f0 - f12);
    f13 = (float)(f13 / f0);
    SF(r31 + 100, f13);
    f28 = (float)(f13 * f31);
L_802959dc:
    f12 = LF(r31 + 80);
    f13 = LF(r31 + 84);
    f10 = LF(r31 + 52);
    f11 = LF(r31 + 88);
    f13 = (float)(f13 - f12);
    f0 = (float)(f10 - f28);
    f12 = LF(D(0x803d07e0u));
    f13 = (float)(f13 - f11);
    f0 = (float)(f0 / f13);
    cr0 = CMPF(f28, f12);
    SF(r31 + 100, f0);
    if (!(cr0 & 8)) goto L_80295a1c;
    f0 = (float)(f10 - f12);
    f0 = (float)(f0 / f13);
    SF(r31 + 100, f0);
    f28 = f12;
L_80295a1c:
    f12 = LF(r31 + 52);
    cr0 = CMPF(f28, f12);
    if (!(cr0 & 4)) goto L_80295a6c;
    S8(r1 + 32, r29);
    r4 = r30;
    r3 = L32(r31 + 144);
    S8(r30 + 2, r29);
    S8(r30 + 3, r28);
    S8(r30 + 1, r29);
L_80295a40:
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r31 + 148);
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r3 = L32(r31 + 152);
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173df0)(W(r3), W(r4));
    r9 = D(0x803d0000u);
    f0 = LF(D(0x803d07e4u));
    SF(r31 + 100, f0);
    goto L_80295cc8;
L_80295a6c:
    f13 = LF(r31 + 100);
    r9 = D(0x803d0000u);
    f0 = LF(r31 + 92);
    r10 = D(0x803d0000u);
    f31 = LF(D(0x803d07e8u));
    r11 = D(0x803d0000u);
    f30 = LF(D(0x803d07e4u));
    f0 = (float)(f0 * f13);
    f13 = (float)(f12 * f31);
    r30 = r1 + 8;
    f0 = (float)(f12 - f0);
    SF(r1 + 8, f30);
    f31 = (float)(f28 * f31);
    f29 = LF(D(0x803d07ecu));
    f0 = (float)(f0 - f13);
    SF(r30 + 8, f30);
    f0 = (float)(f0 - f31);
    r4 = r30;
    f13 = (float)(f31 - f29);
    SF(r31 + 104, f0);
    r11 = L32(r31 + 144);
    f0 = (float)(f0 + f13);
    SF(r30 + 4, f0);
    r5 = 0x0u;
    r3 = r11;
    r9 = L32(r11);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f0 = LF(r31 + 104);
    r4 = r30;
    SF(r1 + 8, f30);
    r5 = 0x0u;
    SF(r30 + 4, f0);
    SF(r30 + 8, f30);
    r3 = L32(r31 + 148);
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f0 = LF(r31 + 104);
    r4 = r30;
    SF(r1 + 8, f30);
    r5 = 0x0u;
    SF(r30 + 8, f30);
    f0 = (float)(f0 - f31);
    f0 = (float)(f0 + f29);
    r11 = L32(r31 + 152);
    SF(r30 + 4, f0);
    r3 = r11;
    r9 = L32(r11);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r11 = D(0x803d0000u);
    f13 = LF(r31 + 160);
    f0 = LF(D(0x803d07f0u));
    r9 = D(0x803d0000u);
    f12 = LF(D(0x803d07f4u));
    r5 = 0x0u;
    SF(r1 + 8, f13);
    f31 = (float)(f31 - f0);
    SF(r30 + 8, f12);
    r4 = r30;
    SF(r30 + 4, f31);
    r3 = L32(r31 + 148);
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r11 = D(0x803d0000u);
    f0 = LF(r31 + 104);
    f12 = LF(D(0x803d07f8u));
    r9 = D(0x803d0000u);
    f11 = LF(D(0x803d07fcu));
    f0 = (float)(f0 + f12);
    r9 = 0x55550000u;
    f0 = (float)(f0 / f11);
    r9 = 0x55555556u;
    r3 = L32(r31 + 144);
    r4 = r1 + 36;
    f13 = FCTIWZ(f0);
    SDS(r1 + 80, f13);
    r10 = L32(r1 + 84);
    r9 = (w3d_u32)(((w3d_s64)(w3d_s32)r10 * (w3d_s64)(w3d_s32)r9) >> 32);
    { w3d_u32 t_ = r10; r11 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r9 = r9 - r11;
    r0 = r9 << 1;
    r0 = r0 + r9;
    r10 = r10 - r0;
    r9 = r10 << 1;
    r28 = r9 + r10;
    r0 = r28 + 47;
    S8(r1 + 36, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r0 = r28 + 48;
    r3 = L32(r31 + 148);
    S8(r1 + 37, r0);
    r4 = r1 + 37;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r0 = r28 + 49;
    r3 = L32(r31 + 152);
    S8(r1 + 38, r0);
    r4 = r1 + 38;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80173f88)(W(r3), W(r4));
    r0 = L32(r31 + 128);
    r10 = 0x66660000u;
    f0 = LF(r31 + 92);
    r10 = 0x66666667u;
    SF(r31 + 108, f28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80295cc8;
    f11 = LF(r31 + 80);
    r9 = D(0x803d0000u);
    f13 = LF(r31 + 84);
    f0 = (float)(f0 - f11);
    f10 = LF(D(0x803d0800u));
    f13 = (float)(f13 - f11);
    r3 = r1 + 24;
    f0 = (float)(f0 / f13);
    f0 = (float)(f0 * f10);
    f12 = FCTIWZ(f0);
    SDS(r1 + 80, f12);
    r11 = L32(r1 + 84);
    r0 = (w3d_u32)(((w3d_s64)(w3d_s32)r11 * (w3d_s64)(w3d_s32)r10) >> 32);
    { w3d_u32 t_ = r11; r10 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r30 = r0 - r10;
    r9 = (w3d_s32)r30 * 10;
    r30 = r11 - r9;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    { w3d_u32 t_ = r30; r30 = (w3d_u32)9 - t_; ca = ((w3d_u32)9 >= t_); }
    r0 = L32(r31 + 176);
    r3 = r1 + 24;
    S32(r1 + 24, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r8 = r3;
    S32(r1 + 84, r30);
    r0 = 0x43300000u;
    r9 = L16(r8);
    r10 = D(0x803d0000u);
    S32(r1 + 80, r0);
    r3 = r1 + 24;
    r9 = r9 + 1;
    f0 = LD(D(0x803d0808u));
    S16(r8, r9);
    f1 = LDS(r1 + 80);
    r4 = L8(r31 + 180);
    f1 = f1 - f0;
    f1 = (float)f1;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, float, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A80264348)(W(r3), W(r4), (float)f1, W(r5), W(r6), W(r7), W(r8));
L_80295cc8:
    r1 = r1 + 144;
    return r3;
}

// 0x802975f8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8029d07c en 8029760c
__attribute__((weak)) w3d_u32 A802975f8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r0 = 0x0u;
    S32(D(0x804abc0cu), r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8029d07c)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x802979b8 FUN_802979b8 no verificada: desde bytes PPC
// Llama a resource_property, resource_identity, weapon_resource, string_property_write, text_default. Hace 2 llamadas virtuales. Usa las cadenas "FE.TempTeamStore", "User.HumanTeamName", "MCa.Team".
__attribute__((weak)) w3d_u32 A802979b8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[128];
    w3d_u32 r1 = h2g(frame) + 112;
    w3d_u32 r0 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 112; S32(t_, r1); r1 = t_; }
    r9 = D(0x803d0000u);
    r0 = 0x0u;
    r9 = D(0x803d0940u);
    S32(r1 + 8, r0);
    S32(r1 + 24, r9);
    r3 = r1 + 24;
    r4 = r1 + 8;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 8)) goto L_80297a10;
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80297b78;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_80297b78;
L_80297a10:
    r3 = L32(r1 + 8);
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r29 = r3;
    r9 = D(0x803d0000u);
    r9 = D(0x803d09ecu);
    r4 = L32(r29 + 60);
    S32(r1 + 28, r9);
    r3 = r1 + 28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r0 = L32(r29 + 40);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80297a5c;
    r9 = D(0x803d0000u);
    r4 = L32(r29 + 60);
    r9 = D(0x803d0a00u);
    r3 = r1 + 32;
    S32(r1 + 32, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
L_80297a5c:
    r9 = L32(r29 + 56);
    r3 = r1 + 16;
    r22 = r3;
    r31 = 0x0u;
    r28 = L32(r9 + 24);
    r27 = r9 + 32;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    cr0 = CMPU(r31, r28);
    r25 = r1 + 40;
    r24 = r1 + 44;
    r23 = r1 + 48;
    r21 = r1 + 52;
    r20 = r1 + 56;
    if (!(cr0 & 8)) goto L_80297ad4;
    r26 = D(0x803d0000u);
L_80297a98:
    r30 = r31 + 1;
    r3 = r22;
    r5 = r30;
    r4 = D(0x803d0a0cu);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = r31 << 2;
    r9 = L32(r1 + 16);
    r4 = L32(r27 + r0);
    r3 = r1 + 36;
    S32(r1 + 36, r9);
    r31 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    cr0 = CMPU(r31, r28);
    if ((cr0 & 8)) goto L_80297a98;
L_80297ad4:
    r9 = D(0x803d0000u);
    r3 = r25;
    r9 = D(0x803d0a20u);
    S32(r1 + 40, r9);
    r4 = L32(r29 + 36);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
    r9 = D(0x803d0000u);
    r3 = r24;
    r9 = D(0x803d0a2cu);
    S32(r1 + 44, r9);
    r4 = L32(r29 + 32);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
    r9 = D(0x803d0000u);
    r4 = L32(r29 + 28);
    r9 = D(0x803d0a3cu);
    r3 = r23;
    S32(r1 + 48, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x803d0000u);
    r4 = L32(r29 + 24);
    r9 = D(0x803d0a48u);
    r3 = r21;
    S32(r1 + 52, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x803d0000u);
    r3 = r20;
    r9 = D(0x803d0a54u);
    S32(r1 + 56, r9);
    r4 = L32(r29 + 40);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80297b78;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80297b78:
    r1 = r1 + 112;
    return r3;
}

// 0x80299a74 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8029d578 en 80299a80
__attribute__((weak)) w3d_u32 A80299a74(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8029d578)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

}
