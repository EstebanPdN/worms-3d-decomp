#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b28_pick_800edd90.c"
/* Assigns a default text to the owner's string field, then replaces it with a
   shared string chosen from the scene's table by index (a value from the
   owner modulo the table count), adjusting the reference counts. Offsets are
   observed; field names and meanings are inferred. */
typedef struct { char p0[24]; unsigned int count; char p1[4]; } Table;
typedef struct { char p0[192]; Ptr32<void> ctx; char p1[108]; Ptr32<char> text; } Owner;
extern Ptr32<void> fn_80341584(Ptr32<void>);
extern Ptr32<char> fn_801797b4(Ptr32<void>);
extern void fn_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
extern void fn_8020bb2c(Ptr32<void>);
extern unsigned int fn_80161080(Ptr32<void>);
extern char lbl_8038b568[];
void tsonnet_b28_pick_800edd90(Ptr32<Owner> o) {
    Ptr32<Table> t = *(Ptr32<Ptr32<Table>>)(fn_801797b4(fn_80341584(o->ctx)) + 232);
    unsigned int n = t->count;
    Ptr32<Ptr32<char>> items = (Ptr32<Ptr32<char>>)((Ptr32<char>)t + 32);
    fn_8020bd38(&o->text, lbl_8038b568);
    if (n != 0) {
        unsigned int i = fn_80161080(o) % n;
        Ptr32<char> s = items[i];
        (*(Ptr32<unsigned short>)(s - 6))++;
        { Ptr32<unsigned short> h = (Ptr32<unsigned short>)(o->text - 6); if (--*h == 0) fn_8020bb2c(h); }
        o->text = items[i];
    }
}

}
