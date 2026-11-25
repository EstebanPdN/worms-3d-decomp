// Funciones del juego sin fuente admitida: 0x8029cdb4 a 0x802b4378. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A80129424();
__attribute__((weak)) void A8015adf4();
__attribute__((weak)) void A8015aee8();
__attribute__((weak)) void A8015fef0();
__attribute__((weak)) void A80162c20();
__attribute__((weak)) void A801790bc();
__attribute__((weak)) void A8018b260();
__attribute__((weak)) void A8018b2b0();
__attribute__((weak)) void A8018b4cc();
__attribute__((weak)) void A8018b524();
__attribute__((weak)) void A8018c5b0();
__attribute__((weak)) void A8018d324();
__attribute__((weak)) void A8018d35c();
__attribute__((weak)) void A8018d434();
__attribute__((weak)) void A801fe1d8();
__attribute__((weak)) void A801fe45c();
__attribute__((weak)) void A8020bb2c();
__attribute__((weak)) void A8020bb54();
__attribute__((weak)) void A8020bbec();
__attribute__((weak)) void A8020bd38();
__attribute__((weak)) void A8020bdf4();
__attribute__((weak)) void A8020bf2c();
__attribute__((weak)) void A8020c048();
__attribute__((weak)) void A8020c43c();
__attribute__((weak)) void A8020c510();
__attribute__((weak)) void A8020c5c0();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A8020c5cc();
__attribute__((weak)) void A8020c620();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A80296410();
__attribute__((weak)) void A802a0c48();
__attribute__((weak)) void A802a0d44();
__attribute__((weak)) void A802a21ec();
__attribute__((weak)) void A802a282c();
__attribute__((weak)) void A802afb20();
__attribute__((weak)) void A802b0668();
__attribute__((weak)) void A802b1258();
__attribute__((weak)) void A802b1880();
__attribute__((weak)) void A802b222c();
__attribute__((weak)) void A802b22b0();
__attribute__((weak)) void A802b264c();
__attribute__((weak)) void A802eeef4();
__attribute__((weak)) void A802ef198();
__attribute__((weak)) void A802ef234();
__attribute__((weak)) void A802ef380();
__attribute__((weak)) void A802ef9c0();
__attribute__((weak)) void A80316270();
__attribute__((weak)) void A803413d8();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A80341884();
__attribute__((weak)) void A803426b8();
__attribute__((weak)) void A803434d4();
__attribute__((weak)) void A80343580();
__attribute__((weak)) void A80343744();
__attribute__((weak)) void A8034435c();

// 0x8029cdb4 FUN_8029cdb4 no verificada: desde bytes PPC
// Llama a string_property, string_from_text, text_compare, audio_set_mode5, assign__20d24d_String_803426b8PCc. Hace 4 llamadas virtuales. Usa las cadenas "User.Speech", "%s%s".
// aviso: lee r3 tras void 80341588 en 8029d064
__attribute__((weak)) w3d_u32 A8029cdb4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[128];
    w3d_u32 r1 = h2g(frame) + 112;
    w3d_u32 r0 = 0, r11 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 112; S32(t_, r1); r1 = t_; }
    r9 = D(0x803d0000u);
    r26 = r3;
    r9 = D(0x803d0a48u);
    r3 = r1 + 56;
    S32(r1 + 56, r9);
    r4 = r1 + 60;
    r3 = A800fc2b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r26 + 124);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029cdfc;
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8029cdfc:
    r3 = L32(r26 + 124);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029ce18;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8029ce18:
    r0 = 0x0u;
    r30 = r1 + 16;
    S32(r26 + 124, r0);
    r3 = r1 + 8;
    r21 = r30;
    r29 = r26 + 120;
    r4 = L32(r1 + 60);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r9 = D(0x803d0000u);
    r4 = L32(r26 + 120);
    r7 = L32(D(0x803d0cbcu));
    r23 = r1 + 8;
    r9 = D(0x803d0cbcu);
    r6 = L32(D(0x803d0cd0u));
    r0 = L32(D(0x803d0cc0u));
    r11 = L32(D(0x803d0cc4u));
    r10 = L32(D(0x803d0cc8u));
    r8 = L32(D(0x803d0cccu));
    S32(r1 + 16, r7);
    S32(r30 + 4, r0);
    S32(r30 + 8, r11);
    S32(r30 + 12, r10);
    S32(r30 + 16, r8);
    S32(r30 + 20, r6);
    r3 = L32(r1 + 60);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029cec0;
    r3 = L32(D(0x804b1788u));
    r3 = A80129738(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = L32(r1 + 60);
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r9 = L32(r1 + 8);
    r0 = L16(r9 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029cee4;
    r5 = D(0x803f0000u);
    r3 = L32(D(0x804b1788u));
    r5 = D(0x803f04e8u);
    r4 = r23;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80129424)(W(r3), W(r4), W(r5));
L_8029cec0:
    r9 = L32(r26 + 120);
    r0 = L16(r9 - 4);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8029cef8;
    goto L_8029cee4;
L_8029ced4:
    r3 = r25;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r25;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_8029cee4:
    r3 = r23;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r23;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_8029d068;
L_8029cef8:
    r9 = L32(D(0x804b1788u));
    r0 = L32(r9 + 108);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029d058;
    r9 = D(0x803f0000u);
    r24 = 0x0u;
    r22 = D(0x803f04e8u);
    r25 = r1 + 40;
L_8029cf18:
    r3 = (w3d_u32)((w3d_u32 (*)())A80162c20)();
    r11 = r3;
    r0 = 0x84210000u;
    r0 = 0x84210843u;
    r9 = r11 >> 1;
    r9 = (w3d_u32)(((w3d_u64)r9 * (w3d_u64)r0) >> 32);
    r3 = r25;
    r0 = r9 >> 4;
    r0 = (w3d_s32)r0 * 62;
    r0 = r11 - r0;
    r9 = r0 << 6;
    r4 = L32(r9 + r22);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r9 = L32(r1 + 40);
    r0 = L16(r9 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029ced4;
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 40);
    r3 = r1 + 48;
    S32(r1 + 48, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r9 = L16(r3);
    r4 = D(0x803d0000u);
    r4 = D(0x803d0cd4u);
    r9 = r9 + 1;
    S16(r3, r9);
    r3 = L32(r1 + 40);
    r3 = CU(A802ef380, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r31 = L32(r1 + 40);
    r29 = r3;
    r0 = L8(r31 + r29);
    cr0 = CMPS(r0, 46);
    if (!(cr0 & 2)) goto L_8029d030;
    r27 = 0x0u;
    r28 = r29 + 1;
    r30 = r21;
L_8029cfb0:
    r4 = L32(r30);
    r30 = r30 + 4;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_8029cfd4;
    r3 = r31 + r28;
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8029cfb0;
    r27 = 0x1u;
L_8029cfd4:
    cr0 = CMPS(r27, 0);
    if (!(cr0 & 2)) goto L_8029d030;
    r5 = L32(r26 + 120);
    r4 = D(0x803d0000u);
    r3 = r1 + 48;
    r6 = r31 + r29;
    r4 = D(0x803d0cd8u);
    r24 = 0x1u;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r11 = L32(D(0x804b1788u));
    r5 = r26 + 124;
    r4 = L32(r1 + 48);
    r3 = L32(r11 + 108);
    r9 = L32(r3);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r26 + 124);
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8029d030:
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 40;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 40;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    cr0 = CMPS(r24, 0);
    if ((cr0 & 2)) goto L_8029cf18;
L_8029d058:
    r3 = r23;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r23;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
L_8029d068:
    r1 = r1 + 112;
    return r3;
}

// 0x8029e194 FUN_8029e194 no verificada: desde bytes PPC
// Llama a spinner_base_step, elapsed_ms, event_current_context, memmove, sol35f7a_pool_allocate. Hace 3 llamadas virtuales. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8029e194(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[144];
    w3d_u32 r1 = h2g(frame) + 128;
    w3d_u32 r0 = 0, r9 = 0, r10 = 0, r11 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f11 = 0, f12 = 0, f13 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, ctr = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 128; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r3 = r31 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b0668)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = (w3d_u32)((w3d_u32 (*)())A801fe45c)();
    r0 = L32(r31 + 212);
    r23 = r3;
    r26 = r23 - r0;
    cr0 = CMPS(r26, 100);
    if (!(cr0 & 4)) goto L_8029e1dc;
    r26 = 0x64u;
