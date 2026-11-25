// Funciones del juego sin fuente admitida: 0x802ea738 a 0x803580f8. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A801651e4();
__attribute__((weak)) void A80165254();
__attribute__((weak)) void A801a2350();
__attribute__((weak)) void A801a2b64();
__attribute__((weak)) void A801ede8c();
__attribute__((weak)) void A801f29d0();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A802e87d4();
__attribute__((weak)) void A802e8c1c();
__attribute__((weak)) void A802eeef4();
__attribute__((weak)) void A803413d8();
__attribute__((weak)) void A8034a400();
__attribute__((weak)) void A8034a7fc();
__attribute__((weak)) void A8034b3f8();
__attribute__((weak)) void A8034b408();

// 0x802ea738 FUN_802ea738 no verificada: desde bytes PPC
// Igual que 0x802e9eac en la variante flotante; solo lo llama 0x802e9de4, de la zona libm.
__attribute__((weak)) w3d_u32 A802ea738(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[432];
    w3d_u32 r1 = h2g(frame) + 416;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, ctr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 416; S32(t_, r1); r1 = t_; }
    r12 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    S32(r1 + 348, r12);
    r9 = r5 - 3;
    r18 = r7;
    { w3d_u32 t_ = r9; r0 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r11 = D(0x804b2720u);
    r0 = r0 >> 29;
    r10 = r18 << 2;
    r9 = r9 + r0;
    r27 = L32(r11 + r10);
    { w3d_u32 t_ = r9; r9 = (w3d_u32)((w3d_s32)t_ >> 3); ca = SRAWCA(t_, 3); }
    r29 = r6 - 1;
    r0 = ~(r9 | r9);
    r11 = r29 + r27; cr0 = CMPS(r11, 0);
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r20 = r3;
    r21 = r9 & r0;
    r26 = r4;
    r0 = r21 + 1;
    r6 = r21 - r29;
    r0 = r0 << 3;
    r19 = r8;
    ctr = r6;
    r22 = r1 + 248;
    r28 = r5 - r0;
    r30 = r1 + 8;
    if ((cr0 & 8)) goto L_802ea824;
    r0 = r6 << 2;
    r8 = r11 + 1;
    f13 = LD(D(0x804ac548u));
    r10 = r0 + r19;
    f12 = LF(D(0x804ac550u));
    r7 = 0x43300000u;
    r11 = r1 + 88;
L_802ea7d4:
    r9 = ctr;
    cr0 = CMPS(r9, 0);
    if ((cr0 & 8)) goto L_802ea804;
    r0 = L32(r10);
    r0 = r0 ^ 0x80000000u;
    S32(r1 + 340, r0);
    S32(r1 + 336, r7);
    f0 = LDS(r1 + 336);
    f0 = f0 - f13;
    f0 = (float)f0;
    SF(r11, f0);
    goto L_802ea808;
L_802ea804:
    SF(r11, f12);
L_802ea808:
    r6 = ctr;
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    r6 = r6 + 1;
    r11 = r11 + 4;
    r10 = r10 + 4;
    ctr = r6;
    if (!(cr0 & 2)) goto L_802ea7d4;
L_802ea824:
    r8 = 0x0u;
    cr4 = CMPS(r28, 0);
    cr0 = CMPS(r8, r27);
    cr3 = CMPS(r18, 2);
    if ((cr0 & 4)) goto L_802ea898;
    f12 = LF(D(0x804ac550u));
    r10 = r22;
L_802ea840:
    cr0 = CMPS(r29, 0);
    f1 = f12;
    r6 = r8 << 2;
    r5 = r8 + 1;
    if ((cr0 & 8)) goto L_802ea888;
    r0 = r29 + r8;
    r9 = r1 + 88;
    r0 = r0 << 2;
    r11 = r20;
    r9 = r0 + r9;
    r0 = r29 + 1;
    ctr = r0;
L_802ea870:
    f13 = LF(r11);
    f0 = LF(r9);
    r11 = r11 + 4;
    r9 = r9 - 4;
    f1 = __builtin_fmaf((float)f13, (float)f0, (float)f1);
    --ctr; if (ctr != 0) goto L_802ea870;
L_802ea888:
    r8 = r5;
    SF(r10 + r6, f1);
    cr0 = CMPS(r8, r27);
    if (!(cr0 & 4)) goto L_802ea840;
L_802ea898:
    r31 = r27;
L_802ea89c:
    cr0 = CMPS(r31, 0);
    r0 = r31 << 2;
    r23 = r0;
    ctr = r31;
    f31 = LF(r22 + r0);
    if (!(cr0 & 4)) goto L_802ea938;
    r0 = r23 - 4;
    f9 = LF(D(0x804ac554u));
    r7 = r0 + r22;
    f11 = LD(D(0x804ac548u));
    f10 = LF(D(0x804ac558u));
    r0 = 0x43300000u;
    r8 = r30;
L_802ea8d0:
    f0 = (float)(f31 * f9);
    r11 = r9;
    r10 = r9;
    r6 = ctr;
    { w3d_u32 t_ = r6; r6 = t_ + (w3d_u32)-1; ca = r6 < t_; cr0 = CMPS(r6, 0); }
    f13 = FCTIWZ(f0);
    ctr = r6;
    SDS(r1 + 336, f13);
    r9 = L32(r1 + 340);
    r9 = r9 ^ 0x80000000u;
    S32(r1 + 340, r9);
    S32(r1 + 336, r0);
    f0 = LDS(r1 + 336);
    f0 = f0 - f11;
    f1 = (float)f0;
    f13 = (float)(f1 * f10);
    f13 = (float)(f31 - f13);
    f12 = FCTIWZ(f13);
    SDS(r1 + 336, f12);
    r10 = L32(r1 + 340);
    S32(r8, r10);
    r8 = r8 + 4;
    f0 = LF(r7);
    r7 = r7 - 4;
    f31 = (float)(f0 + f1);
    if ((cr0 & 4)) goto L_802ea8d0;
L_802ea938:
    f1 = f31;
    r3 = r28;
    f1 = ((float (*)(float, w3d_oarg))A802e8c1c)((float)f1, W(r3));
    f31 = f1;
    f1 = LF(D(0x804ac55cu));
    f1 = (float)(f31 * f1);
    f1 = ((float (*)(float))A802e87d4)((float)f1);
    f0 = LF(D(0x804ac560u));
    r9 = r11;
    r10 = 0x43300000u;
    f1 = (float)(f1 * f0);
    f12 = LD(D(0x804ac548u));
    r8 = 0x0u;
    f31 = (float)(f31 - f1);
    f0 = f31;
    f13 = FCTIWZ(f0);
    SDS(r1 + 336, f13);
    r24 = L32(r1 + 340);
    r0 = r24 ^ 0x80000000u;
    S32(r1 + 340, r0);
    S32(r1 + 336, r10);
    f0 = LDS(r1 + 336);
    f0 = f0 - f12;
    f0 = (float)f0;
    f31 = (float)(f31 - f0);
    if (!(cr4 & 4)) goto L_802ea9d0;
    r11 = r31 - 1;
    { w3d_u32 t_ = r28; r9 = (w3d_u32)8 - t_; ca = ((w3d_u32)8 >= t_); }
    r11 = r11 << 2;
    { w3d_u32 t_ = r28; r10 = (w3d_u32)7 - t_; ca = ((w3d_u32)7 >= t_); }
    r0 = L32(r30 + r11);
    { w3d_u32 t_ = r0, n_ = r9; r8 = SRAW(t_, n_); ca = SRAWCA(t_, n_); }
    r9 = SLW(r8, r9);
    r24 = r24 + r8;
    r0 = r0 - r9;
    { w3d_u32 t_ = r0, n_ = r10; r8 = SRAW(t_, n_); ca = SRAWCA(t_, n_); }
    S32(r30 + r11, r0);
    goto L_802ea9fc;
L_802ea9d0:
    if (!(cr4 & 2)) goto L_802ea9e8;
    r0 = r31 - 1;
    r0 = r0 << 2;
    r9 = L32(r30 + r0);
    { w3d_u32 t_ = r9; r8 = (w3d_u32)((w3d_s32)t_ >> 8); ca = SRAWCA(t_, 8); }
    goto L_802ea9fc;
L_802ea9e8:
    f0 = LF(D(0x804ac564u));
    cr0 = CMPF(f31, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802ea9fc;
    r8 = 0x2u;
L_802ea9fc:
    cr0 = CMPS(r8, 0);
    r25 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    if (!(cr0 & 4)) goto L_802eaac4;
    cr0 = CMPS(r31, 0);
    r24 = r24 + 1;
    cr7 = CMPS(r8, 2);
    r10 = 0x0u;
    if (!(cr0 & 4)) goto L_802eaa64;
    r11 = r30;
    r9 = 0x0u;
    r8 = r31;
L_802eaa28:
    r0 = L32(r9 + r11);
    cr0 = CMPS(r10, 0);
    ctr = r0;
    if (!(cr0 & 2)) goto L_802eaa4c;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802eaa58;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)256 - t_; ca = ((w3d_u32)256 >= t_); }
    r10 = 0x1u;
    goto L_802eaa54;
