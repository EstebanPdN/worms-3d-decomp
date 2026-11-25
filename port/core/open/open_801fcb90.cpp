// Funciones del juego sin fuente admitida: 0x801fcb90 a 0x80226d44. Generado por port/tests/open/ppc2cpp.py.
// Ninguna está verificada ni cuenta como recuperada.
#include "open_rt.h"

extern "C" {
__attribute__((weak)) void A800fc6dc();
__attribute__((weak)) void A80129878();
__attribute__((weak)) void A801298cc();
__attribute__((weak)) void A8015aa04();
__attribute__((weak)) void A80162ba8();
__attribute__((weak)) void A80165018();
__attribute__((weak)) void A80165254();
__attribute__((weak)) void A801e8d9c();
__attribute__((weak)) void A801fcb64();
__attribute__((weak)) void A801fe1d8();
__attribute__((weak)) void A8020430c();
__attribute__((weak)) void A80204760();
__attribute__((weak)) void A802047e0();
__attribute__((weak)) void A80206af4();
__attribute__((weak)) void A80207c0c();
__attribute__((weak)) void A80208768();
__attribute__((weak)) void A8020881c();
__attribute__((weak)) void A80208a4c();
__attribute__((weak)) void A80209720();
__attribute__((weak)) void A8020aad0();
__attribute__((weak)) void A8020abe0();
__attribute__((weak)) void A8020b058();
__attribute__((weak)) void A8020b208();
__attribute__((weak)) void A8020bb54();
__attribute__((weak)) void A8020c3a0();
__attribute__((weak)) void A8020c5c0();
__attribute__((weak)) void A8020c5c4();
__attribute__((weak)) void A8020d82c();
__attribute__((weak)) void A8020dc54();
__attribute__((weak)) void A8020f3b8();
__attribute__((weak)) void A8020f3f0();
__attribute__((weak)) void A8020f8ac();
__attribute__((weak)) void A8020f940();
__attribute__((weak)) void A8021202c();
__attribute__((weak)) void A80212fd4();
__attribute__((weak)) void A802134fc();
__attribute__((weak)) void A802199b4();
__attribute__((weak)) void A802ed984();
__attribute__((weak)) void A802eedc0();
__attribute__((weak)) void A802eee50();
__attribute__((weak)) void A802eeef4();
__attribute__((weak)) void A802ef234();
__attribute__((weak)) void A802fc330();
__attribute__((weak)) void A80341588();
__attribute__((weak)) void A80341884();
__attribute__((weak)) void A803426b8();
__attribute__((weak)) void A803434d4();
__attribute__((weak)) void A80347324();
__attribute__((weak)) void A80351ef8();
__attribute__((weak)) void A8035a32c();
__attribute__((weak)) void A8035bbf0();
__attribute__((weak)) void A8035bc90();
__attribute__((weak)) void A8035bd50();
__attribute__((weak)) void A8035c0ac();
__attribute__((weak)) void A8035c32c();

// 0x801fcb90 FUN_801fcb90 no verificada: desde bytes PPC
// Error fatal: compone el texto con la cadena y el código del error; si hay un manejador registrado lo llama, y si no pinta OSFatal y sale con 999.
__attribute__((weak)) w3d_u32 A801fcb90(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r11 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r31 = r3;
    r4 = D(0x803b0000u);
    r5 = L32(r31);
    r4 = D(0x803b1d40u);
    r6 = L32(r31 + 4);
    r3 = D(0x804b0640u);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    ((void (*)(w3d_oarg, w3d_oarg, ...))A80347324)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r10 = L32(D(0x804b05dcu));
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_801fcbdc;
    r3 = r31;
    lr = r10;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    goto L_801fcc34;
L_801fcbdc:
    r0 = 0xffu;
    r9 = r1 + 16;
    S8(r9 + 1, r0);
    r11 = r1 + 20;
    S8(r9 + 3, r0);
    r3 = r1 + 8;
    S8(r9 + 2, r0);
    r4 = r1 + 12;
    S8(r1 + 16, r0);
    S8(r11 + 2, r10);
    S8(r11 + 1, r10);
    S8(r1 + 20, r10);
    S8(r11 + 3, r0);
    r0 = L32(r1 + 16);
    r9 = L32(r1 + 20);
    r5 = L32(r31);
    S32(r1 + 8, r0);
    S32(r1 + 12, r9);
    r3 = CU(A802fc330, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    w3d_open_break(0x801fcc28u);
    r3 = 0x3e7u;
    r3 = CU(A802ed984, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcc34:
    r1 = r1 + 32;
    return r3;
}

// 0x801fcc48 FUN_801fcc48 no verificada: desde bytes PPC
// Guarda la máscara de canales de registro y activa o apaga cada canal de la tabla 0x803b1d58 según esa máscara.
__attribute__((weak)) w3d_u32 A801fcc48(w3d_u32 r3) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r4 = 0, r9 = 0, r10 = 0, r11 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, ctr = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r0 = L32(D(0x804ab930u));
    r30 = r3;
    S32(D(0x804ab92cu), r30);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801fcd58;
    r9 = D(0x803b0000u);
    r10 = 0x0u;
    r28 = D(0x803b1d60u);
    r29 = D(0x803b1d5cu);
    r27 = D(0x803b1d58u);
L_801fcc80:
    r9 = (w3d_s32)r10 * 12;
    r0 = L32(r28 + r9);
    r4 = r9;
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801fcca0;
    r9 = D(0x80460000u);
    r3 = D(0x8045e970u);
    goto L_801fcca8;
L_801fcca0:
    r9 = D(0x80460000u);
    r3 = D(0x8045e944u);
L_801fcca8:
    r0 = L32(r27 + r4);
    r0 = r30 & r0; cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_801fcd04;
    r4 = L32(r29 + r4);
    cr0 = CMPS(r4, 3);
    if (!(cr0 & 2)) goto L_801fcce4;
    r11 = 0x3u;
    r31 = r10 + 1;
    ctr = r11;
    r0 = 0x1u;
    r9 = r3 + 16;
L_801fccd4:
    S32(r9, r0);
    r9 = r9 + 8;
    --ctr; if (ctr != 0) goto L_801fccd4;
    goto L_801fccfc;
L_801fcce4:
    r9 = r4 << 3;
    r11 = r3 + 12;
    r9 = r9 + 4;
    r0 = 0x1u;
    S32(r11 + r9, r0);
    r31 = r10 + 1;
L_801fccfc:
    ((void (*)(w3d_oarg, w3d_oarg))A8035a32c)(W(r3), W(r4));
    goto L_801fcd4c;
L_801fcd04:
    r4 = L32(r29 + r4);
    cr0 = CMPS(r4, 3);
    if (!(cr0 & 2)) goto L_801fcd34;
    r11 = 0x3u;
    r31 = r10 + 1;
    ctr = r11;
    r0 = 0x0u;
    r9 = r3 + 16;
L_801fcd24:
    S32(r9, r0);
    r9 = r9 + 8;
    --ctr; if (ctr != 0) goto L_801fcd24;
    goto L_801fcd48;
L_801fcd34:
    r9 = r4 << 3;
    r11 = r3 + 12;
    r9 = r9 + 4;
    r31 = r10 + 1;
    S32(r11 + r9, r0);
L_801fcd48:
    ((void (*)(w3d_oarg, w3d_oarg))A8035a32c)(W(r3), W(r4));
L_801fcd4c:
    r10 = r31;
    cr0 = CMPU(r10, 0x5u);
    if (!(cr0 & 4)) goto L_801fcc80;
L_801fcd58:
    r1 = r1 + 32;
    return r3;
}

// 0x801fcd74 FUN_801fcd74 no verificada: desde bytes PPC
// Parece crear los canales de registro de Xom (Xom.Log y los prefijos de aviso y error) y enlazarlos a sus flujos de salida.
__attribute__((weak)) w3d_u32 A801fcd74(void) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, lr = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r3 = 0x14u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020b058)(W(r3));
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801fcdac;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcdac:
    r3 = L32(D(0x804b05e0u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fcdc8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcdc8:
    S32(D(0x804b05e0u), r30);
    r3 = 0x14u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80206af4)(W(r3));
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801fcdf4;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcdf4:
    r3 = L32(D(0x804b05e8u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fce10;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fce10:
    S32(D(0x804b05e8u), r30);
    r3 = 0x20u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x804b05e8u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020881c)(W(r3), W(r4));
    r30 = L32(D(0x804b05e8u));
    S32(D(0x804b05fcu), r3);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801fce48;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fce48:
    r3 = L32(D(0x804b05e4u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fce64;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fce64:
    r3 = D(0x803b0000u);
    S32(D(0x804b05e4u), r30);
    r3 = D(0x803b1da0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80207c0c)(W(r3));
    S16(D(0x804b05f4u), r3);
    r3 = (w3d_u32)((w3d_u32 (*)())A8020b208)();
    r9 = D(0x80460000u);
    r30 = r3; cr0 = CMPS(r30, 0);
    r26 = D(0x8045e944u);
    if ((cr0 & 2)) goto L_801fcea0;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcea0:
    r3 = L32(D(0x8045e968u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fcebc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcebc:
    S32(D(0x8045e968u), r30);
    r3 = (w3d_u32)((w3d_u32 (*)())A8020b208)();
    r9 = D(0x80460000u);
    r30 = r3; cr0 = CMPS(r30, 0);
    r28 = D(0x8045e970u);
    if ((cr0 & 2)) goto L_801fcee8;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcee8:
    r3 = L32(D(0x8045e994u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fcf04;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcf04:
    r29 = L32(D(0x804b05fcu));
    S32(D(0x8045e994u), r30);
    cr0 = CMPS(r29, 0);
    if ((cr0 & 2)) goto L_801fcf28;
    r9 = L32(r29);
    r3 = r29;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcf28:
    r3 = L32(D(0x8045e96cu));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fcf44;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcf44:
    r30 = L32(D(0x804b05fcu));
    S32(D(0x8045e96cu), r29);
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801fcf68;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcf68:
    r3 = L32(D(0x8045e998u));
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fcf84;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcf84:
    S32(D(0x8045e998u), r30);
    r27 = 0x0u;
    r25 = 0x1u;
    r28 = D(0x8045e950u);
    r29 = 0x0u;
L_801fcf98:
    r3 = 0x20u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020aad0)(W(r3));
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801fcfc0;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcfc0:
    r3 = L32(r29 + r26);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fcfdc;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fcfdc:
    S32(r29 + r26, r30);
    r3 = r30;
    r27 = r27 + 1;
    r29 = r29 + 4;
    r4 = L32(D(0x8045e968u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020abe0)(W(r3), W(r4));
    S32(r28, r25);
    cr0 = CMPU(r27, 0x2u);
    r28 = r28 + 8;
    if (!(cr0 & 4)) goto L_801fcf98;
    r9 = D(0x80460000u);
    r26 = 0x0u;
    r28 = D(0x8045e970u);
    r25 = 0x1u;
    r27 = D(0x8045e97cu);
    r29 = 0x0u;
L_801fd01c:
    r3 = 0x20u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A8020aad0)(W(r3));
    r30 = r3; cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_801fd044;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fd044:
    r3 = L32(r29 + r28);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_801fd060;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_801fd060:
    S32(r29 + r28, r30);
    r3 = r30;
    r26 = r26 + 1;
    r29 = r29 + 4;
    r4 = L32(D(0x8045e994u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020abe0)(W(r3), W(r4));
    S32(r27, r25);
    cr0 = CMPU(r26, 0x2u);
    r27 = r27 + 8;
    if (!(cr0 & 4)) goto L_801fd01c;
    r25 = D(0x80460000u);
    r29 = D(0x8045e944u);
    r23 = 0x1u;
    S32(D(0x8045e954u), r23);
    r3 = D(0x8045e944u);
    r4 = 0x0u;
    r22 = D(0x80460000u);
    ((void (*)(w3d_oarg, w3d_oarg))A8035a32c)(W(r3), W(r4));
    r26 = D(0x8045e970u);
    S32(D(0x8045e980u), r23);
    r4 = 0x0u;
    r28 = D(0x80460000u);
    r3 = D(0x8045e970u);
    r30 = D(0x8045e9acu);
    ((void (*)(w3d_oarg, w3d_oarg))A8035a32c)(W(r3), W(r4));
    r24 = D(0x80460000u);
    r3 = 0x28u;
    r27 = D(0x8045e99cu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x804b05e4u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9b0u), r3);
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x8045e944u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9acu), r3);
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x8045e948u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9b4u), r3);
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x8045e94cu));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9b8u), r3);
    r4 = D(0x803b0000u);
    r3 = r1 + 8;
    r4 = D(0x803b1da8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = L32(D(0x8045e9b4u));
    r4 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A80208768)(W(r3), W(r4));
    r4 = D(0x803b0000u);
    r3 = r1 + 8;
    r4 = D(0x803b1db8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = L32(D(0x8045e9b8u));
    r4 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A80208768)(W(r3), W(r4));
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x804b05e4u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9a0u), r3);
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x8045e970u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e99cu), r3);
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x8045e974u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9a4u), r3);
    r3 = 0x28u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A801fe1d8)(W(r3));
    r4 = L32(D(0x8045e978u));
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A80208a4c)(W(r3), W(r4));
    S32(D(0x8045e9a8u), r3);
    r4 = D(0x803b0000u);
    r3 = r1 + 8;
    r4 = D(0x803b1dc8u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = L32(D(0x8045e99cu));
    r4 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A80208768)(W(r3), W(r4));
    r4 = D(0x803b0000u);
    r3 = r1 + 8;
    r4 = D(0x803b1dccu);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = L32(D(0x8045e9a0u));
    r4 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A80208768)(W(r3), W(r4));
    r4 = D(0x803b0000u);
    r3 = r1 + 8;
    r4 = D(0x803b1dd0u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = L32(D(0x8045e9a4u));
    r4 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A80208768)(W(r3), W(r4));
    r4 = D(0x803b0000u);
    r3 = r1 + 8;
    r4 = D(0x803b1dd4u);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020bb54)(W(r3), W(r4));
    r3 = L32(D(0x8045e9a8u));
    r4 = r1 + 8;
    ((void (*)(w3d_oarg, w3d_oarg))A80208768)(W(r3), W(r4));
    r3 = L32(D(0x804ab92cu));
    S32(D(0x804ab930u), r23);
    r3 = A801fcc48(r3);
    r3 = 0x0u;
    r1 = r1 + 56;
    return r3;
}

