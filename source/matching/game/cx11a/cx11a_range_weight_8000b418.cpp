// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx11aVec3 {
 float x,y,z;
 Cx11aVec3() {}
 Cx11aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx11aVec3(const Cx11aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx11aVec3 scaled(float k) const {Cx11aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx11aVec3 plus(const Cx11aVec3 &o) const {Cx11aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx11aVec3 minus(const Cx11aVec3 &o) const {Cx11aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx11aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx11aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

// PPC32 actor position +0x10 and owner position +0x18; registry uses an ordinary pointer-vector header.
struct Cx11aActor {unsigned char unknown00[0x10];Cx11aVec3 position;};struct Cx11aRegistry {Cx11aActor **begin,**end,**capacity;};extern Cx11aRegistry *actors_804aa750;
static inline float distanceSquared(const Cx11aVec3 &a,const Cx11aVec3 &b){float x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;return x*x+y*y+z*z;}
struct Cx11aOwner {unsigned char unknown00[0x10];int index;unsigned char unknown14[4];Cx11aVec3 position;};extern "C" float root_802e82c0(float);
extern const float zero_80369c50[],one_80369c54[];
extern "C" float w3d_cx11a_range_weight_8000b418(Cx11aOwner *self,int index,float range){float zero=zero_80369c50[0],distance;if(range==zero)goto failed;{Cx11aActor *actor=*(Cx11aActor **)((char*)actors_804aa750->begin+(index<<2));distance=root_802e82c0(distanceSquared(self->position,actor->position));}if(distance<range)goto success;failed:return zero;success:return one_80369c54[0]-distance/range;}
