// Typed property setters: one function per property value kind.
// GC32 reconstruction from the original instructions; class and field names
// are inferred. Each setter looks up a named property slot on an owner. When
// the slot exists and flag bit 0 is set, it checks the slot kind and mode
// (bit 2 adopts the slot's current mode) and stores the value through the
// kind's update helper; otherwise it returns E_FAIL (0x80004005). When the
// slot does not exist, it allocates and constructs a 20-byte property of the
// kind, retains it into the slot (releasing the previous one), stores the
// value, name, mode and remaining flags, decrements the owner's free count
// and increments a global creation counter.
//
// The virtual slots are reference-ABI observations: 4-byte vtable entries
// after an 8-byte header (offsets 12/16 retain/release, 24 kind, 28 the
// wrong-kind notification, 36 mode, 44/48/52 name/mode/flags setters), which
// is why this unit is built with -fvtable-thunks. Each failure branch returns
// E_FAIL itself; the compiler's jump pass merges those identical tails.
// The class view is partial: no vtable or member is defined here.

struct D15fName;
struct D15fVector3 { float x, y, z; };
struct D15fInterface;

struct D15fProperty {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual void slot_20();
    virtual int kind();
    virtual int wrong_kind();
    virtual void slot_32();
    virtual int mode();
    virtual void slot_40();
    virtual void set_name(const D15fName *name);
    virtual void set_mode(int mode);
    virtual void set_flags(unsigned flags);
};

// Observed owner layout: slot array at +24, free-slot count at +2092.
struct D15fPropertyOwner {
    char pad_00[24];
    D15fProperty **slots;
    char pad_1c[2064];
    int free_count;
};

extern "C" int d15f_lookup_80177eb0(D15fPropertyOwner *owner, const D15fName *name, unsigned short *index);
extern "C" void *d15f_allocate_801fe1d8(unsigned size);
extern unsigned d15f_created_count_804ab5b0;

extern "C" D15fProperty *d15f_construct_kind0_80178bc4(void *memory);
extern "C" D15fProperty *d15f_view_kind0_803426b4(D15fProperty *property);
extern "C" int d15f_update_kind0_80178c54(D15fProperty *property, const unsigned *value);
extern "C" D15fProperty *d15f_construct_kind1_80178c98(void *memory);
extern "C" D15fProperty *d15f_view_kind1_80342a78(D15fProperty *property);
extern "C" int d15f_update_kind1_80178d28(D15fProperty *property, const int *value);
extern "C" D15fProperty *d15f_construct_kind2_80178d6c(void *memory);
extern "C" D15fProperty *d15f_view_kind2_80342a74(D15fProperty *property);
extern "C" int d15f_update_kind2_80178dfc(D15fProperty *property, const float *value);
extern "C" D15fProperty *d15f_construct_kind3_80178e40(void *memory);
extern "C" D15fProperty *d15f_view_kind3_80342fa4(D15fProperty *property);
extern "C" int d15f_update_kind3_80178fa4(D15fProperty *property, const D15fVector3 *value);
extern "C" D15fProperty *d15f_construct_kind6_8017917c(void *memory);
extern "C" D15fProperty *d15f_view_kind6_80343858(D15fProperty *property);
extern "C" int d15f_update_kind6_801792a4(D15fProperty *property, D15fInterface * const *value);
extern "C" D15fProperty *d15f_construct_kind7_80178ed0(void *memory);
extern "C" D15fProperty *d15f_view_kind7_80343df4(D15fProperty *property);
extern "C" int d15f_update_kind7_80178f60(D15fProperty *property, const unsigned *value);