// 0x801fe2d4 FUN_801fe2d4 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801fe2d4(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801fe2d4u);
    r3 = 0x0u;
    return r3;
}

// 0x801fe568 fn_801FE568 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y no devuelve valor.
__attribute__((weak)) w3d_u32 A801fe568(w3d_u32 r3) {
    w3d_open_break(0x801fe568u);
    return r3;
}

// 0x801fe570 fn_801FE570 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A801fe570(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801fe570u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x801fe580 fn_801FE580 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A801fe580(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801fe580u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x801fe590 fn_801FE590 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A801fe590(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801fe590u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x801fe708 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fe708(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 44);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fe740 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fe740(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 52);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fe824 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fe824(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fe85c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fe85c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 60);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fe948 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fe948(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 56);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fe980 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fe980(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 56);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fea64 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fea64(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fea9c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fea9c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 68);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801feb80 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801feb80(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 72);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801febb8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801febb8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 64);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fec9c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fec9c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fecd4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fecd4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fedb8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fedb8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fedf0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fedf0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 72);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801feee8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801feee8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 108);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801fef20 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fef20(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff01c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff01c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 104);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff054 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff054(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 80);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff13c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff13c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 116);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff174 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff174(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 88);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff258 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff258(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 124);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff290 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff290(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff2dc heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff2dc(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r4 = r5;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8020d82c)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x801ff39c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff39c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 132);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff3d4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff3d4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 96);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff4b8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff4b8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff4f0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff4f0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff5e8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff5e8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 108);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff620 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff620(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 84);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff7f8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff7f8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 36);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ff86c fn_801FF86C no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801ff86c(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801ff86cu);
    r3 = 0x0u;
    return r3;
}

