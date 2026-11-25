// Funciones del juego sin fuente admitida: 0x801a7680 a 0x801fac8c. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A801a381c();
__attribute__((weak)) void A801a3944();
__attribute__((weak)) void A801a9478();
__attribute__((weak)) void A801ab05c();
__attribute__((weak)) void A801b01bc();
__attribute__((weak)) void A801b02c8();
__attribute__((weak)) void A801b0448();
__attribute__((weak)) void A801d7d78();
__attribute__((weak)) void A801e15c8();
__attribute__((weak)) void A801e15f4();
__attribute__((weak)) void A801e16b0();
__attribute__((weak)) void A801e183c();
__attribute__((weak)) void A801e1944();
__attribute__((weak)) void A801e194c();
__attribute__((weak)) void A801e3888();
__attribute__((weak)) void A801e38a4();
__attribute__((weak)) void A801e3d44();
__attribute__((weak)) void A801e3e70();
__attribute__((weak)) void A801e3eb8();
__attribute__((weak)) void A801e5b80();
__attribute__((weak)) void A801e5dfc();
__attribute__((weak)) void A801e5fd4();
__attribute__((weak)) void A801e6054();
__attribute__((weak)) void A801e8d9c();
__attribute__((weak)) void A801e9db8();
__attribute__((weak)) void A801ea470();
__attribute__((weak)) void A801ea59c();
__attribute__((weak)) void A801ef048();
__attribute__((weak)) void A801f68c8();
__attribute__((weak)) void A801f76b8();
__attribute__((weak)) void A801fe0b8();
__attribute__((weak)) void A801fe160();
__attribute__((weak)) void A801fe4d8();
__attribute__((weak)) void A801fe508();
__attribute__((weak)) void A801fffc8();
__attribute__((weak)) void A802098fc();
__attribute__((weak)) void A80209920();
__attribute__((weak)) void A8020998c();
__attribute__((weak)) void A802099b0();
__attribute__((weak)) void A802099d4();
__attribute__((weak)) void A8020bd38();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A8020d2b8();
__attribute__((weak)) void A8020d318();
__attribute__((weak)) void A8020d36c();
__attribute__((weak)) void A8020d82c();
__attribute__((weak)) void A8020da90();
__attribute__((weak)) void A8020dbf8();
__attribute__((weak)) void A8020fcb4();
__attribute__((weak)) void A802eee50();
__attribute__((weak)) void A802eefe0();
__attribute__((weak)) void A802ef234();
__attribute__((weak)) void A802f51e4();
__attribute__((weak)) void A802f5568();
__attribute__((weak)) void A802fb7ac();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A803426b8();
__attribute__((weak)) void A80343bb4();
__attribute__((weak)) void A80347324();
__attribute__((weak)) void A8035366c();
__attribute__((weak)) void A80353880();
__attribute__((weak)) void A80353ff0();
__attribute__((weak)) void A80354734();
__attribute__((weak)) void A80354e78();
__attribute__((weak)) void A80358118();

// 0x801a7680 FUN_801a7680 no verificada: desde bytes PPC
// Llama a vector_get. Hace 9 llamadas virtuales.
__attribute__((weak)) w3d_u32 A801a7680(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[120];
    w3d_u32 r1 = h2g(frame) + 104;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 104; S32(t_, r1); r1 = t_; }
    r21 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r23 = 0x0u;
    if ((cr0 & 2)) goto L_801a76a4;
    r23 = r3 - 4;
L_801a76a4:
    r9 = r23 + 64;
    r10 = L32(r23 + 64);
    r11 = L32(r9 + 4);
    r7 = r1 + 8;
    r8 = L32(r9 + 12);
    r0 = L32(r9 + 8);
    cr0 = CMPS(r10, r11);
    S32(r1 + 8, r10);
    S32(r1 + 16, r0);
    S32(r1 + 12, r11);
    S32(r1 + 20, r8);
    if (!(cr0 & 2)) goto L_801a76f4;
    r0 = r8 - 4;
    S32(r1 + 20, r0);
    r9 = L32(r8 - 4);
    r11 = r9 + 128;
    S32(r1 + 12, r9);
    S32(r1 + 16, r11);
    r0 = L32(r7 + 8);
    S32(r1 + 8, r0);
L_801a76f4:
    r9 = L32(r1 + 8);
    r3 = r21;
    r11 = L32(r21);
    r0 = r9 - 4;
    S32(r1 + 8, r0);
    r0 = L32(r11 + 20);
    r22 = L32(r9 - 4);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r22);
    r19 = r3;
    r3 = r22;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r19, r3);
    if ((cr0 & 2)) goto L_801a7748;
L_801a7738:
    r3 = 0x1u;
    goto L_801a7b2c;
L_801a7740:
    r3 = 0x1u;
    goto L_801a7b2c;
L_801a7748:
    r0 = L32(r19 + 64);
    r20 = 0x0u;
    r9 = L32(r19 + 60);
    r0 = r0 - r9;
    { w3d_u32 t_ = r0; r17 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r20, r17);
    if (!(cr0 & 8)) goto L_801a7b28;
    r18 = r23 + 4;
L_801a7768:
    r3 = r19;
    r4 = r20;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801e9db8)(W(r3), W(r4));
    r31 = r3;
    r9 = L32(r31);
    r0 = L8(r9 + 7);
    r3 = L32(r9 + 8);
    r9 = r0 & 0x4u; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801a7b1c;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801fffc8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    cr0 = CMPS(r3, 24);
    if (!(cr0 & 2)) goto L_801a7af8;
    r9 = L32(r31);
    r0 = L8(r9 + 7);
    r9 = r0 & 0x1u; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_801a7944;
    r9 = L32(r31 + 4);
    r5 = r1 + 24;
    r4 = r21;
    r3 = r31;
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r31 + 4);
    r26 = r3;
    r3 = r31;
    r4 = r22;
    r0 = L32(r9 + 32);
    r5 = r1 + 28;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r1 + 24);
    r27 = r3;
    r0 = L32(r1 + 28);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_801a7738;
    r24 = 0x0u;
    cr0 = CMPU(r24, r9);
    if (!(cr0 & 8)) goto L_801a7b1c;
    r25 = r23 + 4;
    r29 = 0x0u;
    r28 = r26;
L_801a7810:
    r8 = L32(r29 + r26);
    r0 = L32(r29 + r27);
    cr0 = CMPS(r8, r0);
    if ((cr0 & 2)) goto L_801a7928;
    r0 = L32(r23 + 44);
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_801a7740;
    r11 = r23 + 96;
    r9 = L32(r11 + 24);
    r30 = r11;
    r10 = L32(r11 + 16);
    r9 = r9 - 4;
    cr0 = CMPS(r10, r9);
    if ((cr0 & 2)) goto L_801a7864;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801a7854;
    S32(r10, r8);
L_801a7854:
    r9 = L32(r30 + 16);
    r9 = r9 + 4;
    S32(r30 + 16, r9);
    goto L_801a7870;
L_801a7864:
    r3 = r30;
    r4 = r28;
    ((void (*)(w3d_oarg, w3d_oarg))A80353880)(W(r3), W(r4));
L_801a7870:
    r11 = r23 + 48;
    r4 = r29 + r27;
    r9 = L32(r11 + 24);
    r31 = r11;
    r10 = L32(r11 + 16);
    r9 = r9 - 4;
    cr0 = CMPS(r10, r9);
    if ((cr0 & 2)) goto L_801a78b0;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801a78a0;
    r0 = L32(r29 + r27);
    S32(r10, r0);
L_801a78a0:
    r9 = L32(r31 + 16);
    r9 = r9 + 4;
    S32(r31 + 16, r9);
    goto L_801a78b8;
L_801a78b0:
    r3 = r31;
    ((void (*)(w3d_oarg, w3d_oarg))A80353880)(W(r3), W(r4));
L_801a78b8:
    r4 = L32(r29 + r26);
    r3 = r25;
    r11 = L32(r25 + 24);
    r9 = L16(r4 + 6);
    r9 = r9 << 2;
    r0 = L32(r9 + r11);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801a7b2c;
    r9 = L32(r31 + 16);
    r0 = L32(r31 + 20);
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_801a78fc;
    r0 = r9 - 4;
    S32(r31 + 16, r0);
    goto L_801a7904;
L_801a78fc:
    r3 = r31;
    ((void (*)(w3d_oarg))A8035366c)(W(r3));
L_801a7904:
    r9 = L32(r30 + 16);
    r0 = L32(r30 + 20);
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_801a7920;
    r0 = r9 - 4;
    S32(r30 + 16, r0);
    goto L_801a7928;
L_801a7920:
    r3 = r30;
    ((void (*)(w3d_oarg))A8035366c)(W(r3));
L_801a7928:
    r0 = L32(r1 + 24);
    r24 = r24 + 1;
    r29 = r29 + 4;
    r28 = r28 + 4;
    cr0 = CMPU(r24, r0);
    if ((cr0 & 8)) goto L_801a7810;
    goto L_801a7b1c;
L_801a7944:
    r9 = LS16(r31 + 14);
    cr0 = CMPS(r9, 0);
    if ((cr0 & 8)) goto L_801a7968;
    r0 = LS16(r31 + 16);
    r9 = r9 << 2;
    r11 = L32(r21 + r0);
    r9 = r9 + r11;
    r9 = L32(r9 - 4);
    goto L_801a796c;
L_801a7968:
    r9 = L32(r31 + 16);
L_801a796c:
    r3 = LS16(r31 + 12);
    lr = r9;
    r3 = r21 + r3;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = LS16(r31 + 14);
    S32(r1 + 36, r3);
    cr0 = CMPS(r9, 0);
    if ((cr0 & 8)) goto L_801a79a4;
    r0 = LS16(r31 + 16);
    r9 = r9 << 2;
    r11 = L32(r22 + r0);
    r9 = r9 + r11;
    r9 = L32(r9 - 4);
    goto L_801a79a8;
L_801a79a4:
    r9 = L32(r31 + 16);
L_801a79a8:
    r3 = LS16(r31 + 12);
    lr = r9;
    r3 = r22 + r3;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r1 + 36);
    S32(r1 + 32, r3);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801a79d8;
    cr0 = CMPS(r3, 0);
    r3 = 0x0u;
    if ((cr0 & 2)) goto L_801a7b2c;
    goto L_801a7738;
L_801a79d8:
    r8 = r3; cr0 = CMPS(r8, 0);
    if ((cr0 & 2)) goto L_801a7740;
    r0 = L32(r23 + 44);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_801a7aec;
    r11 = r23 + 48;
    r4 = r1 + 32;
    r9 = L32(r11 + 24);
    r31 = r11;
    r10 = L32(r11 + 16);
    r9 = r9 - 4;
    cr0 = CMPS(r10, r9);
    if ((cr0 & 2)) goto L_801a7a28;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801a7a18;
    S32(r10, r8);
L_801a7a18:
    r9 = L32(r31 + 16);
    r9 = r9 + 4;
    S32(r31 + 16, r9);
    goto L_801a7a30;
L_801a7a28:
    r3 = r31;
    ((void (*)(w3d_oarg, w3d_oarg))A80353880)(W(r3), W(r4));
L_801a7a30:
    r11 = r23 + 96;
    r4 = r1 + 36;
    r9 = L32(r11 + 24);
    r30 = r11;
    r10 = L32(r11 + 16);
    r9 = r9 - 4;
    cr0 = CMPS(r10, r9);
    if ((cr0 & 2)) goto L_801a7a70;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801a7a60;
    r0 = L32(r1 + 36);
    S32(r10, r0);