L_8029e1dc:
    cr0 = CMPS(r26, 19);
    if (!(cr0 & 4)) goto L_8029e554;
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f31 = LF(D(0x803d1d08u));
    r10 = D(0x803d0000u);
    r9 = D(0x803d0000u);
    f28 = LF(D(0x803d1d0cu));
    f29 = LF(D(0x803d1d10u));
    r22 = D(0x803d0000u);
    f30 = LF(D(0x803d1d14u));
L_8029e208:
    r0 = L32(r31 + 256);
    r29 = 0x0u;
    r30 = r31 + 28;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029e244;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A802b264c)(W(r3));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029e244;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 48);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    S32(r31 + 256, r29);
L_8029e244:
    r3 = r30;
    r25 = r26 - 20;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A802b264c)(W(r3));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029e50c;
    r0 = L32(r31 + 288);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8029e450;
    r9 = L32(r31 + 292);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_8029e444;
    f13 = LF(r31 + 380);
    f0 = LF(D(0x803d1d00u));
    cr0 = CMPF(f13, f0);
    if (!(cr0 & 4)) goto L_8029e3e4;
    f0 = (float)(f13 - f0);
    r3 = L32(r31 + 336);
    SF(r31 + 380, f0);
    r30 = r31 + 336;
    r4 = r3 + 4;
    r28 = r30;
    r5 = L32(r30 + 4);
    r0 = L32(r3);
    cr0 = CMPS(r4, r5);
    S32(r1 + 8, r0);
    if ((cr0 & 2)) goto L_8029e2bc;
    cr0 = CMPS(r5, r4);
    if ((cr0 & 2)) goto L_8029e2bc;
    r5 = r5 - r4;
    r3 = CU(A802eeef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8029e2bc:
    r9 = L32(r30 + 4);
    r24 = r1 + 8;
    r9 = r9 - 4;
    S32(r30 + 4, r9);
    r30 = L32(r28 + 4);
    r0 = L32(r28 + 12);
    cr0 = CMPS(r30, r0);
    if ((cr0 & 2)) goto L_8029e304;
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_8029e2ec;
    r0 = L32(r1 + 8);
    S32(r30, r0);
L_8029e2ec:
    r9 = L32(r28 + 4);
    r25 = r26 - 20;
    r26 = D(0x803d0000u);
    r9 = r9 + 4;
    S32(r28 + 4, r9);
    goto L_8029e3f4;
L_8029e304:
    r0 = L32(r31 + 336);
    r9 = 0x1u;
    S32(r1 + 16, r9);
    r10 = r1 + 16;
    r0 = r30 - r0;
    r11 = r1 + 12;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S32(r1 + 12, r9);
    cr0 = CMPU(r9, 0x1u);
    if (!(cr0 & 8)) goto L_8029e330;
    r11 = r10;
L_8029e330:
    r0 = L32(r11);
    r0 = r9 + r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029e364;
    r0 = r0 << 2;
    r3 = r0;
    r27 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8029e35c;
    r3 = r27;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
L_8029e35c:
    r29 = r3;
    goto L_8029e36c;
L_8029e364:
    r29 = 0x0u;
    r27 = 0x0u;
L_8029e36c:
    r4 = L32(r28);
    cr0 = CMPS(r30, r4);
    if ((cr0 & 2)) goto L_8029e390;
    r30 = r30 - r4;
    r3 = r29;
    r5 = r30;
    r3 = CU(A802eeef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = r3 + r30;
    goto L_8029e394;
L_8029e390:
    r0 = r29;
L_8029e394:
    r9 = L32(r1 + 16);
    r25 = r26 - 20;
    r30 = r0;
    r26 = D(0x803d0000u);
    ctr = r9;
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8029e3c0;
L_8029e3b0:
    r0 = L32(r24);
    S32(r30, r0);
    r30 = r30 + 4;
    --ctr; if (ctr != 0) goto L_8029e3b0;
L_8029e3c0:
    r3 = L32(r28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029e3d0;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_8029e3d0:
    r0 = r27 + r29;
    S32(r28, r29);
    S32(r28 + 12, r0);
    S32(r28 + 4, r30);
    goto L_8029e3f4;
L_8029e3e4:
    f0 = LF(r31 + 300);
    r26 = D(0x803d0000u);
    f0 = (float)(f13 + f0);
    SF(r31 + 380, f0);
L_8029e3f4:
    f13 = LF(D(0x803d1d04u));
    f0 = LF(r31 + 380);
    cr0 = CMPF(f0, f13);
    if (!(cr0 & 8)) goto L_8029e42c;
    f0 = LF(r31 + 300);
    SF(r31 + 380, f13);
    cr0 = CMPF(f0, f13);
    if (!(cr0 & 8)) goto L_8029e41c;
    SF(r31 + 300, f31);
    goto L_8029e424;
L_8029e41c:
    f0 = -f0;
    SF(r31 + 300, f0);
L_8029e424:
    r0 = 0x64u;
    S32(r31 + 292, r0);
L_8029e42c:
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 40);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_8029e50c;
L_8029e444:
    r0 = r9 - 1;
    S32(r31 + 292, r0);
    goto L_8029e50c;
L_8029e450:
    r9 = L32(r31 + 376);
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8029e494;
    f13 = LF(r9 + 92);
    f0 = LF(r31 + 380);
    cr0 = CMPF(f13, f0);
    if ((cr0 & 2)) goto L_8029e494;
    r0 = L32(r9 + 68);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029e48c;
    SF(r31 + 380, f13);
    r29 = 0x1u;
    f0 = LF(r9 + 92);
    SF(r31 + 384, f0);
    goto L_8029e494;
L_8029e48c:
    SF(r31 + 384, f13);
    r29 = 0x1u;
L_8029e494:
    f13 = LF(r31 + 384);
    f0 = LF(r31 + 380);
    f12 = f13;
    f11 = f0;
    cr0 = CMPF(f13, f0);
    if ((cr0 & 2)) goto L_8029e4d8;
    f0 = (float)(f12 - f11);
    r29 = 0x1u;
    cr0 = CMPF(f0, f31);
    if (!(cr0 & 8)) goto L_8029e4cc;
    cr0 = CMPF(f0, f28);
    if (!(cr0 & 4)) goto L_8029e4cc;
    SF(r31 + 380, f12);
    goto L_8029e4d8;
L_8029e4cc:
    f0 = (float)(f12 * f29);
    f0 = __builtin_fmaf((float)f11, (float)f30, (float)f0);
    SF(r31 + 380, f0);
L_8029e4d8:
    r3 = L32(r31 + 376);
    r25 = r26 - 20;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029e50c;
    f1 = LF(r31 + 380);
    ((void (*)(w3d_oarg, float))A80296410)(W(r3), (float)f1);
    cr0 = CMPS(r29, 1);
    if (!(cr0 & 2)) goto L_8029e50c;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 40);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8029e50c:
    f12 = LF(r31 + 280);
    f13 = LF(r31 + 284);
    cr0 = CMPF(f12, f13);
    if ((cr0 & 2)) goto L_8029e548;
    f0 = (float)(f12 * f29);
    f0 = __builtin_fmaf((float)f13, (float)f30, (float)f0);
    f13 = (float)(f12 - f0);
    SF(r31 + 284, f0);
    cr0 = CMPF(f13, f31);
    if (!(cr0 & 8)) goto L_8029e540;
    cr0 = CMPF(f13, f28);
    if (!(cr0 & 4)) goto L_8029e540;
    SF(r31 + 284, f12);
L_8029e540:
    r3 = r31;
    ((void (*)(w3d_oarg))A802a0d44)(W(r3));
L_8029e548:
    r26 = r25;
    cr0 = CMPS(r26, 19);
    if ((cr0 & 4)) goto L_8029e208;
L_8029e554:
    r0 = r23 - r26;
    r3 = 0x0u;
    S32(r31 + 212, r0);
    r1 = r1 + 128;
    return r3;
}

