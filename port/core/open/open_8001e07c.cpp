// Funciones del juego sin fuente admitida: 0x8001e07c a 0x8006d854. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A8001df1c();
__attribute__((weak)) void A80022634();
__attribute__((weak)) void A8002ae70();
__attribute__((weak)) void A80032bb0();
__attribute__((weak)) void A800358b4();
__attribute__((weak)) void A8003f240();
__attribute__((weak)) void A800418ac();
__attribute__((weak)) void A800490bc();
__attribute__((weak)) void A8004c29c();
__attribute__((weak)) void A8004c2f0();
__attribute__((weak)) void A8004c378();
__attribute__((weak)) void A8004c850();
__attribute__((weak)) void A8004ce58();
__attribute__((weak)) void A8004d54c();
__attribute__((weak)) void A8004ee4c();
__attribute__((weak)) void A80062640();
__attribute__((weak)) void A8006e71c();
__attribute__((weak)) void A800b0824();
__attribute__((weak)) void A800bd920();
__attribute__((weak)) void A800c53a0();
__attribute__((weak)) void A800d5028();
__attribute__((weak)) void A800ea748();
__attribute__((weak)) void A800ec6a8();
__attribute__((weak)) void A800ecb20();
__attribute__((weak)) void A800fc3b0();
__attribute__((weak)) void A800fc43c();
__attribute__((weak)) void A800fc550();
__attribute__((weak)) void A800fc5dc();
__attribute__((weak)) void A80126384();
__attribute__((weak)) void A80126524();
__attribute__((weak)) void A8015ab1c();
__attribute__((weak)) void A8015ab2c();
__attribute__((weak)) void A8015f5a0();
__attribute__((weak)) void A8015fd1c();
__attribute__((weak)) void A801613f0();
__attribute__((weak)) void A8016239c();
__attribute__((weak)) void A801628ec();
__attribute__((weak)) void A80162ba8();
__attribute__((weak)) void A80164514();
__attribute__((weak)) void A80164fc8();
__attribute__((weak)) void A80165254();
__attribute__((weak)) void A80178c48();
__attribute__((weak)) void A80178c54();
__attribute__((weak)) void A80178df0();
__attribute__((weak)) void A801797b4();
__attribute__((weak)) void A802098d8();
__attribute__((weak)) void A8020b680();
__attribute__((weak)) void A8020bb2c();
__attribute__((weak)) void A8020bb54();
__attribute__((weak)) void A8020bd38();
__attribute__((weak)) void A8020bd58();
__attribute__((weak)) void A8020c2e8();
__attribute__((weak)) void A8020c510();
__attribute__((weak)) void A8020c5c0();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A802e79e0();
__attribute__((weak)) void A802e82c0();
__attribute__((weak)) void A802eee50();
__attribute__((weak)) void A802eeef4();
__attribute__((weak)) void A802ef234();
__attribute__((weak)) void A80341584();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A80341884();
__attribute__((weak)) void A803426b8();

// 0x8001e07c FUN_8001e07c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: height. Llama a grid_layer_find.
__attribute__((weak)) float A8001e07c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[40];
    w3d_u32 r1 = h2g(frame) + 24;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f13 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 24; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r29 = r4;
    r31 = r5;
    r28 = r6;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8001df1c)(W(r3), W(r4), W(r5));
    r3 = r3; cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8001e104;
    r5 = LS16(r3 + 28);
    r9 = (w3d_u32)(w3d_s32)(short)r31;
    r10 = LS16(r3 + 30);
    r11 = r28 << 4;
    r0 = LS16(r3 + 32);
    r8 = r11 + r3;
    r9 = r9 - r10;
    r6 = (w3d_u32)(w3d_s32)(short)r29;
    r0 = r0 - r5;
    r11 = r8;
    r9 = (w3d_s32)r9 * (w3d_s32)r0;
    r7 = L32(r11 + 68);
    r10 = L32(r8 + 100);
    r11 = D(0x80370000u);
    f13 = LF(D(0x8036b818u));
    r9 = r9 + r6;
    r9 = r9 - r5;
    r9 = r9 << 2;
    f0 = LF(r10 + r9);
    f1 = LF(r7 + r9);
    f1 = (float)(f1 + f0);
    f1 = (float)(f1 * f13);
    goto L_8001e108;
L_8001e104:
    f1 = LF(r30 + 108);
L_8001e108:
    r1 = r1 + 24;
    return (float)f1;
}

// 0x800229ec heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80022634 en 800229f8
__attribute__((weak)) w3d_u32 A800229ec(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80022634)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x80022c6c FUN_80022c6c no verificada: desde bytes PPC
// Llama a logic_base_destroy. Hace 1 llamada virtual.
// aviso: lee r3 tras void 801628ec en 80022ce8
__attribute__((weak)) w3d_u32 A80022c6c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[64];
    w3d_u32 r1 = h2g(frame) + 48;
    w3d_u32 r0 = 0, r11 = 0, r27 = 0, r28 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 48; S32(t_, r1); r1 = t_; }
    r9 = D(0x80410000u);
    r28 = r3;
    r9 = D(0x8040ddf8u);
    r27 = r4;
    S32(r28, r9);
    r3 = L32(D(0x804aca48u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80022cac;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80022cac:
    r9 = D(0x80420000u);
    r0 = 0x0u;
    r11 = D(0x804200a4u);
    S32(D(0x804aca48u), r0);
    r9 = L32(D(0x804200a4u));
    r0 = L32(D(0x804200a8u));
    cr0 = CMPS(r9, r0);
    if ((cr0 & 2)) goto L_80022cd8;
L_80022ccc:
    r9 = r9 + 4;
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_80022ccc;
L_80022cd8:
    r0 = 0x0u;
    r3 = r28;
    S32(D(0x804aa7d4u), r0);
    r4 = r27;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A801628ec)(W(r3), W(r4));
    r1 = r1 + 48;
    return r3;
}

// 0x80022e20 FUN_80022e20 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: create_slot. Llama a sol35a3_pool_allocate, sol35f7a_pool_allocate, native_forward_copy, handle_storage_release, reference_index. Hace 3 llamadas virtuales.
__attribute__((weak)) w3d_u32 A80022e20(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[80];
    w3d_u32 r1 = h2g(frame) + 64;
    w3d_u32 r0 = 0, r11 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 64; S32(t_, r1); r1 = t_; }
    r29 = r6;
    r25 = r3;
    r3 = L32(r29);
    r26 = r4;
    r24 = r5;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80022e5c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80022e5c:
    r0 = 0x0u;
    r3 = D(0x804aca40u);
    S32(r29, r0);
    r4 = 0x10u;
    r28 = D(0x80420000u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802098d8)(W(r3), W(r4));
    r31 = D(0x804200a4u);
    r11 = L32(D(0x804200a8u));
    r27 = r1 + 8;
    r0 = L32(D(0x804200acu));
    S32(r1 + 8, r3);
    cr0 = CMPS(r11, r0);
    if (!(cr0 & 2)) goto L_80022f38;
    r9 = L32(D(0x804200a4u));
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
    if (!(cr0 & 8)) goto L_80022ec4;
    r10 = r8;
L_80022ec4:
    r0 = L32(r10);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 20, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(D(0x804200a4u));
    r30 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80022f1c;
    r9 = L32(r1 + 20);
    r11 = r1 + 24;
    r0 = L32(r1 + 24);
    r5 = r1 + 20;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80022f04;
    r5 = r11;
L_80022f04:
    r5 = L32(r5);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(D(0x804200a4u));
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80022f1c:
    r0 = L32(r1 + 24);
    r9 = L32(r1 + 20);
    r0 = r30 + r0;
    S32(D(0x804200a4u), r30);
    r9 = r30 + r9;
    S32(D(0x804200a8u), r0);
    S32(D(0x804200acu), r9);
L_80022f38:
    r0 = L32(r27);
    r3 = D(0x804aca40u);
    r11 = L32(D(0x804200a8u));
    r4 = 0x10u;
    S32(r11, r0);
    r9 = L32(D(0x804200a8u));
    r9 = r9 + 4;
    S32(D(0x804200a8u), r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A802098d8)(W(r3), W(r4));
    r9 = D(0x80410000u);
    r30 = r3;
    r0 = 0x0u;
    r9 = D(0x8040de28u);
    S32(r30 + 12, r0);
    cr0 = CMPS(r30, 0);
    S32(r30, r9);
    S32(r30 + 8, r0);
    if ((cr0 & 2)) goto L_80022f8c;
    r0 = L32(D(0x8040de34u));
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80022f8c:
    r3 = L32(r29);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80022fa8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80022fa8:
    r0 = L32(r1 + 8);
    S32(r29, r30);
    S32(r30 + 12, r0);
    r9 = L32(r29);
    r11 = L32(r9 + 12);
    S32(r11 + 8, r26);
    r9 = L32(r29);
    r11 = L32(r9 + 12);
    S32(r11 + 4, r25);
    r9 = L32(r29);
    r11 = L32(r9 + 12);
    S32(r11 + 12, r24);
    r30 = L32(D(0x804aca48u));
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80178c48)(W(r3));
    r3 = r3 + 1;
    r4 = r1 + 28;
    S32(r1 + 28, r3);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80178c54)(W(r3), W(r4));
    r3 = 0x0u;
    r1 = r1 + 64;
    return r3;
}

