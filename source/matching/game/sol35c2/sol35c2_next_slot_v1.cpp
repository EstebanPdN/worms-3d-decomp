// Observed interface prefix and owner offsets; names are structural.
struct Interface { void **vtable; };
struct Owner { char unknown0[24]; Interface **slots; char unknown28[2088]; unsigned int count; };
extern "C" int sol35c2_next_slot_80176594(Owner *self, unsigned int *cursor, Interface **output) {
 unsigned int i = *cursor;
 Interface **slots;
 for (;;) {
  if(i >= self->count) return 0;
  slots = self->slots;
  if(slots[i]) break;
  i = ++*cursor;
 }
 i = *cursor;
 if(i >= self->count) return 0;
 *cursor = i + 1;
 Interface *fresh = slots[i];
 if(fresh) ((unsigned (*)(Interface *))fresh->vtable[3])(fresh);
 Interface *old = *output;
 if(old) ((unsigned (*)(Interface *))old->vtable[4])(old);
 *output = slots[i];
 return 1;
}
