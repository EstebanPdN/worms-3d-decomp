#include "w3d_ptr.h"
#line 1 "s21_fg_801ec494.cpp"
// desc: Appears to read a float through the stream's virtual slot 18 and pass it to a bound member-function pointer on the target object, returning the read status.
typedef Ptr32<int (Ptr32<void>, float)> S21Setter;
struct S21Method { short delta; short index; union { S21Setter function; short vtable_offset; } u; };
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[18]; Ptr32<int (Ptr32<S21Stream>, Ptr32<float>, int, int)> read; };
struct S21Stream { Ptr32<S21StreamMethods> methods; };
struct S21Owner { char pad[8]; Ptr32<S21Stream> stream; };
struct S21Binding { Ptr32<S21Owner> owner; char reserved[16]; S21Method set; };
extern "C" int w3d_s21_read_set_float_801ec494(Ptr32<S21Binding> binding, int position, Ptr32<char> target)
{
    float value;
    S21Setter function;
    int status = binding->owner->stream->methods->read(binding->owner->stream, &value, position, 0);
    if (status >= 0) {
        if (binding->set.index >= 0)
            function = *(Ptr32<S21Setter>)w3d::G((*(Ptr32<int>)(target + binding->set.u.vtable_offset) + binding->set.index * 4 - 4));
        else
            function = binding->set.u.function;
        function(target + binding->set.delta, value);
    }
    return status;
}


