// Funciones del juego sin fuente admitida: 0x800039e4 a 0x8001d388. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A80003424();
__attribute__((weak)) void A80003e78();
__attribute__((weak)) void A80004038();
__attribute__((weak)) void A8000415c();
__attribute__((weak)) void A8000443c();
__attribute__((weak)) void A8000519c();
__attribute__((weak)) void A8000532c();
__attribute__((weak)) void A80005398();
__attribute__((weak)) void A800053e4();
__attribute__((weak)) void A800055b8();
__attribute__((weak)) void A80005d4c();
__attribute__((weak)) void A80006ff4();
__attribute__((weak)) void A8000756c();
__attribute__((weak)) void A80007ccc();
__attribute__((weak)) void A80009674();
__attribute__((weak)) void A80009a94();
__attribute__((weak)) void A8000a9ac();
__attribute__((weak)) void A8000b6bc();
__attribute__((weak)) void A8000d004();
__attribute__((weak)) void A8000e094();
__attribute__((weak)) void A80010630();
__attribute__((weak)) void A8001523c();
__attribute__((weak)) void A80015264();
__attribute__((weak)) void A800154b4();
__attribute__((weak)) void A800154e0();
__attribute__((weak)) void A80017380();
__attribute__((weak)) void A800174cc();
__attribute__((weak)) void A80017a04();
__attribute__((weak)) void A800196dc();
__attribute__((weak)) void A8001a758();
__attribute__((weak)) void A8001a770();
__attribute__((weak)) void A8001b830();
__attribute__((weak)) void A8001b964();
__attribute__((weak)) void A8001df1c();
__attribute__((weak)) void A8001dff8();
__attribute__((weak)) void A8001e11c();
__attribute__((weak)) void A8001e1a0();
__attribute__((weak)) void A8001e2dc();
__attribute__((weak)) void A8001e328();
__attribute__((weak)) void A8001f1d8();
__attribute__((weak)) void A8001f25c();
__attribute__((weak)) void A8001f9f0();
__attribute__((weak)) void A800203a0();
__attribute__((weak)) void A800203cc();
__attribute__((weak)) void A80021468();
__attribute__((weak)) void A800b0824();
__attribute__((weak)) void A800d75f0();
__attribute__((weak)) void A800fc6dc();
__attribute__((weak)) void A800fcb4c();
__attribute__((weak)) void A801182c0();
__attribute__((weak)) void A801182ec();
__attribute__((weak)) void A801188c4();
__attribute__((weak)) void A80131a84();
__attribute__((weak)) void A801613f0();
__attribute__((weak)) void A8016239c();
__attribute__((weak)) void A80178df0();
__attribute__((weak)) void A801f6480();
__attribute__((weak)) void A802e8094();
__attribute__((weak)) void A802e82c0();
__attribute__((weak)) void A802e83cc();
__attribute__((weak)) void A8034141c();
__attribute__((weak)) void A80341448();
__attribute__((weak)) void A8034144c();
__attribute__((weak)) void A80342a74();
__attribute__((weak)) void A80342bac();
__attribute__((weak)) void A80342ddc();

// 0x800039e4 FUN_800039e4 no verificada: desde bytes PPC
// Llama a move_type_name, sol35b8_control_allocate, motion_message_construct, object_base_destroy, move_queue_start_wait. Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A800039e4(w3d_u32 r3) {
    alignas(16) char frame[120];
    w3d_u32 r1 = h2g(frame) + 104;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 104; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r3 = L32(r29 + 20);
    r0 = L32(r29 + 24);
    r26 = L32(r29 + 36);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_80003e60;
    r27 = r26; cr0 = CMPS(r27, 0);
    if (!(cr0 & 2)) goto L_80003e60;
    r0 = L32(D(0x804aa79cu));
    r25 = 0x1u;
    S32(r29 + 36, r25);
    r30 = r1 + 8;
    cr0 = CMPS(r0, 2);
    r31 = L32(r3);
    if (!(cr0 & 2)) goto L_80003a54;
    r9 = r31;
    { w3d_u32 t_ = r9 + 4; f13 = LF(t_); r9 = t_; }
    f12 = LF(r9 + 8);
    f0 = LF(r9 + 4);
    SF(r1 + 8, f13);
    SF(r30 + 4, f0);
    SF(r30 + 8, f12);
    r3 = L32(r31);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80004038)(W(r3));
L_80003a54:
    r3 = L32(D(0x804b1754u));
    r4 = 0xecu;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80131a84)(W(r3));
    r9 = r31;
    r28 = r3;
    { w3d_u32 t_ = r9 + 4; f12 = LF(t_); r9 = t_; }
    r10 = r28 + 16;
    f13 = LF(r9 + 8);
    f0 = LF(r9 + 4);
    SF(r1 + 8, f12);
    SF(r30 + 4, f0);
    SF(r30 + 8, f13);
    r9 = L32(r1 + 8);
    r0 = L32(r1 + 16);
    r11 = L32(r1 + 12);
    S32(r28 + 16, r9);
    S32(r10 + 8, r0);
    S32(r10 + 4, r11);
    r0 = L32(r31);
    cr0 = CMPS(r0, 7);
    if ((cr0 & 2)) goto L_80003bd8;
    if ((cr0 & 4)) goto L_80003ac4;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 8)) goto L_80003e58;
    cr0 = CMPS(r0, 2);
    if (!(cr0 & 4)) goto L_80003af8;
    goto L_80003b04;
L_80003ac4:
    cr0 = CMPS(r0, 10);
    if ((cr0 & 2)) goto L_80003e58;
    if ((cr0 & 4)) goto L_80003ae4;
    cr0 = CMPS(r0, 8);
    if ((cr0 & 2)) goto L_80003d00;
    cr0 = CMPS(r0, 9);
    if ((cr0 & 2)) goto L_80003d78;
    goto L_80003e58;
L_80003ae4:
    cr0 = CMPS(r0, 11);
    if ((cr0 & 2)) goto L_80003d84;
    cr0 = CMPS(r0, 12);
    if ((cr0 & 2)) goto L_80003e14;
    goto L_80003e58;
L_80003af8:
    r0 = 0x2u;
    S32(r28 + 8, r0);
    goto L_80003e58;
L_80003b04:
    r0 = L32(r29 + 40);
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_80003b58;
    if ((cr0 & 4)) goto L_80003b20;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80003b34;
    goto L_80003e58;
L_80003b20:
    cr0 = CMPS(r0, 2);
    if ((cr0 & 2)) goto L_80003bc0;
    cr0 = CMPS(r0, 3);
    if ((cr0 & 2)) goto L_80003bcc;
    goto L_80003e58;
L_80003b34:
    r0 = L32(r31);
    cr0 = CMPS(r0, 4);
    r0 = 0x5u;
    if (!(cr0 & 2)) goto L_80003b48;
    r0 = 0x6u;
L_80003b48:
    S32(r28 + 8, r0);
    r0 = 0x1u;
    S32(r29 + 40, r0);
    goto L_80003e58;
L_80003b58:
    r0 = 0x2u;
    S32(r29 + 40, r0);
    r0 = L32(r31);
    cr0 = CMPS(r0, 4);
    if ((cr0 & 2)) goto L_80003b9c;
    if ((cr0 & 4)) goto L_80003b7c;
    cr0 = CMPS(r0, 3);
    if ((cr0 & 2)) goto L_80003b90;
    goto L_80003e58;
L_80003b7c:
    cr0 = CMPS(r0, 5);
    if ((cr0 & 2)) goto L_80003ba8;
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_80003bb4;
    goto L_80003e58;
L_80003b90:
    r0 = 0x8u;
    S32(r28 + 8, r0);
    goto L_80003e58;
L_80003b9c:
    r0 = 0x9u;
    S32(r28 + 8, r0);
    goto L_80003e58;
L_80003ba8:
    r0 = 0xau;
    S32(r28 + 8, r0);
    goto L_80003e58;
L_80003bb4:
    r0 = 0xau;
    r9 = 0x0u;
    goto L_80003c54;
L_80003bc0:
    r0 = 0xbu;
    r9 = 0x3u;
    goto L_80003c54;
L_80003bcc:
    r0 = 0x2u;
    r9 = 0x0u;
    goto L_80003c54;
L_80003bd8:
    r0 = L32(r29 + 40);
    cr0 = CMPS(r0, 4);
    if ((cr0 & 2)) goto L_80003c60;
    if ((cr0 & 4)) goto L_80003bf4;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80003c08;
    goto L_80003e58;
L_80003bf4:
    cr0 = CMPS(r0, 5);
    if ((cr0 & 2)) goto L_80003cf8;
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_80003c4c;
    goto L_80003e58;
L_80003c08:
    r9 = D(0x80410000u);
    r30 = r1 + 24;
    r9 = D(0x8040dd88u);
    r11 = D(0x80410000u);
    S32(r1 + 40, r9);
    r11 = D(0x8040dd68u);
    S32(r30 + 8, r27);
    r0 = 0x30u;
    S32(r30 + 12, r27);
    r3 = r30;
    S32(r30 + 4, r27);
    S32(r1 + 40, r11);
    S32(r30 + 20, r0);
    S32(r30 + 8, r25);
    S32(r30 + 12, r25);
    r9 = L32(r1 + 40);
    goto L_80003d3c;
L_80003c4c:
    r0 = 0x5u;
    r9 = 0x4u;
L_80003c54:
    S32(r28 + 8, r0);
    S32(r29 + 40, r9);
    goto L_80003e58;
L_80003c60:
    r11 = L32(r29 + 20);
    r7 = r28 + 52;
    r0 = L32(r28 + 88);
    r6 = 0xa8u;
    r9 = L32(r11);
    S32(r1 + 8, r0);
    r8 = r9 + 16;
L_80003c7c:
    r10 = L32(r8);
    { w3d_u32 t_ = r6; r6 = t_ + (w3d_u32)-24; ca = r6 < t_; cr0 = CMPS(r6, 0); }
    S32(r7, r10);
    r10 = L32(r8 + 4);
    S32(r7 + 4, r10);
    r10 = L32(r8 + 8);
    S32(r7 + 8, r10);
    r10 = L32(r8 + 12);
    S32(r7 + 12, r10);
    r10 = L32(r8 + 16);
    S32(r7 + 16, r10);
    r10 = L32(r8 + 20);
    r8 = r8 + 24;
    S32(r7 + 20, r10);
    r7 = r7 + 24;
    if (!(cr0 & 2)) goto L_80003c7c;
    r10 = L32(r8);
    r0 = 0xcu;
    r9 = L32(r1 + 8);
    r11 = 0x5u;
    S32(r7, r10);
    r10 = L32(r8 + 4);
    S32(r7 + 4, r10);
    r10 = L32(r8 + 8);
    S32(r7 + 8, r10);
    r10 = L32(r8 + 12);
    S32(r7 + 12, r10);
    S32(r28 + 88, r9);
    S32(r28 + 8, r0);
    S32(r29 + 40, r11);
    goto L_80003e58;
L_80003cf8:
    r0 = 0x2u;
    goto L_80003d6c;
L_80003d00:
    r0 = L32(r29 + 40);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80003d18;
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_80003d68;
    goto L_80003e58;
L_80003d18:
    r9 = D(0x80410000u);
    r0 = 0x2au;
    r9 = D(0x8040dd68u);
    S32(r30 + 20, r0);
    S32(r30 + 16, r9);
    r3 = r30;
    S32(r30 + 8, r25);
    S32(r30 + 4, r27);
    S32(r30 + 12, r25);
L_80003d3c:
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r30;
    r4 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg))A80021468)(W(r3), W(r4));
    S32(r28 + 8, r27);
    r3 = r29;
    r4 = 0xfau;
    ((void (*)(w3d_oarg, w3d_oarg))A8000415c)(W(r3), W(r4));
    goto L_80003e58;
L_80003d68:
    r0 = 0x5u;
L_80003d6c:
    S32(r28 + 8, r0);
    S32(r29 + 40, r27);
    goto L_80003e58;
L_80003d78:
    r0 = 0xdu;
    S32(r28 + 8, r0);
    goto L_80003e58;
L_80003d84:
    r0 = 0x10u;
    r10 = L32(r28 + 88);
    S32(r28 + 8, r0);
    r8 = r28 + 52;
    r0 = 0xa8u;
    r9 = L32(r29 + 20);
    r11 = L32(r9);
    S32(r1 + 8, r10);
    r3 = r11 + 16;
L_80003da8:
    r9 = L32(r3);
    { w3d_u32 t_ = r0; r0 = t_ + (w3d_u32)-24; ca = r0 < t_; cr0 = CMPS(r0, 0); }
    S32(r8, r9);
    r9 = L32(r3 + 4);
    S32(r8 + 4, r9);
    r9 = L32(r3 + 8);
    S32(r8 + 8, r9);
    r9 = L32(r3 + 12);
    S32(r8 + 12, r9);
    r9 = L32(r3 + 16);
    S32(r8 + 16, r9);
    r9 = L32(r3 + 20);
    r3 = r3 + 24;
    S32(r8 + 20, r9);
    r8 = r8 + 24;
    if (!(cr0 & 2)) goto L_80003da8;
    r9 = L32(r3);
    r0 = L32(r1 + 8);
    S32(r8, r9);
    r9 = L32(r3 + 4);
    S32(r8 + 4, r9);
    r9 = L32(r3 + 8);
    S32(r8 + 8, r9);
    r9 = L32(r3 + 12);
    S32(r8 + 12, r9);
    S32(r28 + 88, r0);
    goto L_80003e58;
L_80003e14:
    S32(r28 + 8, r27);
    r0 = L32(r29 + 40);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80003e30;
    cr0 = CMPS(r0, 6);
    if ((cr0 & 2)) goto L_80003e54;
    goto L_80003e58;
