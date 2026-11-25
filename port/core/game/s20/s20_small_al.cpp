#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_al.c"
/* Position query through a sub-object and indexed table apply. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj { Ptr32<Ptr32<void>> vtable; } S20Obj;
typedef Ptr32<int (Ptr32<S20Obj>, Ptr32<char>)> S20Call1;
extern unsigned short fn_80343740(Ptr32<S20V3>);
extern int fn_801a3190(Ptr32<char>, int, Ptr32<void>);

int w3d_s20_query_position_800e25dc(Ptr32<char> self, Ptr32<S20V3> out) {
    struct {
        S20V3 scratch[3];
        S20V3 position;
    } local;
    Ptr32<S20Obj> sub;
    int result;
    Ptr32<S20V3> scratch = local.scratch;
    Ptr32<S20V3> position = &local.position;
    fn_80343740(position);
    sub = *(Ptr32<Ptr32<S20Obj>>)(self + 300);
    if (sub == 0) {
        return 0x80004005;
    }
    result = ((S20Call1)sub->vtable[31])(sub, (Ptr32<char>)scratch);
    *out = *position;
    return result;
}

int w3d_s20_apply_indexed_801a3164(Ptr32<char> self, int index) {
    Ptr32<int> entry;
    entry = (Ptr32<int>)(*(Ptr32<Ptr32<char>>)(self + 48) + index * 4);
    return fn_801a3190(self, index, w3d::G(*entry));
}

}
