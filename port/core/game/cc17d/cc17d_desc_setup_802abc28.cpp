#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17d_desc_setup_802abc28.c"
/* cc17d: descriptor setup leaf at 0x802abc28.  Observed: copies the words at
   +0 and +16 into several slots, writes constant sizes/offsets (176, 208, 0,
   224, 192, -1) and a code 160/161/164/163 at +4 chosen by the mode at +20
   (0..3).  Meanings inferred. */
struct Cc17dDesc { int w[108]; };
/* Statement order chosen by a local search over store orders; the scheduler
   reorders independent stores, and only this source order reproduces the
   original sequence. */
void w3d_cc17d_desc_setup_802abc28(Ptr32<struct Cc17dDesc> d)
{
    int a = d->w[0];
    int b = d->w[4];
    d->w[9] = 176;
    d->w[16] = 208;
    d->w[42] = 0;
    d->w[47] = 224;
    d->w[107] = 192;
    d->w[6] = a;
    d->w[13] = a;
    d->w[14] = b;
    d->w[44] = a;
    d->w[104] = a;
    d->w[46] = b;
    d->w[105] = b;
    d->w[2] = -1;
    switch (d->w[5]) {
    case 1: d->w[1] = 161; break;
    case 3: d->w[1] = 163; break;
    case 2: d->w[1] = 164; break;
    case 0: d->w[1] = 160; break;
    }
}

}
