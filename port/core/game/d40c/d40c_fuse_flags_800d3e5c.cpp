#include "w3d_ptr.h"
#line 1 "d40c_fuse_flags_800d3e5c.cpp"
// d40c: 0x800d3e5c. Sets four flag bits and two progress fractions from two
// pairs of fuse times against the current time. Both arms of each pair are
// written out in full; they cross-jump after allocation, and the extra
// references order the registers.
struct Desc { char u0[100]; int gap; };
struct Self { char u0[136]; Ptr32<void> h136; };
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void d40c_fuse_flags_800d3e5c(Ptr32<Self> self, int now, int a, int b, int c, int e, Ptr32<unsigned char> flags, Ptr32<float> o1, Ptr32<float> o2) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h136));
    if (a > now) {
        if (b > now) goto second;
        *flags |= 4;
        *o1 = (float)(now - b) / (float)now;
        goto second;
    }
    if (b > now) {
        *flags |= 8;
        *o1 = (float)(now - a) / (float)now;
    } else if (a < b) {
        if (b - a < d->gap) goto second;
        *flags |= 8;
        *o1 = (float)(now - a) / (float)now;
    } else {
        if (a - b < d->gap) goto second;
        *flags |= 4;
        *o1 = (float)(now - b) / (float)now;
    }
second:
    if (c > now) {
        if (e > now) return;
        *flags |= 1;
        *o2 = (float)(now - e) / (float)now;
        return;
    }
    if (e > now) {
        *flags |= 2;
        *o2 = (float)(now - c) / (float)now;
    } else if (c < e) {
        if (e - c < d->gap) return;
        *flags |= 2;
        *o2 = (float)(now - c) / (float)now;
    } else {
        if (c - e < d->gap) return;
        *flags |= 1;
        *o2 = (float)(now - e) / (float)now;
    }
}