// Kind 0 setter (original 0x8034bf50).
extern "C" int d15f_property_set_kind0_8034bf50(D15fPropertyOwner *owner, const D15fName *name,
                                           unsigned value, int mode, unsigned flags)
{
    unsigned short index;
    if (d15f_lookup_80177eb0(owner, name, &index) >= 0) {
        if (flags & 1) {
            if (owner->slots[index]->kind() == 0) {
                if (flags & 4)
                    mode = owner->slots[index]->mode();
                if (owner->slots[index]->mode() != mode) {
                    owner->slots[index]->mode();
                    return (int)0x80004005;
                }
                return d15f_update_kind0_80178c54(d15f_view_kind0_803426b4(owner->slots[index]), &value);
            } else {
                owner->slots[index]->wrong_kind();
                return (int)0x80004005;
            }
        }
        return (int)0x80004005;
    }
    D15fProperty *created = d15f_construct_kind0_80178bc4(d15f_allocate_801fe1d8(20));
    D15fProperty **slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    D15fProperty *old = *(D15fProperty **)(offset + (int)slots);
    if (old)
        old->release();
    *(D15fProperty **)(offset + (int)slots) = created;
    d15f_update_kind0_80178c54(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 1 setter (original 0x8034c148).
extern "C" int d15f_property_set_kind1_8034c148(D15fPropertyOwner *owner, const D15fName *name,
                                           int value, int mode, unsigned flags)
{
    unsigned short index;
    if (d15f_lookup_80177eb0(owner, name, &index) >= 0) {
        if (flags & 1) {
            if (owner->slots[index]->kind() == 1) {
                if (flags & 4)
                    mode = owner->slots[index]->mode();
                if (owner->slots[index]->mode() != mode) {
                    owner->slots[index]->mode();
                    return (int)0x80004005;
                }
                return d15f_update_kind1_80178d28(d15f_view_kind1_80342a78(owner->slots[index]), &value);
            } else {
                owner->slots[index]->wrong_kind();
                return (int)0x80004005;
            }
        }
        return (int)0x80004005;
    }
    D15fProperty *created = d15f_construct_kind1_80178c98(d15f_allocate_801fe1d8(20));
    D15fProperty **slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    D15fProperty *old = *(D15fProperty **)(offset + (int)slots);
    if (old)
        old->release();
    *(D15fProperty **)(offset + (int)slots) = created;
    d15f_update_kind1_80178d28(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 2 setter (original 0x8034c340).
extern "C" int d15f_property_set_kind2_8034c340(D15fPropertyOwner *owner, const D15fName *name,
                                           float value, int mode, unsigned flags)
{
    unsigned short index;
    if (d15f_lookup_80177eb0(owner, name, &index) >= 0) {
        if (flags & 1) {
            if (owner->slots[index]->kind() == 2) {
                if (flags & 4)
                    mode = owner->slots[index]->mode();
                if (owner->slots[index]->mode() != mode) {
                    owner->slots[index]->mode();
                    return (int)0x80004005;
                }
                return d15f_update_kind2_80178dfc(d15f_view_kind2_80342a74(owner->slots[index]), &value);
            } else {
                owner->slots[index]->wrong_kind();
                return (int)0x80004005;
            }
        }
        return (int)0x80004005;
    }
    D15fProperty *created = d15f_construct_kind2_80178d6c(d15f_allocate_801fe1d8(20));
    D15fProperty **slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    D15fProperty *old = *(D15fProperty **)(offset + (int)slots);
    if (old)
        old->release();
    *(D15fProperty **)(offset + (int)slots) = created;
    d15f_update_kind2_80178dfc(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 3 setter (original 0x8034c538).
extern "C" int d15f_property_set_kind3_8034c538(D15fPropertyOwner *owner, const D15fName *name,
                                           const D15fVector3 *value, int mode, unsigned flags)
{
    unsigned short index;
    if (d15f_lookup_80177eb0(owner, name, &index) >= 0) {
        if (flags & 1) {
            if (owner->slots[index]->kind() == 3) {
                if (flags & 4)
                    mode = owner->slots[index]->mode();
                if (owner->slots[index]->mode() != mode) {
                    owner->slots[index]->mode();
                    return (int)0x80004005;
                }
                return d15f_update_kind3_80178fa4(d15f_view_kind3_80342fa4(owner->slots[index]), value);
            } else {
                owner->slots[index]->wrong_kind();
                return (int)0x80004005;
            }
        }
        return (int)0x80004005;
    }
    D15fProperty *created = d15f_construct_kind3_80178e40(d15f_allocate_801fe1d8(20));
    D15fProperty **slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    D15fProperty *old = *(D15fProperty **)(offset + (int)slots);
    if (old)
        old->release();
    *(D15fProperty **)(offset + (int)slots) = created;
    d15f_update_kind3_80178fa4(created, value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 6 setter (original 0x8034c730).
extern "C" int d15f_property_set_kind6_8034c730(D15fPropertyOwner *owner, const D15fName *name,
                                           D15fInterface *value, int mode, unsigned flags)
{
    unsigned short index;
    if (d15f_lookup_80177eb0(owner, name, &index) >= 0) {
        if (flags & 1) {
            if (owner->slots[index]->kind() == 6) {
                if (flags & 4)
                    mode = owner->slots[index]->mode();
                if (owner->slots[index]->mode() != mode) {
                    owner->slots[index]->mode();
                    return (int)0x80004005;
                }
                return d15f_update_kind6_801792a4(d15f_view_kind6_80343858(owner->slots[index]), &value);
            } else {
                owner->slots[index]->wrong_kind();
                return (int)0x80004005;
            }
        }
        return (int)0x80004005;
    }
    D15fProperty *created = d15f_construct_kind6_8017917c(d15f_allocate_801fe1d8(20));
    D15fProperty **slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    D15fProperty *old = *(D15fProperty **)(offset + (int)slots);
    if (old)
        old->release();
    *(D15fProperty **)(offset + (int)slots) = created;
    d15f_update_kind6_801792a4(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 7 setter (original 0x8034c928).
extern "C" int d15f_property_set_kind7_8034c928(D15fPropertyOwner *owner, const D15fName *name,
                                           const unsigned *value, int mode, unsigned flags)
{
    unsigned short index;
    if (d15f_lookup_80177eb0(owner, name, &index) >= 0) {
        if (flags & 1) {
            if (owner->slots[index]->kind() == 7) {
                if (flags & 4)
                    mode = owner->slots[index]->mode();
                if (owner->slots[index]->mode() != mode) {
                    owner->slots[index]->mode();
                    return (int)0x80004005;
                }
                return d15f_update_kind7_80178f60(d15f_view_kind7_80343df4(owner->slots[index]), value);
            } else {
                owner->slots[index]->wrong_kind();
                return (int)0x80004005;
            }
        }
        return (int)0x80004005;
    }
    D15fProperty *created = d15f_construct_kind7_80178ed0(d15f_allocate_801fe1d8(20));
    D15fProperty **slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    D15fProperty *old = *(D15fProperty **)(offset + (int)slots);
    if (old)
        old->release();
    *(D15fProperty **)(offset + (int)slots) = created;
    d15f_update_kind7_80178f60(created, value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}
