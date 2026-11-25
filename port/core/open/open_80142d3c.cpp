// Funciones del juego sin fuente admitida: 0x80142d3c a 0x80168d28. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A80007bf4();
__attribute__((weak)) void A8009ee18();
__attribute__((weak)) void A800fc710();
__attribute__((weak)) void A800fc7f8();
__attribute__((weak)) void A801190b4();
__attribute__((weak)) void A8014be44();
__attribute__((weak)) void A8014be84();
__attribute__((weak)) void A8014c260();
__attribute__((weak)) void A80155850();
__attribute__((weak)) void A8015b9d0();
__attribute__((weak)) void A8015e900();
__attribute__((weak)) void A8015f5a0();
__attribute__((weak)) void A8015fb34();
__attribute__((weak)) void A801613f0();
__attribute__((weak)) void A80161440();
__attribute__((weak)) void A8016239c();
__attribute__((weak)) void A80165254();
__attribute__((weak)) void A8016703c();
__attribute__((weak)) void A8016710c();
__attribute__((weak)) void A801680ec();
__attribute__((weak)) void A801685cc();
__attribute__((weak)) void A8016eed0();
__attribute__((weak)) void A80178474();
__attribute__((weak)) void A80178d1c();
__attribute__((weak)) void A80178d28();
__attribute__((weak)) void A80179598();
__attribute__((weak)) void A801a38c8();
__attribute__((weak)) void A801f76e0();
__attribute__((weak)) void A801fdfc8();
__attribute__((weak)) void A801fe2a8();
__attribute__((weak)) void A80206920();
__attribute__((weak)) void A8020b648();
__attribute__((weak)) void A8020bb2c();
__attribute__((weak)) void A80210afc();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A802cafd0();
__attribute__((weak)) void A802e82c0();
__attribute__((weak)) void A802eee50();
__attribute__((weak)) void A802fa988();
__attribute__((weak)) void A80302b60();
__attribute__((weak)) void A80302ec4();
__attribute__((weak)) void A80304b84();
__attribute__((weak)) void A80305374();
__attribute__((weak)) void A80307d88();
__attribute__((weak)) void A803080e0();
__attribute__((weak)) void A80308dc8();
__attribute__((weak)) void A80308e44();
__attribute__((weak)) void A80308ef4();
__attribute__((weak)) void A80309038();
__attribute__((weak)) void A80309240();
__attribute__((weak)) void A8030bacc();
__attribute__((weak)) void A8030bba0();
__attribute__((weak)) void A8030c264();
__attribute__((weak)) void A8030c2ac();
__attribute__((weak)) void A803413d8();
__attribute__((weak)) void A80341584();
__attribute__((weak)) void A80342a78();
__attribute__((weak)) void A80343740();
__attribute__((weak)) void A80347324();
__attribute__((weak)) void A8034a400();
__attribute__((weak)) void A8034aaf4();
__attribute__((weak)) void A8034ab10();
__attribute__((weak)) void A8034ad50();
__attribute__((weak)) void A8034b974();

// 0x80142d3c FUN_80142d3c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: shutdown. Llama a constructor_native_cast, update_value, sol35b8_control_allocate, cached_message_id, sol35b8_control_post. Hace 12 llamadas virtuales.
// aviso: lee r3 tras void 80178474 en 801431e0
__attribute__((weak)) w3d_u32 A80142d3c(w3d_u32 r3) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r27 = r1 + 8;
    r3 = L32(r29 + 1108);
    r31 = 0x0u;
    r28 = D(0x804b0000u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80342a78)(W(r3));
    r4 = r29 + 584;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80178d28)(W(r3), W(r4));
    r3 = L32(D(0x804b1754u));
    r4 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804afcc8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    r9 = D(0x80410000u);
    S16(r30, r3);
    r9 = D(0x8040db38u);
    r3 = r30;
    S32(r30 + 4, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
    S32(r1 + 8, r31);
    r0 = 0x0u;
    r0 = 0xe3a8u;
    r4 = r27;
    r3 = L32(r29 + 584);
    S32(r27 + 4, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc710)(W(r3), W(r4));
    r30 = r3;
    r9 = D(0x803a0000u);
    S32(r30 + 220, r31);
    r11 = r30 + 68;
    r10 = r30 + 56;
    r8 = r30 + 92;
    f31 = LF(D(0x803a0aa0u));
    r7 = r30 + 44;
    r9 = r30 + 32;
    r5 = D(0x803a0000u);
    SF(r30 + 68, f31);
    r0 = 0x3u;
    SF(r11 + 8, f31);
    r6 = 0x0u;
    SF(r11 + 4, f31);
    SF(r30 + 56, f31);
    SF(r10 + 8, f31);
    SF(r10 + 4, f31);
    SF(r30 + 92, f31);
    SF(r8 + 8, f31);
    SF(r8 + 4, f31);
    SF(r30 + 44, f31);
    SF(r7 + 8, f31);
    SF(r7 + 4, f31);
    SF(r30 + 32, f31);
    SF(r9 + 8, f31);
    SF(r9 + 4, f31);
    S32(r30 + 128, r31);
    SF(r30 + 124, f31);
    S32(r30 + 132, r31);
    f0 = LF(D(0x803a0aa4u));
    S32(r30 + 104, r0);
    S32(r30 + 112, r0);
    SF(r30 + 116, f0);
    S8(r30 + 212, r6);
    S32(r30 + 216, r31);
    S16(r30 + 170, r31);
    S32(r30 + 204, r31);
    S16(r30 + 168, r31);
    S32(r30 + 196, r31);
    S32(r30 + 136, r31);
    S32(r30 + 120, r31);
    S32(r30 + 208, r31);
    S32(r30 + 164, r31);
    S32(r30 + 160, r31);
    S32(r30 + 156, r31);
    r10 = L32(D(0x804b06a0u));
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r30 + 108);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80142eac;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_80142eac:
    r0 = L32(D(0x804b06a0u));
    S32(r30 + 108, r0);
    r10 = L32(D(0x804b06a0u));
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r30 + 152);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80142ee8;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_80142ee8:
    r9 = L32(D(0x804b06a0u));
    r11 = r30 + 20;
    S32(r30 + 200, r31);
    r0 = 0x1u;
    S32(r30 + 152, r9);
    SF(r30 + 20, f31);
    SF(r11 + 8, f31);
    SF(r11 + 4, f31);
    S32(r30 + 188, r0);
    S8(r30 + 179, r0);
    S8(r30 + 178, r0);
    S8(r30 + 172, r0);
    S8(r30 + 176, r0);
    S8(r30 + 175, r0);
    S8(r30 + 174, r0);
    S8(r30 + 173, r0);
    S8(r30 + 177, r0);
    S8(r30 + 246, r0);
    S8(r30 + 236, r0);
    S8(r30 + 245, r0);
    S8(r30 + 244, r0);
    S8(r30 + 243, r0);
    S8(r30 + 242, r0);
    S8(r30 + 266, r0);
    S8(r30 + 240, r0);
    S8(r30 + 239, r0);
    S8(r30 + 238, r0);
    S8(r30 + 237, r0);
    S8(r30 + 272, r0);
    S8(r30 + 235, r0);
    SF(r30 + 144, f31);
    S32(r30 + 192, r31);
    S32(r30 + 184, r31);
    SF(r30 + 148, f31);
    S32(r30 + 180, r31);
    S8(r30 + 234, r0);
    S32(r30 + 256, r0);
    S32(r30 + 248, r31);
    S8(r30 + 233, r0);
    S8(r30 + 232, r0);
    S8(r30 + 231, r0);
    S8(r30 + 230, r0);
    S8(r30 + 278, r0);
    S8(r30 + 228, r0);
    S8(r30 + 227, r0);
    S8(r30 + 226, r0);
    S8(r30 + 225, r0);
    S8(r30 + 271, r0);
    S8(r30 + 282, r0);
    S8(r30 + 281, r0);
    S8(r30 + 280, r0);
    S8(r30 + 279, r0);
    S8(r30 + 229, r0);
    S8(r30 + 277, r0);
    S8(r30 + 276, r0);
    S8(r30 + 275, r0);
    S8(r30 + 274, r0);
    S8(r30 + 273, r0);
    S8(r30 + 224, r0);
    S8(r30 + 252, r0);
    S8(r30 + 270, r0);
    S8(r30 + 269, r0);
    S8(r30 + 268, r0);
    S8(r30 + 267, r0);
    S8(r30 + 241, r0);
    S8(r30 + 265, r0);
    S8(r30 + 264, r0);
    S32(r30 + 260, r31);
    r0 = L32(r1 + 8);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8014300c;
    S32(r1 + 8, r31);
    S32(r27 + 4, r31);
