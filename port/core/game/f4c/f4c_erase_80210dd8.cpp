#include "w3d_ptr.h"
#line 1 "f4c_erase_80210dd8.cpp"
// List layout, interface release role and erase name are inferred from original instructions.
struct List {unsigned count,capacity;
Ptr32<Ptr32<void>> items;
};
extern "C" Ptr32<void> fn_802eefe0(Ptr32<void>,int,unsigned);
inline void release(Ptr32<void> p){(*(Ptr32<Ptr32<void (Ptr32<void>)>>)(*(Ptr32<Ptr32<char>>)p+16))(p);
}extern "C" void f4c_erase_80210dd8(Ptr32<List> self,Ptr32<Ptr32<void>> first,Ptr32<Ptr32<void>> last){unsigned removed=last-first;
Ptr32<Ptr32<void>> end=self->items+self->count;
unsigned i=0;
if(i<removed){Ptr32<Ptr32<void>> cursor=first;
do{Ptr32<void> p=*cursor++;
if(p)release(p);
++i;
}while(i<removed);
}unsigned count=end-last;
Ptr32<Ptr32<void>> source=first+removed;
for(i=0;
i<count;
++i)first[i]=source[i];
fn_802eefe0(first+count,0,removed*4);
self->count-=removed;
}

