// All roles and layouts inferred from original accesses.
struct F7OrbitVec{float x,y,z;F7OrbitVec(){}F7OrbitVec(const F7OrbitVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}F7OrbitVec operator*(float k)const{F7OrbitVec r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}};
struct F7OrbitConfig{char p[68];void*angle,*scale,*mode;};extern F7OrbitConfig*config_804aaecc;extern const float zero_8038a5a0[];
extern "C" void*cast_80342a74(void*),*cast_80342a78(void*);extern "C" float get_80178df0(void*),cos_802e86d4(float),sin_802e88ac(float);extern "C" int get_80178d1c(void*);
extern "C" void f7b_orbit_vector_800e5a70(F7OrbitVec*out){float angle=get_80178df0(cast_80342a74(config_804aaecc->angle));F7OrbitVec direction;direction.x=cos_802e86d4(angle);direction.y=zero_8038a5a0[0];direction.z=sin_802e88ac(angle);float scale=get_80178df0(cast_80342a74(config_804aaecc->scale));switch(get_80178d1c(cast_80342a78(config_804aaecc->mode))){case 0:*out=direction*scale;break;case 1:*out=(direction*scale)*scale;break;}}
