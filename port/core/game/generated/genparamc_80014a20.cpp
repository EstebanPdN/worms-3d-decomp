#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_80014a20.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* AI plan clone variant (see genparam_80013a18): same 104-byte layout, different final store order. */
typedef struct { unsigned char unknown00[44]; int references; } W3dS6CloneQueue;
typedef struct {int unknown; Ptr32<W3dS6CloneQueue> pointer;} W3dS6CloneRef;
static inline void s6_clone_ref_init(Ptr32<W3dS6CloneRef> ref) {ref->pointer=0;}
typedef struct { int kind; float score; int active; Ptr32<void> volatile vtable; int index,weapon; unsigned char unknown18[44]; int flags; W3dS6CloneRef first,second; unsigned char unknown58[16]; } W3dS6ClonePlan;
Ptr32<void> memcpy(Ptr32<void>,Ptr32<const void>,unsigned);
void fn_80006360(Ptr32<W3dS6ClonePlan>);
extern char lbl_8040d7b8[];
extern char lbl_8040cdc8[];
extern const float lbl_8036a520[];

Ptr32<W3dS6ClonePlan> w3d_ai_clone_plan_80014a20(Ptr32<W3dS6ClonePlan> dst,Ptr32<W3dS6ClonePlan> src) {
    Ptr32<void> volatile saved;
    fn_80006360(dst);
    dst->vtable=lbl_8040d7b8;
    s6_clone_ref_init(&dst->first); s6_clone_ref_init(&dst->second);
    saved=dst->vtable;
    memcpy(dst,src,104);
    dst->vtable=saved;
    dst->score=*lbl_8036a520;
    if(src->first.pointer) { dst->first.pointer=src->first.pointer; dst->first.pointer->references++; }
    if(src->second.pointer) { dst->second.pointer=src->second.pointer; dst->second.pointer->references++; }
    dst->vtable=lbl_8040cdc8;
    dst->weapon=18;
    dst->flags=3137;
    return dst;
}

}
