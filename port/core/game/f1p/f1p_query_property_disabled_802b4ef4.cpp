#include "w3d_ptr.h"
#line 1 "f1p_query_property_disabled_802b4ef4.cpp"
// Original 0x802b4ef4: optional property-to-disabled-state query.
// Branch arms deliberately retain the observed flag computation.
struct Item;
struct VTable { Ptr32<void> pad[6]; Ptr32<int (Ptr32<Item>)> kind; };
struct Item { Ptr32<VTable> v; };
struct Owner { char pad[220]; int disabled; char pade0[28]; Ptr32<Item> item; };
extern "C" Ptr32<void> fn_803426b4(Ptr32<Item>);
extern "C" int fn_80178c48(Ptr32<void>);
extern "C" Ptr32<void> fn_80342a78(Ptr32<Item>);
extern "C" int fn_80178d1c(Ptr32<void>);
extern "C" int w3d_query_property_disabled_802b4ef4(Ptr32<Owner> self) {
    if(self->item) {
        int value=0;
        switch(self->item->v->kind(self->item)) {
        case 0: value=fn_80178c48(fn_803426b4(self->item)); break;
        case 1: value=fn_80178d1c(fn_80342a78(self->item)); break;
        }
        if(!value) self->disabled=1; else self->disabled=0;
    }
    return self->disabled;
}