L_801a7a60:
    r9 = L32(r30 + 16);
    r9 = r9 + 4;
    S32(r30 + 16, r9);
    goto L_801a7a78;
L_801a7a70:
    r3 = r30;
    ((void (*)(w3d_oarg, w3d_oarg))A80353880)(W(r3), W(r4));
L_801a7a78:
    r4 = L32(r1 + 36);
    r3 = r18;
    r11 = L32(r18 + 24);
    r9 = L16(r4 + 6);
    r9 = r9 << 2;
    r0 = L32(r9 + r11);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801a7b2c;
    r9 = L32(r31 + 16);
    r0 = L32(r31 + 20);
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_801a7abc;
    r0 = r9 - 4;
    S32(r31 + 16, r0);
    goto L_801a7ac4;
L_801a7abc:
    r3 = r31;
    ((void (*)(w3d_oarg))A8035366c)(W(r3));
L_801a7ac4:
    r9 = L32(r30 + 16);
    r0 = L32(r30 + 20);
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_801a7ae0;
    r0 = r9 - 4;
    S32(r30 + 16, r0);
    goto L_801a7b1c;
L_801a7ae0:
    r3 = r30;
    ((void (*)(w3d_oarg))A8035366c)(W(r3));
    goto L_801a7b1c;
L_801a7aec:
    cr0 = CMPS(r9, r3);
    if ((cr0 & 2)) goto L_801a7b1c;
    goto L_801a7738;
L_801a7af8:
    r9 = L32(r31 + 4);
    r3 = r31;
    r4 = r21;
    r5 = r22;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801a7738;
L_801a7b1c:
    r20 = r20 + 1;
    cr0 = CMPU(r20, r17);
    if ((cr0 & 8)) goto L_801a7768;
L_801a7b28:
    r3 = 0x0u;
L_801a7b2c:
    r1 = r1 + 104;
    return r3;
}

// 0x801a936c FUN_801a936c no verificada: desde bytes PPC
// Llama a stl_sort, build_state_stream.
__attribute__((weak)) w3d_u32 A801a936c(w3d_u32 r3) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r9 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r0 = L32(r30 + 284);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_801a9394;
    r3 = L32(r30 + 176);
    goto L_801a9464;
L_801a9394:
    r0 = L32(r30 + 292);
    r29 = 0x0u;
    r9 = L32(r30 + 288);
    r0 = r0 - r9;
    { w3d_u32 t_ = r0; r28 = (w3d_u32)((w3d_s32)t_ >> 4); ca = SRAWCA(t_, 4); }
    cr0 = CMPU(r29, r28);
    if (!(cr0 & 8)) goto L_801a943c;
    r27 = 0x0u;
    r31 = 0x0u;
L_801a93b8:
    r9 = L32(r30 + 288);
    r11 = r9 + r31;
    r0 = L32(r11 + 12);
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_801a9400;
    if ((cr0 & 4)) goto L_801a93dc;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801a93e8;
    goto L_801a942c;
L_801a93dc:
    cr0 = CMPS(r0, 2);
    if ((cr0 & 2)) goto L_801a9418;
    goto L_801a942c;
L_801a93e8:
    S8(r1 + 8, r0);
    r5 = r1 + 8;
    r3 = L32(r9 + r31);
    r4 = L32(r11 + 4);
    ((void (*)(w3d_oarg, w3d_oarg))A80353ff0)(W(r3), W(r4));
    goto L_801a942c;
L_801a9400:
    S8(r1 + 8, r27);
    r5 = r1 + 8;
    r3 = L32(r9 + r31);
    r4 = L32(r11 + 4);
    ((void (*)(w3d_oarg, w3d_oarg))A80354734)(W(r3), W(r4));
    goto L_801a942c;
L_801a9418:
    S8(r1 + 8, r27);
    r5 = r1 + 8;
    r3 = L32(r9 + r31);
    r4 = L32(r11 + 4);
    ((void (*)(w3d_oarg, w3d_oarg))A80354e78)(W(r3), W(r4));
L_801a942c:
    r29 = r29 + 1;
    r31 = r31 + 16;
    cr0 = CMPU(r29, r28);
    if ((cr0 & 8)) goto L_801a93b8;
L_801a943c:
    r0 = L32(r30 + 160);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801a9454;
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_801a9460;
    goto L_801a9464;
L_801a9454:
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801a9478)(W(r3));
    goto L_801a9464;
L_801a9460:
    w3d_open_break(0x801a9460u);
L_801a9464:
    r1 = r1 + 40;
    return r3;
}

// 0x801aa9dc FUN_801aa9dc no verificada: desde bytes PPC
// Llama a multiply_affine. Hace 2 llamadas virtuales.
__attribute__((weak)) w3d_u32 A801aa9dc(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[112];
    w3d_u32 r1 = h2g(frame) + 96;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 96; S32(t_, r1); r1 = t_; }
    r31 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r29 = 0x0u;
    if ((cr0 & 2)) goto L_801aaa00;
    r29 = r3 - 4;
L_801aaa00:
    r5 = L32(r29 + 56);
    r3 = r1 + 8;
    r4 = r31 + 20;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A801f68c8)(W(r3), W(r4), W(r5));
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r8 = r1 + 8;
    r9 = D(0x80363a14u);
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_801aaa7c;
    f0 = LF(r31 + 72);
    r9 = D(0x803b0000u);
    f12 = LF(D(0x803aa0f8u));
    r10 = r31 + 72;
    SF(r1 + 8, f0);
    r9 = r1 + 24;
    SF(r8 + 4, f12);
    r11 = r1 + 40;
    SF(r8 + 8, f12);
    SF(r1 + 24, f12);
    f0 = LF(r10 + 4);
    SF(r9 + 8, f12);
    SF(r9 + 4, f0);
    f13 = LF(r10 + 8);
    SF(r1 + 40, f12);
    SF(r11 + 8, f13);
    SF(r11 + 4, f12);
L_801aaa7c:
    r9 = L32(r29 + 48);
    cr0 = CMPS(r29, 0);
    r27 = L32(r29 + 56);
    r28 = 0x0u;
    r9 = r9 + 1;
    S32(r29 + 56, r8);
    S32(r29 + 48, r9);
    r9 = r29 + 4;
    if ((cr0 & 2)) goto L_801aaaa4;
    r28 = r9;
L_801aaaa4:
    r9 = L32(r9 + 20);
    r11 = L32(r9 + 44);
    r0 = L32(r11 + 24);
    r31 = r11 + 32;
    r0 = r0 << 2;
    r30 = r31 + r0;
    cr0 = CMPS(r31, r30);
    if ((cr0 & 2)) goto L_801aaaf8;
L_801aaac4:
    r4 = L32(r31);
    r3 = r28;
    r9 = L32(r28 + 24);
    r0 = L16(r4 + 6);
    r0 = r0 << 2;
    r0 = L32(r9 + r0);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r3; cr0 = CMPS(r3, 0);
    if ((cr0 & 8)) goto L_801aaafc;
    r31 = r31 + 4;
    cr0 = CMPS(r31, r30);
    if (!(cr0 & 2)) goto L_801aaac4;
L_801aaaf8:
    r3 = 0x0u;
L_801aaafc:
    r9 = L32(r29 + 48);
    S32(r29 + 56, r27);
    r9 = r9 + 1;
    S32(r29 + 48, r9);
    r1 = r1 + 96;
    return r3;
}

// 0x801ab03c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ab03c(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    f1 = ((float (*)(w3d_oarg))A801ab05c)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x801add4c FUN_801add4c no verificada: desde bytes PPC
// Llama a invoke_ready_callback, array_ref_lock. Hace 3 llamadas virtuales. Algo de cálculo en coma flotante.
// aviso: lee r3 tras void 801f76b8 en 801add98
// aviso: lee r3 tras void 8020fcb4 en 801addac
__attribute__((weak)) w3d_u32 A801add4c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r29 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r31 = 0x0u;
    if ((cr0 & 2)) goto L_801add70;
    r31 = r3 - 4;
L_801add70:
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = r3 & 0x2u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801adf10;
    r9 = D(0x803b0000u);
    r3 = L32(r31 + 44);
    f1 = LF(D(0x803aa564u));
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, float))A801f76b8)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801adf10;
    r3 = D(0x80360000u);
    r3 = D(0x80363064u);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8020fcb4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801addcc;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801addcc:
    r3 = L32(r31 + 96);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801adde8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801adde8:
    S32(r31 + 96, r30);
    r11 = r30 + 20;
    r31 = L32(r31 + 44);
    r3 = L32(r30 + 20);
    r9 = L32(r29 + 20);
    r0 = L16(r3 + 4);
    r30 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r0, 1);
    r4 = r30;
    if (!(cr0 & 2)) goto L_801ade34;
    r0 = L32(r3 + 24);
    cr0 = CMPS(r30, r0);
    if (!(cr0 & 2)) goto L_801ade34;
    r9 = L16(r3 + 28);
    r0 = r3 + 32;
    r9 = r9 + 1;
    S16(r3 + 28, r9);
    goto L_801ade48;
L_801ade34:
    r3 = r11;
    r5 = 0xcu;
    r6 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r0 = r3;
L_801ade48:
    r11 = 0x0u;
    cr0 = CMPU(r11, r30);
    if (!(cr0 & 8)) goto L_801adf10;
    r4 = r30;
    r9 = r29;
    r3 = r0;
    r7 = r31 + 12;
    r8 = r31 + 24;
    r10 = r31 + 36;
L_801ade6c:
    f11 = LF(r9 + 4);
    r11 = r11 + 1;
    f13 = LF(r31 + 12);
    cr0 = CMPU(r11, r4);
    f12 = LF(r9);
    f9 = LF(r31);
    f11 = (float)(f11 * f13);
    f0 = LF(r9 + 8);
    f10 = LF(r31 + 24);
    f12 = __builtin_fmaf((float)f12, (float)f9, (float)f11);
    f13 = LF(r31 + 36);
    f0 = __builtin_fmaf((float)f0, (float)f10, (float)f12);
    f0 = (float)(f0 + f13);
    SF(r3, f0);
    f12 = LF(r9 + 4);
    f13 = LF(r7 + 4);
    f11 = LF(r9);
    f9 = LF(r31 + 4);
    f12 = (float)(f12 * f13);
    f0 = LF(r9 + 8);
    f10 = LF(r8 + 4);
    f11 = __builtin_fmaf((float)f11, (float)f9, (float)f12);
    f13 = LF(r10 + 4);
    f0 = __builtin_fmaf((float)f0, (float)f10, (float)f11);
    f0 = (float)(f0 + f13);
    SF(r3 + 4, f0);
    f13 = LF(r9 + 4);
    f11 = LF(r7 + 8);
    f12 = LF(r9);
    f10 = LF(r31 + 8);
    f13 = (float)(f13 * f11);
    f0 = LF(r9 + 8);
    f9 = LF(r8 + 8);
    f12 = __builtin_fmaf((float)f12, (float)f10, (float)f13);
    f11 = LF(r10 + 8);
    r9 = r9 + 12;
    f0 = __builtin_fmaf((float)f0, (float)f9, (float)f12);
    f0 = (float)(f0 + f11);
    SF(r3 + 8, f0);
    r3 = r3 + 12;
    if ((cr0 & 8)) goto L_801ade6c;
