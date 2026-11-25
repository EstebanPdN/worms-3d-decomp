
struct K4aSlot;
typedef struct K4aSlotVtable
{
  void (*unknown_00[4])(void);
  void (*release)(struct K4aSlot *self);
} K4aSlotVtable;
typedef struct K4aSlot
{
  const K4aSlotVtable *vtable;
} K4aSlot;
typedef struct K4aSlotBank
{
  char pad0[88];
  K4aSlot *slots[200];
  char pad1[2280];
  int mode;
} K4aSlotBank;
inline static void k4a_slot_release(K4aSlot *s)
{
  if (s != 0)
    s->vtable->release(s);
}

void k4a_slot_bank_clear_800f342c(K4aSlotBank *self)
{
  unsigned int i;
  K4aSlot **p;
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
