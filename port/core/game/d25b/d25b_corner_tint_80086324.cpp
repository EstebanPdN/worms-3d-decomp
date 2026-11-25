#include "w3d_ptr.h"
#line 1 "d25b_corner_tint_80086324.cpp"
/* Corner tint selection (0x80086324): reads eight colour components from the two records
 * at +388 and +392 at the eight byte offsets 0x804addec to 0x804ade08 into
 * the two corner sets 0x804ada74 and 0x804ada94, sets 0x7f00 on the corners whose flag
 * words at +656, +664, +660, +668 have bits 2 and 1 set, and stores the averaged rows
 * in 0x804adb28 and 0x804adb30. Field and type names are inferred from the original
 * instructions. The unit owns no data. */
struct Tint {
    char unknown00[388];
    Ptr32<unsigned char> first;   /* +388 */
    Ptr32<unsigned char> second;  /* +392 */
    char unknown396[260];
    unsigned flagsA;  /* +656 */
    unsigned flagsC;  /* +660 */
    unsigned flagsB;  /* +664 */
    unsigned flagsD;  /* +668 */
};
extern int w3d_tint_offset_804addec;
extern int w3d_tint_offset_804addf0;
extern int w3d_tint_offset_804addf4;
extern int w3d_tint_offset_804addf8;
extern int w3d_tint_offset_804addfc;
extern int w3d_tint_offset_804ade00;
extern int w3d_tint_offset_804ade04;
extern int w3d_tint_offset_804ade08;
extern unsigned w3d_tint_corner_804ada74;
extern unsigned w3d_tint_corner_804ada78;
extern unsigned w3d_tint_corner_804ada7c;
extern unsigned w3d_tint_corner_804ada80;
extern unsigned w3d_tint_corner_804ada84;
extern unsigned w3d_tint_corner_804ada88;
extern unsigned w3d_tint_corner_804ada8c;
extern unsigned w3d_tint_corner_804ada90;
extern unsigned w3d_tint_corner_804ada94;
extern unsigned w3d_tint_corner_804ada98;
extern unsigned w3d_tint_corner_804ada9c;
extern unsigned w3d_tint_corner_804adaa0;
extern unsigned w3d_tint_corner_804adaa4;
extern unsigned w3d_tint_corner_804adaa8;
extern unsigned w3d_tint_corner_804adaac;
extern unsigned w3d_tint_corner_804adab0;
extern unsigned w3d_tint_row_804adb28;
extern unsigned w3d_tint_row_804adb30;

extern "C" void w3d_d25b_corner_tint_80086324(Ptr32<Tint> self)
{
    w3d_tint_corner_804ada74 = self->first[w3d_tint_offset_804addec];
    w3d_tint_corner_804ada78 = self->first[w3d_tint_offset_804addf0];
    w3d_tint_corner_804ada7c = self->first[w3d_tint_offset_804addf4];
    w3d_tint_corner_804ada80 = self->first[w3d_tint_offset_804addf8];
    w3d_tint_corner_804ada84 = self->first[w3d_tint_offset_804addfc];
    w3d_tint_corner_804ada88 = self->first[w3d_tint_offset_804ade00];
    w3d_tint_corner_804ada8c = self->first[w3d_tint_offset_804ade04];
    w3d_tint_corner_804ada90 = self->first[w3d_tint_offset_804ade08];
    w3d_tint_corner_804ada94 = self->second[w3d_tint_offset_804addec];
    w3d_tint_corner_804ada98 = self->second[w3d_tint_offset_804addf0];
    w3d_tint_corner_804ada9c = self->second[w3d_tint_offset_804addf4];
    w3d_tint_corner_804adaa0 = self->second[w3d_tint_offset_804addf8];
    w3d_tint_corner_804adaa4 = self->second[w3d_tint_offset_804addfc];
    w3d_tint_corner_804adaa8 = self->second[w3d_tint_offset_804ade00];
    w3d_tint_corner_804adaac = self->second[w3d_tint_offset_804ade04];
    w3d_tint_corner_804adab0 = self->second[w3d_tint_offset_804ade08];
    if (self->flagsA & 2) {
        w3d_tint_corner_804ada74 |= 0x7f00;
        w3d_tint_corner_804ada94 |= 0x7f00;
    }
    if (self->flagsB & 2) {
        w3d_tint_corner_804ada78 |= 0x7f00;
        w3d_tint_corner_804ada98 |= 0x7f00;
    }
    if (self->flagsC & 2) {
        w3d_tint_corner_804ada7c |= 0x7f00;
        w3d_tint_corner_804ada9c |= 0x7f00;
    }
    if (self->flagsD & 2) {
        w3d_tint_corner_804ada80 |= 0x7f00;
        w3d_tint_corner_804adaa0 |= 0x7f00;
    }
    if (self->flagsA & 1) {
        w3d_tint_corner_804ada84 |= 0x7f00;
        w3d_tint_corner_804adaa4 |= 0x7f00;
    }
    if (self->flagsB & 1) {
        w3d_tint_corner_804ada88 |= 0x7f00;
        w3d_tint_corner_804adaa8 |= 0x7f00;
    }
    if (self->flagsC & 1) {
        w3d_tint_corner_804ada8c |= 0x7f00;
        w3d_tint_corner_804adaac |= 0x7f00;
    }
    if (self->flagsD & 1) {
        w3d_tint_corner_804ada90 |= 0x7f00;
        w3d_tint_corner_804adab0 |= 0x7f00;
    }
    w3d_tint_row_804adb28 = (((w3d_tint_corner_804ada74 + w3d_tint_corner_804ada78) & 0xfefe) >> 1) + (((w3d_tint_corner_804ada7c + w3d_tint_corner_804ada80) & 0xfefe) >> 1);
    w3d_tint_row_804adb30 = (((w3d_tint_corner_804ada84 + w3d_tint_corner_804ada88) & 0xfefe) >> 1) + (((w3d_tint_corner_804ada8c + w3d_tint_corner_804ada90) & 0xfefe) >> 1);
}


