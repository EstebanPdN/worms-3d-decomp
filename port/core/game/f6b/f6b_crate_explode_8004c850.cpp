#include "w3d_ptr.h"
#line 1 "f6b_crate_explode_8004c850.cpp"
// All types, field layouts and roles are inferred from observed accesses and strings.
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}};
struct Owner{char p[32];int index;int pad;Vec3 position;char p2[12];float offset;char p3[56];int used;};
extern "C" int read_800fc270(Ptr32<Ptr32<const char>>,Ptr32<float>);struct Property{Ptr32<const char> name;float value;template <class W3dU> Property(Ptr32<W3dU> w3d_p) : Property((const char *)w3d_p.get()) {}
 Property(const char*n){name=n;read_800fc270(&name,&value);}};
extern char a_80377360[],b_8037737c[],c_80377394[],d_803773ac[],e_803773c4[],effect_803773d8[],sound_803773f0[],index_80377118[],value_8040db38[];extern const float intensity_803773fc[];
struct Interface{Ptr32<Ptr32<void>> vtable;};struct Context{char p[108];Ptr32<Interface> audio;};extern Ptr32<Context> context_804b1788;extern Ptr32<void> queue_804b1754;extern int name_804ad350;
struct Message{unsigned short id,pad;Ptr32<void> value;};extern "C" Ptr32<Message> allocate_801613f0(Ptr32<void>,int);extern "C" Ptr32<void> construct_800666b4(Ptr32<void>,Ptr32<const Vec3>,Ptr32<const Vec3>,float,float,float,float,float);extern "C" int post_8016239c(Ptr32<void>);extern "C" int effect_800e5ca4(Ptr32<const Vec3>,Ptr32<const char>,int,float);extern "C" int write_800fc3b0(Ptr32<Ptr32<const char>>,int);extern "C" unsigned int name_8015f5a0(Ptr32<int>,int);extern "C" void finish_8015fd1c(Ptr32<Owner>);
extern "C" void f6b_crate_explode_8004c850(Ptr32<Owner> s){if(!s->used){s->used=1;Vec3 p(s->position);p.y-=s->offset;Ptr32<const char> a=a_80377360;float av;read_800fc270(&a,&av);Ptr32<const char> b=b_8037737c;float bv;read_800fc270(&b,&bv);Ptr32<const char> c=c_80377394;float cv;read_800fc270(&c,&cv);Ptr32<const char> d=d_803773ac;float dv;read_800fc270(&d,&dv);Ptr32<const char> e=e_803773c4;float ev;read_800fc270(&e,&ev);post_8016239c(construct_800666b4(allocate_801613f0(queue_804b1754,52),&s->position,&p,av,bv,cv,dv,ev));effect_800e5ca4(&s->position,effect_803773d8,0,intensity_803773fc[0]);Ptr32<Interface> audio=context_804b1788->audio;if(audio)((Ptr32<void (Ptr32<Interface>, Ptr32<const char>, Ptr32<const Vec3>)>)audio->vtable[24])(audio,sound_803773f0,&s->position);Ptr32<const char> key=index_80377118;write_800fc3b0(&key,s->index);Ptr32<Message> m=allocate_801613f0(queue_804b1754,8);m->id=name_8015f5a0(&name_804ad350,1);m->value=value_8040db38;post_8016239c(m);finish_8015fd1c(s);}}


