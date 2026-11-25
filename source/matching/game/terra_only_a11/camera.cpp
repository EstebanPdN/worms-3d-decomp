inline void *operator new(unsigned int, void *p) { return p; }
typedef struct Ref Ref;
typedef struct Vtable { void *a[3]; void (*retain)(Ref *); void (*release)(Ref *); } Vtable;
struct Ref { Vtable *v; };
struct Fields { int a,b,c; Fields() { c=0; b=0; a=0; } };
typedef struct Camera { int pad; Fields fields; int d; Ref *mag,*radius,*duration; } Camera;
extern char lbl_80373c3c[], lbl_80373c58[], lbl_80373c74[];
extern "C" int fn_800fc1b0(char **, Ref **);
struct Name { char *text; Name(char *p):text(p) {} };
struct Holder {
 Holder(const Holder &); Ref *p; Holder():p(0) {} };
extern "C" Ref *fn_80342a74(Ref *);
extern "C" Camera *terra_only_a11_camera_80036218(Camera *p) {
 Ref *r;
 new (&p->fields) Fields; p->mag=0; p->radius=0; p->duration=0;
 Holder local; Ref **q=&local.p; Name s1(lbl_80373c3c);
 fn_800fc1b0(&s1.text,q); r=fn_80342a74(q[0]); if(r) r->v->retain(r); if(p->mag) p->mag->v->release(p->mag); p->mag=r;
 Name s2(lbl_80373c58); fn_800fc1b0(&s2.text,q); r=fn_80342a74(q[0]); if(r) r->v->retain(r); if(p->radius) p->radius->v->release(p->radius); p->radius=r;
 Name s3(lbl_80373c74); fn_800fc1b0(&s3.text,q); r=fn_80342a74(q[0]); if(r) r->v->retain(r); if(p->duration) p->duration->v->release(p->duration); p->duration=r;
 p->d=0; if(q[0]) q[0]->v->release(q[0]); return p;
}
