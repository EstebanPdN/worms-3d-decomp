// Original 0x8020adb0. Three opaque 32-bit callback arguments are forwarded unchanged.
// Range end is reloaded after each successful callback; first negative result stops iteration.
// Partial registry/interface views; original class identity and full sizes remain unknown.
struct cc41b_DispatchItem;
struct cc41b_DispatchVtable { void *unknown[6]; int (*dispatch)(cc41b_DispatchItem *,unsigned,unsigned,unsigned); };
struct cc41b_DispatchItem { cc41b_DispatchVtable *vtable; };
struct cc41b_DispatchRange { cc41b_DispatchItem **first,**last; cc41b_DispatchItem **begin(){return first;} cc41b_DispatchItem **end(){return last;} };
struct cc41b_DispatchOwner { unsigned char unknown[20]; cc41b_DispatchRange range; };
extern "C" int cc41b_dispatch_registered_8020adb0(cc41b_DispatchOwner *self,unsigned a,unsigned b,unsigned c) {
 for(cc41b_DispatchItem **cursor=self->range.begin();cursor!=self->range.end();++cursor) {
  cc41b_DispatchItem *item=*cursor;
  int status=item->vtable->dispatch(item,a,b,c);
  if(status<0)return status;
 }
 return 0;
}
