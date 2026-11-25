#include "w3d_ptr.h"
#line 1 "cx14b_child_callbacks_apply_801fc5f4.cpp"

// PPC32: owner slot +32 returns pointer array and writes count; child slot +24 accepts zero.
struct Interface{Ptr32<Ptr32<void>> table;};
extern "C" int w3d_cx14b_child_callbacks_apply_801fc5f4(Ptr32<Interface> self){unsigned count;int result=0;unsigned i=0;Ptr32<Ptr32<Interface>> returned=((Ptr32<Ptr32<Ptr32<Interface>> (Ptr32<Interface>, Ptr32<unsigned int>)>)self->table[8])(self,&count);if(i<count){Ptr32<Ptr32<Interface>> items=returned;do{Ptr32<Interface> p=*items++;if(p){int r=((Ptr32<int (Ptr32<Interface>, int)>)p->table[6])(p,0);if(r<0)result=r;}++i;}while(i<count);}return result;}




