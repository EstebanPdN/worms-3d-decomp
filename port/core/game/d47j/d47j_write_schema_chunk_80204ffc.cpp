#include "w3d_ptr.h"
#line 1 "d47j_write_schema_chunk_80204ffc.cpp"
/* GWMP8P rev0 0x80204ffc. Writes the 'SCHM' chunk: a byte-swapped header, one record for each
   schema entry, then one record for each of the entries' typed values. Names and layouts are
   inferred from the original instructions; unread storage is explicit. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <vector>
template <>Ptr32<_STL::_Rb_tree_node_base> _STL::_Rb_global<bool>::_M_increment(Ptr32<_STL::_Rb_tree_node_base>);
inline unsigned short swap16(unsigned short v) { return v; }
inline unsigned swap32(unsigned x) { return x; }
struct ChunkHeader { unsigned tag; unsigned short version, count; int reserved0, reserved1; };
struct Service {  char w3d_empty; };
struct TypedValue { unsigned value; Ptr32<Service> type; };
struct SchemaEntry { Ptr32<Service> service; std::vector<TypedValue> values; };
typedef std::map<unsigned, SchemaEntry> SchemaMap;
template <> void SchemaMap::_Rep_type::_M_erase(Ptr32<_STL::_Rb_tree_node < SchemaMap::value_type >>);
struct Output { int w3d_r_v0() __asm__(W3D_SYM("_ZN6Output2v0Ev")); int w3d_r_v1() __asm__(W3D_SYM("_ZN6Output2v1Ev")); int w3d_r_v2() __asm__(W3D_SYM("_ZN6Output2v2Ev")); int w3d_r_v3() __asm__(W3D_SYM("_ZN6Output2v3Ev")); int w3d_r_write(Ptr32<const void>, int, int) __asm__(W3D_SYM("_ZN6Output5writeEPKvii"));  __attribute__((always_inline)) inline int v0() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Output, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v1() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Output, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v2() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Output, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v3() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Output, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int write(Ptr32<const void> w3d_a0, int w3d_a1, int w3d_a2) { return ((int (*)(w3d_u32, Ptr32<const void>, int, int))w3d::vfn(this->w3d_vptr_Output, 6))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Output; };
struct EntryRecord {
    unsigned short index, valueCount, typeId, reserved;
    void swap() { index = swap16(index); valueCount = swap16(valueCount); reserved = swap16(reserved); typeId = swap16(typeId); }
};
struct ValueRecord {
    unsigned short typeId; unsigned value;
    void swap() { typeId = swap16(typeId); value = swap32(value); }
};
struct TypeIndex;
extern "C" Ptr32<const void> w3d_auto_801fff3c(Ptr32<Service>);
extern "C" unsigned short f5c_find_index_80205738(Ptr32<void>, Ptr32<Service>);
extern "C" int d30s_binary_index_80203598(Ptr32<TypeIndex>, Ptr32<const void>);
extern "C" int w3d_s21_forward_write_802047ac(Ptr32<void>, Ptr32<const void>, int);
struct SchemaWriter {
    char unknown0[20]; Ptr32<Output> output; char unknown24[52]; SchemaMap entries; char unknown100[128 - 76 - sizeof(SchemaMap)];
    Ptr32<TypeIndex> types() { return (Ptr32<TypeIndex>)((Ptr32<char>)this + 128); }
};
extern "C" int d47j_write_schema_chunk_80204ffc(Ptr32<SchemaWriter> self) {
    ChunkHeader h;
    h.tag = 0x4d484353;
    h.version = 1;
    h.count = self->entries.size();
    h.reserved0 = 0;
    h.reserved1 = 0;
    h.version = swap16(h.version);
    h.count = swap16(h.count);
    w3d_s21_forward_write_802047ac(self, &h, 16);
    {
    SchemaMap::iterator i = self->entries.begin();
    SchemaMap::iterator e = self->entries.end();
    for (; i != e; ++i) {
        SchemaEntry &entry = (*i).second;
        EntryRecord r;
        r.index = f5c_find_index_80205738(self, entry.service);
        r.valueCount = entry.values.size();
        r.reserved = 0;
        r.typeId = d30s_binary_index_80203598(self->types(), w3d_auto_801fff3c(entry.service));
        r.swap();
        self->output->write(&r, 8, 0);
    }
    }
    SchemaMap::iterator j = self->entries.begin();
    SchemaMap::iterator end = self->entries.end();
    for (; j != end; ++j) {
        SchemaEntry &entry = (*j).second;
        for (TypedValue *v = entry.values.begin(), *e = entry.values.end(); v != e; ++v) {
            ValueRecord r;
            r.typeId = d30s_binary_index_80203598(self->types(), w3d_auto_801fff3c(v->type));
            r.value = v->value;
            r.swap();
            self->output->write(&r, 8, 0);
        }
    }
    return 0;
}