// 0x8029f714 FUN_8029f714 no verificada: desde bytes PPC
// Llama a runtime_service_lookup, as_font, resource_scope_enter, fit_width, heap_allocate_entry. Hace 3 llamadas virtuales.
__attribute__((weak)) w3d_u32 A8029f714(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[144];
    w3d_u32 r1 = h2g(frame) + 128;
    w3d_u32 r0 = 0, r11 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f13 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, ctr = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 128; S32(t_, r1); r1 = t_; }
    r23 = r3;
    f31 = f1;
    r3 = L32(r23 + 40);
    r30 = r4;
    f30 = f2;
    r3 = r3 + 140;
    r3 = A8015ae3c(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r31 = r3;
    ((void (*)())A8034435c)();
    r9 = D(0x803d0000u);
    SF(r1 + 8, f31);
    f0 = LF(D(0x803d1ddcu));
    r11 = r1 + 8;
    SF(r11 + 4, f31);
    r21 = r3;
    SF(r11 + 8, f0);
    r3 = r31;
    r9 = L32(r31);
    r0 = L32(r9 + 64);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8029f7a4;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 72);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L8(r3);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015aee8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
L_8029f7a4:
    r25 = r23 + 336;
    r28 = r30;
    r22 = r25;
L_8029f7b0:
    r3 = r21;
    r4 = r28;
    f1 = f30;
    f2 = f31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, float, float))A8018b524)(W(r3), W(r4), (float)f1, (float)f2);
    r27 = r3; cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_8029faf4;
    r3 = 0x14u;
    r29 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r30 = r3;
    r31 = r30 + 8;
    S32(r30, r29);
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = L32(r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029f808;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8029f808:
    r4 = D(0x803d0000u);
    r3 = r31;
    r4 = D(0x803d0f78u);
    S32(r30, r29);
    S32(r30 + 4, r29);
    r24 = r1 + 32;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    S32(r30 + 16, r29);
    SF(r30 + 12, f31);
    S32(r1 + 32, r30);
    r9 = L32(r22 + 4);
    r0 = L32(r22 + 12);
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_8029f860;
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8029f84c;
    S32(r9, r30);
L_8029f84c:
    r9 = L32(r25 + 4);
    r26 = r28 + r27;
    r9 = r9 + 4;
    S32(r25 + 4, r9);
    goto L_8029f93c;
L_8029f860:
    r30 = L32(r25 + 4);
    r9 = 0x1u;
    r0 = L32(r23 + 336);
    r11 = r1 + 40;
    S32(r1 + 40, r9);
    r10 = r1 + 36;
    r0 = r30 - r0;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S32(r1 + 36, r9);
    cr0 = CMPU(r9, 0x1u);
    if (!(cr0 & 8)) goto L_8029f890;
    r10 = r11;
L_8029f890:
    r0 = L32(r10);
    r0 = r9 + r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8029f8c4;
    r0 = r0 << 2;
    r3 = r0;
    r31 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8029f8bc;
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
L_8029f8bc:
    r29 = r3;
    goto L_8029f8cc;
L_8029f8c4:
    r29 = 0x0u;
    r31 = 0x0u;
L_8029f8cc:
    r4 = L32(r25);
    cr0 = CMPS(r30, r4);
    if ((cr0 & 2)) goto L_8029f8f0;
    r30 = r30 - r4;
    r3 = r29;
    r5 = r30;
    r3 = CU(A802eeef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = r3 + r30;
    goto L_8029f8f4;
L_8029f8f0:
    r0 = r29;
L_8029f8f4:
    r9 = L32(r1 + 40);
    r30 = r0;
    r26 = r28 + r27;
    ctr = r9;
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8029f91c;
L_8029f90c:
    r0 = L32(r24);
    S32(r30, r0);
    r30 = r30 + 4;
    --ctr; if (ctr != 0) goto L_8029f90c;
L_8029f91c:
    r3 = L32(r25);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8029f92c;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_8029f92c:
    r0 = r31 + r29;
    S32(r25, r29);
    S32(r25 + 4, r30);
    S32(r25 + 12, r0);
L_8029f93c:
    r0 = L32(r25 + 4);
    r3 = r28;
    r9 = L32(r23 + 336);
    r11 = L32(r1 + 32);
    r0 = r0 - r9;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    S32(r11 + 16, r0);
    r3 = CU(A802ef9c0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r27, r3);
    if (!(cr0 & 2)) goto L_8029f984;
    r3 = L32(r1 + 32);
    r4 = r28;
    r28 = r26;
    r3 = r3 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r9 = L32(r1 + 32);
    S32(r9 + 4, r27);
    goto L_8029fae8;
L_8029f984:
    r30 = r26;
    r31 = r1 + 24;
    cr0 = CMPU(r30, r28);
    if (!(cr0 & 4)) goto L_8029f9c0;
    r0 = L8(r28 + r27);
    goto L_8029f9ac;
L_8029f99c:
    r30 = r30 - 1;
    cr0 = CMPU(r30, r28);
    if (!(cr0 & 4)) goto L_8029f9c0;
    r0 = L8(r30);
L_8029f9ac:
    r0 = (w3d_u32)(w3d_s32)(signed char)r0;
    cr0 = CMPS(r0, 32);
    if ((cr0 & 2)) goto L_8029f9c0;
    cr0 = CMPS(r0, 45);
    if (!(cr0 & 2)) goto L_8029f99c;
L_8029f9c0:
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    cr0 = CMPS(r30, r28);
    if (!(cr0 & 2)) goto L_8029fa58;
    cr0 = CMPS(r27, 1);
    if (!(cr0 & 2)) goto L_8029f9f8;
    r4 = r28;
    r3 = r31;
    r5 = 0x1u;
    r28 = r28 + 1;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
    r9 = L32(r1 + 32);
    S32(r9 + 4, r27);
    goto L_8029fa98;
L_8029f9f8:
    r0 = L8(r26 - 1);
    r29 = D(0x803d0000u);
    r0 = r0 & 0xc0u;
    cr0 = CMPS(r0, 128);
    if (!(cr0 & 2)) goto L_8029fa28;
    r0 = r27 - 1;
    r9 = r0 + r28;
L_8029fa14:
    { w3d_u32 t_ = r9 - 1; r0 = L8(t_); r9 = t_; }
    r27 = r27 - 1;
    r0 = r0 & 0xc0u;
    cr0 = CMPS(r0, 128);
    if ((cr0 & 2)) goto L_8029fa14;
L_8029fa28:
    r30 = r27 - 1;
    r4 = r28;
    r3 = r31;
    r5 = r30;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
    r28 = r28 + r30;
    r3 = r31;
    r4 = D(0x803d1db8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    r9 = L32(r1 + 32);
    S32(r9 + 4, r30);
    goto L_8029fa98;
L_8029fa58:
    r29 = r30 - r28;
    r4 = r28;
    r3 = r31;
    r5 = r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
    r0 = L8(r30);
    cr0 = CMPS(r0, 45);
    if (!(cr0 & 2)) goto L_8029fa88;
    r4 = D(0x803d0000u);
    r3 = r31;
    r4 = D(0x803d1db8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
L_8029fa88:
    r9 = L32(r1 + 32);
    r0 = r29 + 1;
    S32(r9 + 4, r0);
    r28 = r30 + 1;
L_8029fa98:
    r10 = L32(r1 + 24);
    r31 = L32(r1 + 32);
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r31 + 8);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8029fad0;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_8029fad0:
    r0 = L32(r1 + 24);
    r3 = r1 + 24;
    S32(r31 + 8, r0);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 24;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_8029fae8:
    r0 = L8(r28);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8029f7b0;
L_8029faf4:
    r9 = D(0x803d0000u);
    r11 = L32(r23 + 336);
    f0 = LF(D(0x803d1de0u));
    SF(r23 + 268, f0);
    r0 = L32(r25 + 4);
    cr0 = CMPS(r11, r0);
    if ((cr0 & 2)) goto L_8029fb38;
    r10 = r25;
L_8029fb14:
    r9 = L32(r11);
    f13 = LF(r23 + 268);
    r11 = r11 + 4;
    f0 = LF(r9 + 12);
    f13 = (float)(f13 + f0);
    SF(r23 + 268, f13);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_8029fb14;
L_8029fb38:
    r1 = r1 + 128;
    return r3;
}

// 0x802a06ac FUN_802a06ac no verificada: desde bytes PPC
// Llama a string_from_text, sol35f7a_pool_header_release, colour_property, handle_load_node, mesh_identity. Hace 9 llamadas virtuales. Usa las cadenas "FE.MenuTextColour". Mucho cálculo en coma flotante.
// aviso: lee r3 tras void 80341588 en 802a0c14
__attribute__((weak)) w3d_u32 A802a06ac(w3d_u32 r3, float s1, float s2, float s3) {
    alignas(16) char frame[296];
    w3d_u32 r1 = h2g(frame) + 280;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f11 = 0, f12 = 0, f13 = 0, f26 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 280; S32(t_, r1); r1 = t_; }
    r28 = r3;
    r9 = D(0x803d0000u);
    r27 = L32(r28 + 40);
    r11 = r1 + 8;
    f11 = LF(D(0x803d1e70u));
    r7 = r28 + 336;
    f0 = LF(r27 + 40);
    SF(r1 + 8, f11);
    r5 = 0x43300000u;
    SF(r11 + 8, f0);
    r9 = D(0x803d0000u);
    SF(r11 + 4, f11);
    r6 = D(0x803d0000u);
    f12 = LF(D(0x803d1e74u));
    r11 = D(0x80400000u);
    r8 = L32(r28 + 336);
    f31 = f1;
    r0 = L32(r7 + 4);
    f29 = (float)(f3 * f12);
    f13 = LD(D(0x803d1e78u));
    r11 = D(0x80401c50u);
    r0 = r0 - r8;
    r9 = L32(r27 + 124);
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    r20 = r7;
    S32(r1 + 172, r0);
    r9 = r9 << 2;
    r0 = L32(r28 + 376);
    f30 = -f29;
    S32(r1 + 168, r5);
    r23 = L32(r11 + r9);
    cr0 = CMPS(r0, 0);
    f0 = LDS(r1 + 168);
    f0 = f0 - f13;
    f0 = (float)f0;
    f0 = (float)(f0 * f31);
    if (!(cr0 & 2)) goto L_802a07e0;
    r0 = L32(r28 + 288);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a07e0;
    r0 = r23 & 0x3u;
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_802a079c;
    if ((cr0 & 4)) goto L_802a0790;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a07a8;
    goto L_802a07f8;
L_802a0790:
    cr0 = CMPS(r0, 2);
    if ((cr0 & 2)) goto L_802a07cc;
    goto L_802a07f8;
L_802a079c:
    SF(r1 + 12, f29);
    f30 = (float)(f30 + f31);
    goto L_802a07f8;
L_802a07a8:
    cr0 = CMPF(f0, f11);
    if ((cr0 & 2)) goto L_802a07bc;
    f0 = (float)(f0 - f31);
    f0 = (float)(f0 * f12);
    SF(r1 + 12, f0);
L_802a07bc:
    f0 = (float)(f31 * f12);
    f29 = (float)(f29 - f0);
    f30 = (float)(f30 + f0);
    goto L_802a07f8;
L_802a07cc:
    f0 = (float)(f30 + f0);
    f0 = (float)(f0 - f31);
    SF(r1 + 12, f0);
    f29 = (float)(f29 - f31);
    goto L_802a07f8;
L_802a07e0:
    f0 = LF(r28 + 380);
    r9 = r23 & 0xcu;
    r23 = r9 + 1;
    f30 = (float)(f30 + f31);
    f0 = __builtin_fmaf((float)f0, (float)f31, (float)f29);
    SF(r1 + 12, f0);
L_802a07f8:
    r0 = r23 & 0xcu;
    cr0 = CMPS(r0, 4);
    if ((cr0 & 2)) goto L_802a0820;
    if ((cr0 & 4)) goto L_802a0814;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a0840;
    goto L_802a085c;
L_802a0814:
    cr0 = CMPS(r0, 8);
    if ((cr0 & 2)) goto L_802a084c;
    goto L_802a085c;
L_802a0820:
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f0 = LF(D(0x803d1e74u));
    f13 = LF(D(0x803d1e70u));
    f0 = (float)(f2 * f0);
    f13 = (float)(f13 - f0);
    SF(r1 + 8, f13);
    goto L_802a085c;
L_802a0840:
    r9 = D(0x803d0000u);
    f0 = LF(D(0x803d1e70u));
    goto L_802a0858;
L_802a084c:
    r9 = D(0x803d0000u);
    f0 = LF(D(0x803d1e74u));
    f0 = (float)(f2 * f0);
L_802a0858:
    SF(r1 + 8, f0);
L_802a085c:
    r0 = 0x0u;
    r9 = r1 + 88;
    S8(r1 + 88, r0);
    r11 = 0xffffffffu;
    r4 = D(0x803d0000u);
    S8(r9 + 2, r0);
    S8(r9 + 3, r11);
    r30 = r9;
    S8(r9 + 1, r0);
    r4 = D(0x803d1e5cu);
    r3 = r1 + 24;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r11 = L32(r27 + 132);
    r0 = L16(r11 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a08d4;
    r9 = L16(r11 - 6);
    r9 = r9 + 1;
    S16(r11 - 6, r9);
    r11 = L32(r1 + 24);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a08cc;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_802a08cc:
    r0 = L32(r27 + 132);
    S32(r1 + 24, r0);
L_802a08d4:
    r0 = L32(r1 + 24);
    r31 = r1 + 96;
    r3 = r1 + 92;
    r4 = r31;
    S32(r1 + 92, r0);
    r3 = A800fc370(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r27 + 116);
    r9 = D(0x803d0000u);
    r29 = L32(r28 + 336);
    r11 = r1 + 32;
    S32(r1 + 96, r0);
    f13 = LF(D(0x803d1e70u));
    f0 = LF(r27 + 40);
    SF(r1 + 32, f13);
    r0 = L32(r20 + 4);
    SF(r11 + 4, f13);
    SF(r1 + 40, f0);
    cr0 = CMPS(r29, r0);
    if ((cr0 & 2)) goto L_802a0bec;
    r19 = D(0x803d0000u);
    r9 = D(0x803d0000u);
    f26 = LF(D(0x803d1e84u));
    f27 = f13;
    f28 = LF(D(0x803d1e80u));
    r21 = r31;
    r24 = r30;
    r22 = r11;
    r26 = r1 + 48;
    r25 = r1 + 72;
L_802a0948:
    r0 = L32(r1 + 32);
    r9 = L32(r22 + 4);
    r11 = L32(r22 + 8);
    S32(r1 + 48, r0);
    S32(r26 + 4, r9);
    S32(r26 + 8, r11);
    f13 = LF(r1 + 36);
    f0 = LF(r1 + 12);
    f0 = (float)(f13 + f0);
    cr0 = CMPF(f0, f29);
    if (!(cr0 & 4)) goto L_802a09b8;
    f0 = (float)(f0 - f29);
    f13 = LF(D(0x803d1e80u));
    f0 = (float)(f0 / f31);
    f0 = (float)(f13 - f0);
    SF(r1 + 100, f0);
    cr0 = CMPF(f0, f27);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802a09d8;
    cr0 = CMPF(f0, f13);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802a09d8;
    f13 = LF(r1 + 52);
    f0 = (float)(f31 * f0);
    f0 = (float)(f31 - f0);
    f13 = (float)(f13 - f0);
    SF(r1 + 52, f13);
    goto L_802a09d8;
L_802a09b8:
    cr0 = CMPF(f0, f30);
    if (!(cr0 & 8)) goto L_802a09d4;
    f0 = (float)(f30 - f0);
    f0 = (float)(f0 / f31);
    f0 = (float)(f28 - f0);
    SF(r1 + 100, f0);
    goto L_802a09d8;
L_802a09d4:
    SF(r1 + 100, f28);
L_802a09d8:
    f0 = LF(r1 + 100);
    r0 = r1 + 104;
    SF(r1 + 104, f28);
    r9 = r1 + 100;
    cr0 = CMPF(f28, f0);
    if (!(cr0 & 8)) goto L_802a09f4;
    r9 = r0;
L_802a09f4:
    f0 = LF(r9);
    cr0 = CMPF(f0, f27);
    SF(r1 + 100, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802a0a58;
    r9 = L32(r29);
    r4 = L32(r9);
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_802a0bd0;
    r3 = L32(r28 + 308);
    r30 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 96);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r31 = L32(r29);
    r3 = L32(r31);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a0a50;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a0a50:
    S32(r31, r30);
    goto L_802a0bd0;
L_802a0a58:
    r9 = L32(r29);
    r0 = L32(r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a0b20;
    r9 = L8(r28 + 216);
    r4 = r1 + 64;
    r5 = L8(r28 + 32);
    r3 = r27 + 140;
    r9 = r9 + 30;
    S32(r1 + 64, r0);
    r5 = r5 + r9;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 64);
    ((void (*)())A80343580)();
    r30 = L32(r29);
    r31 = r3; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_802a0ab4;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a0ab4:
    r3 = L32(r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a0ad0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a0ad0:
    S32(r30, r31);
    r5 = 0x0u;
    r3 = L32(r28 + 308);
    r9 = L32(r29);
    r11 = L32(r3);
    r4 = L32(r9);
    r0 = L32(r11 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r29);
    r4 = L32(r9 + 8);
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018c5b0)(W(r3), W(r4));
    r3 = L32(r1 + 64);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a0b20;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a0b20:
    r9 = L32(r29);
    r4 = r23;
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d324)(W(r3), W(r4));
    r11 = L32(r29);
    r5 = 0x0u;
    r4 = r26;
    r3 = L32(r11);
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    f0 = LF(r1 + 100);
    r10 = r11;
    r4 = r21;
    f13 = f0;
    f0 = (float)(f0 * f26);
    PSQS_U8(r1 + 168, f0);
    f13 = (float)(f13 * f26);
    r9 = L8(r1 + 168);
    PSQS_U8(r1 + 168, f13);
    S8(r21 + 3, r9);
    r0 = L8(r1 + 168);
    S8(r24 + 3, r0);
    r9 = L32(r29);
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d35c)(W(r3), W(r4));
    r9 = L32(r29);
    r4 = r24;
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d434)(W(r3), W(r4));
    f0 = LF(r1 + 100);
    r4 = r25;
    SF(r1 + 72, f31);
    r5 = 0x0u;
    f0 = (float)(f31 * f0);
    SF(r1 + 76, f0);
    SF(r25 + 8, f28);
    r9 = L32(r29);
    r3 = L32(r9);
    r11 = L32(r3);
    r0 = L32(r11 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a0bd0:
    f0 = LF(r1 + 36);
    r29 = r29 + 4;
    r0 = L32(r20 + 4);
    f0 = (float)(f0 - f31);
    SF(r1 + 36, f0);
    cr0 = CMPS(r29, r0);
    if (!(cr0 & 2)) goto L_802a0948;
L_802a0bec:
    r3 = L32(r28 + 308);
    r4 = r1 + 8;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r1 + 24;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 24;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 280;
    return r3;
}