// 0x801ff924 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ff924(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ffbac heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ffbac(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 92);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ffbe4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ffbe4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = r4;
    r9 = L32(r3);
    r4 = r5;
    r5 = r7;
    r0 = L32(r9 + 76);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ffc1c fn_801FFC1C no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A801ffc1c(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801ffc1cu);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x801ffea8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801ffea8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = A8020017c(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r3);
    r1 = r1 + 8;
    return r3;
}

// 0x801fff3c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A801fff3c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = A802001a8(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r3 + 8);
    r1 = r1 + 8;
    return r3;
}

// 0x801ffff0 fn_801FFFF0 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801ffff0(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801ffff0u);
    r3 = 0x0u;
    return r3;
}

// 0x801ffffc fn_801FFFFC no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A801ffffc(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x801ffffcu);
    r3 = 0x0u;
    return r3;
}

// 0x80200008 fn_80200008 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A80200008(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200008u);
    r3 = 0x0u;
    return r3;
}

// 0x80200014 fn_80200014 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A80200014(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200014u);
    r3 = 0x0u;
    return r3;
}

// 0x80200020 fn_80200020 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A80200020(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200020u);
    r3 = 0x0u;
    return r3;
}

// 0x8020002c fn_8020002C no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A8020002c(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x8020002cu);
    r3 = 0x0u;
    return r3;
}

// 0x80200038 fn_80200038 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A80200038(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200038u);
    r3 = 0x0u;
    return r3;
}

// 0x80200044 fn_80200044 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x0.
__attribute__((weak)) w3d_u32 A80200044(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200044u);
    r3 = 0x0u;
    return r3;
}

// 0x80200098 fn_80200098 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A80200098(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200098u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x802000a8 fn_802000A8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A802000a8(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x802000a8u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x802000b8 fn_802000B8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A802000b8(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x802000b8u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x802000c8 fn_802000C8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A802000c8(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x802000c8u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x802000d8 fn_802000D8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A802000d8(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x802000d8u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x802000e8 fn_802000E8 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A802000e8(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x802000e8u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x80200158 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80200158(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = A802001d4(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r3 + 8);
    r1 = r1 + 8;
    return r3;
}

// 0x8020017c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8020017c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802001a8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802001a8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802001d4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802001d4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80200460 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80200460(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80200874 fn_80200874 no verificada: desde bytes PPC
// Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y devuelve 0x80004001 (código de error estilo COM).
__attribute__((weak)) w3d_u32 A80200874(void) {
    w3d_u32 r3 = 0;
    w3d_open_break(0x80200874u);
    r3 = 0x80000000u;
    r3 = 0x80004001u;
    return r3;
}

// 0x802013c8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802013c8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r5 = 0x1u;
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80201400 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80201400(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r5 = 0x1u;
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802015c0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802015c0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r5 = 0x8u;
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802015f8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802015f8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r5 = 0x8u;
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80201698 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80201698(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r5 = 0x8u;
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802025a8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802025a8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80203fb8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80204760 en 80203fc4
__attribute__((weak)) w3d_u32 A80203fb8(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A80204760)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x80204174 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80204174(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    S32(r1 + 8, r5);
    S32(r1 + 12, r6);
    r4 = r1 + 8;
    r5 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r1 = r1 + 16;
    return r3;
}

// 0x802041a4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802041a4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    S32(r1 + 8, r5);
    S32(r1 + 12, r6);
    r4 = r1 + 8;
    r5 = 0x8u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r1 = r1 + 16;
    return r3;
}

// 0x802042ec heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8020430c en 802042f8
__attribute__((weak)) w3d_u32 A802042ec(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg))A8020430c)(W(r3), W(r4));
    r1 = r1 + 8;
    return r3;
}

