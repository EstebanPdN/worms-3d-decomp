extern "C" {
struct S4Object { void (**vtable)(); };
struct S4Handles { void *vtable; unsigned char pad[24]; S4Object *entries[64]; unsigned int count,flags; };
int w3d_ctor_8015fef0(void *);
void w3d_base_destroy_8015ff2c(void *,int);
extern unsigned char w3d_vtable_8041c010[];
extern S4Handles *w3d_handles_instance_804abbc8;
S4Handles *w3d_s4_handles_construct(S4Handles *self)
{
    w3d_ctor_8015fef0(self);
    self->vtable=w3d_vtable_8041c010;
    S4Object **entry=self->entries;
    for(int i=64;i;--i) *entry++=0;
    w3d_handles_instance_804abbc8=self;
    self->count=0;
    unsigned int i=0;
    int zero=0;
    S4Object **current=self->entries;
    do {
        if(*current) ((void (*)(S4Object *))(*current)->vtable[4])(*current);
        *current=(S4Object *)zero; ++i; ++current;
    } while(i<=63);
    self->flags &= 0x7fffffff;
    return self;
}
// Deferred: member-array destructor register and loop allocation differ after two attempts.
#if 0
void w3d_s4_handles_destroy(S4Handles *self,int flags)
{
    self->vtable=w3d_vtable_8041c010;
    S4Object **begin=self->entries;
    if(begin) {
        S4Object **end=self->entries+64;
        if(begin!=end) {
            S4Object **first=begin;
            do {
            S4Object *object=*--end;
            if(object) ((void (*)(S4Object *))object->vtable[4])(object);
            } while(first!=end);
        }
    }
    w3d_base_destroy_8015ff2c(self,flags);
}
#endif
// Deferred: slot-address allocation differs after two attempts.
#if 0
void w3d_s4_handles_append(S4Handles *self,S4Object *object)
{
    ((void (*)(S4Object *,int))object->vtable[22])(object,0);
    S4Object **entry=(S4Object **)((char *)self+self->count*4+28);
    if(object) ((void (*)(S4Object *))object->vtable[3])(object);
    if(*entry) ((void (*)(S4Object *))(*entry)->vtable[4])(*entry);
    *entry=object;
    ++self->count;
    self->flags |= 0x80000000;
}
#endif
void w3d_s4_handles_clear(S4Handles *self)
{
    unsigned int i=0;
    if(i<self->count) {
        int zero=0;
        S4Object **entry=self->entries;
        do {
            if(*entry) ((void (*)(S4Object *))(*entry)->vtable[4])(*entry);
            *entry=(S4Object *)zero; ++i; ++entry;
        } while(i<self->count);
    }
    self->count=0;
}
}
