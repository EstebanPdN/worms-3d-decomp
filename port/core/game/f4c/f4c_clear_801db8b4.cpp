#include "w3d_ptr.h"
#line 1 "f4c_clear_801db8b4.cpp"
// Partial list layout and virtual-method roles are inferred from original offsets.
struct List {unsigned count,capacity;
Ptr32<Ptr32<void>> items;
};
extern "C" void fn_80210dd8(Ptr32<List>,Ptr32<Ptr32<void>>,Ptr32<Ptr32<void>>);
inline void call(Ptr32<void> p,unsigned off){(*(Ptr32<Ptr32<void (Ptr32<void>)>>)(*(Ptr32<Ptr32<char>>)p+off))(p);
}extern "C" int f4c_clear_801db8b4(Ptr32<char> self){(*(Ptr32<Ptr32<void (Ptr32<void>)>>)(*(Ptr32<Ptr32<char>>)self+32))(self);
(*(Ptr32<Ptr32<int (Ptr32<void>, int)>>)(*(Ptr32<Ptr32<char>>)self+140))(self,1);
call(self,88);
if(*(Ptr32<unsigned int>)(self+48)){Ptr32<List> list=(Ptr32<List>)(self+48);
do{Ptr32<Ptr32<void>> first=list->items;
call(*first,24);
fn_80210dd8(list,first,first+1);
}while(*(Ptr32<unsigned int>)(self+48));
}Ptr32<void> old=*(Ptr32<Ptr32<void>>)(self+172);
if(old)call(old,16);
*(Ptr32<Ptr32<void>>)(self+172)=0;
return 0;
}