L_80003e30:
    r11 = L32(r29 + 20);
    r3 = r29;
    r9 = L32(r11);
    f0 = LF(r9 + 4);
    f13 = FCTIWZ(f0);
    SDS(r1 + 64, f13);
    r4 = L32(r1 + 68);
    ((void (*)(w3d_oarg, w3d_oarg))A8000415c)(W(r3), W(r4));
    goto L_80003e58;
L_80003e54:
    S32(r29 + 40, r26);
L_80003e58:
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
L_80003e60:
    r3 = 0x0u;
    r1 = r1 + 104;
    return r3;
}

// 0x80004394 FUN_80004394 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: path_search_reset. Llama a path_table_clear, empty, operator_delete, path_bucket_clear.
// aviso: lee r3 tras void 8000532c en 80004414
__attribute__((weak)) w3d_u32 A80004394(w3d_u32 r3) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r3 = r30 + 4;
    r31 = r30 + 65536;
    ((void (*)(w3d_oarg))A80005398)(W(r3));
    r3 = r30 + 16392;
    ((void (*)(w3d_oarg))A80005398)(W(r3));
    r30 = r31;
    r0 = L32(r30 - 32692);
    S32(r30 - 32688, r0);
    r30 = L32(r31 - 32756);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_800043e0;
    ((void (*)())A8034144c)();
    r3 = r30;
    ((void (*)(w3d_oarg))A80015264)(W(r3));
L_800043e0:
    r30 = L32(r31 - 32752);
    r29 = 0x0u;
    S32(r31 - 32756, r29);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_80004400;
    ((void (*)())A8034144c)();
    r3 = r30;
    ((void (*)(w3d_oarg))A80015264)(W(r3));
L_80004400:
    r0 = 0xffffffffu;
    S32(r31 - 32752, r29);
    S32(r31 - 32744, r29);
    r3 = r31 - 32732;
    S32(r31 - 32740, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8000532c)(W(r3));
    r0 = 0x7fffu;
    S16(r31 - 32696, r29);
    S16(r31 - 32694, r0);
    S32(r31 - 32736, r29);
    r1 = r1 + 24;
    return r3;
}

// 0x80004498 FUN_80004498 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: start. Llama a path_search_reset, hop_test_height, grid_select_layer, sol35a10_allocate, range_limits_reset.
// aviso: lee r3 tras void 80005d4c en 80004698
// aviso: lee r3 tras void 8001523c en 80004504
// aviso: lee r3 tras void 8001523c en 8000455c
__attribute__((weak)) w3d_u32 A80004498(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[80];
    w3d_u32 r1 = h2g(frame) + 64;
    w3d_u32 r0 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 64; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r24 = r5;
    r30 = r4;
    r3 = A80004394(r3);
    r29 = r31 + 65536;
    r3 = L32(D(0x804b1758u));
    r25 = 0x0u;
    r0 = 0xau;
    S32(r29 - 32748, r25);
    S32(r29 - 32676, r25);
    r23 = 0x0u;
    S32(r29 - 32672, r25);
    S32(r29 - 32668, r25);
    S32(D(0x804b175cu), r0);
    f1 = ((float (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e2dc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r3 = L32(D(0x804b1758u));
    r5 = r1 + 8;
    r6 = r1 + 10;
    r7 = r1 + 16;
    SF(r29 - 32712, f1);
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e328)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9));
    r3 = 0x14u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8001523c)(W(r3));
    r30 = r3;
    r26 = LS16(r1 + 8);
    r28 = LS16(r1 + 10);
    r27 = L32(r1 + 16);
    ((void (*)(w3d_oarg))A8034141c)(W(r3));
    S16(r30 + 2, r26);
    S16(r30 + 4, r28);
    S8(r30 + 6, r27);
    ((void (*)())A80341448)();
    S32(r29 - 32756, r30);
    r4 = r30;
    r3 = r31 + 4;
    r3 = CU(A800053e4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(D(0x804b1758u));
    r4 = r24;
    r5 = r1 + 12;
    r6 = r1 + 14;
    r7 = r1 + 20;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e328)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9));
    r24 = r3;
    r3 = 0x14u;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8001523c)(W(r3));
    r30 = r3;
    r26 = LS16(r1 + 12);
    r28 = LS16(r1 + 14);
    r27 = L32(r1 + 20);
    ((void (*)(w3d_oarg))A8034141c)(W(r3));
    S16(r30 + 2, r26);
    S16(r30 + 4, r28);
    S8(r30 + 6, r27);
    ((void (*)())A80341448)();
    r9 = L32(r29 - 32756);
    S32(r29 - 32752, r30);
    S16(r9 + 10, r25);
    r3 = L32(r29 - 32756);
    r4 = L32(r29 - 32752);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8000443c)(W(r3), W(r4));
    r9 = L32(r29 - 32756);
    r0 = L32(D(0x804aa794u));
    S16(r9 + 8, r3);
    cr0 = CMPS(r0, 0);
    r9 = L32(r29 - 32756);
    r0 = L16(r9 + 10);
    r11 = L16(r9 + 8);
    r0 = r0 + r11;
    S16(r9 + 12, r0);
    if (!(cr0 & 2)) goto L_80004648;
    cr0 = CMPS(r24, 0);
    if (!(cr0 & 2)) goto L_800045d8;
    r0 = 0x5u;
    r23 = 0x1u;
    S32(D(0x804b175cu), r0);
L_800045d8:
    r3 = L32(D(0x804b1758u));
    r4 = LS16(r1 + 12);
    r5 = LS16(r1 + 14);
    r6 = L32(r1 + 20);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r0 = L8(r3);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80004648;
    r23 = 0x1u;
    cr0 = CMPS(r0, 2);
    if ((cr0 & 2)) goto L_80004630;
    if ((cr0 & 4)) goto L_80004614;
    cr0 = CMPS(r0, 1);
    if ((cr0 & 2)) goto L_80004628;
    goto L_80004648;
L_80004614:
    cr0 = CMPS(r0, 3);
    if ((cr0 & 2)) goto L_80004638;
    cr0 = CMPS(r0, 4);
    if ((cr0 & 2)) goto L_80004640;
    goto L_80004648;
L_80004628:
    r0 = 0x6u;
    goto L_80004644;
L_80004630:
    r0 = 0x7u;
    goto L_80004644;
L_80004638:
    r0 = 0x8u;
    goto L_80004644;
L_80004640:
    r0 = 0x9u;
L_80004644:
    S32(D(0x804b175cu), r0);
L_80004648:
    r9 = LS16(r1 + 8);
    r0 = LS16(r1 + 12);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8000468c;
    r9 = LS16(r1 + 10);
    r0 = LS16(r1 + 14);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8000468c;
    r9 = L32(r1 + 16);
    r0 = L32(r1 + 20);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8000468c;
    r0 = 0x0u;
    r9 = 0xbu;
    S32(D(0x804aa794u), r0);
    r23 = 0x1u;
    S32(D(0x804b175cu), r9);
L_8000468c:
    cr0 = CMPS(r23, 0);
    if ((cr0 & 2)) goto L_8000469c;
    r3 = r31;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80005d4c)(W(r3));
L_8000469c:
    r11 = L32(D(0x804aa6d8u));
    r10 = r31 + 65536;
    r0 = L32(r11 + 496);
    S32(r10 - 32704, r0);
    r9 = L32(r11 + 492);
    S32(r10 - 32700, r9);
    r1 = r1 + 64;
    return r3;
}

// 0x800047f0 FUN_800047f0 no verificada: desde bytes PPC
// Llama a grid_cell_slot, grid_byte_cell, path_vertical_fit, path_relax, grid_layer_find. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A800047f0(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[320];
    w3d_u32 r1 = h2g(frame) + 304;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f12 = 0, f13 = 0, f23 = 0, f24 = 0, f25 = 0, f26 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 304; S32(t_, r1); r1 = t_; }
    r12 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    S32(r1 + 156, r12);
    S32(r1 + 8, r4);
    r17 = r3;
    r21 = L32(D(0x804b1758u));
    r30 = 0x0u;
    r15 = LS16(r4 + 2);
    r16 = LS16(r4 + 4);
    r3 = r21;
    r28 = L8(r4 + 6);
    r22 = r15 - 1;
    r4 = r15;
    r5 = r16;
    r6 = r28;
    r29 = r22;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e11c)(W(r3), W(r4), W(r5), W(r6));
    f26 = LF(r3);
    r4 = r15;
    r3 = r21;
    r5 = r16;
    r6 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e1a0)(W(r3), W(r4), W(r5), W(r6));
    f25 = LF(r3);
L_80004880:
    r4 = r29;
    r5 = r16;
    r6 = r30;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r0 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r9 + r0 + ca; r31 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r29;
    r5 = r16;
    r6 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r31, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_800048cc;
    r9 = 0x0u;
L_800048cc:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_800048dc;
    r0 = 0x0u;
L_800048dc:
    r31 = r9 & r0; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_80004904;
    r4 = L32(r1 + 8);
    r5 = (w3d_u32)(w3d_s32)(short)r29;
    r7 = r30;
    r3 = r17;
    r6 = (w3d_u32)(w3d_s32)(short)r16;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004910;
L_80004904:
    r30 = r30 + 1;
    cr0 = CMPS(r30, 1);
    if (!(cr0 & 4)) goto L_80004880;
L_80004910:
    r23 = r15 + 1;
    cr4 = CMPS(r31, 0);
    r29 = r23;
    cr2 = CMPS(r28, 0);
    r30 = 0x0u;
    r25 = r16 - 1;
    r24 = r16 + 1;
L_8000492c:
    r4 = r29;
    r5 = r16;
    r6 = r30;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r0 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r9 + r0 + ca; r31 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r29;
    r5 = r16;
    r6 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r31, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004978;
    r9 = 0x0u;
L_80004978:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004988;
    r0 = 0x0u;
L_80004988:
    r31 = r9 & r0; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_800049b0;
    r4 = L32(r1 + 8);
    r7 = r30;
    r3 = r17;
    r5 = (w3d_u32)(w3d_s32)(short)r23;
    r6 = (w3d_u32)(w3d_s32)(short)r16;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_800049bc;
L_800049b0:
    r30 = r30 + 1;
    cr0 = CMPS(r30, 1);
    if (!(cr0 & 4)) goto L_8000492c;
L_800049bc:
    cr3 = CMPS(r31, 0);
    r30 = r25;
    r31 = 0x0u;
L_800049c8:
    r4 = r15;
    r5 = r30;
    r6 = r31;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r0 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r9 + r0 + ca; r27 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r15;
    r5 = r30;
    r6 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r27, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004a14;
    r9 = 0x0u;
L_80004a14:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004a24;
    r0 = 0x0u;
L_80004a24:
    r27 = r9 & r0; cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_80004a4c;
    r4 = L32(r1 + 8);
    r7 = r31;
    r3 = r17;
    r5 = (w3d_u32)(w3d_s32)(short)r15;
    r6 = (w3d_u32)(w3d_s32)(short)r25;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004a58;
L_80004a4c:
    r31 = r31 + 1;
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 4)) goto L_800049c8;
L_80004a58:
    r31 = 0x0u;
    r30 = r24;
L_80004a60:
    r4 = r15;
    r5 = r30;
    r6 = r31;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r0 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r0; r9 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r9 + r0 + ca; r26 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r15;
    r5 = r30;
    r6 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r26, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004aac;
    r9 = 0x0u;
L_80004aac:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004abc;
    r0 = 0x0u;
L_80004abc:
    r26 = r9 & r0; cr0 = CMPS(r26, 0);
    if ((cr0 & 2)) goto L_80004ae4;
    r4 = L32(r1 + 8);
    r7 = r31;
    r3 = r17;
    r5 = (w3d_u32)(w3d_s32)(short)r15;
    r6 = (w3d_u32)(w3d_s32)(short)r24;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004af0;
L_80004ae4:
    r31 = r31 + 1;
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 4)) goto L_80004a60;
L_80004af0:
    if ((cr4 & 2)) goto L_80004b98;
    cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_80004b98;
    r31 = 0x0u;
    r28 = r22;
    r29 = r25;
L_80004b08:
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r30 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r30; r0 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r0 + r30 + ca; r30 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r30, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004b54;
    r9 = 0x0u;
L_80004b54:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004b64;
    r0 = 0x0u;
L_80004b64:
    r10 = r9 & r0; cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80004b8c;
    r4 = L32(r1 + 8);
    r7 = r31;
    r3 = r17;
    r5 = (w3d_u32)(w3d_s32)(short)r22;
    r6 = (w3d_u32)(w3d_s32)(short)r25;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004b98;
L_80004b8c:
    r31 = r31 + 1;
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 4)) goto L_80004b08;
L_80004b98:
    if ((cr3 & 2)) goto L_80004c40;
    cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_80004c40;
    r31 = 0x0u;
    r28 = r23;
    r29 = r25;
L_80004bb0:
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r30 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r30; r0 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r0 + r30 + ca; r30 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r30, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004bfc;
    r9 = 0x0u;
L_80004bfc:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004c0c;
    r0 = 0x0u;
L_80004c0c:
    r10 = r9 & r0; cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80004c34;
    r4 = L32(r1 + 8);
    r6 = (w3d_u32)(w3d_s32)(short)r25;
    r7 = r31;
    r3 = r17;
    r5 = (w3d_u32)(w3d_s32)(short)r23;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004c40;
L_80004c34:
    r31 = r31 + 1;
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 4)) goto L_80004bb0;
L_80004c40:
    if ((cr4 & 2)) goto L_80004ce8;
    cr0 = CMPS(r26, 0);
    if ((cr0 & 2)) goto L_80004ce8;
    r31 = 0x0u;
    r28 = r22;
    r29 = r24;
L_80004c58:
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r30 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r30; r0 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r0 + r30 + ca; r30 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r30, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004ca4;
    r9 = 0x0u;
L_80004ca4:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004cb4;
    r0 = 0x0u;
