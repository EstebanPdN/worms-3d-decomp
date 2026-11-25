// All names, types, layouts and roles are inferred.

struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}Vec3 operator+(const Vec3&o)const{Vec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}};
struct Queue_80003300{Queue_80003300();char gap[44];int count;};
extern "C" void fn_800033d8(Queue_80003300*);
struct Ref{void assign(Queue_80003300*q){value=q;}int pad;Queue_80003300*value;void reset(){fn_800033d8(value);value=0;}};
extern "C" void fn_800033d8(Queue_80003300*);

extern "C" const Vec3*fn_80003e78(void*);
extern "C" void fn_80003424(Queue_80003300*,const Vec3*,int);
extern "C" void fn_80003710(Queue_80003300*,float);
extern "C" void fn_800108b8(void*);
struct Target{char gap[16];Vec3 p;};extern Target***table_804aa750;
extern const float half_8036a3e4[],duration_8036a3e8[],rise_8036a3ec[];
struct Owner{char pad[16];int index;char gap[56];void*current;Ref queue;};
extern "C" void f5b_build_two_steps_80011d40(Owner*s){s->queue.reset();Vec3 a(*fn_80003e78(s->current));Vec3 b((*(Target**)((char*)(*table_804aa750)+(s->index<<2)))->p);Queue_80003300*q=new Queue_80003300;s->queue.assign(q);q->count++;float half=half_8036a3e4[0];Vec3 p=a+(a-b)*half;fn_80003424(q,&p,0);fn_80003710(q,duration_8036a3e8[0]);float rise=rise_8036a3ec[0];Vec3 next=(a+b)*half;next.y+=rise;fn_80003424(q,&next,5);fn_800108b8(s);}
