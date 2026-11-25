#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_entry_property_value_800fd388.c"
typedef struct K4aPropValue { int value; } K4aPropValue;
typedef struct K4aEntry { char pad0[213]; unsigned char index; } K4aEntry;
extern Ptr32<void> w3d_table_8044a524[];
extern Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern Ptr32<K4aEntry> w3d_auto_801797b4(Ptr32<void>);
extern Ptr32<void> s8_indexed_property_800fd3e4(Ptr32<K4aPropValue> out, int index, ...);

/* En PPC el resultado va a un puntero oculto en r3, y así lo llaman todos. */
Ptr32<K4aPropValue> k4a_entry_property_value_800fd388(Ptr32<K4aPropValue> out, unsigned int slot)
{
    Ptr32<K4aEntry> entry = w3d_auto_801797b4(w3d_empty_80341584(*(Ptr32<Ptr32<void>>)((slot << 2) + (Ptr32<char>)w3d_table_8044a524)));
    s8_indexed_property_800fd3e4(out, entry->index);
    return out;
}

}