// 0x8002a68c heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8015fd1c en 8002a698
__attribute__((weak)) w3d_u32 A8002a68c(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8015fd1c)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x8002ad7c heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8015fd1c en 8002ad88
__attribute__((weak)) w3d_u32 A8002ad7c(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8015fd1c)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x8002b070 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8002b070(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r3 = r3 + 44;
    S32(r1 + 8, r4);
    r4 = r3;
    r3 = r1 + 8;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 16;
    return r3;
}

// 0x8002c4ec FUN_8002c4ec no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: fill.
__attribute__((weak)) w3d_u32 A8002c4ec(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r21 = r4;
    r22 = r3;
    r0 = r21 << 2;
    r25 = r5;
    r9 = r0 + r22;
    r11 = L32(r22 + r0);
    r0 = L32(r9 - 4);
    cr0 = CMPS(r21, 1);
    r26 = L32(r9 + 16);
    r11 = r11 << 2;
    r10 = L32(r9 + 36);
    r0 = r0 << 2;
    r8 = L32(r9 + 20);
    r27 = r26 >> 1;
    r29 = r22 + r11;
    r24 = r10 >> 1;
    r30 = r22 + r0;
    if (!(cr0 & 2)) goto L_8002c5fc;
    r9 = 0x0u;
    cr0 = CMPU(r9, r24);
    if (!(cr0 & 8)) goto L_8002c6b0;
    r23 = r8 << 2;
    r20 = r26 << 3;
L_8002c558:
    r31 = 0x0u;
    r28 = r9 + 1;
    r6 = r30;
    cr0 = CMPU(r31, r27);
    if (!(cr0 & 8)) goto L_8002c5e4;
    r4 = 0xaaaa0000u;
    r5 = 0x55550000u;
    r3 = r26 << 2;
    r4 = 0xaaaaaaaau;
    r5 = 0x55555555u;
    r12 = r29;
L_8002c584:
    r11 = L32(r6 + 4);
    r7 = r3 + r6;
    r9 = L32(r6);
    r31 = r31 + 1;
    r10 = L32(r3 + r6);
    cr0 = CMPU(r31, r27);
    r0 = r9 & r11;
    r8 = L32(r7 + 4);
    r9 = r9 | r11;
    r0 = r0 & r10;
    r9 = r9 | r10;
    r6 = r6 + 8;
    r10 = r0 & r8;
    r11 = r9 | r8;
    r0 = r10 << 1;
    r9 = r11 >> 1;
    r0 = r10 & r0;
    r9 = r11 | r9;
    r10 = r0 & r4;
    r11 = r9 & r5;
    r0 = r11 | r10;
    S32(r12, r0);
    r12 = r12 + 4;
    if ((cr0 & 8)) goto L_8002c584;
L_8002c5e4:
    r9 = r28;
    r30 = r30 + r20;
    r29 = r29 + r23;
    cr0 = CMPU(r9, r24);
    if ((cr0 & 8)) goto L_8002c558;
    goto L_8002c6b0;
L_8002c5fc:
    r9 = 0x0u;
    cr0 = CMPU(r9, r24);
    if (!(cr0 & 8)) goto L_8002c6b0;
    r23 = r8 << 2;
    r20 = r26 << 3;
L_8002c610:
    r31 = 0x0u;
    r28 = r9 + 1;
    r6 = r30;
    cr0 = CMPU(r31, r27);
    if (!(cr0 & 8)) goto L_8002c69c;
    r4 = 0xaaaa0000u;
    r5 = 0x55550000u;
    r3 = r26 << 2;
    r4 = 0xaaaaaaaau;
    r5 = 0x55555555u;
    r12 = r29;
L_8002c63c:
    r11 = L32(r6 + 4);
    r7 = r3 + r6;
    r9 = L32(r6);
    r31 = r31 + 1;
    r10 = L32(r3 + r6);
    cr0 = CMPU(r31, r27);
    r0 = r9 & r11;
    r8 = L32(r7 + 4);
    r9 = r9 | r11;
    r0 = r0 & r10;
    r9 = r9 | r10;
    r6 = r6 + 8;
    r10 = r0 & r8;
    r11 = r9 | r8;
    r0 = SRW(r10, r25);
    r9 = SRW(r11, r25);
    r0 = r10 & r0;
    r9 = r11 | r9;
    r10 = r0 & r4;
    r11 = r9 & r5;
    r0 = r11 | r10;
    S32(r12, r0);
    r12 = r12 + 4;
    if ((cr0 & 8)) goto L_8002c63c;
L_8002c69c:
    r9 = r28;
    r30 = r30 + r20;
    r29 = r29 + r23;
    cr0 = CMPU(r9, r24);
    if ((cr0 & 8)) goto L_8002c610;
L_8002c6b0:
    cr0 = CMPU(r21, 0x3u);
    if ((cr0 & 4)) goto L_8002c6c8;
    r3 = r22;
    r4 = r21 + 1;
    r5 = r25 << 1;
    r3 = A8002c4ec(r3, r4, r5);
L_8002c6c8:
    r1 = r1 + 56;
    return r3;
}

// 0x80035714 FUN_80035714 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: camera_set_mode. Llama a scene_timer_is_one, string_from_text, text_compare, service_mode_is_inactive, mode. Hace 2 llamadas virtuales.
__attribute__((weak)) w3d_u32 A80035714(w3d_u32 r3, w3d_u32 r4, float s1) {
    alignas(16) char frame[96];
    w3d_u32 r1 = h2g(frame) + 80;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 80; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r30 = r4;
    f31 = f1;
    r3 = (w3d_u32)((w3d_u32 (*)())A8006e71c)();
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80035894;
    r0 = L32(r31 + 804);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80035894;
    r4 = r30;
    r29 = L32(r31 + 316);
    r3 = r1 + 8;
    r30 = r31 + 316;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r27 = r30;
    r0 = L32(r30 + 4);
    r25 = 0x0u;
    r26 = r1 + 8;
    cr0 = CMPS(r29, r0);
    if ((cr0 & 2)) goto L_80035884;
    r9 = D(0x80370000u);
    r28 = r31 + 728;
    f30 = LF(D(0x803733c4u));
L_80035788:
    r9 = L32(r29);
    r4 = L32(r1 + 8);
    r3 = L32(r9 + 60);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r30 = r3;
    cr0 = CMPS(r30, 0);
    if (!(cr0 & 2)) goto L_80035870;
    r3 = L32(r29);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8015ab1c)(W(r3));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80035864;
    r0 = L32(r27 + 4);
    r11 = L32(r31 + 316);
    r9 = L32(r31 + 312);
    r0 = r0 - r11;
    { w3d_u32 t_ = r0; r0 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); }
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 8)) goto L_800357e8;
    r9 = r9 << 2;
    r3 = L32(r11 + r9);
    r11 = L32(r3 + 72);
    r0 = L32(r11 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_800357e8:
    r3 = L32(r29);
    r9 = L32(r31 + 312);
    r10 = L32(r3 + 72);
    r11 = L32(r31 + 316);
    r9 = r9 << 2;
    r0 = L32(r10 + 16);
    r4 = L32(r11 + r9);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r29);
    r3 = r31;
    r4 = L32(r9 + 48);
    ((void (*)(w3d_oarg, w3d_oarg))A80032bb0)(W(r3), W(r4));
    r0 = L32(r31 + 728);
    r3 = r26;
    S32(r31 + 312, r25);
    r0 = r0 & 0x7fffffu;
    SF(r31 + 820, f31);
    S32(r31 + 728, r0);
    S32(r28 + 16, r30);
    SF(r28 + 4, f30);
    S32(r28 + 8, r30);
    S32(r28 + 12, r30);
    r0 = L32(r31 + 728);
    r0 = r0 & 0xff9fffffu;
    S32(r31 + 728, r0);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r26;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = 0x1u;
    goto L_80035898;
L_80035864:
    r3 = r31;
    ((void (*)(w3d_oarg))A800358b4)(W(r3));
    goto L_80035884;
L_80035870:
    r0 = L32(r27 + 4);
    r29 = r29 + 4;
    r25 = r25 + 1;
    cr0 = CMPS(r29, r0);
    if (!(cr0 & 2)) goto L_80035788;
L_80035884:
    r3 = r26;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r26;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_80035894:
    r3 = 0x0u;
L_80035898:
    r1 = r1 + 80;
    return r3;
}