// 0x802a0f98 FUN_802a0f98 no verificada: desde bytes PPC
// Llama a string_from_text, sol35f7a_pool_header_release, colour_property, handle_load_node, mesh_identity. Hace 10 llamadas virtuales. Usa las cadenas "FE.MenuTextColour". Mucho cálculo en coma flotante.
// aviso: lee r3 tras void 80341588 en 802a1520
__attribute__((weak)) w3d_u32 A802a0f98(w3d_u32 r3, float s1, float s2, float s3) {
    alignas(16) char frame[320];
    w3d_u32 r1 = h2g(frame) + 304;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f12 = 0, f13 = 0, f24 = 0, f25 = 0, f26 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 304; S32(t_, r1); r1 = t_; }
    r27 = r3;
    r9 = D(0x803d0000u);
    r25 = L32(r27 + 40);
    r10 = r1 + 8;
    f12 = LF(D(0x803d1e88u));
    r11 = D(0x80400000u);
    f0 = LF(r25 + 40);
    r11 = D(0x80401c50u);
    SF(r1 + 8, f12);
    r9 = D(0x803d0000u);
    SF(r10 + 8, f0);
    f31 = f1;
    SF(r10 + 4, f12);
    f27 = f2;
    f13 = LF(D(0x803d1e8cu));
    r0 = L32(r25 + 124);
    f0 = LF(r27 + 380);
    f28 = (float)(f3 * f13);
    r0 = r0 << 2;
    f29 = -f28;
    r26 = L32(r11 + r0);
    f0 = __builtin_fmaf((float)f0, (float)f31, (float)f28);
    SF(r1 + 12, f0);
    f29 = (float)(f29 + f31);
    r9 = r26 & 0xcu;
    r26 = r9 + 1;
    r0 = r26 & 0xcu;
    cr0 = CMPS(r0, 4);
    if ((cr0 & 2)) goto L_802a1058;
    if ((cr0 & 4)) goto L_802a104c;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a1064;
    goto L_802a1074;
