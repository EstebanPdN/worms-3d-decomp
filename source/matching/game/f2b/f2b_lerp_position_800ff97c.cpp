// Partial observed layouts; position, target and interpolation-factor roles are inferred. Plain assignment preserves the original word copy, while arithmetic results use explicit float copies.
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}Vec3&operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;return *this;}};
struct I{void**table;};struct Owner{char pad[28];I*iface;char gap[8];Vec3 position;char gap2[32];void*target;char gap3[4];void*factor;};
extern "C" const Vec3* target_80178ec4(void*);extern "C" float factor_80178df0(void*);
extern "C" void f2b_lerp_position_800ff97c(Owner*s){Vec3 target;target=*target_80178ec4(s->target);Vec3 step=(target-s->position)*factor_80178df0(s->factor);s->position+=step;((void(*)(I*,const Vec3*,int))s->iface->table[19])(s->iface,&s->position,0);}
