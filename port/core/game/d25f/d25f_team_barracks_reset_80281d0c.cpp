#include "w3d_ptr.h"
#line 1 "d25f_team_barracks_reset_80281d0c.cpp"
// GWMP8P rev0 0x80281d0c. Looks up DATA.TeamBarracks, converts it with the
// tagged descriptor at 0x80178474 and clears the +64 word of every listed
// entry. The descriptor has two real words: the original writes tag 58280 at
// +4. String and handle classes here are one word. The early return is
// written as an if over a do-while(0): the loop-end note before the join
// stops CSE path following, which gives the fresh zero load and the reloads.
// Only the instruction effect supports that form, as a macro would; it is
// listed under caveats.
struct Object;
struct ObjectTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct D25fEntry { char pad[64]; int score; };
struct D25fList { char pad[24]; unsigned count; char pad28[4]; Ptr32<D25fEntry> entries[1]; };
struct Object { Ptr32<ObjectTable> vtable; char pad[20]; Ptr32<D25fList> list; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
};
struct Held {
    Ptr32<Object> value;
    Held() : value(0) {}
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Object *)w3d_p.get()) {}
 Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Held(const Held &);
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct PropertyKey { Ptr32<const char> name; template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) : name(n) {} };
extern "C" int w3d_resource_property_800fc1b0(const PropertyKey &, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<void> w3d_identity_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_as_team_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern char w3d_string_803ceaa0[];
extern "C" void d25f_team_barracks_reset_80281d0c() {
    Descriptor_80178474 descriptor;
    Ptr32<Descriptor_80178474> d = &descriptor;
    Handle handle;
    if (w3d_resource_property_800fc1b0(PropertyKey(w3d_string_803ceaa0), &handle.value) < 0) do { return; } while (0);
    Held team;
    {
        Held acquired(w3d_as_team_80179598(w3d_identity_80341584(handle.value), d));
        team.assign(acquired.value);
    }
    Ptr32<D25fList> list = team.value->list;
    unsigned count = list->count;
    Ptr32<Ptr32<D25fEntry>> entries = list->entries;
    for (unsigned i = 0; i < count; i++)
        entries[i]->score = 0;
}


