typedef struct K4aPropValue { int value; } K4aPropValue;
typedef struct K4aEntry { char pad0[213]; unsigned char index; } K4aEntry;
extern void *w3d_table_8044a524[];
extern void *w3d_empty_80341584(void *);
extern K4aEntry *w3d_auto_801797b4(void *);
extern void * s8_indexed_property_800fd3e4(K4aPropValue *out, int index, ...);

K4aPropValue k4a_entry_property_value_800fd388(unsigned int slot)
{
    K4aPropValue v;
    K4aEntry *entry = w3d_auto_801797b4(w3d_empty_80341584(*(void **)((slot << 2) + (char *)w3d_table_8044a524)));
    s8_indexed_property_800fd3e4(&v, entry->index);
    return v;
}