L_80004cb4:
    r10 = r9 & r0; cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80004cdc;
    r4 = L32(r1 + 8);
    r5 = (w3d_u32)(w3d_s32)(short)r22;
    r7 = r31;
    r3 = r17;
    r6 = (w3d_u32)(w3d_s32)(short)r24;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004ce8;
L_80004cdc:
    r31 = r31 + 1;
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 4)) goto L_80004c58;
L_80004ce8:
    if ((cr3 & 2)) goto L_80004d90;
    cr0 = CMPS(r26, 0);
    if ((cr0 & 2)) goto L_80004d90;
    r31 = 0x0u;
    r28 = r23;
    r29 = r24;
L_80004d00:
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001dff8)(W(r3), W(r4), W(r5), W(r6));
    r30 = L8(r3);
    f1 = f26;
    r3 = r17;
    f2 = f25;
    { w3d_u32 t_ = r30; r0 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r0 + r30 + ca; r30 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
    r4 = r28;
    r5 = r29;
    r6 = r31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float))A8000519c)(W(r3), W(r4), W(r5), W(r6), (float)f1, (float)f2);
    cr0 = CMPS(r30, 0);
    r9 = 0x1u;
    if (!(cr0 & 2)) goto L_80004d4c;
    r9 = 0x0u;
L_80004d4c:
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_80004d5c;
    r0 = 0x0u;
L_80004d5c:
    r10 = r9 & r0; cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80004d84;
    r4 = L32(r1 + 8);
    r5 = (w3d_u32)(w3d_s32)(short)r23;
    r6 = (w3d_u32)(w3d_s32)(short)r24;
    r7 = r31;
    r3 = r17;
    r8 = 0x0u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_80004d90;
L_80004d84:
    r31 = r31 + 1;
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 4)) goto L_80004d00;
L_80004d90:
    if (!(cr2 & 2)) goto L_8000515c;
    r9 = r17 + 65536;
    r19 = 0x0u;
    S32(r1 + 24, r9);
    cr7 = CMPS(r19, 1);
L_80004da4:
    r10 = L32(r1 + 24);
    r0 = r19 << 2;
    r9 = r10 - 32704;
    r11 = L32(r9 + r0);
    r10 = r0;
    r0 = r19 + 1;
    S32(r1 + 28, r0);
    cr0 = CMPS(r11, 0);
    if ((cr0 & 2)) goto L_80005150;
    r9 = 0x3u;
    cr0 = CMPS(r19, 0);
    S32(r1 + 12, r9);
    if ((cr0 & 2)) goto L_80004de4;
    if (!(cr7 & 2)) goto L_80004de4;
    r11 = 0x4u;
    S32(r1 + 12, r11);
L_80004de4:
    r0 = r19 + 1;
    r9 = r21 + 52;
    S32(r1 + 28, r0);
    r18 = L32(r9 + r10);
    { w3d_u32 t_ = r18; r23 = (w3d_u32)1 - t_; ca = ((w3d_u32)1 >= t_); }
    cr0 = CMPS(r23, r18);
    if (!(cr0 & 8)) goto L_80005150;
    r9 = D(0x80370000u);
    f23 = LF(D(0x80368eecu));
L_80004e08:
    { w3d_u32 t_ = r18; r26 = (w3d_u32)1 - t_; ca = ((w3d_u32)1 >= t_); }
    r9 = r23 + 1;
    S32(r1 + 32, r9);
    cr0 = CMPS(r26, r18);
    if (!(cr0 & 8)) goto L_80005144;
    r22 = r15 + r23;
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    r10 = (w3d_u32)(w3d_s32)(short)r22;
    f28 = LD(D(0x80368ee0u));
    cr2 = CMPS(r23, 0);
    f24 = LF(D(0x80368ee8u));
    S32(r1 + 16, r10);
L_80004e3c:
    r25 = r16 + r26;
    r3 = r21;
    r11 = (w3d_u32)(w3d_s32)(short)r25;
    r4 = r22;
    S32(r1 + 20, r11);
    r5 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8001df1c)(W(r3), W(r4), W(r5));
    r24 = 0x0u;
    r0 = r26 + 1;
    r27 = r3;
    S32(r1 + 36, r0);
L_80004e68:
    r9 = r24 + 1;
    cr0 = CMPS(r27, 0);
    S32(r1 + 40, r9);
    if ((cr0 & 2)) goto L_8000512c;
    r8 = LS16(r27 + 28);
    r10 = (w3d_u32)(w3d_s32)(short)r22;
    r9 = LS16(r27 + 30);
    r7 = r24 << 4;
    r0 = LS16(r27 + 32);
    r11 = r7 + r27;
    S32(r1 + 44, r10);
    r10 = L32(r1 + 20);
    r0 = r0 - r8;
    r9 = r10 - r9;
    r9 = (w3d_s32)r9 * (w3d_s32)r0;
    r10 = L32(r11 + 36);
    r0 = L32(r1 + 16);
    r11 = (w3d_u32)(w3d_s32)(short)r25;
    S32(r1 + 48, r11);
    r9 = r9 + r0;
    r11 = r9 - r8;
    r0 = L8(r10 + r11);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8000512c;
    r10 = r7 + r27;
    r11 = r11 << 2;
    r9 = r10;
    { w3d_u32 t_ = r26; r0 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r8 = L32(r9 + 68);
    r30 = r0 ^ r26;
    r9 = L32(r10 + 100);
    r30 = r30 - r0;
    { w3d_u32 t_ = r23; r10 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    f0 = LF(r8 + r11);
    r31 = r10 ^ r23;
    f13 = LF(r9 + r11);
    r31 = r31 - r10;
    r4 = r19;
    f30 = (float)(f13 - f26);
    r5 = r31;
    f29 = (float)(f0 - f25);
    r6 = r30;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800203a0)(W(r3), W(r4), W(r5), W(r6));
    f31 = LF(r3);
    r4 = r19;
    r3 = r21;
    r5 = r31;
    r6 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800203cc)(W(r3), W(r4), W(r5), W(r6));
    f12 = LF(r3);
    cr0 = CMPF(f30, f31);
    if (!(cr0 & 8)) goto L_8000512c;
    cr0 = CMPF(f30, f12);
    if (!(cr0 & 4)) goto L_8000512c;
    cr0 = CMPF(f29, f31);
    if (!(cr0 & 8)) goto L_8000512c;
    cr0 = CMPF(f29, f12);
    if (!(cr0 & 4)) goto L_8000512c;
    r28 = r22;
    r29 = r25;
    r7 = 0x1u;
    cr3 = CMPS(r23, 0);
    if (!(cr2 & 4)) goto L_80004f6c;
    r7 = 0xffffffffu;
L_80004f6c:
    r14 = 0x1u;
    cr4 = CMPS(r26, 0);
    if (!(cr4 & 4)) goto L_80004f7c;
    r14 = 0xffffffffu;
L_80004f7c:
    r8 = D(0x80370000u);
    f27 = LF(D(0x80368ed8u));
    if ((cr4 & 2)) goto L_80004fc4;
    r0 = r31 ^ 0x80000000u;
    S32(r1 + 148, r0);
    r11 = r9;
    r0 = 0x43300000u;
    r10 = r30 ^ 0x80000000u;
    S32(r1 + 144, r0);
    f13 = LDS(r1 + 144);
    S32(r1 + 148, r10);
    f13 = f13 - f28;
    S32(r1 + 144, r0);
    f13 = (float)f13;
    f0 = LDS(r1 + 144);
    f0 = f0 - f28;
    f0 = (float)f0;
    f27 = (float)(f13 / f0);
L_80004fc4:
    f0 = (float)(f30 + f29);
    r20 = 0x0u;
    f30 = LF(D(0x80368ed8u));
    f0 = (float)(f0 * f24);
    cr0 = CMPF(f31, f12);
    if (!(cr0 & 4)) goto L_800050f0;
    f13 = (float)(f31 - f12);
    f0 = (float)(f31 - f0);
    f30 = (float)(f0 / f13);
    goto L_800050f0;
L_80004fec:
    r0 = r28 - r15;
    r9 = r29 - r16;
    { w3d_u32 t_ = r0; r10 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    { w3d_u32 t_ = r9; r11 = (w3d_u32)((w3d_s32)t_ >> 31); ca = SRAWCA(t_, 31); }
    r31 = r10 ^ r0;
    r30 = r11 ^ r9;
    r31 = r31 - r10;
    r30 = r30 - r11;
    cr0 = CMPS(r28, r22);
    if (!(cr0 & 2)) goto L_8000501c;
    cr0 = CMPS(r29, r25);
    if ((cr0 & 2)) goto L_80005090;
L_8000501c:
    S32(r1 + 56, r7);
    r4 = r19;
    r5 = r31;
    r6 = r30;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800203cc)(W(r3), W(r4), W(r5), W(r6));
    f31 = LF(r3);
    r4 = r19;
    r5 = r31;
    r6 = r30;
    r3 = r21;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800203a0)(W(r3), W(r4), W(r5), W(r6));
    f13 = LF(r3);
    f0 = (float)(f23 - f30);
    r3 = r21;
    r4 = r28;
    f0 = (float)(f0 * f13);
    r5 = r29;
    f31 = __builtin_fmaf((float)f31, (float)f30, (float)f0);
    r6 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e1a0)(W(r3), W(r4), W(r5), W(r6));
    f0 = LF(r3);
    r7 = L32(r1 + 56);
    f0 = (float)(f0 - f26);
    cr0 = CMPF(f0, f31);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_80005090;
    r20 = 0x1u;
    goto L_80005108;
L_80005090:
    if ((cr4 & 2)) goto L_800050e0;
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_800050e0;
    r0 = r31 ^ 0x80000000u;
    S32(r1 + 148, r0);
    r11 = r9;
    r0 = 0x43300000u;
    r10 = r30 ^ 0x80000000u;
    S32(r1 + 144, r0);
    f13 = LDS(r1 + 144);
    S32(r1 + 148, r10);
    f13 = f13 - f28;
    S32(r1 + 144, r0);
    f13 = (float)f13;
    f0 = LDS(r1 + 144);
    f0 = f0 - f28;
    f0 = (float)f0;
    f13 = (float)(f13 / f0);
    cr0 = CMPF(f13, f27);
    if (!(cr0 & 4)) goto L_800050ec;
L_800050e0:
    if ((cr3 & 2)) goto L_80005108;
    r28 = r28 + r7;
    goto L_800050f0;
L_800050ec:
    r29 = r29 + r14;
L_800050f0:
    cr0 = CMPS(r28, r15);
    if (!(cr0 & 2)) goto L_80004fec;
    cr0 = CMPS(r29, r16);
    if (!(cr0 & 2)) goto L_80004fec;
    cr0 = CMPS(r24, 0);
    if (!(cr0 & 2)) goto L_80004fec;
L_80005108:
    cr0 = CMPS(r20, 0);
    if (!(cr0 & 2)) goto L_8000512c;
    r5 = L32(r1 + 44);
    r7 = r24;
    r6 = L32(r1 + 48);
    r3 = r17;
    r4 = L32(r1 + 8);
    r8 = L32(r1 + 12);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800055b8)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
L_8000512c:
    r24 = L32(r1 + 40);
    cr0 = CMPS(r24, 1);
    if (!(cr0 & 4)) goto L_80004e68;
    r26 = L32(r1 + 36);
    cr0 = CMPS(r26, r18);
    if ((cr0 & 8)) goto L_80004e3c;
L_80005144:
    r23 = L32(r1 + 32);
    cr0 = CMPS(r23, r18);
    if ((cr0 & 8)) goto L_80004e08;
L_80005150:
    r19 = L32(r1 + 28);
    cr7 = CMPS(r19, 1);
    if (!(cr7 & 4)) goto L_80004da4;
L_8000515c:
    r12 = L32(r1 + 156);
    cr2 = (r12 >> 20) & 15; cr3 = (r12 >> 16) & 15; cr4 = (r12 >> 12) & 15;
    r1 = r1 + 304;
    return r3;
}