L_8014300c:
    r3 = L32(D(0x804b1754u));
    r4 = 0xcu;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804afb50u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    r4 = r3 & 0xffffu;
    r5 = L32(r29 + 20);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A801190b4)(W(r3), W(r4), W(r5));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
    r9 = L32(D(0x804ab3e0u));
    r30 = r9 - 1;
    S32(D(0x804ab3e0u), r30);
    cr0 = CMPS(r30, 0);
    if (!(cr0 & 2)) goto L_80143170;
    r3 = L32(D(0x804afdd8u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8014306c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8014306c:
    r3 = L32(D(0x804afddcu));
    S32(D(0x804afdd8u), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8014308c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8014308c:
    r3 = L32(D(0x804afde0u));
    S32(D(0x804afddcu), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801430ac;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801430ac:
    r3 = L32(D(0x804afde4u));
    S32(D(0x804afde0u), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801430cc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801430cc:
    r3 = L32(D(0x804afde8u));
    S32(D(0x804afde4u), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801430ec;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801430ec:
    r3 = L32(D(0x804afdecu));
    S32(D(0x804afde8u), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8014310c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8014310c:
    r3 = L32(D(0x804afdf0u));
    S32(D(0x804afdecu), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8014312c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8014312c:
    r3 = L32(D(0x804afdf8u));
    S32(D(0x804afdf0u), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8014314c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8014314c:
    r3 = L32(D(0x804afdf4u));
    S32(D(0x804afdf8u), r30);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8014316c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8014316c:
    S32(D(0x804afdf4u), r30);
L_80143170:
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r31 = 0x0u;
    r3 = L32(r29 + 800);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80143194;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80143194:
    r3 = L32(r29 + 804);
    S32(r29 + 800, r31);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801431b4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801431b4:
    r3 = L32(r29 + 808);
    S32(r29 + 804, r31);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801431d4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801431d4:
    S32(r29 + 808, r31);
    r3 = r1 + 8;
    r4 = 0x2u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
    r1 = r1 + 56;
    return r3;
}

// 0x801431fc FUN_801431fc no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: command. Llama a sol35b8_control_allocate, cached_message_id, sol35b8_control_post, engine_get_context, worm_handle. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A801431fc(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[136];
    w3d_u32 r1 = h2g(frame) + 120;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 120; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r29 = r4;
    r3 = L32(D(0x804b1754u));
    r4 = 0x8u;
    r27 = 0x1u;
    r28 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804afc40u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    r9 = D(0x80410000u);
    S16(r30, r3);
    r26 = D(0x8040db38u);
    r3 = r30;
    S32(r30 + 4, r26);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
    r0 = L32(r29 + 8);
    S32(r31 + 304, r27);
    S32(r31 + 308, r0);
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = L32(r3 + 52);
    S32(r31 + 332, r0);
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = L32(r3 + 52);
    r4 = r31 + 560;
    r8 = L32(r31 + 560);
    r10 = r31 + 340;
    S32(r31 + 336, r0);
    r30 = r29 + 16;
    r5 = r1 + 8;
    r6 = r31 + 312;
    r0 = L32(r4 + 8);
    r11 = 0x0u;
    r9 = L32(r4 + 4);
    r7 = r1 + 24;
    S32(r31 + 340, r8);
    r11 = 0xe3a8u;
    S32(r10 + 8, r0);
    r12 = r5;
    S32(r10 + 4, r9);
    r25 = r7;
    f0 = LF(r29 + 16);
    f13 = LF(r30 + 4);
    f12 = LF(r30 + 8);
    SF(r1 + 8, f0);
    SF(r1 + 12, f13);
    SF(r1 + 16, f12);
    r0 = L32(r1 + 8);
    r8 = L32(r5 + 4);
    r10 = L32(r5 + 8);
    S32(r31 + 312, r0);
    S32(r6 + 4, r8);
    S32(r6 + 8, r10);
    S32(r1 + 24, r28);
    r0 = L32(r31 + 308);
    S32(r7 + 4, r11);
    cr0 = CMPS(r0, 7);
    if ((cr0 & 2)) goto L_801435ac;
    if ((cr0 & 4)) goto L_80143330;
    cr0 = CMPS(r0, 3);
    if ((cr0 & 2)) goto L_80143594;
    if ((cr0 & 4)) goto L_80143320;
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_80143368;
    if ((cr0 & 4)) goto L_80143660;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801433a8;
    goto L_80143770;
L_80143320:
    cr0 = CMPS(r0, 5);
    if ((cr0 & 2)) goto L_80143488;
    if ((cr0 & 4)) goto L_801434c8;
    goto L_801433b0;
L_80143330:
    cr0 = CMPS(r0, 13);
    if ((cr0 & 2)) goto L_80143660;
    if ((cr0 & 4)) goto L_80143348;
    cr0 = CMPS(r0, 11);
    if (!(cr0 & 4)) goto L_80143660;
    goto L_801435c4;
L_80143348:
    cr0 = CMPS(r0, 15);
    if ((cr0 & 2)) goto L_8014367c;
    if ((cr0 & 8)) goto L_80143660;
    cr0 = CMPS(r0, 16);
    if ((cr0 & 2)) goto L_801436a0;
    cr0 = CMPS(r0, 17);
    if ((cr0 & 2)) goto L_80143740;
    goto L_80143770;
L_80143368:
    r3 = L32(r31 + 584);
    r4 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc710)(W(r3), W(r4));
    r0 = L32(r29 + 12);
    r4 = 0x8u;
    S32(r3 + 132, r0);
    r3 = L32(D(0x804b1754u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804afbc8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r30, r3);
    S32(r30 + 4, r26);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
L_801433a8:
    S32(r31 + 304, r28);
    goto L_80143770;
L_801433b0:
    r9 = r31 + 312;
    r11 = r31 + 560;
    f8 = LF(r9 + 4);
    r10 = D(0x803a0000u);
    f9 = LF(r11 + 4);
    f10 = LF(r31 + 560);
    f1 = LF(r31 + 312);
    f13 = (float)(f8 - f9);
    f6 = LF(r9 + 8);
    f13 = (float)(f13 * f13);
    f7 = LF(r11 + 8);
    f0 = (float)(f1 - f10);
    f11 = LF(D(0x803a0e08u));
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f13);
    f12 = (float)(f6 - f7);
    f12 = __builtin_fmaf((float)f12, (float)f12, (float)f0);
    cr0 = CMPF(f12, f11);
    if (!(cr0 & 8)) goto L_80143434;
    r3 = L32(D(0x804b1754u));
    r4 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804ac9d4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    r9 = D(0x80410000u);
    S16(r30, r3);
    r9 = D(0x8040db38u);
    r3 = r30;
    S32(r30 + 4, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
    ((void (*)())A80007bf4)();
    goto L_80143770;
L_80143434:
    f0 = (float)(f8 - f9);
    f1 = (float)(f1 - f10);
    f0 = (float)(f0 * f0);
    f13 = (float)(f6 - f7);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r3 = L32(D(0x804b1754u));
    r4 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804afc90u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    r9 = D(0x80410000u);
    S16(r30, r3);
    r9 = D(0x8040db38u);
    r3 = r30;
    S32(r30 + 4, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
    goto L_80143770;
L_80143488:
    f9 = LF(r31 + 560);
    f12 = LF(r6 + 8);
    f11 = LF(r4 + 8);
    f0 = LF(r31 + 312);
    f13 = LF(r6 + 4);
    f12 = (float)(f12 - f11);
    f10 = LF(r4 + 4);
    f0 = (float)(f0 - f9);
    SF(r1 + 8, f0);
    f13 = (float)(f13 - f10);
    SF(r1 + 16, f12);
    SF(r1 + 12, f13);
    SF(r1 + 32, f0);
    SF(r1 + 36, f13);
    SF(r1 + 40, f12);
    goto L_80143770;
L_801434c8:
    f12 = LF(r4 + 4);
    r10 = 0x5u;
    f13 = LF(r4 + 8);
    f0 = LF(r31 + 560);
    f12 = (float)(f12 + f12);
    f13 = (float)(f13 + f13);
    SF(r1 + 52, f12);
    f0 = (float)(f0 + f0);
    SF(r1 + 56, f13);
    SF(r1 + 48, f0);
    SF(r1 + 32, f0);
    SF(r1 + 36, f12);
    SF(r1 + 40, f13);
    f10 = LF(r29 + 16);
    f11 = LF(r30 + 4);
    f9 = LF(r30 + 8);
    f0 = (float)(f0 - f10);
    SF(r1 + 8, f0);
    f12 = (float)(f12 - f11);
    f13 = (float)(f13 - f9);
    SF(r1 + 12, f12);
    SF(r1 + 16, f13);
    SF(r1 + 48, f10);
    SF(r1 + 52, f11);
    SF(r1 + 56, f9);
    SF(r1 + 64, f0);
    SF(r1 + 68, f12);
    SF(r1 + 72, f13);
    r9 = L32(r1 + 8);
    r11 = L32(r5 + 8);
    r0 = L32(r5 + 4);
    S32(r31 + 312, r9);
    S32(r6 + 4, r0);
    S32(r6 + 8, r11);
    S32(r31 + 308, r10);
    f11 = LF(r31 + 560);
    f13 = LF(r31 + 312);
    f0 = LF(r4 + 4);
    f12 = LF(r6 + 4);
    f13 = (float)(f13 - f11);
    SF(r1 + 32, f13);
    f12 = (float)(f12 - f0);
    SF(r1 + 36, f12);
    f0 = LF(r6 + 8);
    f11 = LF(r4 + 8);
    SF(r1 + 8, f13);
    f0 = (float)(f0 - f11);
    SF(r1 + 12, f12);
    SF(r1 + 16, f0);
    SF(r1 + 40, f0);
    goto L_80143770;
L_80143594:
    r3 = L32(r31 + 584);
    r4 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc710)(W(r3), W(r4));
    f0 = LF(r29 + 40);
    SF(r3 + 116, f0);
    goto L_801433a8;
L_801435ac:
    r3 = L32(r29 + 44);
    S32(r31 + 324, r3);
    f0 = LF(r29 + 48);
    SF(r31 + 328, f0);
    r3 = A80015564(r3);
    goto L_80143770;
L_801435c4:
    r0 = L32(r31 + 388);
    r4 = r29 + 52;
    r11 = r31 + 352;
    r10 = 0xa8u;
    S32(r1 + 80, r0);
    r8 = r31 + 312;
L_801435dc:
    r9 = L32(r4);
    { w3d_u32 t_ = r10; r10 = t_ + (w3d_u32)-24; ca = r10 < t_; cr0 = CMPS(r10, 0); }
    S32(r11, r9);
    r9 = L32(r4 + 4);
    S32(r11 + 4, r9);
    r9 = L32(r4 + 8);
    S32(r11 + 8, r9);
    r9 = L32(r4 + 12);
    S32(r11 + 12, r9);
    r9 = L32(r4 + 16);
    S32(r11 + 16, r9);
    r9 = L32(r4 + 20);
    r4 = r4 + 24;
    S32(r11 + 20, r9);
    r11 = r11 + 24;
    if (!(cr0 & 2)) goto L_801435dc;
    r9 = L32(r4);
    r0 = L32(r1 + 80);
    S32(r11, r9);
    r9 = L32(r4 + 4);
    S32(r11 + 4, r9);
    r9 = L32(r4 + 8);
    S32(r11 + 8, r9);
    r9 = L32(r4 + 12);
    S32(r11 + 12, r9);
    S32(r31 + 388, r0);
    f12 = LF(r31 + 312);
    f0 = LF(r8 + 8);
    f13 = LF(r8 + 4);
    SF(r12 + 8, f0);
    SF(r1 + 8, f12);
    SF(r12 + 4, f13);
    goto L_80143770;
L_80143660:
    f0 = LF(r31 + 312);
    f13 = LF(r6 + 8);
    f12 = LF(r6 + 4);
    SF(r1 + 8, f0);
    SF(r5 + 8, f13);
    SF(r5 + 4, f12);
    goto L_80143770;
L_8014367c:
    r0 = L32(r31 + 312);
    r9 = D(0x80450000u);
    r11 = D(0x80448c90u);
    S32(D(0x804aaefcu), r28);
    S32(D(0x80448c90u), r0);
    S32(D(0x80448c98u), r10);
    S32(D(0x804aaef8u), r27);
    S32(D(0x80448c94u), r8);
    goto L_80143770;
L_801436a0:
    r0 = L32(r31 + 312);
    r9 = D(0x80450000u);
    r11 = D(0x80448c90u);
    S32(D(0x804aaefcu), r28);
    S32(D(0x80448c90u), r0);
    r4 = r29 + 52;
    S32(D(0x80448c98u), r10);
    S32(D(0x80448c94u), r8);
    r10 = r31 + 352;
    S32(D(0x804aaef8u), r27);
    r11 = 0xa8u;
    r0 = L32(r31 + 388);
    S32(r1 + 80, r0);
L_801436d4:
    r9 = L32(r4);
    { w3d_u32 t_ = r11; r11 = t_ + (w3d_u32)-24; ca = r11 < t_; cr0 = CMPS(r11, 0); }
    S32(r10, r9);
    r9 = L32(r4 + 4);
    S32(r10 + 4, r9);
    r9 = L32(r4 + 8);
    S32(r10 + 8, r9);
    r9 = L32(r4 + 12);
    S32(r10 + 12, r9);
    r9 = L32(r4 + 16);
    S32(r10 + 16, r9);
    r9 = L32(r4 + 20);
    r4 = r4 + 24;
    S32(r10 + 20, r9);
    r10 = r10 + 24;
    if (!(cr0 & 2)) goto L_801436d4;
    r9 = L32(r4);
    r0 = L32(r1 + 80);
    S32(r10, r9);
    r9 = L32(r4 + 4);
    S32(r10 + 4, r9);
    r9 = L32(r4 + 8);
    S32(r10 + 8, r9);
    r9 = L32(r4 + 12);
    S32(r10 + 12, r9);
    S32(r31 + 388, r0);
    goto L_80143770;
L_80143740:
    S32(r31 + 304, r28);
    r4 = 0x8u;
    r3 = L32(D(0x804b1754u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804afbf0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    S16(r30, r3);
    S32(r30 + 4, r26);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
L_80143770:
    r3 = r25;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
    r3 = 0x0u;
    r1 = r1 + 120;
    return r3;
}

// 0x8014b8ec FUN_8014b8ec no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: motion. Llama a direction_of__FP16d24d_JetpackWorm, sqrt, point_init, permute, inverse. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8014b8ec(w3d_u32 r3, w3d_u32 r4, float s1) {
    alignas(16) char frame[600];
    w3d_u32 r1 = h2g(frame) + 584;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 584; S32(t_, r1); r1 = t_; }
    r27 = r3;
    r26 = r4;
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, float))A8014c260)(W(r3), W(r4), (float)f1);
    r9 = D(0x803a0000u);
    r11 = r1 + 24;
    f30 = LF(D(0x803a1464u));
    r10 = r1 + 8;
    SF(r1 + 24, f30);
    SF(r11 + 8, f30);
    SF(r11 + 4, f30);
    f0 = LF(r10 + 4);
    f1 = LF(r1 + 8);
    f0 = (float)(f0 * f0);
    f13 = LF(r10 + 8);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f0 = LF(r1 + 8);
    f29 = f1;
    cr0 = CMPF(f0, f30);
    if (!(cr0 & 2)) goto L_8014b96c;
    f0 = LF(r1 + 16);
    cr0 = CMPF(f0, f30);
    if ((cr0 & 2)) goto L_8014bdf8;
L_8014b96c:
    r30 = r1 + 272;
    r3 = r1 + 260;
    ((void (*)())A80343740)();
    r9 = D(0x803a0000u);
    r11 = r1 + 40;
    f0 = LF(D(0x803a1468u));
    r29 = r1 + 336;
    SF(r1 + 40, f30);
    r31 = r1 + 464;
    r28 = r1 + 384;
    SF(r11 + 8, f0);
    SF(r11 + 4, f30);
    r4 = r30;
    r3 = r26;
    ((void (*)(w3d_oarg, w3d_oarg))A8014be44)(W(r3), W(r4));
    r3 = r1 + 372;
    ((void (*)())A80343740)();
    f13 = LF(r1 + 272);
    r9 = r1 + 372;
    r3 = r1 + 420;
    SF(r1 + 336, f13);
    f0 = LF(r30 + 4);
    SF(r29 + 4, f0);
    f13 = LF(r30 + 8);
    SF(r29 + 8, f13);
    f0 = LF(r30 + 16);
    SF(r29 + 12, f0);
    f13 = LF(r30 + 20);
    SF(r29 + 16, f13);
    f0 = LF(r30 + 24);
    SF(r29 + 20, f0);
    f13 = LF(r30 + 32);
    SF(r29 + 24, f13);
    f0 = LF(r30 + 36);
    SF(r29 + 28, f0);
    f13 = LF(r30 + 40);
    SF(r29 + 32, f13);
    f0 = LF(r30 + 48);
    SF(r1 + 372, f0);
    f13 = LF(r30 + 52);
    SF(r9 + 4, f13);
    f0 = LF(r30 + 56);
    SF(r9 + 8, f0);
    ((void (*)())A80343740)();
    r4 = r29;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801f76e0)(W(r3), W(r4));
    r9 = D(0x803a0000u);
    SF(r1 + 464, f30);
    f0 = LF(D(0x803a146cu));
    r6 = r1 + 420;
    SF(r31 + 4, f30);
    r5 = r1 + 396;
    SF(r31 + 8, f0);
    r4 = r1 + 408;
    r11 = D(0x803a0000u);
    r10 = r1 + 104;
    f9 = LF(r1 + 468);
    r8 = r1 + 88;
    f13 = LF(r1 + 396);
    r3 = r1 + 72;
    f8 = LF(r1 + 464);
    r7 = D(0x803a0000u);
    f12 = LF(r1 + 384);
    f13 = (float)(f9 * f13);
    f11 = LF(r1 + 472);
    f0 = LF(r1 + 408);
    f12 = __builtin_fmaf((float)f8, (float)f12, (float)f13);
    f10 = LF(r1 + 420);
    f0 = __builtin_fmaf((float)f11, (float)f0, (float)f12);
    f7 = LF(r6 + 4);
    f6 = LF(r6 + 8);
    f0 = (float)(f0 + f10);
    SF(r1 + 432, f0);
    f5 = LF(D(0x803a1470u));
    f13 = LF(r5 + 4);
    f12 = LF(r28 + 4);
    f0 = LF(r4 + 4);
    f13 = (float)(f9 * f13);
    f12 = __builtin_fmaf((float)f8, (float)f12, (float)f13);
    f0 = __builtin_fmaf((float)f11, (float)f0, (float)f12);
    f0 = (float)(f0 + f7);
    SF(r1 + 436, f0);
    f13 = LF(r5 + 8);
    f0 = LF(r28 + 8);
    f12 = LF(r4 + 8);
    f9 = (float)(f9 * f13);
    f8 = __builtin_fmaf((float)f8, (float)f0, (float)f9);
    SF(r1 + 464, f5);
    f11 = __builtin_fmaf((float)f11, (float)f12, (float)f8);
    SF(r1 + 436, f30);
    f11 = (float)(f11 + f6);
    SF(r1 + 440, f11);
    SF(r31 + 4, f30);
    SF(r31 + 8, f30);
    f9 = LF(r1 + 468);
    f13 = LF(r1 + 396);
    f8 = LF(r1 + 464);
    f12 = LF(r1 + 384);
    f13 = (float)(f9 * f13);
    f10 = LF(r1 + 472);
    f0 = LF(r1 + 408);
    f12 = __builtin_fmaf((float)f8, (float)f12, (float)f13);
    f11 = LF(r1 + 420);
    f0 = __builtin_fmaf((float)f10, (float)f0, (float)f12);
    f0 = (float)(f0 + f11);
    SF(r1 + 448, f0);
    f13 = LF(r5 + 4);
    f12 = LF(r28 + 4);
    f0 = LF(r4 + 4);
    f13 = (float)(f9 * f13);
    f11 = LF(r6 + 4);
    f12 = __builtin_fmaf((float)f8, (float)f12, (float)f13);
    f0 = __builtin_fmaf((float)f10, (float)f0, (float)f12);
    f7 = LF(r6 + 8);
    f0 = (float)(f0 + f11);
    r9 = L32(r1 + 420);
    SF(r1 + 452, f0);
    f0 = LF(r5 + 8);
    f13 = LF(r28 + 8);
    f12 = LF(r4 + 8);
    f9 = (float)(f9 * f0);
    f8 = __builtin_fmaf((float)f8, (float)f13, (float)f9);
    r11 = L32(r6 + 4);
    f10 = __builtin_fmaf((float)f10, (float)f12, (float)f8);
    r0 = L32(r6 + 8);
    f10 = (float)(f10 + f7);
    S32(r1 + 104, r9);
    SF(r1 + 456, f10);
    SF(r1 + 452, f30);
    S32(r10 + 8, r0);
    S32(r10 + 4, r11);
    SF(r1 + 108, f30);
    f11 = LF(r1 + 104);
    f12 = LF(r1 + 448);
    f10 = LF(r1 + 112);
    f0 = LF(r1 + 452);
    f12 = (float)(f12 - f11);
    f13 = LF(r1 + 456);
    SF(r1 + 464, f12);
    f0 = (float)(f0 - f30);
    f13 = (float)(f13 - f10);
    SF(r1 + 468, f0);
    SF(r1 + 472, f13);
    SF(r1 + 480, f12);
    SF(r1 + 484, f0);
    SF(r1 + 488, f13);
    r9 = L32(r1 + 464);
    r11 = L32(r31 + 8);
    r0 = L32(r31 + 4);
    S32(r1 + 88, r9);
    S32(r8 + 4, r0);
    S32(r8 + 8, r11);
    f9 = LF(D(0x803a1474u));
    f11 = LF(r1 + 104);
    f12 = LF(r1 + 432);
    f13 = LF(r1 + 436);
    f12 = (float)(f12 - f11);
    f10 = LF(r1 + 108);
    f0 = LF(r1 + 440);
    f11 = LF(r1 + 112);
    f13 = (float)(f13 - f10);
    SF(r1 + 464, f12);
    f0 = (float)(f0 - f11);
    SF(r1 + 468, f13);
    SF(r1 + 472, f0);
    SF(r1 + 496, f12);
    SF(r1 + 500, f13);
    SF(r1 + 504, f0);
    r0 = L32(r1 + 464);
    r9 = L32(r31 + 4);
    r11 = L32(r31 + 8);
    S32(r1 + 72, r0);
    S32(r3 + 4, r9);
    S32(r3 + 8, r11);
    f13 = LF(r1 + 76);
    f12 = LF(r1 + 72);
    f13 = (float)(f13 * f13);
    f0 = LF(r1 + 80);
    f12 = __builtin_fmaf((float)f12, (float)f12, (float)f13);
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f12);
    cr0 = CMPF(f0, f9);
    if (!(cr0 & 8)) goto L_8014bd18;
    SF(r1 + 464, f30);
    SF(r31 + 4, f5);
    SF(r31 + 8, f30);
    f7 = LF(r1 + 468);
    f0 = LF(r1 + 396);
    f6 = LF(r1 + 464);
    f13 = LF(r1 + 384);
    f0 = (float)(f7 * f0);
    f10 = LF(r1 + 472);
    f11 = LF(r1 + 408);
    f13 = __builtin_fmaf((float)f6, (float)f13, (float)f0);
    f12 = LF(r1 + 420);
    f11 = __builtin_fmaf((float)f10, (float)f11, (float)f13);
    f5 = LF(r6 + 4);
    f4 = LF(r6 + 8);
    f11 = (float)(f11 + f12);
    SF(r1 + 432, f11);
    f0 = LF(r1 + 104);
    f13 = LF(r5 + 4);
    f12 = LF(r28 + 4);
    f11 = (float)(f11 - f0);
    f0 = LF(r4 + 4);
    f13 = (float)(f7 * f13);
    f12 = __builtin_fmaf((float)f6, (float)f12, (float)f13);
    f8 = LF(r1 + 108);
    f0 = __builtin_fmaf((float)f10, (float)f0, (float)f12);
    f9 = LF(r1 + 112);
    f0 = (float)(f0 + f5);
    SF(r1 + 436, f0);
    f8 = (float)(f30 - f8);
    f0 = LF(r5 + 8);
    f13 = LF(r28 + 8);
    f12 = LF(r4 + 8);
    f7 = (float)(f7 * f0);
    f6 = __builtin_fmaf((float)f6, (float)f13, (float)f7);
    SF(r1 + 464, f11);
    f10 = __builtin_fmaf((float)f10, (float)f12, (float)f6);
    SF(r1 + 468, f8);
    f10 = (float)(f10 + f4);
    SF(r1 + 436, f30);
    f9 = (float)(f10 - f9);
    SF(r1 + 440, f10);
    SF(r1 + 472, f9);
    SF(r1 + 480, f11);
    SF(r1 + 484, f8);
    SF(r1 + 488, f9);
    r9 = L32(r1 + 464);
    r11 = L32(r31 + 4);
    r0 = L32(r31 + 8);
    S32(r1 + 72, r9);
    S32(r3 + 8, r0);
    S32(r3 + 4, r11);
L_8014bd18:
    f0 = LF(r1 + 76);
    f1 = LF(r1 + 72);
    f13 = LF(r1 + 80);
    f0 = (float)(f0 * f0);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x803a0000u);
    f13 = LF(r1 + 92);
    f31 = LF(D(0x803a1478u));
    f10 = LF(r1 + 72);
    f13 = (float)(f13 * f13);
    f12 = (float)(f31 / f1);
    f11 = LF(r1 + 76);
    f0 = LF(r1 + 80);
    f1 = LF(r1 + 88);
    f9 = LF(r1 + 96);
    f0 = (float)(f0 * f12);
    f10 = (float)(f10 * f12);
    SF(r1 + 80, f0);
    f11 = (float)(f11 * f12);
    SF(r1 + 72, f10);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f13);
    SF(r1 + 76, f11);
    f1 = __builtin_fmaf((float)f9, (float)f9, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f31 = (float)(f31 / f1);
    f0 = LF(r1 + 96);
    f11 = LF(r1 + 16);
    r4 = r26;
    f12 = LF(r1 + 80);
    r5 = r31;
    f9 = LF(r1 + 88);
    r3 = r27;
    f13 = LF(r1 + 8);
    f8 = LF(r1 + 72);
    f10 = LF(r1 + 92);
    SF(r1 + 468, f30);
    SF(r1 + 28, f30);
    f0 = (float)(f0 * f31);
    f12 = (float)(f11 * f12);
    SF(r1 + 96, f0);
    f0 = __builtin_fmaf((float)f13, (float)f0, (float)f12);
    f9 = (float)(f9 * f31);
    SF(r1 + 472, f0);
    f11 = (float)(f11 * f8);
    SF(r1 + 88, f9);
    f13 = __builtin_fmaf((float)f13, (float)f9, (float)f11);
    SF(r1 + 32, f0);
    f10 = (float)(f10 * f31);
    SF(r1 + 464, f13);
    SF(r1 + 92, f10);
    f1 = f29;
    SF(r1 + 24, f13);
    w3d_open_sret((void *)A8014be84, W(r3), W(r4), W(r5), 0, 0, 0, 0, (float)f1, (float)f2, (float)f3, (float)f4, (float)f5, (float)f6, (float)f7, (float)f8);
    goto L_8014be20;
L_8014bdf8:
    SF(r1 + 40, f30);
    r9 = r1 + 40;
    SF(r9 + 8, f30);
    SF(r9 + 4, f30);
    f0 = LF(r1 + 40);
    f13 = LF(r1 + 44);
    f12 = LF(r1 + 48);
    SF(r27, f0);
    SF(r27 + 4, f13);
    SF(r27 + 8, f12);
L_8014be20:
    r3 = r27;
    r1 = r1 + 584;
    return r3;
}

// 0x8014cd48 FUN_8014cd48 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: step. Llama a constructor_native_cast, sol35b9_power_value, quadratic_roots. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8014cd48(w3d_u32 r3) {
    alignas(16) char frame[264];
    w3d_u32 r1 = h2g(frame) + 248;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f31 = 0;
    w3d_u32 cr0 = 0, ctr = 0;
    { w3d_u32 t_ = r1 - 248; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804ab400u));
    r25 = r3;
    r3 = L32(r9 + 32);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80342a78)(W(r3));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80178d1c)(W(r3));
    r0 = L32(r25 + 584);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_8014d1b4;
    r9 = D(0x803a0000u);
    r11 = D(0x803a0000u);
    f11 = LF(D(0x803a1600u));
    r10 = r1 + 56;
    f0 = LF(D(0x803a1604u));
    r8 = r25 + 560;
    SF(r1 + 56, f11);
    r9 = D(0x803a0000u);
    SF(r10 + 4, f0);
    r31 = r1 + 40;
    SF(r10 + 8, f11);
    r27 = r1 + 8;
    f8 = LF(D(0x803a1608u));
    r4 = D(0x80450000u);
    f10 = LF(r25 + 560);
    r5 = D(0x804522ecu);
    f12 = LF(r1 + 56);
    r30 = D(0x80400000u);
    f0 = LF(r1 + 60);
    r3 = r1 + 24;
    f12 = (float)(f10 - f12);
    f9 = LF(r1 + 64);
    SF(r1 + 72, f12);
    r7 = D(0x803fde84u);
    r29 = 0x43300000u;
    f13 = LF(r8 + 4);
    r26 = r1 + 104;
    r28 = D(0x803a0000u);
    r24 = r31;
    f13 = (float)(f13 - f0);
    r23 = r26;
    SF(r1 + 76, f13);
    f0 = LF(r8 + 8);
    SF(r1 + 40, f12);
    f0 = (float)(f0 - f9);
    SF(r1 + 44, f13);
    SF(r1 + 48, f0);
    SF(r1 + 80, f0);
    r0 = L32(r1 + 40);
    r9 = L32(r31 + 4);
    r11 = L32(r31 + 8);
    S32(r1 + 8, r0);
    S32(r27 + 4, r9);
    S32(r27 + 8, r11);
    SF(r1 + 56, f11);
    SF(r10 + 8, f11);
    SF(r10 + 4, f8);
    f0 = LF(r1 + 56);
    f12 = LF(r1 + 60);
    f10 = (float)(f10 + f0);
    f11 = LF(r1 + 64);
    SF(r1 + 88, f10);
    f13 = LF(r8 + 4);
    f13 = (float)(f13 + f12);
    SF(r1 + 92, f13);
    f0 = LF(r8 + 8);
    f0 = (float)(f0 + f11);
    SF(r1 + 96, f0);
    f11 = LF(D(0x804522f4u));
    f12 = LF(D(0x804522f0u));
    SF(r1 + 40, f10);
    SF(r1 + 44, f13);
    SF(r1 + 48, f0);
    r0 = L32(r1 + 40);
    r9 = L32(r31 + 8);
    r10 = L32(r31 + 4);
    S32(r1 + 24, r0);
    f1 = LF(D(0x804522ecu));
    r11 = L32(D(0x804b1870u));
    r8 = L32(D(0x803fde84u));
    S32(r3 + 8, r9);
    S32(r3 + 4, r10);
    S32(r1 + 196, r11);
    r11 = L16(D(0x803fde90u));
    r0 = L32(D(0x803fde88u));
    r9 = L32(D(0x803fde8cu));
    S32(r1 + 104, r8);
    S32(r1 + 192, r29);
    S32(r26 + 4, r0);
    S32(r26 + 8, r9);
    S16(r26 + 12, r11);
    f0 = LDS(r1 + 192);
    f13 = LD(D(0x803a1610u));
    f10 = LF(r1 + 8);
    f0 = f0 - f13;
    SF(r1 + 120, f1);
    cr0 = CMPF(f1, f10);
    SF(r1 + 124, f12);
    f31 = (float)f0;
    SF(r1 + 128, f11);
    SF(r1 + 136, f1);
    SF(r1 + 140, f12);
    SF(r1 + 144, f11);
    SF(r1 + 152, f1);
    SF(r1 + 156, f12);
    SF(r1 + 160, f11);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014cf10;
    r0 = L8(r1 + 168);
    r0 = r0 | 0x1u;
    S8(r1 + 168, r0);
