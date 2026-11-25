// PPC32 owner slots and interface methods; names inferred from the observed drain/release operations.
struct Service;struct Vtable {void *p0[4];int (*release)(Service *);void *p1[19];void (*remove)(Service *,void *);void *p2[4];void *(*item)(Service *,int);int (*count)(Service *);};struct Service {Vtable *vtable;};
struct Owner {unsigned char p[28];Service *children;unsigned char p2[8];Service *s40,*s44,*s48,*s52,*s56,*s60,*s64;unsigned char p3[24];Service *s92;template<unsigned int Offset>void clear(Service *zero){Service **slot=(Service **)((unsigned char *)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void w3d_cx11b_child_services_clear_802c7014(Owner *self){if(self->children){while(self->children->vtable->count(self->children)){Service *s=self->children;Vtable *v=s->vtable;void *child=v->item(s,0);v->remove(s,child);}if(self->children)self->children->vtable->release(self->children);self->children=0;}
 if(self->s92)self->clear<92>(0);
 if(self->s40)self->clear<40>(0);
 if(self->s48)self->clear<48>(0);
 if(self->s56)self->clear<56>(0);
 if(self->s44)self->clear<44>(0);
 if(self->s52)self->clear<52>(0);
 if(self->s60)self->clear<60>(0);
 if(self->s64)self->clear<64>(0);
}