L_802eaa4c:
    r6 = ctr;
    { w3d_u32 t_ = r6; r0 = (w3d_u32)255 - t_; ca = ((w3d_u32)255 >= t_); }
L_802eaa54:
    S32(r9 + r30, r0);
L_802eaa58:
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    r9 = r9 + 4;
    if (!(cr0 & 2)) goto L_802eaa28;
L_802eaa64:
    if (!(cr4 & 4)) goto L_802eaaa4;
    cr0 = CMPS(r28, 1);
    if ((cr0 & 2)) goto L_802eaa7c;
    cr0 = CMPS(r28, 2);
    if ((cr0 & 2)) goto L_802eaa90;
    goto L_802eaaa4;
L_802eaa7c:
    r9 = r31 - 1;
    r9 = r9 << 2;
    r0 = L32(r30 + r9);
    r0 = r0 & 0x7fu;
    goto L_802eaaa0;
L_802eaa90:
    r9 = r31 - 1;
    r9 = r9 << 2;
    r0 = L32(r30 + r9);
    r0 = r0 & 0x3fu;
L_802eaaa0:
    S32(r30 + r9, r0);
L_802eaaa4:
    if (!(cr7 & 2)) goto L_802eaac4;
    f1 = LF(D(0x804ac568u));
    cr0 = CMPS(r10, 0);
    f31 = (float)(f1 - f31);
    if ((cr0 & 2)) goto L_802eaac4;
    r3 = r28;
    f1 = ((float (*)(float, w3d_oarg))A802e8c1c)((float)f1, W(r3));
    f31 = (float)(f31 - f1);
