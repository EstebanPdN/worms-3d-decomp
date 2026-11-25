#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_s.c"
/* Per-kind handler dispatch, block copy, referenced constructor and a warning wrapper. */
typedef struct S20KindSource { char pad[32]; unsigned int word; } S20KindSource;
extern Ptr32<S20KindSource> lbl_80363938[];
extern void fn_801a4278(Ptr32<char>);

int w3d_s20_dispatch_kind_801a42fc(Ptr32<char> self, Ptr32<char> item) {
    if (*(Ptr32<unsigned char>)(item + 8) & 2)
        fn_801a4278(item);
    return ((Ptr32<int (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[(lbl_80363938[0]->word >> 22) & 1023])(self, item);
}

typedef struct S20Block24 { int words[6]; } S20Block24;
extern Ptr32<void> fn_801f55ec(Ptr32<char>, Ptr32<char>);

int w3d_s20_set_block_and_forward_801a5650(Ptr32<char> self, Ptr32<S20Block24> value) {
    *(Ptr32<S20Block24>)(self + 60) = *value;
    fn_801f55ec(self + 44, self + 60);
    return 0;
}

typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_801c90c0(Ptr32<char>, Ptr32<void>);
extern Ptr32<S20Object> lbl_804b05ac;
extern char lbl_80416348[];

Ptr32<char> w3d_s20_construct_with_global_801c98b8(Ptr32<char> self, Ptr32<void> arg_r4) {
    Ptr32<S20Object> global;
    fn_801c90c0(self, arg_r4);
    global = lbl_804b05ac;
    *(Ptr32<Ptr32<char>>)self = lbl_80416348;
    *(Ptr32<Ptr32<S20Object>>)(self + 28) = global;
    if (global != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)global->vtable[3])(global);
    *(Ptr32<int>)(self + 32) = 0;
    *(Ptr32<int>)(self + 36) = 0;
    return self;
}

extern void fn_801d6000(Ptr32<char>, Ptr32<char>, ...);
extern int fn_801d6644(Ptr32<char>, Ptr32<char>);
extern char lbl_803af55c[];

int w3d_s20_warn_if_empty_801d66d8(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(item + 60) + 24) == 0)
        fn_801d6000(base, lbl_803af55c, w3d::VA(item));
    return fn_801d6644(self, item);
}

}