// 0x8000776c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8000776c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = 0x31u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A80007ccc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x8000cfe4 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8000d004 en 8000cff0
__attribute__((weak)) w3d_u32 A8000cfe4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8000d004)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x8000e204 FUN_8000e204 no verificada: desde bytes PPC
// Llama a settings_read_float, read_int_property, ai_bomber_radius, matrix3_axis_angle, body_predict_position. Usa las cadenas "Bomber.GroundSpeed", "Bomber.BlitzDuration", "Bomber.NumBombs". Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8000e204(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[648];
    w3d_u32 r1 = h2g(frame) + 632;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r14 = 0, r15 = 0, r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f15 = 0, f16 = 0, f17 = 0, f18 = 0, f19 = 0, f20 = 0, f21 = 0, f22 = 0, f23 = 0, f24 = 0, f25 = 0, f26 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 632; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r9 = r1 + 8;
    f11 = LF(r29 + 24);
    r10 = r29 + 24;
    f12 = LF(r10 + 4);
    r7 = D(0x80370000u);
    f0 = LF(r10 + 8);
    r8 = D(0x80370000u);
    SF(r1 + 8, f11);
    r11 = r1 + 64;
    SF(r9 + 8, f0);
    r25 = r10;
    f13 = LF(D(0x80369f8cu));
    r0 = r1 + 128;
    SF(r9 + 4, f12);
    r4 = r1 + 228;
    f0 = LF(D(0x80369f90u));
    f19 = f13;
    SF(r1 + 64, f13);
    r9 = D(0x80370000u);
    SF(r11 + 4, f0);
    r8 = D(0x80370000u);
    SF(r11 + 8, f0);
    r9 = D(0x80369f44u);
    r11 = L32(D(0x804aa6d8u));
    f22 = f0;
    f13 = LF(r10 + 4);
    r3 = r1 + 224;
    f12 = LF(r10 + 8);
    r19 = r29 + 48;
    r10 = r1 + 80;
    S32(r1 + 268, r0);
    SF(r1 + 80, f11);
    r0 = 0x0u;
    S32(r1 + 260, r10);
    r20 = r19;
    SF(r1 + 84, f13);
    f16 = f22;
    SF(r1 + 88, f12);
    r14 = D(0x80370000u);
    f17 = LF(D(0x80369f88u));
    r16 = 0x43300000u;
    f18 = LF(r11 + 36);
    S32(r1 + 248, r0);
    r15 = L32(r11 + 484);
    S32(r1 + 224, r9);
    r3 = A800fc270(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80370000u);
    r4 = r1 + 236;
    r9 = D(0x80369f58u);
    r3 = r1 + 232;
    S32(r1 + 232, r9);
    r9 = r1 + 96;
    S32(r1 + 264, r9);
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80370000u);
    r4 = r1 + 244;
    r9 = D(0x80369f78u);
    r3 = r1 + 240;
    S32(r1 + 240, r9);
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r29;
    r17 = r1 + 24;
    f1 = ((float (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8000e094)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r0 = L32(r1 + 236);
    r10 = 0x43300000u;
    r9 = D(0x80370000u);
    S32(r1 + 420, r0);
    f28 = f1;
    f13 = LD(D(0x80369f98u));
    f11 = (float)(f28 + f28);
    S32(r1 + 416, r10);
    r9 = D(0x80370000u);
    f12 = LF(r1 + 228);
    r8 = D(0x80370000u);
    f0 = LDS(r1 + 416);
    r10 = r1 + 48;
    f15 = LF(D(0x80369fc4u));
    f23 = f13;
    f0 = f0 - f13;
    r9 = r1 + 36;
    f0 = (float)f0;
    f21 = LD(D(0x80369fb0u));
    f20 = __builtin_fmaf((float)f12, (float)f0, (float)f11);
    S32(r1 + 252, r9);
    S32(r1 + 256, r10);
    r21 = r1 + 112;
    f20 = (float)(f20 * f20);
L_8000e3b8:
    r11 = D(0x80370000u);
    r9 = D(0x80370000u);
    f4 = LF(D(0x80369fa4u));
    r10 = D(0x80370000u);
    f0 = LF(D(0x80369fa8u));
    r11 = D(0x80370000u);
    f4 = (float)(f22 * f4);
    f1 = LF(D(0x80369f90u));
    f4 = (float)(f4 / f0);
    f2 = LF(D(0x80369f8cu));
    r3 = r17;
    r18 = 0x0u;
    f3 = f1;
    ((void (*)(w3d_oarg, float, float, float, float))A801f6480)(W(r3), (float)f1, (float)f2, (float)f3, (float)f4);
    SF(r1 + 112, f19);
    SF(r21 + 4, f16);
    r11 = r9;
    SF(r21 + 8, f16);
    r0 = L32(r1 + 236);
    f10 = LF(r1 + 116);
    f13 = LF(r1 + 36);
    S32(r1 + 420, r0);
    f8 = LF(r1 + 112);
    f13 = (float)(f10 * f13);
    f0 = LF(r1 + 24);
    f9 = LF(r1 + 120);
    f12 = LF(r1 + 48);
    f0 = __builtin_fmaf((float)f8, (float)f0, (float)f13);
    S32(r1 + 416, r16);
    r0 = L32(r1 + 244);
    f12 = __builtin_fmaf((float)f9, (float)f12, (float)f0);
    f13 = LDS(r1 + 416);
    SF(r1 + 128, f12);
    r9 = L32(r1 + 252);
    f13 = f13 - f23;
    S32(r1 + 420, r0);
    f13 = (float)f13;
    f0 = LF(r9 + 4);
    f11 = LF(r17 + 4);
    S32(r1 + 416, r16);
    f10 = (float)(f10 * f0);
    r10 = L32(r1 + 256);
    f8 = __builtin_fmaf((float)f8, (float)f11, (float)f10);
    f0 = LDS(r1 + 416);
    f12 = LF(r10 + 4);
    f10 = LF(r1 + 228);
    f0 = f0 - f23;
    f9 = __builtin_fmaf((float)f9, (float)f12, (float)f8);
    f11 = LF(r1 + 112);
    f10 = (float)(f10 * f13);
    SF(r1 + 132, f9);
    f0 = (float)f0;
    f9 = LF(r1 + 116);
    f10 = (float)(f10 / f0);
    f6 = LF(r9 + 8);
    f0 = LF(r1 + 128);
    f7 = LF(r17 + 8);
    f8 = LF(r10 + 8);
    SF(r1 + 96, f0);
    f13 = LF(r1 + 132);
    f12 = LF(r1 + 120);
    r0 = L32(r1 + 96);
    SF(r1 + 100, f13);
    S32(r29 + 48, r0);
    r11 = L32(r1 + 264);
    f9 = (float)(f9 * f6);
    f11 = __builtin_fmaf((float)f11, (float)f7, (float)f9);
    f12 = __builtin_fmaf((float)f12, (float)f8, (float)f11);
    SF(r1 + 136, f12);
    f0 = f12;
    SF(r1 + 104, f0);
    r0 = L32(r11 + 4);
    r9 = L32(r11 + 8);
    S32(r19 + 4, r0);
    S32(r19 + 8, r9);
    f0 = LF(r29 + 48);
    f0 = (float)(f0 * f10);
    SF(r1 + 112, f0);
    f13 = LF(r19 + 4);
    f12 = LF(r19 + 8);
    f13 = (float)(f13 * f10);
    SF(r1 + 96, f0);
    f12 = (float)(f12 * f10);
    SF(r1 + 100, f13);
    SF(r1 + 104, f12);
    SF(r1 + 116, f13);
    SF(r1 + 120, f12);
L_8000e514:
    r0 = r18 ^ 0x80000000u;
    S32(r1 + 420, r0);
    r10 = D(0x80370000u);
    f12 = LF(D(0x80369fb8u));
    r28 = 0x0u;
    S32(r1 + 416, r16);
    f13 = LF(r1 + 96);
    f0 = LDS(r1 + 416);
    f9 = LF(r1 + 100);
    f0 = f0 - f21;
    f11 = LF(r1 + 104);
    f0 = (float)f0;
    f8 = LF(r1 + 8);
    f0 = (float)(f0 * f12);
    f10 = LF(r1 + 12);
    f12 = LF(r1 + 16);
    f13 = (float)(f13 * f0);
    f11 = (float)(f11 * f0);
    SF(r1 + 144, f13);
    f8 = (float)(f8 + f13);
    SF(r1 + 152, f11);
    f9 = (float)(f9 * f0);
    SF(r1 + 112, f8);
    f10 = (float)(f10 + f9);
    SF(r1 + 148, f9);
    f12 = (float)(f12 + f11);
    SF(r1 + 116, f10);
    SF(r1 + 120, f12);
    SF(r1 + 160, f8);
    SF(r1 + 164, f10);
    SF(r1 + 168, f12);
    r0 = L32(r1 + 112);
    r9 = L32(r21 + 4);
    r11 = L32(r21 + 8);
    S32(r29 + 24, r0);
    S32(r25 + 4, r9);
    S32(r25 + 8, r11);
    r9 = L32(D(0x804aa750u));
    f29 = LF(D(0x80369f90u));
    r11 = L32(r9);
    r0 = L32(r9 + 4);
    r0 = r0 - r11;
    { w3d_u32 t_ = r0; r11 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); cr0 = CMPS(r11, 0); }
    if (!(cr0 & 4)) goto L_8000e8a8;
    r24 = r25;
    f24 = f29;
L_8000e5cc:
    r11 = L32(D(0x804aa750u));
    r10 = r28 << 2;
    f10 = LF(r29 + 24);
    r22 = r28 + 1;
    r9 = L32(r11);
    r31 = L32(r9 + r10);
    r11 = r31 + 16;
    f12 = LF(r31 + 16);
    f13 = LF(r11 + 8);
    f0 = LF(r11 + 4);
    f10 = (float)(f12 - f10);
    SF(r1 + 120, f13);
    SF(r1 + 116, f0);
    SF(r1 + 112, f12);
    f12 = LF(r24 + 4);
    f11 = LF(r24 + 8);
    f0 = (float)(f0 - f12);
    f0 = (float)(f0 * f0);
    f13 = (float)(f13 - f11);
    f10 = __builtin_fmaf((float)f10, (float)f10, (float)f0);
    f13 = __builtin_fmaf((float)f13, (float)f13, (float)f10);
    cr0 = CMPF(f13, f20);
    if (!(cr0 & 8)) goto L_8000e888;
    r3 = L32(r1 + 268);
    r4 = r31;
    f1 = f18;
    r30 = 0x0u;
    w3d_open_sret((void *)A800196dc, W(r3), W(r4), 0, 0, 0, 0, 0, (float)f1, (float)f2, (float)f3, (float)f4, (float)f5, (float)f6, (float)f7, (float)f8);
    r8 = L32(r1 + 244);
    f27 = LF(r31 + 12);
    f31 = LF(D(0x80369f90u));
    cr0 = CMPS(r30, r8);
    if (!(cr0 & 8)) goto L_8000e864;
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    r10 = D(0x80370000u);
    f30 = LF(D(0x80369fb8u));
    f25 = LF(D(0x80369fbcu));
    r23 = 0x43300000u;
    f26 = LF(D(0x80369fc0u));
    r26 = r25;
    r27 = r1 + 192;
    r31 = r20;
L_8000e678:
    r0 = r30 ^ 0x80000000u;
    S32(r1 + 420, r0);
    r11 = r9;
    f11 = LF(r1 + 96);
    S32(r1 + 416, r23);
    f10 = LF(r29 + 24);
    f13 = LDS(r1 + 416);
    S32(r1 + 420, r8);
    f13 = f13 - f21;
    f9 = LF(r1 + 100);
    S32(r1 + 416, r23);
    f13 = (float)f13;
    f8 = LF(r1 + 104);
    f0 = LDS(r1 + 416);
    f12 = LF(r1 + 132);
    f0 = f0 - f23;
    f1 = LF(r1 + 128);
    f0 = (float)f0;
    f7 = LF(r1 + 136);
    f0 = (float)(f0 - f19);
    f0 = (float)(f0 * f30);
    f13 = (float)(f13 - f0);
    f11 = (float)(f11 * f13);
    f8 = (float)(f8 * f13);
    SF(r1 + 176, f11);
    f9 = (float)(f9 * f13);
    SF(r1 + 200, f8);
    f10 = (float)(f10 + f11);
    SF(r1 + 196, f9);
    SF(r1 + 184, f8);
    f1 = (float)(f10 - f1);
    SF(r1 + 180, f9);
    SF(r1 + 192, f10);
    f13 = LF(r26 + 4);
    f13 = (float)(f13 + f9);
    SF(r1 + 196, f13);
    f12 = (float)(f13 - f12);
    f12 = (float)(f12 * f12);
    f0 = LF(r26 + 8);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f12);
    SF(r1 + 144, f10);
    f0 = (float)(f0 + f8);
    SF(r1 + 148, f13);
    f7 = (float)(f0 - f7);
    SF(r1 + 200, f0);
    f1 = __builtin_fmaf((float)f7, (float)f7, (float)f1);
    SF(r1 + 152, f0);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    cr0 = CMPF(f1, f28);
    if (!(cr0 & 8)) goto L_8000e854;
    f0 = (float)(f28 - f1);
    f0 = (float)(f0 / f28);
    f7 = (float)(f27 * f0);
    f31 = (float)(f31 + f7);
    cr0 = CMPF(f0, f24);
    if (!(cr0 & 4)) goto L_8000e854;
    cr0 = CMPF(f0, f25);
    if (!(cr0 & 8)) goto L_8000e854;
    cr0 = CMPS(r15, 0);
    if ((cr0 & 2)) goto L_8000e854;
    r9 = L32(r1 + 244);
    r9 = r9 - 1;
    cr0 = CMPS(r30, r9);
    if (!(cr0 & 8)) goto L_8000e854;
    f0 = LF(r1 + 148);
    f11 = LF(r1 + 116);
    f9 = LF(r1 + 144);
    f11 = (float)(f11 - f0);
    f10 = LF(r1 + 112);
    f0 = LF(r1 + 152);
    f12 = (float)(f11 * f11);
    f13 = LF(r1 + 120);
    f10 = (float)(f10 - f9);
    f12 = __builtin_fmaf((float)f10, (float)f10, (float)f12);
    SF(r1 + 192, f10);
    f13 = (float)(f13 - f0);
    SF(r1 + 196, f11);
    f12 = __builtin_fmaf((float)f13, (float)f13, (float)f12);
    SF(r1 + 200, f13);
    SF(r1 + 408, f12);
    SF(r1 + 208, f10);
    r0 = L32(r1 + 408);
    SF(r1 + 212, f11);
    SF(r1 + 216, f13);
    r9 = r0;
    r11 = L32(D(0x804ab8d0u));
    r10 = ROTL(r9, 15) & 0x7fu;
    r9 = ROTL(r9, 9) & 0xffu;
    f9 = LF(r29 + 48);
    r0 = L8(r11 + r10);
    { w3d_u32 t_ = r9; r9 = (w3d_u32)380 - t_; ca = ((w3d_u32)380 >= t_); }
    r9 = ROTL(r9, 22) & 0xff800000u;
    r0 = r0 << 15;
    r9 = r9 | r0;
    S32(r1 + 408, r9);
    f8 = LF(r1 + 408);
    f0 = (float)(f8 * f8);
    f0 = (float)(f0 * f12);
    f0 = (float)(f26 - f0);
    f0 = (float)(f0 * f8);
    f8 = (float)(f0 * f30);
    f10 = (float)(f10 * f8);
    f13 = (float)(f13 * f8);
    SF(r1 + 192, f10);
    f11 = (float)(f11 * f8);
    SF(r1 + 200, f13);
    SF(r1 + 196, f11);
    f12 = LF(r27 + 4);
    f0 = LF(r27 + 8);
    SF(r1 + 176, f10);
    SF(r1 + 180, f12);
    SF(r1 + 184, f0);
    f13 = LF(r31 + 4);
    f11 = LF(r31 + 8);
    f12 = (float)(f12 * f13);
    f10 = __builtin_fmaf((float)f10, (float)f9, (float)f12);
    f0 = __builtin_fmaf((float)f0, (float)f11, (float)f10);
    f0 = (float)(f7 * f0);
    f31 = __builtin_fmaf((float)f0, (float)f30, (float)f31);