L_801adf10:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x801adf28 FUN_801adf28 no verificada: desde bytes PPC
// Llama a invoke_ready_callback, array_ref_lock, record12_at. Hace 3 llamadas virtuales. Algo de cálculo en coma flotante.
// aviso: lee r3 tras void 801f76b8 en 801adf74
// aviso: lee r3 tras void 8020fcb4 en 801adf88
__attribute__((weak)) w3d_u32 A801adf28(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f10 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r29 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_801adf4c;
    r30 = r3 - 4;
L_801adf4c:
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = r3 & 0x2u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801ae144;
    r9 = D(0x803b0000u);
    r3 = L32(r30 + 44);
    f1 = LF(D(0x803aa568u));
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, float))A801f76b8)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801ae144;
    r3 = D(0x80360000u);
    r3 = D(0x803632e4u);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8020fcb4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r31 = r3; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_801adfa8;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801adfa8:
    r3 = L32(r30 + 96);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801adfc4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801adfc4:
    S32(r30 + 96, r31);
    r11 = r31 + 20;
    r28 = r30 + 48;
    r3 = L32(r31 + 20);
    r9 = L32(r29 + 20);
    r0 = L16(r3 + 4);
    r25 = L32(r9 + 24);
    r31 = r9 + 32;
    cr0 = CMPS(r0, 1);
    r4 = r25;
    if (!(cr0 & 2)) goto L_801ae010;
    r0 = L32(r3 + 24);
    cr0 = CMPS(r25, r0);
    if (!(cr0 & 2)) goto L_801ae010;
    r9 = L16(r3 + 28);
    r0 = r3 + 32;
    r9 = r9 + 1;
    S16(r3 + 28, r9);
    goto L_801ae024;
L_801ae010:
    r3 = r11;
    r5 = 0xcu;
    r6 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r0 = r3;
L_801ae024:
    r26 = 0x0u;
    cr0 = CMPU(r26, r25);
    if (!(cr0 & 8)) goto L_801ae144;
    r27 = r0;
L_801ae034:
    r4 = 0x0u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    r26 = r26 + 1;
    r29 = r3;
    r4 = 0x1u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x2u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    f0 = LF(r30);
    r4 = 0x0u;
    f13 = LF(r31 + 4);
    f10 = LF(r29);
    f13 = (float)(f13 * f0);
    f12 = LF(r31);
    f11 = LF(r3);
    f0 = LF(r31 + 8);
    f12 = __builtin_fmaf((float)f12, (float)f10, (float)f13);
    r3 = r28;
    f0 = __builtin_fmaf((float)f0, (float)f11, (float)f12);
    SF(r27, f0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    r29 = r3;
    r4 = 0x1u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x2u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    f0 = LF(r30 + 4);
    r4 = 0x0u;
    f13 = LF(r31 + 4);
    f10 = LF(r29 + 4);
    f13 = (float)(f13 * f0);
    f12 = LF(r31);
    f11 = LF(r3 + 4);
    f0 = LF(r31 + 8);
    f12 = __builtin_fmaf((float)f12, (float)f10, (float)f13);
    r3 = r28;
    f0 = __builtin_fmaf((float)f0, (float)f11, (float)f12);
    SF(r27 + 4, f0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    r29 = r3;
    r4 = 0x1u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x2u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80343bb4)(W(r3), W(r4));
    f0 = LF(r30 + 8);
    cr0 = CMPU(r26, r25);
    f13 = LF(r31 + 4);
    f12 = LF(r31);
    f10 = LF(r29 + 8);
    f13 = (float)(f13 * f0);
    f0 = LF(r31 + 8);
    f11 = LF(r3 + 8);
    f12 = __builtin_fmaf((float)f12, (float)f10, (float)f13);
    r31 = r31 + 12;
    f0 = __builtin_fmaf((float)f0, (float)f11, (float)f12);
    SF(r27 + 8, f0);
    r27 = r27 + 12;
    if ((cr0 & 8)) goto L_801ae034;
L_801ae144:
    r3 = 0x0u;
    r1 = r1 + 40;
    return r3;
}

// 0x801afac0 FUN_801afac0 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: surface_prepare. Llama a array_ref_lock.
__attribute__((weak)) w3d_u32 A801afac0(w3d_u32 r3) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r0 = L32(r29 + 24);
    cr0 = CMPS(r0, 11);
    if ((cr0 & 2)) goto L_801afb74;
    if ((cr0 & 4)) goto L_801afb18;
    cr0 = CMPS(r0, 5);
    if ((cr0 & 4)) goto L_801afb04;
    cr0 = CMPS(r0, 3);
    if (!(cr0 & 8)) goto L_801afb84;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801afb6c;
    if ((cr0 & 8)) goto L_801afd48;
    goto L_801afb74;
L_801afb04:
    cr0 = CMPS(r0, 9);
    if ((cr0 & 4)) goto L_801afb8c;
    cr0 = CMPS(r0, 8);
    if (!(cr0 & 8)) goto L_801afb7c;
    goto L_801afb8c;
L_801afb18:
    cr0 = CMPS(r0, 18);
    if ((cr0 & 2)) goto L_801afb84;
    if ((cr0 & 4)) goto L_801afb38;
    cr0 = CMPS(r0, 16);
    if ((cr0 & 4)) goto L_801afb94;
    cr0 = CMPS(r0, 15);
    if (!(cr0 & 8)) goto L_801afb8c;
    goto L_801afb84;
L_801afb38:
    cr0 = CMPS(r0, 22);
    if ((cr0 & 2)) goto L_801afb84;
    if ((cr0 & 4)) goto L_801afb58;
    cr0 = CMPS(r0, 19);
    if ((cr0 & 2)) goto L_801afb8c;
    cr0 = CMPS(r0, 20);
    if ((cr0 & 2)) goto L_801afb94;
    goto L_801afd48;
L_801afb58:
    cr0 = CMPS(r0, 23);
    if ((cr0 & 2)) goto L_801afb8c;
    cr0 = CMPS(r0, 24);
    if ((cr0 & 2)) goto L_801afb7c;
    goto L_801afd48;
L_801afb6c:
    r27 = 0x18u;
    goto L_801afb98;
L_801afb74:
    r27 = 0x20u;
    goto L_801afb98;
L_801afb7c:
    r27 = 0x4u;
    goto L_801afb98;
L_801afb84:
    r27 = 0x10u;
    goto L_801afb98;
L_801afb8c:
    r27 = 0x8u;
    goto L_801afb98;
L_801afb94:
    w3d_open_break(0x801afb94u);
L_801afb98:
    r11 = L32(r29 + 32);
    r3 = r29 + 32;
    r30 = L16(r29 + 46);
    r0 = L16(r11 + 4);
    r31 = L16(r29 + 44);
    cr0 = CMPS(r0, 1);
    r28 = L16(r29 + 42);
    if (!(cr0 & 2)) goto L_801afbd8;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r28, r0);
    if (!(cr0 & 2)) goto L_801afbd8;
    r9 = L16(r11 + 28);
    r26 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801afbec;
L_801afbd8:
    r4 = r28;
    r5 = 0x4u;
    r6 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r26 = r3;
L_801afbec:
    r11 = L32(r29 + 28);
    r3 = r29 + 28;
    r0 = L16(r11 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801afc20;
    r0 = L32(r11 + 24);
    cr0 = CMPS(r28, r0);
    if (!(cr0 & 2)) goto L_801afc20;
    r9 = L16(r11 + 28);
    r3 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801afc30;
L_801afc20:
    r4 = r28;
    r5 = 0x4u;
    r6 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_801afc30:
    r4 = 0x0u;
    r7 = 0x0u;
    cr0 = CMPU(r4, r28);
    r6 = r29 + 48;
    if (!(cr0 & 8)) goto L_801afd0c;
    r8 = 0x0u;
L_801afc48:
    r0 = (w3d_s32)r30 * (w3d_s32)r27;
    r11 = L32(r29 + 24);
    r9 = r31;
    cr0 = CMPS(r11, 17);
    r10 = r0 >> 3;
    if ((cr0 & 2)) goto L_801afca4;
    if (!(cr0 & 4)) goto L_801afc84;
    cr0 = CMPS(r11, 19);
    if ((cr0 & 2)) goto L_801afc94;
    if ((cr0 & 8)) goto L_801afcb8;
    cr0 = CMPS(r11, 20);
    if ((cr0 & 2)) goto L_801afca4;
    cr0 = CMPS(r11, 22);
    if ((cr0 & 2)) goto L_801afcb8;
    goto L_801afcd0;
L_801afc84:
    cr0 = CMPS(r11, 11);
    if ((cr0 & 8)) goto L_801afcd0;
    cr0 = CMPS(r11, 14);
    if (!(cr0 & 4)) goto L_801afcb8;
L_801afc94:
    r0 = r30 + 7;
    r9 = r31 + 3;
    r0 = r0 & 0xfffffff8u;
    goto L_801afcc4;
L_801afca4:
    r0 = r30 + 7;
    r9 = r31 + 7;
    r0 = r0 & 0xfffffff8u;
    r9 = r9 & 0xfffffff8u;
    goto L_801afcc8;
L_801afcb8:
    r0 = r30 + 3;
    r9 = r31 + 3;
    r0 = r0 & 0xfffffffcu;
L_801afcc4:
    r9 = r9 & 0xfffffffcu;
L_801afcc8:
    r0 = (w3d_s32)r0 * (w3d_s32)r27;
    r10 = r0 >> 3;
L_801afcd0:
    r0 = (w3d_s32)r10 * (w3d_s32)r9;
    S32(r8 + r26, r10);
    S32(r8 + r3, r4);
    r31 = r31 >> 1;
    r30 = r30 >> 1; cr0 = CMPS(r30, 0);
    r4 = r4 + r0;
    if (!(cr0 & 2)) goto L_801afcf0;
    r30 = 0x1u;
L_801afcf0:
    cr0 = CMPS(r31, 0);
    if (!(cr0 & 2)) goto L_801afcfc;
    r31 = 0x1u;
L_801afcfc:
    r7 = r7 + 1;
    r8 = r8 + 4;
    cr0 = CMPU(r7, r28);
    if ((cr0 & 8)) goto L_801afc48;
L_801afd0c:
    r3 = L32(r29 + 48);
    r0 = L16(r3 + 4);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801afd38;
    r0 = L32(r3 + 24);
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_801afd38;
    r9 = L16(r3 + 28);
    r9 = r9 + 1;
    S16(r3 + 28, r9);
    goto L_801afd48;
L_801afd38:
    r3 = r6;
    r5 = 0x1u;
    r6 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
L_801afd48:
    r1 = r1 + 32;
    return r3;
}

// 0x801afd5c FUN_801afd5c no verificada: desde bytes PPC
// Llama a surface_prepare, array_ref_lock. Hace 2 llamadas virtuales.
__attribute__((weak)) w3d_u32 A801afd5c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r25 = r4;
    r30 = L32(r31 + 48);
    r26 = r5;
    r24 = L16(r31 + 46);
    r29 = r31 + 48;
    r9 = L32(r30);
    r3 = r30;
    r11 = r3;
    r23 = L16(r31 + 44);
    r0 = L32(r9 + 12);
    r28 = r11 + 32;
    r9 = L32(r31 + 32);
    lr = r0;
    r27 = L32(r9 + 32);
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = 0x1u;
    S16(r31 + 46, r25);
    S16(r31 + 44, r26);
    r3 = r31;
    S16(r31 + 42, r0);
    r3 = A801afac0(r3);
    r11 = L32(r31 + 48);
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801afdec;
    r9 = L16(r11 + 28);
    r7 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801afe00;
L_801afdec:
    r3 = r29;
    r5 = 0x1u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r7 = r3;
