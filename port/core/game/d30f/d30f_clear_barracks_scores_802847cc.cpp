#include "w3d_ptr.h"
#line 1 "d30f_clear_barracks_scores_802847cc.cpp"
// GWMP8P rev0 0x802847cc. Looks up DATA.TeamBarracks, converts it with the
// tagged descriptor at 0x80178474 and clears the word at +64 of every listed
// entry. The early return is an if over a do-while(0): the loop-end note
// before the join stops CSE path following (d28f). The count is read
// directly through the embedded list holder and the items through its inline
// member, so CSE keeps a second load that the post-reload pass turns into a
// register copy.
struct Object;
struct ObjectTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct D25fEntry { char pad[64]; int score; };
struct D25fList { char pad[24]; unsigned count; char pad28[4]; Ptr32<D25fEntry> entries[1]; };
struct D25fSub { int a; Ptr32<D25fList> list; Ptr32<Ptr32<D25fEntry>> Entries() { return list->entries; } };
struct Object { Ptr32<ObjectTable> vtable; char pad[16]; D25fSub sub; };
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
struct LR { Ptr32<D25fList> l; Ptr32<Ptr32<D25fEntry>> E() const { return l->entries; } unsigned N() const { return l->count; } };
struct Items { Ptr32<Ptr32<D25fEntry>> p; Ptr32<Ptr32<D25fEntry>> Get() const { return p; } };
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
extern "C" void d30f_clear_barracks_scores_802847cc() {
    Descriptor_80178474 descriptor;
    Ptr32<Descriptor_80178474> d = &descriptor;
    Handle handle;
    if (w3d_resource_property_800fc1b0(PropertyKey(w3d_string_803ceaa0), &handle.value) < 0) do { return; } while (0);
    Held team;
    {
        Held acquired(w3d_as_team_80179598(w3d_identity_80341584(handle.value), d));
        team.assign(acquired.value);
    }
    unsigned i = 0;
    unsigned count = team.value->sub.list->count;
    Ptr32<Ptr32<D25fEntry>> items = team.value->sub.Entries();
    for (; i < count; i++)
        items[i]->score = 0;
}


