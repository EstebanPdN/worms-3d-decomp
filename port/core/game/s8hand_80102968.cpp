#include "w3d_ptr.h"
#line 1 "s8hand_80102968.cpp"
struct s8_ItemOwner { char pad0[40]; Ptr32<void> items; };
extern "C" int fn_800ffca4(Ptr32<void>,int,Ptr32<int>);
extern "C" int fn_800ffb58(Ptr32<void>,int);
extern "C" int s8_apply_item_80102968(Ptr32<s8_ItemOwner> self,int key,int value) {
    int item;
    if(!self->items) return (int)0x80004005;
    int status=fn_800ffca4(self->items,key,&item);
    if(status>=0) { fn_800ffb58((Ptr32<void>)w3d::G(item),value); status=0; }
    return status;
}


