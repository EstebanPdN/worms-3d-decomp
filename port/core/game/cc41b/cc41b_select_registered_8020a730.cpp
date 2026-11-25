#include "w3d_ptr.h"
#line 1 "cc41b_select_registered_8020a730.cpp"
// Original 0x8020a730. Partial registry and interface views; size/identity unknown.
// Validation precedes incoming retain and outgoing release, including self-assignment.
struct cc41b_Selectable;
struct cc41b_SelectableVtable { Ptr32<void> unknown[3]; Ptr32<void (Ptr32<cc41b_Selectable>)> retain; Ptr32<void (Ptr32<cc41b_Selectable>)> release; };
struct cc41b_Selectable { Ptr32<cc41b_SelectableVtable> vtable; };
struct cc41b_SelectionRange {Ptr32<Ptr32<cc41b_Selectable>> first; Ptr32<Ptr32<cc41b_Selectable>> last; Ptr32<Ptr32<cc41b_Selectable>> begin(){return first;} Ptr32<Ptr32<cc41b_Selectable>> end(){return last;} };
struct cc41b_Selection { unsigned char unknown[20]; cc41b_SelectionRange range; unsigned unknown2; Ptr32<cc41b_Selectable> selected; };
inline Ptr32<Ptr32<cc41b_Selectable>> cc41b_find(Ptr32<cc41b_SelectionRange> range,Ptr32<cc41b_Selectable> incoming) {
 Ptr32<Ptr32<cc41b_Selectable>> cursor=range->begin();
 for(;cursor!=range->end();++cursor) if(*cursor==incoming) break;
 return cursor;
}
extern "C" unsigned cc41b_select_registered_8020a730(Ptr32<cc41b_Selection> self,Ptr32<cc41b_Selectable> incoming) {
 if(incoming) {
  Ptr32<Ptr32<cc41b_Selectable>> cursor=cc41b_find(&self->range,incoming);
  if(cursor==self->range.end()) return 0x80004005;
  if(incoming) incoming->vtable->retain(incoming);
 }
 if(self->selected) self->selected->vtable->release(self->selected);
 self->selected=incoming;
 return 0;
}


