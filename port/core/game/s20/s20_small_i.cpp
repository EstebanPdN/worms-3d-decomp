#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_i.c"
/* Forwarding helpers, state swaps and handle checks. */
extern int fn_800e5da0(Ptr32<void>, Ptr32<void>, int, int, float);
extern Ptr32<void> lbl_804aaecc;

int w3d_s20_forward_global_800e5ca4(int a, int b, int c, float arg_f1) {
    if (lbl_804aaecc == 0)
        return 0;
    return fn_800e5da0(lbl_804aaecc, w3d::G(a), b, c, arg_f1);
}

extern int fn_800de16c(Ptr32<char>, Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern float fn_800ddfe4(Ptr32<char>, Ptr32<void>, Ptr32<void>);  /* A800ddfe4 (particles.cpp) devuelve un float, en s0 */

int w3d_s20_call_with_swapped_800e7114(Ptr32<char> self, Ptr32<void> arg_r4, Ptr32<void> arg_r5, Ptr32<void> arg_r6) {
    int first = *(Ptr32<int>)(self + 168);
    int second = *(Ptr32<int>)(self + 172);
    int saved_a = *(Ptr32<int>)(self + 100);
    int saved_b = *(Ptr32<int>)(self + 92);
    int result;
    *(Ptr32<int>)(self + 100) = first;
    *(Ptr32<int>)(self + 92) = second;
    result = fn_800de16c(self, arg_r4, arg_r5, arg_r6);
    *(Ptr32<int>)(self + 100) = saved_a;
    *(Ptr32<int>)(self + 92) = saved_b;
    return result;
}

float w3d_s20_call_with_swapped_800e7160(Ptr32<char> self, Ptr32<void> arg_r4, Ptr32<void> arg_r5) {
    int first = *(Ptr32<int>)(self + 168);
    int second = *(Ptr32<int>)(self + 172);
    int saved_a = *(Ptr32<int>)(self + 100);
    int saved_b = *(Ptr32<int>)(self + 92);
    float result;
    *(Ptr32<int>)(self + 100) = first;
    *(Ptr32<int>)(self + 92) = second;
    result = fn_800ddfe4(self, arg_r4, arg_r5);
    *(Ptr32<int>)(self + 100) = saved_a;
    *(Ptr32<int>)(self + 92) = saved_b;
    return result;
}

typedef struct S20HandleHolder152 { char pad[152]; int handle; } S20HandleHolder152;
extern Ptr32<void> fn_80164fc8(int);
extern void fn_800a4d3c(Ptr32<void>, Ptr32<char>);

void w3d_s20_forward_handle_8013dda8(Ptr32<S20HandleHolder152> self) {
    if (self->handle != -1) {
        Ptr32<void> object = fn_80164fc8(self->handle);
        if (object == 0)
            self->handle = -1;
        else
            fn_800a4d3c(object, (Ptr32<char>)self + 52);
    }
}

extern Ptr32<char> fn_801ecab4(Ptr32<char>, Ptr32<char>);
extern void fn_801e8d9c(Ptr32<char>);
extern char lbl_803ab810[];

int w3d_s20_reset_named_801bc430(Ptr32<char> self) {
    Ptr32<char> result = fn_801ecab4(self, lbl_803ab810);
    *(Ptr32<long long>)(result + 8) = 0;
    fn_801e8d9c(self);
    return 0;
}

}