L_8000e854:
    r8 = L32(r1 + 244);
    r30 = r30 + 1;
    cr0 = CMPS(r30, r8);
    if ((cr0 & 8)) goto L_8000e678;
L_8000e864:
    cr0 = CMPF(f31, f24);
    if (!(cr0 & 4)) goto L_8000e888;
    r0 = L32(r29 + 16);
    cr0 = CMPS(r28, r0);
    if ((cr0 & 2)) goto L_8000e884;
    r9 = L32(D(0x804aa6d8u));
    f0 = LF(r9 + 100);
    f31 = (float)(f31 * f0);
L_8000e884:
    f29 = (float)(f29 + f31);
L_8000e888:
    r9 = L32(D(0x804aa750u));
    r28 = r22;
    r11 = L32(r9);
    r0 = L32(r9 + 4);
    r0 = r0 - r11;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPS(r28, r0);
    if ((cr0 & 8)) goto L_8000e5cc;
L_8000e8a8:
    cr0 = CMPF(f29, f17);
    if (!(cr0 & 4)) goto L_8000e900;
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8000a9ac)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r0 = r3; cr0 = CMPS(r0, 0);
    S32(r1 + 248, r0);
    if (!(cr0 & 2)) goto L_8000e8cc;
    f22 = (float)(f22 + f15);
    goto L_8000e908;
L_8000e8cc:
    r7 = L32(r29 + 48);
    f17 = f29;
    r0 = L32(r20 + 4);
    r9 = L32(r20 + 8);
    r11 = L32(r29 + 24);
    r10 = L32(r25 + 4);
    r8 = L32(r25 + 8);
    S32(r1 + 64, r7);
    S32(r1 + 68, r0);
    S32(r1 + 72, r9);
    S32(r1 + 80, r11);
    S32(r1 + 84, r10);
    S32(r1 + 88, r8);
L_8000e900:
    { w3d_u32 t_ = r18; r18 = t_ + (w3d_u32)1; ca = r18 < t_; cr0 = CMPS(r18, 0); }
    if ((cr0 & 2)) goto L_8000e514;
L_8000e908:
    r9 = D(0x80370000u);
    r10 = D(0x80370000u);
    f0 = LF(D(0x80369fc8u));
    f13 = LF(D(0x80369fa0u));
    f22 = (float)(f22 + f0);
    cr0 = CMPF(f22, f13);
    if ((cr0 & 8)) goto L_8000e3b8;
    r0 = L32(r1 + 64);
    r3 = r29;
    r11 = L32(r1 + 72);
    r9 = L32(r1 + 68);
    r4 = L32(r1 + 248);
    S32(r29 + 48, r0);
    r10 = L32(r1 + 80);
    S32(r20 + 4, r9);
    S32(r20 + 8, r11);
    r11 = L32(r1 + 260);
    r0 = L32(r11 + 8);
    r9 = L32(r11 + 4);
    S32(r29 + 24, r10);
    S32(r25 + 8, r0);
    S32(r25 + 4, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8000b6bc)(W(r3), W(r4));
    r1 = r1 + 632;
    return r3;
}

// 0x8000f804 FUN_8000f804 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: directed_ready. Llama a sqrt, grid_probe_named, grid_position, hop_test_height, path_queue_build_timed. Hace 2 llamadas virtuales. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8000f804(w3d_u32 r3, float s1) {
    alignas(16) char frame[272];
    w3d_u32 r1 = h2g(frame) + 256;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 256; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804aa750u));
    r31 = r3;
    r11 = L32(r31 + 16);
    r8 = r1 + 8;
    r10 = L32(r9);
    r7 = r31 + 24;
    r11 = r11 << 2;
    f10 = LF(r31 + 24);
    r9 = L32(r10 + r11);
    r25 = r8;
    r10 = D(0x80370000u);
    r11 = r1 + 40;
    f13 = LF(r9 + 16);
    r26 = r11;
    r9 = r9 + 16;
    f11 = LF(D(0x8036a074u));
    f12 = LF(r9 + 8);
    f29 = f1;
    f0 = LF(r9 + 4);
    r6 = 0x0u;
    SF(r1 + 8, f13);
    SF(r8 + 4, f0);
    SF(r8 + 8, f12);
    f0 = LF(r1 + 8);
    f10 = (float)(f10 - f0);
    SF(r1 + 40, f10);
    f0 = LF(r8 + 4);
    f13 = LF(r7 + 4);
    f13 = (float)(f13 - f0);
    SF(r1 + 44, f13);
    f0 = LF(r7 + 8);
    f12 = LF(r8 + 8);
    SF(r1 + 24, f10);
    f0 = (float)(f0 - f12);
    SF(r1 + 40, f11);
    SF(r1 + 28, f13);
    SF(r1 + 32, f0);
    SF(r1 + 48, f0);
    SF(r11 + 8, f11);
    SF(r11 + 4, f11);
    r9 = L32(r1 + 40);
    r0 = L32(r1 + 24);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8000f8fc;
    r9 = L32(r1 + 44);
    r0 = L32(r1 + 28);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8000f8fc;
    r9 = L32(r1 + 48);
    r0 = L32(r1 + 32);
    r6 = r9 ^ r0;
    { w3d_u32 t_ = r6; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r6 + ca; r6 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8000f8fc:
    cr0 = CMPS(r6, 0);
    r30 = D(0x80420000u);
    if ((cr0 & 2)) goto L_8000f96c;
    f0 = LF(r31 + 24);
    r9 = D(0x8041d3a0u);
    f11 = LF(D(0x8041d3a0u));
    r11 = r31 + 24;
    f12 = LF(D(0x8041d3a4u));
    r8 = r1 + 56;
    f13 = LF(D(0x8041d3a8u));
    f11 = (float)(f11 - f0);
    SF(r1 + 72, f11);
    r10 = r1 + 24;
    f0 = LF(r11 + 4);
    f12 = (float)(f12 - f0);
    SF(r1 + 76, f12);
    f0 = LF(r11 + 8);
    SF(r1 + 56, f11);
    f13 = (float)(f13 - f0);
    SF(r1 + 60, f12);
    SF(r1 + 64, f13);
    SF(r1 + 80, f13);
    r0 = L32(r1 + 56);
    r9 = L32(r8 + 8);
    r11 = L32(r8 + 4);
    S32(r1 + 24, r0);
    S32(r10 + 8, r9);
    S32(r10 + 4, r11);
L_8000f96c:
    f0 = LF(r1 + 28);
    f1 = LF(r1 + 24);
    f0 = (float)(f0 * f0);
    f13 = LF(r1 + 32);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    f28 = LF(D(0x8036a078u));
    r10 = D(0x80370000u);
    f13 = LF(r1 + 24);
    f1 = (float)(f28 / f1);
    f12 = LF(r1 + 28);
    f0 = LF(r1 + 32);
    f27 = LF(D(0x8036a080u));
    f30 = LF(D(0x8036a07cu));
    f31 = (float)(f29 + f27);
    f0 = (float)(f0 * f1);
    f13 = (float)(f13 * f1);
    SF(r1 + 32, f0);
    f12 = (float)(f12 * f1);
    SF(r1 + 24, f13);
    SF(r1 + 28, f12);
    cr0 = CMPF(f31, f30);
    if (!(cr0 & 4)) goto L_8000f9d8;
    f30 = f31;
L_8000f9d8:
    r9 = D(0x80420000u);
    f12 = LF(r25 + 4);
    r29 = D(0x8041d3a0u);
    f13 = LF(D(0x8041d3a0u));
    f0 = LF(D(0x8041d3a4u));
    r27 = 0x0u;
    f11 = LF(r1 + 8);
    f0 = (float)(f0 - f12);
    f1 = LF(D(0x8041d3a8u));
    f12 = LF(r25 + 8);
    f0 = (float)(f0 * f0);
    f13 = (float)(f13 - f11);
    f13 = __builtin_fmaf((float)f13, (float)f13, (float)f0);
    f1 = (float)(f1 - f12);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f13);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f0 = (float)(f29 - f27);
    cr0 = CMPF(f1, f0);
    if (!(cr0 & 4)) goto L_8000faf8;
    cr0 = CMPF(f1, f31);
    if (!(cr0 & 8)) goto L_8000faf8;
    f13 = LF(D(0x8041d3a0u));
    f11 = LF(r1 + 8);
    r30 = r31 + 36;
    f0 = LF(D(0x8041d3a8u));
    f9 = LF(D(0x8041d3a4u));
    f11 = (float)(f11 - f13);
    f10 = LF(r25 + 4);
    f12 = LF(r25 + 8);
    SF(r1 + 40, f11);
    f10 = (float)(f10 - f9);
    f12 = (float)(f12 - f0);
    SF(r1 + 44, f10);
    SF(r1 + 48, f12);
    r0 = L32(r1 + 40);
    r11 = L32(r26 + 4);
    S32(r31 + 36, r0);
    r9 = L32(r26 + 8);
    S32(r30 + 4, r11);
    S32(r30 + 8, r9);
    f0 = LF(r30 + 4);
    f1 = LF(r31 + 36);
    f13 = LF(r30 + 8);
    f0 = (float)(f0 * f0);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    SF(r1 + 56, f11);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    SF(r1 + 60, f10);
    SF(r1 + 64, f12);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f1 = (float)(f28 / f1);
    f13 = LF(r31 + 36);
    r0 = L32(r1 + 8);
    r9 = r31 + 24;
    r10 = L32(r25 + 8);
    r3 = 0x1u;
    r11 = L32(r25 + 4);
    f13 = (float)(f13 * f1);
    SF(r31 + 36, f13);
    f0 = LF(r30 + 4);
    f13 = LF(r30 + 8);
    f0 = (float)(f0 * f1);
    f13 = (float)(f13 * f1);
    SF(r30 + 4, f0);
    SF(r30 + 8, f13);
    S32(r31 + 24, r0);
    f0 = LF(r31 + 40);
    f0 = (float)(f0 + f28);
    SF(r31 + 40, f0);
    S32(r9 + 8, r10);
    S32(r9 + 4, r11);
    goto L_8000fe90;
L_8000faf8:
    r0 = L32(D(0x804aa6dcu));
    r9 = 0x0u;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8000fb14;
    r0 = L32(D(0x804aa6e0u));
    { w3d_u32 t_ = r0; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r0 + ca; r9 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8000fb14:
    cr0 = CMPS(r9, 0);
    if (!(cr0 & 2)) goto L_8000fb24;
    r3 = 0x0u;
    goto L_8000fe90;
L_8000fb24:
    r11 = L32(r31 + 16);
    r0 = 0x0u;
    S32(r1 + 136, r0);
    r9 = L32(D(0x804aa750u));
    r11 = r11 << 2;
    r3 = L32(D(0x804b1758u));
    r10 = L32(r9);
    r9 = L32(r10 + r11);
    r24 = L32(r9 + 8);
    r4 = r24;
    ((void (*)(w3d_oarg, w3d_oarg))A8001f1d8)(W(r3), W(r4));
    f11 = LF(r1 + 24);
    r4 = L32(D(0x804b1758u));
    f13 = LF(r1 + 28);
    f11 = (float)(f11 * f30);
    f0 = LF(r1 + 32);
    r30 = r31 + 24;
    f9 = LF(r1 + 8);
    f13 = (float)(f13 * f30);
    f10 = LF(r25 + 4);
    f0 = (float)(f0 * f30);
    f12 = LF(r25 + 8);
    f9 = (float)(f9 + f11);
    SF(r1 + 40, f9);
    f10 = (float)(f10 + f13);
    f12 = (float)(f12 + f0);
    SF(r1 + 44, f10);
    SF(r1 + 48, f12);
    r3 = r26;
    r11 = L32(r1 + 40);
    r5 = r30;
    r9 = L32(r26 + 4);
    r28 = r30;
    r0 = L32(r26 + 8);
    S32(r31 + 24, r11);
    S32(r30 + 4, r9);
    S32(r30 + 8, r0);
    SF(r1 + 96, f0);
    SF(r1 + 64, f0);
    SF(r1 + 88, f11);
    SF(r1 + 92, f13);
    SF(r1 + 56, f11);
    SF(r1 + 60, f13);
    SF(r1 + 72, f9);
    SF(r1 + 76, f10);
    SF(r1 + 80, f12);
    { w3d_open_vec3 t_ = ((w3d_open_vec3 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001f9f0)(W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10)); w3d_open_store(r3, t_); }
    r0 = L32(r1 + 40);
    r9 = L32(r26 + 4);
    r11 = L32(r26 + 8);
    S32(r31 + 24, r0);
    S32(r30 + 4, r9);
    S32(r30 + 8, r11);
    r3 = L32(D(0x804b1758u));
    f0 = LF(r1 + 12);
    f31 = LF(r31 + 28);
    f31 = (float)(f31 - f0);
    f31 = __builtin_fabs(f31);
    f1 = ((float (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001e2dc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    cr0 = CMPF(f31, f1);
    if ((cr0 & 4)) goto L_8000fc70;
    r11 = L32(D(0x804aa6d8u));
    r9 = D(0x80420000u);
    r29 = D(0x8041d3a0u);
    r30 = r1 + 136;
    f1 = LF(r11 + 188);
    r3 = r30;
    r4 = D(0x8041d3a0u);
    r5 = r28;
    r6 = 0x96u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float))A80009674)(W(r3), W(r4), W(r5), W(r6), (float)f1);
    r27 = r3; cr0 = CMPS(r27, 0);
    if (!(cr0 & 2)) goto L_8000fc78;
    r0 = L8(r31 + 64);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8000fc70;
    r9 = L32(D(0x804aa6d8u));
    r3 = r30;
    r4 = D(0x8041d3a0u);
    r5 = r28;
    f1 = LF(r9 + 188);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, float, w3d_oarg, w3d_oarg, w3d_oarg))A80009a94)(W(r3), W(r4), W(r5), (float)f1, W(r6), W(r7), W(r8));
    r27 = r3;
