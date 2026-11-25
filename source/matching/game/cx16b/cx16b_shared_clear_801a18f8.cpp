/* Global owner reloads after callbacks are intentional: a release callback
   may change it. Empty-copy call and byte-distance update are observed. */
struct Cx16bSharedObject { void **vtable; };
struct Cx16bSharedRange { Cx16bSharedObject **begin,**end,**capacity; };
struct Cx16bSharedList { char pad[20]; Cx16bSharedRange values; Cx16bSharedObject *held; };
extern "C" {
extern Cx16bSharedList *lbl_804ab74c;
void *fn_802eee50(void *,const void *,...);
}
static inline void cx16b_shared_release(Cx16bSharedObject *p){if(p)((void(*)(Cx16bSharedObject *))p->vtable[4])(p);}
extern "C" int w3d_cx16b_shared_clear_801a18f8()
{
    if(lbl_804ab74c){
        Cx16bSharedObject **p=lbl_804ab74c->values.begin;
        Cx16bSharedObject **end=lbl_804ab74c->values.end;
        for(;p!=end;++p)cx16b_shared_release(*p);
        Cx16bSharedList *owner=lbl_804ab74c;
        cx16b_shared_release(owner->held);
        Cx16bSharedList *current=lbl_804ab74c;
        owner->held=0;
        Cx16bSharedRange *range=&current->values;
        Cx16bSharedObject **last=range->end;
        Cx16bSharedObject **first=current->values.begin;
        unsigned bytes=(unsigned)last-(unsigned)first;
        fn_802eee50(first,last,0);
        range->end=(Cx16bSharedObject **)((unsigned)range->end-bytes);
    }
    return 0;
}
