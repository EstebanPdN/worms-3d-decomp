// Funciones del juego sin fuente admitida: 0x800f46b8 a 0x8011a1c8. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A8009ed90();
__attribute__((weak)) void A800a8d00();
__attribute__((weak)) void A800d7788();
__attribute__((weak)) void A800e58fc();
__attribute__((weak)) void A800f6ca0();
__attribute__((weak)) void A800fc6dc();
__attribute__((weak)) void A800fc7f8();
__attribute__((weak)) void A800fcec8();
__attribute__((weak)) void A800ffcdc();
__attribute__((weak)) void A80101018();
__attribute__((weak)) void A80102028();
__attribute__((weak)) void A801022b0();
__attribute__((weak)) void A8010272c();
__attribute__((weak)) void A80102968();
__attribute__((weak)) void A80102a34();
__attribute__((weak)) void A8015adf4();
__attribute__((weak)) void A8015fef0();
__attribute__((weak)) void A80161f54();
__attribute__((weak)) void A80165254();
__attribute__((weak)) void A80178474();
__attribute__((weak)) void A80179598();
__attribute__((weak)) void A80182498();
__attribute__((weak)) void A801ea4c8();
__attribute__((weak)) void A801ef174();
__attribute__((weak)) void A801f6120();
__attribute__((weak)) void A801f61a0();
__attribute__((weak)) void A801f621c();
__attribute__((weak)) void A801f62d0();
__attribute__((weak)) void A801f6350();
__attribute__((weak)) void A801f63cc();
__attribute__((weak)) void A801fe220();
__attribute__((weak)) void A802098d8();
__attribute__((weak)) void A8020b680();
__attribute__((weak)) void A8020bb54();
__attribute__((weak)) void A8020bd38();
__attribute__((weak)) void A8020bf2c();
__attribute__((weak)) void A8020c048();
__attribute__((weak)) void A8020c510();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A802cbe9c();
__attribute__((weak)) void A802ceb4c();
__attribute__((weak)) void A802ddbd8();
__attribute__((weak)) void A802e82c0();
__attribute__((weak)) void A802ec334();
__attribute__((weak)) void A802ede44();
__attribute__((weak)) void A802eee50();
__attribute__((weak)) void A802ef234();
__attribute__((weak)) void A802ef9c0();
__attribute__((weak)) void A80341584();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A803426b8();
__attribute__((weak)) void A80343580();
__attribute__((weak)) void A80343740();
__attribute__((weak)) void A80346ef0();

// 0x800f46b8 FUN_800f46b8 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: finish_stage. Llama a service_forward, propagate_tag, iface_array_field_append, text_default, string_prefix_assign. Hace 14 llamadas virtuales. Usa las cadenas "PreviewLow", "PreviewHigh", "PreviewBeachLow". Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A800f46b8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[304];
    w3d_u32 r1 = h2g(frame) + 288;
    w3d_u32 r0 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 288; S32(t_, r1); r1 = t_; }
    r9 = D(0x80390000u);
    r11 = r1 + 8;
    f0 = LF(D(0x8038c554u));
    r31 = r3;
    r10 = r1 + 104;
    r20 = r11;
    SF(r1 + 8, f0);
    r8 = r1 + 24;
    SF(r11 + 4, f0);
    r27 = 0x0u;
    SF(r11 + 8, f0);
    f12 = LF(r1 + 8);
    r9 = L32(r31 + 44);
    r0 = L32(r31 + 48);
    f12 = -f12;
    SF(r1 + 120, f12);
    r0 = r0 - r9;
    f13 = LF(r11 + 4);
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    f13 = -f13;
    SF(r1 + 124, f13);
    f0 = LF(r11 + 8);
    SF(r1 + 104, f12);
    f0 = -f0;
    SF(r1 + 108, f13);
    SF(r1 + 112, f0);
    SF(r1 + 128, f0);
    r0 = L32(r1 + 104);
    r9 = L32(r10 + 8);
    r11 = L32(r10 + 4);
    S32(r1 + 24, r0);
    S32(r8 + 8, r9);
    S32(r8 + 4, r11);
    if ((cr0 & 2)) goto L_800f4ea8;
    r9 = D(0x80390000u);
    r28 = r31 + 88;
    f30 = LF(D(0x8038c55cu));
    r25 = 0x0u;
L_800f4768:
    r10 = L32(r31 + 44);
    r3 = 0x0u;
    r5 = 0x0u;
    r4 = 0x0u;
    r9 = L32(r10 + r25);
    r11 = L32(r9 + 4);
    r0 = L32(r9 + 8);
    r0 = r0 - r11;
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_800f4820;
    r7 = r25;
    r30 = 0x50u;
    r6 = 0x0u;
L_800f479c:
    r10 = L32(r31 + 44);
    r8 = L32(r31 + 80);
    r11 = L32(r10 + r7);
    r9 = L32(r11 + 28);
    r9 = r9 << 2;
    r11 = L32(r9 + r8);
    r10 = L32(r11 + r30);
    r0 = L32(r10 + 24);
    r10 = r10 + 32;
    S32(D(0x804af0c8u), r0);
    r9 = L32(r6 + r10);
    r0 = L32(r9 + 56);
    r9 = r0 & 0x5555u; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_800f47f4;
    r9 = L32(r31 + 44);
    r10 = L32(r9 + r25);
    r11 = L32(r10 + 4);
    r0 = L32(r11 + r6);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_800f47fc;
    r4 = 0x1u;
    goto L_800f47fc;
L_800f47f4:
    r9 = L32(r31 + 44);
    r3 = 0x1u;
L_800f47fc:
    r9 = L32(r9 + r7);
    r5 = r5 + 1;
    r6 = r6 + 4;
    r11 = L32(r9 + 4);
    r0 = L32(r9 + 8);
    r0 = r0 - r11;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r5, r0);
    if ((cr0 & 8)) goto L_800f479c;
L_800f4820:
    cr0 = CMPS(r3, 0);
    r0 = 0x0u;
    if (!(cr0 & 2)) goto L_800f4834;
    cr0 = CMPS(r4, 0);
    if (!(cr0 & 2)) goto L_800f4838;
L_800f4834:
    r0 = 0x1u;
L_800f4838:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_800f4e84;
    r3 = D(0x80420000u);
    r3 = D(0x8041b5c8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    S32(r1 + 104, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f4868;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f4868:
    r9 = L32(r31 + 44);
    r30 = r1 + 112;
    r10 = L32(r31 + 80);
    r29 = r30;
    r11 = L32(r9 + r25);
    r3 = L32(r1 + 104);
    r9 = L32(r11 + 28);
    r9 = r9 << 2;
    r11 = L32(r9 + r10);
    r4 = L32(r11 + 72);
    ((void (*)(w3d_oarg, w3d_oarg))A801ea4c8)(W(r3), W(r4));
    r11 = L32(r31 + 44);
    r4 = 0x2cu;
    r7 = L32(r1 + 104);
    r5 = 0x3u;
    r9 = L32(r11 + r25);
    r8 = r7 + 132;
    r11 = L32(r9 + 36);
    r9 = r9 + 36;
    r0 = L32(r9 + 8);
    r10 = L32(r9 + 4);
    S32(r7 + 132, r11);
    S32(r8 + 8, r0);
    S32(r8 + 4, r10);
    r11 = L32(r31 + 44);
    r8 = L32(r1 + 104);
    r9 = L32(r11 + r25);
    r7 = r8 + 120;
    r10 = L32(r9 + 48);
    r9 = r9 + 48;
    r0 = L32(r9 + 8);
    r11 = L32(r9 + 4);
    S32(r8 + 120, r10);
    S32(r7 + 8, r0);
    S32(r7 + 4, r11);
    r6 = L32(r1 + 104);
    r3 = L32(r31 + 888);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801ef174)(W(r3), W(r4), W(r5), W(r6));
    r26 = L8(r31 + 3176);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r30;
    r4 = r31 + 892;
    r5 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c048)(W(r3), W(r4), W(r5));
    r10 = L32(r31 + 44);
    r8 = L32(r31 + 80);
    r11 = L32(r10 + r25);
    r9 = L32(r11 + 28);
    r9 = r9 << 2;
    r11 = L32(r9 + r8);
    r0 = L32(r11 + 68);
    cr0 = CMPS(r0, 3);
    if ((cr0 & 2)) goto L_800f4998;
    if ((cr0 & 4)) goto L_800f4958;
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_800f4970;
    cr0 = CMPS(r0, 2);
    if ((cr0 & 2)) goto L_800f4984;
    goto L_800f49e8;
