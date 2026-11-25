// UNPROVED: 504 native bytes, with eight differing instruction words.
// This source is excluded from exact coverage and has no admission manifest.
// Observed GC32 boundaries: owner slot pointer +24 and remaining count +2092;
// 16-bit lookup index, 20-byte allocation, retain/release slots +12/+16.
// The lookup writes the index on the observed paths; valid index/owner storage
// and live virtual objects are required. Callback meanings and complete object
// identities remain inferred. Explicit vtable views are reference-ABI evidence,
// not a portable class model. No runtime or hardware verification is claimed.
// GC32 reconstruction from original accesses. Class and field names inferred.
struct Owner;
struct Name;
typedef void (*VirtualSlot)();
struct Property { VirtualSlot *vtable; };
extern "C" int sol35f4a_lookup_80177eb0(Owner *, const Name *, unsigned short *);
extern "C" void *sol35f4a_allocate_801fe1d8(unsigned);
extern "C" Property *sol35f4a_construct_80178bc4(void *);
extern "C" Property *sol35f4a_cast_803426b4(Property *);
extern "C" int sol35f4a_update_80178c54(Property *, const unsigned *);
extern unsigned sol35f4a_created_804ab5b0;

inline Property **slots(Owner *owner)
{
    return *reinterpret_cast<Property ***>(reinterpret_cast<char *>(owner) + 24);
}
inline Property *at(Owner *owner, unsigned short index)
{
    return slots(owner)[index];
}
inline int query(Property *p, unsigned slot)
{
    return reinterpret_cast<int (*)(Property *)>(p->vtable[slot])(p);
}
inline void command(Property *p, unsigned slot, unsigned value)
{
    reinterpret_cast<void (*)(Property *, unsigned)>(p->vtable[slot])(p, value);
}
inline void replace(Property *&slot, Property *fresh)
{
    if (fresh)
        reinterpret_cast<void (*)(Property *)>(fresh->vtable[3])(fresh);
    if (slot)
        reinterpret_cast<void (*)(Property *)>(slot->vtable[4])(slot);
    slot = fresh;
}
extern "C" int sol35f4a_property_8034bf50(Owner *self, const Name *name,
                                        unsigned value, unsigned mode, unsigned flags)
{
    unsigned short index;
    if (sol35f4a_lookup_80177eb0(self, name, &index) >= 0) {
        if (flags & 1) {
            Property *action;
            int (*callback)(Property *);
            if (!query(at(self, index), 6)) {
                if (flags & 4)
                    mode = query(at(self, index), 9);
                if (query(at(self, index), 9) != mode) {
                    action = at(self, index);
                    callback = reinterpret_cast<int (*)(Property *)>(action->vtable[9]);
                } else {
                    return sol35f4a_update_80178c54(sol35f4a_cast_803426b4(at(self, index)), &value);
                }
            } else {
                action = at(self, index);
                callback = reinterpret_cast<int (*)(Property *)>(action->vtable[7]);
            }
            callback(action);
        }
        return int(0x80004005u);
    }
    Property *fresh = sol35f4a_construct_80178bc4(sol35f4a_allocate_801fe1d8(20));
    replace(slots(self)[index], fresh);
    sol35f4a_update_80178c54(fresh, &value);
    reinterpret_cast<void (*)(Property *, const Name *)>(fresh->vtable[11])(fresh, name);
    command(fresh, 12, mode);
    command(fresh, 13, flags & ~1u);
    unsigned &remaining = *reinterpret_cast<unsigned *>(reinterpret_cast<char *>(self) + 2092);
    unsigned old_remaining = remaining;
    unsigned old_created = sol35f4a_created_804ab5b0;
    remaining = old_remaining - 1;
    sol35f4a_created_804ab5b0 = old_created + 1;
    return 0;
}
