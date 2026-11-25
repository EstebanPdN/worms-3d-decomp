#include "w3d_ptr.h"
#line 1 "d25j_set_string_property_80175a34.cpp"
// Create or update a kind-4 (string) property of a table (Worms 3D GameCube PAL, 0x80175a34).
//
// Looks the name up (0x80177eb0). When it exists and flag 1 allows updating, a
// slot of kind 4 is updated; flag 4 skips the mode handling, flag 8 replaces
// the mode, otherwise a different mode is an error. Any other existing case
// returns 0x80004005. A missing name creates a 20-byte property
// (0x80179038), stores it in the slot with retain/release, sets value, name,
// mode and the flags without 1, 4 and 8, then updates the free count and the
// global created counter.
//
// The two update returns are separate statements in the source: late
// cross-jumping merges them, and the extra references give the value parameter
// its register priority. Built with -fvtable-thunks (real virtual calls).

struct Name;
struct String;

struct Property {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN8Property15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN8Property6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN8Property7releaseEv"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN8Property7slot_20Ev"));
    int w3d_r_kind() __asm__(W3D_SYM("_ZN8Property4kindEv"));
    int w3d_r_wrong_kind() __asm__(W3D_SYM("_ZN8Property10wrong_kindEv"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN8Property7slot_32Ev"));
    int w3d_r_mode() __asm__(W3D_SYM("_ZN8Property4modeEv"));
    void w3d_r_slot_40() __asm__(W3D_SYM("_ZN8Property7slot_40Ev"));
    void w3d_r_set_name(Ptr32<const Name> name) __asm__(W3D_SYM("_ZN8Property8set_nameEPK4Name"));
    void w3d_r_set_mode(int mode) __asm__(W3D_SYM("_ZN8Property8set_modeEi"));
    void w3d_r_set_flags(unsigned flags) __asm__(W3D_SYM("_ZN8Property9set_flagsEj"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int kind() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int wrong_kind() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int mode() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Property, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set_name(Ptr32<const Name> w3d_a0) { ((void (*)(w3d_u32, Ptr32<const Name>))w3d::vfn(this->w3d_vptr_Property, 11))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void set_mode(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Property, 12))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void set_flags(unsigned int w3d_a0) { ((void (*)(w3d_u32, unsigned int))w3d::vfn(this->w3d_vptr_Property, 13))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Property; };

// Observed layout: slot array at +24, free-slot count at +2092.
struct Table {
    char pad_00[24];
    Ptr32<Ptr32<Property>> slots;
    char pad_1c[2064];
    int free_count;
};

extern "C" int fn_80177eb0(Ptr32<Table> table, Ptr32<const Name> name, Ptr32<unsigned short> index);
extern "C" Ptr32<void> fn_801fe1d8(unsigned size);
extern unsigned var_804ab5b0;
extern "C" Ptr32<Property> fn_80179038(Ptr32<void> memory);
extern "C" Ptr32<Property> fn_80343744(Ptr32<Property> property);
extern "C" int fn_801790bc(Ptr32<Property> property, Ptr32<const String> value);

extern "C" int d25j_set_string_property_80175a34(Ptr32<Table> table, Ptr32<const Name> name, Ptr32<const String> value, int mode, unsigned flags)
{
    unsigned short index;
    if (fn_80177eb0(table, name, &index) >= 0) {
        if (flags & 1) {
            if (table->slots[index]->kind() == 4) {
                if (flags & 4)
                    return fn_801790bc(fn_80343744(table->slots[index]), value);
                if (flags & 8) {
                    table->slots[index]->set_mode(mode);
                } else if (table->slots[index]->mode() != mode) {
                    table->slots[index]->mode();
                    return (int)0x80004005;
                }
                return fn_801790bc(fn_80343744(table->slots[index]), value);
            }
        }
        return (int)0x80004005;
    }
    Ptr32<Property> created = fn_80179038(fn_801fe1d8(20));
    Ptr32<Ptr32<Property>> slots = table->slots;
    unsigned offset = (unsigned)index << 2;
    if (created)
        created->retain();
    Ptr32<Property> old = *(Ptr32<Ptr32<Property>>)w3d::G((offset + (int)w3d::H(slots)));
    if (old)
        old->release();
    *(Ptr32<Ptr32<Property>>)w3d::G((offset + (int)w3d::H(slots))) = created;
    fn_801790bc(created, value);
    created->set_name(name);
    created->set_mode(mode);
    created->set_flags(flags & ~13u);
    table->free_count--;
    var_804ab5b0++;
    return 0;
}