L_800f4958:
    cr0 = CMPS(r0, 5);
    if ((cr0 & 2)) goto L_800f49c0;
    if ((cr0 & 8)) goto L_800f49ac;
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_800f49d4;
    goto L_800f49e8;
L_800f4970:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c4e0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    goto L_800f49f8;
L_800f4984:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c4ecu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    goto L_800f49f8;
L_800f4998:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c4f8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    goto L_800f49f8;
L_800f49ac:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c508u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    goto L_800f49f8;
L_800f49c0:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c518u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    goto L_800f49f8;
L_800f49d4:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c528u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    goto L_800f49f8;
L_800f49e8:
    r4 = D(0x80390000u);
    r3 = r29;
    r4 = D(0x8038c538u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
L_800f49f8:
    r4 = D(0x80390000u);
    r3 = L32(r1 + 112);
    r4 = D(0x8038c538u);
    r30 = 0x1u;
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_800f4a18;
    r30 = 0x0u;
L_800f4a18:
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_800f4e38;
    r3 = L32(r28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f4a70;
    r9 = L32(r3);
    r0 = L32(r9 + 64);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r3);
    r0 = L32(r9 + 68);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r3);
    r4 = L32(r1 + 112);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_800f4a68;
    r0 = 0x0u;
L_800f4a68:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_800f4aa4;
L_800f4a70:
    r3 = r29;
    r5 = r26;
    r4 = r28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r31 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f4aa4;
    r9 = L32(r3);
    r5 = 0x0u;
    r4 = L32(r28);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f4aa4:
    r5 = L32(r31 + 44);
    r7 = r1 + 56;
    r10 = L32(r31 + 80);
    r6 = r1 + 88;
    r11 = L32(r5 + r25);
    r4 = r1 + 72;
    r3 = r1 + 172;
    r21 = r7;
    r9 = L32(r11 + 28);
    r18 = r6;
    r26 = r1 + 148;
    r24 = r1 + 160;
    r9 = r9 << 2;
    r22 = r3;
    r30 = L32(r9 + r10);
    r23 = r1 + 120;
    r19 = D(0x80390000u);
    r11 = L32(r30 + 32);
    r9 = r30 + 32;
    r0 = L32(r9 + 4);
    r10 = r30 + 20;
    r8 = L32(r9 + 8);
    S32(r1 + 56, r11);
    S32(r7 + 4, r0);
    S32(r7 + 8, r8);
    r9 = L32(r30 + 20);
    r11 = L32(r10 + 8);
    r0 = L32(r10 + 4);
    S32(r1 + 88, r9);
    S32(r6 + 4, r0);
    S32(r6 + 8, r11);
    r9 = L32(r5 + r25);
    r10 = L32(r9 + 48);
    r9 = r9 + 48;
    r11 = L32(r9 + 4);
    r0 = L32(r9 + 8);
    S32(r1 + 72, r10);
    S32(r4 + 4, r11);
    S32(r4 + 8, r0);
    ((void (*)())A80343740)();
    r9 = D(0x80460000u);
    r11 = r1 + 136;
    r29 = r11;
    r9 = D(0x8045e748u);
    r10 = 0x30u;
L_800f4b58:
    r0 = L32(r9);
    { w3d_u32 t_ = r10; r10 = t_ + (w3d_u32)-24; ca = r10 < t_; cr0 = CMPS(r10, 0); }
    S32(r11, r0);
    r0 = L32(r9 + 4);
    S32(r11 + 4, r0);
    r0 = L32(r9 + 8);
    S32(r11 + 8, r0);
    r0 = L32(r9 + 12);
    S32(r11 + 12, r0);
    r0 = L32(r9 + 16);
    S32(r11 + 16, r0);
    r0 = L32(r9 + 20);
    r9 = r9 + 24;
    S32(r11 + 20, r0);
    r11 = r11 + 24;
    if (!(cr0 & 2)) goto L_800f4b58;
    f1 = LF(r1 + 72);
    r3 = r29;
    ((void (*)(w3d_oarg, float))A801f6120)(W(r3), (float)f1);
    f1 = LF(r1 + 76);
    r3 = r29;
    ((void (*)(w3d_oarg, float))A801f61a0)(W(r3), (float)f1);
    f1 = LF(r1 + 80);
    r3 = r29;
    ((void (*)(w3d_oarg, float))A801f621c)(W(r3), (float)f1);
    r11 = L32(r31 + 44);
    r7 = r30 + 44;
    f11 = LF(r1 + 148);
    r3 = r29;
    r9 = L32(r11 + r25);
    f9 = LF(r1 + 136);
    r11 = r9 + 36;
    r10 = L32(r9 + 36);
    r8 = L32(r11 + 8);
    r0 = L32(r11 + 4);
    S32(r1 + 172, r10);
    S32(r1 + 176, r0);
    S32(r1 + 180, r8);
    f10 = LF(r1 + 160);
    f0 = LF(r7 + 4);
    f12 = LF(r30 + 44);
    f13 = LF(r7 + 8);
    f0 = (float)(f0 * f11);
    f11 = LF(r1 + 172);
    f12 = __builtin_fmaf((float)f12, (float)f9, (float)f0);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f12);
    f9 = LF(r29 + 4);
    f10 = LF(r22 + 4);
    f13 = (float)(f13 + f11);
    SF(r1 + 40, f13);
    f1 = LF(r1 + 64);
    f13 = LF(r7 + 4);
    f12 = LF(r26 + 4);
    f11 = LF(r30 + 44);
    f13 = (float)(f13 * f12);
    f0 = LF(r7 + 8);
    f12 = LF(r24 + 4);
    f11 = __builtin_fmaf((float)f11, (float)f9, (float)f13);
    f7 = LF(r29 + 8);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f11);
    f8 = LF(r22 + 8);
    f0 = (float)(f0 + f10);
    SF(r1 + 44, f0);
    f13 = LF(r7 + 4);
    f11 = LF(r26 + 8);
    f12 = LF(r30 + 44);
    f13 = (float)(f13 * f11);
    f0 = LF(r7 + 8);
    f11 = LF(r24 + 8);
    f12 = __builtin_fmaf((float)f12, (float)f7, (float)f13);
    f0 = __builtin_fmaf((float)f0, (float)f11, (float)f12);
    f0 = (float)(f0 + f8);
    SF(r1 + 48, f0);
    ((void (*)(w3d_oarg, float))A801f63cc)(W(r3), (float)f1);
    f1 = LF(r1 + 60);
    r3 = r29;
    ((void (*)(w3d_oarg, float))A801f6350)(W(r3), (float)f1);
    f1 = LF(r1 + 56);
    r3 = r29;
    ((void (*)(w3d_oarg, float))A801f62d0)(W(r3), (float)f1);
    r3 = r29;
    r4 = r21;
    ((void (*)(w3d_oarg, w3d_oarg))A8009ed90)(W(r3), W(r4));
    r9 = L32(r28);
    r4 = r23;
    f31 = LF(D(0x8038c558u));
    r5 = 0x0u;
    f13 = LF(r1 + 40);
    r3 = r9;
    f12 = LF(r1 + 44);
    f0 = LF(r1 + 48);
    f13 = (float)(f13 * f31);
    r11 = L32(r9);
    f12 = (float)(f12 * f31);
    f0 = (float)(f0 * f31);
    SF(r1 + 120, f13);
    SF(r1 + 124, f12);
    SF(r1 + 128, f0);
    SF(r1 + 184, f13);
    SF(r1 + 188, f12);
    SF(r1 + 192, f0);
    r0 = L32(r11 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r28);
    r4 = r21;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 80);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f13 = LF(r1 + 88);
    r4 = r18;
    f12 = LF(r1 + 92);
    r5 = 0x0u;
    f0 = LF(r1 + 96);
    f13 = (float)(f13 * f30);
    f12 = (float)(f12 * f30);
    SF(r1 + 88, f13);
    f0 = (float)(f0 * f30);
    SF(r1 + 92, f12);
    SF(r1 + 96, f0);
    r3 = L32(r28);
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f0 = LF(r1 + 40);
    f12 = LF(r1 + 44);
    f11 = (float)(f0 * f31);
    f13 = LF(r1 + 48);
    f0 = LF(r1 + 8);
    f12 = (float)(f12 * f31);
    f13 = (float)(f13 * f31);
    SF(r1 + 124, f12);
    SF(r1 + 128, f13);
    cr0 = CMPF(f11, f0);
    SF(r1 + 184, f11);
    SF(r1 + 188, f12);
    SF(r1 + 192, f13);
    SF(r1 + 120, f11);
    if (!(cr0 & 8)) goto L_800f4d94;
    SF(r1 + 8, f11);
