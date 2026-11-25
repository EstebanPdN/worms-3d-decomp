// Observed vector and virtual-call operations. Position, direction and rise roles are inferred.
extern "C" float sqrt_802e82c0(float);
extern const float one_80377880[],rise_80377884[];
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}float length2()const{return x*x+y*y+z*z;}void operator*=(float f){x*=f;y*=f;z*=f;}void operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;}};
struct Owner{char pad[96];Vec3 position;};struct Service{void**vt;};struct Context{char pad[48];Service*service;};extern Context*context_804b1788;
extern "C" void f4b_offset_position_8004eb34(Owner*s,const Vec3*in){s->position=*in;Service*p=context_804b1788->service;Vec3 from(*((Vec3*(*)(Service*))p->vt[14])(p));Vec3 d=from-*in;d*=one_80377880[0]/sqrt_802e82c0(d.length2());s->position+=d;s->position.y+=rise_80377884[0];}
