// Original 0x8020a730. Partial registry and interface views; size/identity unknown.
// Validation precedes incoming retain and outgoing release, including self-assignment.
struct cc41b_Selectable;
struct cc41b_SelectableVtable { void *unknown[3]; void (*retain)(cc41b_Selectable *); void (*release)(cc41b_Selectable *); };
struct cc41b_Selectable { cc41b_SelectableVtable *vtable; };
struct cc41b_SelectionRange {cc41b_Selectable **begin,**end;};
struct cc41b_Selection { unsigned char unknown[20]; cc41b_SelectionRange range; unsigned unknown2; cc41b_Selectable *selected; };
inline cc41b_Selectable **cc41b_find(cc41b_SelectionRange *range,cc41b_Selectable *incoming) {
 cc41b_Selectable **cursor=range->begin;
 for(;cursor!=range->end;++cursor) if(*cursor==incoming) break;
 return cursor;
}
extern "C" unsigned cc41b_select_registered_8020a730(cc41b_Selection *self,cc41b_Selectable *incoming) {
 if(incoming) {
  cc41b_Selectable **cursor=cc41b_find(&self->range,incoming);
  if(cursor==self->range.end) return 0x80004005;
  if(incoming) incoming->vtable->retain(incoming);
 }
 if(self->selected) self->selected->vtable->release(self->selected);
 self->selected=incoming;
 return 0;
}
