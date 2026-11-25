#include "w3d_ptr.h"
#line 1 "d24d_arguments_set_8015b330.cpp"
// d24d: 0x8015b330 (224 bytes). Store the program's argument texts: resize the
// argument object's string vector to the count, with a default string as the
// fill value (fill routine 0x80347570 when growing), then assign each text to
// its slot through 0x8020bd38. Called from the application entry 0x8015ad40
// with (count - 1, argv + 1). Returns 0.
#define D24D_FILL_INSERT d24d_fill_insert_80347570
template<class T> struct d24d_Vector;
struct d24d_String_803426b8;
extern "C" void D24D_FILL_INSERT(Ptr32<d24d_Vector < d24d_String_803426b8 >>, Ptr32<d24d_String_803426b8>, unsigned, const d24d_String_803426b8 &);
#include "d24d_string_vector.h"
typedef d24d_Vector<d24d_String_803426b8> d24d_StringVector;
struct d24d_Arguments {
    Ptr32<d24d_StringVector> strings;          // +0
};
extern "C" void d24d_string_assign_8020bd38(Ptr32<d24d_String_803426b8>, Ptr32<const char>);

extern "C" int d24d_arguments_set_8015b330(Ptr32<d24d_Arguments> self, int count, Ptr32<Ptr32<const char>> text) {
    Ptr32<d24d_StringVector> strings = self->strings;
    {
        d24d_String_803426b8 empty;
        strings->resize(count, empty);
    }
    for (int i = 0; i < count; i++) d24d_string_assign_8020bd38(strings->start + i, text[i]);
    return 0;
}