L_802a104c:
    cr0 = CMPS(r0, 8);
    if ((cr0 & 2)) goto L_802a106c;
    goto L_802a1074;
L_802a1058:
    f0 = (float)(f27 * f13);
    f0 = (float)(f12 - f0);
    goto L_802a1070;
L_802a1064:
    SF(r1 + 8, f12);
    goto L_802a1074;
L_802a106c:
    f0 = (float)(f27 * f13);
L_802a1070:
    SF(r1 + 8, f0);
L_802a1074:
    r0 = 0x0u;
    r9 = r1 + 88;
    S8(r1 + 88, r0);
    r11 = 0xffffffffu;
    r4 = D(0x803d0000u);
    S8(r9 + 2, r0);
    S8(r9 + 3, r11);
    r21 = r9;
    S8(r9 + 1, r0);
    r4 = D(0x803d1e5cu);
    r3 = r1 + 24;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r11 = L32(r25 + 132);
    r0 = L16(r11 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a10ec;
    r9 = L16(r11 - 6);
    r9 = r9 + 1;
    S16(r11 - 6, r9);
    r11 = L32(r1 + 24);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a10e4;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_802a10e4:
    r0 = L32(r25 + 132);
    S32(r1 + 24, r0);
L_802a10ec:
    r0 = L32(r1 + 24);
    r4 = r1 + 96;
    r22 = r4;
    r3 = r1 + 92;
    S32(r1 + 92, r0);
    r3 = A800fc370(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r25 + 116);
    r9 = D(0x803d0000u);
    f13 = LF(D(0x803d1e88u));
    r11 = r1 + 32;
    S32(r1 + 96, r0);
    r9 = r27 + 336;
    r23 = r11;
    r18 = r9;
    r30 = L32(r27 + 336);
    f0 = LF(r25 + 40);
    SF(r1 + 32, f13);
    SF(r11 + 4, f13);
    SF(r1 + 40, f0);
    r0 = L32(r9 + 4);
    cr0 = CMPS(r30, r0);
    if ((cr0 & 2)) goto L_802a14f8;
    r20 = D(0x803d0000u);
    r9 = D(0x803d0000u);
    r11 = D(0x803d0000u);
    f24 = LF(D(0x803d1e94u));
    f25 = LF(D(0x803d1e8cu));
    f26 = f13;
    f30 = LF(D(0x803d1e90u));
    r24 = r1 + 48;
    r19 = r26 & 0x3u;
L_802a1168:
    r0 = L32(r1 + 32);
    r9 = L32(r23 + 4);
    r11 = L32(r23 + 8);
    S32(r1 + 48, r0);
    S32(r24 + 4, r9);
    S32(r24 + 8, r11);
    f13 = LF(r1 + 36);
    f0 = LF(r1 + 12);
    f0 = (float)(f13 + f0);
    cr0 = CMPF(f0, f28);
    if (!(cr0 & 4)) goto L_802a11d8;
    f0 = (float)(f0 - f28);
    f13 = LF(D(0x803d1e90u));
    f0 = (float)(f0 / f31);
    f0 = (float)(f13 - f0);
    SF(r1 + 100, f0);
    cr0 = CMPF(f0, f26);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802a11f8;
    cr0 = CMPF(f0, f13);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802a11f8;
    f13 = LF(r1 + 52);
    f0 = (float)(f31 * f0);
    f0 = (float)(f31 - f0);
    f13 = (float)(f13 - f0);
    SF(r1 + 52, f13);
    goto L_802a11f8;
L_802a11d8:
    cr0 = CMPF(f0, f29);
    if (!(cr0 & 8)) goto L_802a11f4;
    f0 = (float)(f29 - f0);
    f0 = (float)(f0 / f31);
    f0 = (float)(f30 - f0);
    SF(r1 + 100, f0);
    goto L_802a11f8;
L_802a11f4:
    SF(r1 + 100, f30);
L_802a11f8:
    f0 = LF(r1 + 100);
    r0 = r1 + 104;
    SF(r1 + 104, f30);
    r9 = r1 + 100;
    cr0 = CMPF(f30, f0);
    if (!(cr0 & 8)) goto L_802a1214;
    r9 = r0;
L_802a1214:
    f0 = LF(r9);
    cr0 = CMPF(f0, f26);
    SF(r1 + 100, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_802a1278;
    r9 = L32(r30);
    r4 = L32(r9);
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_802a14dc;
    r3 = L32(r27 + 308);
    r29 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 96);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r31 = L32(r30);
    r3 = L32(r31);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a1270;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a1270:
    S32(r31, r29);
    goto L_802a14dc;
L_802a1278:
    r9 = L32(r30);
    r28 = r1 + 64;
    r0 = L32(r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a1344;
    r9 = L8(r27 + 216);
    r4 = r28;
    r5 = L8(r27 + 32);
    r3 = r25 + 140;
    r9 = r9 + 30;
    S32(r1 + 64, r0);
    r5 = r5 + r9;
    r5 = r5 & 0xffu;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8015adf4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(r1 + 64);
    ((void (*)())A80343580)();
    r29 = L32(r30);
    r31 = r3; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_802a12d8;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a12d8:
    r3 = L32(r29);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a12f4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a12f4:
    S32(r29, r31);
    r5 = 0x0u;
    r3 = L32(r27 + 308);
    r9 = L32(r30);
    r11 = L32(r3);
    r4 = L32(r9);
    r0 = L32(r11 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r30);
    r4 = L32(r9 + 8);
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018c5b0)(W(r3), W(r4));
    r3 = L32(r1 + 64);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a1344;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a1344:
    r3 = L32(r30);
    r0 = L32(r3 + 16);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a13cc;
    f12 = LF(r1 + 48);
    r0 = r26 & 0xcu;
    f13 = LF(r1 + 52);
    cr0 = CMPS(r0, 4);
    f0 = LF(r1 + 56);
    SF(r1 + 76, f13);
    SF(r1 + 80, f0);
    SF(r1 + 72, f12);
    if (!(cr0 & 2)) goto L_802a1380;
    f0 = __builtin_fmaf((float)f27, (float)f25, (float)f12);
    SF(r1 + 72, f0);
L_802a1380:
    cr0 = CMPS(r0, 8);
    if (!(cr0 & 2)) goto L_802a1398;
    f0 = LF(r1 + 72);
    f13 = (float)(f27 * f25);
    f0 = (float)(f0 - f13);
    SF(r1 + 72, f0);
L_802a1398:
    r9 = L32(r30);
    r4 = r19;
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d324)(W(r3), W(r4));
    r11 = L32(r30);
    r4 = r1 + 72;
    r5 = 0x0u;
    r3 = L32(r11);
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_802a13f8;
L_802a13cc:
    r3 = L32(r3);
    r4 = r26;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d324)(W(r3), W(r4));
    r9 = L32(r30);
    r4 = r24;
    r5 = 0x0u;
    r3 = L32(r9);
    r11 = L32(r3);
    r0 = L32(r11 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a13f8:
    f0 = LF(r1 + 100);
    r10 = r11;
    f13 = f0;
    f0 = (float)(f0 * f24);
    PSQS_U8(r1 + 176, f0);
    f13 = (float)(f13 * f24);
    r9 = L8(r1 + 176);
    PSQS_U8(r1 + 176, f13);
    S8(r22 + 3, r9);
    r0 = L8(r1 + 176);
    S8(r21 + 3, r0);
    r3 = L32(r30);
    r0 = L32(r3 + 16);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a148c;
    r0 = L32(r1 + 96);
    r9 = r0 >> 24;
    S32(r1 + 108, r0);
    cr0 = CMPU(r9, 0x1eu);
    if (!(cr0 & 4)) goto L_802a1450;
    r0 = r9 - 30;
    S8(r1 + 108, r0);
L_802a1450:
    r9 = L8(r1 + 109);
    r4 = r1 + 108;
    cr0 = CMPU(r9, 0x1eu);
    if (!(cr0 & 4)) goto L_802a1468;
    r0 = r9 - 30;
    S8(r4 + 1, r0);
L_802a1468:
    r9 = L8(r1 + 110);
    cr0 = CMPU(r9, 0x1eu);
    if (!(cr0 & 4)) goto L_802a147c;
    r0 = r9 - 30;
    S8(r4 + 2, r0);
L_802a147c:
    r9 = L32(r30);
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d35c)(W(r3), W(r4));
    goto L_802a1498;
