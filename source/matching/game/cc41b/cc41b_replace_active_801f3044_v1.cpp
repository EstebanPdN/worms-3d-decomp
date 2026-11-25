// Original 0x801f3044. Partial owner/interface views; callback results are ignored.
// Retain incoming before releasing prior pointer, including self-assignment, then clear bit 31.
struct cc41b_ActiveInterface;
struct cc41b_ActiveVtable { void *unknown[3]; void (*retain)(cc41b_ActiveInterface *); void (*release)(cc41b_ActiveInterface *); };
struct cc41b_ActiveInterface { cc41b_ActiveVtable *vtable; };
struct cc41b_ActiveOwner { unsigned char unknown[32]; unsigned flags; cc41b_ActiveInterface *active; };
extern "C" int cc41b_replace_active_801f3044(cc41b_ActiveOwner *self,cc41b_ActiveInterface *incoming) {
 if(incoming)incoming->vtable->retain(incoming);
 if(self->active)self->active->vtable->release(self->active);
 *(cc41b_ActiveInterface **)((char *)self+36)=incoming;
 self->flags&=0x7fffffff;
 return 0;
}
