#include "w3d_ptr.h"
#line 1 "s21_ff_801ed2c0.cpp"
// desc: Appears to compare the strings obtained from two objects through a bound member-function pointer and report whether they are equal.
typedef Ptr32<Ptr32<Ptr32<char>> (Ptr32<void>)> S21Getter;
struct S21Method { short delta; short index; union { S21Getter function; short vtable_offset; } u; };
struct S21Binding { char reserved[12]; S21Method get; };
extern int fn_802ef234(Ptr32<const char>, Ptr32<const char>);
extern "C" int w3d_s21_equal_strings_801ed2c0(Ptr32<S21Binding> binding, Ptr32<char> first, Ptr32<char> second)
{
    S21Getter function;
    Ptr32<Ptr32<char>> a;
    Ptr32<Ptr32<char>> b;
    if (binding->get.index >= 0)
        function = *(Ptr32<S21Getter>)w3d::G((*(Ptr32<int>)(first + binding->get.u.vtable_offset) + binding->get.index * 4 - 4));
    else
        function = binding->get.u.function;
    a = function(first + binding->get.delta);
    if (binding->get.index >= 0)
        function = *(Ptr32<S21Getter>)w3d::G((*(Ptr32<int>)(second + binding->get.u.vtable_offset) + binding->get.index * 4 - 4));
    else
        function = binding->get.u.function;
    b = function(second + binding->get.delta);
    return fn_802ef234(*a, *b) == 0;
}