L_801afe00:
    r9 = L32(r31 + 32);
    r3 = r28;
    r0 = L32(r31 + 24);
    r4 = r27;
    r8 = L32(r9 + 32);
    r5 = r24;
    S32(r1 + 8, r0);
    r9 = r25;
    r6 = r23;
    r10 = r26;
    r3 = A801b0a14(r3, r4, r5, r6, r7, r8, r9, r10, L32(r1 + 8));
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 56;
    return r3;
}

// 0x801afe54 FUN_801afe54 no verificada: desde bytes PPC
// Llama a fetch, surface_prepare, array_ref_lock. Hace 3 llamadas virtuales.
__attribute__((weak)) w3d_u32 A801afe54(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[80];
    w3d_u32 r1 = h2g(frame) + 64;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f13 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 64; S32(t_, r1); r1 = t_; }
    r12 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    S32(r1 + 36, r12);
    r31 = r3;
    r30 = r4;
    r0 = L16(r31 + 42);
    r10 = L32(r31 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801b01a0;
    r11 = L32(r31 + 32);
    cr0 = CMPS(r10, 3);
    r9 = L32(r31 + 48);
    r26 = L32(r11 + 32);
    r27 = r9 + 32;
    if ((cr0 & 2)) goto L_801b01a0;
    if ((cr0 & 4)) goto L_801afeb8;
    cr0 = CMPS(r10, 1);
    if ((cr0 & 2)) goto L_801b01a0;
    cr4 = CMPS(r10, 0);
    if ((cr0 & 4)) goto L_801afec0;
    if ((cr4 & 2)) goto L_801afec0;
    goto L_801b01a0;
L_801afeb8:
    cr0 = CMPS(r10, 5);
    goto L_801b01a0;
L_801afec0:
    f0 = LF(r30);
    f13 = LF(r30 + 4);
    r8 = r11;
    PSQS_U8(r1 + 24, f0);
    r7 = r11;
    f0 = LF(r30 + 8);
    r28 = 0x4u;
    r9 = L8(r1 + 24);
    PSQS_U8(r1 + 24, f13);
    r9 = r9 & 0xffu;
    r10 = L8(r1 + 24);
    r0 = r9 << 8;
    PSQS_U8(r1 + 24, f0);
    r0 = r0 - r9;
    r10 = r10 & 0xffu;
    r4 = r0 & 0xffu;
    r11 = L8(r1 + 24);
    r9 = r10 << 8;
    r9 = r9 - r10;
    r11 = r11 & 0xffu;
    r9 = r9 & 0xffu;
    r0 = r11 << 8;
    r0 = r0 - r11;
    r5 = r0 & 0xffu;
    if (!(cr4 & 2)) goto L_801aff28;
    r28 = 0x3u;
L_801aff28:
    r11 = L16(r31 + 44);
    r7 = 0x0u;
    cr0 = CMPU(r7, r11);
    if (!(cr0 & 8)) goto L_801b01a0;
    r0 = L16(r31 + 46);
    r29 = r11;
    r6 = 0x0u;
    r12 = r0;
    r3 = r0 & 0xffffu;
L_801aff4c:
    r10 = 0x0u;
    r11 = r27 + r6;
    cr0 = CMPU(r10, r3);
    if (!(cr0 & 8)) goto L_801aff94;
    r8 = r12 & 0xffffu;
L_801aff60:
    r0 = L8(r11);
    cr0 = CMPS(r0, r4);
    if (!(cr0 & 2)) goto L_801aff84;
    r0 = L8(r11 + 1);
    cr0 = CMPS(r0, r9);
    if (!(cr0 & 2)) goto L_801aff84;
    r0 = L8(r11 + 2);
    cr0 = CMPS(r0, r5);
    if ((cr0 & 2)) goto L_801affa8;
L_801aff84:
    r10 = r10 + 1;
    r11 = r11 + r28;
    cr0 = CMPU(r10, r8);
    if ((cr0 & 8)) goto L_801aff60;
L_801aff94:
    r7 = r7 + 1;
    r6 = r6 + r26;
    cr0 = CMPU(r7, r29);
    if ((cr0 & 8)) goto L_801aff4c;
    goto L_801b01a0;
L_801affa8:
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801ea470)(W(r3));
    S32(r1 + 8, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801affcc;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801affcc:
    r0 = 0x1u;
    r3 = r31;
    S32(r31 + 24, r0);
    r3 = A801afac0(r3);
    r11 = L32(r31 + 48);
    r3 = r31 + 48;
    r0 = L16(r11 + 4);
    r4 = L32(r11 + 24);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_801b0008;
    r9 = L16(r11 + 28);
    r29 = r11 + 32;
    r9 = r9 + 1;
    S16(r11 + 28, r9);
    goto L_801b0018;
L_801b0008:
    r5 = 0x1u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r29 = r3;
L_801b0018:
    r3 = L32(r1 + 8);
    r9 = L32(r31 + 32);
    r0 = L32(r3 + 24);
    r28 = L32(r9 + 32);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801b0054;
    cr0 = CMPS(r0, 2);
    if (!(cr0 & 2)) goto L_801b0174;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801b01a0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_801b01a0;
L_801b0054:
    f0 = LF(r30);
    f13 = LF(r30 + 4);
    r8 = r11;
    PSQS_U8(r1 + 24, f0);
    r7 = r11;
    f0 = LF(r30 + 8);
    r9 = L8(r1 + 24);
    r30 = 0x4u;
    PSQS_U8(r1 + 24, f13);
    r9 = r9 & 0xffu;
    r10 = L8(r1 + 24);
    r0 = r9 << 8;
    PSQS_U8(r1 + 24, f0);
    r0 = r0 - r9;
    r10 = r10 & 0xffu;
    r3 = r0 & 0xffu;
    r11 = L8(r1 + 24);
    r9 = r10 << 8;
    r9 = r9 - r10;
    r11 = r11 & 0xffu;
    r12 = r9 & 0xffu;
    r0 = r11 << 8;
    r0 = r0 - r11;
    r4 = r0 & 0xffu;
    if (!(cr4 & 2)) goto L_801b00bc;
    r30 = 0x3u;
L_801b00bc:
    r0 = L16(r31 + 44);
    r10 = 0x0u;
    cr0 = CMPU(r10, r0);
    if (!(cr0 & 8)) goto L_801b0174;
L_801b00cc:
    r11 = (w3d_s32)r10 * (w3d_s32)r28;
    r9 = L16(r31 + 46);
    r7 = 0x0u;
    r0 = (w3d_s32)r10 * (w3d_s32)r26;
    r6 = r10 + 1;
    cr0 = CMPU(r7, r9);
    r11 = r29 + r11;
    r10 = r27 + r0;
    if (!(cr0 & 8)) goto L_801b0164;
    r8 = 0x0u;
    r5 = 0xffu;
L_801b00f8:
    r0 = L8(r10);
    r9 = r0;
    cr0 = CMPS(r0, r3);
    if (!(cr0 & 2)) goto L_801b0134;
    r0 = L8(r10 + 1);
    cr0 = CMPS(r0, r12);
    if (!(cr0 & 2)) goto L_801b0134;
    r0 = L8(r10 + 2);
    cr0 = CMPS(r0, r4);
    if (!(cr0 & 2)) goto L_801b0134;
    S8(r11, r8);
    S8(r11 + 1, r8);
    S8(r11 + 2, r8);
    S8(r11 + 3, r8);
    goto L_801b014c;
L_801b0134:
    S8(r11, r9);
    r0 = L8(r10 + 1);
    S8(r11 + 1, r0);
    r9 = L8(r10 + 2);
    S8(r11 + 3, r5);
    S8(r11 + 2, r9);
L_801b014c:
    r0 = L16(r31 + 46);
    r7 = r7 + 1;
    r10 = r10 + r30;
    r11 = r11 + 4;
    cr0 = CMPU(r7, r0);
    if ((cr0 & 8)) goto L_801b00f8;
L_801b0164:
    r0 = L16(r31 + 44);
    r10 = r6;
    cr0 = CMPU(r10, r0);
    if ((cr0 & 8)) goto L_801b00cc;
L_801b0174:
    r0 = L16(r31 + 40);
    r3 = L32(r1 + 8);
    r0 = r0 & 0xfff9u; cr0 = CMPS(r0, 0);
    r0 = r0 | 0x4u;
    cr0 = CMPS(r3, 0);
    S16(r31 + 40, r0);
    if ((cr0 & 2)) goto L_801b01a0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801b01a0:
    r12 = L32(r1 + 36);
    cr4 = (r12 >> 12) & 15;
    r1 = r1 + 64;
    return r3;
}

// 0x801b05b0 FUN_801b05b0 no verificada: desde bytes PPC
// Función de 137 instrucciones sin destinos con nombre ni cadenas.
__attribute__((weak)) w3d_u32 A801b05b0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10) {
    alignas(16) char frame[80];
    w3d_u32 r1 = h2g(frame) + 64;
    w3d_u32 r0 = 0, r11 = 0, r12 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 64; S32(t_, r1); r1 = t_; }
    r0 = r10 + r10;
    r27 = r4;
    cr0 = CMPS(r6, r0);
    r4 = r7;
    if (!(cr0 & 2)) goto L_801b07c4;
    r0 = r8 + r8;
    cr0 = CMPS(r27, r0);
    if (!(cr0 & 2)) goto L_801b07c4;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801b07c8;
    r28 = r5 + r5;
    r0 = r9 + r9;
    r25 = r0 - r8;
    r26 = r28;
L_801b05f0:
    r30 = r3 + r28;
    r29 = r10 - 1;
    cr0 = CMPS(r3, r30);
    if ((cr0 & 2)) goto L_801b07b0;
    r0 = r3 + 2;
    r5 = r1 + 8;
    r7 = r0 + r27;
    r31 = 0xffu;
L_801b0610:
    r0 = L16(r3);
    r9 = ROTL(r0, 3) & 0xf8u;
    r11 = ROTL(r0, 30) & 0xf8u;
    r10 = r0 >> 15; cr0 = CMPS(r10, 0);
    S8(r1 + 8, r9);
    r0 = ROTL(r0, 25) & 0xf8u;
    S8(r5 + 1, r11);
    S8(r5 + 2, r0);
    if ((cr0 & 2)) goto L_801b063c;
    S8(r5 + 3, r31);
    goto L_801b0640;
L_801b063c:
    S8(r5 + 3, r10);
L_801b0640:
    r0 = L16(r3 + 2);
    r10 = r1 + 12;
    r9 = ROTL(r0, 3) & 0xf8u;
    r11 = ROTL(r0, 30) & 0xf8u;
    r8 = r0 >> 15; cr0 = CMPS(r8, 0);
    S8(r1 + 12, r9);
    r0 = ROTL(r0, 25) & 0xf8u;
    S8(r1 + 13, r11);
    S8(r1 + 14, r0);
    if ((cr0 & 2)) goto L_801b0670;
    S8(r10 + 3, r31);
    goto L_801b0674;
L_801b0670:
    S8(r10 + 3, r8);
L_801b0674:
    r0 = L16(r7 - 2);
    r10 = r1 + 16;
    r9 = ROTL(r0, 3) & 0xf8u;
    r11 = ROTL(r0, 30) & 0xf8u;
    r8 = r0 >> 15; cr0 = CMPS(r8, 0);
    S8(r1 + 16, r9);
    r0 = ROTL(r0, 25) & 0xf8u;
    S8(r1 + 17, r11);
    S8(r1 + 18, r0);
    if ((cr0 & 2)) goto L_801b06a4;
    S8(r10 + 3, r31);
    goto L_801b06a8;
L_801b06a4:
    S8(r10 + 3, r8);