L_8014cf10:
    f0 = LF(r27 + 4);
    cr0 = CMPF(f12, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014cf2c;
    r0 = L8(r1 + 168);
    r0 = r0 | 0x20u;
    S8(r1 + 168, r0);
L_8014cf2c:
    f0 = LF(r27 + 8);
    cr0 = CMPF(f11, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014cf48;
    r0 = L8(r1 + 168);
    r0 = r0 | 0x4u;
    S8(r1 + 168, r0);
L_8014cf48:
    f0 = LF(r1 + 24);
    cr0 = CMPF(f1, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014cf64;
    r0 = L8(r1 + 168);
    r0 = r0 | 0x2u;
    S8(r1 + 168, r0);
L_8014cf64:
    f0 = LF(r1 + 28);
    cr0 = CMPF(f12, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014cf80;
    r0 = L8(r1 + 168);
    r0 = r0 | 0x10u;
    S8(r1 + 168, r0);
L_8014cf80:
    f0 = LF(r1 + 32);
    cr0 = CMPF(f11, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014cf9c;
    r0 = L8(r1 + 168);
    r0 = r0 | 0x8u;
    S8(r1 + 168, r0);
L_8014cf9c:
    f2 = f1;
    r3 = r1 + 44;
    f1 = (float)(f1 - f10);
    f3 = f2;
    f1 = ((float (*)(w3d_oarg, float, float, float))A8009ee18)(W(r3), (float)f1, (float)f2, (float)f3);
    SF(r1 + 40, f1);
    r3 = r1 + 52;
    f0 = LF(r1 + 124);
    f1 = LF(r27 + 4);
    f2 = LF(r1 + 140);
    f3 = LF(r1 + 156);
    f1 = (float)(f0 - f1);
    f1 = ((float (*)(w3d_oarg, float, float, float))A8009ee18)(W(r3), (float)f1, (float)f2, (float)f3);
    SF(r1 + 48, f1);
    r3 = r1 + 60;
    f0 = LF(r1 + 128);
    f1 = LF(r27 + 8);
    f2 = LF(r1 + 144);
    f3 = LF(r1 + 160);
    f1 = (float)(f0 - f1);
    f1 = ((float (*)(w3d_oarg, float, float, float))A8009ee18)(W(r3), (float)f1, (float)f2, (float)f3);
    f13 = LF(r1 + 120);
    r3 = r1 + 68;
    f0 = LF(r1 + 24);
    SF(r1 + 56, f1);
    f2 = LF(r1 + 136);
    f1 = (float)(f13 - f0);
    f3 = LF(r1 + 152);
    f1 = ((float (*)(w3d_oarg, float, float, float))A8009ee18)(W(r3), (float)f1, (float)f2, (float)f3);
    f13 = LF(r1 + 124);
    r3 = r1 + 76;
    f0 = LF(r1 + 28);
    SF(r1 + 64, f1);
    f2 = LF(r1 + 140);
    f1 = (float)(f13 - f0);
    f3 = LF(r1 + 156);
    f1 = ((float (*)(w3d_oarg, float, float, float))A8009ee18)(W(r3), (float)f1, (float)f2, (float)f3);
    f13 = LF(r1 + 128);
    r3 = r1 + 84;
    f0 = LF(r1 + 32);
    SF(r1 + 72, f1);
    f2 = LF(r1 + 144);
    f1 = (float)(f13 - f0);
    f3 = LF(r1 + 160);
    f1 = ((float (*)(w3d_oarg, float, float, float))A8009ee18)(W(r3), (float)f1, (float)f2, (float)f3);
    SF(r1 + 80, f1);
    SF(r1 + 88, f31);
L_8014d058:
    r0 = 0xcu;
    r8 = 0x1u;
    ctr = r0;
    r10 = r26;
    r11 = r31;
L_8014d06c:
    f13 = LF(r11);
    f0 = LF(r11 + 4);
    cr0 = CMPF(f13, f0);
    if (!(cr0 & 4)) goto L_8014d098;
    SF(r11, f0);
    r8 = 0x0u;
    SF(r11 + 4, f13);
    r0 = L8(r10);
    r9 = L8(r10 + 1);
    S8(r10 + 1, r0);
    S8(r10, r9);
L_8014d098:
    r10 = r10 + 1;
    r11 = r11 + 4;
    --ctr; if (ctr != 0) goto L_8014d06c;
    cr0 = CMPS(r8, 0);
    if ((cr0 & 2)) goto L_8014d058;
    r9 = D(0x803a0000u);
    r5 = 0x0u;
    f13 = LF(D(0x803a1604u));
    f0 = LF(r24 + r5);
    cr0 = CMPF(f0, f13);
    if (!(cr0 & 8)) goto L_8014d0dc;
    f12 = f13;
    r9 = r24;
L_8014d0cc:
    { w3d_u32 t_ = r9 + 4; f0 = LF(t_); r9 = t_; }
    r5 = r5 + 1;
    cr0 = CMPF(f0, f12);
    if ((cr0 & 8)) goto L_8014d0cc;
L_8014d0dc:
    cr0 = CMPF(f13, f31);
    if (!(cr0 & 8)) goto L_8014d1b4;
    r31 = r24;
    r3 = r23;
    r6 = r5 << 2;
L_8014d0f0:
    r0 = L8(r1 + 168);
    cr0 = CMPS(r0, 63);
    if (!(cr0 & 2)) goto L_8014d128;
    f0 = f13;
    f13 = FCTIWZ(f0);
    r0 = L32(D(0x804b1874u));
    SDS(r1 + 192, f13);
    r9 = L32(r1 + 196);
    cr0 = CMPU(r0, r9);
    if ((cr0 & 8)) goto L_8014d128;
    r0 = L32(r25 + 584);
    S32(D(0x804b1870u), r9);
    S32(D(0x804b187cu), r0);
    S32(D(0x804b1874u), r9);
L_8014d128:
    r9 = L8(r3 + r5);
    r10 = r31;
    r0 = L8(r1 + 168);
    r5 = r5 + 1;
    f13 = LF(r6 + r10);
    r0 = r0 ^ r9;
    r6 = r6 + 4;
    S8(r1 + 168, r0);
    f0 = LF(r6 + r10);
    cr0 = CMPF(f13, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014d1ac;
    cr0 = CMPS(r5, 13);
    if ((cr0 & 2)) goto L_8014d1ac;
    r8 = r5 << 2;
    r4 = r23;
    r7 = r8;
L_8014d16c:
    r9 = L8(r4 + r5);
    r11 = r10;
    r0 = L8(r1 + 168);
    r8 = r8 + 4;
    f13 = LF(r10 + r7);
    r6 = r6 + 4;
    r0 = r0 ^ r9;
    r7 = r7 + 4;
    S8(r1 + 168, r0);
    r5 = r5 + 1;
    f0 = LF(r11 + r8);
    cr0 = CMPF(f13, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8014d1ac;
    cr0 = CMPS(r5, 13);
    if (!(cr0 & 2)) goto L_8014d16c;
L_8014d1ac:
    cr0 = CMPF(f13, f31);
    if ((cr0 & 8)) goto L_8014d0f0;
L_8014d1b4:
    r1 = r1 + 248;
    return r3;
}

// 0x80156214 FUN_80156214 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: turns_begin. Llama a resource_property, destroy_owned, resource_identity, settings_get, native_forward_copy. Hace 7 llamadas virtuales. Usa las cadenas "GM.GameInitData".
__attribute__((weak)) w3d_u32 A80156214(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[160];
    w3d_u32 r1 = h2g(frame) + 144;
    w3d_u32 r0 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 144; S32(t_, r1); r1 = t_; }
    r30 = 0x0u;
    r0 = 0x0u;
    r11 = r1 + 16;
    S32(r1 + 8, r30);
    S32(r1 + 16, r30);
    r0 = 0xe3a8u;
    r9 = D(0x803a0000u);
    S32(r11 + 4, r0);
    r9 = D(0x803a2aa4u);
    r31 = r3;
    r24 = r11;
    S32(r1 + 56, r9);
    r3 = r1 + 56;
    r4 = r1 + 8;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 8)) goto L_80156294;
    r3 = r24;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801565d0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_801565d0;
L_80156294:
    r3 = L32(r1 + 8);
    S32(r1 + 24, r30);
    ((void (*)())A80341584)();
    r4 = r24;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80179598)(W(r3), W(r4));
    S32(r1 + 32, r3);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801562c4;
    r9 = L32(r3);
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801562c4:
    r30 = L32(r1 + 32);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80156304;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80156300;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80156300:
    S32(r1 + 24, r30);
L_80156304:
    r3 = L32(r1 + 32);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80156320;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80156320:
    r11 = L32(r1 + 24);
    r29 = r31 + 100;
    r10 = L32(r31 + 100);
    r23 = r1 + 40;
    r0 = L32(r11 + 80);
    r5 = 0x0u;
    r3 = r10;
    r28 = r31 + 112;
    S32(r1 + 40, r0);
    r27 = r31 + 124;
    r26 = r31 + 136;
    r25 = 0x0u;
    r0 = L32(r11 + 76);
    S32(r1 + 44, r0);
    r9 = L32(r11 + 72);
    S32(r1 + 48, r9);
    r0 = L32(r11 + 68);
    S32(r1 + 52, r0);
    r30 = L32(r29 + 4);
    r4 = r30;
    r30 = r30 - r10;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r29 + 4);
    r5 = 0x0u;
    r0 = r0 - r30;
    S32(r29 + 4, r0);
    r30 = L32(r28 + 4);
    r9 = L32(r31 + 112);
    r4 = r30;
    r30 = r30 - r9;
    r3 = r9;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r28 + 4);
    r5 = 0x0u;
    r0 = r0 - r30;
    S32(r28 + 4, r0);
    r30 = L32(r27 + 4);
    r9 = L32(r31 + 124);
    r4 = r30;
    r30 = r30 - r9;
    r3 = r9;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r27 + 4);
    r5 = 0x0u;
    r0 = r0 - r30;
    S32(r27 + 4, r0);
    r30 = L32(r26 + 4);
    r9 = L32(r31 + 136);
    r4 = r30;
    r30 = r30 - r9;
    r3 = r9;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r26 + 4);
    r3 = 0x0u;
    r0 = r0 - r30;
    S32(r26 + 4, r0);
    S32(r1 + 60, r25);
