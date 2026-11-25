#include "w3d_ptr.h"
#line 1 "s21_ff_801ed7bc.cpp"
// desc: Appears to convert a float to an integer and call a bound member-function pointer of the target object with it, returning the call's result.
typedef Ptr32<int (Ptr32<void>, int)> S21Function;
struct S21Method { short delta; short index; union { S21Function function; short vtable_offset; } u; };
struct S21Binding { char reserved[20]; S21Method set; };
extern "C" int w3d_s21_set_int_801ed7bc(Ptr32<S21Binding> binding, Ptr32<char> target, int unused, Ptr32<const float> value)
{
    S21Function function;
    if (binding->set.index >= 0)
        function = *(Ptr32<S21Function>)w3d::G((*(Ptr32<int>)(target + binding->set.u.vtable_offset) + binding->set.index * 4 - 4));
    else
        function = binding->set.u.function;
    return function(target + binding->set.delta, (int)*value);
}