L_801b06a8:
    r0 = L16(r7);
    r10 = r1 + 20;
    r9 = ROTL(r0, 3) & 0xf8u;
    r11 = ROTL(r0, 30) & 0xf8u;
    r8 = r0 >> 15; cr0 = CMPS(r8, 0);
    S8(r1 + 20, r9);
    r0 = ROTL(r0, 25) & 0xf8u;
    S8(r1 + 21, r11);
    S8(r1 + 22, r0);
    if ((cr0 & 2)) goto L_801b06d8;
    S8(r10 + 3, r31);
    goto L_801b06dc;
L_801b06d8:
    S8(r10 + 3, r8);
L_801b06dc:
    r0 = L8(r1 + 8);
    r9 = L8(r1 + 12);
    r10 = L8(r1 + 16);
    r0 = r0 + r9;
    r11 = L8(r1 + 20);
    r0 = r0 + r10;
    r8 = r0 + r11;
    r9 = L8(r1 + 13);
    { w3d_u32 t_ = r8; r8 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r0 = L8(r1 + 9);
    r11 = L8(r1 + 17);
    r0 = r0 + r9;
    r10 = L8(r1 + 21);
    r0 = r0 + r11;
    S8(r1 + 24, r8);
    r9 = r0 + r10;
    { w3d_u32 t_ = r9; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r8 = r1 + 24;
    S8(r8 + 1, r9);
    r12 = r9;
    r9 = L8(r1 + 14);
    r0 = L8(r1 + 10);
    r10 = L8(r1 + 18);
    r0 = r0 + r9;
    r11 = L8(r1 + 22);
    r0 = r0 + r10;
    r9 = r0 + r11;
    { w3d_u32 t_ = r9; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S8(r8 + 2, r0);
    r6 = r0;
    r9 = L8(r1 + 11);
    r0 = L8(r1 + 15);
    r10 = L8(r1 + 19);
    r9 = r9 + r0;
    r11 = L8(r1 + 23);
    r9 = r9 + r10;
    r9 = r9 + r11;
    { w3d_u32 t_ = r9; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r10 = ROTL(r12, 2) & 0x3e0u;
    S8(r8 + 3, r9);
    r11 = ROTL(r6, 7) & 0x7c00u;
    r9 = ROTL(r9, 8) & 0x8000u;
    r3 = r3 + 4;
    r0 = L8(r1 + 24);
    r7 = r7 + 4;
    cr0 = CMPS(r3, r30);
    r0 = r0 >> 3;
    r0 = r0 | r10;
    r0 = r0 | r11;
    r0 = r0 | r9;
    S16(r4, r0);
    r4 = r4 + 2;
    if (!(cr0 & 2)) goto L_801b0610;
L_801b07b0:
    r3 = r3 + r26;
    r4 = r4 + r25;
    r10 = r29; cr0 = CMPS(r10, 0);
    if (!(cr0 & 2)) goto L_801b05f0;
    goto L_801b07c8;
L_801b07c4:
    w3d_open_break(0x801b07c4u);
L_801b07c8:
    r1 = r1 + 64;
    return r3;
}

// 0x801b07d4 FUN_801b07d4 no verificada: desde bytes PPC
// Función de 117 instrucciones sin destinos con nombre ni cadenas.
__attribute__((weak)) w3d_u32 A801b07d4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10) {
    alignas(16) char frame[88];
    w3d_u32 r1 = h2g(frame) + 72;
    w3d_u32 r0 = 0, r11 = 0, r12 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 72; S32(t_, r1); r1 = t_; }
    r0 = r10 + r10;
    r31 = r4;
    cr0 = CMPS(r6, r0);
    r12 = r7;
    if (!(cr0 & 2)) goto L_801b0998;
    r0 = r8 + r8;
    cr0 = CMPS(r31, r0);
    if (!(cr0 & 2)) goto L_801b0998;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801b099c;
    r25 = r5 + r5;
    r0 = r9 + r9;
    r23 = r0 - r8;
    r24 = r25;
L_801b0814:
    r30 = r3 + r25;
    r29 = r10 - 1;
    cr0 = CMPS(r3, r30);
    if ((cr0 & 2)) goto L_801b0984;
    r5 = r1 + 8;
    r4 = 0xffu;
    r26 = r1 + 12;
    r27 = r1 + 16;
    r28 = r1 + 20;
L_801b0838:
    r0 = L16(r3);
    r7 = r3 + r31;
    r11 = L16(r3 + 2);
    r9 = ROTL(r0, 3) & 0xf8u;
    r10 = ROTL(r0, 24) & 0xf8u;
    S8(r1 + 8, r9);
    r0 = ROTL(r0, 29) & 0xfcu;
    S8(r5 + 2, r10);
    r8 = ROTL(r11, 24) & 0xf8u;
    S8(r5 + 3, r4);
    r9 = ROTL(r11, 3) & 0xf8u;
    S8(r5 + 1, r0);
    r11 = ROTL(r11, 29) & 0xfcu;
    r0 = L16(r3 + r31);
    S8(r1 + 12, r9);
    S8(r1 + 13, r11);
    r10 = ROTL(r0, 24) & 0xf8u;
    S8(r1 + 14, r8);
    r9 = ROTL(r0, 3) & 0xf8u;
    S8(r26 + 3, r4);
    r0 = ROTL(r0, 29) & 0xfcu;
    S8(r1 + 16, r9);
    S8(r1 + 18, r10);
    S8(r1 + 17, r0);
    S8(r27 + 3, r4);
    r0 = L16(r7 + 2);
    r11 = ROTL(r0, 24) & 0xf8u;
    r9 = ROTL(r0, 3) & 0xf8u;
    r0 = ROTL(r0, 29) & 0xfcu;
    S8(r1 + 20, r9);
    S8(r1 + 21, r0);
    S8(r1 + 22, r11);
    S8(r28 + 3, r4);
    r0 = L8(r1 + 8);
    r9 = L8(r1 + 12);
    r10 = L8(r1 + 16);
    r0 = r0 + r9;
    r11 = L8(r1 + 20);
    r0 = r0 + r10;
    r8 = r0 + r11;
    r9 = L8(r1 + 13);
    { w3d_u32 t_ = r8; r8 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r0 = L8(r1 + 9);
    r11 = L8(r1 + 17);
    r0 = r0 + r9;
    r10 = L8(r1 + 21);
    r0 = r0 + r11;
    S8(r1 + 24, r8);
    r9 = r0 + r10;
    { w3d_u32 t_ = r9; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r8 = r1 + 24;
    S8(r8 + 1, r9);
    r6 = r9;
    r9 = L8(r1 + 14);
    r0 = L8(r1 + 10);
    r10 = L8(r1 + 18);
    r0 = r0 + r9;
    r11 = L8(r1 + 22);
    r0 = r0 + r10;
    r9 = r0 + r11;
    { w3d_u32 t_ = r9; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S8(r8 + 2, r0);
    r7 = r0;
    r9 = L8(r1 + 11);
    r0 = L8(r1 + 15);
    r10 = L8(r1 + 19);
    r9 = r9 + r0;
    r11 = L8(r1 + 23);
    r9 = r9 + r10;
    r9 = r9 + r11;
    { w3d_u32 t_ = r9; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r11 = ROTL(r6, 3) & 0x7e0u;
    S8(r8 + 3, r0);
    r9 = ROTL(r7, 8) & 0xf800u;
    r3 = r3 + 4;
    r0 = L8(r1 + 24);
    cr0 = CMPS(r3, r30);
    r0 = r0 >> 3;
    r0 = r0 | r11;
    r0 = r0 | r9;
    S16(r12, r0);
    r12 = r12 + 2;
    if (!(cr0 & 2)) goto L_801b0838;
L_801b0984:
    r3 = r3 + r24;
    r12 = r12 + r23;
    r10 = r29; cr0 = CMPS(r10, 0);
    if (!(cr0 & 2)) goto L_801b0814;
    goto L_801b099c;
L_801b0998:
    w3d_open_break(0x801b0998u);
L_801b099c:
    r1 = r1 + 72;
    return r3;
}

// 0x801b09a8 FUN_801b09a8 no verificada: desde bytes PPC
// Función de 27 instrucciones sin destinos con nombre ni cadenas.
__attribute__((weak)) w3d_u32 A801b09a8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10) {
    w3d_u32 r0 = 0, r11 = 0;
    w3d_u32 cr0 = 0;
    r0 = r10 + r10;
    cr0 = CMPS(r6, r0);
    if (!(cr0 & 2)) goto L_801b0a0c;
    r0 = r8 + r8;
    cr0 = CMPS(r4, r0);
    if (!(cr0 & 2)) goto L_801b0a0c;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) return r3;
    r8 = r9 - r8;
    r6 = r5;
L_801b09d0:
    r11 = r3 + r5;
    r10 = r10 - 1;
    cr0 = CMPS(r3, r11);
    if ((cr0 & 2)) goto L_801b09f8;
L_801b09e0:
    r0 = L8(r3);
    r3 = r3 + 2;
    S8(r7, r0);
    cr0 = CMPS(r3, r11);
    r7 = r7 + 1;
    if (!(cr0 & 2)) goto L_801b09e0;
L_801b09f8:
    r3 = r3 + r6;
    r7 = r7 + r8;
    r10 = r10; cr0 = CMPS(r10, 0);
    if (!(cr0 & 2)) goto L_801b09d0;
    return r3;
L_801b0a0c:
    w3d_open_break(0x801b0a0cu);
    return r3;
}

// 0x801b0a14 FUN_801b0a14 no verificada: desde bytes PPC
// Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A801b0a14(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, w3d_u32 sp0) {
    alignas(16) char frame[28];
    w3d_u32 r1 = h2g(frame) + 8;
    S32(r1 + 8, sp0);
    w3d_u32 r0 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r0 = L32(r1 + 16);
    cr0 = CMPS(r0, 4);
    if (!(cr0 & 4)) goto L_801b0a44;
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_801b0a80;
    if ((cr0 & 8)) goto L_801b0a70;
    cr0 = CMPS(r0, 7);
    if ((cr0 & 2)) goto L_801b0a78;
    goto L_801b0a88;
L_801b0a44:
    cr0 = CMPS(r0, 3);
    if (!(cr0 & 8)) goto L_801b0a68;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801b0a60;
    if ((cr0 & 8)) goto L_801b0a88;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801b02c8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    goto L_801b0a8c;
L_801b0a60:
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801b0448)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    goto L_801b0a8c;
L_801b0a68:
    r3 = A801b05b0(r3, r4, r5, r6, r7, r8, r9, r10);
    goto L_801b0a8c;
L_801b0a70:
    r3 = A801b07d4(r3, r4, r5, r6, r7, r8, r9, r10);
    goto L_801b0a8c;
L_801b0a78:
    r3 = A801b09a8(r3, r4, r5, r6, r7, r8, r9, r10);
    goto L_801b0a8c;
L_801b0a80:
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801b01bc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    goto L_801b0a8c;
L_801b0a88:
    w3d_open_break(0x801b0a88u);
L_801b0a8c:
    r1 = r1 + 8;
    return r3;
}

// 0x801b5328 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b5328(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b6b40 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b6b40(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b6ef4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b6ef4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b705c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b705c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b71c4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b71c4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b7bbc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b7bbc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b7d24 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b7d24(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b7e8c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b7e8c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b7ff4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b7ff4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b884c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b884c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b89b4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b89b4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b8b1c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b8b1c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b8c84 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b8c84(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801b8dec heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801b8dec(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801bd2a4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801bd2a4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801be070 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801be070(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801bf0c4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801bf0c4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801bf3d8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801bf3d8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801c155c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801c155c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801cb4b4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801cb4b4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801ce318 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ce318(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801ce8ec heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ce8ec(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801d65a0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801d65a0(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801a381c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x801d65c0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801d65c0(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801a3944)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x801d88a8 fn_801D88A8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801d88a8(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801d88a8u);
    r3 = 0x0u;
    return r3;
}