L_8000fc70:
    cr0 = CMPS(r27, 0);
    if ((cr0 & 2)) goto L_8000fe54;
L_8000fc78:
    f9 = LF(r1 + 24);
    r29 = 0x0u;
    f10 = LF(r1 + 28);
    r30 = r1 + 140;
    f11 = LF(r1 + 32);
    f9 = (float)(f9 * f29);
    f12 = LF(r1 + 8);
    f10 = (float)(f10 * f29);
    f13 = LF(r25 + 4);
    f11 = (float)(f11 * f29);
    f0 = LF(r25 + 8);
    f12 = (float)(f12 + f9);
    SF(r1 + 40, f12);
    f13 = (float)(f13 + f10);
    f0 = (float)(f0 + f11);
    SF(r1 + 44, f13);
    SF(r1 + 48, f0);
    r0 = L32(r1 + 40);
    r9 = L32(r26 + 4);
    r11 = L32(r26 + 8);
    S32(r31 + 24, r0);
    r3 = L32(r1 + 136);
    S32(r28 + 4, r9);
    S32(r28 + 8, r11);
    SF(r1 + 56, f9);
    SF(r1 + 60, f10);
    SF(r1 + 64, f11);
    SF(r1 + 72, f12);
    SF(r1 + 76, f13);
    SF(r1 + 80, f0);
    S32(r1 + 140, r29);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80003e78)(W(r3));
    r9 = D(0x80370000u);
    r4 = r3;
    f1 = LF(D(0x8036a074u));
    r3 = r30;
    r5 = r28;
    r6 = 0x1eu;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float))A80009674)(W(r3), W(r4), W(r5), W(r6), (float)f1);
    r0 = L32(D(0x804b175cu));
    r27 = r3;
    cr0 = CMPS(r0, 11);
    if (!(cr0 & 2)) goto L_8000fd28;
    r27 = 0x1u;
L_8000fd28:
    r3 = L32(r1 + 140);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8000fd48;
    r9 = L32(r3 + 16);
    r4 = 0x3u;
    r0 = L32(r9 + 8);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8000fd48:
    S32(r1 + 140, r29);
    cr0 = CMPS(r27, 0);
    if (!(cr0 & 2)) goto L_8000fd7c;
    r3 = L32(r1 + 136);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8000fd74;
    r9 = L32(r3 + 16);
    r4 = 0x3u;
    r0 = L32(r9 + 8);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8000fd74:
    S32(r1 + 136, r27);
    goto L_8000fe54;
L_8000fd7c:
    r3 = L32(r1 + 136);
    r4 = r28;
    r5 = 0x1u;
    r30 = r31 + 36;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80003424)(W(r3), W(r4), W(r5));
    f0 = LF(r31 + 24);
    f11 = LF(r1 + 8);
    f13 = LF(r28 + 8);
    f9 = LF(r28 + 4);
    f11 = (float)(f11 - f0);
    f10 = LF(r25 + 4);
    f12 = LF(r25 + 8);
    SF(r1 + 40, f11);
    f10 = (float)(f10 - f9);
    f12 = (float)(f12 - f13);
    SF(r1 + 44, f10);
    SF(r1 + 48, f12);
    r0 = L32(r1 + 40);
    r11 = L32(r26 + 4);
    S32(r31 + 36, r0);
    r9 = L32(r26 + 8);
    S32(r30 + 4, r11);
    S32(r30 + 8, r9);
    f0 = LF(r30 + 4);
    f1 = LF(r31 + 36);
    f13 = LF(r30 + 8);
    f0 = (float)(f0 * f0);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    SF(r1 + 64, f12);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    SF(r1 + 56, f11);
    SF(r1 + 60, f10);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x80370000u);
    f13 = LF(r31 + 36);
    f12 = LF(D(0x8036a078u));
    r0 = L32(r1 + 8);
    f1 = (float)(f12 / f1);
    r9 = L32(r25 + 8);
    r11 = L32(r25 + 4);
    f13 = (float)(f13 * f1);
    SF(r31 + 36, f13);
    f0 = LF(r30 + 4);
    f13 = LF(r30 + 8);
    f0 = (float)(f0 * f1);
    f13 = (float)(f13 * f1);
    SF(r30 + 4, f0);
    SF(r30 + 8, f13);
    S32(r31 + 24, r0);
    f0 = LF(r31 + 40);
    f0 = (float)(f0 + f12);
    SF(r31 + 40, f0);
    S32(r28 + 8, r9);
    S32(r28 + 4, r11);
L_8000fe54:
    r3 = L32(D(0x804b1758u));
    r4 = r24;
    ((void (*)(w3d_oarg, w3d_oarg))A8001f25c)(W(r3), W(r4));
    r11 = L32(r1 + 136);
    cr0 = CMPS(r11, 0);
    if ((cr0 & 2)) goto L_8000fe7c;
    S32(r31 + 76, r11);
    r9 = L32(r11 + 44);
    r9 = r9 + 1;
    S32(r11 + 44, r9);
L_8000fe7c:
    r0 = L32(r1 + 136);
    r3 = 0x1u;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8000fe90;
    r3 = 0x0u;
L_8000fe90:
    r1 = r1 + 256;
    return r3;
}

// 0x80010898 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80010630 en 800108a4
__attribute__((weak)) w3d_u32 A80010898(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80010630)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x8001528c heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8001523c en 80015298
__attribute__((weak)) w3d_u32 A8001528c(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8001523c)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x800152ac heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80015264 en 800152b8
__attribute__((weak)) w3d_u32 A800152ac(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80015264)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x800152fc FUN_800152fc no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: ai_select_team. Llama a placement_record, vector, artillery_mode, index_query, read_int_property. Usa las cadenas "ChooseWorm.Enabled".
// aviso: lee r3 tras void 80006ff4 en 800153bc
__attribute__((weak)) w3d_u32 A800152fc(w3d_u32 r3) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r29 = D(0x80420000u);
    S32(D(0x804aa6c0u), r31);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r30 = D(0x8041d3acu);
    r0 = L8(r3 + 213);
    r3 = r31;
    S32(D(0x804aa6ccu), r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800154b4)(W(r3));
    S32(D(0x804aa6d0u), r3);
    r3 = r31;
    r3 = A80015588(r3);
    r9 = r3;
    r11 = D(0x80420000u);
    r0 = L32(r9);
    r7 = D(0x8041d3a0u);
    r8 = L32(r9 + 8);
    r3 = r31;
    r10 = L32(r9 + 4);
    S32(D(0x8041d3a0u), r0);
    S32(D(0x8041d3a8u), r8);
    S32(D(0x8041d3acu), r0);
    S32(D(0x8041d3b4u), r8);
    S32(D(0x8041d3a4u), r10);
    S32(D(0x8041d3b0u), r10);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800154e0)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    S32(D(0x804aa6dcu), r3);
    r3 = L32(D(0x804aa6c0u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fcb4c)(W(r3));
    r9 = D(0x80370000u);
    S32(D(0x804aa6d8u), r3);
    r9 = D(0x8036a588u);
    S32(D(0x804aa6c8u), r31);
    S32(r1 + 8, r9);
    r3 = r1 + 8;
    r4 = r1 + 12;
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r1 + 12);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_800153c8;
    r0 = L32(D(0x804aa598u));
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_800153c8;
    S32(D(0x804aa6c4u), r31);
    r3 = (w3d_u32)((w3d_oarg (*)())A80006ff4)();
    r0 = 0x1u;
    S32(D(0x804aa59cu), r0);
L_800153c8:
    r1 = r1 + 32;
    return r3;
}

// 0x800153dc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A800153dc(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r3 = L32(r3 + 220);
    r1 = r1 + 8;
    return r3;
}

// 0x80015564 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80015564(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r3 = L32(r3 + 140);
    r1 = r1 + 8;
    return r3;
}

// 0x80015588 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80015588(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r3 = r3 + 80;
    r1 = r1 + 8;
    return r3;
}

// 0x800172e4 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8000756c en 800172f0
__attribute__((weak)) w3d_u32 A800172e4(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A8000756c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x8001750c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8001750c(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = A800172e4(r3, r4);
    r1 = r1 + 8;
    return r3;
}

// 0x8001781c heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 800174cc en 80017828
__attribute__((weak)) w3d_u32 A8001781c(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A800174cc)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x80017848 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80017380 en 80017854
__attribute__((weak)) w3d_u32 A80017848(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80017380)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x80017a70 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80017a04 en 80017a7c
__attribute__((weak)) w3d_u32 A80017a70(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80017a04)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x80017b60 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8000756c en 80017b6c
__attribute__((weak)) w3d_u32 A80017b60(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A8000756c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x8001aaf8 FUN_8001aaf8 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: aim_search. Llama a motion_set_target, ballistic_solve, planner_trace_distance, sqrt. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8001aaf8(w3d_u32 r3, float s1, float s2) {
    alignas(16) char frame[224];
    w3d_u32 r1 = h2g(frame) + 208;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, ctr = 0;
    { w3d_u32 t_ = r1 - 208; S32(t_, r1); r1 = t_; }
    r26 = r3;
    f30 = f1;
    r3 = D(0x80420000u);
    f31 = f2;
    r3 = D(0x8041e780u);
    r4 = r26;
    ((void (*)(w3d_oarg, w3d_oarg))A801182c0)(W(r3), W(r4));
    r18 = D(0x80420000u);
    f12 = LF(D(0x804b1774u));
    r9 = D(0x80370000u);
    f13 = LF(D(0x804b1770u));
    r11 = D(0x80370000u);
    f11 = LF(D(0x8036afc0u));
    f13 = (float)(f13 - f12);
    f10 = LF(D(0x8036afc4u));
    f9 = __builtin_fmaf((float)f13, (float)f31, (float)f12);
    f1 = __builtin_fmaf((float)f13, (float)f30, (float)f12);
    f0 = (float)(f9 - f1);
    f29 = (float)(f0 / f11);
    cr0 = CMPF(f29, f10);
    if (!(cr0 & 2)) goto L_8001ab78;
    r9 = D(0x80370000u);
    f29 = LF(D(0x8036afc8u));
    f1 = (float)(f1 - f29);
L_8001ab78:
    SF(r1 + 40, f10);
    r9 = D(0x80460000u);
    r0 = L32(D(0x8045e788u));
    r11 = D(0x8045e788u);
    r10 = L32(D(0x8045e78cu));
    r9 = D(0x80420000u);
    r8 = L32(D(0x8045e790u));
    r6 = r1 + 40;
    S32(D(0x8041e850u), r0);
    r5 = D(0x8041e850u);
    SF(r6 + 4, f10);
    r7 = r1 + 52;
    SF(r6 + 8, f10);
    r9 = D(0x80370000u);
    S32(D(0x8041e854u), r10);
    r11 = r1 + 76;
    S32(D(0x8041e858u), r8);
    f31 = (float)(f1 + f29);
    SF(r1 + 52, f10);
    r10 = D(0x80370000u);
    SF(r7 + 8, f10);
    r19 = 0x0u;
    SF(r7 + 4, f10);
    SF(r1 + 64, f10);
    r7 = r1 + 64;
    f0 = LF(D(0x8036afd0u));
    SF(r7 + 4, f10);
    SF(r7 + 8, f10);
    f0 = (float)(f9 + f0);
    SF(r1 + 76, f10);
    cr0 = CMPF(f31, f0);
    SF(r11 + 8, f10);
    f30 = LF(D(0x8036afccu));
    SF(r11 + 4, f10);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8001adac;
    r25 = D(0x8041e850u);
    r21 = r6;
    r22 = r7;
    r23 = r1 + 52;
    r24 = r11;
    f28 = f0;
    r20 = D(0x80420000u);
L_8001ac24:
    r3 = D(0x8041e780u);
    f1 = f31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, float))A801182ec)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001ad08;
    r30 = D(0x8041e780u);
    r31 = D(0x8041e818u);
    f1 = LF(D(0x8041e834u));
    r3 = D(0x8041e818u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, float))A8001b830)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001ac68;
    r0 = L32(D(0x8041e818u));
    r19 = 0x1u;
    r9 = L32(D(0x8041e820u));
    r11 = L32(D(0x8041e81cu));
    goto L_8001acc8;
L_8001ac68:
    r27 = D(0x80420000u);
    r7 = L32(D(0x8041e820u));
    r10 = L32(D(0x8041e85cu));
    r28 = D(0x8041e85cu);
    r0 = L32(D(0x8041e818u));
    r29 = D(0x8041e78cu);
    r9 = L32(D(0x8041e81cu));
    r3 = D(0x8041e78cu);
    f1 = LF(D(0x8041e830u));
    r8 = L32(D(0x8041e860u));
    r11 = L32(D(0x8041e864u));
    S32(r1 + 40, r10);
    S32(r21 + 4, r8);
    S32(r21 + 8, r11);
    S32(r1 + 64, r0);
    S32(r22 + 4, r9);
    S32(r22 + 8, r7);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, float))A8001b830)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001acd8;
    r0 = L32(D(0x8041e78cu));
    r19 = 0x1u;
    r9 = L32(D(0x8041e794u));
    r11 = L32(D(0x8041e790u));
