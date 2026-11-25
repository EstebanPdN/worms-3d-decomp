// PPC32 vector at owner +20; release virtual slot +16. Empty copy is retained from the original generic erase.
struct Service;struct Vtable {void *unused[4];int (*release)(Service *);};struct Service {Vtable *vtable;};
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);
struct Vector {Service **begin,**end,**capacity;
 void clear(){Service **first=begin,**last=end;unsigned int bytes=(unsigned char *)last-(unsigned char *)first;copy_802eee50(first,last,0);end=(Service **)((unsigned char *)end-bytes);}
};
struct Owner {unsigned char opaque[20];Vector values;};
extern "C" int w3d_cx11b_service_vector_clear_8020ad18(Owner *self){Service **end=self->values.end;Service **p=self->values.begin;while(p!=end){Service *s=*p++;s->vtable->release(s);}self->values.clear();return 0;}

