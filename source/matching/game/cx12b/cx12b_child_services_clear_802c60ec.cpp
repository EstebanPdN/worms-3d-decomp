// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {void *s0[3];void (*retain)(Service*);void (*release)(Service*);void *s1[17];void (*visible)(Service*,int);void (*attach)(Service*,Service*,int);void (*remove)(Service*,void*);void *s2[4];void *(*item)(Service*,int);int (*count)(Service*);};struct Service {Vtable *vtable;};
struct Owner {unsigned char opaque[28];Service *children;int state;unsigned char opaque2[4];Service *s40,*s44,*s48,*s52,*s56,*s60,*s64;unsigned char rest[36];int enabled;template<unsigned int Offset>void clear(Service *zero){Service **slot=(Service **)((unsigned char*)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};

extern "C" void w3d_cx12b_child_services_clear_802c60ec(Owner *self){if(self->children){while(self->children->vtable->count(self->children)){Service *s=self->children;Vtable *v=s->vtable;void *child=v->item(s,0);v->remove(s,child);}if(self->children)self->children->vtable->release(self->children);self->children=0;}
 if(self->s48)self->clear<48>(0);if(self->s52)self->clear<52>(0);if(self->s56)self->clear<56>(0);
}

