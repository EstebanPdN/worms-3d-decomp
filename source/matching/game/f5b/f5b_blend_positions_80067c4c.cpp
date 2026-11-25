// All names, types, layouts and roles are inferred. 
extern const float one_8037a1a0[];
extern "C" void*fn_80164fc8(int);
extern "C" char*fn_80165254();
extern "C" void fn_8015ab54(void*,float,float);
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}Vec3 operator+(const Vec3&o)const{Vec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}};
struct Owner{int v;Vec3 a,b;char pad[48];int handle;float fa,fb,fc,fd;};
extern "C" void f5b_blend_positions_80067c4c(Owner*s){void*p=fn_80164fc8(s->handle);if(p){Vec3 target;char*c=fn_80165254();typedef void(*Fill)(void*,int,Vec3*);((Fill)(*(void***)p)[11])(p,*(int*)(c+52),&target);s->b=target*s->fa+s->b*(one_8037a1a0[0]-s->fa);s->a=target*s->fb+s->a*(one_8037a1a0[0]-s->fb);fn_8015ab54(s,s->fc,s->fd);}}