L_800f4d94:
    f13 = LF(r1 + 124);
    f0 = LF(r20 + 4);
    cr0 = CMPF(f13, f0);
    if (!(cr0 & 8)) goto L_800f4da8;
    SF(r20 + 4, f13);
L_800f4da8:
    f13 = LF(r1 + 128);
    f0 = LF(r20 + 8);
    cr0 = CMPF(f13, f0);
    if (!(cr0 & 8)) goto L_800f4dbc;
    SF(r20 + 8, f13);
L_800f4dbc:
    f0 = LF(r1 + 40);
    f12 = LF(r1 + 44);
    f11 = (float)(f0 * f31);
    f13 = LF(r1 + 48);
    f0 = LF(r1 + 24);
    f12 = (float)(f12 * f31);
    f13 = (float)(f13 * f31);
    SF(r1 + 124, f12);
    SF(r1 + 128, f13);
    cr0 = CMPF(f11, f0);
    SF(r1 + 184, f11);
    SF(r1 + 188, f12);
    SF(r1 + 192, f13);
    SF(r1 + 120, f11);
    if (!(cr0 & 4)) goto L_800f4dfc;
    SF(r1 + 24, f11);
L_800f4dfc:
    f13 = LF(r1 + 124);
    f0 = LF(r1 + 28);
    cr0 = CMPF(f13, f0);
    if (!(cr0 & 4)) goto L_800f4e10;
    SF(r1 + 28, f13);
L_800f4e10:
    f13 = LF(r1 + 128);
    f0 = LF(r1 + 32);
    cr0 = CMPF(f13, f0);
    if (!(cr0 & 4)) goto L_800f4e24;
    SF(r1 + 32, f13);
L_800f4e24:
    r9 = r25 + r31;
    r4 = L32(r31 + 32);
    r3 = L32(r9 + 88);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80182498)(W(r3), W(r4));
    goto L_800f4e58;
L_800f4e38:
    r3 = L32(r28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f4e54;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f4e54:
    S32(r28, r30);
L_800f4e58:
    r3 = r1 + 112;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 112;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 104);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f4e84;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f4e84:
    r0 = L32(r31 + 48);
    r27 = r27 + 1;
    r9 = L32(r31 + 44);
    r28 = r28 + 4;
    r25 = r25 + 4;
    r0 = r0 - r9;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r27, r0);
    if ((cr0 & 8)) goto L_800f4768;
L_800f4ea8:
    r3 = L32(r31 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f4ec4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f4ec4:
    f7 = LF(r1 + 24);
    r9 = D(0x80390000u);
    f9 = LF(r1 + 8);
    r0 = 0x0u;
    f0 = LF(r20 + 8);
    r27 = 0x0u;
    f8 = LF(r20 + 4);
    f13 = (float)(f7 - f9);
    f6 = LF(r1 + 28);
    f9 = (float)(f9 + f7);
    f10 = LF(r20 + 4);
    f7 = f0;
    f11 = LF(r1 + 32);
    f8 = (float)(f6 - f8);
    f12 = LF(D(0x8038c560u));
    f1 = (float)(f8 * f8);
    f0 = (float)(f0 + f11);
    S32(r31 + 32, r0);
    f10 = (float)(f10 + f6);
    SF(r1 + 120, f13);
    f0 = (float)(f0 * f12);
    SF(r1 + 124, f8);
    f11 = (float)(f11 - f7);
    SF(r1 + 112, f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    SF(r1 + 128, f11);
    f9 = (float)(f9 * f12);
    r28 = r31 + 44;
    f10 = (float)(f10 * f12);
    SF(r1 + 104, f9);
    f1 = __builtin_fmaf((float)f11, (float)f11, (float)f1);
    SF(r1 + 108, f10);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r26 = r31 + 56;
    r9 = D(0x80390000u);
    r11 = D(0x80390000u);
    f13 = LF(D(0x8038c564u));
    r29 = r1 + 88;
    f0 = LF(D(0x8038c568u));
    r30 = r31 + 88;
    f1 = (float)(f1 + f13);
    f31 = (float)(f0 / f1);
L_800f4f6c:
    r3 = L32(r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f5064;
    r9 = L32(r3);
    r0 = L32(r9 + 100);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = r3;
    f0 = LF(r1 + 104);
    f12 = LF(r9);
    r4 = r1 + 40;
    f11 = LF(r1 + 108);
    r5 = 0x0u;
    f12 = (float)(f12 - f0);
    f10 = LF(r1 + 112);
    SF(r1 + 40, f12);
    f12 = (float)(f12 * f31);
    f13 = LF(r9 + 4);
    r11 = L32(r30);
    f13 = (float)(f13 - f11);
    SF(r1 + 44, f13);
    r3 = r11;
    f13 = (float)(f13 * f31);
    f0 = LF(r9 + 8);
    SF(r1 + 40, f12);
    f0 = (float)(f0 - f10);
    SF(r1 + 44, f13);
    f0 = (float)(f0 * f31);
    SF(r1 + 48, f0);
    r9 = L32(r11);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r30);
    r9 = L32(r3);
    r0 = L32(r9 + 108);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = r3;
    r8 = L32(r30);
    r11 = L32(r9);
    r4 = r29;
    r0 = L32(r9 + 4);
    r3 = r8;
    r10 = L32(r9 + 8);
    r5 = 0x0u;
    S32(r1 + 88, r11);
    S32(r29 + 4, r0);
    S32(r29 + 8, r10);
    f0 = LF(r1 + 88);
    f13 = LF(r1 + 92);
    f12 = LF(r1 + 96);
    f0 = (float)(f0 * f31);
    f13 = (float)(f13 * f31);
    SF(r1 + 88, f0);
    f12 = (float)(f12 * f31);
    SF(r1 + 92, f13);
    SF(r1 + 96, f12);
    r9 = L32(r8);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f5064:
    r27 = r27 + 1;
    r30 = r30 + 4;
    cr0 = CMPU(r27, 0xc7u);
    if (!(cr0 & 4)) goto L_800f4f6c;
    r9 = L32(r31 + 44);
    r27 = 0x0u;
    r0 = L32(r28 + 4);
    r0 = r0 - r9;
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_800f50d4;
    r29 = 0x0u;
    r30 = 0x0u;
L_800f5094:
    r9 = L32(r31 + 44);
    r3 = L32(r9 + r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_800f50ac;
    r4 = 0x3u;
    ((void (*)(w3d_oarg, w3d_oarg))A800f6ca0)(W(r3), W(r4));
L_800f50ac:
    r9 = L32(r31 + 44);
    r27 = r27 + 1;
    S32(r9 + r30, r29);
    r30 = r30 + 4;
    r0 = L32(r28 + 4);
    r9 = L32(r31 + 44);
    r0 = r0 - r9;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r27, r0);
    if ((cr0 & 8)) goto L_800f5094;
L_800f50d4:
    r30 = L32(r26 + 4);
    r5 = 0x0u;
    r0 = L32(r31 + 56);
    r4 = r30;
    r30 = r30 - r0;
    r3 = r0;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r26 + 4);
    r5 = 0x0u;
    r0 = r0 - r30;
    S32(r26 + 4, r0);
    r30 = L32(r28 + 4);
    r9 = L32(r31 + 44);
    r4 = r30;
    r30 = r30 - r9;
    r3 = r9;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r28 + 4);
    r0 = r0 - r30;
    S32(r28 + 4, r0);
    r1 = r1 + 288;
    return r3;
}

// 0x800f5f44 FUN_800f5f44 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: update. Llama a point_init, rotate_cols12, rotate_rows_y, rotate_cols01, sol35a3_pool_allocate. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A800f5f44(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[392];
    w3d_u32 r1 = h2g(frame) + 376;
    w3d_u32 r0 = 0, r5 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, ctr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 376; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r21 = r4;
    r3 = r1 + 156;
    ((void (*)())A80343740)();
    r3 = r1 + 204;
    ((void (*)())A80343740)();
    r9 = D(0x80460000u);
    r11 = r1 + 120;
    r30 = r11;
    r9 = D(0x8045e748u);
    r10 = 0x30u;