// 0x80204428 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80204428(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x80204448 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80204448(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x80204468 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8035bbf0 en 80204474
__attribute__((weak)) w3d_u32 A80204468(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8035bbf0)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x80204488 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8035bbf0 en 80204494
__attribute__((weak)) w3d_u32 A80204488(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8035bbf0)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x802044a8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8035bc90 en 802044b4
__attribute__((weak)) w3d_u32 A802044a8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8035bc90)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x802044c8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8035bc90 en 802044d4
__attribute__((weak)) w3d_u32 A802044c8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8035bc90)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x80204530 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80204530(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A8035bd50, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80204720 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80204720(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x80204740 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80204740(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r1 = r1 + 8;
    return r3;
}

// 0x802047ac heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802047ac(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r6 = 0x0u;
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80205258 FUN_80205258 no verificada: desde bytes PPC
// Llama a sol35f7a_pool_allocate, native_forward_copy, handle_storage_release, memmove, sol35f9_binary_hint_8035b594_next.
__attribute__((weak)) w3d_u32 A80205258(w3d_u32 r3) {
    alignas(16) char frame[168];
    w3d_u32 r1 = h2g(frame) + 152;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 152; S32(t_, r1); r1 = t_; }
    r11 = 0x0u;
    r9 = r1 + 8;
    S32(r9 + 8, r11);
    r10 = r1 + 24;
    S32(r9 + 4, r11);
    r23 = r3;
    S32(r1 + 8, r11);
    r26 = r9;
    S32(r10 + 4, r11);
    r6 = r1 + 76;
    S32(r10 + 8, r11);
    r7 = r1 + 72;
    r25 = L32(r23 + 116);
    r0 = L32(r1 + 32);
    r8 = L32(r1 + 28);
    r24 = r25;
    r10 = r0 + r25;
    r9 = r0 >> 1;
    r0 = r0 + r9;
    S32(r1 + 24, r11);
    cr0 = CMPS(r10, r0);
    S32(r1 + 84, r8);
    S32(r1 + 72, r10);
    S32(r1 + 76, r0);
    if (!(cr0 & 8)) goto L_802052d0;
    r7 = r6;
L_802052d0:
    r0 = L32(r7);
    r0 = r0 << 2;
    r3 = r0;
    S32(r1 + 80, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r1 + 24);
    r30 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80205328;
    r9 = L32(r1 + 80);
    r11 = r1 + 84;
    r0 = L32(r1 + 84);
    r5 = r1 + 80;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80205310;
    r5 = r11;
L_80205310:
    r5 = L32(r5);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r1 + 24);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80205328:
    r0 = L32(r1 + 84);
    r11 = r25 << 2;
    r9 = L32(r1 + 80);
    r10 = r23 + 108;
    r0 = r30 + r0;
    S32(r1 + 24, r30);
    r9 = r30 + r9;
    r0 = r0 + r11;
    S32(r1 + 32, r9);
    S32(r1 + 28, r0);
    r9 = L32(r10 + 4);
    r0 = L32(r9 + 8);
    S32(r1 + 40, r0);
    r9 = L32(r10 + 4);
    S32(r1 + 48, r9);
    r21 = r11;
    r22 = r1 + 56;
    goto L_802054d4;
L_80205370:
    r11 = L32(r9 + 20);
    r10 = L32(r1 + 8);
    r0 = L32(r26 + 4);
    r11 = r11 << 2;
    r9 = L32(r1 + 24);
    r0 = r0 - r10;
    S32(r9 + r11, r0);
    r9 = L32(r1 + 40);
    r10 = L32(r26 + 4);
    r28 = L32(r9 + 16);
    r7 = L32(r1 + 8);
    r31 = r10;
    r11 = L16(r28 - 4);
    r8 = L32(r26 + 8);
    r27 = r10 - r7;
    r29 = r11 + 1;
    r0 = r10 + r29;
    cr0 = CMPU(r0, r8);
    if (!(cr0 & 4)) goto L_80205468;
    r0 = r8 - r7;
    r9 = r8 - r10;
    r11 = r0 >> 1;
    r9 = r29 - r9;
    r11 = r0 + r11;
    S32(r1 + 100, r27);
    r0 = r0 + r9;
    S32(r1 + 92, r11);
    cr0 = CMPS(r0, r11);
    S32(r1 + 88, r0);
    r0 = r1 + 92;
    r9 = r1 + 88;
    if (!(cr0 & 8)) goto L_802053f4;
    r9 = r0;
L_802053f4:
    r0 = L32(r9);
    r3 = r0;
    S32(r1 + 96, r0);
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80212fd4)(W(r3));
    r4 = L32(r1 + 8);
    r30 = r3;
    cr0 = CMPS(r4, 0);
    if ((cr0 & 2)) goto L_80205448;
    r9 = L32(r1 + 96);
    r11 = r1 + 100;
    r0 = L32(r1 + 100);
    r5 = r1 + 96;
    cr0 = CMPU(r9, r0);
    if (!(cr0 & 4)) goto L_80205430;
    r5 = r11;
L_80205430:
    r5 = L32(r5);
    r3 = r30;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r3 = L32(r1 + 8);
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80205448:
    r9 = L32(r1 + 100);
    r31 = r30 + r27;
    r0 = L32(r1 + 96);
    r9 = r30 + r9;
    S32(r26, r30);
    r0 = r30 + r0;
    S32(r26 + 4, r9);
    S32(r26 + 8, r0);
L_80205468:
    r5 = L32(r26 + 4);
    cr0 = CMPS(r31, r5);
    if (!(cr0 & 2)) goto L_80205498;
    r3 = r31;
    r4 = r28;
    r5 = r29;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
    r0 = L32(r26 + 4);
    r0 = r0 + r29;
    S32(r26 + 4, r0);
    goto L_802054c8;
L_80205498:
    r3 = r31 + r29;
    r4 = r31;
    r5 = r5 - r3;
    r3 = CU(A802eeef4, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r0 = L32(r26 + 4);
    r3 = r31;
    r4 = r28;
    r5 = r29;
    r0 = r0 + r29;
    S32(r26 + 4, r0);
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802eee50)(W(r3), W(r4), W(r5));
L_802054c8:
    r3 = L32(r1 + 40);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80351ef8)(W(r3));
    S32(r1 + 40, r3);
L_802054d4:
    r9 = L32(r1 + 40);
    r11 = 0x1u;
    r0 = L32(r1 + 48);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_802054ec;
    r11 = 0x0u;
