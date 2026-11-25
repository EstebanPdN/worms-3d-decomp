// Observed PPC32 vector operations; point, gate and flag roles are inferred.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
Vec3 plus(const Vec3&o)const{Vec3 v;v.x=x+o.x;v.y=y+o.y;v.z=z+o.z;return v;}
Vec3 minus(const Vec3&o)const{Vec3 v;v.x=x-o.x;v.y=y-o.y;v.z=z-o.z;return v;}
float dot(const Vec3&o)const{return x*o.x+y*o.y+z*o.z;}
float squared()const{return x*x+y*y+z*z;}
};
extern int enabled_804aaef8,flag_804aaefc;
extern Vec3 point_80448c90;
extern "C" void f1b_planar_distance_flag_800ed860(Vec3*p,Vec3*d){if(enabled_804aaef8 && !flag_804aaefc){Vec3 a=point_80448c90.minus(*p);a.y=0.0f;Vec3 b=point_80448c90.minus(p->plus(*d));b.y=0.0f;if(b.squared()>a.squared())flag_804aaefc=1;}}
