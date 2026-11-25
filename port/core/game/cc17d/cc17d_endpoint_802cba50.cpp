#include "w3d_ptr.h"
#line 1 "cc17d_endpoint_802cba50.cpp"
// cc17d: endpoint queries for the 16 endpoint slots (see cx7p endpoint units).
// Observed: 0x804abce4 is a nonzero "initialized" word; 0x80473724 holds 16
// active words, 0x804737a4 sixteen 16-byte vector records (begin, end, ...)
// and 0x804738a4 sixteen endpoint interface pointers.  0x802cb314 is called
// with the slot index first (inferred: per-slot update).
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
struct Cc17dQueue { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<void> alloc; Ptr32<Ptr32<void>> cap; };
extern int lbl_804abce4;
extern unsigned int lbl_80473724[];
extern Cc17dQueue lbl_804737a4[];
extern Ptr32<void> lbl_804738a4[];
extern "C" void fn_802cb314(unsigned int index);
#define CC17D_AT(T, base, off) (*(w3d::slot_t<T> *)w3d::AG((off) + (char *)w3d::AG(base)))
static inline unsigned int cc17d_size(Ptr32<Cc17dQueue> q) { return (unsigned int)((Ptr32<char>)q->end - (Ptr32<char>)q->begin) / 4; }
extern "C" int w3d_cc17d_endpoint_has_queued_802cba50(unsigned int index)
{
    if (index > 15)
        return 0;
    fn_802cb314(index);
    if (lbl_804abce4 != 0) {
        int r = 0;
        if (cc17d_size(&CC17D_AT(Cc17dQueue, lbl_804737a4, index << 4)) != 0)
            r = 1;
        return r;
    }
    return 0;
}
extern "C" int w3d_cc17d_endpoint_query_802cbacc(unsigned int index)
{
    if (lbl_804abce4 == 0 || index > 15)
        return 0;
    fn_802cb314(index);
    if (CC17D_AT(unsigned int, lbl_80473724, index << 2) == 0)
        return 0;
    Ptr32<void> p = CC17D_AT(void *, lbl_804738a4, index << 2);
    return VCALL(p, int (*)(void *), 48)(p) != 0;
}


