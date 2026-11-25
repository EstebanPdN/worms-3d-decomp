/* GWMP8P rev0 0x80204ffc. Writes the 'SCHM' chunk: a byte-swapped header, one record for each
   schema entry, then one record for each of the entries' typed values. Names and layouts are
   inferred from the original instructions; unread storage is explicit. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <vector>
template <> _STL::_Rb_tree_node_base *_STL::_Rb_global<bool>::_M_increment(_STL::_Rb_tree_node_base *);
inline unsigned short swap16(unsigned short v) { return ((v & 0xff) << 8) | (v >> 8); }
inline unsigned swap32(unsigned x) { return x << 24 | (x & 0xff00) << 8 | (x >> 8 & 0xff00) | x >> 24; }
struct ChunkHeader { unsigned tag; unsigned short version, count; int reserved0, reserved1; };
struct Service { };
struct TypedValue { unsigned value; Service *type; };
struct SchemaEntry { Service *service; std::vector<TypedValue> values; };
typedef std::map<unsigned, SchemaEntry> SchemaMap;
template <> void SchemaMap::_Rep_type::_M_erase(_STL::_Rb_tree_node<SchemaMap::value_type> *);
struct Output { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int write(const void *, int, int); };
struct EntryRecord {
    unsigned short index, valueCount, typeId, reserved;
    void swap() { index = swap16(index); valueCount = swap16(valueCount); reserved = swap16(reserved); typeId = swap16(typeId); }
};
struct ValueRecord {
    unsigned short typeId; unsigned value;
    void swap() { typeId = swap16(typeId); value = swap32(value); }
};
struct TypeIndex;
extern "C" const void *w3d_auto_801fff3c(Service *);
extern "C" unsigned short f5c_find_index_80205738(void *, Service *);
extern "C" int d30s_binary_index_80203598(TypeIndex *, const void *);
extern "C" int w3d_s21_forward_write_802047ac(void *, const void *, int);
struct SchemaWriter {
    char unknown0[20]; Output *output; char unknown24[52]; SchemaMap entries; char unknown100[128 - 76 - sizeof(SchemaMap)];
    TypeIndex *types() { return (TypeIndex *)((char *)this + 128); }
};
extern "C" int d47j_write_schema_chunk_80204ffc(SchemaWriter *self) {
    ChunkHeader h;
    h.tag = 0x5343484d;
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
