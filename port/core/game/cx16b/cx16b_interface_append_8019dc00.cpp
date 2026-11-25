#include "w3d_ptr.h"
#line 1 "cx16b_interface_append_8019dc00.cpp"
/* Three-word counted interface vector at owner+24. The virtual callback
   receives the owner after the retained value has been installed. */
struct Cx16bInterface { Ptr32<Ptr32<void>> vtable; };
struct Cx16bVector { int count,capacity; Ptr32<Ptr32<Cx16bInterface>> items; };
struct Cx16bOwner { char unknown[24]; Cx16bVector list; };
extern "C" void fn_80210d54(Ptr32<Cx16bVector>,int);
extern "C" int w3d_cx16b_interface_append_8019dc00(Ptr32<Cx16bOwner> self,Ptr32<Cx16bInterface> item)
{
    Ptr32<Cx16bVector> list=&self->list;
    fn_80210d54(list,self->list.count+1);
    int offset=self->list.count<<2;
    Ptr32<Ptr32<Cx16bInterface>> items=list->items;
    if(item)((Ptr32<void (Ptr32<Cx16bInterface>)>)item->vtable[3])(item);
    Ptr32<Ptr32<Cx16bInterface>> slot=(Ptr32<Ptr32<Cx16bInterface>>)w3d::G((offset+(unsigned)w3d::H(items)));
    Ptr32<Cx16bInterface> old=*slot;
    if(old)((Ptr32<void (Ptr32<Cx16bInterface>)>)old->vtable[4])(old);
    *slot=item;
    ++self->list.count;
    ((Ptr32<void (Ptr32<Cx16bInterface>, Ptr32<Cx16bOwner>)>)item->vtable[6])(item,self);
    return 0;
}


