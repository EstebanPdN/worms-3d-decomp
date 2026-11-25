// All types, names, field meanings and trajectory roles are inferred.
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}};
struct Trajectory_801181bc{Trajectory_801181bc();char data[184];};
extern "C" void destroy_80118200(Trajectory_801181bc*,int),set_a_80118288(Trajectory_801181bc*,const Vec3*),set_b_80118230(Trajectory_801181bc*,const Vec3*),set_c_80118268(Trajectory_801181bc*,const Vec3*);
extern "C" int height_80118a5c(Trajectory_801181bc*,Vec3*,int,float);
struct Owner{char pad[312];Vec3 target;char pad2[236];Vec3 position;int angle;char pad3[100];Vec3 velocity,acceleration;char pad4[60];int state;};
extern void*queue_804b1754;extern "C" void reset_8015286c(Owner*);extern "C" void*allocate_801613f0(void*,int),*construct_80131b50(void*,int);extern "C" int post_8016239c(void*);
extern "C" void f6b_height_step_80151d64(Owner*s,Vec3*out){if((unsigned)(s->state-6)<2){Trajectory_801181bc t;set_a_80118288(&t,&s->acceleration);set_b_80118230(&t,&s->position);set_c_80118268(&t,&s->velocity);Vec3 hit;if(height_80118a5c(&t,&hit,1,s->target.y)){Vec3 d=s->target-hit;*out=d;}destroy_80118200(&t,2);}int n=s->state;if(n!=6 && n!=2 && n!=3 && n!=5 && n!=4 && n!=7){reset_8015286c(s);post_8016239c(construct_80131b50(allocate_801613f0(queue_804b1754,12),5));}}
