// Observed interface prefix and owner offsets; names are structural.
struct Interface { void **vtable; };
struct Owner;
#define SLOTS (*(Interface ***)((char *)self + 24))
#define COUNT (*(unsigned int *)((char *)self + 2116))
extern "C" int sol35c2_next_slot_80176594(Owner *self, unsigned int *cursor, Interface **output) {
 unsigned int i = *cursor;
 Interface **slots;
 for (;;) {
  if(i >= COUNT) return 0;
  slots = SLOTS;
  if(slots[i]) break;
  i = *cursor + 1;
  *cursor = i;
 }
 i = *cursor;
 if(i >= COUNT) return 0;
 *cursor = i + 1;
 Interface *fresh = slots[i];
 if(fresh) ((unsigned (*)(Interface *))fresh->vtable[3])(fresh);
 Interface *old = *output;
 if(old) ((unsigned (*)(Interface *))old->vtable[4])(old);
 *output = slots[i];
 return 1;
}