L_80156414:
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc7f8)(W(r3));
    r30 = L8(r3 + 60);
    r4 = L32(r1 + 60);
    r3 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80155850)(W(r3), W(r4));
    cr0 = CMPS(r3, 1);
    if (!(cr0 & 2)) goto L_80156518;
    cr0 = CMPU(r30, 0x3u);
    if ((cr0 & 4)) goto L_80156518;
    r30 = (w3d_s32)r30 * 12;
    r28 = r1 + 60;
    r30 = r30 + r31;
    r30 = r30 + 100;
    r11 = L32(r30 + 4);
    r0 = L32(r30 + 8);
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_80156500;
    r9 = L32(r30);
    r10 = r1 + 68;
    r8 = r1 + 64;
    r9 = r11 - r9;
    r0 = r9 >> 1;
    r11 = r9 + 1;
    r0 = r9 + r0;
    S32(r1 + 76, r9);
    cr0 = CMPS(r11, r0);
    S32(r1 + 64, r11);
    S32(r1 + 68, r0);
    if (!(cr0 & 8)) goto L_8015648c;
    r8 = r10;
L_8015648c:
    r0 = L32(r8);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 72, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r30);
    r29 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_801564e4;
    r9 = L32(r1 + 72);
    r11 = r1 + 76;
    r0 = L32(r1 + 76);
    r5 = r1 + 72;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_801564cc;
    r5 = r11;
