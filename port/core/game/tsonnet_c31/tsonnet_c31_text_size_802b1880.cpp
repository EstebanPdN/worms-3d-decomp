#include "w3d_ptr.h"
#line 1 "tsonnet_c31_text_size_802b1880.cpp"
/* Cached text-size property of a text box. The owner caches the size at offset 172;
   a zero cache is refilled from the source object at offset 12 and, if still zero,
   from a named property lookup (string 0x803d7a54). Offsets are observed; names
   and meanings are inferred. Reference-compiler observation: the local lookup
   record needs 24 bytes of stack to reproduce the original frame. */
extern "C" {
struct Iface { Ptr32<Ptr32<void (Ptr32<Iface>)>> vtable; int unknown04[3]; int value; };
struct Ref { Ptr32<Iface> object; int reserved; };
struct Src { char unknown00[64]; float size; };
struct Owner { char p0[12]; Ptr32<Src> source; char p1[156]; float size; };
extern const char w3d_str_803d7a54[];
extern const float w3d_f32_803d7a68[];
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<Ref>);
Ptr32<Iface> w3d_empty_80342a74(Ptr32<Iface>);
float w3d_auto_80178df0(Ptr32<Iface>);
float tsonnet_c31_text_size_802b1880(Ptr32<Owner> self)
{
    float v = self->size;
    if (v == w3d_f32_803d7a68[0]) {
        v = self->source->size;
        self->size = v;
        if (v == w3d_f32_803d7a68[0]) {
            struct { Ref ref; Ptr32<const char> name; int reserved[2]; } local;
            float t;
            local.ref.object = 0;
            local.name = w3d_str_803d7a54;
            w3d_constructor_lookup_name(&local.name, &local.ref);
            t = w3d_auto_80178df0(w3d_empty_80342a74(local.ref.object));
            self->size = t;
            if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
            return t;
        }
    }
    return v;
}
}


