#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_h.c"
/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_801ad0e4(Ptr32<char>);
extern int fn_801ad168(Ptr32<char>, Ptr32<char>, int);
extern void fn_801ace68(Ptr32<char>, Ptr32<char>);
extern void fn_801ad060(Ptr32<char>);

int w3d_s20_commit_item_801ad590(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result;
    if (((Ptr32<int (Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[15])(base) & 1) {
        if (fn_801ad0e4(base) != 0)
            return fn_801ad168(base, item, 1);
        fn_801ace68(base, item);
        result = fn_801ad168(base, item, 0);
        fn_801ad060(base);
        return result;
    }
    return fn_801ad168(base, item, 0);
}

typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerH;
extern Ptr32<S20Object> lbl_804b1884;

int w3d_s20_apply_item_targets_8016bafc(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record;
    unsigned int count;
    unsigned int i;
    Ptr32<Ptr32<char>> targets;
    *(Ptr32<unsigned short>)(base + 196) = 0;
    *(Ptr32<int>)(base + 200) = 1;
    *(Ptr32<int>)(base + 204) = 1;
    record = *(Ptr32<Ptr32<char>>)(item + 84);
    count = *(Ptr32<unsigned int>)(record + 24);
    targets = (Ptr32<Ptr32<char>>)(record + 32);
    ((Ptr32<void (Ptr32<S20Object>, Ptr32<char>)>)lbl_804b1884->vtable[23])(lbl_804b1884, item + 20);
    for (i = 0; i < count; i++) {
        Ptr32<char> sub = base + 4;
        Ptr32<char> target = *targets;
        targets++;
        ((S20HandlerH)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    *(Ptr32<int>)(base + 200) = 0;
    *(Ptr32<int>)(base + 204) = 0;
    return 0;
}

}
