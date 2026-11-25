#include "w3d_ptr.h"
#line 1 "d41i_load_resource_folders_80128f6c.cpp"
// d41i: 0x80128f6c. Load the resource folders of the game through the
// virtual +20. Flag bit 0x20000000 of +188 first loads Bundles; when that
// flag is still set without 0x10000000, the rest are skipped. Otherwise it
// loads Objects, Temp, HUD, Frontend/Mechanics and Frontend/Icons in order.
// The virtual returns int: the table at 0x80410c48 has 0x8015c154 at +20,
// which ends in li r3,0.
struct d24i_String {
    Ptr32<char> text;
    d24i_String(const d24i_String &);
    template <class W3dU> d24i_String(Ptr32<W3dU> w3d_p) : d24i_String((const char *)w3d_p.get()) {}
 d24i_String(const char *);
    ~d24i_String();
};
extern "C" void d24i_string_finish_8020c5c4(Ptr32<d24i_String>);
extern "C" void d24i_string_release_80341588(Ptr32<d24i_String>);
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
struct d24i_Actor;
struct d24i_ActorVtable {
    Ptr32<void> unknown00[5];
    Ptr32<int (Ptr32<d24i_Actor>, const d24i_String &)> load;   // +20
};
struct d24i_Actor {
    Ptr32<d24i_ActorVtable> vtable;
    unsigned char unknown04[184];
    unsigned flags;                      // +188
};
extern const char d24i_name_8039c85c[], d24i_name_8039c864[], d24i_name_8039c86c[], d24i_name_8039c874[], d24i_name_8039c878[], d24i_name_8039c88c[];

extern "C" void d41i_load_resource_folders_80128f6c(Ptr32<d24i_Actor> self) {
    if (self->flags & 0x20000000) {
        {
        Ptr32<d24i_ActorVtable> table = self->vtable;
        d24i_String name(d24i_name_8039c85c);
        table->load(self, name);
    }
        unsigned flags = self->flags;
        if (flags & 0x20000000) {
            if (!(flags & 0x10000000))
                return;
        }
    }
    {
        Ptr32<d24i_ActorVtable> table = self->vtable;
        d24i_String name(d24i_name_8039c864);
        table->load(self, name);
    }
    {
        Ptr32<d24i_ActorVtable> table = self->vtable;
        d24i_String name(d24i_name_8039c86c);
        table->load(self, name);
    }
    {
        Ptr32<d24i_ActorVtable> table = self->vtable;
        d24i_String name(d24i_name_8039c874);
        table->load(self, name);
    }
    {
        Ptr32<d24i_ActorVtable> table = self->vtable;
        d24i_String name(d24i_name_8039c878);
        table->load(self, name);
    }
    {
        Ptr32<d24i_ActorVtable> table = self->vtable;
        d24i_String name(d24i_name_8039c88c);
        table->load(self, name);
    }
}