// 0x801d8978 fn_801D8978 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801d8978(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801d8978u);
    r3 = 0x0u;
    return r3;
}

// 0x801d8984 fn_801D8984 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801d8984(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801d8984u);
    r3 = 0x0u;
    return r3;
}

// 0x801d8a54 FUN_801d8a54 no verificada: desde bytes PPC
// Llama a tsonnet_c26_temp_alloc, two_byte_tile_copy, temp_release.
__attribute__((weak)) w3d_u32 A801d8a54(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, w3d_u32 sp0) {
    alignas(16) char frame[92];
    w3d_u32 r1 = h2g(frame) + 72;
    S32(r1 + 8, sp0);
    w3d_u32 r0 = 0, r11 = 0, r12 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 72; S32(t_, r1); r1 = t_; }
    r20 = r7;
    r21 = r6;
    r0 = (w3d_s32)r21 * (w3d_s32)r20;
    r28 = r3;
    r31 = r5;
    r19 = L32(r1 + 80);
    r24 = r8;
    r26 = r31 + r31;
    r3 = r0 << 1;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe0b8)(W(r3));
    r0 = r20 - 1;
    r6 = 0x0u;
    r25 = r3;
    cr0 = CMPU(r6, r0);
    if (!(cr0 & 8)) goto L_801d8b14;
    r29 = r0;
    r3 = r21 - 1;
L_801d8aa8:
    r0 = (w3d_s32)r6 * (w3d_s32)r26;
    r5 = 0x0u;
    r30 = r6 + 1;
    r9 = (w3d_s32)r6 * (w3d_s32)r31;
    cr0 = CMPU(r5, r3);
    r4 = r25 + r0;
    r6 = r28 + r9;
    if (!(cr0 & 8)) goto L_801d8b08;
L_801d8ac8:
    r10 = L8(r6);
    r5 = r5 + 1;
    r0 = L8(r6 + 1);
    cr0 = CMPU(r5, r3);
    r11 = L8(r6 + r31);
    r7 = r10 - r0;
    r6 = r6 + 1;
    r8 = r10 - r11;
    { w3d_u32 t_ = r7; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r7 = r9 + 128;
    { w3d_u32 t_ = r8; r11 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S8(r4, r7);
    r8 = r11 + 128;
    { w3d_u32 t_ = r4 + 1; S8(t_, r8); r4 = t_; }
    r4 = r4 + 1;
    if ((cr0 & 8)) goto L_801d8ac8;
L_801d8b08:
    r6 = r30;
    cr0 = CMPU(r6, r29);
    if ((cr0 & 8)) goto L_801d8aa8;
L_801d8b14:
    r27 = r20 - 1;
    r6 = 0x0u;
    r23 = r27;
    cr0 = CMPU(r6, r27);
    r22 = r21 - 1;
    r18 = r20 + 3;
    r17 = r21 + 3;
    if (!(cr0 & 8)) goto L_801d8ba4;
    r0 = r28 - 1;
    r9 = r25 - 2;
    r0 = r31 + r0;
    r12 = r26 + r9;
    r30 = r0;
    r3 = r0 + r31;
    r5 = r26 - 2;
    r29 = 0x0u;
L_801d8b54:
    r10 = L8(r30);
    r4 = r25 + r5;
    r0 = L8(r29 + r28);
    r6 = r6 + 1;
    r11 = L8(r3);
    r30 = r30 + r31;
    r7 = r10 - r0;
    r3 = r3 + r31;
    r8 = r10 - r11;
    { w3d_u32 t_ = r7; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r7 = r9 + 128;
    { w3d_u32 t_ = r8; r11 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S8(r12, r7);
    r8 = r11 + 128;
    S8(r4 + 1, r8);
    r12 = r12 + r26;
    r5 = r5 + r26;
    r29 = r29 + r31;
    cr0 = CMPU(r6, r27);
    if ((cr0 & 8)) goto L_801d8b54;
L_801d8ba4:
    r6 = r23;
    r5 = 0x0u;
    r9 = (w3d_s32)r6 * (w3d_s32)r26;
    cr0 = CMPU(r5, r22);
    r0 = (w3d_s32)r6 * (w3d_s32)r31;
    r4 = r25 + r9;
    r6 = r28 + r0;
    if (!(cr0 & 8)) goto L_801d8bf8;
L_801d8bc4:
    r8 = L8(r6);
    r7 = 0x7fu;
    r0 = L8(r28 + r5);
    r6 = r6 + 1;
    S8(r4, r7);
    r5 = r5 + 1;
    r8 = r8 - r0;
    cr0 = CMPU(r5, r22);
    { w3d_u32 t_ = r8; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r8 = r9 + 128;
    { w3d_u32 t_ = r4 + 1; S8(t_, r8); r4 = t_; }
    r4 = r4 + 1;
    if ((cr0 & 8)) goto L_801d8bc4;
L_801d8bf8:
    r6 = r23;
    r7 = 0x80u;
    r0 = (w3d_s32)r6 * (w3d_s32)r31;
    r23 = r18 >> 2;
    r10 = 0x0u;
    r11 = (w3d_s32)r6 * (w3d_s32)r26;
    r29 = 0x0u;
    r27 = r17 >> 2;
    r0 = r0 + r22;
    cr0 = CMPU(r29, r23);
    r6 = r28 + r0;
    r8 = L8(r28 + r0);
    r9 = r6 - r31;
    r11 = r11 + r22;
    r0 = L8(r9);
    r4 = r25 + r11;
    S8(r25 + r11, r7);
    r8 = r8 - r0;
    { w3d_u32 t_ = r8; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r8 = r9 + 128;
    S8(r4 + 1, r8);
    S32(r19, r10);
    if (!(cr0 & 8)) goto L_801d8cb4;
L_801d8c54:
    r30 = 0x0u;
    r28 = r29 + 1;
    cr0 = CMPU(r30, r27);
    if (!(cr0 & 8)) goto L_801d8ca8;
    r31 = 0x0u;
L_801d8c68:
    r9 = r24;
    r7 = r31;
    r3 = r25;
    r4 = r26;
    r5 = r21;
    r6 = r20;
    r8 = r29 << 2;
    r30 = r30 + 1;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801d7d78)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9));
    r24 = r24 + 32;
    r9 = L32(r19);
    r31 = r31 + 4;
    cr0 = CMPU(r30, r27);
    r9 = r9 + 32;
    S32(r19, r9);
    if ((cr0 & 8)) goto L_801d8c68;
L_801d8ca8:
    r29 = r28;
    cr0 = CMPU(r29, r23);
    if ((cr0 & 8)) goto L_801d8c54;
L_801d8cb4:
    r3 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe160)(W(r3));
    r3 = 0x0u;
    r1 = r1 + 72;
    return r3;
}

// 0x801df0c4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801df0c4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = r4;
    r5 = 0x0u;
    r11 = L32(r9);
    r4 = r3 + 24;
    r3 = r9;
    r0 = L32(r11 + 148);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801e3010 FUN_801e3010 no verificada: desde bytes PPC
// Llama a sound_emitter_list_init, voice_update, stream_cue_advance, stream_cue_update_attenuation, sound_emitter_list_insert. Hace 2 llamadas virtuales.
__attribute__((weak)) w3d_u32 A801e3010(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[192];
    w3d_u32 r1 = h2g(frame) + 176;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 176; S32(t_, r1); r1 = t_; }
    r28 = r3;
    r29 = r4;
    r3 = r1 + 8;
    r26 = r28 + 44;
    ((void (*)(w3d_oarg))A801e15c8)(W(r3));
    r30 = 0x0u;
    r0 = 0x6u;
    r31 = r26;
    S32(r1 + 140, r0);
L_801e3044:
    r3 = L32(r31);
    r31 = r31 + 4;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801e3060;
    r5 = L32(r28 + 68);
    r4 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801e6054)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
L_801e3060:
    r30 = r30 + 1;
    cr0 = CMPU(r30, 0x5u);
    if (!(cr0 & 4)) goto L_801e3044;
    r9 = r28 + 24;
    r11 = L32(r28 + 24);
    r0 = L32(r9 + 4);
    r27 = r9;
    r31 = 0x0u;
    r0 = r0 - r11;
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_801e3108;
    r30 = 0x0u;
L_801e3090:
    r9 = L32(r28 + 24);
    r4 = r29;
    r3 = L32(r9 + r30);
    ((void (*)(w3d_oarg, w3d_oarg))A801e3888)(W(r3), W(r4));
    r9 = L32(r28 + 24);
    r3 = L32(r9 + r30);
    r11 = L32(r3);
    r0 = L32(r11 + 36);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801e30e8;
    r9 = L32(r28 + 24);
    r4 = L32(r28 + 68);
    r3 = L32(r9 + r30);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801e38a4)(W(r3), W(r4));
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801e30e8;
    r9 = L32(r28 + 24);
    r3 = r1 + 8;
    r4 = L32(r9 + r30);
    ((void (*)(w3d_oarg, w3d_oarg))A801e16b0)(W(r3), W(r4));
L_801e30e8:
    r0 = L32(r27 + 4);
    r31 = r31 + 1;
    r9 = L32(r28 + 24);
    r30 = r30 + 4;
    r0 = r0 - r9;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r31, r0);
    if ((cr0 & 8)) goto L_801e3090;
L_801e3108:
    r29 = r26;
    r25 = r26 + 20;
L_801e3110:
    r3 = L32(r29);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801e5fd4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801e31a4;
    r27 = 0x0u;
    r31 = 0x0u;
    goto L_801e3184;
L_801e312c:
    r3 = r1 + 8;
    r4 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801e194c)(W(r3), W(r4));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801e3180;
    r9 = L32(r29);
    r4 = r31;
    r3 = r1 + 8;
    r30 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801e194c)(W(r3), W(r4));
    r9 = L32(r3);
    r0 = L32(r9 + 72);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r30, r3);
    if (!(cr0 & 2)) goto L_801e3180;
    r4 = r31;
    r3 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A801e183c)(W(r3), W(r4));
    r27 = 0x1u;
    goto L_801e3194;
L_801e3180:
    r31 = r31 + 1;
L_801e3184:
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801e1944)(W(r3));
    cr0 = CMPU(r31, r3);
    if ((cr0 & 8)) goto L_801e312c;
L_801e3194:
    cr0 = CMPS(r27, 0);
    if (!(cr0 & 2)) goto L_801e31a4;
    r3 = L32(r29);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801e5dfc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
L_801e31a4:
    r29 = r29 + 4;
    cr0 = CMPU(r29, r25);
    if (!(cr0 & 4)) goto L_801e3110;
    r30 = 0x0u;
    r31 = 0x0u;
L_801e31b8:
    r3 = L32(r31 + r26);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801e3214;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801e5fd4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801e3214;
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801e1944)(W(r3));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801e3214;
    r3 = r1 + 8;
    r4 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801e194c)(W(r3), W(r4));
    r4 = r3;
    r3 = L32(r31 + r26);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801e5b80)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r31 + r26);
    r4 = 0x0u;
    r5 = L32(r28 + 68);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801e6054)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = r1 + 8;
    r4 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg))A801e183c)(W(r3), W(r4));
L_801e3214:
    r30 = r30 + 1;
    r31 = r31 + 4;
    cr0 = CMPU(r30, 0x5u);
    if (!(cr0 & 4)) goto L_801e31b8;
    r3 = r1 + 8;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A801e15f4)(W(r3), W(r4));
    r3 = 0x0u;
    r1 = r1 + 176;
    return r3;
}