L_8001acc8:
    S32(D(0x8041e850u), r0);
    S32(D(0x8041e858u), r9);
    S32(D(0x8041e854u), r11);
    goto L_8001adac;
L_8001acd8:
    r11 = L32(D(0x8041e85cu));
    r8 = L32(D(0x8041e78cu));
    r7 = L32(D(0x8041e794u));
    r9 = L32(D(0x8041e790u));
    r10 = L32(D(0x8041e864u));
    r0 = L32(D(0x8041e860u));
    S32(r1 + 52, r11);
    S32(r23 + 4, r0);
    S32(r23 + 8, r10);
    S32(r1 + 76, r8);
    S32(r24 + 4, r9);
    S32(r24 + 8, r7);
L_8001ad08:
    r0 = 0x2u;
    r10 = r1 + 40;
    ctr = r0;
    f9 = LF(r26);
    f10 = LF(r26 + 4);
    f1 = (float)(f31 + f29);
    f11 = LF(r26 + 8);
    r6 = r1 + 8;
    r7 = r1 + 24;
    r8 = r10;
L_8001ad30:
    f0 = LF(r8 + 4);
    f13 = LF(r8);
    f0 = (float)(f10 - f0);
    f12 = LF(r8 + 8);
    f0 = (float)(f0 * f0);
    f13 = (float)(f9 - f13);
    f13 = __builtin_fmaf((float)f13, (float)f13, (float)f0);
    f12 = (float)(f11 - f12);
    f0 = __builtin_fmaf((float)f12, (float)f12, (float)f13);
    cr0 = CMPF(f0, f30);
    if (!(cr0 & 8)) goto L_8001ad90;
    r11 = L32(r10 + 24);
    f30 = f0;
    r0 = L32(r10 + 28);
    r9 = L32(r10 + 32);
    S32(r1 + 8, r11);
    S32(r6 + 4, r0);
    S32(r6 + 8, r9);
    r0 = L32(r10);
    r9 = L32(r10 + 4);
    r11 = L32(r10 + 8);
    S32(r1 + 24, r0);
    S32(r7 + 4, r9);
    S32(r7 + 8, r11);
L_8001ad90:
    r10 = r10 + 12;
    r8 = r8 + 12;
    --ctr; if (ctr != 0) goto L_8001ad30;
    f31 = f1;
    cr0 = CMPF(f31, f28);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if ((cr0 & 1)) goto L_8001ac24;
L_8001adac:
    cr0 = CMPS(r19, 0);
    if (!(cr0 & 2)) goto L_8001ae08;
    f1 = f30;
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = r1 + 8;
    r8 = L32(r1 + 8);
    r3 = L32(r9 + 8);
    r6 = r1 + 24;
    r4 = L32(r9 + 4);
    r11 = D(0x80420000u);
    r30 = L32(r6 + 8);
    r5 = D(0x8041e850u);
    r9 = L32(r6 + 4);
    r10 = D(0x80420000u);
    r0 = L32(r1 + 24);
    r7 = D(0x8041e85cu);
    S32(D(0x8041e850u), r8);
    S32(D(0x8041e858u), r3);
    S32(D(0x8041e85cu), r0);
    S32(D(0x8041e864u), r30);
    SF(D(0x804b1778u), f1);
    S32(D(0x8041e854u), r4);
    S32(D(0x8041e860u), r9);
L_8001ae08:
    r3 = r19;
    r1 = r1 + 208;
    return r3;
}

// 0x8001ae30 FUN_8001ae30 no verificada: desde bytes PPC
// Llama a motion_set_target, ballistic_launch_for_time, sqrt, set_c, ballistic_sample. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8001ae30(w3d_u32 r3) {
    alignas(16) char frame[240];
    w3d_u32 r1 = h2g(frame) + 224;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 224; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r25 = D(0x80420000u);
    r3 = D(0x80420000u);
    r4 = r29;
    r3 = D(0x8041e780u);
    r20 = D(0x8041e780u);
    ((void (*)(w3d_oarg, w3d_oarg))A801182c0)(W(r3), W(r4));
    r21 = D(0x80420000u);
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    f13 = LF(D(0x8036afd8u));
    r24 = D(0x8041e78cu);
    f0 = LF(D(0x804b1770u));
    r9 = D(0x80370000u);
    f27 = LF(D(0x8036afdcu));
    f29 = f13;
    f30 = LF(D(0x8036afd4u));
    f28 = (float)(f0 * f0);
    SF(D(0x804b1768u), f13);
    r23 = D(0x8041e850u);
    r22 = 0x0u;
    r19 = D(0x80370000u);
    r26 = r1 + 8;
    r27 = r1 + 24;
L_8001aeb4:
    f13 = LF(D(0x804b1768u));
    r3 = D(0x8041e780u);
    f0 = LF(D(0x8036afe0u));
    f31 = (float)(f13 * f0);
    f1 = f31;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, float))A801188c4)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001b034;
    r30 = D(0x8041e780u);
    r28 = 0x0u;
    r31 = D(0x8041e78cu);
    f13 = LF(D(0x8041e78cu));
    f12 = LF(D(0x8041e790u));
    f11 = LF(D(0x8041e794u));
    f0 = (float)(f12 * f12);
    f0 = __builtin_fmaf((float)f13, (float)f13, (float)f0);
    f1 = __builtin_fmaf((float)f11, (float)f11, (float)f0);
    cr0 = CMPF(f1, f28);
    if (!(cr0 & 4)) goto L_8001af84;
    SF(r1 + 40, f13);
    r28 = 0x1u;
    SF(r1 + 44, f12);
    SF(r1 + 48, f11);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f1 = (float)(f29 / f1);
    f13 = LF(r1 + 40);
    f12 = LF(r1 + 44);
    r4 = r1 + 56;
    f0 = LF(r1 + 48);
    r3 = D(0x8041e780u);
    f11 = LF(D(0x804b1770u));
    f0 = (float)(f0 * f1);
    f13 = (float)(f13 * f1);
    SF(r1 + 48, f0);
    f12 = (float)(f12 * f1);
    SF(r1 + 40, f13);
    SF(r1 + 44, f12);
    f0 = (float)(f0 * f11);
    f13 = (float)(f13 * f11);
    SF(r1 + 64, f0);
    f12 = (float)(f12 * f11);
    SF(r1 + 56, f13);
    SF(r1 + 60, f12);
    SF(r1 + 72, f13);
    SF(r1 + 76, f12);
    SF(r1 + 80, f0);
    r3 = A80118268(r3, r4);
    r4 = D(0x80420000u);
    r3 = D(0x8041e780u);
    r4 = D(0x8041e85cu);
    f1 = f31;
    ((void (*)(w3d_oarg, w3d_oarg, float))A800d75f0)(W(r3), W(r4), (float)f1);
L_8001af84:
    f1 = f31;
    r3 = D(0x8041e78cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, float))A8001b830)(W(r3), (float)f1);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001afc0;
    cr0 = CMPS(r28, 0);
    if (!(cr0 & 2)) goto L_8001afc0;
    r0 = L32(D(0x8041e78cu));
    r22 = 0x1u;
    r9 = L32(D(0x8041e794u));
    r11 = L32(D(0x8041e790u));
    S32(D(0x8041e850u), r0);
    S32(D(0x8041e858u), r9);
    S32(D(0x8041e854u), r11);
    goto L_8001b04c;
L_8001afc0:
    r10 = D(0x80420000u);
    f11 = LF(r29 + 4);
    r8 = D(0x8041e85cu);
    f13 = LF(r29);
    f12 = LF(D(0x8041e860u));
    f10 = LF(D(0x8041e85cu));
    f11 = (float)(f11 - f12);
    f0 = LF(r29 + 8);
    f12 = LF(D(0x8041e864u));
    f13 = (float)(f13 - f10);
    f11 = (float)(f11 * f11);
    f0 = (float)(f0 - f12);
    f13 = __builtin_fmaf((float)f13, (float)f13, (float)f11);
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f13);
    cr0 = CMPF(f0, f30);
    if (!(cr0 & 8)) goto L_8001b034;
    r0 = L32(D(0x8041e78cu));
    f30 = f0;
    r9 = L32(D(0x8041e790u));
    r11 = L32(D(0x8041e794u));
    S32(r1 + 8, r0);
    S32(r26 + 4, r9);
    S32(r26 + 8, r11);
    r10 = L32(D(0x8041e85cu));
    r9 = L32(D(0x8041e864u));
    r0 = L32(D(0x8041e860u));
    S32(r1 + 24, r10);
    S32(r27 + 4, r0);
    S32(r27 + 8, r9);
L_8001b034:
    f0 = LF(D(0x804b1768u));
    f0 = (float)(f0 + f29);
    cr0 = CMPF(f0, f27);
    SF(D(0x804b1768u), f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if ((cr0 & 1)) goto L_8001aeb4;
L_8001b04c:
    cr0 = CMPS(r22, 0);
    if (!(cr0 & 2)) goto L_8001b0a8;
    f1 = f30;
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = r1 + 8;
    r8 = L32(r1 + 8);
    r3 = L32(r9 + 8);
    r6 = r1 + 24;
    r4 = L32(r9 + 4);
    r11 = D(0x80420000u);
    r30 = L32(r6 + 8);
    r5 = D(0x8041e850u);
    r9 = L32(r6 + 4);
    r10 = D(0x80420000u);
    r0 = L32(r1 + 24);
    r7 = D(0x8041e85cu);
    S32(D(0x8041e850u), r8);
    S32(D(0x8041e858u), r3);
    S32(D(0x8041e85cu), r0);
    S32(D(0x8041e864u), r30);
    SF(D(0x804b1778u), f1);
    S32(D(0x8041e854u), r4);
    S32(D(0x8041e860u), r9);
L_8001b0a8:
    r3 = r22;
    r1 = r1 + 224;
    return r3;
}

// 0x8001b0d4 FUN_8001b0d4 no verificada: desde bytes PPC
// Llama a motion_set_target, aim_search, resource_property, channel_value, value_get. Hace 4 llamadas virtuales. Usa las cadenas "Bounce.MinSpeed", "Water.Level". Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8001b0d4(w3d_u32 r3) {
    alignas(16) char frame[256];
    w3d_u32 r1 = h2g(frame) + 240;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f27 = 0, f28 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 240; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r31 = 0x0u;
    r3 = D(0x80420000u);
    r4 = r30;
    r3 = D(0x8041e780u);
    ((void (*)(w3d_oarg, w3d_oarg))A801182c0)(W(r3), W(r4));
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    f1 = LF(D(0x8036b000u));
    r3 = r30;
    f2 = LF(D(0x8036b004u));
    r3 = A8001aaf8(r3, f1, f2);
    r10 = D(0x80420000u);
    r9 = D(0x80460000u);
    r11 = L32(D(0x8045e788u));
    r7 = D(0x8041e850u);
    r0 = L32(D(0x8041e850u));
    r8 = D(0x8045e788u);
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_8001b16c;
    r9 = L32(D(0x8045e78cu));
    r0 = L32(D(0x8041e854u));
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8001b16c;
    r9 = L32(D(0x8045e790u));
    r0 = L32(D(0x8041e858u));
    r31 = r9 ^ r0;
    { w3d_u32 t_ = r31; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r31 + ca; r31 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8001b16c:
    cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_8001b184;
L_8001b174:
    r3 = 0x0u;
    goto L_8001b4e8;
L_8001b17c:
    r21 = 0x1u;
    goto L_8001b390;
L_8001b184:
    r9 = D(0x80370000u);
    r4 = r1 + 8;
    r9 = D(0x8036afe4u);
    S32(r1 + 8, r31);
    S32(r1 + 88, r9);
    r3 = r1 + 88;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r22 = D(0x80420000u);
    r3 = L32(r1 + 8);
    r23 = D(0x80420000u);
    r28 = D(0x8041e85cu);
    r29 = D(0x8041e850u);
    ((void (*)())A80342a74)();
    r21 = 0x0u;
    f1 = ((float (*)(w3d_oarg))A80178df0)(W(r3));
    r25 = 0x0u;
    r9 = D(0x80370000u);
    S32(r1 + 16, r31);
    r9 = D(0x8036aff4u);
    f27 = f1;
    S32(r1 + 92, r9);
    r4 = r1 + 16;
    r3 = r1 + 92;
    r17 = D(0x80370000u);
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r18 = D(0x80370000u);
    r3 = L32(r1 + 16);
    r26 = r1 + 24;
    r27 = r1 + 40;
    r19 = D(0x80420000u);
    ((void (*)())A80342a74)();
    r20 = D(0x80420000u);
    r31 = r1 + 56;
    f1 = ((float (*)(w3d_oarg))A80178df0)(W(r3));
    r9 = D(0x80420000u);
    f12 = LF(r30 + 4);
    r11 = D(0x8041e838u);
    f10 = LF(D(0x8041e838u));
    f11 = LF(D(0x8041e83cu));
    r24 = D(0x8041e838u);
    f0 = LF(r30);
    r10 = D(0x80370000u);
    f12 = (float)(f12 - f11);
    f9 = LF(D(0x8041e840u));
    f13 = LF(r30 + 8);
    f0 = (float)(f0 - f10);
    f11 = LF(D(0x8036b008u));
    r9 = D(0x80370000u);
    f12 = (float)(f12 * f12);
    r11 = D(0x80370000u);
    f13 = (float)(f13 - f9);
    f30 = LF(D(0x8036b00cu));
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f12);
    f31 = LF(D(0x8036b010u));
    f28 = (float)(f1 - f11);
    f29 = __builtin_fmaf((float)f13, (float)f13, (float)f0);