// 0x8003591c FUN_8003591c no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: play. Llama a string_from_text, text_compare, large_reserve_string_finish, large_reserve_string_release.
// aviso: lee r3 tras void 80341588 en 800359cc
__attribute__((weak)) w3d_u32 A8003591c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r26 = r5;
    r3 = r1 + 8;
    r31 = L32(r30 + 316);
    r29 = r3;
    r28 = r30 + 316;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r27 = r30 + 404;
    r4 = L32(r30 + 464);
    r3 = L32(r1 + 8);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_80035988;
    r3 = r27;
    goto L_8003596c;
L_80035968:
    r3 = L32(r31);
L_8003596c:
    r4 = r26;
    ((void (*)(w3d_oarg, w3d_oarg))A8015ab2c)(W(r3), W(r4));
    goto L_800359d0;
L_80035988:
    r0 = L32(r28 + 4);
    cr0 = CMPS(r31, r0);
    if ((cr0 & 2)) goto L_800359c0;
    r30 = r28;
L_80035998:
    r9 = L32(r31);
    r4 = L32(r1 + 8);
    r3 = L32(r9 + 60);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80035968;
    r0 = L32(r30 + 4);
    r31 = r31 + 4;
    cr0 = CMPS(r31, r0);
    if (!(cr0 & 2)) goto L_80035998;
L_800359c0:
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r29;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
L_800359d0:
    r1 = r1 + 40;
    return r3;
}

// 0x8003af68 FUN_8003af68 no verificada: desde bytes PPC
// Llama a value_get, trajectory_setup, dispatch_indexed, sqrt. Mucho cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A8003af68(w3d_u32 r3) {
    alignas(16) char frame[240];
    w3d_u32 r1 = h2g(frame) + 224;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 224; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r9 = D(0x80370000u);
    r3 = L32(r31 + 84);
    f30 = LF(D(0x803742f0u));
    f1 = ((float (*)(w3d_oarg))A80178df0)(W(r3));
    r3 = L32(r31 + 88);
    f31 = f1;
    f1 = ((float (*)(w3d_oarg))A80178df0)(W(r3));
    r9 = D(0x80370000u);
    f0 = LF(r31 + 56);
    f13 = LF(D(0x803742f4u));
    f31 = (float)(f31 * f1);
    cr0 = CMPF(f0, f13);
    if (!(cr0 & 8)) goto L_8003afdc;
    r11 = D(0x80370000u);
    r9 = r31 + 64;
    f0 = LF(D(0x803742f8u));
    r28 = r9;
    SF(r31 + 64, f13);
    f0 = (float)(f31 * f0);
    SF(r9 + 8, f13);
    SF(r9 + 4, f0);
    goto L_8003aff0;
L_8003afdc:
    r9 = r31 + 64;
    SF(r31 + 64, f13);
    SF(r9 + 4, f31);
    r28 = r9;
    SF(r9 + 8, f13);
L_8003aff0:
    r29 = r31 + 28;
    r30 = r31 + 52;
    r3 = r29;
    r4 = r30;
    r5 = r28;
    r6 = 0x14u;
    r7 = 0x1u;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float))A800b0824)(W(r3), W(r4), W(r5), W(r6), W(r7), (float)f1);
    r0 = L32(D(0x804b1764u));
    r27 = r0;
    cr0 = CMPU(r27, 0x14u);
    if ((cr0 & 4)) goto L_8003b1c4;
    r0 = L32(D(0x804b1784u));
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8003b030;
    ((void (*)())A800bd920)();
L_8003b030:
    r9 = D(0x80440000u);
    r8 = r1 + 56;
    r10 = L32(D(0x8043ae38u));
    r9 = D(0x8043ae38u);
    r0 = L32(D(0x8043ae40u));
    r11 = L32(D(0x8043ae3cu));
    S32(r1 + 56, r10);
    S32(r8 + 8, r0);
    S32(r8 + 4, r11);
    f0 = LF(r1 + 60);
    f1 = LF(r1 + 56);
    f0 = (float)(f0 * f0);
    f13 = LF(r1 + 64);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x80370000u);
    f12 = LF(D(0x803742fcu));
    r0 = r27 ^ 0x80000000u;
    S32(r1 + 180, r0);
    r9 = D(0x80440000u);
    f12 = (float)(f12 / f1);
    r8 = L32(D(0x8043ae20u));
    r0 = 0x43300000u;
    r9 = D(0x8043ae20u);
    S32(r1 + 176, r0);
    r7 = D(0x80370000u);
    r10 = L32(D(0x8043ae28u));
    r6 = D(0x80370000u);
    r0 = L32(D(0x8043ae24u));
    S32(r31 + 28, r8);
    S32(r29 + 8, r10);
    S32(r29 + 4, r0);
    f0 = LDS(r1 + 176);
    f8 = LD(D(0x80374300u));
    f11 = LF(r31 + 64);
    f13 = LF(r1 + 64);
    f7 = LF(r1 + 56);
    f9 = LF(r1 + 60);
    f10 = LF(r31 + 52);
    f6 = LF(D(0x80374308u));
    f0 = f0 - f8;
    f0 = (float)f0;
    f11 = (float)(f11 * f0);
    f5 = (float)(f13 * f12);
    SF(r1 + 88, f11);
    f9 = (float)(f9 * f12);
    SF(r1 + 64, f5);
    f7 = (float)(f7 * f12);
    SF(r1 + 60, f9);
    SF(r1 + 56, f7);
    f10 = (float)(f10 + f11);
    cr0 = CMPF(f9, f6);
    f12 = LF(r28 + 4);
    f12 = (float)(f12 * f0);
    SF(r1 + 92, f12);
    f13 = LF(r28 + 8);
    SF(r31 + 52, f10);
    SF(r1 + 72, f11);
    f13 = (float)(f13 * f0);
    f11 = LF(r30 + 8);
    f0 = LF(r30 + 4);
    SF(r1 + 96, f13);
    f11 = (float)(f11 + f13);
    SF(r1 + 76, f12);
    f0 = (float)(f0 + f12);
    SF(r1 + 80, f13);
    SF(r30 + 4, f0);
    SF(r30 + 8, f11);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8003b16c;
    r9 = D(0x80370000u);
    r0 = 0x1u;
    f0 = LF(D(0x803742f4u));
    SF(r31 + 52, f0);
    SF(r30 + 8, f0);
    SF(r30 + 4, f0);
    S32(r31 + 80, r0);
    goto L_8003b2d0;
L_8003b16c:
    f13 = LF(r31 + 52);
    f0 = (float)(f9 * f0);
    f0 = __builtin_fmaf((float)f7, (float)f13, (float)f0);
    f0 = __builtin_fmaf((float)f5, (float)f11, (float)f0);
    f0 = (float)(f0 + f0);
    f10 = (float)(f7 * f0);
    SF(r1 + 104, f10);
    f13 = (float)(f13 - f10);
    SF(r31 + 52, f13);
    f11 = (float)(f5 * f0);
    SF(r1 + 112, f11);
    f0 = (float)(f9 * f0);
    f13 = LF(r30 + 4);
    f12 = LF(r30 + 8);
    SF(r1 + 108, f0);
    f13 = (float)(f13 - f0);
    f12 = (float)(f12 - f11);
    SF(r30 + 4, f13);
    SF(r30 + 8, f12);
    SF(r1 + 72, f10);
    SF(r1 + 76, f0);
    goto L_8003b2cc;
L_8003b1c4:
    r9 = D(0x80370000u);
    f8 = LF(r30 + 4);
    f13 = LF(D(0x803742f8u));
    f9 = LF(r30 + 8);
    f8 = (float)(f8 * f30);
    f11 = LF(r31 + 52);
    f13 = (float)(f30 * f13);
    f7 = LF(r31 + 64);
    f13 = (float)(f13 * f30);
    f11 = (float)(f11 * f30);
    SF(r1 + 124, f8);
    f7 = (float)(f7 * f13);
    SF(r1 + 120, f11);
    f9 = (float)(f9 * f30);
    SF(r1 + 88, f11);
    SF(r1 + 128, f9);
    f11 = (float)(f11 + f7);
    SF(r1 + 92, f8);
    SF(r1 + 96, f9);
    SF(r1 + 136, f7);
    f10 = LF(r28 + 4);
    f0 = LF(r31 + 28);
    f10 = (float)(f10 * f13);
    SF(r1 + 140, f10);
    f0 = (float)(f0 + f11);
    f8 = (float)(f8 + f10);
    f12 = LF(r28 + 8);
    SF(r31 + 28, f0);
    SF(r1 + 104, f7);
    f12 = (float)(f12 * f13);
    f9 = (float)(f9 + f12);
    f13 = LF(r29 + 4);
    f0 = LF(r29 + 8);
    SF(r1 + 144, f12);
    f13 = (float)(f13 + f8);
    f0 = (float)(f0 + f9);
    SF(r29 + 4, f13);
    SF(r29 + 8, f0);
    SF(r1 + 108, f10);
    f13 = LF(r31 + 64);
    SF(r1 + 120, f11);
    f13 = (float)(f13 * f30);
    SF(r1 + 72, f11);
    SF(r1 + 88, f13);
    SF(r1 + 112, f12);
    SF(r1 + 124, f8);
    SF(r1 + 128, f9);
    SF(r1 + 76, f8);
    SF(r1 + 80, f9);
    f12 = LF(r28 + 4);
    f12 = (float)(f12 * f30);
    SF(r1 + 92, f12);
    f0 = LF(r31 + 52);
    f11 = LF(r28 + 8);
    SF(r1 + 72, f13);
    f0 = (float)(f0 + f13);
    SF(r31 + 52, f0);
    f11 = (float)(f11 * f30);
    SF(r1 + 96, f11);
    f0 = LF(r30 + 4);
    f13 = LF(r30 + 8);
    SF(r1 + 76, f12);
    f0 = (float)(f0 + f12);
    f13 = (float)(f13 + f11);
    SF(r30 + 4, f0);
    SF(r30 + 8, f13);
