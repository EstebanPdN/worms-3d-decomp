// All roles, types and layouts are inferred from observed accesses.
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}void operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;}};
inline float magnitude(float v){union{float f;unsigned i;}u;u.f=v;u.i&=0x7fffffff;return u.f;}
extern const float target_803772a8[],up_803772ac[],down_803772b0[],step_803772b4[],height_803772b8[];
struct Owner{char p[32];int index;int pad;Vec3 position,velocity;char p2[120];void*height;};
struct Message{unsigned short id,pad;void*value;};extern void*queue_804b1754;extern int name_804ad360;extern char value_8040db38[],property_80377118[];
extern "C" float get_80178df0(void*);extern "C" int write_800fc3b0(const char**,int);extern "C" Message*allocate_801613f0(void*,int);extern "C" unsigned int name_8015f5a0(int*,int);extern "C" void finish_8015fd1c(Owner*);
extern "C" int post_8016239c(Message*);
extern "C" void f6b_crate_step_8004c138(Owner*s){float current=s->velocity.y;if(current<target_803772a8[0])s->velocity.y=(target_803772a8[0]-current)*up_803772ac[0]+current;else if(current>target_803772a8[0])s->velocity.y=current-magnitude(target_803772a8[0]-current)*down_803772b0[0];s->position+=s->velocity*step_803772b4[0];if(s->position.y<get_80178df0(s->height)+height_803772b8[0]){const char*key=property_80377118;write_800fc3b0(&key,s->index);Message*m=allocate_801613f0(queue_804b1754,8);m->id=name_8015f5a0(&name_804ad360,1);m->value=value_8040db38;post_8016239c(m);finish_8015fd1c(s);}}
