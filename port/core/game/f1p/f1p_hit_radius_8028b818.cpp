#include "w3d_ptr.h"
#line 1 "f1p_hit_radius_8028b818.cpp"
// Partial observed vector layouts and inferred radius semantics.
extern int mode_804abb4c;extern const float factor_803cfcbc[],zero_803cfcc0[];
extern "C" float fn_802e82c0(float);
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator*(const Vec3&o)const{Vec3 r;r.x=x*o.x;r.y=y*o.y;r.z=z*o.z;return r;}Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}Vec3 operator*=(const Vec3&o){Vec3 result(x*o.x,y*o.y,z*o.z);*this=result;return result;}float distance(const Vec3&o){float a=x-o.x,b=y-o.y,c=z-o.z;return fn_802e82c0(a*a+b*b+c*c);}};
struct I{Ptr32<Ptr32<void>> v;};struct Settings{char pad[20];Vec3 scale;};struct Owner{char pad[40];Ptr32<Settings> settings;char pad2[68];Ptr32<I> target;};
extern "C" Vec3 fn_802b22e4(Ptr32<void>);
extern "C" int w3d_hit_radius_8028b818(Ptr32<Owner> self,float x,float y){if(mode_804abb4c==1)return 0;Vec3 pos=fn_802b22e4((Ptr32<char>)self+28);Vec3 size(*((Ptr32<Ptr32<Vec3> (Ptr32<I>)>)self->target->v[27])(self->target));Vec3 radius(self->settings->scale);radius=radius*size;Vec3 point(x,y,pos.z);char unused[16];radius.x*=factor_803cfcbc[0];float distance=point.distance(pos);float zero=zero_803cfcc0[0];if(distance<zero)distance=-distance;if(radius.x<zero)radius.x=-radius.x;return distance<=radius.x;}