L_8003b2cc:
    SF(r1 + 80, f11);
L_8003b2d0:
    r1 = r1 + 224;
    return r3;
}

// 0x8003cf5c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8003cf5c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 36);
    r9 = L32(r3);
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8003f2a4 FUN_8003f2a4 no verificada: desde bytes PPC
// Llama a native_forward_copy, logic_base_destroy. Hace 1 llamada virtual.
// aviso: lee r3 tras void 801628ec en 8003f354
__attribute__((weak)) w3d_u32 A8003f2a4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r11 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r9 = D(0x80410000u);
    r28 = r3;
    r9 = D(0x8040e8f8u);
    r11 = D(0x80420000u);
    S32(r28, r9);
    r0 = 0x0u;
    S32(D(0x804aa96cu), r0);
    r27 = D(0x804273ecu);
    r31 = L32(D(0x804273ecu));
    r26 = r4;
    r29 = L32(D(0x804273f0u));
    r30 = r31;
    cr0 = CMPS(r31, r29);
    if ((cr0 & 2)) goto L_8003f314;
L_8003f2ec:
    r3 = L32(r30 + 28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8003f308;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8003f308:
    r30 = r30 + 32;
    cr0 = CMPS(r30, r29);
    if (!(cr0 & 2)) goto L_8003f2ec;
L_8003f314:
    r9 = D(0x80420000u);
    S32(D(0x804273f0u), r31);
    r29 = D(0x804273fcu);
    r0 = L32(D(0x804273fcu));
    r30 = L32(D(0x80427400u));
    r5 = 0x0u;
    r3 = r0;
    r4 = r30;
    r30 = r30 - r0;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(D(0x80427400u));
    r3 = r28;
    r4 = r26;
    r0 = r0 - r30;
    S32(D(0x80427400u), r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A801628ec)(W(r3), W(r4));
    r1 = r1 + 32;
    return r3;
}

// 0x80041d28 FUN_80041d28 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: commentary_select. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A80041d28(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0;
    double f0 = 0, f13 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r12 = r3;
    cr0 = CMPS(r4, 0);
    S32(r12 + 28, r4);
    if ((cr0 & 2)) goto L_80041e10;
    r11 = D(0x80370000u);
    r10 = D(0x80370000u);
    f0 = LF(D(0x80374d90u));
    r9 = r1 + 8;
    f13 = LF(D(0x80374d94u));
    r8 = D(0x80370000u);
    SF(r1 + 8, f0);
    r3 = D(0x80420000u);
    SF(r9 + 4, f13);
    r5 = D(0x8042745cu);
    SF(r9 + 8, f0);
    r30 = D(0x80420000u);
    r25 = L32(r9 + 4);
    r6 = D(0x80427468u);
    r4 = L32(r9 + 8);
    r26 = D(0x80370000u);
    r29 = L32(r1 + 8);
    r27 = 0x0u;
    SF(r1 + 8, f0);
    r28 = 0x640u;
    SF(r9 + 4, f13);
    r11 = r12 + 32;
    SF(r9 + 8, f0);
    r7 = r12 + 48;
    f13 = LF(D(0x80374d8cu));
    r24 = 0x3eu;
    r10 = L32(r9 + 8);
    r8 = L32(r9 + 4);
    S32(D(0x8042745cu), r29);
    r0 = L32(r1 + 8);
    S32(D(0x80427464u), r4);
    S32(D(0x80427468u), r0);
    S32(D(0x80427470u), r10);
    S32(D(0x80427460u), r25);
    S32(D(0x8042746cu), r8);
    f0 = LF(D(0x80374d98u));
    S32(D(0x804aa978u), r28);
    S32(D(0x804aa97cu), r27);
    SF(D(0x804aa980u), f13);
    S32(D(0x804aa974u), r27);
    SF(r12 + 32, f0);
    SF(r11 + 12, f0);
    SF(r11 + 4, f0);
    SF(r11 + 8, f0);
    r8 = L32(r11 + 12);
    r0 = L32(r12 + 32);
    r9 = L32(r11 + 4);
    r10 = L32(r11 + 8);
    S32(r12 + 48, r0);
    S32(r7 + 12, r8);
    S32(r7 + 4, r9);
    goto L_80041ee4;
L_80041e10:
    r9 = D(0x80370000u);
    r10 = D(0x80370000u);
    f13 = LF(D(0x80374d90u));
    r11 = r1 + 8;
    f0 = LF(D(0x80374d9cu));
    r9 = D(0x80370000u);
    SF(r1 + 8, f13);
    r10 = D(0x80370000u);
    SF(r11 + 4, f0);
    r3 = D(0x80420000u);
    SF(r11 + 8, f13);
    r5 = D(0x8042745cu);
    r25 = L32(r11 + 4);
    r30 = D(0x80420000u);
    r4 = L32(r11 + 8);
    r6 = D(0x80427468u);
    r26 = L32(r1 + 8);
    r27 = D(0x80370000u);
    f0 = LF(D(0x80374da0u));
    r28 = 0xfau;
    SF(r1 + 8, f13);
    r29 = 0x4b0u;
    SF(r11 + 4, f0);
    r9 = r12 + 32;
    SF(r11 + 8, f13);
    r7 = r12 + 48;
    f13 = LF(D(0x80374d8cu));
    r24 = 0x24u;
    r10 = L32(r11 + 8);
    r8 = L32(r11 + 4);
    S32(D(0x8042745cu), r26);
    r0 = L32(r1 + 8);
    S32(D(0x80427464u), r4);
    S32(D(0x80427468u), r0);
    S32(D(0x80427470u), r10);
    S32(D(0x80427460u), r25);
    S32(D(0x8042746cu), r8);
    f0 = LF(D(0x80374d98u));
    S32(D(0x804aa978u), r29);
    S32(D(0x804aa97cu), r28);
    SF(D(0x804aa980u), f13);
    S32(D(0x804aa974u), r28);
    SF(r12 + 32, f0);
    SF(r9 + 12, f0);
    SF(r9 + 4, f0);
    SF(r9 + 8, f0);
    r8 = L32(r9 + 12);
    r0 = L32(r12 + 32);
    r11 = L32(r9 + 4);
    r10 = L32(r9 + 8);
    S32(r12 + 48, r0);
    S32(r7 + 12, r8);
    S32(r7 + 4, r11);
L_80041ee4:
    S32(r7 + 8, r10);
    S32(r12 + 260, r24);
    r1 = r1 + 56;
    return r3;
}

// 0x800438d4 FUN_800438d4 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: commentary_advance. Llama a text_default, lookup_handle_object, sol35f7a_pool_header_release, large_reserve_string_finish, large_reserve_string_release. Hace 2 llamadas virtuales. Algo de cálculo en coma flotante.
// aviso: lee r3 tras void 80341588 en 80043b5c
__attribute__((weak)) w3d_u32 A800438d4(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[104];
    w3d_u32 r1 = h2g(frame) + 88;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 88; S32(t_, r1); r1 = t_; }
    r28 = r3;
    r22 = r4;
    r3 = r1 + 8;
    r27 = r28 + 72;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = L32(r28 + 68);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80164fc8)(W(r3));
    r31 = L32(r28 + 72);
    r23 = r3;
    r0 = L32(r27 + 4);
    r0 = r0 - r31;
    r9 = r0 >> 2; cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_80043ab8;
    r10 = L32(r31);
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
    if (!(cr0 & 2)) goto L_8004394c;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_8004394c:
    r0 = L32(r31);
    r25 = r28 + 96;
    r11 = L32(r28 + 72);
    r26 = r1 + 16;
    S32(r1 + 8, r0);
    r24 = r28 + 48;
    r0 = r11 + 4;
    r21 = r1 + 8;
    r9 = L32(r27 + 4);
    cr0 = CMPS(r0, r9);
    if ((cr0 & 2)) goto L_800439d8;
    r30 = r0;
    r31 = r11;
    r0 = r9 - r30;
    { w3d_u32 t_ = r0; r29 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); cr0 = CMPS(r29, 0); }
    if (!(cr0 & 4)) goto L_800439d8;