L_802eaac4:
    f0 = LF(D(0x804ac550u));
    cr0 = CMPF(f31, f0);
    f13 = f0;
    if (!(cr0 & 2)) goto L_802eac08;
    r8 = r31 - 1;
    r0 = 0x0u;
    cr0 = CMPS(r8, r27);
    ctr = r0;
    if ((cr0 & 8)) goto L_802eab10;
    r0 = r8 << 2;
    r9 = r0 + r30;
L_802eaaf0:
    r0 = L32(r9);
    r8 = r8 - 1;
    r6 = ctr;
    cr0 = CMPS(r8, r27);
    r6 = r6 | r0;
    r9 = r9 - 4;
    ctr = r6;
    if (!(cr0 & 8)) goto L_802eaaf0;
L_802eab10:
    r7 = ctr;
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_802eac08;
    r0 = r27 - 1;
    r7 = 0x1u;
    r0 = r0 << 2;
    r11 = r31 + 1;
    r9 = L32(r30 + r0);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_802eab54;
    r9 = r27 << 2;
    r9 = r9 + r30;
    r9 = r9 - 4;
L_802eab44:
    { w3d_u32 t_ = r9 - 4; r0 = L32(t_); r9 = t_; }
    r7 = r7 + 1;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802eab44;
L_802eab54:
    r0 = r31 + r7;
    r8 = r11;
    cr0 = CMPS(r8, r0);
    r7 = r0;
    if ((cr0 & 4)) goto L_802eac00;
    r4 = r1 + 88;
    f12 = LD(D(0x804ac548u));
    f11 = LF(D(0x804ac550u));
    r25 = r4;
    r31 = 0x43300000u;
    r12 = r22;
    r3 = r7;
L_802eab84:
    r0 = r21 + r8;
    r0 = r0 << 2;
    r9 = r29 + r8;
    r11 = L32(r19 + r0);
    cr0 = CMPS(r29, 0);
    r9 = r9 << 2;
    r5 = r8 + 1;
    r11 = r11 ^ 0x80000000u;
    f1 = f11;
    S32(r1 + 340, r11);
    r6 = r8 << 2;
    S32(r1 + 336, r31);
    f0 = LDS(r1 + 336);
    f0 = f0 - f12;
    f0 = (float)f0;
    SF(r4 + r9, f0);
    if ((cr0 & 8)) goto L_802eabf0;
    r10 = r29 + 1;
    r9 = r9 + r25;
    ctr = r10;
    r11 = r20;
L_802eabd8:
    f13 = LF(r11);
    f0 = LF(r9);
    r11 = r11 + 4;
    r9 = r9 - 4;
    f1 = __builtin_fmaf((float)f13, (float)f0, (float)f1);
    --ctr; if (ctr != 0) goto L_802eabd8;
L_802eabf0:
    r8 = r5;
    SF(r12 + r6, f1);
    cr0 = CMPS(r8, r3);
    if (!(cr0 & 4)) goto L_802eab84;
L_802eac00:
    r31 = r7;
    goto L_802ea89c;
