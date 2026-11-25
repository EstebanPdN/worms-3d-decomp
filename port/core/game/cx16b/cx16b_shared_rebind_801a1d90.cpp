#include "w3d_ptr.h"
#line 1 "cx16b_shared_rebind_801a1d90.cpp"
/* Pointer identity gate uses the original global object. The callback list
   has its next link at +32; all virtual slot offsets are instruction facts. */
struct Cx16bSharedIface { Ptr32<Ptr32<void>> vtable; };
struct Cx16bSharedOwner { char pad[32]; Ptr32<Cx16bSharedIface> held; };
struct Cx16bNotifyLink { char pad[32]; Ptr32<Cx16bNotifyLink> next; };
extern "C" {
extern Cx16bSharedIface lbl_80365094[];
extern Ptr32<Cx16bNotifyLink> lbl_804ab750;
void fn_801a2754(Ptr32<Cx16bNotifyLink>,Ptr32<Cx16bSharedIface>,Ptr32<void>);
int w3d_cx16b_shared_rebind_801a1d90(Ptr32<Cx16bSharedOwner> self,Ptr32<Cx16bSharedIface> source)
{
    if(source==lbl_80365094){
        Ptr32<Cx16bSharedIface> replacement=((Ptr32<Ptr32<Cx16bSharedIface> (Ptr32<Cx16bSharedIface>)>)lbl_80365094[0].vtable[22])(source);
        if(replacement)((Ptr32<void (Ptr32<Cx16bSharedIface>)>)replacement->vtable[3])(replacement);
        Ptr32<Cx16bSharedIface> old=self->held;
        if(old)((Ptr32<void (Ptr32<Cx16bSharedIface>)>)old->vtable[4])(old);
        Ptr32<Cx16bNotifyLink> link=lbl_804ab750;
        self->held=replacement;
        for(;link;link=link->next)fn_801a2754(link,source,0);
    }
    return 0;
}
}


