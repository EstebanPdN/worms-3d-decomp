#include "w3d_ptr.h"
#line 1 "s21_fe_801ed3f8.cpp"
// desc: Appears to read a value through a bound member-function pointer on the target and write it to a stream through virtual slot 8 together with the binding's first word.
typedef Ptr32<int (Ptr32<void>)> S21Getter;
struct S21Method { short delta; short index; union { S21Getter function; short vtable_offset; } u; };
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[8]; Ptr32<int (Ptr32<S21Stream>, int, int)> write; };
struct S21Stream { Ptr32<S21StreamMethods> methods; };
struct S21Binding { Ptr32<int> key; char reserved[8]; S21Method get; };
extern "C" int w3d_s21_write_value_801ed3f8(Ptr32<S21Binding> binding, Ptr32<S21Stream> stream, Ptr32<char> target)
{
    Ptr32<S21StreamMethods> methods = stream->methods;
    S21Getter function;
    int value;
    if (binding->get.index >= 0)
        function = *(Ptr32<S21Getter>)w3d::G((*(Ptr32<int>)(target + binding->get.u.vtable_offset) + binding->get.index * 4 - 4));
    else
        function = binding->get.u.function;
    value = function(target + binding->get.delta);
    return methods->write(stream, value, *binding->key);
}