L_802a148c:
    r3 = L32(r3);
    r4 = r22;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d35c)(W(r3), W(r4));
L_802a1498:
    r9 = L32(r30);
    r4 = r21;
    r3 = L32(r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018d434)(W(r3), W(r4));
    f0 = LF(r1 + 100);
    r4 = r28;
    SF(r1 + 64, f31);
    r5 = 0x0u;
    f0 = (float)(f31 * f0);
    SF(r1 + 68, f0);
    SF(r28 + 8, f30);
    r9 = L32(r30);
    r3 = L32(r9);
    r11 = L32(r3);
    r0 = L32(r11 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a14dc:
    f0 = LF(r1 + 36);
    r30 = r30 + 4;
    r0 = L32(r18 + 4);
    f0 = (float)(f0 - f31);
    SF(r1 + 36, f0);
    cr0 = CMPS(r30, r0);
    if (!(cr0 & 2)) goto L_802a1168;
L_802a14f8:
    r3 = L32(r27 + 308);
    r4 = r1 + 8;
    r5 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r1 + 24;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 24;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 304;
    return r3;
}

// 0x802a1c90 FUN_802a1c90 no verificada: desde bytes PPC
// Llama a text_default, strchr, sol35d11_character_count, utf8_prefix, string_substring_construct. Hace 7 llamadas virtuales. Usa las cadenas "A.KeyDel", "GS.OutBox".
// aviso: lee r3 tras void 80341588 en 802a21d0
__attribute__((weak)) w3d_u32 A802a1c90(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[240];
    w3d_u32 r1 = h2g(frame) + 224;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr7 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 224; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r30 = r4;
    r3 = r1 + 8;
    r24 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = L32(r31 + 420);
    r26 = L32(r31 + 40);
    r0 = L16(r3 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a1ce0;
    r4 = r30;
    r3 = CU(A802ef198, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a1ce0;
    r30 = 0x0u;
L_802a1ce0:
    cr0 = CMPS(r30, 13);
    if ((cr0 & 2)) goto L_802a1e4c;
    cr0 = CMPU(r30, 0xdu);
    if ((cr0 & 4)) goto L_802a1cfc;
    cr0 = CMPS(r30, 8);
    if ((cr0 & 2)) goto L_802a1db8;
    goto L_802a1f24;
L_802a1cfc:
    cr0 = CMPS(r30, 127);
    if (!(cr0 & 2)) goto L_802a1f24;
    r27 = r31 + 412;
    r3 = r27;
    r3 = CU(A8020c5cc, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = L32(r31 + 404);
    cr0 = CMPU(r4, r3);
    if (!(cr0 & 8)) goto L_802a1e40;
    r3 = r27;
    r24 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020c620)(W(r3), W(r4));
    r4 = L32(r31 + 412);
    r28 = r1 + 16;
    r30 = r3;
    r6 = L16(r4 - 4);
    r5 = r30;
    r3 = r28;
    r6 = r6 - r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8020bbec)(W(r3), W(r4), W(r5), W(r6));
    r4 = 0x1u;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020c620)(W(r3), W(r4));
    r29 = r3;
    r4 = r27;
    r3 = r1 + 8;
    r5 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c048)(W(r3), W(r4), W(r5));
    r4 = L32(r31 + 412);
    r0 = r30 + r29;
    r3 = r1 + 8;
    r5 = L16(r4 - 4);
    r4 = r4 + r30;
    r5 = r5 - r0;
    r4 = r4 + r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
    r9 = L32(r31 + 208);
    r4 = D(0x803d0000u);
    r4 = D(0x803d1f64u);
    r3 = r31 + 28;
    r0 = L32(r9 + 28);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r28;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r28;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_802a215c;
