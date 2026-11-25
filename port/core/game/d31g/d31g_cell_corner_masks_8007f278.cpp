#include "w3d_ptr.h"
#line 1 "d31g_cell_corner_masks_8007f278.cpp"
// GWMP8P rev0 0x8007f278. Builds the two corner masks 0x804adb20 and
// 0x804adb24 for a terrain cell from the eight neighbour flag words
// 0x804addec..0x804ade08: bits 0..8 from the first four words, bits 10..18
// from the last four. Meanings of the flag bits are inferred.
extern unsigned w3d_mask_a_804adb20, w3d_mask_b_804adb24;
extern unsigned n0_804addec, n1_804addf0, n2_804addf4, n3_804addf8, n4_804addfc, n5_804ade00, n6_804ade04, n7_804ade08;


extern "C" void w3d_d31g_cell_corner_masks_8007f278() {
    unsigned a = n0_804addec;
    w3d_mask_a_804adb20 = 0;
    w3d_mask_b_804adb24 = 0;
    if ((a & 68) != 68) w3d_mask_b_804adb24 = 2;
    if ((n2_804addf4 & 17) != 17) w3d_mask_b_804adb24 |= 128;
    if ((a & 34) != 34) w3d_mask_b_804adb24 |= 8;
    unsigned b = n1_804addf0;
    if ((b & 17) != 17) w3d_mask_b_804adb24 |= 32;
    if (a & 64) {
        if (!(a & 32)) w3d_mask_b_804adb24 |= 1;
        if (!(b & 16)) w3d_mask_b_804adb24 |= 4;
    } else {
        w3d_mask_b_804adb24 |= 2;
        if (a & 128) w3d_mask_b_804adb24 |= 1;
        if (b & 64) w3d_mask_b_804adb24 |= 4;
    }
    if (n2_804addf4 & 16) {
        if (!(n0_804addec & 32)) w3d_mask_b_804adb24 |= 64;
        if (!(n1_804addf0 & 16)) w3d_mask_b_804adb24 |= 256;
    } else {
        w3d_mask_b_804adb24 |= 128;
        if (n2_804addf4 & 32) w3d_mask_b_804adb24 |= 64;
        if (n3_804addf8 & 16) w3d_mask_b_804adb24 |= 256;
    }
    if (n0_804addec & 32) {
        if (!(n0_804addec & 64)) w3d_mask_b_804adb24 |= 1;
        if (!(n2_804addf4 & 16)) w3d_mask_b_804adb24 |= 64;
    } else {
        w3d_mask_b_804adb24 |= 8;
        if (n0_804addec & 128) w3d_mask_b_804adb24 |= 1;
        if (n2_804addf4 & 32) w3d_mask_b_804adb24 |= 64;
    }
    if (n1_804addf0 & 16) {
        if (!(n0_804addec & 64)) w3d_mask_b_804adb24 |= 4;
        if (!(n2_804addf4 & 16)) w3d_mask_b_804adb24 |= 256;
    } else {
        w3d_mask_b_804adb24 |= 32;
        if (n1_804addf0 & 64) w3d_mask_b_804adb24 |= 4;
        if (n3_804addf8 & 16) w3d_mask_b_804adb24 |= 256;
    }
    unsigned x = n0_804addec;
    if (x & 1) {
        if ((x & 15) == 1 && (x & 240) > 16) w3d_mask_a_804adb20 |= 11;
        x = n1_804addf0;
        if ((x & 15) == 2 && (x & 240) > 32) w3d_mask_a_804adb20 |= 38;
        x = n2_804addf4;
        if ((x & 15) == 4 && (x & 240) > 64) w3d_mask_a_804adb20 |= 200;
        x = n3_804addf8;
        if ((x & 15) == 8 && (x & 240) > 128) w3d_mask_a_804adb20 |= 416;
    } else {
        w3d_mask_a_804adb20 = 186;
        if (x & 64) w3d_mask_a_804adb20 = 191;
        unsigned c = n2_804addf4;
        if (c & 16) w3d_mask_a_804adb20 |= 320;
        if (x & 32) w3d_mask_a_804adb20 |= 65;
        unsigned d = n1_804addf0;
        if (d & 16) w3d_mask_a_804adb20 |= 260;
        if (x & 128) w3d_mask_a_804adb20 |= 1;
        if (d & 64) w3d_mask_a_804adb20 |= 4;
        if (c & 32) w3d_mask_a_804adb20 |= 64;
        if (n3_804addf8 & 16) w3d_mask_a_804adb20 |= 256;
    }
    unsigned e = n4_804addfc;
    if ((e & 68) != 68) w3d_mask_b_804adb24 |= 1024;
    if ((n6_804ade04 & 17) != 17) w3d_mask_b_804adb24 |= 65536;
    if ((e & 34) != 34) w3d_mask_b_804adb24 |= 4096;
    if ((n5_804ade00 & 17) != 17) w3d_mask_b_804adb24 |= 16384;
    if (n0_804addec & 64) {
        if (!(n0_804addec & 32)) w3d_mask_b_804adb24 |= 512;
        if (!(n1_804addf0 & 16)) w3d_mask_b_804adb24 |= 2048;
    } else {
        w3d_mask_b_804adb24 |= 1024;
        if (n0_804addec & 128) w3d_mask_b_804adb24 |= 512;
        if (n1_804addf0 & 64) w3d_mask_b_804adb24 |= 2048;
    }
    if (n2_804addf4 & 16) {
        if (!(n0_804addec & 32)) w3d_mask_b_804adb24 |= 32768;
        if (!(n1_804addf0 & 16)) w3d_mask_b_804adb24 |= 131072;
    } else {
        w3d_mask_b_804adb24 |= 65536;
        if (n2_804addf4 & 32) w3d_mask_b_804adb24 |= 32768;
        if (n3_804addf8 & 16) w3d_mask_b_804adb24 |= 131072;
    }
    if (n0_804addec & 32) {
        if (!(n0_804addec & 64)) w3d_mask_b_804adb24 |= 512;
        if (!(n2_804addf4 & 16)) w3d_mask_b_804adb24 |= 32768;
    } else {
        w3d_mask_b_804adb24 |= 4096;
        if (n0_804addec & 128) w3d_mask_b_804adb24 |= 512;
        if (n2_804addf4 & 32) w3d_mask_b_804adb24 |= 32768;
    }
    if (n1_804addf0 & 16) {
        if (!(n0_804addec & 64)) w3d_mask_b_804adb24 |= 2048;
        if (!(n2_804addf4 & 16)) w3d_mask_b_804adb24 |= 131072;
    } else {
        w3d_mask_b_804adb24 |= 16384;
        if (n1_804addf0 & 64) w3d_mask_b_804adb24 |= 2048;
        if (n3_804addf8 & 16) w3d_mask_b_804adb24 |= 131072;
    }
    x = n4_804addfc;
    if (x & 16) {
        if ((x & 240) == 16 && (x & 15) > 1) w3d_mask_a_804adb20 |= 5632;
        x = n5_804ade00;
        if ((x & 240) == 32 && (x & 15) > 2) w3d_mask_a_804adb20 |= 19456;
        x = n6_804ade04;
        if ((x & 240) == 64 && (x & 15) > 4) w3d_mask_a_804adb20 |= 102400;
        x = n7_804ade08;
        if ((x & 240) == 128 && (x & 15) > 8) w3d_mask_a_804adb20 |= 212992;
    } else {
        unsigned y = w3d_mask_a_804adb20 | 65536;
        unsigned g = n0_804addec;
        w3d_mask_a_804adb20 = y | 29696;
        if (g & 64) w3d_mask_a_804adb20 = y | 32256;
        unsigned c = n2_804addf4;
        if (c & 16) { unsigned t = w3d_mask_a_804adb20 | 32768; w3d_mask_a_804adb20 = t | 131072; }
        if (g & 32) w3d_mask_a_804adb20 |= 33280;
        unsigned d = n1_804addf0;
        if (d & 16) { unsigned t = w3d_mask_a_804adb20 | 2048; w3d_mask_a_804adb20 = t | 131072; }
        if (g & 128) w3d_mask_a_804adb20 |= 512;
        if (d & 64) w3d_mask_a_804adb20 |= 2048;
        if (c & 32) w3d_mask_a_804adb20 |= 32768;
        if (n3_804addf8 & 16) w3d_mask_a_804adb20 |= 131072;
    }
    w3d_mask_a_804adb20 |= w3d_mask_b_804adb24;
}