L_800f5f94:
    r0 = L32(r9);
    { w3d_u32 t_ = r10; r10 = t_ + (w3d_u32)-24; ca = r10 < t_; cr0 = CMPS(r10, 0); }
    S32(r11, r0);
    r0 = L32(r9 + 4);
    S32(r11 + 4, r0);
    r0 = L32(r9 + 8);
    S32(r11 + 8, r0);
    r0 = L32(r9 + 12);
    S32(r11 + 12, r0);
    r0 = L32(r9 + 16);
    S32(r11 + 16, r0);
    r0 = L32(r9 + 20);
    r9 = r9 + 24;
    S32(r11 + 20, r0);
    r11 = r11 + 24;
    if (!(cr0 & 2)) goto L_800f5f94;
    f1 = LF(r21 + 48);
    r3 = r30;
    r31 = 0x0u;
    ((void (*)(w3d_oarg, float))A801f6120)(W(r3), (float)f1);
    f1 = LF(r21 + 52);
    r3 = r30;
    ((void (*)(w3d_oarg, float))A801f61a0)(W(r3), (float)f1);
    f1 = LF(r21 + 56);
    r3 = r30;
    ((void (*)(w3d_oarg, float))A801f621c)(W(r3), (float)f1);
    r9 = r21 + 36;
    r11 = L32(r21 + 36);
    r10 = L32(r9 + 8);
    r0 = L32(r9 + 4);
    S32(r1 + 164, r10);
    S32(r1 + 160, r0);
    S32(r1 + 156, r11);
    r11 = L32(r29 + 36);
    r0 = L32(r21 + 28);
    r9 = L32(r11 + 44);
    r0 = r0 << 2;
    r9 = r9 + 32;
    r11 = L32(r9 + r0);
    r10 = L32(r11 + 76);
    r15 = L32(r10 + 24);
    r25 = r10 + 32;
    cr0 = CMPU(r31, r15);
    if (!(cr0 & 8)) goto L_800f65a4;
    r9 = D(0x80390000u);
    r11 = D(0x80390000u);
    r10 = D(0x80390000u);
    r20 = r30;
    f27 = LF(D(0x8038c56cu));
    r26 = r1 + 8;
    f29 = LF(D(0x8038c570u));
    r17 = r1 + 24;
    f28 = LF(D(0x8038c574u));
    r18 = r1 + 40;
    r30 = r1 + 168;
    r22 = r1 + 180;
    r23 = r1 + 192;
    r27 = r1 + 132;
    r28 = r1 + 144;
    r24 = r1 + 204;
    r19 = r1 + 156;
    r29 = r21 + 16;
    r14 = r1 + 216;
L_800f6090:
    r3 = D(0x804adde4u);
    r4 = 0x40u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802098d8)(W(r3), W(r4));
    r16 = r31 + 1;
    r0 = 0x3u;
    r31 = r31 << 2;
    ctr = r0;
L_800f60ac:
    --ctr; if (ctr != 0) goto L_800f60ac;
    S32(r1 + 216, r3);
    r10 = D(0x80460000u);
    SF(r1 + 8, f27);
    r11 = D(0x8045e748u);
    SF(r26 + 4, f29);
    r9 = r30;
    SF(r26 + 8, f29);
    r10 = 0x30u;
    SF(r1 + 24, f29);
    SF(r17 + 4, f27);
    SF(r17 + 8, f29);
    SF(r1 + 40, f29);
    SF(r18 + 4, f29);
    SF(r18 + 8, f27);
L_800f60e8:
    r0 = L32(r11);
    { w3d_u32 t_ = r10; r10 = t_ + (w3d_u32)-24; ca = r10 < t_; cr0 = CMPS(r10, 0); }
    S32(r9, r0);
    r0 = L32(r11 + 4);
    S32(r9 + 4, r0);
    r0 = L32(r11 + 8);
    S32(r9 + 8, r0);
    r0 = L32(r11 + 12);
    S32(r9 + 12, r0);
    r0 = L32(r11 + 16);
    S32(r9 + 16, r0);
    r0 = L32(r11 + 20);
    r11 = r11 + 24;
    S32(r9 + 20, r0);
    r9 = r9 + 24;
    if (!(cr0 & 2)) goto L_800f60e8;
    r9 = L32(r31 + r25);
    r3 = r30;
    f1 = LF(r9 + 20);
    ((void (*)(w3d_oarg, float))A801f6120)(W(r3), (float)f1);
    r9 = L32(r31 + r25);
    r3 = r30;
    f1 = LF(r9 + 24);
    ((void (*)(w3d_oarg, float))A801f61a0)(W(r3), (float)f1);
    r9 = L32(r31 + r25);
    r3 = r30;
    f1 = LF(r9 + 28);
    ((void (*)(w3d_oarg, float))A801f621c)(W(r3), (float)f1);
    r9 = L32(r31 + r25);
    f30 = LF(r1 + 180);
    r11 = r9 + 44;
    r10 = L32(r9 + 44);
    r8 = L32(r11 + 8);
    r0 = L32(r11 + 4);
    S32(r1 + 204, r10);
    S32(r1 + 208, r0);
    S32(r1 + 212, r8);
    f10 = LF(r1 + 8);
    f0 = LF(r26 + 4);
    f1 = LF(r1 + 168);
    f31 = LF(r26 + 8);
    f0 = (float)(f0 * f30);
    f2 = LF(r1 + 192);
    f0 = __builtin_fmaf((float)f10, (float)f1, (float)f0);
    f6 = LF(r1 + 28);
    f31 = __builtin_fmaf((float)f31, (float)f2, (float)f0);
    f5 = LF(r1 + 24);
    SF(r1 + 56, f31);
    f11 = (float)(f6 * f30);
    f4 = LF(r1 + 32);
    f11 = __builtin_fmaf((float)f5, (float)f1, (float)f11);
    f13 = LF(r22 + 4);
    f12 = LF(r26 + 4);
    f11 = __builtin_fmaf((float)f4, (float)f2, (float)f11);
    f0 = LF(r30 + 4);
    f12 = (float)(f12 * f13);
    f7 = LF(r26 + 8);
    f13 = LF(r23 + 4);
    f0 = __builtin_fmaf((float)f10, (float)f0, (float)f12);
    f7 = __builtin_fmaf((float)f7, (float)f13, (float)f0);
    SF(r1 + 60, f7);
    f13 = LF(r22 + 8);
    f0 = LF(r26 + 4);
    f12 = LF(r30 + 8);
    f0 = (float)(f0 * f13);
    f3 = LF(r26 + 8);
    f13 = LF(r23 + 8);
    f10 = __builtin_fmaf((float)f10, (float)f12, (float)f0);
    SF(r1 + 72, f11);
    f3 = __builtin_fmaf((float)f3, (float)f13, (float)f10);
    SF(r1 + 64, f3);
    f13 = LF(r22 + 4);
    f12 = LF(r30 + 4);
    f13 = (float)(f6 * f13);
    f0 = LF(r23 + 4);
    f12 = __builtin_fmaf((float)f5, (float)f12, (float)f13);
    f0 = __builtin_fmaf((float)f4, (float)f0, (float)f12);
    SF(r1 + 76, f0);
    f13 = LF(r22 + 8);
    f8 = LF(r1 + 44);
    f12 = LF(r30 + 8);
    f6 = (float)(f6 * f13);
    f9 = LF(r1 + 40);
    f30 = (float)(f8 * f30);
    f0 = LF(r23 + 8);
    f5 = __builtin_fmaf((float)f5, (float)f12, (float)f6);
    f10 = LF(r1 + 48);
    f1 = __builtin_fmaf((float)f9, (float)f1, (float)f30);
    f4 = __builtin_fmaf((float)f4, (float)f0, (float)f5);
    f12 = LF(r1 + 132);
    f2 = __builtin_fmaf((float)f10, (float)f2, (float)f1);
    SF(r1 + 80, f4);
    SF(r1 + 88, f2);
    f7 = (float)(f7 * f12);
    f13 = LF(r1 + 120);
    f0 = LF(r22 + 4);
    f12 = LF(r30 + 4);
    f31 = __builtin_fmaf((float)f31, (float)f13, (float)f7);
    f13 = LF(r23 + 4);
    f0 = (float)(f8 * f0);
    f12 = __builtin_fmaf((float)f9, (float)f12, (float)f0);
    f11 = LF(r1 + 144);
    f13 = __builtin_fmaf((float)f10, (float)f13, (float)f12);
    r11 = L32(r1 + 216);
    SF(r1 + 92, f13);
    f3 = __builtin_fmaf((float)f3, (float)f11, (float)f31);
    r9 = r11 + 16;
    r10 = r11 + 28;
    f13 = LF(r22 + 8);
    r8 = r11 + 40;
    f12 = LF(r30 + 8);
    r7 = r11 + 4;
    f0 = LF(r23 + 8);
    f8 = (float)(f8 * f13);
    f9 = __builtin_fmaf((float)f9, (float)f12, (float)f8);
    f10 = __builtin_fmaf((float)f10, (float)f0, (float)f9);
    SF(r1 + 96, f10);
    SF(r11 + 16, f3);
    f12 = LF(r27 + 4);
    f11 = LF(r1 + 60);
    f10 = LF(r20 + 4);
    f13 = LF(r1 + 56);
    f11 = (float)(f11 * f12);
    f12 = LF(r28 + 4);
    f0 = LF(r1 + 64);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r9 + 4, f0);
    f12 = LF(r27 + 8);
    f11 = LF(r1 + 60);
    f10 = LF(r20 + 8);
    f11 = (float)(f11 * f12);
    f13 = LF(r1 + 56);
    f12 = LF(r28 + 8);
    f0 = LF(r1 + 64);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r9 + 8, f0);
    f12 = LF(r1 + 132);
    f11 = LF(r1 + 76);
    f10 = LF(r1 + 120);
    f13 = LF(r1 + 72);
    f11 = (float)(f11 * f12);
    f12 = LF(r1 + 144);
    f0 = LF(r1 + 80);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r11 + 28, f0);
    f12 = LF(r27 + 4);
    f11 = LF(r1 + 76);
    f10 = LF(r20 + 4);
    f13 = LF(r1 + 72);
    f11 = (float)(f11 * f12);
    f12 = LF(r28 + 4);
    f0 = LF(r1 + 80);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r10 + 4, f0);
    f12 = LF(r27 + 8);
    f11 = LF(r1 + 76);
    f10 = LF(r20 + 8);
    f13 = LF(r1 + 72);
    f11 = (float)(f11 * f12);
    f12 = LF(r28 + 8);
    f0 = LF(r1 + 80);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r10 + 8, f0);
    f12 = LF(r1 + 132);
    f11 = LF(r1 + 92);
    f10 = LF(r1 + 120);
    f13 = LF(r1 + 88);
    f11 = (float)(f11 * f12);
    f12 = LF(r1 + 144);
    f0 = LF(r1 + 96);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r11 + 40, f0);
    f12 = LF(r27 + 4);
    f11 = LF(r1 + 92);
    f10 = LF(r20 + 4);
    f11 = (float)(f11 * f12);
    f13 = LF(r1 + 88);
    f12 = LF(r28 + 4);
    f0 = LF(r1 + 96);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r8 + 4, f0);
    f12 = LF(r27 + 8);
    f11 = LF(r1 + 92);
    f10 = LF(r20 + 8);
    f13 = LF(r1 + 88);
    f11 = (float)(f11 * f12);
    f12 = LF(r28 + 8);
    f0 = LF(r1 + 96);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f12, (float)f13);
    SF(r8 + 8, f0);
    f13 = LF(r1 + 132);
    f12 = LF(r24 + 4);
    f9 = LF(r1 + 120);
    f11 = LF(r1 + 204);
    f12 = (float)(f12 * f13);
    f10 = LF(r1 + 144);
    f0 = LF(r24 + 8);
    f11 = __builtin_fmaf((float)f11, (float)f9, (float)f12);
    f13 = LF(r1 + 156);
    f0 = __builtin_fmaf((float)f0, (float)f10, (float)f11);
    f0 = (float)(f0 + f13);
    SF(r11 + 4, f0);
    f13 = LF(r27 + 4);
    f12 = LF(r24 + 4);
    f9 = LF(r20 + 4);
    f11 = LF(r1 + 204);
    f12 = (float)(f12 * f13);
    f10 = LF(r28 + 4);
    f0 = LF(r24 + 8);
    f11 = __builtin_fmaf((float)f11, (float)f9, (float)f12);
    f13 = LF(r19 + 4);
    f0 = __builtin_fmaf((float)f0, (float)f10, (float)f11);
    f0 = (float)(f0 + f13);
    SF(r7 + 4, f0);
    f13 = LF(r27 + 8);
    f12 = LF(r24 + 4);
    f11 = LF(r1 + 204);
    f9 = LF(r20 + 8);
    f12 = (float)(f12 * f13);
    f0 = LF(r24 + 8);
    f10 = LF(r28 + 8);
    f11 = __builtin_fmaf((float)f11, (float)f9, (float)f12);
    f13 = LF(r19 + 8);
    f0 = __builtin_fmaf((float)f0, (float)f10, (float)f11);
    f0 = (float)(f0 + f13);
    SF(r7 + 8, f0);
    r9 = L32(r31 + r25);
    f0 = LF(r9 + 32);
    f0 = (float)(f0 * f28);
    SF(r11 + 52, f0);
    r9 = L32(r31 + r25);
    r11 = L32(r1 + 216);
    f0 = LF(r9 + 32);
    f0 = (float)(f0 * f28);
    SF(r11 + 56, f0);
    r9 = L32(r31 + r25);
    r11 = L32(r1 + 216);
    f0 = LF(r9 + 32);
    f0 = (float)(f0 * f28);
    SF(r11 + 60, f0);
    r11 = L32(r29 + 4);
    r0 = L32(r29 + 8);
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_800f6580;
    r9 = L32(r21 + 16);
    r10 = r1 + 224;
    r8 = r1 + 220;
    r9 = r11 - r9;
    r0 = r9 >> 1;
    r11 = r9 + 1;
    r0 = r9 + r0;
    S32(r1 + 232, r9);
    cr0 = CMPS(r11, r0);
    S32(r1 + 220, r11);
    S32(r1 + 224, r0);
    if (!(cr0 & 8)) goto L_800f650c;
    r8 = r10;
