#include "w3d_ptr.h"
#line 1 "s8family_800e6c30.cpp"
struct s8_Triple { int x,y,z; };
struct s8_Base_800dcbc4 {
    s8_Triple source;
    template <class W3dU> s8_Base_800dcbc4(Ptr32<W3dU> w3d_p) : s8_Base_800dcbc4((const s8_Triple *)w3d_p.get()) {}
 s8_Base_800dcbc4(const s8_Triple *);
};
struct s8_Snapshot_800e6be8 : s8_Base_800dcbc4 {
    char pad12[104] __attribute__((aligned(__alignof__(s8_Base_800dcbc4))));
    s8_Triple snapshot;
    s8_Snapshot_800e6be8();
};
inline void *operator new(__SIZE_TYPE__,void *storage) { return storage; }
extern "C" void s8_snapshot_reset_800e6c30(Ptr32<s8_Snapshot_800e6be8> self,Ptr32<const s8_Triple> from) {
    new ((Ptr32<s8_Base_800dcbc4>)self) s8_Base_800dcbc4(from);
    self->snapshot=self->source;
}