L_8004398c:
    r10 = L32(r30);
    r9 = L16(r10 - 6);
    r9 = r9 + 1;
    S16(r10 - 6, r9);
    r11 = L32(r31);
    r9 = L16(r11 - 6);
    r3 = r11 - 6;
    r9 = r9 - 1;
    r0 = r9 & 0xffffu;
    S16(r11 - 6, r9);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_800439c0;
    ((void (*)(w3d_oarg))A8020bb2c)(W(r3));
L_800439c0:
    r0 = L32(r30);
    { w3d_u32 t_ = r29; r29 = t_ + (w3d_u32)-1; ca = r29 < t_; cr0 = CMPS(r29, 0); }
    r30 = r30 + 4;
    S32(r31, r0);
    r31 = r31 + 4;
    if ((cr0 & 4)) goto L_8004398c;
L_800439d8:
    r30 = L32(r27 + 4);
    r30 = r30 - 4;
    S32(r27 + 4, r30);
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r28 + 96);
    r0 = L32(r3);
    r4 = r3 + 4;
    S32(r28 + 92, r0);
    r5 = L32(r25 + 4);
    cr0 = CMPS(r4, r5);
    if ((cr0 & 2)) goto L_80043a20;
    cr0 = CMPS(r5, r4);
    if ((cr0 & 2)) goto L_80043a20;
    r5 = r5 - r4;
    r3 = CU(A802eeef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80043a20:
    r9 = L32(r25 + 4);
    r11 = D(0x80370000u);
    r3 = r23;
    r9 = r9 - 4;
    r8 = r10;
    S32(r25 + 4, r9);
    r7 = r10;
    r6 = r10;
    f12 = LF(D(0x80374e08u));
    f0 = LF(r28 + 48);
    f13 = LF(r24 + 4);
    f0 = (float)(f0 * f12);
    PSQS_U8(r1 + 32, f0);
    f13 = (float)(f13 * f12);
    r9 = L8(r1 + 32);
    PSQS_U8(r1 + 32, f13);
    S8(r1 + 16, r9);
    r0 = L8(r1 + 32);
    S8(r26 + 1, r0);
    f0 = LF(r24 + 8);
    f0 = (float)(f0 * f12);
    PSQS_U8(r1 + 32, f0);
    r0 = L8(r1 + 32);
    S8(r26 + 2, r0);
    f0 = LF(r24 + 12);
    f0 = (float)(f0 * f12);
    PSQS_U8(r1 + 32, f0);
    r0 = L8(r1 + 32);
    S8(r26 + 3, r0);
    r9 = L32(r23);
    r4 = L32(r1 + 8);
    r0 = L32(r9 + 44);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = 0x1u;
    S32(r28 + 88, r22);
    S32(r28 + 64, r0);
    goto L_80043b50;
L_80043ab8:
    r4 = D(0x80370000u);
    r3 = r1 + 8;
    r4 = D(0x80374dd8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd58)(W(r3), W(r4));
    r9 = D(0x80370000u);
    f0 = LF(r28 + 48);
    f13 = LF(D(0x80374e08u));
    r9 = r28 + 48;
    r8 = r10;
    f0 = (float)(f0 * f13);
    r11 = r1 + 20;
    PSQS_U8(r1 + 32, f0);
    r7 = r10;
    r6 = r10;
    r3 = r23;
    r0 = L8(r1 + 32);
    r21 = r1 + 8;
    S8(r1 + 20, r0);
    f0 = LF(r9 + 4);
    f0 = (float)(f0 * f13);
    PSQS_U8(r1 + 32, f0);
    r0 = L8(r1 + 32);
    S8(r11 + 1, r0);
    f0 = LF(r9 + 8);
    f0 = (float)(f0 * f13);
    PSQS_U8(r1 + 32, f0);
    r0 = L8(r1 + 32);
    S8(r11 + 2, r0);
    f0 = LF(r9 + 12);
    f0 = (float)(f0 * f13);
    PSQS_U8(r1 + 32, f0);
    r0 = L8(r1 + 32);
    S8(r11 + 3, r0);
    r9 = L32(r23);
    r4 = L32(r1 + 8);
    r0 = L32(r9 + 44);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80043b50:
    r3 = r21;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r21;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 88;
    return r3;
}

// 0x80048fac heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80048fac(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800490bc)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x8004b958 FUN_8004b958 no verificada: desde bytes PPC
// Llama a set_direction_80126384__5ProbeP3Ve, iterator_next, registry_entry, query_hit_delta, sqrt. Hace 2 llamadas virtuales. Mucho cálculo en coma flotante.
// aviso: lee r3 tras void 8004d54c en 8004bdd4
__attribute__((weak)) w3d_u32 A8004b958(w3d_u32 r3) {
    alignas(16) char frame[176];
    w3d_u32 r1 = h2g(frame) + 160;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f9 = 0, f10 = 0, f11 = 0, f12 = 0, f13 = 0, f29 = 0, f30 = 0, f31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, cr2 = 0, cr3 = 0, cr4 = 0, cr5 = 0, cr6 = 0, cr7 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 160; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r0 = 0x0u;
    r31 = r30 + 236;
    S32(r30 + 104, r0);
    r3 = r31;
    r4 = r30 + 52;
    r5 = 0x14u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A80126384)(W(r3), W(r4), W(r5));
    r3 = r31;
    r3 = A801264fc(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = 0x0u;
    r0 = 0xffffu;
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 124);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 132);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 160);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 156);
    r26 = r31;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r9 = D(0x80370000u);
    r11 = D(0x80370000u);
    r10 = D(0x80370000u);
    f30 = LF(D(0x80377268u));
    f31 = LF(D(0x8037726cu));
    r29 = r1 + 8;
    f29 = LF(D(0x80377270u));
    r27 = r30 + 40;
L_8004ba00:
    r3 = L16(D(0x804aa95eu));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8003f240)(W(r3));
    r31 = L32(r3 + 20);
    r3 = (w3d_u32)((w3d_u32 (*)())A800418ac)();
    f0 = LF(r3);
    f12 = LF(r3 + 8);
    f13 = LF(r3 + 4);
    SF(r1 + 8, f0);
    SF(r29 + 4, f13);
    SF(r29 + 8, f12);
    f13 = (float)(f13 * f13);
    f0 = LF(r1 + 8);
    f0 = __builtin_fmaf((float)f0, (float)f0, (float)f13);
    f1 = __builtin_fmaf((float)f12, (float)f12, (float)f0);
    cr0 = CMPF(f1, f30);
    if (!(cr0 & 2)) goto L_8004ba50;
    SF(r1 + 8, f30);
    SF(r29 + 4, f31);
    SF(r29 + 8, f30);
    goto L_8004ba7c;
L_8004ba50:
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f1 = (float)(f31 / f1);
    f0 = LF(r1 + 8);
    f0 = (float)(f0 * f1);
    SF(r1 + 8, f0);
    f13 = LF(r29 + 4);
    f0 = LF(r29 + 8);
    f13 = (float)(f13 * f1);
    f0 = (float)(f0 * f1);
    SF(r29 + 4, f13);
    SF(r29 + 8, f0);
L_8004ba7c:
    cr0 = CMPS(r31, 1);
    if (!(cr0 & 2)) goto L_8004baa4;
    r3 = L16(D(0x804aa95eu));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8003f240)(W(r3));
    r3 = L32(r3 + 24);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80164fc8)(W(r3));
    r4 = L32(r3 + 584);
    r3 = r30;
    ((void (*)(w3d_oarg, w3d_oarg))A8004c2f0)(W(r3), W(r4));
    goto L_8004bd50;
L_8004baa4:
    cr0 = CMPS(r31, 136);
    if (!(cr0 & 2)) goto L_8004bac0;
    r3 = r30;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8004c29c)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_8004bd50;
L_8004bab8:
    r0 = 0x0u;
    goto L_8004bb1c;
L_8004bac0:
    r3 = L16(D(0x804aa95eu));
    r28 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8003f240)(W(r3));
    r3 = L32(r3 + 24);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80164fc8)(W(r3));
    r31 = r3; cr0 = CMPS(r31, 0);
    if ((cr0 & 2)) goto L_8004bb4c;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x803600c0u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_8004bb18;
L_8004bb00:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_8004bab8;
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_8004bb00;
L_8004bb18:
    r0 = 0x1u;
L_8004bb1c:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8004bb4c;
    r0 = L32(r31 + 100);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bb4c;
    r0 = L32(r31 + 104);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bb4c;
    r0 = L32(r31 + 172);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bb4c;
    r28 = 0x1u;
