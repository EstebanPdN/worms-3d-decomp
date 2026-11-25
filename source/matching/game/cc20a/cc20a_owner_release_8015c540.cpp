// Observed interface pointers at 96,100,104,108,112; names are structural.
struct Cc20aInterface {void **vtable;};
struct Cc20aOwner {void *vtable;char reserved[92];Cc20aInterface *held96,*held100,*held104,*held108,*held112;};
extern "C" char lbl_804111c8[];
extern "C" void fn_8015b630(Cc20aOwner*,int);
static inline void cc20a_release(Cc20aInterface *p){if(p)((void(*)(Cc20aInterface*))p->vtable[4])(p);}
static inline void cc20a_reset(Cc20aInterface *&p,Cc20aInterface *value){cc20a_release(p);p=value;}
extern "C" void w3d_cc20a_owner_release_8015c540(Cc20aOwner *self){
 self->vtable=lbl_804111c8;
 cc20a_reset(self->held96,0);cc20a_reset(self->held108,0);cc20a_reset(self->held100,0);
 cc20a_release(self->held112);cc20a_release(self->held108);cc20a_release(self->held104);cc20a_release(self->held100);cc20a_release(self->held96);
 fn_8015b630(self,0);
}