L_801564cc:
    r5 = L32(r5);
    r3 = r29;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r30);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_801564e4:
    S32(r30, r29);
    r0 = L32(r1 + 76);
    r0 = r29 + r0;
    S32(r30 + 4, r0);
    r9 = L32(r1 + 72);
    r9 = r29 + r9;
    S32(r30 + 8, r9);
L_80156500:
    r0 = L32(r28);
    r11 = L32(r30 + 4);
    S32(r11, r0);
    r9 = L32(r30 + 4);
    r9 = r9 + 4;
    S32(r30 + 4, r9);
L_80156518:
    r9 = L32(r1 + 60);
    r9 = r9 + 1;
    r3 = r9;
    S32(r1 + 60, r9);
    cr0 = CMPS(r3, 3);
    if (!(cr0 & 4)) goto L_80156414;
    r8 = r23;
    r25 = 0x0u;
L_80156538:
    r0 = r25 << 2;
    r0 = L32(r8 + r0);
    cr0 = CMPS(r0, -1);
    if ((cr0 & 2)) goto L_8015657c;
    cr0 = CMPS(r0, 3);
    if ((cr0 & 4)) goto L_8015657c;
    r9 = (w3d_s32)r25 * 12;
    r10 = r9;
    r9 = r9 + r31;
    { w3d_u32 t_ = r9 + 100; r11 = L32(t_); r9 = t_; }
    r0 = L32(r9 + 4);
    cr0 = CMPS(r11, r0);
    if ((cr0 & 2)) goto L_8015657c;
    r9 = r10 + r31;
    r11 = L32(r9 + 100);
    r0 = L32(r11);
    S32(r1 + 80, r0);
L_8015657c:
    r0 = r25 + 1;
    r25 = r0 & 0xffu;
    cr0 = CMPU(r25, 0x3u);
    if (!(cr0 & 4)) goto L_80156538;
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801565a8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801565a8:
    r3 = r24;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801565d0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801565d0:
    r1 = r1 + 144;
    return r3;
}

// 0x80158ea4 FUN_80158ea4 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: team_set_share. Llama a destroy_owned, worm_handle.
// aviso: lee r3 tras void 80178474 en 80158f50
__attribute__((weak)) w3d_u32 A80158ea4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r9 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r11 = 0x0u;
    r0 = 0x0u;
    S32(r1 + 8, r11);
    r9 = r1 + 8;
    r0 = 0xe3a8u;
    r29 = r5;
    S32(r9 + 4, r0);
    cr0 = CMPU(r4, 0x4u);
    if (!(cr0 & 4)) goto L_80158ee8;
    r3 = r9;
    r4 = 0x2u;
    ((void (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
    goto L_80158f54;
L_80158ee8:
    r9 = (w3d_s32)r4 * 12;
    r11 = r9;
    r4 = r11;
    r9 = r9 + r3;
    r11 = r11 + r3;
    r31 = L32(r9 + 52);
    r0 = L32(r11 + 56);
    cr0 = CMPS(r31, r0);
    if ((cr0 & 2)) goto L_80158f48;
    r30 = r4 + r3;
    r30 = r30 + 52;
L_80158f14:
    r3 = L32(r31);
    r4 = r1 + 8;
    r31 = r31 + 4;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc710)(W(r3), W(r4));
    r11 = r3;
    r0 = L32(r11 + 164);
    r9 = L16(r11 + 170);
    r9 = r9 - r0;
    r9 = r9 - r29;
    S32(r11 + 164, r9);
    r0 = L32(r30 + 4);
    cr0 = CMPS(r31, r0);
    if (!(cr0 & 2)) goto L_80158f14;
L_80158f48:
    r3 = r1 + 8;
    r4 = 0x2u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A80178474)(W(r3), W(r4));
L_80158f54:
    r1 = r1 + 32;
    return r3;
}