L_802a1db8:
    r4 = L32(r31 + 404);
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_802a1e40;
    r30 = r31 + 412;
    r4 = r4 - 1;
    r3 = r30;
    r24 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020c620)(W(r3), W(r4));
    r29 = r3;
    r4 = L32(r31 + 404);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020c620)(W(r3), W(r4));
    r28 = r3;
    r4 = r30;
    r5 = r29;
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c048)(W(r3), W(r4), W(r5));
    r4 = L32(r31 + 412);
    r3 = r1 + 8;
    r5 = L16(r4 - 4);
    r4 = r4 + r28;
    r5 = r5 - r28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
    r9 = L32(r31 + 404);
    r4 = D(0x803d0000u);
    r11 = L32(r31 + 208);
    r4 = D(0x803d1f64u);
    r9 = r9 - 1;
    r3 = r31 + 28;
    S32(r31 + 404, r9);
    r0 = L32(r11 + 28);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_802a215c;
L_802a1e40:
    r3 = r31 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b22b0)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_802a215c;
L_802a1e4c:
    r4 = D(0x803d0000u);
    r3 = L32(r26 + 136);
    r4 = D(0x803d1f70u);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_802a1ea0;
    r0 = 0x0u;
    r9 = L32(r31 + 208);
    S32(r31 + 424, r0);
    r3 = r31 + 28;
    r4 = 0x0u;
    r0 = L32(r9 + 52);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r31 + 392);
    r4 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_802a1ee8;
L_802a1ea0:
    r29 = D(0x804b0000u);
    r10 = L32(D(0x804b06a0u));
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r1 + 8);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_802a1ed8;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_802a1ed8:
    r0 = L32(D(0x804b06a0u));
    r24 = 0x1u;
    S32(r31 + 404, r30);
    S32(r1 + 8, r0);
L_802a1ee8:
    r3 = L32(r31 + 416);
    r4 = L32(r31 + 412);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_802a1f04;
    r0 = 0x0u;