L_802eac08:
    cr0 = CMPF(f31, f13);
    if (!(cr0 & 2)) goto L_802eac44;
    r31 = r31 - 1;
    r28 = r28 - 8;
    r9 = r31 << 2;
    r0 = L32(r30 + r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802eacf4;
    r9 = r9 + r30;
L_802eac2c:
    { w3d_u32 t_ = r9 - 4; r0 = L32(t_); r9 = t_; }
    r31 = r31 - 1;
    r28 = r28 - 8;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802eac2c;
    goto L_802eacf4;
L_802eac44:
    f1 = f31;
    r3 = 0u - r28;
    f1 = ((float (*)(float, w3d_oarg))A802e8c1c)((float)f1, W(r3));
    f31 = f1;
    f9 = LF(D(0x804ac558u));
    cr0 = CMPF(f31, f9);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802eace0;
    f0 = LF(D(0x804ac554u));
    r11 = r9;
    r8 = r9;
    f0 = (float)(f31 * f0);
    r10 = r9;
    r0 = 0x43300000u;
    f10 = LD(D(0x804ac548u));
    r31 = r31 + 1;
    r28 = r28 + 8;
    r7 = r31 << 2;
    f13 = FCTIWZ(f0);
    SDS(r1 + 336, f13);
    r9 = L32(r1 + 340);
    r9 = r9 ^ 0x80000000u;
    S32(r1 + 340, r9);
    S32(r1 + 336, r0);
    f0 = LDS(r1 + 336);
    f0 = f0 - f10;
    f1 = (float)f0;
    f13 = (float)(f1 * f9);
    f0 = f1;
    f13 = (float)(f31 - f13);
    f11 = FCTIWZ(f0);
    f12 = FCTIWZ(f13);
    SDS(r1 + 336, f12);
    r8 = L32(r1 + 340);
    SDS(r1 + 336, f11);
    S32(r30 + r23, r8);
    r10 = L32(r1 + 340);
    S32(r30 + r7, r10);
    goto L_802eacf4;
L_802eace0:
    f0 = f31;
    f13 = FCTIWZ(f0);
    SDS(r1 + 336, f13);
    r9 = L32(r1 + 340);
    S32(r30 + r23, r9);
L_802eacf4:
    f1 = LF(D(0x804ac568u));
    r3 = r28;
    f1 = ((float (*)(float, w3d_oarg))A802e8c1c)((float)f1, W(r3));
    r8 = r31; cr0 = CMPS(r8, 0);
    if ((cr0 & 8)) goto L_802ead54;
    f13 = LD(D(0x804ac548u));
    r7 = r30;
    f12 = LF(D(0x804ac554u));
    r10 = r22;
    r6 = 0x43300000u;
    r11 = r8 << 2;
L_802ead20:
    r0 = L32(r11 + r7);
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    r0 = r0 ^ 0x80000000u;
    S32(r1 + 340, r0);
    S32(r1 + 336, r6);
    f0 = LDS(r1 + 336);
    f0 = f0 - f13;
    f0 = (float)f0;
    f0 = (float)(f1 * f0);
    f1 = (float)(f1 * f12);
    SF(r11 + r10, f0);
    r11 = r11 - 4;
    if (!(cr0 & 8)) goto L_802ead20;
L_802ead54:
    r8 = r31; cr0 = CMPS(r8, 0);
    if ((cr0 & 8)) goto L_802eadcc;
    r3 = r22;
L_802ead60:
    r7 = 0x0u;
    f1 = LF(D(0x804ac550u));
    cr0 = CMPS(r7, r27);
    r4 = r8 - 1;
    r6 = r31 - r8;
    r11 = r1 + 168;
    if ((cr0 & 4)) goto L_802eadbc;
    cr0 = CMPS(r7, r6);
    r5 = r6;
    if ((cr0 & 4)) goto L_802eadbc;
    r0 = r8 << 2;
    r10 = D(0x804b272cu);
    r9 = r0 + r3;
L_802ead94:
    r7 = r7 + 1;
    f13 = LF(r10);
    f0 = LF(r9);
    cr0 = CMPS(r7, r27);
    r10 = r10 + 4;
    r9 = r9 + 4;
    f1 = __builtin_fmaf((float)f13, (float)f0, (float)f1);
    if ((cr0 & 4)) goto L_802eadbc;
    cr0 = CMPS(r7, r5);
    if (!(cr0 & 4)) goto L_802ead94;
L_802eadbc:
    r8 = r4; cr0 = CMPS(r8, 0);
    r0 = r6 << 2;
    SF(r11 + r0, f1);
    if (!(cr0 & 8)) goto L_802ead60;
L_802eadcc:
    if ((cr3 & 4)) goto L_802eade4;
    cr0 = CMPS(r18, 1);
    if (!(cr0 & 8)) goto L_802eae34;
    cr0 = CMPS(r18, 0);
    if ((cr0 & 2)) goto L_802eadf0;
    goto L_802eafa0;
L_802eade4:
    cr0 = CMPS(r18, 3);
    if ((cr0 & 2)) goto L_802eaeb4;
    goto L_802eafa0;
L_802eadf0:
    r8 = r31; cr0 = CMPS(r8, 0);
    f1 = LF(D(0x804ac550u));
    if ((cr0 & 8)) goto L_802eae1c;
    r9 = r1 + 168;
    r0 = r8 << 2;
    r9 = r9 + r0;
L_802eae08:
    f0 = LF(r9);
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    r9 = r9 - 4;
    f1 = (float)(f1 + f0);
    if (!(cr0 & 8)) goto L_802eae08;
L_802eae1c:
    SF(r26, f1);
    cr0 = (r25 >> 28) & 15;
    if ((cr0 & 2)) goto L_802eafa0;
    f0 = -f1;
    SF(r26, f0);
    goto L_802eafa0;
L_802eae34:
    r8 = r31; cr0 = CMPS(r8, 0);
    f1 = LF(D(0x804ac550u));
    if ((cr0 & 8)) goto L_802eae60;
    r9 = r1 + 168;
    r0 = r8 << 2;
    r9 = r9 + r0;
L_802eae4c:
    f0 = LF(r9);
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    r9 = r9 - 4;
    f1 = (float)(f1 + f0);
    if (!(cr0 & 8)) goto L_802eae4c;
L_802eae60:
    SF(r26, f1);
    cr0 = (r25 >> 28) & 15;
    if ((cr0 & 2)) goto L_802eae74;
    f0 = -f1;
    SF(r26, f0);
L_802eae74:
    f0 = LF(r1 + 168);
    cr0 = CMPS(r31, 0);
    f1 = (float)(f0 - f1);
    if (!(cr0 & 4)) goto L_802eaea0;
    r8 = r31;
    r9 = r1 + 172;
L_802eae8c:
    f0 = LF(r9);
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    r9 = r9 + 4;
    f1 = (float)(f1 + f0);
    if (!(cr0 & 2)) goto L_802eae8c;
L_802eaea0:
    SF(r26 + 4, f1);
    cr0 = (r25 >> 28) & 15;
    if ((cr0 & 2)) goto L_802eafa0;
    f0 = -f1;
    goto L_802eaf9c;
L_802eaeb4:
    r8 = r31; cr0 = CMPS(r8, 0);
    if (!(cr0 & 4)) goto L_802eaef0;
    r9 = r1 + 164;
    r0 = r8 << 2;
    r9 = r9 + r0;
L_802eaec8:
    f13 = LF(r9);
    { w3d_u32 t_ = r8; r8 = t_ + (w3d_u32)-1; ca = r8 < t_; cr0 = CMPS(r8, 0); }
    f0 = LF(r9 + 4);
    f1 = (float)(f13 + f0);
    f13 = (float)(f13 - f1);
    SF(r9, f1);
    f0 = (float)(f0 + f13);
    SF(r9 + 4, f0);
    r9 = r9 - 4;
    if ((cr0 & 4)) goto L_802eaec8;
L_802eaef0:
    r8 = r31;
    cr0 = CMPS(r8, 1);
    if (!(cr0 & 4)) goto L_802eaf34;
    r9 = r1 + 164;
    r0 = r8 << 2;
    r9 = r9 + r0;
L_802eaf08:
    f13 = LF(r9);
    r8 = r8 - 1;
    f0 = LF(r9 + 4);
    cr0 = CMPS(r8, 1);
    f1 = (float)(f13 + f0);
    f13 = (float)(f13 - f1);
    SF(r9, f1);
    f0 = (float)(f0 + f13);
    SF(r9 + 4, f0);
    r9 = r9 - 4;
    if ((cr0 & 4)) goto L_802eaf08;
L_802eaf34:
    r8 = r31;
    f1 = LF(D(0x804ac550u));
    cr0 = CMPS(r8, 1);
    f13 = LF(r1 + 168);
    if (!(cr0 & 4)) goto L_802eaf6c;
    r9 = r1 + 168;
    r0 = r8 << 2;
    r9 = r9 + r0;
L_802eaf54:
    r8 = r8 - 1;
    f0 = LF(r9);
    cr0 = CMPS(r8, 1);
    r9 = r9 - 4;
    f1 = (float)(f1 + f0);
    if ((cr0 & 4)) goto L_802eaf54;
L_802eaf6c:
    cr0 = (r25 >> 28) & 15;
    if (!(cr0 & 2)) goto L_802eaf84;
    f0 = LF(r1 + 172);
    SF(r26 + 8, f1);
    SF(r26, f13);
    goto L_802eaf9c;
L_802eaf84:
    f0 = LF(r1 + 172);
    f13 = -f13;
    f12 = -f1;
    f0 = -f0;
    SF(r26, f13);
    SF(r26 + 8, f12);
L_802eaf9c:
    SF(r26 + 4, f0);
L_802eafa0:
    r3 = r24 & 0x7u;
    r12 = L32(r1 + 348);
    cr3 = (r12 >> 16) & 15; cr4 = (r12 >> 12) & 15;
    r1 = r1 + 416;
    return r3;
}

