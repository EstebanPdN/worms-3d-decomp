// Original entry 0x80018ed0. Water.Level is the original property string.
// The Name wrapper's reserved field is inferred.
struct Interface {void **vt;};struct Array {void **begin,**end;};
extern "C" {extern Array *lbl_804aa750;extern float lbl_804aa760;extern char lbl_8036a8f4[];int fn_800fc1b0(const char**,Interface**);Interface* fn_80342a74(Interface*);float fn_80178df0(Interface*);void fn_80018f88(void*,int);
void w3d_f2a_update_water_80018ed0(){struct Handle {
 Handle(const Handle &);Interface *p;Handle():p(0){}} handle;struct Name{const char *p;int reserved;Name(const char *s):p(s){}} key(lbl_8036a8f4);fn_800fc1b0(&key.p,&handle.p);lbl_804aa760=fn_80178df0(fn_80342a74(handle.p));int count=lbl_804aa750->end-lbl_804aa750->begin;for(int i=0;i<count;++i)fn_80018f88(*(void**)((char*)lbl_804aa750->begin+(i<<2)),i);if(handle.p)((void(*)(Interface*))handle.p->vt[4])(handle.p);}}
