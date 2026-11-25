#include "w3d_ptr.h"
#line 1 "cx16b_shared_clear_801a18f8.cpp"
/* Global owner reloads after callbacks are intentional: a release callback
   may change it. Empty-copy call and byte-distance update are observed. */
struct Cx16bSharedObject { Ptr32<Ptr32<void>> vtable; };
struct Cx16bSharedRange { Ptr32<Ptr32<Cx16bSharedObject>> begin; Ptr32<Ptr32<Cx16bSharedObject>> end; Ptr32<Ptr32<Cx16bSharedObject>> capacity; };
struct Cx16bSharedList { char pad[20]; Cx16bSharedRange values; Ptr32<Cx16bSharedObject> held; };
extern "C" {
extern Ptr32<Cx16bSharedList> lbl_804ab74c;
Ptr32<void> fn_802eee50(Ptr32<void>,Ptr32<const void>,...);
}
static inline void cx16b_shared_release(Ptr32<Cx16bSharedObject> p){if(p)((Ptr32<void (Ptr32<Cx16bSharedObject>)>)p->vtable[4])(p);}
extern "C" int w3d_cx16b_shared_clear_801a18f8()
{
    if(lbl_804ab74c){
        Ptr32<Ptr32<Cx16bSharedObject>> p=lbl_804ab74c->values.begin;
        Ptr32<Ptr32<Cx16bSharedObject>> end=lbl_804ab74c->values.end;
        for(;p!=end;++p)cx16b_shared_release(*p);
        Ptr32<Cx16bSharedList> owner=lbl_804ab74c;
        cx16b_shared_release(owner->held);
        Ptr32<Cx16bSharedList> current=lbl_804ab74c;
        owner->held=0;
        Ptr32<Cx16bSharedRange> range=&current->values;
        Ptr32<Ptr32<Cx16bSharedObject>> last=range->end;
        Ptr32<Ptr32<Cx16bSharedObject>> first=current->values.begin;
        unsigned bytes=(unsigned)w3d::H(last)-(unsigned)w3d::H(first);
        fn_802eee50(first,last,0);
        range->end=(Ptr32<Ptr32<Cx16bSharedObject>>)w3d::G(((unsigned)w3d::H(range->end)-bytes));
    }
    return 0;
}