L_802054ec:
    cr0 = CMPS(r11, 0);
    if (!(cr0 & 2)) goto L_80205370;
    r10 = L32(r26 + 4);
    r0 = ROTL(r24, 8) & 0xff0000u;
    r11 = L32(r1 + 8);
    r8 = r24 << 24;
    r8 = r8 | r0;
    r9 = ROTL(r24, 24) & 0xff00u;
    r10 = r10 - r11;
    r8 = r8 | r9;
    r0 = ROTL(r10, 8) & 0xff0000u;
    r11 = r10 << 24;
    r9 = ROTL(r10, 24) & 0xff00u;
    r11 = r11 | r0;
    r11 = r11 | r9;
    r10 = r10 >> 24;
    r9 = r24 >> 24;
    r0 = 0x53540000u;
    r8 = r8 | r9;
    r11 = r11 | r10;
    r0 = 0x53525453u;
    S32(r1 + 60, __builtin_bswap32(r8));
    S32(r1 + 56, r0);
    r4 = r22;
    S32(r1 + 64, __builtin_bswap32(r11));
    r3 = r23;
    r5 = 0xcu;
    r3 = A802047ac(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r6 = 0x0u;
    cr0 = CMPU(r6, r25);
    if (!(cr0 & 8)) goto L_802055a4;
    r7 = 0x0u;
L_8020556c:
    r8 = L32(r1 + 24);
    r6 = r6 + 1;
    cr0 = CMPU(r6, r25);
    r10 = L32(r8 + r7);
    r0 = r10 << 24;
    r9 = ROTL(r10, 8) & 0xff0000u;
    r11 = ROTL(r10, 24) & 0xff00u;
    r0 = r0 | r9;
    r0 = r0 | r11;
    r10 = r10 >> 24;
    r0 = r0 | r10;
    r7 = r7 + 4;
    if ((cr0 & 8)) goto L_8020556c;
L_802055a4:
    r4 = L32(r1 + 24);
    r5 = r21;
    r3 = r23;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r6 = 0x0u;
    cr0 = CMPU(r6, r25);
    if (!(cr0 & 8)) goto L_802055fc;
    r7 = 0x0u;
L_802055c4:
    r8 = L32(r1 + 24);
    r6 = r6 + 1;
    cr0 = CMPU(r6, r25);
    r10 = L32(r8 + r7);
    r0 = r10 << 24;
    r9 = ROTL(r10, 8) & 0xff0000u;
    r11 = ROTL(r10, 24) & 0xff00u;
    r0 = r0 | r9;
    r0 = r0 | r11;
    r10 = r10 >> 24;
    r0 = r0 | r10;
    r7 = r7 + 4;
    if ((cr0 & 8)) goto L_802055c4;
L_802055fc:
    r4 = L32(r1 + 8);
    r3 = r23;
    r5 = L32(r26 + 4);
    r5 = r5 - r4;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A802047e0)(W(r3), W(r4), W(r5));
    r3 = L32(r1 + 24);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80205620;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80205620:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80205630;
    ((void (*)(w3d_oarg))A802134fc)(W(r3));
L_80205630:
    r3 = 0x0u;
    r1 = r1 + 152;
    return r3;
}

// 0x80206058 FUN_80206058 no verificada: desde bytes PPC
// Llama a text_default, find, large_reserve_string_finish, large_reserve_string_release, record_assign. Hace 5 llamadas virtuales.
__attribute__((weak)) w3d_u32 A80206058(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[72];
    w3d_u32 r1 = h2g(frame) + 56;
    w3d_u32 r0 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 cr0 = 0, lr = 0, ca = 0;
    { w3d_u32 t_ = r1 - 56; S32(t_, r1); r1 = t_; }
    r28 = r3;
    r9 = r1 + 8;
    r3 = r1 + 12;
    r0 = 0x0u;
    r30 = r4;
    r29 = r9 + 8;
    S32(r1 + 8, r0);
    r26 = r9;
    r27 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r29;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    cr0 = CMPS(r30, 0);
    if ((cr0 & 2)) goto L_802060b4;
    r9 = L32(r30);
    r3 = r30;
    r0 = L32(r9 + 12);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802060b4:
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802060d0;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802060d0:
    S32(r1 + 24, r30);
    r31 = r28 + 20;
    S32(r1 + 8, r30);
    r5 = r1 + 24;
    r3 = L32(r28 + 20);
    r4 = L32(r31 + 4);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, w3d_oarg))A8035c0ac)(W(r3), W(r4), W(r5));
    r9 = L32(r31 + 4);
    cr0 = CMPS(r3, r9);
    if (!(cr0 & 2)) goto L_80206140;
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r29;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80206134;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80206134:
    r3 = 0x80000000u;
    r3 = 0x80004005u;
    goto L_8020621c;
L_80206140:
    r4 = r3 + 12;
    cr0 = CMPS(r4, r9);
    if ((cr0 & 2)) goto L_80206188;
    r30 = r4;
    r0 = 0xaaaa0000u;
    r9 = r9 - r30;
    r0 = 0xaaaaaaabu;
    r9 = (w3d_s32)r9 * (w3d_s32)r0;
    r28 = r3;
    { w3d_u32 t_ = r9; r29 = (w3d_u32)((w3d_s32)t_ >> 2); ca = SRAWCA(t_, 2); cr0 = CMPS(r29, 0); }
    if (!(cr0 & 4)) goto L_80206188;
L_8020616c:
    r3 = r28;
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8035c32c)(W(r3), W(r4));
    r30 = r30 + 12;
    r28 = r28 + 12;
    { w3d_u32 t_ = r29; r29 = t_ + (w3d_u32)-1; ca = r29 < t_; cr0 = CMPS(r29, 0); }
    if ((cr0 & 4)) goto L_8020616c;
L_80206188:
    r30 = L32(r31 + 4);
    r0 = r30 - 12;
    r28 = r30 - 4;
    S32(r31 + 4, r0);
    r3 = r28;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r29 = r30 - 8;
    r3 = r28;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = r29;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r29;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r30 - 12);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_802061d8;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_802061d8:
    r30 = r26 + 8;
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
    r3 = L32(r1 + 8);
    cr0 = CMPS(r3, 0);
    if ((cr0 & 2)) goto L_80206218;
    r9 = L32(r3);
    r0 = L32(r9 + 16);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
L_80206218:
    r3 = 0x0u;
L_8020621c:
    r1 = r1 + 56;
    return r3;
}

// 0x80208168 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80208168(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 28);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80208198 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80208198(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802081c8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802081c8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
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

// 0x80208298 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80208298(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802082c8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802082c8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8020860c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8020860c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 28);
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802088c4 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802088c4(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80209190 FUN_80209190 no verificada: desde bytes PPC
// Llama a text_format, request_report_failure.
__attribute__((weak)) w3d_u32 A80209190(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10) {
    alignas(16) char frame[160];
    w3d_u32 r1 = h2g(frame) + 144;
    w3d_u32 r0 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0, cr1 = 0;
    { w3d_u32 t_ = r1 - 144; S32(t_, r1); r1 = t_; }
    r31 = L32(r3 + 32);
    r30 = r6;
    r3 = r4;
    cr0 = CMPS(r31, 0);
    if (!(cr0 & 2)) goto L_802091b8;
    r31 = L32(D(0x804b0684u));
L_802091b8:
    cr0 = CMPS(r5, 0);
    if (!(cr0 & 2)) goto L_80209220;
    r0 = L32(r31 + 8);
    cr0 = CMPU(r0, r30);
    if ((cr0 & 8)) goto L_8020923c;
    r0 = L32(r31 + 12);
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_80209204;
    r5 = L32(r31 + 52);
    r4 = D(0x803b0000u);
    r4 = D(0x803b2eacu);
    r6 = r30;
    r3 = r1 + 8;
    cr1 = (cr1 & ~2u) | (((0) & 1) << 1);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg, ...))A803434d4)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8), W(r9), W(r10));
    r3 = r1 + 8;
    r4 = r30;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A801fcb64)(W(r3), W(r4));
    w3d_open_break(0x80209200u);
L_80209204:
    r0 = L32(r31 + 16);
    S32(r31 + 12, r30);
    cr0 = CMPU(r30, r0);
    if (!(cr0 & 4)) goto L_80209218;
    S32(r31 + 16, r30);
L_80209218:
    r3 = L32(r31 + 4);
    goto L_80209258;