L_802a1f04:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a215c;
    r3 = L32(r26 + 172);
    r0 = L16(r3 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a215c;
    ((void (*)(w3d_oarg))A802b1258)(W(r3));
    goto L_802a215c;
L_802a1f24:
    cr0 = CMPU(r30, 0x1fu);
    if (!(cr0 & 4)) goto L_802a215c;
    cr0 = CMPS(r30, 47);
    if ((cr0 & 2)) goto L_802a215c;
    cr0 = CMPS(r30, 92);
    if ((cr0 & 2)) goto L_802a215c;
    cr0 = CMPS(r30, 37);
    if ((cr0 & 2)) goto L_802a215c;
    r9 = r31 + 336;
    r11 = L32(r31 + 336);
    r0 = L32(r9 + 4);
    r25 = r9;
    r0 = r0 - r11;
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_802a1f84;
    r11 = L32(r11);
    r30 = r30 & 0xffffu;
    r29 = r30;
    r3 = L32(r11);
    r9 = L32(r3);
    r0 = L32(r9 + 64);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_802a1f94;
L_802a1f84:
    r3 = r26 + 140;
    r30 = r30 & 0xffffu;
    r3 = A8015ae3c(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r29 = r30;
L_802a1f94:
    ((void (*)())A8034435c)();
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8018b260)(W(r3), W(r4));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a215c;
    r0 = L32(r26 + 164);
    r27 = 0x1u;
    r28 = r31 + 412;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a1fd4;
    r3 = r28;
    r3 = CU(A8020c5cc, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r26 + 164);
    { w3d_u32 a_ = r0, b_ = r3; r27 = b_ - a_; ca = b_ >= a_; }
    { w3d_u64 t_ = (w3d_u64)(w3d_u32)~r27 + r27 + ca; r27 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r27 = 0u - r27;
L_802a1fd4:
    r30 = r1 + 24;
    r5 = 0x0u;
    r3 = r29;
    r4 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8018b2b0)(W(r3), W(r4), W(r5));
    r23 = r30;
    r4 = r3;
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A803434d4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r4 = L32(r31 + 404);
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020c620)(W(r3), W(r4));
    r29 = r3;
    cr7 = CMPS(r27, 1);
    if (!(cr7 & 2)) goto L_802a2154;
    r0 = L32(r26 + 160);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a2108;
    r9 = L32(r31 + 336);
    r0 = L32(r25 + 4);
    r0 = r0 - r9;
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_802a2108;
    r30 = r1 + 16;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r0 = L32(r26 + 184);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_802a206c;
    r9 = L32(r31 + 412);
    r4 = D(0x803d0000u);
    r3 = r30;
    r4 = D(0x803d1f04u);
    r5 = L16(r9 - 4);
    r5 = r5 + 1;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020bdf4)(W(r3), W(r4), W(r5));
    goto L_802a20a0;
L_802a206c:
    r5 = r29;
    r4 = r28;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c048)(W(r3), W(r4), W(r5));
    r4 = r23;
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    r4 = L32(r31 + 412);
    r3 = r30;
    r5 = L16(r4 - 4);
    r4 = r4 + r29;
    r5 = r5 - r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
L_802a20a0:
    r9 = L32(r31 + 336);
    r11 = L32(r9);
    r3 = L32(r11);
    r9 = L32(r3);
    r0 = L32(r9 + 64);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    ((void (*)())A8034435c)();
    r4 = L32(r1 + 16);
    f1 = ((float (*)(w3d_oarg, w3d_oarg))A8018b4cc)(W(r3), W(r4));
    f31 = f1;
    r3 = r31 + 28;
    f1 = ((float (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b1880)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    f31 = (float)(f31 * f1);
    r0 = L32(r26 + 160);
    f0 = FCTIWZ(f31);
    SDS(r1 + 168, f0);
    r9 = L32(r1 + 172);
    cr0 = CMPU(r9, r0);
    if ((cr0 & 8)) goto L_802a20f4;
    r27 = 0x0u;
L_802a20f4:
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    cr7 = CMPS(r27, 1);
L_802a2108:
    if (!(cr7 & 2)) goto L_802a2154;
    r5 = r29;
    r3 = r1 + 8;
    r4 = r28;
    r24 = 0x1u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c048)(W(r3), W(r4), W(r5));
    r4 = r23;
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bf2c)(W(r3), W(r4));
    r4 = L32(r31 + 412);
    r3 = r1 + 8;
    r5 = L16(r4 - 4);
    r4 = r4 + r29;
    r5 = r5 - r29;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8020c43c)(W(r3), W(r4), W(r5));
    r9 = L32(r31 + 404);
    r9 = r9 + 1;
    S32(r31 + 404, r9);
    goto L_802a215c;
L_802a2154:
    r3 = r31 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b22b0)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
L_802a215c:
    cr0 = CMPS(r24, 0);
    if ((cr0 & 2)) goto L_802a21c0;
    r9 = L32(r31);
    r3 = r31;
    r4 = L32(r1 + 8);
    r0 = L32(r9 + 44);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r31 + 312);
    r0 = 0x1u;
    S32(r31 + 428, r0);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802a219c;
    ((void (*)())A80343744)();
    r4 = L32(r1 + 8);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801790bc)(W(r3), W(r4));
L_802a219c:
    r0 = 0x0u;
    r3 = r31;
    S32(r31 + 428, r0);
    ((void (*)(w3d_oarg))A802a282c)(W(r3));
    r3 = L32(r26 + 168);
    r0 = L16(r3 - 4);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_802a21c0;
    ((void (*)(w3d_oarg))A802b1258)(W(r3));
L_802a21c0:
    r30 = r1 + 8;
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 224;
    return r3;
}

// 0x802a27f8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 802a21ec en 802a2814
__attribute__((weak)) w3d_u32 A802a27f8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r30 = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = r3;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802a0c48)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = r30;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802a21ec)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 16;
    return r3;
}

// 0x802a2e24 FUN_802a2e24 no verificada: desde bytes PPC
// Llama a base_construct, image_base_construct. Hace 1 llamada virtual.
// aviso: acceso absoluto 0 en 802a2e8c
__attribute__((weak)) w3d_u32 A802a2e24(w3d_u32 r3) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r30 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8015fef0)(W(r3));
    r3 = r31 + 28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A802afb20)(W(r3));
    r9 = D(0x803d0000u);
    S32(r31 + 228, r30);
    f0 = LF(D(0x803d2e04u));
    r11 = D(0x80420000u);
    r9 = D(0x80420000u);
    r3 = 0x0u;
    r11 = D(0x8041c3e0u);
    r9 = D(0x8041c430u);
    S32(r31 + 220, r30);
    cr0 = CMPS(r3, 0);
    S32(r31 + 224, r30);
    S32(r31 + 208, r11);
    S32(r31, r9);
    SF(r31 + 232, f0);
    S32(r31 + 212, r30);
    S32(r31 + 216, r30);
    if ((cr0 & 2)) goto L_802a2e9c;
    r9 = L32(0x0u);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802a2e9c:
    S32(r31 + 228, r30);
    r3 = r31;
    r1 = r1 + 16;
    return r3;
}

// 0x802a3030 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802a3030(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r3 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b0668)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x802abfdc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802abfdc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A80316270, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802af220 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802af220(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
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

// 0x802af254 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802af254(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
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

// 0x802b0970 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 802b222c en 802b097c
__attribute__((weak)) w3d_u32 A802b0970(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A802b222c)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x802b4378 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802b4378(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r3 + 28;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802b0668)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

}
