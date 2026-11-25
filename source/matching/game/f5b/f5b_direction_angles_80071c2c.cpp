// All names, types, layouts and roles are inferred.
extern const float zero_8037cac8[],one_8037cacc[],turn_8037cad0[];
extern "C" float fn_802e82c0(float);
extern "C" float fn_802e7c30(float);
extern "C" void fn_801a3eb0(const void*,int,void*);
struct Vec3{float x,y,z;void scale(float f){x*=f;y*=f;z*=f;}float norm2()const{return x*x+y*y+z*z;}};
extern "C" void f5b_direction_angles_80071c2c(char*s,const Vec3*v){Vec3 q=*v;Vec3 angles;float zero=zero_8037cac8[0];q.y=zero;float n=q.norm2();if(n!=zero){q.scale(one_8037cacc[0]/fn_802e82c0(n));float yaw=fn_802e7c30(q.x);if(v->z<zero)yaw=turn_8037cad0[0]-yaw;angles.y=yaw;angles.x=-fn_802e7c30(v->y);angles.z=zero;}fn_801a3eb0(&angles,2,s+124);}
