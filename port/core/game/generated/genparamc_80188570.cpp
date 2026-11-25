#include "w3d_ptr.h"
#line 1 "genparamc_80188570.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): toggle a flag while holding a reference. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
struct W3dRef {
    Ptr32<void> object;
    int pad;
    template <class W3dU> W3dRef(Ptr32<W3dU> w3d_p) : W3dRef((void *)w3d_p.get()) {}
 W3dRef(void *p) { object = p; if (p) VCALL(p, 12); }
    ~W3dRef() { if (object) VCALL(object, 16); }
};
extern "C" Ptr32<void> lbl_804b0208;
extern "C" Ptr32<void> lbl_804b0204;
extern "C" int fn_801d4544(Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<void> lbl_804b0214;
extern "C" Ptr32<void> lbl_804b0218;

extern "C" int w3d_set_highlight_80188570(Ptr32<void> self, int enable)
{
    W3dRef node(FIELD(FIELD(self, void *, 48), void *, 52));
    if (!enable) {
        fn_801d4544(node.object, lbl_804b0208);
        FIELD(self, unsigned short, 56) &= ~2;
    } else {
        fn_801d4544(node.object, lbl_804b0204);
        FIELD(self, unsigned short, 56) |= 2;
    }
    return 0;
}

extern "C" int w3d_set_highlight_80188618(Ptr32<void> self, int enable)
{
    W3dRef node(FIELD(FIELD(self, void *, 48), void *, 52));
    if (!enable) {
        fn_801d4544(node.object, lbl_804b0214);
        FIELD(self, unsigned short, 56) &= ~16;
    } else {
        fn_801d4544(node.object, lbl_804b0218);
        FIELD(self, unsigned short, 56) |= 16;
    }
    return 0;
}


