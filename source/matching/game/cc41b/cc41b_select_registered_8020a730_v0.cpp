// Original 0x8020a730. Partial registry and interface views; size/identity unknown.
// Validation precedes incoming retain and outgoing release, including self-assignment.
struct cc41b_Selectable;
struct cc41b_SelectableVtable { void *unknown[3]; void (*retain)(cc41b_Selectable *); void (*release)(cc41b_Selectable *); };
struct cc41b_Selectable { cc41b_SelectableVtable *vtable; };
struct cc41b_Selection { unsigned char unknown[20]; cc41b_Selectable **begin,**end; unsigned unknown2; cc41b_Selectable *selected; };
extern "C" unsigned cc41b_select_registered_8020a730(cc41b_Selection *self,cc41b_Selectable *incoming) {
 if(incoming) {
  cc41b_Selectable **cursor=self->begin;
  for(;cursor!=self->end && *cursor!=incoming;++cursor) {}
  if(cursor==self->end) return 0x80004005;
  if(incoming) incoming->vtable->retain(incoming);
 }
 if(self->selected) self->selected->vtable->release(self->selected);
 self->selected=incoming;
 return 0;
}