L_800f650c:
    r0 = L32(r8);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 228, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r21 + 16);
    r31 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_800f6564;
    r9 = L32(r1 + 228);
    r11 = r1 + 232;
    r0 = L32(r1 + 232);
    r5 = r1 + 228;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_800f654c;
    r5 = r11;
L_800f654c:
    r5 = L32(r5);
    r3 = r31;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r21 + 16);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_800f6564:
    r0 = L32(r1 + 232);
    r9 = L32(r1 + 228);
    r0 = r31 + r0;
    S32(r29, r31);
    r9 = r31 + r9;
    S32(r29 + 4, r0);
    S32(r29 + 8, r9);
L_800f6580:
    r11 = L32(r29 + 4);
    r31 = r16;
    r0 = L32(r14);
    cr0 = CMPU(r31, r15);
    S32(r11, r0);
    r9 = L32(r29 + 4);
    r9 = r9 + 4;
    S32(r29 + 4, r9);
    if ((cr0 & 8)) goto L_800f6090;
L_800f65a4:
    r1 = r1 + 376;
    return r3;
}

// 0x800f8804 FUN_800f8804 no verificada: desde bytes PPC
// Llama a sol35f7a_halfword_insert, message_find_id, qsort, heap_allocate. Usa las cadenas "Input.KeyTyped", "Chat.OpenConsole", "Chat.CloseConsole".
__attribute__((weak)) w3d_u32 A800f8804(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r0 = L32(D(0x804aaf4cu));
    r29 = r3;
    r31 = 0x0u;
    r27 = D(0x804aaf4cu);
    cr0 = CMPS(r0, 0);
    r6 = r1 + 8;
    if ((cr0 & 2)) goto L_800f8844;
    r9 = D(0x804aaf4cu);
L_800f8834:
    { w3d_u32 t_ = r9 + 4; r0 = L32(t_); r9 = t_; }
    r31 = r31 + 1;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_800f8834;
L_800f8844:
    r11 = r29 + 412;
    r10 = L32(r29 + 412);
    r4 = L32(r11 + 4);
    r0 = 0x0u;
    r28 = r11;
    S16(r1 + 8, r0);
    r9 = r4 - r10;
    { w3d_u32 t_ = r9; r9 = (w3d_u32)((w3d_s32)t_ >> 1); ca = SRAWCA(t_, 1); }
    cr0 = CMPU(r31, r9);
    if (!(cr0 & 8)) goto L_800f887c;
    r0 = r31 + r31;
    r0 = r0 + r10;
    S32(r11 + 4, r0);
    goto L_800f8888;
L_800f887c:
    r5 = r31 - r9;
    r3 = r28;
    r3 = CU(A80346ef0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800f8888:
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_800f88b0;
    r30 = 0x0u;
    cr0 = CMPU(r30, r31);
    r31 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
L_800f889c:
    r3 = L32(D(0x804aaf4cu));
    r4 = L32(r29 + 412);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80161f54)(W(r3), W(r4));
    cr0 = (r31 >> 28) & 15;
    if ((cr0 & 8)) goto L_800f889c;
L_800f88b0:
    r3 = L32(r29 + 412);
    r6 = 0x80100000u;
    r4 = L32(r28 + 4);
    r6 = FN(0x800f87f4u);
    r5 = 0x2u;
    r4 = r4 - r3;
    { w3d_u32 t_ = r4; r4 = (w3d_u32)((w3d_s32)t_ >> 1); ca = SRAWCA(t_, 1); }
    r3 = CU(A802ede44, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = 0x5u;
    r3 = 0xau;
    S32(r29 + 440, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe220)(W(r3));
    r0 = r3;
    r3 = D(0x80390000u);
    r4 = r0;
    S32(r29 + 436, r0);
    r3 = D(0x8038cae8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80161f54)(W(r3), W(r4));
    r4 = L32(r29 + 436);
    r3 = D(0x80390000u);
    r3 = D(0x8038caf8u);
    r4 = r4 + 2;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80161f54)(W(r3), W(r4));
    r4 = L32(r29 + 436);
    r3 = D(0x80390000u);
    r3 = D(0x8038cb0cu);
    r4 = r4 + 4;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80161f54)(W(r3), W(r4));
    r4 = L32(r29 + 436);
    r3 = D(0x80390000u);
    r3 = D(0x8038cb20u);
    r4 = r4 + 6;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80161f54)(W(r3), W(r4));
    r4 = L32(r29 + 436);
    r3 = D(0x80390000u);
    r3 = D(0x8038cb2cu);
    r4 = r4 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80161f54)(W(r3), W(r4));
    r1 = r1 + 40;
    return r3;
}

