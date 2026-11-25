#include "w3d_ptr.h"
#line 1 "s1_detail_resources.cpp"
/* Detail-resource teardown and observed land-theme suffix handling. */
extern "C" {
struct W3dS1DetailRef;
struct W3dS1DetailVtable { Ptr32<void (void)> unused[4];Ptr32<void (Ptr32<W3dS1DetailRef>)> release; };
struct W3dS1DetailRef { Ptr32<W3dS1DetailVtable> vtable; };
struct W3dS1Detail { char unknown[60];Ptr32<const char> name; Ptr32<const char> resource;Ptr32<void> effect; Ptr32<void> handle;Ptr32<W3dS1DetailRef> held; };
struct W3dS1DetailString { Ptr32<const char> text;unsigned int unknown; };
extern unsigned int w3d_heap_804adde4,w3d_detail_count_804b17e4,w3d_detail_limit_804b17e8;
extern const char w3d_str_8037917c[],w3d_str_80379180[],w3d_str_80379188[],w3d_str_80379190[],w3d_str_80379198[],w3d_str_8037919c[],w3d_str_803791a4[],w3d_str_803791b0[],w3d_str_803791c0[];
void w3d_handle_member_destroy_801265a4(Ptr32<void>,int);
void w3d_fn_800e5bb8(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_heap_release(Ptr32<void>,Ptr32<void>);
void w3d_string_from_text(Ptr32<void>,Ptr32<const char>);
void w3d_fn_8020c048(Ptr32<void>,Ptr32<const void>,int);
void w3d_fn_8020c0fc(Ptr32<void>,Ptr32<const void>,int);
void w3d_fn_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
void w3d_string_assign(Ptr32<void>,Ptr32<const char>);
void w3d_string_append(Ptr32<void>,Ptr32<const char>);
int strcmp(Ptr32<const char>,Ptr32<const char>);
void w3d_fn_800fc5dc(Ptr32<Ptr32<const char>>,Ptr32<void>);
static inline void replace_detail_ref(Ptr32<W3dS1DetailRef> &slot,Ptr32<W3dS1DetailRef> next)
{
    if(slot)slot->vtable->release(slot);
    slot=next;
}
void w3d_fn_800600d4(Ptr32<W3dS1Detail> self,int flags)
{
    if(self->handle)w3d_handle_member_destroy_801265a4(self->handle,3);
    if(self->held)replace_detail_ref(self->held,0);
    if(self->effect)w3d_fn_800e5bb8(self->effect);
    if(self->held)self->held->vtable->release(self->held);
    Ptr32<Ptr32<const char>> resource=&self->resource;
    Ptr32<Ptr32<const char>> name=&self->name;
    w3d_string_base_finish(resource);w3d_string_release(resource);
    w3d_string_base_finish(name);w3d_string_release(name);
    if(flags&1)w3d_heap_release(&w3d_heap_804adde4,self);
}
#if 0 /* Excluded: argument setup scheduling remains different after three attempts. */
void w3d_fn_800606e4(W3dS1Detail *self)
{
    struct { W3dS1DetailString suffix,prefix;const char *key,*theme; } local;
    w3d_string_from_text(&local.suffix,w3d_str_8037917c);
    int found=0;
    w3d_string_from_text(&local.prefix,w3d_str_8037917c);
    w3d_fn_8020c048(&local.prefix,&self->resource,7);
    if(!strcmp(local.prefix.text,w3d_str_80379180)) {
        found=1;w3d_fn_8020c0fc(&local.suffix,&self->resource,((unsigned short *)self->resource)[-2]-7);
    }
    w3d_fn_8020c048(&local.prefix,&self->resource,6);
    if(!strcmp(local.prefix.text,w3d_str_80379188)) {
        found=1;w3d_fn_8020c0fc(&local.suffix,&self->resource,((unsigned short *)self->resource)[-2]-6);
    }
    if(!strcmp(local.prefix.text,w3d_str_80379190)) {
        found=1;w3d_fn_8020c0fc(&local.suffix,&self->resource,((unsigned short *)self->resource)[-2]-6);
    }
    w3d_fn_8020c048(&local.prefix,&self->resource,3);
    if(!strcmp(local.prefix.text,w3d_str_80379198)) {
        found=1;w3d_fn_8020c0fc(&local.suffix,&self->resource,((unsigned short *)self->resource)[-2]-3);
    }
    w3d_fn_8020c048(&local.prefix,&self->resource,5);
    if(!strcmp(local.prefix.text,w3d_str_8037919c)) {
        found=1;w3d_fn_8020c0fc(&local.suffix,&self->resource,((unsigned short *)self->resource)[-2]-5);
    }
    if(found) {
        local.key=w3d_str_803791a4;w3d_fn_800fc2b0(&local.key,&local.theme);
        w3d_string_assign(&self->resource,local.theme);w3d_string_append(&self->resource,local.suffix.text);
    }
    W3dS1DetailString *suffix=&local.suffix;
    w3d_string_base_finish(&local.prefix);w3d_string_release(&local.prefix);
    w3d_string_base_finish(suffix);w3d_string_release(suffix);
}
#endif
void w3d_fn_800608d4(Ptr32<W3dS1Detail> self,Ptr32<Ptr32<const char>> name)
{
    Ptr32<const char> position; Ptr32<const char> orientation;
    if(!strcmp(self->name,*name)) {
        if(++w3d_detail_count_804b17e4<=w3d_detail_limit_804b17e8) {
            position=w3d_str_803791b0;w3d_fn_800fc5dc(&position,(Ptr32<char>)self+4);
        }
        orientation=w3d_str_803791c0;w3d_fn_800fc5dc(&orientation,(Ptr32<char>)self+28);
    }
    w3d_string_base_finish(name);w3d_string_release(name);
}
void w3d_fn_8006096c(Ptr32<W3dS1Detail> self)
{
    if(self->handle) { w3d_handle_member_destroy_801265a4(self->handle,3);self->handle=0; }
    if(self->held)replace_detail_ref(self->held,0);
    if(self->effect) { w3d_fn_800e5bb8(self->effect);self->effect=0; }
}
}