// 0x802f3c6c FUN_802f3c6c no verificada: desde bytes PPC
// _exit de newlib: una palabra 0 seguida de blr; en el original salta a la trampa y no vuelve.
__attribute__((weak)) w3d_u32 A802f3c6c(w3d_u32 r3) {
    w3d_open_break(0x802f3c6cu);
    return r3;
}

// 0x802f4eb8 FUN_802f4eb8 no verificada: desde bytes PPC
// Guarda 0x80000000 y el valor de 0x80000038 en dos globales. El primero queda como constante cruda, sin traducir a memoria baja.
__attribute__((weak)) w3d_u32 A802f4eb8(void) {
    w3d_u32 r0 = 0, r3 = 0;
    w3d_u32 cr0 = 0;
    r3 = 0x80000000u;
    S32(D(0x804b10c0u), r3);
    r0 = L32(LOW(0x80000038u));
    S32(D(0x804b10c4u), r0);
    r3 = L32(D(0x804b10c4u));
    cr0 = CMPU(r3, 0x0u);
    if ((cr0 & 2)) return r3;
    r0 = L32(r3 + 8);
    S32(D(0x804b10ccu), r0);
    r0 = L32(D(0x804b10ccu));
    r0 = (w3d_s32)r0 * 12;
    r0 = r3 + r0;
    S32(D(0x804b10c8u), r0);
    return r3;
}

