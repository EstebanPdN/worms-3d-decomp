#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_q.c"
/* Guarded forwards, list iteration, reference replacement and struct copy. */
extern void fn_800e68f0(Ptr32<char>, int, Ptr32<void>);
extern int fn_800dc740(Ptr32<char>, int, Ptr32<void>, Ptr32<void>);

int w3d_s20_forward_if_enabled_800e6834(Ptr32<char> self, int a, int b, int c) {
    if (*(Ptr32<unsigned char>)(self + 104) != 0) {
        fn_800e68f0(self, a, w3d::G(c));
        return fn_800dc740(self, a, w3d::G(b), w3d::G(c));
    }
    return 0;
}

extern int fn_80161e38(Ptr32<char>, int);

int w3d_s20_apply_list_80161dd4(Ptr32<char> self, Ptr32<int> list) {
    int result = 0;
    if (*list != 0) {
        Ptr32<int> p = list;
        do {
            int status = fn_80161e38(self, *p);
            if (status < 0)
                result = status;
            p++;
        } while (*p != 0);
    }
    return result;
}

typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef struct S20Replacer { char pad[40]; Ptr32<S20Object> target; } S20Replacer;

void w3d_s20_replace_target_80174820(Ptr32<S20Replacer> self, Ptr32<S20Object> target) {
    if (target != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)target->vtable[3])(target);
    if (self->target != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)self->target->vtable[4])(self->target);
    self->target = target;
}

typedef struct S20Block28 { int words[7]; } S20Block28;
extern void fn_801a0b80(Ptr32<char>);

int w3d_s20_set_block_and_notify_801a0910(Ptr32<char> self, Ptr32<S20Block28> value) {
    *(Ptr32<S20Block28>)(self + 148) = *value;
    fn_801a0b80(self);
    return 0;
}

}
