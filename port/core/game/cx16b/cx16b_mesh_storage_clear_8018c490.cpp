#include "w3d_ptr.h"
#line 1 "cx16b_mesh_storage_clear_8018c490.cpp"
/* Observed release and clear order for the mesh-like owner. Callback return
   value is preserved independently from cleanup; global count decrements. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
struct Cx16bStorageIface { Ptr32<Ptr32<void>> vtable; };
extern "C" {
int fn_8017b348(Ptr32<void>);
extern int lbl_804ab6b0;
Ptr32<void> fn_802eee50(Ptr32<void>,Ptr32<const void>,...);
}
static inline void cx16b_storage_release(Ptr32<Cx16bStorageIface> p){if(p)((Ptr32<void (Ptr32<Cx16bStorageIface>)>)p->vtable[4])(p);}
extern "C" int w3d_cx16b_mesh_storage_clear_8018c490(Ptr32<char> self)
{
    Ptr32<void> zero=0;
    int result=fn_8017b348(self);
    Ptr32<Cx16bStorageIface> manager=FIELD(self,Cx16bStorageIface *,116);
    ((Ptr32<void (Ptr32<Cx16bStorageIface>, Ptr32<void>)>)manager->vtable[15])(manager,self);
    Ptr32<Cx16bStorageIface> held=FIELD(self,Cx16bStorageIface *,176);
    --lbl_804ab6b0;
    cx16b_storage_release(held);
    Ptr32<Cx16bStorageIface> next=FIELD(self,Cx16bStorageIface *,168);
    FIELD(self,void *,176)=zero;
    cx16b_storage_release(next);
    next=FIELD(self,Cx16bStorageIface *,172);
    FIELD(self,void *,168)=zero;
    cx16b_storage_release(next);
    FIELD(self,void *,172)=zero;
    Ptr32<char> first=FIELD(self,char *,180);
    Ptr32<char> range=self+180;
    Ptr32<char> end=FIELD(range,char *,4);
    unsigned bytes=(unsigned)w3d::H(end)-(unsigned)w3d::H(first);
    fn_802eee50(first,end,0);
    FIELD(range,char *,4)=FIELD(range,char *,4)-bytes;
    return result;
}