// 0x800fbd48 FUN_800fbd48 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: reset. Llama a text_default, text_format, resource_property, large_reserve_string_finish, large_reserve_string_release. Usa las cadenas "Worm.Data%.2d", "Inventory.Worm%.2d", "AIParams.Worm%.2d".
// aviso: lee r3 tras void 80341588 en 800fbf4c
__attribute__((weak)) w3d_u32 A800fbd48(void) {
    alignas(16) char frame[136];
    w3d_u32 r1 = h2g(frame) + 120;
    w3d_u32 r0 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 120; S32(t_, r1); r1 = t_; }
    r3 = r1 + 8;
    r30 = 0x0u;
    r23 = r3;
    r16 = D(0x803a0000u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r31 = r23;
    r9 = D(0x80450000u);
    r11 = D(0x80450000u);
    r10 = D(0x80450000u);
    r27 = D(0x8044a584u);
    r28 = D(0x8044a5e4u);
    r29 = D(0x8044a524u);
    r24 = r1 + 16;
    r18 = D(0x803a0000u);
    r25 = r1 + 20;
    r19 = D(0x803a0000u);
    r26 = r1 + 24;
    r20 = r1 + 28;
    r14 = D(0x803a0000u);
    r21 = r1 + 32;
    r15 = D(0x803a0000u);
    r22 = r1 + 36;
    r17 = r1 + 40;
L_800fbdb4:
    r3 = r1 + 8;
    r5 = r30;
    r4 = D(0x80398058u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 8);
    r4 = r29;
    r3 = r24;
    r29 = r29 + 4;
    S32(r1 + 16, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = r30;
    r3 = r31;
    r4 = D(0x80398068u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 8);
    r4 = r27;
    r3 = r25;
    r27 = r27 + 4;
    S32(r1 + 20, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = r30;
    r3 = r31;
    r4 = D(0x8039807cu);
    r30 = r30 + 1;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 8);
    r4 = r28;
    r3 = r26;
    r28 = r28 + 4;
    S32(r1 + 24, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPU(r30, 0xfu);
    if (!(cr0 & 4)) goto L_800fbdb4;
    r9 = D(0x80450000u);
    r11 = D(0x80450000u);
    r10 = D(0x80450000u);
    r28 = D(0x8044a5c4u);
    r29 = D(0x8044a574u);
    r30 = D(0x8044a564u);
    r31 = 0x0u;
    r27 = r23;
L_800fbe64:
    r9 = D(0x803a0000u);
    r3 = r1 + 8;
    r4 = D(0x80398090u);
    r5 = r31;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 8);
    r4 = r30;
    r3 = r20;
    r30 = r30 + 4;
    S32(r1 + 28, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = r31;
    r3 = r27;
    r4 = D(0x803980a0u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 8);
    r4 = r28;
    r3 = r21;
    r28 = r28 + 4;
    S32(r1 + 32, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = r31;
    r3 = r27;
    r4 = D(0x803980b4u);
    r31 = r31 + 1;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 8);
    r4 = r29;
    r3 = r22;
    r29 = r29 + 4;
    S32(r1 + 36, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPU(r31, 0x3u);
    if (!(cr0 & 4)) goto L_800fbe64;
    r9 = D(0x80450000u);
    r31 = 0x0u;
    r30 = D(0x8044a5d4u);
L_800fbf04:
    r9 = D(0x803a0000u);
    r5 = r31;
    r3 = r1 + 8;
    r4 = D(0x803980ccu);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r31 = r31 + 1;
    r0 = L32(r1 + 8);
    r4 = r30;
    r3 = r17;
    r30 = r30 + 4;
    S32(r1 + 40, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPU(r31, 0x3u);
    if (!(cr0 & 4)) goto L_800fbf04;
    r3 = r23;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r23;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 120;
    return r3;
}

// 0x800fc1b0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc1b0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 124);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc1f0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc1f0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 132);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc230 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc230(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 136);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc270 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc270(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 140);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc2b0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc2b0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 148);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc2f0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc2f0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 144);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc330 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc330(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 152);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc370 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc370(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 160);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc668 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc668(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r3 = L32(r9 + 100);
    r11 = L32(r3);
    r0 = L32(r11 + 112);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fc69c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fc69c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 116);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fcea0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fcea0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = 0xffffffffu;
    r4 = 0x3cu;
    r3 = CU(A800fcec8, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fd488 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fd488(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b1788u));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 100);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 172);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x800fd5f4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800fd5f4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r11 = L32(D(0x804b1788u));
    r4 = r3;
    r3 = L32(r11 + 100);
    r9 = L32(r3);
    r0 = L32(r9 + 184);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80100c4c FUN_80100c4c no verificada: desde bytes PPC
// Llama a assign__20d24d_String_803426b8PCc, text_default, sscanf, apply_item, source_document_name. Usa las cadenas "break %d", "b %d", "line not found in file %s, c".
// aviso: lee r3 tras void 80341588 en 80101000
__attribute__((weak)) w3d_u32 A80100c4c(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[320];
    w3d_u32 r1 = h2g(frame) + 304;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 304; S32(t_, r1); r1 = t_; }
    r29 = r4;
    r31 = r3;
    r0 = L8(r29);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80100c74;
    r29 = L32(r31 + 360);
L_80100c74:
    r4 = r29;
    r3 = r31 + 360;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r3 = r1 + 264;
    r28 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r30 = r1 + 280;
    r4 = D(0x803a0000u);
    r3 = r29;
    r4 = D(0x803988c4u);
    r5 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A802ec334)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    cr0 = CMPS(r3, 1);
    if ((cr0 & 2)) goto L_80100cd0;
    r4 = D(0x803a0000u);
    r3 = r29;
    r4 = D(0x803988d0u);
    r5 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A802ec334)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    cr0 = CMPS(r3, 1);
    if (!(cr0 & 2)) goto L_80100d6c;
L_80100cd0:
    r4 = L32(r1 + 280);
    r3 = r31;
    r5 = 0x1u;
    r4 = r4 - 1;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80102968)(W(r3), W(r4), W(r5));
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 8)) goto L_80100d28;
    r30 = r1 + 272;
    r4 = L32(r31 + 40);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800ffcdc)(W(r3), W(r4));
    r5 = L32(r1 + 272);
    r4 = D(0x803a0000u);
    r3 = r28;
    r4 = D(0x803988d8u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_80100f6c;
L_80100d28:
    r30 = r1 + 272;
    r4 = L32(r31 + 40);
    r29 = L32(r1 + 280);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800ffcdc)(W(r3), W(r4));
    r6 = L32(r1 + 272);
    r4 = D(0x803a0000u);
    r3 = r28;
    r4 = D(0x80398904u);
    r5 = r29;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_80100f6c;
L_80100d6c:
    r4 = D(0x803a0000u);
    r3 = r29;
    r4 = D(0x8039892cu);
    r5 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A802ec334)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    cr0 = CMPS(r3, 1);
    if ((cr0 & 2)) goto L_80100dac;
    r4 = D(0x803a0000u);
    r5 = r30;
    r4 = D(0x80398938u);
    r3 = r29;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A802ec334)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    cr0 = CMPS(r3, 1);
    if (!(cr0 & 2)) goto L_80100e48;
