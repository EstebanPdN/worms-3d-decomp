/* Three-word counted interface vector at owner+24. The virtual callback
   receives the owner after the retained value has been installed. */
struct Cx16bInterface { void **vtable; };
struct Cx16bVector { int count,capacity; Cx16bInterface **items; };
struct Cx16bOwner { char unknown[24]; Cx16bVector list; };
extern "C" void fn_80210d54(Cx16bVector *,int);
extern "C" int w3d_cx16b_interface_append_8019dc00(Cx16bOwner *self,Cx16bInterface *item)
{
    Cx16bVector *list=&self->list;
    fn_80210d54(list,self->list.count+1);
    int offset=self->list.count<<2;
    Cx16bInterface **items=list->items;
    if(item)((void(*)(Cx16bInterface *))item->vtable[3])(item);
    Cx16bInterface **slot=(Cx16bInterface **)(offset+(unsigned)items);
    Cx16bInterface *old=*slot;
    if(old)((void(*)(Cx16bInterface *))old->vtable[4])(old);
    *slot=item;
    ++self->list.count;
    ((void(*)(Cx16bInterface *,Cx16bOwner *))item->vtable[6])(item,self);
    return 0;
}