L_8004bb4c:
    cr0 = CMPS(r28, 0);
    if (!(cr0 & 2)) goto L_8004bd50;
    r31 = r30 + 52;
    f1 = LF(r30 + 52);
    f0 = LF(r31 + 4);
    f13 = LF(r31 + 8);
    f0 = (float)(f0 * f0);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    cr0 = CMPF(f1, f29);
    if (!(cr0 & 4)) goto L_8004bcbc;
    r0 = 0x1u;
    f1 = LF(r30 + 52);
    S32(r30 + 104, r0);
    f0 = LF(r31 + 4);
    f13 = LF(r31 + 8);
    f12 = (float)(f0 * f0);
    SF(r1 + 24, f1);
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f12);
    SF(r1 + 28, f0);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    SF(r1 + 32, f13);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    f1 = (float)(f31 / f1);
    f11 = LF(r1 + 24);
    f12 = LF(r1 + 28);
    r9 = D(0x80370000u);
    f13 = LF(r1 + 32);
    r0 = r1 + 72;
    f9 = LF(r1 + 8);
    r10 = r1 + 76;
    f8 = LF(D(0x80377274u));
    r11 = r1 + 80;
    f13 = (float)(f13 * f1);
    f11 = (float)(f11 * f1);
    SF(r1 + 32, f13);
    f12 = (float)(f12 * f1);
    SF(r1 + 24, f11);
    SF(r1 + 28, f12);
    f0 = LF(r29 + 4);
    f10 = LF(r29 + 8);
    f12 = (float)(f12 * f0);
    SF(r1 + 76, f8);
    f11 = __builtin_fmaf((float)f11, (float)f9, (float)f12);
    SF(r1 + 80, f31);
    f13 = __builtin_fmaf((float)f13, (float)f10, (float)f11);
    cr0 = CMPF(f13, f31);
    SF(r1 + 72, f13);
    if (!(cr0 & 8)) goto L_8004bc18;
    r11 = r0;
L_8004bc18:
    f0 = LF(r11);
    r9 = r11;
    cr0 = CMPF(f0, f8);
    if (!(cr0 & 8)) goto L_8004bc2c;
    r9 = r10;
L_8004bc2c:
    f0 = LF(r9);
    f1 = f0;
    SF(r1 + 72, f0);
    f1 = ((float (*)(float))A802e79e0)((float)f1);
    r9 = D(0x80370000u);
    f0 = LF(D(0x80377278u));
    cr0 = CMPF(f1, f0);
    cr0 = (cr0 & ~1u) | (((((cr0 >> 1) & 1) | ((cr0 >> 2) & 1)) & 1) << 0);
    if (!(cr0 & 1)) goto L_8004bd50;
    f13 = LF(r30 + 52);
    r3 = r30;
    f10 = LF(D(0x804b17a4u));
    r4 = r29;
    f12 = LF(r30 + 40);
    f13 = (float)(f13 * f10);
    SF(r1 + 56, f13);
    f12 = (float)(f12 + f13);
    f11 = LF(r31 + 4);
    f11 = (float)(f11 * f10);
    SF(r1 + 60, f11);
    f0 = LF(r31 + 8);
    SF(r30 + 40, f12);
    f0 = (float)(f0 * f10);
    SF(r1 + 40, f13);
    SF(r1 + 48, f0);
    SF(r1 + 64, f0);
    SF(r1 + 44, f11);
    f0 = LF(r27 + 4);
    f12 = LF(r27 + 8);
    f0 = (float)(f0 + f11);
    SF(r27 + 4, f0);
    f13 = LF(r1 + 48);
    f12 = (float)(f12 + f13);
    SF(r27 + 8, f12);
    ((void (*)(w3d_oarg))A8004ce58)(W(r3));
    goto L_8004bd50;
L_8004bcbc:
    r3 = L16(D(0x804aa95eu));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8003f240)(W(r3));
    f0 = LF(r30 + 44);
    f11 = LF(r3 + 4);
    f12 = LF(r3 + 8);
    f13 = LF(r3);
    cr7 = CMPF(f11, f0);
    r0 = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;
    r0 = ROTL(r0, 29) & 0x1u;
    SF(r1 + 32, f12);
    SF(r1 + 24, f13);
    cr0 = CMPS(r0, 0);
    SF(r1 + 28, f11);
    if ((cr0 & 2)) goto L_8004bd50;
    r0 = 0x1u;
    r3 = L16(D(0x804aa95eu));
    S32(r30 + 104, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8003f240)(W(r3));
    r0 = L32(r3 + 24);
    r9 = D(0x80460000u);
    r11 = D(0x8045e788u);
    S32(r30 + 248, r0);
    r10 = L32(D(0x8045e788u));
    r0 = L32(D(0x8045e790u));
    r9 = L32(D(0x8045e78cu));
    S32(r30 + 52, r10);
    S32(r31 + 8, r0);
    S32(r31 + 4, r9);
    S32(r30 + 112, r28);
    r3 = L32(r30 + 244);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8004bd4c;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_8004bd4c:
    S32(r30 + 244, r28);
L_8004bd50:
    r3 = r26;
    r3 = A801264fc(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = 0x0u;
    r0 = 0xffffu;
    cr0 = CMPS(r3, r0);
    if ((cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 124);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 132);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 160);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8004bd98;
    r0 = L32(r30 + 156);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8004ba00;
L_8004bd98:
    r3 = r30 + 236;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80126524)(W(r3));
    r0 = L32(r30 + 156);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8004bdb8;
    r3 = r30;
    r3 = CU(A8004c378, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_8004bdd8;
L_8004bdb8:
    r0 = L32(r30 + 160);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8004bdd0;
    r3 = r30;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8004c850)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    goto L_8004bdd8;
L_8004bdd0:
    r3 = r30;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8004d54c)(W(r3));
L_8004bdd8:
    r1 = r1 + 160;
    return r3;
}

// 0x8004ce38 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8004c850 en 8004ce44
__attribute__((weak)) w3d_u32 A8004ce38(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8004c850)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x80052340 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 800d5028 en 8005234c
__attribute__((weak)) w3d_u32 A80052340(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A800d5028)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x800614d8 FUN_800614d8 no verificada: desde bytes PPC
// Llama a scene_timer_is_one, resource_identity, weapon_resource, contact_query, sqrt. Hace 2 llamadas virtuales. Algo de cálculo en coma flotante.
__attribute__((weak)) w3d_u32 A800614d8(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[128];
    w3d_u32 r1 = h2g(frame) + 112;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 112; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r30 = r4;
    r3 = (w3d_u32)((w3d_u32 (*)())A8006e71c)();
    cr0 = CMPS(r3, 0);
    r3 = L32(D(0x804b1944u));
    if (!(cr0 & 2)) goto L_80061670;
    r3 = L32(r31 + 192);
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r9 = L32(r31);
    r27 = r3;
    r3 = r31;
    r0 = L32(r9 + 72);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r31 + 84);
    cr0 = CMPS(r30, r0);
    if (!(cr0 & 8)) goto L_80061614;
    r30 = r1 + 24;
    r28 = r31 + 36;
    r29 = r31 + 48;
    r3 = r31;
    r4 = r28;
    r5 = r29;
    r6 = r1 + 8;
    r7 = r30;
    r8 = r1 + 56;
    r9 = r1 + 64;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800ea748)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80061638;
    r9 = L32(r1 + 64);
    r10 = L32(r1 + 68);
    r10 = r10 & 0x1u;
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_80061620;
    f0 = LF(r1 + 12);
    f1 = LF(r1 + 8);
    f0 = -f0;
    f13 = LF(r1 + 16);
    SF(r1 + 44, f0);
    f1 = -f1;
    SF(r1 + 40, f1);
    f0 = (float)(f0 * f0);
    f13 = -f13;
    f1 = __builtin_fmaf((float)f1, (float)f1, (float)f0);
    SF(r1 + 48, f13);
    f1 = __builtin_fmaf((float)f13, (float)f13, (float)f1);
    f1 = ((float (*)(float))A802e82c0)((float)f1);
    r9 = D(0x80380000u);
    f11 = LF(r1 + 40);
    f13 = LF(D(0x803792c8u));
    r4 = 0x24u;
    f12 = LF(r1 + 44);
    f13 = (float)(f13 / f1);
    f0 = LF(r1 + 48);
    r3 = L32(D(0x804b1754u));
    f11 = (float)(f11 * f13);
    f12 = (float)(f12 * f13);
    SF(r1 + 40, f11);
    f0 = (float)(f0 * f13);
    SF(r1 + 44, f12);
    SF(r1 + 48, f0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    f0 = LF(r27 + 200);
    f1 = LF(r27 + 264);
    r6 = r1 + 40;
    r4 = L32(r1 + 56);
    f13 = FCTIWZ(f0);
    r7 = 0x0u;
    SDS(r1 + 80, f13);
    r8 = 0x0u;
    r5 = L32(r1 + 84);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, w3d_oarg, w3d_oarg))A8004ee4c)(W(r3), W(r4), W(r5), W(r6), (float)f1, W(r7), W(r8));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8016239c)(W(r3));