L_80209220:
    cr0 = CMPS(r30, 0);
    if (!(cr0 & 2)) goto L_80209230;
    S32(r31 + 12, r30);
    goto L_80209258;
L_80209230:
    r0 = L32(r31 + 8);
    cr0 = CMPU(r0, r30);
    if (!(cr0 & 8)) goto L_80209244;
L_8020923c:
    r3 = 0x0u;
    goto L_80209258;
L_80209244:
    r0 = L32(r31 + 16);
    S32(r31 + 12, r30);
    cr0 = CMPU(r30, r0);
    if (!(cr0 & 4)) goto L_80209258;
    S32(r31 + 16, r30);
L_80209258:
    r1 = r1 + 144;
    return r3;
}

// 0x80209968 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80209968(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3);
    r3 = CU(A80209720, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x8020d544 FUN_8020d544 no verificada: desde bytes PPC
// Llama a string_truncate.
__attribute__((weak)) w3d_u32 A8020d544(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0, r9 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L16(r9 - 4);
    cr0 = CMPU(r0, r4);
    if (!(cr0 & 4)) goto L_8020d56c;
    ((void (*)(w3d_oarg, w3d_oarg))A8020c3a0)(W(r3), W(r4));
    goto L_8020d570;
L_8020d56c:
    w3d_open_break(0x8020d56cu);
L_8020d570:
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

// 0x8020ddc0 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8020ddc0(w3d_u32 r3, w3d_u32 r4) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r30 = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020dc54)(W(r3), W(r4));
    r3 = r30;
    r1 = r1 + 16;
    return r3;
}

// 0x8020f4b0 FUN_8020f4b0 no verificada: desde bytes PPC
// Nombre deducido por sus llamadores: buffer_request_write. Llama a tsonnet_c32_storage_open, request_prepare_write, request_transfer_write, tsonnet_c26_stack_pop.
__attribute__((weak)) w3d_u32 A8020f4b0(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[56];
    w3d_u32 r1 = h2g(frame) + 40;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    w3d_u32 cr0 = 0;
    { w3d_u32 t_ = r1 - 40; S32(t_, r1); r1 = t_; }
    r28 = r3;
    r25 = r4;
    r0 = L32(r28);
    r30 = r5;
    r26 = r6;
    cr0 = CMPS(r0, 0);
    if (!(cr0 & 2)) goto L_8020f4e4;
    r4 = 0x900000u;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020f3f0)(W(r3), W(r4));
L_8020f4e4:
    r9 = L32(r28 + 2064);
    r0 = r30 + 31;
    r29 = r0 & 0xffffffe0u;
    r8 = 0xffffffffu;
    r7 = r9;
    r10 = 0x0u;
    r11 = 0x0u;
    cr0 = CMPS(r9, 0);
    if ((cr0 & 2)) goto L_8020f578;
    r31 = r28 + 16;
    r0 = L32(r31 + 4);
    cr0 = CMPU(r0, r29);
    if ((cr0 & 8)) goto L_8020f544;
    cr0 = CMPS(r0, r29);
    if (!(cr0 & 2)) goto L_8020f52c;
    r10 = 0x1u;
    r27 = 0x0u;
    goto L_8020f578;
L_8020f52c:
    r0 = L32(r31 + 4);
    cr0 = CMPU(r0, r8);
    if (!(cr0 & 8)) goto L_8020f544;
    r8 = r0;
    r10 = 0x1u;
    r27 = r11;
L_8020f544:
    r11 = r11 + 1;
    cr0 = CMPU(r11, r7);
    if (!(cr0 & 8)) goto L_8020f578;
    r9 = r11 << 3;
    r9 = r9 + 16;
    r31 = r28 + r9;
    r0 = L32(r31 + 4);
    cr0 = CMPU(r0, r29);
    if ((cr0 & 8)) goto L_8020f544;
    cr0 = CMPS(r0, r29);
    if (!(cr0 & 2)) goto L_8020f52c;
    r27 = r11;
    r10 = 0x1u;
L_8020f578:
    cr0 = CMPS(r10, 0);
    if ((cr0 & 2)) goto L_8020f598;
    r0 = L32(r31 + 4);
    r9 = L32(r31);
    r11 = L32(r28 + 8);
    r9 = r9 + r0;
    cr0 = CMPU(r9, r11);
    if (!(cr0 & 4)) goto L_8020f5a0;
L_8020f598:
    r3 = 0x0u;
    goto L_8020f604;
L_8020f5a0:
    r9 = r27 << 3;
    r4 = r25;
    r30 = r9 + 16;
    r3 = r26;
    r27 = L32(r28 + r30);
    r6 = r29;
    r31 = r28 + r30;
    r5 = r27;
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A8020f3b8)(W(r3), W(r4), W(r5), W(r6));
    r4 = r26;
    r3 = r28;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg, w3d_oarg))A8020f940)(W(r3), W(r4));
    r0 = L32(r31 + 4);
    cr0 = CMPS(r0, r29);
    if (!(cr0 & 2)) goto L_8020f5ec;
    r3 = r28;
    r4 = r31;
    ((void (*)(w3d_oarg, w3d_oarg))A8020f8ac)(W(r3), W(r4));
    goto L_8020f600;
L_8020f5ec:
    r9 = r27 + r29;
    S32(r28 + r30, r9);
    r0 = L32(r31 + 4);
    r0 = r0 - r29;
    S32(r31 + 4, r0);
L_8020f600:
    r3 = 0x1u;
L_8020f604:
    r1 = r1 + 40;
    return r3;
}

// 0x802112d8 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 8021202c en 802112e4
__attribute__((weak)) w3d_u32 A802112d8(w3d_u32 r3) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A8021202c)(W(r3));
    r1 = r1 + 8;
    return r3;
}

// 0x8021660c heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A8021660c(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(D(0x804aba74u));
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x802185c8 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A802185c8(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r9 = L32(r3);
    r5 = r5 & 0xfffffffbu;
    r0 = L32(r9 + 20);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80219734 FUN_80219734 no verificada: desde bytes PPC
// Hace 1 llamada virtual.
__attribute__((weak)) w3d_u32 A80219734(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6) {
    alignas(16) char frame[48];
    w3d_u32 r1 = h2g(frame) + 32;
    w3d_u32 r0 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0;
    double f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 32; S32(t_, r1); r1 = t_; }
    r30 = r3;
    r29 = r4;
    r28 = r5;
    r27 = r6;
    w3d_open_break(0x80219754u);
    ((void (*)(w3d_oarg))A802199b4)(W(r3));
    r3 = L32(r30 + 20);
    r4 = r29;
    r5 = r28;
    r6 = r27;
    r9 = L32(r3);
    r0 = L32(r9 + 24);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 32;
    return r3;
}

// 0x80219840 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80219840(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    w3d_u32 r0 = 0;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    w3d_u32 lr = 0;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(r3 + 20);
    r9 = L32(r3);
    r0 = L32(r9 + 32);
    lr = r0;
    r3 = CU(g2h(lr), r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r1 = r1 + 8;
    return r3;
}