// 0x8015a6b8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015a6b8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3 + 72);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015ae3c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015ae3c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r11 = L32(D(0x804b17ecu));
    r4 = r3;
    r3 = L32(r11 + 116);
    r9 = L32(r3);
    r0 = L32(r9 + 140);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015ae74 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015ae74(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b17ecu));
    r3 = L32(r9 + 116);
    r11 = L32(r3);
    r0 = L32(r11 + 104);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015aea8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015aea8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b17ecu));
    r0 = r3;
    r5 = r4;
    r3 = L32(r9 + 116);
    r4 = r0;
    r9 = L32(r3);
    r0 = L32(r9 + 108);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015b1a8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 802cafd0 en 8015b1b4
__attribute__((weak)) w3d_u32 A8015b1a8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A802cafd0)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x8015b764 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015b764(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    ((void (*)(w3d_oarg))A8015b9d0)(W(r3));
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8015ba30 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015ba30(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 68);
    r9 = L32(r3);
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015bd08 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015bd08(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 68);
    r9 = L32(r3);
    r0 = L32(r9 + 36);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015c118 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015c118(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r0 = L32(r9 + 44);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015c960 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015c960(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 68);
    r9 = L32(r3);
    r0 = L32(r9 + 136);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015cabc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015cabc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 68);
    r9 = L32(r3);
    r0 = L32(r9 + 72);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015cc24 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015cc24(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r11 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3 + 92);
    r11 = L32(r3 + 96);
    r9 = r9 + 1;
    S32(r3 + 92, r9);
    r3 = r11;
    r9 = L32(r11);
    r0 = L32(r9 + 40);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015cd04 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015cd04(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 68);
    r9 = L32(r3);
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015cd34 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015cd34(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 68);
    r9 = L32(r3);
    r0 = L32(r9 + 80);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8015e0c0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8015e0c0(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8015e900)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x80160e34 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80160e34(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 28);
    r9 = L32(r3);
    r0 = L32(r9 + 68);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8016293c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8016293c(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015fb34)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x80163754 FUN_80163754 no verificada: desde bytes PPC
// Llama a sol35f7a_pool_allocate, native_forward_copy, handle_storage_release, actor_from_handle. Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A80163754(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[88];
    w3d_u32 r1 = h2g(frame) + 72;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 72; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804b178cu));
    r25 = r3;
    cr0 = CMPS(r4, -1);
    r26 = L32(r9 + 28);
    if (!(cr0 & 2)) goto L_80163780;
    r10 = 0x0u;
    goto L_801637a4;
L_80163780:
    r0 = r4 & 0xfffu;
    r11 = L32(r26);
    r0 = (w3d_s32)r0 * 36;
    r10 = 0x0u;
    r11 = r11 + r0;
    r9 = L32(r11 + 20);
    cr0 = CMPS(r9, r4);
    if (!(cr0 & 2)) goto L_801637a4;
    r10 = r11;
L_801637a4:
    cr0 = CMPS(r10, 0);
    if (!(cr0 & 2)) goto L_801637b8;
    r3 = 0x80000000u;
    r3 = 0x80004005u;
    goto L_80163928;
L_801637b8:
    r9 = r1 + 8;
    r27 = 0x0u;
    S32(r9 + 8, r27);
    r30 = r9;
    S32(r9 + 4, r27);
    S32(r1 + 8, r27);
    r9 = L16(r10 + 6);
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_801638c8;
L_801637dc:
    r11 = (w3d_s32)r9 * 36;
    r10 = L32(r1 + 12);
    r9 = L32(r26);
    r0 = L32(r1 + 16);
    r29 = r9 + r11;
    cr0 = CMPS(r10, r0);
    r28 = r29 + 20;
    if (!(cr0 & 2)) goto L_801638a4;
    r9 = L32(r1 + 8);
    r8 = r1 + 28;
    r7 = r1 + 24;
    r9 = r10 - r9;
    r0 = r9 >> 1;
    r11 = r9 + 1;
    r0 = r9 + r0;
    S32(r1 + 36, r9);
    cr0 = CMPS(r11, r0);
    S32(r1 + 24, r11);
    S32(r1 + 28, r0);
    if (!(cr0 & 8)) goto L_80163830;
    r7 = r8;
L_80163830:
    r0 = L32(r7);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 32, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r1 + 8);
    r31 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80163888;
    r9 = L32(r1 + 32);
    r11 = r1 + 36;
    r0 = L32(r1 + 36);
    r5 = r1 + 32;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80163870;
    r5 = r11;
L_80163870:
    r5 = L32(r5);
    r3 = r31;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r1 + 8);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80163888:
    r0 = L32(r1 + 36);
    r9 = L32(r1 + 32);
    r0 = r31 + r0;
    S32(r30, r31);
    r9 = r31 + r9;
    S32(r30 + 4, r0);
    S32(r30 + 8, r9);
L_801638a4:
    r0 = L32(r28);
    r11 = L32(r30 + 4);
    S32(r11, r0);
    r9 = L32(r30 + 4);
    r9 = r9 + 4;
    S32(r30 + 4, r9);
    r9 = L16(r29 + 10);
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_801637dc;
L_801638c8:
    r31 = L32(r1 + 8);
    r30 = L32(r1 + 12);
    goto L_801638d8;
L_801638d4:
    r31 = r31 + 4;
L_801638d8:
    cr0 = CMPS(r31, r30);
    if ((cr0 & 2)) goto L_80163914;
    r4 = L32(r31);
    r3 = r26;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8034b974)(W(r3), W(r4));
    r3 = r3; cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8016390c;
    r9 = L32(r3);
    r4 = r25;
    r0 = L32(r9 + 36);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r27 = r3;
L_8016390c:
    cr0 = CMPS(r27, 0);
    if (!(cr0 & 8)) goto L_801638d4;
L_80163914:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163924;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80163924:
    r3 = r27;
L_80163928:
    r1 = r1 + 72;
    return r3;
}

// 0x8016393c FUN_8016393c no verificada: desde bytes PPC
// Llama a actor_queue_exchange, apply_actor_types, apply_to_subtree, message_arena_checkpoint, engine_get_context. Hace 2 llamadas virtuales.
__attribute__((weak)) w3d_u32 A8016393c(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[136];
    w3d_u32 r1 = h2g(frame) + 120;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, ctr = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 120; S32(t_, r1); r1 = t_; }
    r19 = r3;
    r28 = r4;
    r31 = L32(r19 + 28);
    r0 = L32(r28);
    r9 = L32(r31 + 4);
    r3 = r31;
    r0 = r0 - r9;
    S32(r28, r0);
    r9 = L32(r31 + 24);
    r29 = L32(r9 + 8);
    r30 = L32(r9);
    ((void (*)(w3d_oarg))A8034aaf4)(W(r3));
    cr0 = CMPS(r30, r29);
    if ((cr0 & 2)) goto L_801639cc;
L_80163984:
    r4 = L32(r30);
    r6 = r4 & 0x3u;
    r0 = r4 & 0x1u; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801639ac;
    r5 = L32(r30 + 4);
    r6 = r6 >> 1;
    r3 = r31;
    r4 = r4 & 0xfffffffcu;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034ad50)(W(r3), W(r4), W(r5), W(r6));
    goto L_801639c0;
L_801639ac:
    r5 = L32(r30 + 4);
    r6 = r6 >> 1;
    r3 = r31;
    r4 = r4 & 0xfffffffcu;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8034ab10)(W(r3), W(r4), W(r5), W(r6));
L_801639c0:
    r30 = r30 + 8;
    cr0 = CMPS(r30, r29);
    if (!(cr0 & 2)) goto L_80163984;
L_801639cc:
    r3 = L32(D(0x804b1754u));
    r30 = r31 + 40;
    r22 = r30;
    ((void (*)(w3d_oarg))A80161440)(W(r3));
    r5 = L32(r28);
    r3 = r30;
    r4 = 0x3u;
    r3 = A8034af90(r3, r4, r5);
    r9 = L32(r31 + 52);
    r11 = L32(r9);
    r0 = L32(r9 + 4);
    r0 = r0 - r11;
    r9 = r0 >> 3; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_80163a2c;
    r9 = L32(r31 + 40);
    r11 = L32(r9);
    r0 = L32(r9 + 4);
    r0 = r0 - r11;
    r9 = r0 >> 3; cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_80163a2c;
    r0 = L32(r28);
    r9 = L32(D(0x804b178cu));
    S32(r31 + 36, r0);
    S32(r9 + 52, r0);
L_80163a2c:
    r9 = L32(r28);
    r0 = 0xcccc0000u;
    r0 = 0xcccccccdu;
    r11 = L32(D(0x804b178cu));
    r9 = r9 + 19;
    r30 = 0x2u;
    r9 = (w3d_u32)(((w3d_u64)r9 * (w3d_u64)r0) >> 32);
    r20 = r31 + 64;
    r9 = r9 >> 4;
    r24 = (w3d_s32)r9 * 20;
    S32(r31 + 32, r24);
    S32(r11 + 48, r24);
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    S32(r3 + 60, r30);
    r25 = L32(r22 + 4);
    cr0 = CMPS(r25, 0);
    if ((cr0 & 2)) goto L_80163d48;
    S32(r1 + 16, r25);
    r11 = r1 + 16;
    r0 = 0x0u;
    r21 = r11;
    S32(r11 + 4, r0);
    r9 = L32(r1 + 16);
    r11 = L32(r9 + 4);
    r0 = L32(r9);
    cr0 = CMPS(r0, r11);
    if ((cr0 & 2)) goto L_80163d48;
    r23 = r21;
L_80163a9c:
    r9 = L32(r1 + 16);
    r11 = L32(r21 + 4);
    r10 = L32(r9);
    r11 = r11 << 2;
    r9 = L32(r22 + 8);
    r30 = L32(r10 + r11);
    cr0 = CMPS(r30, -1);
    if (!(cr0 & 2)) goto L_80163ac4;
    r10 = 0x0u;
    goto L_80163ae8;
L_80163ac4:
    r0 = r30 & 0xfffu;
    r11 = L32(r9);
    r0 = (w3d_s32)r0 * 36;
    r10 = 0x0u;
    r11 = r11 + r0;
    r9 = L32(r11 + 20);
    cr0 = CMPS(r9, r30);
    if (!(cr0 & 2)) goto L_80163ae8;
    r10 = r11;
L_80163ae8:
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80163d00;
    r3 = L32(r10 + 12);
    r4 = r24;
    r9 = L32(r3);
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80163b20;
    r9 = L32(r23 + 4);
    r9 = r9 + 1;
    S32(r23 + 4, r9);
    goto L_80163d28;
L_80163b20:
    r9 = L32(r1 + 16);
    cr0 = CMPS(r3, -1);
    r8 = L32(r25 + 4);
    r11 = L32(r23 + 4);
    r10 = L32(r9);
    r0 = L32(r8 - 4);
    r11 = r11 << 2;
    S32(r10 + r11, r0);
    r9 = L32(r25 + 4);
    r9 = r9 - 4;
    S32(r25 + 4, r9);
    if ((cr0 & 2)) goto L_80163d28;
    r31 = L32(r22);
    r0 = r24 + r3;
    S32(r1 + 24, r30);
    r27 = r1 + 24;
    S32(r27 + 4, r0);
    r11 = L32(r31 + 4);
    r0 = L32(r31 + 12);
    cr0 = CMPS(r11, r0);
    if ((cr0 & 2)) goto L_80163b9c;
    cr0 = CMPS(r11, 0);
    if ((cr0 & 2)) goto L_80163b8c;
    r9 = L32(r1 + 24);
    r10 = L32(r1 + 28);
    S32(r11, r9);
    S32(r11 + 4, r10);
