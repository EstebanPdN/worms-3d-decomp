#include "w3d_ptr.h"
#line 1 "camera.cpp"
inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
typedef struct Ref Ref;
typedef struct Vtable { Ptr32<void> a[3]; Ptr32<void (Ptr32<Ref>)> retain; Ptr32<void (Ptr32<Ref>)> release; } Vtable;
struct Ref { Ptr32<Vtable> v; };
struct Fields { int a,b,c; Fields() { c=0; b=0; a=0; } };
typedef struct Camera { int pad; Fields fields; int d; Ptr32<Ref> mag; Ptr32<Ref> radius; Ptr32<Ref> duration; } Camera;
extern char lbl_80373c3c[], lbl_80373c58[], lbl_80373c74[];
extern "C" int fn_800fc1b0(Ptr32<Ptr32<char>>, Ptr32<Ptr32<Ref>>);
struct Name { Ptr32<char> text; template <class W3dU> Name(Ptr32<W3dU> w3d_p) : Name((char *)w3d_p.get()) {}
 Name(char *p):text(p) {} };
struct Holder {
 Holder(const Holder &); Ptr32<Ref> p; Holder():p(0) {} };
extern "C" Ptr32<Ref> fn_80342a74(Ptr32<Ref>);
extern "C" Ptr32<Camera> terra_only_a11_camera_80036218(Ptr32<Camera> p) {
 Ptr32<Ref> r;
 new (&p->fields) Fields; p->mag=0; p->radius=0; p->duration=0;
 Holder local; Ptr32<Ptr32<Ref>> q=&local.p; Name s1(lbl_80373c3c);
 fn_800fc1b0(&s1.text,q); r=fn_80342a74(q[0]); if(r) r->v->retain(r); if(p->mag) p->mag->v->release(p->mag); p->mag=r;
 Name s2(lbl_80373c58); fn_800fc1b0(&s2.text,q); r=fn_80342a74(q[0]); if(r) r->v->retain(r); if(p->radius) p->radius->v->release(p->radius); p->radius=r;
 Name s3(lbl_80373c74); fn_800fc1b0(&s3.text,q); r=fn_80342a74(q[0]); if(r) r->v->retain(r); if(p->duration) p->duration->v->release(p->duration); p->duration=r;
 p->d=0; if(q[0]) q[0]->v->release(q[0]); return p;
}


