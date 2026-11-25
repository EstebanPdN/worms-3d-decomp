#include "w3d_ptr.h"
#line 1 "s21_fd_801ed5b8.cpp"
// desc: Appears to convert a float to a boolean (at least the global threshold) and call a bound member-function pointer of the target object with it, returning the call's result.
typedef Ptr32<int (Ptr32<void>, int)> S21Function;
struct S21Method { short delta; short index; union { S21Function function; short vtable_offset; } u; };
struct S21Binding { char reserved[20]; S21Method set; };
extern float lbl_803b0c84[];
extern "C" int w3d_s21_set_bool_801ed5b8(Ptr32<S21Binding> binding, Ptr32<char> target, int unused, Ptr32<const float> value)
{
    int flag = *value >= lbl_803b0c84[0];
    S21Function function;
    if (binding->set.index >= 0)
        function = *(Ptr32<S21Function>)w3d::G((*(Ptr32<int>)(target + binding->set.u.vtable_offset) + binding->set.index * 4 - 4));
    else
        function = binding->set.u.function;
    return function(target + binding->set.delta, flag);
}