L_80061614:
    r3 = r31;
    ((void (*)(w3d_oarg))A800ecb20)(W(r3));
    goto L_8006166c;
L_80061620:
    r3 = r31;
    r4 = r30;
    r5 = r29;
    r6 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A800ec6a8)(W(r3), W(r4), W(r5), W(r6));
    goto L_8006166c;
L_80061638:
    r9 = L32(r31);
    r4 = r28;
    r5 = r29;
    r7 = r30;
    r0 = L32(r9 + 64);
    r3 = r31;
    r6 = r1 + 8;
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8006166c;
    r3 = r31;
    ((void (*)(w3d_oarg))A800ecb20)(W(r3));
L_8006166c:
    r3 = L32(D(0x804b1944u));
L_80061670:
    r1 = r1 + 112;
    return r3;
}

// 0x80062390 FUN_80062390 no verificada: desde bytes PPC
// Llama a create_slot, read_int_property, sol35b9_retreat_write, engine_get_context, sol35b8_control_allocate. Hace 3 llamadas virtuales. Usa las cadenas "Earthquake Active", "EarthquakeLogicEntity.cpp", "Earthquake.Length.Default".
__attribute__((weak)) w3d_u32 A80062390(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[152];
    w3d_u32 r1 = h2g(frame) + 136;
    w3d_u32 r0 = 0, r11 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8, f13 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 136; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r29 = r1 + 64;
    r9 = L32(r31);
    r30 = r1 + 68;
    r27 = r1 + 72;
    r0 = L32(r9 + 20);
    r26 = r1 + 76;
    r25 = r1 + 80;
    r28 = r1 + 40;
    lr = r0;
    r24 = r1 + 84;
    r23 = r1 + 56;
    r22 = r1 + 88;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x80361860u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_80062408;
L_800623e8:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if (!(cr0 & 2)) goto L_800623fc;
    r0 = 0x0u;
    goto L_8006240c;
L_800623fc:
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_800623e8;
L_80062408:
    r0 = 0x1u;
L_8006240c:
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_80062464;
    r9 = L32(r31);
    r3 = r31;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80360000u);
    r9 = D(0x803618f0u);
    cr0 = CMPS(r3, r9);
    if ((cr0 & 2)) goto L_80062458;
L_80062438:
    r0 = L32(r3 + 20);
    cr0 = CMPS(r3, r0);
    if (!(cr0 & 2)) goto L_8006244c;
    r0 = 0x0u;
    goto L_8006245c;
L_8006244c:
    r3 = r0;
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_80062438;
L_80062458:
    r0 = 0x1u;
L_8006245c:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80062480;
L_80062464:
    r3 = D(0x80380000u);
    r4 = D(0x80380000u);
    r3 = D(0x803799f0u);
    r4 = D(0x80379a04u);
    r5 = 0xbeu;
    r6 = r31 + 76;
    r3 = A80022e20(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80062480:
    r9 = D(0x80380000u);
    r4 = r30;
    r9 = D(0x80379a20u);
    r3 = r29;
    S32(r1 + 64, r9);
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80380000u);
    r4 = L32(r1 + 68);
    r9 = D(0x80379a3cu);
    r3 = r27;
    S32(r1 + 72, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc3b0)(W(r3), W(r4));
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r0 = L32(r1 + 68);
    r4 = 0x8u;
    r29 = L32(r3 + 52);
    r3 = L32(D(0x804b1754u));
    r29 = r29 + r0;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801613f0)(W(r3), W(r4));
    r30 = r3;
    r4 = 0x1u;
    r3 = D(0x804ad510u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8015f5a0)(W(r3), W(r4));
    r9 = D(0x80410000u);
    S16(r30, r3);
    r9 = D(0x8040db38u);
    r4 = r29;
    S32(r30 + 4, r9);
    r3 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800c53a0)(W(r3), W(r4));
    r30 = D(0x80380000u);
    S32(r31 + 68, r3);
    r30 = D(0x80379a50u);
    r29 = L32(D(0x804aa8c8u));
    S32(r1 + 76, r30);
    r3 = r26;
    r9 = L32(r29 + 312);
    r11 = L32(r29 + 316);
    r9 = r9 << 2;
    r4 = L32(r11 + r9);
    r4 = r4 + 4;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc5dc)(W(r3), W(r4));
    r9 = L32(r29 + 312);
    r3 = r25;
    S32(r1 + 80, r30);
    r9 = r9 << 2;
    r11 = L32(r29 + 316);
    r4 = L32(r11 + r9);
    r4 = r4 + 16;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc5dc)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r10 = D(0x80380000u);
    f13 = LF(D(0x80379a78u));
    r11 = D(0x80380000u);
    f0 = LF(D(0x80379a7cu));
    r11 = D(0x80379a68u);
    SF(r1 + 40, f13);
    r4 = r28;
    SF(r28 + 4, f0);
    r3 = r24;
    SF(r28 + 8, f13);
    S32(r1 + 84, r11);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc5dc)(W(r3), W(r4));
    r3 = D(0x80410000u);
    r3 = D(0x8040ecd8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b680)(W(r3));
    r4 = r3;
    r5 = L32(r31 + 20);
    r3 = L32(D(0x804b178cu));
    r3 = CU(A80164514, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80380000u);
    r0 = 0x0u;
    r9 = D(0x803795c0u);
    S32(r1 + 56, r0);
    S32(r1 + 88, r9);
    r4 = r23;
    r3 = r22;
    r3 = A800fc1b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r1 + 56);
    ((void (*)())A80341584)();
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801797b4)(W(r3));
    r9 = L32(r3 + 52);
    r0 = L32(r1 + 68);
    r3 = r31;
    r0 = r0 + r9;
    S32(r31 + 56, r0);
    ((void (*)(w3d_oarg))A8002ae70)(W(r3));
    r3 = r31;
    ((void (*)(w3d_oarg))A80062640)(W(r3));
    r3 = L32(r1 + 56);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80062600;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80062600:
    r1 = r1 + 136;
    return r3;
}

// 0x8006d854 FUN_8006d854 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: apply_land. Llama a string_property, assign__20d24d_String_803426b8PCc, string_from_text, string_uppercase, text_compare. Usa las cadenas "Land.Theme", "Land.TimeOfDay", "RANDOM".
// aviso: lee r3 tras void 80341588 en 8006df80
__attribute__((weak)) w3d_u32 A8006d854(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[288];
    w3d_u32 r1 = h2g(frame) + 272;
    w3d_u32 r0 = 0, r11 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 272; S32(t_, r1); r1 = t_; }
    r9 = D(0x80380000u);
    r31 = r3;
    r9 = D(0x8037ba54u);
    r4 = r1 + 116;
    S32(r1 + 112, r9);
    r3 = r1 + 112;
    r3 = A800fc2b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r29 = r31 + 3344;
    r9 = D(0x80380000u);
    r4 = r1 + 124;
    r9 = D(0x8037ba60u);
    r30 = r1 + 8;
    r3 = r1 + 120;
    S32(r1 + 120, r9);
    r3 = A800fc2b0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r19 = r30;
    r4 = L32(r1 + 116);
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    r4 = L32(r1 + 124);
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c2e8)(W(r3));
    r3 = r1 + 8;
    ((void (*)(w3d_oarg))A8020c2e8)(W(r3));
    r4 = D(0x80380000u);
    r3 = L32(r1 + 8);
    r4 = D(0x8037c1a4u);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8006d94c;
    r3 = (w3d_u32)((w3d_u32 (*)())A80162ba8)();
    r0 = 0xaaaa0000u;
    r0 = 0xaaaaaaabu;
    r0 = (w3d_u32)(((w3d_u64)r3 * (w3d_u64)r0) >> 32);
    r0 = r0 >> 1;
    r9 = r0 << 1;
    r9 = r9 + r0;
    r3 = r3 - r9; cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8006d914;
    cr0 = CMPS(r3, 1);
    if ((cr0 & 2)) goto L_8006d928;
    goto L_8006d93c;