// 0x80219870 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80219870(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
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

// 0x8021de58 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 801298cc en 8021de78
__attribute__((weak)) w3d_u32 A8021de58(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[32];
    w3d_u32 r1 = h2g(frame) + 16;
    w3d_u32 r0 = 0, r30 = 0;
    { w3d_u32 t_ = r1 - 16; S32(t_, r1); r1 = t_; }
    r30 = L32(D(0x804abac0u));
    r0 = 0x0u;
    S32(r4 + 20, r0);
    r3 = L32(D(0x804b1788u));
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A801298cc)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r0 = 0x1u;
    S32(r30 + 160, r0);
    r1 = r1 + 16;
    return r3;
}

// 0x8021de98 heredados no verificada: desde bytes PPC
// aviso: lee r3 tras void 80129878 en 8021dea8
__attribute__((weak)) w3d_u32 A8021de98(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = L32(D(0x804b1788u));
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg))A80129878)(W(r3), W(r4), W(r5), W(r6), W(r7), W(r8));
    r1 = r1 + 8;
    return r3;
}

// 0x8021e248 FUN_8021e248 no verificada: desde bytes PPC
// Llama a engine_get_context, settings_read_int, placement_record, random, text_default. Usa las cadenas "ActiveWormIndex". Algo de cálculo en coma flotante.
// aviso: lee r3 tras void 80341588 en 8021e874
__attribute__((weak)) w3d_u32 A8021e248(w3d_u32 r3) {
    alignas(16) char frame[168];
    w3d_u32 r1 = h2g(frame) + 152;
    w3d_u32 r0 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r29 = 0, r30 = 0, r31 = 0;
    double f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f11 = 0, f12 = 0, f13 = 0;
    w3d_u32 cr0 = 0, ca = 0;
    { w3d_u32 t_ = r1 - 152; S32(t_, r1); r1 = t_; }
    r29 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r9 = D(0x803b0000u);
    r0 = 0xffffffffu;
    r9 = D(0x803b4708u);
    S32(r1 + 132, r0);
    r4 = r1 + 132;
    S32(r1 + 128, r9);
    r3 = r1 + 128;
    r3 = A800fc1f0(r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r29 + 272);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A800fc6dc)(W(r3));
    r31 = r3;
    r3 = (w3d_u32)((w3d_u32 (*)())A80162ba8)();
    r3 = r1 + 8;
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A803426b8)(W(r3));
    r3 = r1 + 8;
    r3 = CU(A80165018, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = L32(r29 + 260);
    r4 = L32(r1 + 8);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_8021e2bc;
    r0 = 0x0u;
L_8021e2bc:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8021e338;
    r3 = (w3d_u32)((w3d_u32 (*)())A80165254)();
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r1 + 8);
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
    r3 = r1 + 16;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r29 + 260);
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
L_8021e338:
    r3 = L32(D(0x804aa8c8u));
    r4 = r1 + 24;
    r3 = r3 + 328;
    ((void (*)(w3d_oarg, w3d_oarg))A8015aa04)(W(r3), W(r4));
    r4 = r1 + 24;
    r5 = 0x40u;
    r3 = r29 + 28;
    r3 = CU(A802eedc0, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r11 = L32(D(0x804aa8c8u));
    r3 = L32(r29 + 256);
    r9 = L32(r11 + 312);
    r10 = L32(r11 + 316);
    r9 = r9 << 2;
    r11 = L32(r10 + r9);
    r4 = L32(r11 + 60);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r9 = L32(r29 + 264);
    r4 = L32(r31 + 140);
    r3 = L32(r9 + 140);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_8021e398;
    r0 = 0x0u;
L_8021e398:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8021e414;
    r3 = r1 + 16;
    r30 = L32(r29 + 264);
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r30 + 140);
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
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r31 + 140);
    r3 = r1 + 88;
    S32(r1 + 88, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 88;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_8021e414:
    r9 = L32(r29 + 264);
    r7 = 0x0u;
    r11 = L32(r31 + 80);
    r10 = r31 + 80;
    r0 = L32(r9 + 80);
    r8 = r9 + 80;
    cr0 = CMPS(r0, r11);
    if (!(cr0 & 2)) goto L_8021e458;
    r9 = L32(r8 + 4);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8021e458;
    r9 = L32(r8 + 8);
    r0 = L32(r10 + 8);
    r7 = r9 ^ r0;
    { w3d_u32 t_ = r7; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r7 + ca; r7 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8021e458:
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_8021e498;
    r9 = L32(r29 + 264);
    r11 = r9 + 80;
    f13 = LF(r9 + 80);
    f0 = LF(r11 + 4);
    f12 = LF(r11 + 8);
    SF(r1 + 96, f13);
    SF(r1 + 100, f0);
    SF(r1 + 104, f12);
    f11 = LF(r10 + 8);
    f0 = LF(r31 + 80);
    f13 = LF(r10 + 4);
    SF(r1 + 112, f0);
    SF(r1 + 116, f13);
    SF(r1 + 120, f11);
L_8021e498:
    r9 = L32(r29 + 264);
    r7 = 0x0u;
    r11 = L32(r31 + 68);
    r10 = r31 + 68;
    r0 = L32(r9 + 68);
    r8 = r9 + 68;
    cr0 = CMPS(r0, r11);
    if (!(cr0 & 2)) goto L_8021e4dc;
    r9 = L32(r8 + 4);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8021e4dc;
    r9 = L32(r8 + 8);
    r0 = L32(r10 + 8);
    r7 = r9 ^ r0;
    { w3d_u32 t_ = r7; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r7 + ca; r7 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8021e4dc:
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_8021e51c;
    r9 = L32(r29 + 264);
    r11 = r9 + 68;
    f13 = LF(r9 + 68);
    f0 = LF(r11 + 4);
    f12 = LF(r11 + 8);
    SF(r1 + 88, f13);
    SF(r1 + 92, f0);
    SF(r1 + 96, f12);
    f11 = LF(r10 + 8);
    f0 = LF(r31 + 68);
    f13 = LF(r10 + 4);
    SF(r1 + 104, f0);
    SF(r1 + 108, f13);
    SF(r1 + 112, f11);
L_8021e51c:
    r9 = L32(r29 + 264);
    r7 = 0x0u;
    r11 = L32(r31 + 92);
    r10 = r31 + 92;
    r0 = L32(r9 + 92);
    r8 = r9 + 92;
    cr0 = CMPS(r0, r11);
    if (!(cr0 & 2)) goto L_8021e560;
    r9 = L32(r8 + 4);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8021e560;
    r9 = L32(r8 + 8);
    r0 = L32(r10 + 8);
    r7 = r9 ^ r0;
    { w3d_u32 t_ = r7; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r7 + ca; r7 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8021e560:
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_8021e5a0;
    r9 = L32(r29 + 264);
    r11 = r9 + 92;
    f13 = LF(r9 + 92);
    f0 = LF(r11 + 4);
    f12 = LF(r11 + 8);
    SF(r1 + 88, f13);
    SF(r1 + 92, f0);
    SF(r1 + 96, f12);
    f11 = LF(r10 + 8);
    f0 = LF(r31 + 92);
    f13 = LF(r10 + 4);
    SF(r1 + 104, f0);
    SF(r1 + 108, f13);
    SF(r1 + 112, f11);
L_8021e5a0:
    r9 = L32(r29 + 264);
    r7 = 0x0u;
    r11 = L32(r31 + 44);
    r10 = r31 + 44;
    r0 = L32(r9 + 44);
    r8 = r9 + 44;
    cr0 = CMPS(r0, r11);
    if (!(cr0 & 2)) goto L_8021e5e4;
    r9 = L32(r8 + 4);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8021e5e4;
    r9 = L32(r8 + 8);
    r0 = L32(r10 + 8);
    r7 = r9 ^ r0;
    { w3d_u32 t_ = r7; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r7 + ca; r7 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8021e5e4:
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_8021e624;
    r9 = L32(r29 + 264);
    r11 = r9 + 44;
    f13 = LF(r9 + 44);
    f0 = LF(r11 + 4);
    f12 = LF(r11 + 8);
    SF(r1 + 88, f13);
    SF(r1 + 92, f0);
    SF(r1 + 96, f12);
    f11 = LF(r10 + 8);
    f0 = LF(r31 + 44);
    f13 = LF(r10 + 4);
    SF(r1 + 104, f0);
    SF(r1 + 108, f13);
    SF(r1 + 112, f11);
L_8021e624:
    r9 = L32(r29 + 264);
    r7 = 0x0u;
    r11 = L32(r31 + 32);
    r10 = r31 + 32;
    r0 = L32(r9 + 32);
    r8 = r9 + 32;
    cr0 = CMPS(r0, r11);
    if (!(cr0 & 2)) goto L_8021e668;
    r9 = L32(r8 + 4);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8021e668;
    r9 = L32(r8 + 8);
    r0 = L32(r10 + 8);
    r7 = r9 ^ r0;
    { w3d_u32 t_ = r7; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r7 + ca; r7 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8021e668:
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_8021e6a8;
    r9 = L32(r29 + 264);
    r11 = r9 + 32;
    f13 = LF(r9 + 32);
    f0 = LF(r11 + 4);
    f12 = LF(r11 + 8);
    SF(r1 + 88, f13);
    SF(r1 + 92, f0);
    SF(r1 + 96, f12);
    f11 = LF(r10 + 8);
    f0 = LF(r31 + 32);
    f13 = LF(r10 + 4);
    SF(r1 + 104, f0);
    SF(r1 + 108, f13);
    SF(r1 + 112, f11);
L_8021e6a8:
    r11 = L32(r29 + 264);
    r3 = L32(r11 + 108);
    r4 = L32(r31 + 108);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_8021e6c8;
    r0 = 0x0u;
L_8021e6c8:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8021e744;
    r3 = r1 + 16;
    r30 = L32(r29 + 264);
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r30 + 108);
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
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r31 + 108);
    r3 = r1 + 88;
    S32(r1 + 88, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 88;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_8021e744:
    r9 = L32(r29 + 264);
    r4 = L32(r31 + 152);
    r3 = L32(r9 + 152);
    r3 = CU(A802ef234, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    cr0 = CMPS(r3, 0);
    r0 = 0x1u;
    if (!(cr0 & 2)) goto L_8021e764;
    r0 = 0x0u;
L_8021e764:
    cr0 = CMPS(r0, 0);
    if ((cr0 & 2)) goto L_8021e7e0;
    r3 = r1 + 16;
    r30 = L32(r29 + 264);
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r30 + 152);
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
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A8020c5c0)(W(r3));
    r0 = L32(r31 + 152);
    r3 = r1 + 88;
    S32(r1 + 88, r0);
    r3 = (w3d_u32)((w3d_u32 (*)(w3d_oarg))A80341884)(W(r3));
    r11 = r3;
    r9 = L16(r11);
    r3 = r1 + 88;
    r9 = r9 + 1;
    S16(r11, r9);
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r1 + 88;
    ((void (*)(w3d_oarg))A80341588)(W(r3));
L_8021e7e0:
    r9 = L32(r29 + 264);
    r7 = 0x0u;
    r11 = L32(r31 + 20);
    r10 = r31 + 20;
    r0 = L32(r9 + 20);
    r8 = r9 + 20;
    cr0 = CMPS(r0, r11);
    if (!(cr0 & 2)) goto L_8021e824;
    r9 = L32(r8 + 4);
    r0 = L32(r10 + 4);
    cr0 = CMPS(r9, r0);
    if (!(cr0 & 2)) goto L_8021e824;
    r9 = L32(r8 + 8);
    r0 = L32(r10 + 8);
    r7 = r9 ^ r0;
    { w3d_u32 t_ = r7; r11 = (w3d_u32)0 - t_; ca = ((w3d_u32)0 >= t_); }
    { w3d_u64 t_ = (w3d_u64)r11 + r7 + ca; r7 = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32); }
L_8021e824:
    cr0 = CMPS(r7, 0);
    if (!(cr0 & 2)) goto L_8021e864;
    r9 = L32(r29 + 264);
    r11 = r9 + 20;
    f13 = LF(r9 + 20);
    f0 = LF(r11 + 4);
    f12 = LF(r11 + 8);
    SF(r1 + 88, f13);
    SF(r1 + 92, f0);
    SF(r1 + 96, f12);
    f11 = LF(r10 + 8);
    f0 = LF(r31 + 20);
    f13 = LF(r10 + 4);
    SF(r1 + 104, f0);
    SF(r1 + 108, f13);
    SF(r1 + 112, f11);
L_8021e864:
    r30 = r1 + 8;
    r3 = r30;
    ((void (*)(w3d_oarg))A8020c5c4)(W(r3));
    r3 = r30;
    r3 = (w3d_u32)((w3d_oarg (*)(w3d_oarg))A80341588)(W(r3));
    r1 = r1 + 152;
    return r3;
}

// 0x80226d44 heredados no verificada: desde bytes PPC
__attribute__((weak)) w3d_u32 A80226d44(w3d_u32 r3, w3d_u32 r4, w3d_u32 r5, w3d_u32 r6, w3d_u32 r7, w3d_u32 r8, w3d_u32 r9, w3d_u32 r10, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8) {
    alignas(16) char frame[24];
    w3d_u32 r1 = h2g(frame) + 8;
    double f1 = s1, f2 = s2, f3 = s3, f4 = s4, f5 = s5, f6 = s6, f7 = s7, f8 = s8;
    { w3d_u32 t_ = r1 - 8; S32(t_, r1); r1 = t_; }
    r3 = CU(A801e8d9c, r3, r4, r5, r6, r7, r8, r9, r10, f1, f2, f3, f4, f5, f6, f7, f8);
    r3 = 0x0u;
    r1 = r1 + 8;
    return r3;
}

}
