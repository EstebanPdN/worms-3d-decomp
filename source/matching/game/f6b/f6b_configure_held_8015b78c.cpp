// Observed ownership and configuration; names and layouts are inferred.
struct Interface{void**vtable;void retain(){((void(*)(Interface*))vtable[3])(this);}void release(){((void(*)(Interface*))vtable[4])(this);}void set(unsigned slot,const void*p){((void(*)(Interface*,const void*))vtable[slot])(this,p);}};
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c){x=a;y=b;z=c;}Vec3&set(float a,float b,float c){x=a;y=b;z=c;return *this;}void setY(float f){y=f;}void setZ(float f){z=f;}};
extern const float x_803a42e4[],y_803a42e8[],z_803a42ec[],zero_803a42f0[],one_803a42f4[],v_803a42f8[],a_803a42fc[],c_803a4300[],b_803a4304[],d_803a4308[];
extern char service_804138c0[];extern "C" Interface*lookup_8020b680(void*);
struct Owner{char pad[48];Interface*value;};struct Config{float a,b,c,d,e,f;int g;};
extern "C" void f6b_configure_held_8015b78c(Owner*s){Interface*p=lookup_8020b680(service_804138c0);if(p)p->retain();if(s->value)s->value->release();s->value=p;float x=x_803a42e4[0],y=y_803a42e8[0],z=z_803a42ec[0];Vec3 v;((int(*)(Interface*,const Vec3&))p->vtable[11])(p,v.set(x,y,z));float zero=zero_803a42f0[0];((void(*)(Interface*,const Vec3&))s->value->vtable[12])(s->value,v.set(zero,zero,zero));float one=one_803a42f4[0];((void(*)(Interface*,const Vec3&))s->value->vtable[13])(s->value,v.set(zero,one,zero));Config q;q.g=0;q.f=v_803a42f8[0];q.e=one;q.a=a_803a42fc[0];q.c=c_803a4300[0];q.b=b_803a4304[0];q.d=d_803a4308[0];s->value->set(10,&q);// Original frame reserves sixteen further bytes; their original purpose is unknown.
}