L_80163b8c:
    r9 = L32(r31 + 4);
    r9 = r9 + 8;
    S32(r31 + 4, r9);
    goto L_80163ce4;
L_80163b9c:
    r0 = L32(r31);
    r29 = r11;
    r9 = 0x1u;
    r10 = r1 + 36;
    r0 = r29 - r0;
    S32(r1 + 36, r9);
    { w3d_u32 t_ = r0; r9 = (w3d_u32)((w3d_s32)t_ >> 3); ca = SRAWCA(t_, 3); }
    r11 = r1 + 32;
    S32(r1 + 32, r9);
    cr0 = CMPU(r9, 0x1u);
    if (!(cr0 & 8)) goto L_80163bcc;
    r11 = r10;
L_80163bcc:
    r0 = L32(r11);
    r0 = r9 + r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80163bfc;
    r0 = r0 << 3;
    r3 = r0;
    r26 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80163c04;
    r3 = r26;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
    goto L_80163c04;
L_80163bfc:
    r3 = 0x0u;
    r26 = 0x0u;
L_80163c04:
    r30 = r3;
    r11 = L32(r31);
    r28 = r30;
    r3 = r28;
    cr0 = CMPS(r11, r29);
    if ((cr0 & 2)) goto L_80163c44;
L_80163c1c:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163c34;
    r9 = L32(r11);
    r10 = L32(r11 + 4);
    S32(r3, r9);
    S32(r3 + 4, r10);
L_80163c34:
    r11 = r11 + 8;
    r3 = r3 + 8;
    cr0 = CMPS(r11, r29);
    if (!(cr0 & 2)) goto L_80163c1c;
L_80163c44:
    r0 = L32(r1 + 36);
    r30 = r3;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80163c74;
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80163c6c;
    r9 = L32(r27);
    r10 = L32(r27 + 4);
    S32(r30, r9);
    S32(r30 + 4, r10);
L_80163c6c:
    r30 = r30 + 8;
    goto L_80163ca8;
L_80163c74:
    r9 = r0; cr0 = CMPS(r9, 0);
    r3 = r30;
    ctr = r9;
    if ((cr0 & 2)) goto L_80163ca4;
L_80163c84:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163c9c;
    r9 = L32(r27);
    r10 = L32(r27 + 4);
    S32(r3, r9);
    S32(r3 + 4, r10);
L_80163c9c:
    r3 = r3 + 8;
    --ctr; if (ctr != 0) goto L_80163c84;
L_80163ca4:
    r30 = r3;
L_80163ca8:
    r9 = L32(r31);
    r0 = L32(r31 + 4);
    r3 = r9;
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_80163cc8;
L_80163cbc:
    r9 = r9 + 8;
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_80163cbc;
L_80163cc8:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163cd4;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80163cd4:
    r0 = r26 + r28;
    S32(r31, r28);
    S32(r31 + 4, r30);
    S32(r31 + 12, r0);
L_80163ce4:
    r0 = L8(r31 + 16);
    r5 = r1 + 8;
    S8(r1 + 8, r0);
    r4 = L32(r31 + 4);
    r3 = L32(r31);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8034a400)(W(r3), W(r4), W(r5));
    goto L_80163d28;
L_80163d00:
    r9 = L32(r25 + 4);
    r8 = L32(r1 + 16);
    r11 = L32(r23 + 4);
    r0 = L32(r9 - 4);
    r10 = L32(r8);
    r11 = r11 << 2;
    S32(r10 + r11, r0);
    r9 = L32(r25 + 4);
    r9 = r9 - 4;
    S32(r25 + 4, r9);
L_80163d28:
    r11 = L32(r1 + 16);
    r0 = L32(r21 + 4);
    r9 = L32(r11);
    r10 = L32(r11 + 4);
    r0 = r0 << 2;
    r9 = r9 + r0;
    cr0 = CMPS(r9, r10);
    if (!(cr0 & 2)) goto L_80163a9c;
L_80163d48:
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r31 = 0x0u;
    S32(r3 + 60, r31);
    r30 = 0x2u;
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    S32(r3 + 60, r30);
    r25 = L32(r20 + 4);
    cr0 = CMPS(r25, 0);
    if ((cr0 & 2)) goto L_80164040;
    S32(r1 + 40, r25);
    r9 = r1 + 40;
    S32(r9 + 4, r31);
    r22 = r9;
    r11 = L32(r1 + 40);
    r9 = L32(r11 + 4);
    r0 = L32(r11);
    cr0 = CMPS(r0, r9);
    if ((cr0 & 2)) goto L_80164040;
    r23 = r22;
L_80163d94:
    r9 = L32(r1 + 40);
    r11 = L32(r22 + 4);
    r10 = L32(r9);
    r11 = r11 << 2;
    r9 = L32(r20 + 8);
    r30 = L32(r10 + r11);
    cr0 = CMPS(r30, -1);
    if (!(cr0 & 2)) goto L_80163dbc;
    r10 = 0x0u;
    goto L_80163de0;
L_80163dbc:
    r0 = r30 & 0xfffu;
    r11 = L32(r9);
    r0 = (w3d_s32)r0 * 36;
    r10 = 0x0u;
    r11 = r11 + r0;
    r9 = L32(r11 + 20);
    cr0 = CMPS(r9, r30);
    if (!(cr0 & 2)) goto L_80163de0;
    r10 = r11;
L_80163de0:
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80163ff8;
    r3 = L32(r10 + 12);
    r4 = r24;
    r9 = L32(r3);
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80163e18;
    r9 = L32(r23 + 4);
    r9 = r9 + 1;
    S32(r23 + 4, r9);
    goto L_80164020;
L_80163e18:
    r9 = L32(r1 + 40);
    cr0 = CMPS(r3, -1);
    r8 = L32(r25 + 4);
    r11 = L32(r23 + 4);
    r10 = L32(r9);
    r0 = L32(r8 - 4);
    r11 = r11 << 2;
    S32(r10 + r11, r0);
    r9 = L32(r25 + 4);
    r9 = r9 - 4;
    S32(r25 + 4, r9);
    if ((cr0 & 2)) goto L_80164020;
    r31 = L32(r20);
    r0 = r24 + r3;
    S32(r1 + 48, r30);
    r27 = r1 + 48;
    S32(r27 + 4, r0);
    r11 = L32(r31 + 4);
    r0 = L32(r31 + 12);
    cr0 = CMPS(r11, r0);
    if ((cr0 & 2)) goto L_80163e94;
    cr0 = CMPS(r11, 0);
    if ((cr0 & 2)) goto L_80163e84;
    r9 = L32(r1 + 48);
    r10 = L32(r1 + 52);
    S32(r11, r9);
    S32(r11 + 4, r10);
L_80163e84:
    r9 = L32(r31 + 4);
    r9 = r9 + 8;
    S32(r31 + 4, r9);
    goto L_80163fdc;
L_80163e94:
    r0 = L32(r31);
    r29 = r11;
    r9 = 0x1u;
    r10 = r1 + 60;
    r0 = r29 - r0;
    S32(r1 + 60, r9);
    { w3d_u32 t_ = r0; r9 = (w3d_u32)((w3d_s32)t_ >> 3); ca = SRAWCA(t_, 3); }
    r11 = r1 + 56;
    S32(r1 + 56, r9);
    cr0 = CMPU(r9, 0x1u);
    if (!(cr0 & 8)) goto L_80163ec4;
    r11 = r10;
L_80163ec4:
    r0 = L32(r11);
    r0 = r9 + r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80163ef4;
    r0 = r0 << 3;
    r3 = r0;
    r26 = r0;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80163efc;
    r3 = r26;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
    goto L_80163efc;
L_80163ef4:
    r3 = 0x0u;
    r26 = 0x0u;
L_80163efc:
    r30 = r3;
    r11 = L32(r31);
    r28 = r30;
    r3 = r28;
    cr0 = CMPS(r11, r29);
    if ((cr0 & 2)) goto L_80163f3c;
L_80163f14:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163f2c;
    r9 = L32(r11);
    r10 = L32(r11 + 4);
    S32(r3, r9);
    S32(r3 + 4, r10);
L_80163f2c:
    r11 = r11 + 8;
    r3 = r3 + 8;
    cr0 = CMPS(r11, r29);
    if (!(cr0 & 2)) goto L_80163f14;
L_80163f3c:
    r0 = L32(r1 + 60);
    r30 = r3;
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_80163f6c;
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80163f64;
    r9 = L32(r27);
    r10 = L32(r27 + 4);
    S32(r30, r9);
    S32(r30 + 4, r10);
L_80163f64:
    r30 = r30 + 8;
    goto L_80163fa0;
L_80163f6c:
    r9 = r0; cr0 = CMPS(r9, 0);
    r3 = r30;
    ctr = r9;
    if ((cr0 & 2)) goto L_80163f9c;
L_80163f7c:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163f94;
    r9 = L32(r27);
    r10 = L32(r27 + 4);
    S32(r3, r9);
    S32(r3 + 4, r10);
L_80163f94:
    r3 = r3 + 8;
    --ctr; if (ctr != 0) goto L_80163f7c;
L_80163f9c:
    r30 = r3;
L_80163fa0:
    r9 = L32(r31);
    r0 = L32(r31 + 4);
    r3 = r9;
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_80163fc0;
L_80163fb4:
    r9 = r9 + 8;
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_80163fb4;
L_80163fc0:
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80163fcc;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80163fcc:
    r0 = r26 + r28;
    S32(r31, r28);
    S32(r31 + 4, r30);
    S32(r31 + 12, r0);
L_80163fdc:
    r0 = L8(r31 + 16);
    r5 = r1 + 8;
    S8(r1 + 8, r0);
    r4 = L32(r31 + 4);
    r3 = L32(r31);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8034a400)(W(r3), W(r4), W(r5));
    goto L_80164020;
L_80163ff8:
    r9 = L32(r25 + 4);
    r8 = L32(r1 + 40);
    r11 = L32(r23 + 4);
    r0 = L32(r9 - 4);
    r10 = L32(r8);
    r11 = r11 << 2;
    S32(r10 + r11, r0);
    r9 = L32(r25 + 4);
    r9 = r9 - 4;
    S32(r25 + 4, r9);
L_80164020:
    r11 = L32(r1 + 40);
    r0 = L32(r22 + 4);
    r9 = L32(r11);
    r10 = L32(r11 + 4);
    r0 = r0 << 2;
    r9 = r9 + r0;
    cr0 = CMPS(r9, r10);
    if (!(cr0 & 2)) goto L_80163d94;
L_80164040:
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = 0x0u;
    S32(r3 + 60, r0);
    r3 = L32(r19 + 28);
    r3 = r3 + 76;
    ((void (*)(w3d_oarg))A80210afc)(W(r3));
    r3 = 0x0u;
    r1 = r1 + 120;
    return r3;
}

