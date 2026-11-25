#include "w3d_ptr.h"
#line 1 "d16c_text_attach_800e2118.cpp"
// d16c: 0x800e2118 (160 bytes). Load the "NULL" resource into a text owner's
// handle, attach it to a target through the target's virtual slot +92, and
// mark the owner attached (+180 |= 16) and wide (|= 32) on request.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return; GCC 2.95 then loads the temporary string
// address last, as in the original.
struct d16c_Target;
struct d16c_TargetVtable {
    Ptr32<void> unknown00[23];
    Ptr32<void (Ptr32<d16c_Target>, Ptr32<void>, int)> attach;   // +92
};
struct d16c_Target { Ptr32<d16c_TargetVtable> vtable; };

// Shared engine string; constructor and release are out of line.
struct d16c_String_8020bb54 {
 d16c_String_8020bb54(const d16c_String_8020bb54 &);
    Ptr32<char> text;
    template <class W3dU> d16c_String_8020bb54(Ptr32<W3dU> w3d_p) : d16c_String_8020bb54((const char *)w3d_p.get()) {}
 d16c_String_8020bb54(const char *);
    ~d16c_String_8020bb54();
};
extern "C" void d16c_string_finish_8020c5c4(Ptr32<d16c_String_8020bb54>);
extern "C" void d16c_string_release_80341588(Ptr32<d16c_String_8020bb54>);
inline d16c_String_8020bb54::~d16c_String_8020bb54() {
    d16c_string_finish_8020c5c4(this);
    d16c_string_release_80341588(this);
}

extern const char d16c_null_text_80389efc[];   // "NULL"

struct d16c_TextOwner {
    unsigned char unknown000[180];
    unsigned int flags;                  // +180
    unsigned char unknown184[116];
    Ptr32<void> handle;                        // +300
};

extern "C" int d16c_handle_load_8015adf4(Ptr32<const d16c_String_8020bb54>, Ptr32<Ptr32<void>>, unsigned char);

extern "C" void d16c_text_attach_800e2118(Ptr32<d16c_TextOwner> self, Ptr32<d16c_Target> target, Ptr32<int> value, int wide) {
    {
        d16c_String_8020bb54 name(d16c_null_text_80389efc);
        d16c_handle_load_8015adf4(&name, &self->handle, 255);
    }
    target->vtable->attach(target, self->handle, *value);
    self->flags |= 16;
    if (wide) self->flags |= 32;
}


