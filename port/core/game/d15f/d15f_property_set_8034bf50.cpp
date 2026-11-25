#include "w3d_ptr.h"
#line 1 "d15f_property_set_8034bf50.cpp"
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
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN12D15fProperty15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN12D15fProperty6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN12D15fProperty7releaseEv"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN12D15fProperty7slot_20Ev"));
    int w3d_r_kind() __asm__(W3D_SYM("_ZN12D15fProperty4kindEv"));
    int w3d_r_wrong_kind() __asm__(W3D_SYM("_ZN12D15fProperty10wrong_kindEv"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN12D15fProperty7slot_32Ev"));
    int w3d_r_mode() __asm__(W3D_SYM("_ZN12D15fProperty4modeEv"));
    void w3d_r_slot_40() __asm__(W3D_SYM("_ZN12D15fProperty7slot_40Ev"));
    void w3d_r_set_name(Ptr32<const D15fName> name) __asm__(W3D_SYM("_ZN12D15fProperty8set_nameEPK8D15fName"));
    void w3d_r_set_mode(int mode) __asm__(W3D_SYM("_ZN12D15fProperty8set_modeEi"));
    void w3d_r_set_flags(unsigned flags) __asm__(W3D_SYM("_ZN12D15fProperty9set_flagsEj"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int kind() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int wrong_kind() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int mode() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fProperty, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set_name(Ptr32<const D15fName> w3d_a0) { ((void (*)(w3d_u32, Ptr32<const D15fName>))w3d::vfn(this->w3d_vptr_D15fProperty, 11))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void set_mode(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_D15fProperty, 12))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void set_flags(unsigned int w3d_a0) { ((void (*)(w3d_u32, unsigned int))w3d::vfn(this->w3d_vptr_D15fProperty, 13))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D15fProperty; };

// Observed owner layout: slot array at +24, free-slot count at +2092.
struct D15fPropertyOwner {
    char pad_00[24];
    Ptr32<Ptr32<D15fProperty>> slots;
    char pad_1c[2064];
    int free_count;
};

extern "C" int d15f_lookup_80177eb0(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name, Ptr32<unsigned short> index);
extern "C" Ptr32<void> d15f_allocate_801fe1d8(unsigned size);
extern unsigned d15f_created_count_804ab5b0;

extern "C" Ptr32<D15fProperty> d15f_construct_kind0_80178bc4(Ptr32<void> memory);
extern "C" Ptr32<D15fProperty> d15f_view_kind0_803426b4(Ptr32<D15fProperty> property);
extern "C" int d15f_update_kind0_80178c54(Ptr32<D15fProperty> property, Ptr32<const unsigned int> value);
extern "C" Ptr32<D15fProperty> d15f_construct_kind1_80178c98(Ptr32<void> memory);
extern "C" Ptr32<D15fProperty> d15f_view_kind1_80342a78(Ptr32<D15fProperty> property);
extern "C" int d15f_update_kind1_80178d28(Ptr32<D15fProperty> property, Ptr32<const int> value);
extern "C" Ptr32<D15fProperty> d15f_construct_kind2_80178d6c(Ptr32<void> memory);
extern "C" Ptr32<D15fProperty> d15f_view_kind2_80342a74(Ptr32<D15fProperty> property);
extern "C" int d15f_update_kind2_80178dfc(Ptr32<D15fProperty> property, Ptr32<const float> value);
extern "C" Ptr32<D15fProperty> d15f_construct_kind3_80178e40(Ptr32<void> memory);
extern "C" Ptr32<D15fProperty> d15f_view_kind3_80342fa4(Ptr32<D15fProperty> property);
extern "C" int d15f_update_kind3_80178fa4(Ptr32<D15fProperty> property, Ptr32<const D15fVector3> value);
extern "C" Ptr32<D15fProperty> d15f_construct_kind6_8017917c(Ptr32<void> memory);
extern "C" Ptr32<D15fProperty> d15f_view_kind6_80343858(Ptr32<D15fProperty> property);
extern "C" int d15f_update_kind6_801792a4(Ptr32<D15fProperty> property, Ptr32<Ptr32<D15fInterface> const> value);
extern "C" Ptr32<D15fProperty> d15f_construct_kind7_80178ed0(Ptr32<void> memory);
extern "C" Ptr32<D15fProperty> d15f_view_kind7_80343df4(Ptr32<D15fProperty> property);
extern "C" int d15f_update_kind7_80178f60(Ptr32<D15fProperty> property, Ptr32<const unsigned int> value);

// Kind 0 setter (original 0x8034bf50).
extern "C" int d15f_property_set_kind0_8034bf50(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name,
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
    Ptr32<D15fProperty> created = d15f_construct_kind0_80178bc4(d15f_allocate_801fe1d8(20));
    Ptr32<Ptr32<D15fProperty>> slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<D15fProperty> old = *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    d15f_update_kind0_80178c54(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 1 setter (original 0x8034c148).
extern "C" int d15f_property_set_kind1_8034c148(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name,
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
    Ptr32<D15fProperty> created = d15f_construct_kind1_80178c98(d15f_allocate_801fe1d8(20));
    Ptr32<Ptr32<D15fProperty>> slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<D15fProperty> old = *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    d15f_update_kind1_80178d28(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 2 setter (original 0x8034c340).
extern "C" int d15f_property_set_kind2_8034c340(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name,
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
    Ptr32<D15fProperty> created = d15f_construct_kind2_80178d6c(d15f_allocate_801fe1d8(20));
    Ptr32<Ptr32<D15fProperty>> slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<D15fProperty> old = *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    d15f_update_kind2_80178dfc(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 3 setter (original 0x8034c538).
extern "C" int d15f_property_set_kind3_8034c538(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name,
                                           Ptr32<const D15fVector3> value, int mode, unsigned flags)
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
    Ptr32<D15fProperty> created = d15f_construct_kind3_80178e40(d15f_allocate_801fe1d8(20));
    Ptr32<Ptr32<D15fProperty>> slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<D15fProperty> old = *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    d15f_update_kind3_80178fa4(created, value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 6 setter (original 0x8034c730).
extern "C" int d15f_property_set_kind6_8034c730(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name,
                                           Ptr32<D15fInterface> value, int mode, unsigned flags)
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
    Ptr32<D15fProperty> created = d15f_construct_kind6_8017917c(d15f_allocate_801fe1d8(20));
    Ptr32<Ptr32<D15fProperty>> slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<D15fProperty> old = *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    d15f_update_kind6_801792a4(created, &value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}

// Kind 7 setter (original 0x8034c928).
extern "C" int d15f_property_set_kind7_8034c928(Ptr32<D15fPropertyOwner> owner, Ptr32<const D15fName> name,
                                           Ptr32<const unsigned int> value, int mode, unsigned flags)
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
    Ptr32<D15fProperty> created = d15f_construct_kind7_80178ed0(d15f_allocate_801fe1d8(20));
    Ptr32<Ptr32<D15fProperty>> slots = owner->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<D15fProperty> old = *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<D15fProperty>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    d15f_update_kind7_80178f60(created, value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~1u);
    owner->free_count--;
    d15f_created_count_804ab5b0++;
    return 0;
}