// 0x80165924 FUN_80165924 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: __18w3d_class. Llama a sol35f7a_pool_allocate, sol35f8b_allocation_fallback, get_service. Hace 9 llamadas virtuales. Usa las cadenas "OpenGLHandle".
__attribute__((weak)) w3d_u32 A80165924(w3d_u32 r3) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r9 = D(0x80410000u);
    r31 = r3;
    r9 = D(0x80411a88u);
    r11 = r31 + 4;
    S32(r31, r9);
    r0 = 0x2u;
    S8(r11 + 4, r0);
    r29 = 0x0u;
    r10 = r31 + 12;
    r9 = D(0x80410000u);
    r0 = L8(r11 + 4);
    r9 = D(0x80411a30u);
    r28 = r31 + 24;
    r3 = 0x30u;
    S32(r11 + 4, r0);
    S32(r31 + 12, r29);
    S32(r10 + 4, r29);
    S16(r31 + 4, r29);
    S16(r11 + 2, r29);
    S32(r31, r9);
    S32(r31 + 20, r29);
    S32(r28 + 4, r29);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r3 = r3; cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_801659a0;
    r3 = 0x30u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803413d8)(W(r3));
L_801659a0:
    S32(r3, r3);
    r30 = D(0x80420000u);
    S32(r3 + 4, r3);
    r30 = D(0x804191b0u);
    r27 = r1 + 24;
    S32(r28 + 4, r3);
    r3 = (w3d_u32)((w3d_u32 (*)())A8020b648)();
    r9 = L32(r3);
    r4 = D(0x804191b0u);
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    S32(r1 + 24, r29);
    r28 = r3;
    r4 = D(0x803a0000u);
    r9 = L32(r28);
    r4 = D(0x803a4ba0u);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3;
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80165a10;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80165a10:
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80165a3c;
    r9 = L32(r30);
    r4 = D(0x80410000u);
    r3 = r30;
    r4 = D(0x804119f0u);
    r0 = L32(r9 + 8);
    r5 = r27;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_80165a40;
L_80165a3c:
    S32(r1 + 24, r30);
L_80165a40:
    r30 = L32(r1 + 24);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80165a64;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_80165a9c;
L_80165a64:
    r9 = L32(r28);
    r4 = D(0x803a0000u);
    r3 = r28;
    r4 = D(0x803a4ba0u);
    r0 = L32(r9 + 48);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80165a9c;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80165a9c:
    r3 = L32(r31 + 20);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80165ab8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80165ab8:
    S32(r31 + 20, r30);
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80165ad8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80165ad8:
    r3 = r31;
    r1 = r1 + 56;
    return r3;
}

// 0x80166ff8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8016703c en 80167004
__attribute__((weak)) w3d_u32 A80166ff8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8016703c)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x80167018 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80167018(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = D(0x804b00dcu);
    r3 = A80209968(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80167118 FUN_80167118 no verificada: desde bytes PPC
// Inicia el dibujo GX: fija los GQR 2 a 5 (u8, u16, s8, s16), lee GXgl.ScreenWidth, ScreenHeight y ScreenDepth, y prepara búferes y pantalla.
__attribute__((weak)) w3d_u32 A80167118(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[88];
    w3d_u32 r1 = h2g(frame) + 72;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 72; S32(t_, r1); r1 = t_; }
    r31 = r3;
    S32(r31 + 20, r4);
    r3 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fdfc8)(W(r3));
    r5 = r3;
    r4 = D(0x803a0000u);
    r4 = D(0x803a4d54u);
    r3 = D(0x804b0640u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, w3d_oarg, ...))A80347324)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r10 = 0x20u;
    r8 = 0x0u;
    r0 = 0x280u;
    r9 = 0x1c0u;
    r11 = 0x1u;
    r3 = D(0x803a0000u);
    S32(r1 + 8, r0);
    r4 = r1 + 8;
    S32(r1 + 12, r9);
    r3 = D(0x803a4d80u);
    S32(r1 + 20, r10);
    S32(r1 + 32, r11);
    S32(r1 + 28, r8);
    S32(r1 + 16, r10);
    S32(r1 + 24, r8);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r3 = D(0x803a0000u);
    r4 = r1 + 12;
    r3 = D(0x803a4d94u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r3 = D(0x803a0000u);
    r4 = r1 + 16;
    r3 = D(0x803a4da8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r3 = D(0x803a0000u);
    r4 = r1 + 20;
    r3 = D(0x803a4dbcu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r3 = D(0x803a0000u);
    r4 = r1 + 24;
    r3 = D(0x803a4dd0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r3 = D(0x803a0000u);
    r4 = r1 + 28;
    r3 = D(0x803a4de0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r3 = D(0x803a0000u);
    r4 = r1 + 32;
    r3 = D(0x803a4df0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80206920)(W(r3), W(r4));
    r4 = 0x20u;
    r3 = 0x80000u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801fe2a8)(W(r3), W(r4));
    r0 = r3;
    r4 = 0x80000u;
    S32(r31 + 184, r0);
    r3 = CU(A80305374, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    S32(r31 + 192, r3);
    r3 = 0x4u;
    r3 = 0x40004u;
    /* mtgqr 2: la cuantización no existe en el anfitrión */
    r3 = 0x5u;
    r3 = 0x50005u;
    /* mtgqr 3: la cuantización no existe en el anfitrión */
    r3 = 0x6u;
    r3 = 0x60006u;
    /* mtgqr 4: la cuantización no existe en el anfitrión */
    r3 = 0x7u;
    r3 = 0x70007u;
    /* mtgqr 5: la cuantización no existe en el anfitrión */
    r29 = L32(D(0x804b1888u));
    r9 = D(0x803a0000u);
    r8 = r10;
    r30 = L32(r29 + 40);
    r11 = D(0x803a0000u);
    f1 = LF(D(0x803a4dfcu));
    r0 = L16(r30 + 4);
    r9 = L16(r30 + 6);
    f2 = f1;
    S16(r1 + 48, r0);
    f5 = f2;
    f6 = LF(D(0x803a4e00u));
    f3 = PSQL_U16(r1 + 48);
    S16(r1 + 48, r9);
    f4 = PSQL_U16(r1 + 48);
    ((void (*)(float, float, float, float, float, float))A8030c264)((float)f1, (float)f2, (float)f3, (float)f4, (float)f5, (float)f6);
    r5 = L16(r30 + 4);
    r3 = 0x0u;
    r6 = L16(r30 + 6);
    r4 = 0x0u;
    r3 = CU(A8030c2ac, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r5 = L16(r30 + 4);
    r3 = 0x0u;
    r6 = L16(r30 + 6);
    r4 = 0x0u;
    r3 = CU(A80308dc8, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r4 = L16(r30 + 8);
    r3 = L16(r30 + 4);
    r3 = CU(A80308e44, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L16(r30 + 8);
    r10 = L16(r30 + 6);
    r11 = r9;
    S16(r1 + 48, r0);
    f0 = PSQL_U16(r1 + 48);
    S16(r1 + 48, r10);
    f1 = PSQL_U16(r1 + 48);
    f1 = (float)(f0 / f1);
    r3 = CU(A80308ef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L8(r30 + 25);
    r4 = r30 + 26;
    r5 = 0x1u;
    r6 = r30 + 50;
    r3 = CU(A80309038, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L8(r30 + 25);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80167308;
    r3 = 0x2u;
    r4 = 0x0u;
    r3 = CU(A8030bacc, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_80167314;
L_80167308:
    r3 = 0x0u;
    r4 = 0x0u;
    r3 = CU(A8030bacc, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80167314:
    r3 = L32(r29 + 540);
    r3 = CU(A80309240, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fdfc8)(W(r3));
    r5 = r3;
    r4 = D(0x803a0000u);
    r4 = D(0x803a4d54u);
    r3 = D(0x804b0640u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, w3d_oarg, ...))A80347324)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = 0x2u;
    ((void (*)(w3d_oarg))A801680ec)(W(r3));
    r4 = 0x8u;
    r3 = 0x1u;
    r3 = CU(A803080e0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x803a0000u);
    r11 = D(0x803a0000u);
    f1 = LF(D(0x803a4e04u));
    r10 = D(0x803a0000u);
    f2 = LF(D(0x803a4e08u));
    r0 = 0x0u;
    f3 = f1;
    f6 = LF(D(0x803a4e00u));
    f4 = f2;
    S32(r31 + 776, r0);
    f5 = f3;
    S32(r31 + 232, r0);
    S32(r31 + 240, r0);
    r3 = r31 + 780;
    ((void (*)(w3d_oarg, float, float, float, float, float, float))A80302ec4)(W(r3), (float)f1, (float)f2, (float)f3, (float)f4, (float)f5, (float)f6);
    r3 = r31 + 844;
    ((void (*)(w3d_oarg))A80302b60)(W(r3));
    r3 = r31 + 1112;
    ((void (*)(w3d_oarg))A80302b60)(W(r3));
    r3 = r31;
    ((void (*)(w3d_oarg))A801685cc)(W(r3));
    r3 = r31;
    ((void (*)(w3d_oarg))A8016710c)(W(r3));
    r3 = 0x1u;
    ((void (*)(w3d_oarg))A80304b84)(W(r3));
    r3 = 0x1u;
    r3 = CU(A8030bba0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(D(0x804b1888u));
    ((void (*)(w3d_oarg))A8016eed0)(W(r3));
    r3 = 0x0u;
    r1 = r1 + 72;
    return r3;
}

// 0x80167728 fn_80167728 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A80167728(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80167728u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x80167738 fn_80167738 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A80167738(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80167738u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x801689a0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801689a0(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801a38c8)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x80168c8c FUN_80168c8c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_tex0_float2_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A80168c8c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_80168cb0;
    r30 = r3 - 4;
L_80168cb0:
    r9 = L32(r11 + 20);
    r4 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80168d10;
    r31 = r9;
    r4 = r4 << 3;
    r0 = L16(r31 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80168ce8;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r31 + 28, r0);
L_80168ce8:
    r4 = r29;
    r3 = 0xdu;
    r5 = 0x8u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 288);
    r9 = L32(r30 + 284);
    r0 = r0 | 0x80u;
    r9 = r9 + 1;
    S32(r30 + 288, r0);
    S32(r30 + 284, r9);
L_80168d10:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

// 0x80168d28 FUN_80168d28 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: bind_tex0_short2_array. Llama a cache_flush, GXSetArray.
__attribute__((weak)) w3d_u32 A80168d28(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r11 = r4;
    r3 = r3; cr0 = CMPS(r3, 0);
    r30 = 0x0u;
    if ((cr0 & 2)) goto L_80168d4c;
    r30 = r3 - 4;
L_80168d4c:
    r9 = L32(r11 + 20);
    r4 = L32(r9 + 24);
    r29 = r9 + 32;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80168db4;
    r31 = r9;
    r4 = r4 << 2;
    r0 = L16(r31 + 28);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80168d84;
    r3 = r29;
    ((void (*)(w3d_oarg, w3d_oarg))A802fa988)(W(r3), W(r4));
    r0 = 0x0u;
    S16(r31 + 28, r0);
L_80168d84:
    r4 = r29;
    r3 = 0xdu;
    r5 = 0x4u;
    r3 = CU(A80307d88, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r30 + 288);
    r11 = 0xcu;
    r9 = L32(r30 + 284);
    r0 = r0 | 0x100u;
    S8(r30 + 318, r11);
    r9 = r9 + 1;
    S32(r30 + 288, r0);
    S32(r30 + 284, r9);
L_80168db4:
    r3 = 0x0u;
    r1 = r1 + 24;
    return r3;
}

}
