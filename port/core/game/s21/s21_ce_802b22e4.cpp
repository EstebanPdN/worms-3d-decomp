#include "w3d_ptr.h"
#line 1 "s21_ce_802b22e4.cpp"
// desc: Appears to return by value a three-float vector obtained from a virtual slot of the linked object.
struct S21Vec3 {
    float x, y, z;
    S21Vec3(const S21Vec3 &other) { float a = other.x, b = other.y, c = other.z; x = a; y = b; z = c; }
};
struct S21Source;
struct S21SourceMethods { Ptr32<void (void)> reserved[25]; Ptr32<Ptr32<S21Vec3> (Ptr32<S21Source>)> position; };
struct S21Source { Ptr32<S21SourceMethods> methods; };
struct S21Object { char pad[88]; Ptr32<S21Source> source; };
extern "C" S21Vec3 w3d_s21_get_position_802b22e4(Ptr32<S21Object> self)
{
    return *self->source->methods->position(self->source);
}