L_8006d914:
    r4 = D(0x80380000u);
    r3 = r19;
    r4 = D(0x8037ba40u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_8006d94c;
L_8006d928:
    r4 = D(0x80380000u);
    r3 = r19;
    r4 = D(0x8037ba44u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
    goto L_8006d94c;
L_8006d93c:
    r4 = D(0x80380000u);
    r3 = r1 + 8;
    r4 = D(0x8037ba4cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bd38)(W(r3), W(r4));
L_8006d94c:
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r21 = 0x0u;
    r0 = L32(r31 + 3344);
    r3 = r1 + 48;
    r27 = r1 + 56;
    r29 = r1 + 16;
    r30 = r1 + 32;
    S32(r1 + 48, r0);
    r28 = r3;
    r20 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r26 = r1 + 64;
    r9 = L16(r11);
    r25 = r1 + 72;
    r24 = r1 + 80;
    r23 = r1 + 88;
    r9 = r9 + 1;
    r22 = r1 + 96;
    r3 = r1 + 48;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 8);
    r3 = r1 + 48;
    S32(r1 + 48, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 48;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r9 = D(0x80380000u);
    r3 = r1 + 128;
    r9 = D(0x8037c1d0u);
    r4 = r29;
    S32(r1 + 128, r9);
    r3 = A800fc2f0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80380000u);
    r3 = r1 + 132;
    r9 = D(0x8037c1e4u);
    r4 = r30;
    S32(r1 + 132, r9);
    r3 = A800fc2f0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r27;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r26;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r25;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r24;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r23;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r22;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r6 = L32(r31 + 3344);
    r4 = D(0x80380000u);
    r5 = L32(r1 + 8);
    r4 = D(0x8037c1f8u);
    r0 = L8(r6);
    r3 = r28;
    r0 = r0 << 8;
    S16(r1 + 136, r0 >> 8);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r6 = L32(r1 + 8);
    r4 = D(0x80380000u);
    r5 = L32(r31 + 3344);
    r4 = D(0x8037c20cu);
    r3 = r27;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r6 = L32(r1 + 8);
    r4 = D(0x80380000u);
    r5 = L32(r31 + 3344);
    r4 = D(0x8037c218u);
    r3 = r26;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r6 = L32(r1 + 8);
    r4 = D(0x80380000u);
    r5 = L32(r31 + 3344);
    r4 = D(0x8037c224u);
    r3 = r25;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r6 = L32(r1 + 8);
    r4 = D(0x80380000u);
    r5 = r1 + 136;
    r4 = D(0x8037c234u);
    r3 = r24;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r5 = L32(r1 + 116);
    r4 = D(0x80380000u);
    r6 = L32(r1 + 8);
    r4 = D(0x8037c248u);
    r3 = r23;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r5 = L32(r31 + 3344);
    r4 = D(0x80380000u);
    r6 = L32(r1 + 8);
    r3 = r22;
    r4 = D(0x8037c254u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r9 = D(0x80380000u);
    r4 = L32(r1 + 56);
    r9 = D(0x8037c268u);
    r3 = r1 + 140;
    S32(r1 + 140, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r4 = L32(r1 + 64);
    r9 = D(0x8037c27cu);
    r3 = r1 + 144;
    S32(r1 + 144, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r4 = L32(r1 + 72);
    r9 = D(0x8037c290u);
    r3 = r1 + 148;
    S32(r1 + 148, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r4 = L32(r1 + 80);
    r9 = D(0x8037c2acu);
    r3 = r1 + 152;
    S32(r1 + 152, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r4 = L32(r1 + 88);
    r9 = D(0x8037c2c8u);
    r3 = r1 + 156;
    S32(r1 + 156, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r4 = L32(r1 + 96);
    r9 = D(0x8037c2d8u);
    r3 = r1 + 160;
    S32(r1 + 160, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r25 = r29;
    r28 = r30;
    goto L_8006dbc0;
L_8006dbbc:
    r21 = r21 + 1;
L_8006dbc0:
    r0 = (w3d_s32)r21 * 36;
    r9 = D(0x803f0000u);
    r30 = D(0x803f477cu);
    r3 = L32(r30 + r0);
    r26 = r0;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8006dbf8;
    r4 = L32(r31 + 3344);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8006dbbc;
    r0 = L32(r30 + r26);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8006dc58;
L_8006dbf8:
    r3 = r1 + 104;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r31 + 3344);
    r3 = r1 + 104;
    S32(r1 + 104, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 104;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 104;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_8006dc30:
    r3 = L32(r30);
    r30 = r30 + 36;
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8006dc90;
    r4 = L32(r31 + 3344);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8006dc30;
    goto L_8006dc90;
L_8006dc54:
    r20 = r20 + 1;
L_8006dc58:
    r9 = D(0x803f0000u);
    r0 = r20 << 2;
    r30 = D(0x803f4878u);
    r27 = r0;
    r3 = L32(r30 + r0);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_8006dc90;
    r4 = L32(r1 + 8);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8006dc54;
    r0 = L32(r30 + r27);
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8006dd14;
L_8006dc90:
    r3 = r1 + 96;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 96;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 80;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 80;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 72;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 72;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 56;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 56;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r19;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r19;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    goto L_8006df84;
L_8006dd14:
    r30 = D(0x803f0000u);
    r29 = r27 + r26;
    r30 = D(0x803f477cu);
    r9 = D(0x80380000u);
    r11 = D(0x803f4780u);
    r9 = D(0x8037c328u);
    r4 = L32(r11 + r29);
    r3 = r1 + 164;
    S32(r1 + 164, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc3b0)(W(r3), W(r4));
    r30 = D(0x803f478cu);
    r0 = L32(r30 + r29);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8006dd68;
    r9 = D(0x80380000u);
    r4 = r25;
    r9 = D(0x8037c33cu);
    r3 = r1 + 168;
    S32(r1 + 168, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc5dc)(W(r3), W(r4));
    goto L_8006dd80;
L_8006dd68:
    r9 = D(0x80380000u);
    r4 = r28;
    r9 = D(0x8037c33cu);
    r3 = r1 + 172;
    S32(r1 + 172, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc5dc)(W(r3), W(r4));
L_8006dd80:
    r9 = D(0x80380000u);
    r11 = D(0x803f0000u);
    r9 = D(0x8037bbbcu);
    r25 = D(0x803f477cu);
    S32(r1 + 176, r9);
    r11 = D(0x803f4798u);
    r28 = r1 + 104;
    r3 = r1 + 176;
    r4 = L32(r11 + r26);
    r24 = 0x0u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc550)(W(r3), W(r4));
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r9 = D(0x80380000u);
    S32(r1 + 192, r24);
    r9 = D(0x8037c34cu);
    r3 = r1 + 180;
    S32(r1 + 180, r9);
    r4 = r1 + 184;
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r1 + 184);
    cr0 = CMPS(r0, 1);
    if (!(cr0 & 2)) goto L_8006de80;
    r30 = D(0x803f0000u);
    r5 = L32(r25 + r26);
    r30 = D(0x803f4878u);
    r4 = D(0x80380000u);
    r6 = L32(r30 + r27);
    r29 = r1 + 192;
    r4 = D(0x8037c35cu);
    r3 = r28;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 104);
    r3 = r1 + 188;
    r4 = r29;
    S32(r1 + 188, r0);
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80380000u);
    r4 = L32(r1 + 192);
    r9 = D(0x8037c36cu);
    r3 = r1 + 196;
    S32(r1 + 196, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
    r5 = L32(r25 + r26);
    r4 = D(0x80380000u);
    r6 = L32(r30 + r27);
    r3 = r28;
    r4 = D(0x8037c380u);
    S32(r1 + 192, r24);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A8020c510)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r0 = L32(r1 + 104);
    r4 = r29;
    r3 = r1 + 200;
    S32(r1 + 200, r0);
    r3 = A800fc230(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = D(0x80380000u);
    r4 = L32(r1 + 192);
    r9 = D(0x8037c390u);
    r3 = r1 + 204;
    S32(r1 + 204, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
    goto L_8006deb0;
L_8006de80:
    r9 = D(0x80380000u);
    r4 = 0x0u;
    r9 = D(0x8037c36cu);
    r3 = r1 + 208;
    S32(r1 + 208, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
    r9 = D(0x80380000u);
    r3 = r1 + 212;
    r9 = D(0x8037c390u);
    r4 = 0x0u;
    S32(r1 + 212, r9);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A800fc43c)(W(r3), W(r4));
L_8006deb0:
    r0 = 0x0u;
    r9 = D(0x803f0000u);
    r30 = D(0x803f45e4u);
    S32(r31 + 3336, r0);
    goto L_8006ded0;
L_8006dec4:
    r9 = L32(r31 + 3336);
    r9 = r9 + 1;
    S32(r31 + 3336, r9);
L_8006ded0:
    r0 = L32(r31 + 3336);
    cr0 = CMPU(r0, 0x58u);
    if ((cr0 & 4)) goto L_8006def4;
    r0 = r0 << 2;
    r3 = L32(r1 + 48);
    r4 = L32(r30 + r0);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    if (!(cr0 & 2)) goto L_8006dec4;
L_8006def4:
    r3 = r1 + 104;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 104;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 96;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 96;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 80;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 80;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 72;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 72;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 64;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 56;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 56;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 48;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r19;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r19;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
L_8006df84:
    r1 = r1 + 272;
    return r3;
}

}
