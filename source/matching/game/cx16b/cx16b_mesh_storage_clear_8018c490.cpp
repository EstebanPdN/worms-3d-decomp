/* Observed release and clear order for the mesh-like owner. Callback return
   value is preserved independently from cleanup; global count decrements. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct Cx16bStorageIface { void **vtable; };
extern "C" {
int fn_8017b348(void *);
extern int lbl_804ab6b0;
void *fn_802eee50(void *,const void *,...);
}
static inline void cx16b_storage_release(Cx16bStorageIface *p){if(p)((void(*)(Cx16bStorageIface *))p->vtable[4])(p);}
extern "C" int w3d_cx16b_mesh_storage_clear_8018c490(char *self)
{
    void *zero=0;
    int result=fn_8017b348(self);
    Cx16bStorageIface *manager=FIELD(self,Cx16bStorageIface *,116);
    ((void(*)(Cx16bStorageIface *,void *))manager->vtable[15])(manager,self);
    Cx16bStorageIface *held=FIELD(self,Cx16bStorageIface *,176);
    --lbl_804ab6b0;
    cx16b_storage_release(held);
    Cx16bStorageIface *next=FIELD(self,Cx16bStorageIface *,168);
    FIELD(self,void *,176)=zero;
    cx16b_storage_release(next);
    next=FIELD(self,Cx16bStorageIface *,172);
    FIELD(self,void *,168)=zero;
    cx16b_storage_release(next);
    FIELD(self,void *,172)=zero;
    char *first=FIELD(self,char *,180);
    char *range=self+180;
    char *end=FIELD(range,char *,4);
    unsigned bytes=(unsigned)end-(unsigned)first;
    fn_802eee50(first,end,0);
    FIELD(range,char *,4)=FIELD(range,char *,4)-bytes;
    return result;
}