L_80100dac:
    r4 = L32(r1 + 280);
    r3 = r31;
    r5 = 0x0u;
    r4 = r4 - 1;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80102968)(W(r3), W(r4), W(r5));
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 8)) goto L_80100e04;
    r30 = r1 + 272;
    r4 = L32(r31 + 40);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800ffcdc)(W(r3), W(r4));
    r5 = L32(r1 + 272);
    r4 = D(0x803a0000u);
    r3 = r28;
    r4 = D(0x803988d8u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_80100f6c;
L_80100e04:
    r30 = r1 + 272;
    r4 = L32(r31 + 40);
    r29 = L32(r1 + 280);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800ffcdc)(W(r3), W(r4));
    r6 = L32(r1 + 272);
    r4 = D(0x803a0000u);
    r3 = r28;
    r4 = D(0x80398940u);
    r5 = r29;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_80100f6c;
L_80100e48:
    r3 = D(0x803a0000u);
    r4 = r29;
    r3 = D(0x8039896cu);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80100e78;
    r3 = D(0x803a0000u);
    r4 = r29;
    r3 = D(0x80398974u);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80100e88;
L_80100e78:
    r3 = r31;
    r4 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg))A8010272c)(W(r3), W(r4));
    goto L_80100ff4;
L_80100e88:
    r3 = D(0x803a0000u);
    r4 = r29;
    r3 = D(0x80398978u);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80100eb8;
    r3 = D(0x803a0000u);
    r4 = r29;
    r3 = D(0x80398984u);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80100edc;
L_80100eb8:
    r4 = D(0x803a0000u);
    r3 = r31;
    r4 = D(0x80398988u);
    r5 = 0x9u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A801022b0)(W(r3), W(r4), W(r5));
    r3 = r31;
    r4 = 0x1u;
    ((void (*)(w3d_oarg, w3d_oarg))A8010272c)(W(r3), W(r4));
    goto L_80100ff4;
L_80100edc:
    r4 = D(0x803a0000u);
    r3 = r29;
    r4 = D(0x80398998u);
    r5 = r1 + 8;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A802ec334)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    cr0 = CMPS(r3, 1);
    if ((cr0 & 2)) goto L_80100f1c;
    r4 = D(0x803a0000u);
    r3 = r29;
    r4 = D(0x803989a0u);
    r5 = r1 + 8;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A802ec334)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    cr0 = CMPS(r3, 1);
    if (!(cr0 & 2)) goto L_80100f80;
L_80100f1c:
    r0 = 0x0u;
    r3 = r31;
    S32(r1 + 284, r0);
    r4 = r1 + 8;
    r5 = r1 + 284;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80102a34)(W(r3), W(r4), W(r5));
    r0 = L32(r1 + 284);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80100f50;
    r4 = D(0x803a0000u);
    r3 = r31;
    r4 = D(0x803989a8u);
    goto L_80100f74;
L_80100f50:
    r4 = D(0x803a0000u);
    r3 = r28;
    r4 = D(0x803989d0u);
    r5 = r1 + 8;
    S32(r31 + 40, r0);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
L_80100f6c:
    r4 = L32(r1 + 264);
    r3 = r31;
L_80100f74:
    r5 = 0x9u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A801022b0)(W(r3), W(r4), W(r5));
    goto L_80100ff4;
L_80100f80:
    r3 = L32(D(0x804aaf88u));
    r4 = D(0x803a0000u);
    r4 = D(0x803989ecu);
    r5 = 0x9u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802cbe9c)(W(r3), W(r4), W(r5));
    r3 = L32(r31 + 68);
    r6 = 0x0u;
    r4 = 0x0u;
    r5 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802ceb4c)(W(r3), W(r4), W(r5), W(r6));
    r30 = L32(r31 + 68);
    r3 = r29;
    r3 = CU(A802ef9c0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = r3;
    r6 = D(0x803a0000u);
    r3 = r30;
    r4 = r29;
    r6 = D(0x80398a00u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802ddbd8)(W(r3), W(r4), W(r5), W(r6));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80100fdc;
    r3 = L32(r31 + 68);
    r3 = A80102004(r3);
L_80100fdc:
    r4 = 0x80100000u;
    r3 = L32(r31 + 68);
    r4 = FN(0x80101dd4u);
    r5 = 0x4u;
    r6 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802ceb4c)(W(r3), W(r4), W(r5), W(r6));
L_80100ff4:
    r3 = r1 + 264;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 264;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 304;
    return r3;
}

// 0x80102004 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80102004(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80101018)(W(r3));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80102028)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x80104768 FUN_80104768 no verificada: desde bytes PPC
// Llama a base_construct, service_forward. Hace 5 llamadas virtuales.
__attribute__((weak)) w3d_u32 A80104768(w3d_u32 r3) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, ctr = 0, lr = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8015fef0)(W(r3));
    r9 = D(0x80410000u);
    r0 = 0x0u;
    r9 = D(0x80410690u);
    r11 = r30 + 28;
    S32(r30, r9);
    r9 = 0x1u;
L_80104798:
    S32(r11, r0);
    cr0 = CMPS(r9, 0);
    r11 = r11 + 4;
    r9 = r9 - 1;
    if (!(cr0 & 2)) goto L_80104798;
    r9 = r30 + 36;
    r11 = 0x1u;
    r10 = r30 + 80;
    r0 = 0x0u;
L_801047bc:
    S32(r9, r0);
    cr0 = CMPS(r11, 0);
    r9 = r9 + 4;
    r11 = r11 - 1;
    if (!(cr0 & 2)) goto L_801047bc;
    r9 = D(0x803a0000u);
    r11 = D(0x803a0000u);
    f0 = LF(D(0x804aafacu));
    r0 = 0x0u;
    f13 = LF(D(0x80399808u));
    f12 = LF(D(0x8039980cu));
    f0 = -f0;
    S32(r30 + 560, r0);
    r11 = D(0x80450000u);
    S32(r30 + 44, r0);
    r9 = D(0x8044b688u);
    S32(r30 + 48, r0);
    S32(r30 + 52, r0);
    SF(D(0x8044b688u), f13);
    r11 = 0x1eu;
    SF(D(0x8044b690u), f0);
    SF(D(0x8044b68cu), f12);
    ctr = r11;
    S32(D(0x804aafa4u), r30);
L_8010481c:
    S32(r10, r0);
    r10 = r10 + 16;
    --ctr; if (ctr != 0) goto L_8010481c;
    r29 = 0x0u;
    r28 = 0x0u;
    r31 = r30 + 36;