// 0x80343748 FUN_80343748 no verificada: desde bytes PPC
// Función de 11 instrucciones sin destinos con nombre ni cadenas.
__attribute__((weak)) w3d_u32 A80343748(w3d_u32 r3) {
    w3d_u32 r0 = 0, r10 = 0, r11 = 0;
    double f0 = 0;
    r0 = L32(r3);
    r10 = D(0x80370000u);
    f0 = LF(D(0x80373c20u));
    r11 = 0x0u;
    r0 = r0 & 0x1fffffu;
    S32(r3 + 16, r11);
    S32(r3, r0);
    SF(r3 + 4, f0);
    S32(r3 + 8, r11);
    S32(r3 + 12, r11);
    return r3;
}

// 0x8034af90 FUN_8034af90 no verificada: desde bytes PPC
// Llama a engine_get_context, pop_heap__H2ZP15D31sQueueRecordZ13, set_time, set_time2, sol35f7a_pool_allocate. Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A8034af90(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[104];
    w3d_u32 r1 = h2g(frame) + 88;
    w3d_u32 r0 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, ctr = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 88; S32(t_, r1); r1 = t_; }
    r25 = r3;
    r23 = r4;
    r24 = r5;
    r30 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    S32(r3 + 60, r30);
    goto L_8034b3c8;
L_8034afbc:
    cr0 = CMPU(r0, r23);
    r6 = 0x3u;
    r7 = 0xffffffffu;
    r8 = 0x0u;
    if (!(cr0 & 8)) goto L_8034b018;
    r10 = r25;
L_8034afd4:
    r9 = L32(r10);
    r10 = r10 + 12;
    r11 = L32(r9);
    r0 = L32(r9 + 4);
    r0 = r0 - r11;
    r9 = r0 >> 3; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8034b00c;
    r9 = L32(r11 + 4);
    cr0 = CMPU(r9, r24);
    if ((cr0 & 4)) goto L_8034b00c;
    cr0 = CMPU(r9, r7);
    if (!(cr0 & 8)) goto L_8034b00c;
    r7 = r9;
    r6 = r8;
L_8034b00c:
    r8 = r8 + 1;
    cr0 = CMPU(r8, r23);
    if ((cr0 & 8)) goto L_8034afd4;
L_8034b018:
    cr0 = CMPS(r6, 3);
    if ((cr0 & 2)) goto L_8034b3d8;
    r0 = (w3d_s32)r6 * 12;
    r5 = r1 + 8;
    r28 = L32(r25 + r0);
    r27 = r25 + r0;
    r9 = L32(r28);
    r0 = L8(r28 + 16);
    r30 = L32(r9);
    r31 = L32(r9 + 4);
    S8(r1 + 8, r0);
    r3 = L32(r28);
    r4 = L32(r28 + 4);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8034a7fc)(W(r3), W(r4), W(r5));
    r9 = L32(r28 + 4);
    r10 = r30;
    cr0 = CMPS(r10, -1);
    r9 = r9 - 8;
    S32(r28 + 4, r9);
    r11 = L32(r27 + 8);
    if (!(cr0 & 2)) goto L_8034b074;
    r29 = 0x0u;
    goto L_8034b098;
L_8034b074:
    r0 = r10 & 0xfffu;
    r11 = L32(r11);
    r0 = (w3d_s32)r0 * 36;
    r29 = 0x0u;
    r11 = r11 + r0;
    r9 = L32(r11 + 20);
    cr0 = CMPS(r9, r10);
    if (!(cr0 & 2)) goto L_8034b098;
    r29 = r11;
L_8034b098:
    cr0 = CMPS(r29, 0);
    if ((cr0 & 2)) goto L_8034b3b4;
    r3 = L32(r27 + 8);
    r4 = r31;
    ((void (*)(w3d_oarg, w3d_oarg))A8034b3f8)(W(r3), W(r4));
    r3 = L32(r29 + 12);
    r4 = r31;
    r9 = L32(r3);
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r29 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = L32(r3 + 56);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8034b0e8;
    r3 = L32(r27 + 8);
    r24 = r31;
    r4 = r31;
    ((void (*)(w3d_oarg, w3d_oarg))A8034b408)(W(r3), W(r4));
