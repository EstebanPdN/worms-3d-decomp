#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_slot_bank_clear_800f342c.c"

struct K4aSlot;
typedef struct K4aSlotVtable
{
  Ptr32<void (void)> unknown_00[4];
  Ptr32<void (Ptr32<struct K4aSlot>)> release;
} K4aSlotVtable;
typedef struct K4aSlot
{
  Ptr32<const K4aSlotVtable> vtable;
} K4aSlot;
typedef struct K4aSlotBank
{
  char pad0[88];
  Ptr32<K4aSlot> slots[200];
  char pad1[2280];
  int mode;
} K4aSlotBank;
inline static void k4a_slot_release(Ptr32<K4aSlot> s)
{
  if (s != 0)
    s->vtable->release(s);
}

void k4a_slot_bank_clear_800f342c(Ptr32<K4aSlotBank> self)
{
  unsigned int i;
  Ptr32<Ptr32<K4aSlot>> p;
  if (self->mode != 1)
  {
    self->mode = 0;
  }
  p = self->slots;
  for (i = 0; i < 200; i++)
  {
    self++;
    self--;
    k4a_slot_release(*p);
    *p = 0;
    p++;
  }

}

}
