#include "w3d_ptr.h"
#line 1 "f5c_search_801e8ff8.cpp"
struct Entry{Ptr32<const void> key;unsigned value;};struct Owner{char unknown[24];Ptr32<Entry> entries;};struct Registry{Ptr32<Ptr32<Owner>> first;Ptr32<Ptr32<Owner>> last;};extern Registry lbl_8045e0a4[];extern "C" Ptr32<const void> fn_801fff3c(Ptr32<const void>);extern "C" int fn_802eedc0(Ptr32<const void>,Ptr32<const void>,unsigned);extern "C" Ptr32<Entry> f5c_search_801e8ff8(Ptr32<const void> key){Ptr32<Ptr32<Owner>> end=lbl_8045e0a4[0].last;Ptr32<Ptr32<Owner>> p=lbl_8045e0a4[0].first;for(;p!=end;++p){Ptr32<Entry> q=(*p)->entries;while(q->key){Ptr32<const void> t=fn_801fff3c(key);if(fn_802eedc0(q->key,t,16)==0)return q;++q;}}return 0;}