L_8034b0e8:
    cr0 = CMPS(r29, 0);
    if ((cr0 & 2)) goto L_8034b2a4;
    cr0 = CMPS(r29, -1);
    if ((cr0 & 2)) goto L_8034b3b4;
    r0 = r29 + r31;
    S32(r1 + 16, r30);
    r31 = r1 + 16;
    S32(r31 + 4, r0);
    r11 = L32(r28 + 4);
    r0 = L32(r28 + 12);
    cr0 = CMPS(r11, r0);
    if ((cr0 & 2)) goto L_8034b140;
    cr0 = CMPS(r11, 0);
    if ((cr0 & 2)) goto L_8034b130;
    r9 = L32(r1 + 16);
    r10 = L32(r1 + 20);
    S32(r11, r9);
    S32(r11 + 4, r10);
L_8034b130:
    r9 = L32(r28 + 4);
    r9 = r9 + 8;
    S32(r28 + 4, r9);
    goto L_8034b288;
L_8034b140:
    r0 = L32(r28);
    r29 = r11;
    r9 = 0x1u;
    r10 = r1 + 28;
    r0 = r29 - r0;
    S32(r1 + 28, r9);
    { w3d_u32 t_ = r0; r9 = (w3d_u32)((w3d_s32)t_ >> 3); ca = SRAWCA(t_, 3); }
    r11 = r1 + 24;
    S32(r1 + 24, r9);
    cr0 = CMPU(r9, 0x1u);
    if (!(cr0 & 8)) goto L_8034b170;
    r11 = r10;
L_8034b170:
    r0 = L32(r11);
    r0 = r9 + r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8034b1a0;
    r0 = r0 << 3;
    r3 = r0;
    r26 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8034b1a8;
    r3 = r26;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
    goto L_8034b1a8;
L_8034b1a0:
    r3 = 0x0u;
    r26 = 0x0u;
L_8034b1a8:
    r30 = r3;
    r11 = L32(r28);
    r27 = r30;
    r3 = r27;
    cr0 = CMPS(r11, r29);
    if ((cr0 & 2)) goto L_8034b1e8;
L_8034b1c0:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8034b1d8;
    r9 = L32(r11);
    r10 = L32(r11 + 4);
    S32(r3, r9);
    S32(r3 + 4, r10);
L_8034b1d8:
    r11 = r11 + 8;
    r3 = r3 + 8;
    cr0 = CMPS(r11, r29);
    if (!(cr0 & 2)) goto L_8034b1c0;
L_8034b1e8:
    r0 = L32(r1 + 28);
    r30 = r3;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8034b218;
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_8034b210;
    r9 = L32(r31);
    r10 = L32(r31 + 4);
    S32(r30, r9);
    S32(r30 + 4, r10);
L_8034b210:
    r30 = r30 + 8;
    goto L_8034b24c;
L_8034b218:
    r9 = r0; cr0 = CMPS(r9, 0);
    r3 = r30;
    ctr = r9;
    if ((cr0 & 2)) goto L_8034b248;
L_8034b228:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8034b240;
    r9 = L32(r31);
    r10 = L32(r31 + 4);
    S32(r3, r9);
    S32(r3 + 4, r10);
L_8034b240:
    r3 = r3 + 8;
    --ctr; if (ctr != 0) goto L_8034b228;
L_8034b248:
    r30 = r3;
L_8034b24c:
    r9 = L32(r28);
    r0 = L32(r28 + 4);
    r3 = r9;
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_8034b26c;
L_8034b260:
    r9 = r9 + 8;
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8034b260;
L_8034b26c:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8034b278;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_8034b278:
    r0 = r26 + r27;
    S32(r28, r27);
    S32(r28 + 4, r30);
    S32(r28 + 12, r0);
L_8034b288:
    r0 = L8(r28 + 16);
    r5 = r1 + 8;
    S8(r1 + 8, r0);
    r4 = L32(r28 + 4);
    r3 = L32(r28);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8034a400)(W(r3), W(r4), W(r5));
    goto L_8034b3b4;
L_8034b2a4:
    r29 = L32(r27 + 4);
    r3 = r30;
    S32(r1 + 32, r3);
    r27 = r1 + 32;
    r30 = L32(r29 + 4);
    r0 = L32(r29 + 12);
    cr0 = CMPS(r30, r0);
    if ((cr0 & 2)) goto L_8034b2e0;
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_8034b2d0;
    S32(r30, r3);
L_8034b2d0:
    r9 = L32(r29 + 4);
    r9 = r9 + 4;
    S32(r29 + 4, r9);
    goto L_8034b3b4;
