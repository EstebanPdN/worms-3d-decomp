// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx14aVec3 {
 float x,y,z;
 Cx14aVec3() {}
 Cx14aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx14aVec3(const Cx14aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx14aVec3 scaled(float k) const {Cx14aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx14aVec3 plus(const Cx14aVec3 &o) const {Cx14aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx14aVec3 minus(const Cx14aVec3 &o) const {Cx14aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx14aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx14aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};



extern const char direction_8036af98[],speed_8036afa8[];extern const float zero_8036afb4[];extern "C" int property_800fc270(const char **,float *);extern "C" float cos_802e86d4(float),sin_802e88ac(float);

extern "C" Cx14aVec3 *w3d_cx14a_wind_vector_8001a9a0(Cx14aVec3 *out){struct QueryWorkspace{const char *direction;float angle;const char *speedKey;float speed;unsigned reserved[4];};QueryWorkspace q;float zero=zero_8036afb4[0];q.direction=direction_8036af98;q.angle=zero;property_800fc270(&q.direction,&q.angle);q.speed=zero;q.speedKey=speed_8036afa8;property_800fc270(&q.speedKey,&q.speed);float x=cos_802e86d4(q.angle)*q.speed;float z=sin_802e88ac(q.angle)*q.speed;out->x=x;out->y=zero;out->z=z;return out;}