// 0x801e4074 FUN_801e4074 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: stream_slot_start. Llama a sol35f2_fill.
__attribute__((weak)) w3d_u32 A801e4074(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r0 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r8 = 0x0u;
    r0 = 0x0u;
    r9 = 0x10000u;
    r11 = 0x1u;
    S32(r31 + 124, r8);
    r0 = 0xd680u;
    r9 = 0x17760u;
    r10 = 0x6b40u;
    S8(r31 + 20, r5);
    S8(r31 + 21, r6);
    S8(r31 + 108, r11);
    S32(r31 + 100, r0);
    S32(r31 + 104, r9);
    S32(r31 + 88, r10);
    S32(r31 + 16, r4);
    S32(r31 + 112, r11);
    S32(r31 + 116, r8);
    S32(r31 + 120, r11);
    r0 = L32(r4 + 12);
    S32(r31 + 92, r0);
    cr0 = CMPU(r0, 0x6b40u);
    if (!(cr0 & 8)) goto L_801e40fc;
    r3 = L32(r31 + 96);
    r30 = r0;
    r4 = 0x0u;
    { w3d_u32 t_ = r30; r5 = (w3d_u32)27456 - t_; ca = ((w3d_u32)27456 >= t_); }
    r3 = r3 + r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eefe0)(W(r3), W(r4), W(r5));
    goto L_801e4100;
L_801e40fc:
    r30 = 0x6b40u;
L_801e4100:
    r0 = 0x2u;
    r3 = r30;
    S8(r31, r0);
    r1 = r1 + 16;
    return r3;
}

// 0x801e41d0 FUN_801e41d0 no verificada: desde bytes PPC
// Llama a stream_lock, stream_slot_open, stream_slot_start, stream_unlock, disc_open.
__attribute__((weak)) w3d_u32 A801e41d0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[64];
    w3d_u32 r1 = h2g(frame) + 48;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 48; S32(t_, r1); r1 = t_; }
    r29 = r1 + 8;
    r28 = r4;
    r26 = r5;
    r27 = r6;
    ((void (*)())A801e3eb8)();
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801e3d44)(W(r3));
    r25 = r3;
    r30 = r25;
    cr0 = CMPS(r30, -1);
    if ((cr0 & 2)) goto L_801e4348;
    r3 = r1 + 12;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801e3d44)(W(r3));
    r31 = r3;
    cr0 = CMPS(r31, -1);
    if ((cr0 & 2)) goto L_801e4338;
    r11 = L32(r1 + 8);
    r4 = r28;
    r0 = L32(r29 + 4);
    r5 = r27;
    r6 = 0x0u;
    S32(r11 + 8, r0);
    r0 = L32(r1 + 8);
    r9 = L32(r29 + 4);
    S32(r9 + 12, r0);
    r3 = L32(r1 + 8);
    r3 = A801e4074(r3, r4, r5, r6);
    r31 = r3;
    r4 = r26;
    r3 = L32(r29 + 4);
    r5 = r27;
    r6 = 0x7fu;
    r3 = A801e4074(r3, r4, r5, r6);
    r28 = r3;
    ((void (*)())A801e3e70)();
    r4 = L32(r1 + 8);
    r9 = L32(r4 + 16);
    r4 = r4 + 24;
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802f51e4)(W(r3), W(r4));
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_801e4290;
    r0 = 0x0u;
L_801e4290:
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_801e42a8;
    r3 = D(0x803b0000u);
    r3 = D(0x803b0698u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, ...))A802fb7ac)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
L_801e42a8:
    r3 = L32(r1 + 8);
    r30 = 0x801e0000u;
    r5 = r31;
    r7 = FN(0x801e4a4cu);
    r9 = L32(r3 + 16);
    r8 = 0x2u;
    r4 = L32(r3 + 96);
    r6 = L32(r9 + 8);
    r3 = r3 + 24;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802f5568)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r4 = L32(r29 + 4);
    r9 = L32(r4 + 16);
    r4 = r4 + 24;
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802f51e4)(W(r3), W(r4));
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_801e42f4;
    r0 = 0x0u;
L_801e42f4:
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_801e430c;
    r3 = D(0x803b0000u);
    r3 = D(0x803b06c0u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, ...))A802fb7ac)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
L_801e430c:
    r9 = L32(r29 + 4);
    r5 = r28;
    r7 = FN(0x801e4a4cu);
    r8 = 0x2u;
    r11 = L32(r9 + 16);
    r3 = r9 + 24;
    r4 = L32(r9 + 96);
    r6 = L32(r11 + 8);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802f5568)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = r25;
    goto L_801e4350;
L_801e4338:
    r9 = L32(r1 + 8);
    r0 = 0x0u;
    r30 = 0xffffffffu;
    S8(r9, r0);
L_801e4348:
    ((void (*)())A801e3e70)();
    r3 = r30;
L_801e4350:
    r1 = r1 + 48;
    return r3;
}

// 0x801e5a60 FUN_801e5a60 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: stream_channel_construct.
__attribute__((weak)) w3d_u32 A801e5a60(w3d_u32 r3) {
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0;
    w3d_u32 cr0 = 0, ctr = 0;
    r0 = L32(r3 + 8);
    r9 = D(0x80410000u);
    r11 = 0x0u;
    r9 = D(0x80416f78u);
    r10 = 0xffffffffu;
    r0 = r0 & 0xff1fffffu;
    S32(r3 + 168, r9);
    r8 = 0x0u;
    S32(r3 + 56, r10);
    r7 = 0x0u;
    S32(r3 + 8, r0);
    r10 = r3 + 4;
    S32(r3 + 164, r11);
    r0 = 0xffffffffu;
    S32(r3 + 44, r11);
    r9 = r3 + 60;
    S32(r3 + 52, r11);
L_801e5aa4:
    S32(r9, r7);
    r8 = r8 + 1;
    S16(r10, r0);
    r9 = r9 + 4;
    r10 = r10 + 2;
    cr0 = CMPU(r8, 0x1u);
    if (!(cr0 & 4)) goto L_801e5aa4;
    r0 = 0x10u;
    r9 = D(0x80460000u);
    ctr = r0;
    r9 = D(0x8045dbc8u);
L_801e5ad0:
    r0 = L32(r9 + 60);
    r0 = r0 & 0x3fffffffu;
    S32(r9 + 60, r0);
    r9 = r9 + 64;
    --ctr; if (ctr != 0) goto L_801e5ad0;
    return r3;
}

// 0x801e6f88 fn_801E6F88 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801e6f88(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801e6f88u);
    r3 = 0x0u;
    return r3;
}

// 0x801ea44c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ea44c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x801eb0b0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801eb0b0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r0 = L8(r9 + 7);  /* lbz +7: byte de flags del descriptor, en crudo */
    r9 = r0 & 0x4u; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801eb0e8;
    r9 = r0 & 0x20u; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801eb0e8;
    r9 = L32(r3 + 4);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_801eb0ec;
L_801eb0e8:
    r3 = 0x1u;
L_801eb0ec:
    r1 = r1 + 8;
    return r3;
}

// 0x801eb538 fn_801EB538 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801eb538(w3d_u32 r3) {
    w3d_open_break(0x801eb538u);
    return r3;
}

// 0x801ed550 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ed550(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r11 = L32(r4);
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r11 + 84);
    r3 = r4;
    r5 = L32(r9);
    r4 = 0x0u;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ed590 fn_801ED590 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801ed590(w3d_u32 r3) {
    w3d_open_break(0x801ed590u);
    return r3;
}

// 0x801ed598 fn_801ED598 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801ed598(w3d_u32 r3) {
    w3d_open_break(0x801ed598u);
    return r3;
}

// 0x801ed5a0 fn_801ED5A0 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801ed5a0(w3d_u32 r3) {
    w3d_open_break(0x801ed5a0u);
    return r3;
}

// 0x801ed5a8 fn_801ED5A8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801ed5a8(w3d_u32 r3) {
    w3d_open_break(0x801ed5a8u);
    return r3;
}

// 0x801ed5b0 fn_801ED5B0 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801ed5b0(w3d_u32 r3) {
    w3d_open_break(0x801ed5b0u);
    return r3;
}

// 0x801edc5c FUN_801edc5c no verificada: desde bytes PPC
// Llama a elapsed, buffer_heap_dispatch, actor_registry_pool_remove, native_forward_copy, remap_properties.
// aviso: lee r3 tras void 802098fc en 801edcfc
// aviso: lee r3 tras void 802099d4 en 801edc9c
__attribute__((weak)) w3d_u32 A801edc5c(void) {
    alignas(16) char frame[2664];
    w3d_u32 r1 = h2g(frame) + 2648;
    w3d_u32 r0 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 2648; S32(t_, r1); r1 = t_; }
    { w3d_u64 v_ = ((w3d_oarg (*)())A801fe4d8)(); r3 = (w3d_u32)(v_ >> 32); r4 = (w3d_u32)v_; }
    r24 = 0x0u;
    r9 = D(0x80410000u);
    S32(r1 + 8, r3);
    S32(r1 + 12, r4);
    r9 = D(0x80417658u);
    r3 = r1 + 16;
    S32(r1 + 16, r9);
    r23 = 0x0u;
    ((void (*)(w3d_oarg))A80358118)(W(r3));
    r21 = 0x0u;
    r3 = D(0x804b05a0u);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A802099d4)(W(r3));
    r19 = r3;
    r3 = D(0x804b05a0u);
    r4 = r19 | 0x4u;
    ((void (*)(w3d_oarg, w3d_oarg))A802099b0)(W(r3), W(r4));
    r22 = r1 + 16;
    r20 = r1 + 8;
    goto L_801eddc4;
L_801edcbc:
    { w3d_u32 t_ = r9; r28 = t_ + (w3d_u32)-1; ca = r28 < t_; cr0 = CMPS(r28, 0); }
    if ((cr0 & 8)) goto L_801edd50;
    r0 = r9 - 128;
    cr0 = CMPU(r28, r0);
    if (!(cr0 & 4)) goto L_801edd50;
    r25 = r1 + 544;
    r26 = r1 + 32;
    r29 = r1 + 2080;
L_801edcdc:
    r31 = ROTL(r28, 2) & 0x1fcu;
    r0 = L32(r1 + 28);
    r30 = L32(r25 + r31);
    cr0 = CMPU(r30, r0);
    if (!(cr0 & 8)) goto L_801edd38;
    r3 = D(0x804b05a0u);
    r4 = r30;
    r5 = 0x20u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802098fc)(W(r3), W(r4), W(r5));
    r0 = L32(r26 + r31);
    cr0 = CMPU(r3, r0);
    if (!(cr0 & 8)) goto L_801edd24;
    S32(r29 - 1024, r0);
    r27 = r27 + 1;
    S32(r29 - 512, r3);
    S32(r29, r30);
    r29 = r29 + 4;
    goto L_801edd38;