L_80104834:
    r3 = L32(r31 - 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80104850;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80104850:
    r3 = L32(r31);
    S32(r31 - 8, r28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80104870;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80104870:
    S32(r31, r28);
    r29 = r29 + 1;
    r31 = r31 + 4;
    cr0 = CMPU(r29, 0x1u);
    if (!(cr0 & 4)) goto L_80104834;
    r3 = L32(r30 + 44);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801048a0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801048a0:
    r0 = 0x0u;
    S32(r30 + 44, r0);
    r9 = L32(D(0x804af1e8u));
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_80104964;
    r3 = D(0x80410000u);
    r3 = D(0x80415bb0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    r31 = r3; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_801048dc;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801048dc:
    r3 = L32(D(0x804af1e8u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801048f8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801048f8:
    S32(D(0x804af1e8u), r31);
    r0 = 0x4u;
    S32(r31 + 28, r0);
    r10 = r31 + 4;
    r9 = D(0x803a0000u);
    r0 = L8(r10 + 4);
    f0 = LF(D(0x80399810u));
    r0 = r0 | 0x2u;
    S8(r10 + 4, r0);
    r0 = 0x1u;
    r11 = L32(D(0x804af1e8u));
    S32(r11 + 32, r0);
    r11 = r11 + 4;
    r0 = L8(r11 + 4);
    r0 = r0 | 0x2u;
    S8(r11 + 4, r0);
    r9 = L32(D(0x804af1e8u));
    r9 = r9 + 4;
    r0 = L8(r9 + 4);
    r0 = r0 | 0x1u;
    S8(r9 + 4, r0);
    r11 = L32(D(0x804af1e8u));
    SF(r11 + 24, f0);
    r11 = r11 + 4;
    r0 = L8(r11 + 4);
    r0 = r0 | 0x2u;
    S8(r11 + 4, r0);
L_80104964:
    r0 = 0x0u;
    r3 = r30;
    S32(r30 + 64, r0);
    r1 = r1 + 24;
    return r3;
}

// 0x80107a90 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 800e58fc en 80107aa4
__attribute__((weak)) w3d_u32 A80107a90(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(D(0x804aaeccu));
    r4 = 0x0u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800e58fc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x80108224 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 800a8d00 en 80108230
__attribute__((weak)) w3d_u32 A80108224(w3d_u32 r3, w3d_u32 r4, float s1) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, float))A800a8d00)(W(r3), W(r4), (float)f1);
    r1 = r1 + 8;
    return r3;
}

// 0x80109bec FUN_80109bec no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: flush. Llama a settings_read_int, text_default, text_format, resource_property, resource_identity. Hace 13 llamadas virtuales. Usa las cadenas "ActiveWormIndex", "GameStats.Worm%.2d".
// aviso: lee r3 tras void 80178474 en 8010a004
__attribute__((weak)) w3d_u32 A80109bec(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[136];
    w3d_u32 r1 = h2g(frame) + 120;
    w3d_u32 r0 = 0, r11 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 120; S32(t_, r1); r1 = t_; }
    r9 = D(0x803a0000u);
    r31 = r3;
    r9 = D(0x80399cd8u);
    r3 = r1 + 72;
    S32(r1 + 72, r9);
    r4 = r1 + 76;
    r3 = A800fc1f0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r1 + 76);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 8)) goto L_8010a008;
    r29 = 0x0u;
    r0 = 0x0u;
    r27 = r1 + 8;
    S32(r1 + 8, r29);
    r0 = 0xe3a8u;
    r30 = r1 + 24;
    S32(r27 + 4, r0);
    r3 = r30;
    S32(r1 + 16, r29);
    r24 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r25 = D(0x803a0000u);
    r5 = L32(r1 + 76);
    r4 = D(0x803a0000u);
    r28 = r1 + 16;
    r4 = D(0x80399ce8u);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 24);
    r4 = r28;
    r3 = r1 + 80;
    S32(r1 + 80, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 16);
    S32(r1 + 32, r29);
    ((void (*)())A80341584)();
    r4 = r27;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80179598)(W(r3), W(r4));
    S32(r1 + 40, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109cb4;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109cb4:
    r30 = L32(r1 + 40);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80109cf4;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109cf0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109cf0:
    S32(r1 + 32, r30);
L_80109cf4:
    r3 = L32(r1 + 40);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109d10;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109d10:
    r3 = L32(r1 + 76);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r3 = L8(r3 + 213);
    cr0 = CMPU(r3, 0x3u);
    if ((cr0 & 4)) goto L_80109d40;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc7f8)(W(r3));
    r0 = L32(r3 + 44);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80109d40;
    r9 = L32(r31 + 104);
    r9 = r9 + 9;
    S32(r31 + 104, r9);
L_80109d40:
    r9 = L32(r1 + 32);
    r30 = L32(r9 + 48);
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r9 = L32(r3 + 52);
    r0 = L32(r31 + 116);
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80109d64;
    r0 = r9 - r0;
    r30 = r30 + r0;
L_80109d64:
    r9 = L32(r1 + 32);
    S32(r9 + 48, r30);
    r11 = L32(r1 + 32);
    r0 = L32(r31 + 112);
    r10 = L32(r11 + 56);
    r0 = r10 + r0;
    S32(r11 + 56, r0);
    r9 = L32(r1 + 32);
    r0 = L32(r31 + 104);
    S32(r9 + 40, r0);
    r11 = L32(r1 + 32);
    r0 = L32(r31 + 108);
    S32(r11 + 44, r0);
    r9 = L32(r31 + 84);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_80109dc4;
    r0 = L32(r31 + 88);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80109dc4;
    r11 = L32(r1 + 32);
    r9 = L32(r11 + 52);
    r9 = r9 + 1;
    S32(r11 + 52, r9);
    goto L_80109df8;
L_80109dc4:
    r10 = L32(r1 + 32);
    r9 = L32(r31 + 84);
    r0 = L32(r31 + 88);
    r11 = L32(r10 + 20);
    r9 = r9 + r0;
    cr0 = CMPU(r9, r11);
    if (!(cr0 & 4)) goto L_80109de4;
    S32(r10 + 20, r9);
L_80109de4:
    r9 = L32(r1 + 32);
    r0 = L32(r31 + 84);
    r11 = L32(r9 + 60);
    r0 = r11 + r0;
    S32(r9 + 60, r0);
L_80109df8:
    r9 = L32(r1 + 32);
    r0 = L32(r31 + 100);
    r10 = L32(r9 + 32);
    r0 = r10 + r0;
    S32(r9 + 32, r0);
    r11 = L32(r1 + 32);
    r0 = L32(r31 + 92);
    r10 = L32(r11 + 64);
    r0 = r10 + r0;
    S32(r11 + 64, r0);
    r9 = L32(r1 + 32);
    r0 = L32(r31 + 96);
    r10 = L32(r9 + 36);
    r0 = r10 + r0;
    S32(r9 + 36, r0);
    r9 = L32(r1 + 32);
    r3 = L32(r31 + 92);
    r10 = L32(r9 + 24);
    cr0 = CMPU(r3, r10);
    if (!(cr0 & 4)) goto L_80109e4c;
    S32(r9 + 24, r3);
L_80109e4c:
    r3 = L32(r1 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109e68;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109e68:
    r0 = 0x0u;
    r29 = 0x0u;
    S32(r1 + 32, r0);
    r31 = r1 + 48;
    r28 = 0x0u;
    r26 = r1 + 40;
L_80109e80:
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r0 = L32(r3 + 220);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80109fa8;
    r0 = 0x0u;
    S32(r1 + 48, r28);
    r0 = 0xe3a8u;
    r5 = r29;
    S32(r31 + 4, r0);
    r3 = r24;
    S32(r1 + 40, r28);
    r4 = D(0x80399ce8u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r27 = r31;
    r0 = L32(r1 + 24);
    r4 = r26;
    r3 = r1 + 84;
    S32(r1 + 84, r0);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 40);
    S32(r1 + 56, r28);
    ((void (*)())A80341584)();
    r4 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80179598)(W(r3), W(r4));
    S32(r1 + 64, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109f04;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109f04:
    r30 = L32(r1 + 64);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80109f44;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 56);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109f40;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109f40:
    S32(r1 + 56, r30);
L_80109f44:
    r3 = L32(r1 + 64);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109f60;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109f60:
    r9 = L32(r1 + 56);
    r3 = r9;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109f80;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109f80:
    r3 = L32(r1 + 40);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109f9c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109f9c:
    r3 = r27;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
L_80109fa8:
    r29 = r29 + 1;
    cr0 = CMPU(r29, 0xfu);
    if (!(cr0 & 4)) goto L_80109e80;
    r3 = L32(r1 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109fd0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109fd0:
    r3 = r1 + 24;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 24;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80109ffc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80109ffc:
    r3 = r1 + 8;
    r4 = 0x2u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
L_8010a008:
    r1 = r1 + 120;
    return r3;
}

// 0x80118268 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 800d7788 en 80118274
__attribute__((weak)) w3d_u32 A80118268(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A800d7788)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x8011a1c8 FUN_8011a1c8 no verificada: desde bytes PPC
// Llama a string_from_text, handle_load_node, mesh_identity, large_reserve_string_finish, large_reserve_string_release. Hace 5 llamadas virtuales. Usa las cadenas "FE.Font", "Text.2DBacking".
// aviso: lee r3 tras void 80341588 en 8011a2ec
__attribute__((weak)) w3d_u32 A8011a1c8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r30 = 0x0u;
    r3 = L32(r31 + 28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8011a1fc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8011a1fc:
    r3 = L32(r31 + 32);
    r28 = r31 + 32;
    S32(r31 + 28, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8011a220;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8011a220:
    S32(r31 + 32, r30);
    r4 = D(0x803a0000u);
    r3 = r1 + 8;
    r4 = D(0x8039adb4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r0 = 0x0u;
    r29 = r1 + 8;
    S32(r1 + 16, r0);
    r4 = r1 + 16;
    r5 = 0x3au;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 16);
    ((void (*)())A80343580)();
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_8011a274;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8011a274:
    r3 = L32(r31 + 28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8011a290;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8011a290:
    r3 = L32(r1 + 16);
    S32(r31 + 28, r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8011a2b0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8011a2b0:
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r29;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r4 = D(0x803a0000u);
    r3 = r29;
    r4 = D(0x8039adbcu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r4 = r28;
    r5 = 0x38u;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r29;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 40;
    return r3;
}

}
