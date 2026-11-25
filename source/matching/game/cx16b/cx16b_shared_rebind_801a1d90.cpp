/* Pointer identity gate uses the original global object. The callback list
   has its next link at +32; all virtual slot offsets are instruction facts. */
struct Cx16bSharedIface { void **vtable; };
struct Cx16bSharedOwner { char pad[32]; Cx16bSharedIface *held; };
struct Cx16bNotifyLink { char pad[32]; Cx16bNotifyLink *next; };
extern "C" {
extern Cx16bSharedIface lbl_80365094[];
extern Cx16bNotifyLink *lbl_804ab750;
void fn_801a2754(Cx16bNotifyLink *,Cx16bSharedIface *,void *);
int w3d_cx16b_shared_rebind_801a1d90(Cx16bSharedOwner *self,Cx16bSharedIface *source)
{
    if(source==lbl_80365094){
        Cx16bSharedIface *replacement=((Cx16bSharedIface*(*)(Cx16bSharedIface *))lbl_80365094[0].vtable[22])(source);
        if(replacement)((void(*)(Cx16bSharedIface *))replacement->vtable[3])(replacement);
        Cx16bSharedIface *old=self->held;
        if(old)((void(*)(Cx16bSharedIface *))old->vtable[4])(old);
        Cx16bNotifyLink *link=lbl_804ab750;
        self->held=replacement;
        for(;link;link=link->next)fn_801a2754(link,source,0);
    }
    return 0;
}
}