L_801edd24:
    r4 = r3;
    r3 = D(0x804b05a0u);
    ((void (*)(w3d_oarg, w3d_oarg))A80209920)(W(r3), W(r4));
    r3 = D(0x804b05a0u);
    r3 = A80209968(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801edd38:
    { w3d_u32 t_ = r28; r28 = t_ + (w3d_u32)-1; ca = r28 < t_; cr0 = CMPS(r28, 0); }
    if ((cr0 & 8)) goto L_801edd50;
    r9 = L32(r1 + 20);
    r9 = r9 - 128;
    cr0 = CMPU(r28, r9);
    if ((cr0 & 4)) goto L_801edcdc;
L_801edd50:
    cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_801eddf8;
    r29 = 0x0u;
    r24 = r24 + 1;
    r23 = r23 + r27;
    cr0 = CMPU(r29, r27);
    r25 = r1 + 1056;
    r26 = r1 + 1568;
    if (!(cr0 & 8)) goto L_801eddb0;
    r28 = r25;
    r30 = r1 + 2080;
    r31 = 0x0u;
L_801edd80:
    r5 = L32(r30);
    r29 = r29 + 1;
    r4 = L32(r31 + r28);
    r30 = r30 + 4;
    r3 = L32(r31 + r26);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r4 = L32(r31 + r28);
    r3 = D(0x804b05a0u);
    r31 = r31 + 4;
    ((void (*)(w3d_oarg, w3d_oarg))A80209920)(W(r3), W(r4));
    cr0 = CMPU(r29, r27);
    if ((cr0 & 8)) goto L_801edd80;
L_801eddb0:
    r3 = r25;
    r4 = r26;
    r5 = r27;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A801ea59c)(W(r3), W(r4), W(r5));
    r21 = r21 + r3;
L_801eddc4:
    r0 = 0x0u;
    r3 = D(0x804b05a0u);
    S32(r22 + 12, r0);
    r27 = 0x0u;
    S32(r22 + 4, r0);
    S32(r22 + 8, r0);
    r3 = A80209968(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = D(0x804b05a0u);
    r4 = r22;
    ((void (*)(w3d_oarg, w3d_oarg))A8020998c)(W(r3), W(r4));
    r9 = L32(r1 + 20);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801edcbc;
L_801eddf8:
    r4 = r19;
    r3 = D(0x804b05a0u);
    ((void (*)(w3d_oarg, w3d_oarg))A802099b0)(W(r3), W(r4));
    { w3d_u64 v_ = ((w3d_oarg (*)())A801fe4d8)(); r3 = (w3d_u32)(v_ >> 32); r4 = (w3d_u32)v_; }
    r0 = L32(r20 + 4);
    r3 = r4 - r0;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe508)(W(r3));
    r5 = r3;
    r4 = D(0x803b0000u);
    r4 = D(0x803b0cb4u);
    r3 = D(0x804b0640u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, w3d_oarg, ...))A80347324)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r4 = D(0x803b0000u);
    r3 = D(0x804b0640u);
    r4 = D(0x803b0cd0u);
    r5 = r24;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, w3d_oarg, ...))A80347324)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r4 = D(0x803b0000u);
    r3 = D(0x804b0640u);
    r5 = r23;
    r4 = D(0x803b0cf8u);
    r6 = r21;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, w3d_oarg, ...))A80347324)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = r24;
    r1 = r1 + 2648;
    return r3;
}

// 0x801ef380 FUN_801ef380 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: resource_set. Llama a array_ref_lock. Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A801ef380(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r31 = r4;
    r27 = r6;
    r29 = r7; cr0 = CMPS(r29, 0);
    if ((cr0 & 2)) goto L_801ef448;
    r8 = L32(r30 + r31);
    r0 = L16(r8 + 4);
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_801ef3cc;
    r4 = L32(r8 + 24);
    r3 = r30 + r31;
    r5 = 0x4u;
    r6 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef048)(W(r3), W(r4), W(r5), W(r6));
    r8 = L32(r30 + r31);
L_801ef3cc:
    r0 = L32(r8 + 24);
    r9 = r27 + r29;
    r28 = r8 + 32;
    r11 = r27 << 2;
    r10 = r0 - r29;
    r9 = r9 << 2;
    r0 = r0 << 2;
    r26 = r11;
    r27 = r28 + r0;
    S32(r8 + 24, r10);
    r30 = r28 + r9;
    r31 = r28 + r11;
    cr0 = CMPS(r29, 0);
    if ((cr0 & 2)) goto L_801ef424;
L_801ef404:
    r3 = L32(r31);
    r31 = r31 + 4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    { w3d_u32 t_ = r29; r29 = t_ + (w3d_u32)-1; ca = r29 < t_; cr0 = CMPS(r29, 0); }
    if (!(cr0 & 2)) goto L_801ef404;
L_801ef424:
    r31 = r28 + r26;
    cr0 = CMPS(r30, r27);
    if ((cr0 & 2)) goto L_801ef448;
L_801ef430:
    r0 = L32(r30);
    r30 = r30 + 4;
    S32(r31, r0);
    cr0 = CMPS(r30, r27);
    r31 = r31 + 4;
    if (!(cr0 & 2)) goto L_801ef430;
L_801ef448:
    r1 = r1 + 32;
    return r3;
}

// 0x801f2034 fn_801F2034 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801f2034(w3d_u32 r3) {
    w3d_open_break(0x801f2034u);
    return r3;
}

// 0x801f203c fn_801F203C no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801f203c(w3d_u32 r3) {
    w3d_open_break(0x801f203cu);
    return r3;
}

// 0x801fac8c FUN_801fac8c no verificada: desde bytes PPC
// Llama a tagged_construct, registry_retain, text_default, assign__20d24d_String_803426b8PCc, write_text. Hace 3 llamadas virtuales. Usa las cadenas "Left", "Right", "Down".
__attribute__((weak)) w3d_u32 A801fac8c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[104];
    w3d_u32 r1 = h2g(frame) + 88;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 88; S32(t_, r1); r1 = t_; }
    r29 = r1 + 8;
    r26 = r4;
    r31 = r5;
    r4 = r6;
    r3 = r29;
    r24 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020d318)(W(r3), W(r4));
    r9 = L32(r1 + 8);
    r3 = r29;
    S32(r1 + 36, r29);
    r30 = r1 + 36;
    r28 = r1 + 48;
    r25 = r30;
    r0 = L32(r9 + 12);
    r27 = r28;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 4);
    r9 = 0xau;
    r11 = 0x0u;
    r10 = 0x6u;
    r0 = (ROTL(r9, 25) & 0xfe000000u) | (r0 & 0x1ffffffu);
    r3 = r29;
    r0 = r0 & 0xfeffffffu;
    S32(r30 + 4, r0);
    S8(r30 + 6, r11); /* PPC +5: bits 16-23 de la palabra +4; en el anfitrión es +6 */
    r0 = L32(r30 + 4);
    r0 = (ROTL(r10, 11) & 0xf800u) | (r0 & 0xffff07ffu);
    S32(r30 + 4, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020d2b8)(W(r3));
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    cr0 = CMPS(r26, 1);
    if ((cr0 & 2)) goto L_801faea4;
    if ((cr0 & 4)) goto L_801faff4;
    cr0 = CMPS(r26, 0);
    if (!(cr0 & 2)) goto L_801faff4;
    cr0 = CMPS(r31, 5);
    if ((cr0 & 2)) goto L_801fae1c;
    cr0 = CMPU(r31, 0x5u);
    if ((cr0 & 4)) goto L_801fad78;
    cr0 = CMPS(r31, 2);
    if ((cr0 & 2)) goto L_801fade0;
    cr0 = CMPU(r31, 0x2u);
    if ((cr0 & 4)) goto L_801fad64;
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_801fadb8;
    cr0 = CMPS(r31, 1);
    if ((cr0 & 2)) goto L_801fadcc;
    goto L_801faf58;
L_801fad64:
    cr0 = CMPS(r31, 3);
    if ((cr0 & 2)) goto L_801fadf4;
    cr0 = CMPS(r31, 4);
    if ((cr0 & 2)) goto L_801fae08;
    goto L_801faf58;
L_801fad78:
    cr0 = CMPS(r31, 8);
    if ((cr0 & 2)) goto L_801fae58;
    cr0 = CMPU(r31, 0x8u);
    if ((cr0 & 4)) goto L_801fad9c;
    cr0 = CMPS(r31, 6);
    if ((cr0 & 2)) goto L_801fae30;
    cr0 = CMPS(r31, 7);
    if ((cr0 & 2)) goto L_801fae44;
    goto L_801faf58;
L_801fad9c:
    cr0 = CMPS(r31, 10);
    if ((cr0 & 2)) goto L_801fae80;
    cr0 = CMPU(r31, 0xau);
    if ((cr0 & 8)) goto L_801fae6c;
    cr0 = CMPS(r31, 11);
    if ((cr0 & 2)) goto L_801fae94;
    goto L_801faf58;
L_801fadb8:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b40u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fadcc:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b48u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fade0:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b50u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fadf4:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b58u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae08:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b5cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae1c:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b68u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae30:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b74u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae44:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b80u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae58:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b84u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae6c:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b88u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae80:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b8cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801fae94:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b90u);
    goto L_801faf54;
L_801faea4:
    cr0 = CMPS(r31, 2);
    if ((cr0 & 2)) goto L_801faf0c;
    cr0 = CMPU(r31, 0x2u);
    if ((cr0 & 4)) goto L_801faec8;
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_801faee4;
    cr0 = CMPS(r31, 1);
    if ((cr0 & 2)) goto L_801faef8;
    goto L_801faf58;
L_801faec8:
    cr0 = CMPS(r31, 4);
    if ((cr0 & 2)) goto L_801faf34;
    cr0 = CMPU(r31, 0x4u);
    if ((cr0 & 8)) goto L_801faf20;
    cr0 = CMPS(r31, 5);
    if ((cr0 & 2)) goto L_801faf48;
    goto L_801faf58;
L_801faee4:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1b98u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801faef8:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1ba4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801faf0c:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1bb0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801faf20:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1bbcu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801faf34:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1bc8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_801faf58;
L_801faf48:
    r4 = D(0x803b0000u);
    r3 = r27;
    r4 = D(0x803b1bd4u);
L_801faf54:
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
L_801faf58:
    r4 = r27;
    r3 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8020d82c)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r4 = D(0x803b0000u);
    r3 = L32(r1 + 48);
    r4 = D(0x803b1be0u);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801fb038;
    cr0 = CMPS(r26, 2);
    if ((cr0 & 2)) goto L_801fafc8;
    if ((cr0 & 4)) goto L_801faf9c;
    cr0 = CMPS(r26, 0);
    if ((cr0 & 2)) goto L_801fafb8;
    cr0 = CMPS(r26, 1);
    if ((cr0 & 2)) goto L_801fafa8;
    goto L_801faff4;
L_801faf9c:
    cr0 = CMPS(r26, 3);
    if ((cr0 & 2)) goto L_801fafd8;
    goto L_801faff4;
L_801fafa8:
    r4 = D(0x803b0000u);
    r3 = r25;
    r4 = D(0x803b1be4u);
    goto L_801fafe4;
L_801fafb8:
    r4 = D(0x803b0000u);
    r3 = r25;
    r4 = D(0x803b1becu);
    goto L_801fafe4;
L_801fafc8:
    r4 = D(0x803b0000u);
    r3 = r25;
    r4 = D(0x803b1bf4u);
    goto L_801fafe4;
L_801fafd8:
    r4 = D(0x803b0000u);
    r3 = r25;
    r4 = D(0x803b1bfcu);
L_801fafe4:
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020dbf8)(W(r3), W(r4));
    r4 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020da90)(W(r3), W(r4));
    goto L_801fb038;
L_801faff4:
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 36);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fb020;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fb020:
    r3 = r24;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A8020d36c)(W(r3), W(r4));
    r3 = 0x80000000u;
    r3 = 0x80004005u;
    goto L_801fb074;
L_801fb038:
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 36);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fb064;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fb064:
    r3 = r24;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A8020d36c)(W(r3), W(r4));
    r3 = 0x0u;
L_801fb074:
    r1 = r1 + 88;
    return r3;
}

}
