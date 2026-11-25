#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_stage_held_setters.c"
/* Held-interface setters of two sibling COM-style classes (session
 * b169b320). Each method retains the new interface (vtable slot 0x0c),
 * releases the one it replaces (slot 0x10), stores it and returns 0; the
 * classes keep 32-byte stage entries at +0x18 and an interface array at
 * +0x50. A flag setter stores one bit and forwards a value to the child
 * at +0x60 through its vtable slot 0x34. Both classes share the code. */

typedef struct W3dInterface W3dInterface;
typedef struct W3dInterfaceVtable
{
    Ptr32<void> unknown_00[3];
    Ptr32<int (Ptr32<W3dInterface>)> retain;   /* 0x0c */
    Ptr32<int (Ptr32<W3dInterface>)> release;  /* 0x10 */
    Ptr32<void> unknown_14[8];
    Ptr32<int (Ptr32<W3dInterface>, int)> set_value; /* 0x34 */
} W3dInterfaceVtable;
struct W3dInterface
{
    Ptr32<W3dInterfaceVtable> vtable;
};

typedef struct W3dStageEntry
{
    int unknown_00;
    Ptr32<W3dInterface> first;                 /* 0x04 */
    Ptr32<W3dInterface> third;                 /* 0x08 */
    Ptr32<W3dInterface> second;                /* 0x0c */
    unsigned char unknown_10[16];
} W3dStageEntry;

typedef struct W3dStageOwner
{
    Ptr32<void> vtable;
    unsigned char unknown_04[20];
    Ptr32<W3dStageEntry> entries;              /* 0x18 */
    unsigned char unknown_1c[20];
    unsigned int unknown_bits:30; unsigned int flag:1; unsigned int unknown_bit:1;
    unsigned char unknown_34[28];
    Ptr32<Ptr32<W3dInterface>> slots;                /* 0x50 */
    unsigned char unknown_54[12];
    Ptr32<W3dInterface> child;                 /* 0x60 */
} W3dStageOwner;

/* Retain the new interface, release the old one, store the new one. The
 * array setter matches only through this inline helper; the stage-entry
 * setters were written out in full. */
static inline void w3d_held_assign(Ptr32<Ptr32<W3dInterface>> slot, Ptr32<W3dInterface> value)
{
    if (value != 0)
        value->vtable->retain(value);
    if (*slot != 0)
        (*slot)->vtable->release(*slot);
    *slot = value;
}

int w3d_stage_set_flag_8034870c(Ptr32<W3dStageOwner> self, int flag, int value)
{
    self->flag = flag;
    self->child->vtable->set_value(self->child, value);
    return 0;
}

int w3d_stage_set_flag_803499f0(Ptr32<W3dStageOwner> self, int flag, int value)
{
    self->flag = flag;
    self->child->vtable->set_value(self->child, value);
    return 0;
}

int w3d_stage_set_slot_80348878(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    w3d_held_assign(&self->slots[index], value);
    return 0;
}

int w3d_stage_set_slot_80349b5c(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    w3d_held_assign(&self->slots[index], value);
    return 0;
}

int w3d_stage_set_first_80348c80(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    Ptr32<W3dStageEntry> entry = &self->entries[index];
    if (value != 0)
        value->vtable->retain(value);
    if (entry->first != 0)
        entry->first->vtable->release(entry->first);
    entry->first = value;
    return 0;
}

int w3d_stage_set_first_80349f74(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    Ptr32<W3dStageEntry> entry = &self->entries[index];
    if (value != 0)
        value->vtable->retain(value);
    if (entry->first != 0)
        entry->first->vtable->release(entry->first);
    entry->first = value;
    return 0;
}

int w3d_stage_set_second_80348d04(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    Ptr32<W3dStageEntry> entry = &self->entries[index];
    if (value != 0)
        value->vtable->retain(value);
    if (entry->second != 0)
        entry->second->vtable->release(entry->second);
    entry->second = value;
    return 0;
}

int w3d_stage_set_second_80349ff8(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    Ptr32<W3dStageEntry> entry = &self->entries[index];
    if (value != 0)
        value->vtable->retain(value);
    if (entry->second != 0)
        entry->second->vtable->release(entry->second);
    entry->second = value;
    return 0;
}

int w3d_stage_set_third_80348d98(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    Ptr32<W3dStageEntry> entry = &self->entries[index];
    if (value != 0)
        value->vtable->retain(value);
    if (entry->third != 0)
        entry->third->vtable->release(entry->third);
    entry->third = value;
    return 0;
}

int w3d_stage_set_third_8034a08c(Ptr32<W3dStageOwner> self, int index, Ptr32<W3dInterface> value)
{
    Ptr32<W3dStageEntry> entry = &self->entries[index];
    if (value != 0)
        value->vtable->retain(value);
    if (entry->third != 0)
        entry->third->vtable->release(entry->third);
    entry->third = value;
    return 0;
}


}