L_8034b2e0:
    r0 = L32(r29);
    r9 = 0x1u;
    S32(r1 + 40, r9);
    r10 = r1 + 40;
    r0 = r30 - r0;
    r11 = r1 + 36;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S32(r1 + 36, r9);
    cr0 = CMPU(r9, 0x1u);
    if (!(cr0 & 8)) goto L_8034b30c;
    r11 = r10;
L_8034b30c:
    r0 = L32(r11);
    r0 = r9 + r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8034b340;
    r0 = r0 << 2;
    r3 = r0;
    r31 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8034b338;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
L_8034b338:
    r28 = r3;
    goto L_8034b348;
L_8034b340:
    r28 = 0x0u;
    r31 = 0x0u;
L_8034b348:
    r4 = L32(r29);
    cr0 = CMPS(r30, r4);
    if ((cr0 & 2)) goto L_8034b36c;
    r30 = r30 - r4;
    r3 = r28;
    r5 = r30;
    r3 = CU(A802eeef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = r3 + r30;
    goto L_8034b370;
L_8034b36c:
    r0 = r28;
L_8034b370:
    r9 = L32(r1 + 40);
    r30 = r0;
    ctr = r9;
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8034b394;
L_8034b384:
    r0 = L32(r27);
    S32(r30, r0);
    r30 = r30 + 4;
    --ctr; if (ctr != 0) goto L_8034b384;
L_8034b394:
    r3 = L32(r29);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8034b3a4;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_8034b3a4:
    r0 = r31 + r28;
    S32(r29, r28);
    S32(r29 + 12, r0);
    S32(r29 + 4, r30);
L_8034b3b4:
    r0 = L32(D(0x804ab4d8u));
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8034b3c8;
    r3 = L32(D(0x804b178cu));
    ((void (*)())A801651e4)();
L_8034b3c8:
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = L32(r3 + 56);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8034afbc;
L_8034b3d8:
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = 0x0u;
    S32(r3 + 60, r0);
    r1 = r1 + 88;
    return r3;
}

// 0x8034bc68 FUN_8034bc68 no verificada: desde bytes PPC
// Llama a get_indexed_byte, task_pool_reserve, slots_fill. Hace 5 llamadas virtuales.
__attribute__((weak)) w3d_u32 A8034bc68(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[64];
    w3d_u32 r1 = h2g(frame) + 48;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r12 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 48; S32(t_, r1); r1 = t_; }
    r12 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    S32(r1 + 20, r12);
    r29 = r3;
    r31 = r4;
    r3 = L16(r31 + 6);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801a2350)(W(r3));
    r0 = L32(r29 + 136);
    r27 = r3;
    r30 = L32(r29 + 144);
    r0 = r0 << 2;
    r28 = r30 + r0;
    r26 = r1 + 8;
    goto L_8034bcb0;
L_8034bcac:
    r30 = r30 + 4;
L_8034bcb0:
    cr0 = CMPS(r30, r28);
    cr4 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_8034bd0c;
    r9 = L32(r30);
    r3 = L16(r9 + 6);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801a2350)(W(r3));
    cr0 = CMPS(r3, r27);
    if (!(cr0 & 2)) goto L_8034bcac;
    if ((cr4 & 2)) goto L_8034bce8;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8034bce8:
    r3 = L32(r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8034bd04;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8034bd04:
    S32(r30, r31);
    goto L_8034bd70;
L_8034bd0c:
    r4 = L32(r29 + 136);
    r30 = r29 + 136;
    r3 = r30;
    r4 = r4 + 1;
    ((void (*)(w3d_oarg, w3d_oarg))A801f29d0)(W(r3), W(r4));
    r0 = L32(r29 + 136);
    r28 = L32(r30 + 8);
    r30 = r0 << 2;
    if ((cr4 & 2)) goto L_8034bd44;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8034bd44:
    r3 = L32(r30 + r28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8034bd60;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8034bd60:
    S32(r30 + r28, r31);
    r9 = L32(r29 + 136);
    r9 = r9 + 1;
    S32(r29 + 136, r9);
L_8034bd70:
    r9 = L32(r29);
    r4 = r26;
    r3 = r29;
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = r3;
    r5 = L32(r1 + 8);
    r3 = L32(r29 + 116);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A801a2b64)(W(r3), W(r4), W(r5));
    r3 = 0x0u;
    r12 = L32(r1 + 20);
    cr4 = (r12 >> 12) & 15;
    r1 = r1 + 48;
    return r3;
}

// 0x80355a14 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80355a14(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3);
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x803580b0 fn_803580B0 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A803580b0(w3d_u32 r3) {
    w3d_open_break(0x803580b0u);
    return r3;
}

// 0x803580b8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 801ede8c en 803580c4
__attribute__((weak)) w3d_u32 A803580b8(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A801ede8c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x803580d8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 801ede8c en 803580e4
__attribute__((weak)) w3d_u32 A803580d8(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A801ede8c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x803580f8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 801ede8c en 80358104
__attribute__((weak)) w3d_u32 A803580f8(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A801ede8c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

}