L_8001b264:
    f1 = f27;
    r3 = 0x0u;
    f2 = f28;
    ((void (*)(float, float))A8001b964)((float)f1, (float)f2);
    f11 = LF(D(0x8041e860u));
    f13 = LF(r30 + 4);
    f12 = LF(r30);
    f13 = (float)(f13 - f11);
    f10 = LF(D(0x8041e85cu));
    f0 = LF(r30 + 8);
    f13 = (float)(f13 * f13);
    f11 = LF(D(0x8041e864u));
    f12 = (float)(f12 - f10);
    f12 = __builtin_fmaf((float)f12, (float)f12, (float)f13);
    f0 = (float)(f0 - f11);
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f12);
    cr0 = CMPF(f0, f30);
    if (!(cr0 & 8)) goto L_8001b2f4;
    r9 = L32(D(0x8041e850u));
    f30 = f0;
    r0 = L32(D(0x8041e858u));
    f31 = (float)(f31 + f31);
    S32(r1 + 24, r9);
    r11 = L32(D(0x8041e854u));
    S32(r26 + 8, r0);
    r10 = L32(D(0x8041e85cu));
    S32(r26 + 4, r11);
    r9 = L32(D(0x8041e860u));
    r0 = L32(D(0x8041e864u));
    f0 = LF(D(0x8036b008u));
    S32(r1 + 40, r10);
    S32(r27 + 4, r9);
    cr0 = CMPF(f30, f0);
    S32(r27 + 8, r0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 3) & 1)) & 1) << 0);
    if ((cr0 & 1)) goto L_8001b17c;
L_8001b2f4:
    f12 = LF(r1 + 44);
    r25 = r25 + 1;
    f13 = LF(D(0x8041e83cu));
    f11 = LF(r1 + 40);
    f13 = (float)(f13 - f12);
    f0 = LF(D(0x8041e838u));
    f12 = LF(r1 + 48);
    f13 = (float)(f13 * f13);
    f1 = LF(D(0x8041e840u));
    f0 = (float)(f0 - f11);
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f13);
    f1 = (float)(f1 - f12);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = (float)(f29 / f1);
    f1 = ((float (*)(float))A802e83cc)((float)f1);
    f1 = (float)(f31 * f1);
    f1 = ((float (*)(float, float))A802e8094)((float)f1, (float)f2);
    f12 = LF(r1 + 24);
    cr0 = CMPS(r25, 9);
    f13 = LF(r1 + 28);
    f0 = LF(r1 + 32);
    f12 = (float)(f12 * f1);
    SF(r1 + 56, f12);
    f13 = (float)(f13 * f1);
    f0 = (float)(f0 * f1);
    SF(r1 + 60, f13);
    SF(r1 + 64, f0);
    SF(r1 + 80, f0);
    SF(r1 + 72, f12);
    SF(r1 + 76, f13);
    r0 = L32(r1 + 56);
    r9 = L32(r31 + 4);
    r11 = L32(r31 + 8);
    f0 = LF(D(0x8036b010u));
    S32(D(0x8041e850u), r0);
    S32(D(0x8041e854u), r9);
    f31 = (float)(f31 * f0);
    S32(D(0x8041e858u), r11);
    if (!(cr0 & 4)) goto L_8001b264;
L_8001b390:
    cr0 = CMPS(r21, 0);
    if (!(cr0 & 2)) goto L_8001b3ec;
    f1 = f30;
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = r1 + 24;
    r8 = L32(r1 + 24);
    r3 = L32(r9 + 8);
    r6 = r1 + 40;
    r4 = L32(r9 + 4);
    r11 = D(0x80420000u);
    r30 = L32(r6 + 8);
    r5 = D(0x8041e850u);
    r9 = L32(r6 + 4);
    r10 = D(0x80420000u);
    r0 = L32(r1 + 40);
    r7 = D(0x8041e85cu);
    S32(D(0x8041e850u), r8);
    S32(D(0x8041e858u), r3);
    S32(D(0x8041e85cu), r0);
    S32(D(0x8041e864u), r30);
    SF(D(0x804b1778u), f1);
    S32(D(0x8041e854u), r4);
    S32(D(0x8041e860u), r9);
L_8001b3ec:
    r10 = D(0x80420000u);
    r9 = D(0x80460000u);
    r11 = L32(D(0x8045e788u));
    r6 = D(0x8041e850u);
    r0 = L32(D(0x8041e850u));
    r7 = D(0x8045e788u);
    r8 = 0x0u;
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_8001b434;
    r9 = L32(D(0x8045e78cu));
    r0 = L32(D(0x8041e854u));
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8001b434;
    r9 = L32(D(0x8045e790u));
    r0 = L32(D(0x8041e858u));
    r8 = r9 ^ r0;
    { w3d_u32 t_ = r8; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r8 + ca; r8 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8001b434:
    cr0 = CMPS(r8, 0);
    if (!(cr0 & 2)) goto L_8001b470;
    r9 = D(0x80420000u);
    r11 = D(0x8041e850u);
    f1 = LF(D(0x8041e850u));
    f0 = LF(D(0x8041e854u));
    f13 = LF(D(0x8041e858u));
    f0 = (float)(f0 * f0);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x80370000u);
    f0 = LF(D(0x8036b014u));
    cr0 = CMPF(f1, f0);
    if (!(cr0 & 4)) goto L_8001b4ac;
L_8001b470:
    r3 = L32(r1 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001b48c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8001b48c:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001b174;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_8001b174;
L_8001b4ac:
    r3 = L32(r1 + 16);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001b4c8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8001b4c8:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001b4e4;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8001b4e4:
    r3 = r21;
L_8001b4e8:
    r1 = r1 + 240;
    return r3;
}

// 0x8001b510 FUN_8001b510 no verificada: desde bytes PPC
// Llama a set_weapon_index, eye_vector, trajectory_setup. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8001b510(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[88];
    w3d_u32 r1 = h2g(frame) + 72;
    w3d_u32 r0 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r29 = 0, r30 = 0;
    double f0 = 0, f1 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0;
    { w3d_u32 t_ = r1 - 72; S32(t_, r1); r1 = t_; }
    r29 = r5;
    r30 = r4;
    ((void (*)(w3d_oarg))A8001a758)(W(r3));
    r3 = r30;
    r4 = 0x1u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8001a770)(W(r3), W(r4), W(r5), W(r6));
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    f11 = LF(D(0x8036b01cu));
    r10 = D(0x80420000u);
    f0 = LF(D(0x8036b018u));
    r3 = D(0x8041e844u);
    f13 = LF(r29);
    r9 = D(0x80370000u);
    f11 = (float)(f11 / f0);
    f7 = LF(D(0x8041e844u));
    f9 = LF(D(0x8041e848u));
    r8 = r1 + 8;
    f8 = LF(D(0x8041e84cu));
    r30 = D(0x80420000u);
    f12 = LF(r29 + 8);
    r10 = D(0x8041e850u);
    f0 = LF(r29 + 4);
    r4 = r8;
    f10 = LF(D(0x8036b020u));
    r29 = r1 + 24;
    r7 = 0x1u;
    r5 = r29;
    r6 = 0x3e8u;
    f13 = (float)(f13 - f7);
    SF(r1 + 8, f13);
    f0 = (float)(f0 - f9);
    f12 = (float)(f12 - f8);
    SF(r1 + 24, f13);
    SF(r1 + 12, f0);
    SF(r1 + 16, f12);
    SF(r1 + 28, f0);
    SF(r1 + 32, f12);
    r0 = L32(r1 + 8);
    r9 = L32(r8 + 4);
    r11 = L32(r8 + 8);
    S32(D(0x8041e850u), r0);
    S32(D(0x8041e854u), r9);
    S32(D(0x8041e858u), r11);
    f0 = LF(D(0x8041e854u));
    f12 = LF(D(0x8041e858u));
    f13 = LF(D(0x8041e850u));
    f0 = (float)(f0 * f11);
    f12 = (float)(f12 * f11);
    SF(r1 + 12, f0);
    f13 = (float)(f13 * f11);
    SF(r1 + 16, f12);
    SF(r1 + 8, f13);
    SF(r1 + 40, f13);
    SF(r1 + 44, f0);
    SF(r1 + 48, f12);
    SF(r1 + 24, f10);
    SF(r29 + 8, f10);
    SF(r29 + 4, f10);
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float))A800b0824)(W(r3), W(r4), W(r5), W(r6), W(r7), (float)f1);
    r9 = D(0x80440000u);
    r0 = L32(D(0x804b1764u));
    r11 = D(0x8043ae20u);
    r10 = L32(D(0x8043ae20u));
    r8 = L32(D(0x8043ae28u));
    r9 = D(0x80420000u);
    r7 = L32(D(0x8043ae24u));
    cr7 = CMPS(r0, 990);
    r11 = D(0x8041e85cu);
    S32(D(0x8041e85cu), r10);
    S32(D(0x8041e864u), r8);
    cr7 = (cr7 & ~1u) | (((((cr7 >> 1) & 1) | ((cr7 >> 2) & 1)) & 1) << 0);
    r3 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    r3 = r3 & 0x1u;
    S32(D(0x8041e860u), r7);
    r1 = r1 + 72;
    return r3;
}

// 0x8001d388 FUN_8001d388 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: layer_setup. Llama a float_vector_fill_insert, sol35f2_byte_fill_insert. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8001d388(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5) {
    alignas(16) char frame[112];
    w3d_u32 r1 = h2g(frame) + 96;
    w3d_u32 r0 = 0, r11 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f31 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 96; S32(t_, r1); r1 = t_; }
    f13 = LF(r4 + 116);
    r9 = D(0x80370000u);
    f0 = LF(r3 + 4);
    f12 = LF(r4 + 104);
    r7 = r10;
    f0 = (float)(f0 - f13);
    f8 = LF(D(0x8036b730u));
    f0 = (float)(f0 / f12);
    r11 = r10;
    r8 = r10;
    f13 = LF(r3 + 12);
    f12 = LF(r3 + 16);
    r9 = D(0x80370000u);
    f11 = LF(r3 + 24);
    r28 = r3 + 68;
    f31 = LF(D(0x8036b734u));
    r23 = r1 + 8;
    r24 = r1 + 12;
    r25 = r1 + 16;
    r30 = r3 + 36;
    r29 = r3 + 100;
    r26 = 0x2u;
    f0 = (float)(f0 + f8);
    f10 = FCTIWZ(f0);
    SDS(r1 + 40, f10);
    r10 = L32(r1 + 44);
    S16(r3 + 28, r10);
    r10 = (w3d_u32)(w3d_s32)(short)r10;
    f0 = LF(r4 + 124);
    f10 = LF(r4 + 104);
    f13 = (float)(f13 - f0);
    f13 = (float)(f13 / f10);
    f13 = (float)(f13 + f8);
    f9 = FCTIWZ(f13);
    SDS(r1 + 40, f9);
    r7 = L32(r1 + 44);
    S16(r3 + 30, r7);
    r7 = (w3d_u32)(w3d_s32)(short)r7;
    f0 = LF(r4 + 116);
    f13 = LF(r4 + 104);
    f12 = (float)(f12 - f0);
    f12 = (float)(f12 / f13);
    f12 = (float)(f12 + f8);
    f7 = FCTIWZ(f12);
    SDS(r1 + 40, f7);
    r11 = L32(r1 + 44);
    r11 = r11 + 1;
    S16(r3 + 32, r11);
    r11 = (w3d_u32)(w3d_s32)(short)r11;
    f0 = LF(r4 + 124);
    r11 = r11 - r10;
    f13 = LF(r4 + 104);
    f11 = (float)(f11 - f0);
    f11 = (float)(f11 / f13);
    f11 = (float)(f11 + f8);
    f6 = FCTIWZ(f11);
    SDS(r1 + 40, f6);
    r8 = L32(r1 + 44);
    r8 = r8 + 1;
    r0 = (w3d_u32)(w3d_s32)(short)r8;
    S16(r3 + 34, r8);
    r0 = r0 - r7;
    r31 = (w3d_s32)r11 * (w3d_s32)r0;
    r27 = r31 << 2;
L_8001d49c:
    r4 = L32(r30 + 32);
    r11 = r28;
    r9 = r4;
    S32(r30 + 36, r4);
    r0 = r4 - r9;
    SF(r1 + 8, f31);
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r31, r0);
    if (!(cr0 & 8)) goto L_8001d4cc;
    r0 = r27 + r9;
    S32(r11 + 4, r0);
    goto L_8001d4dc;
L_8001d4cc:
    r5 = r31 - r0;
    r3 = r28;
    r6 = r23;
    r3 = CU(A80342bac, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8001d4dc:
    r0 = L32(r30 + 64);
    r11 = r29;
    SF(r1 + 12, f31);
    S32(r29 + 4, r0);
    r4 = L32(r30 + 68);
    r9 = L32(r30 + 64);
    r0 = r4 - r9;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r31, r0);
    if (!(cr0 & 8)) goto L_8001d510;
    r0 = r27 + r9;
    S32(r11 + 4, r0);
    goto L_8001d520;
L_8001d510:
    r5 = r31 - r0;
    r3 = r29;
    r6 = r24;
    r3 = CU(A80342bac, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8001d520:
    r0 = L32(r30);
    r9 = 0x1u;
    r10 = r30;
    S32(r30 + 4, r0);
    r11 = r0;
    S8(r1 + 16, r9);
    r4 = L32(r30 + 4);
    r0 = r4 - r11;
    cr0 = CMPU(r31, r0);
    if (!(cr0 & 8)) goto L_8001d554;
    r0 = r11 + r31;
    S32(r10 + 4, r0);
    goto L_8001d564;
L_8001d554:
    r5 = r31 - r0;
    r3 = r30;
    r6 = r25;
    r3 = CU(A80342ddc, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8001d564:
    r30 = r30 + 16;
    r29 = r29 + 16;
    r28 = r28 + 16;
    { w3d_u32 t_ = r26; r26 = t_ + (w3d_u32)-1; ca = r26 < t_; cr0 = CMPS(r26, 0); }
    if (!(cr0 & 2)) goto L_8001d49c;
    r1 = r1 + 96;
    return r3;
}

}
