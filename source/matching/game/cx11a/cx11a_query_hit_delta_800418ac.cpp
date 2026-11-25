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

// PPC32 query record stride is 0x20; global pointer slot is outside the small-data window.
struct Cx11aQueryRecord {Cx11aVec3 position;float radius;unsigned int unknown[4];};extern Cx11aQueryRecord *records_804273ec[];extern Cx11aVec3 origin_80427408[],direction_80427414[],output_80427450[];extern int tick_804b1790;extern unsigned short hit_804aa95e;extern "C" unsigned int swept_800400f0();extern unsigned int(*method_804b17b4)();
extern "C" Cx11aVec3 *w3d_cx11a_query_hit_delta_800418ac(){if(method_804b17b4==swept_800400f0)output_80427450[0]=origin_80427408[0].plus(direction_80427414[0].scaled((float)tick_804b1790)).minus(((const Cx11aQueryRecord*)((char*)records_804273ec[0]+((unsigned int)hit_804aa95e<<5)))->position);return output_80427450;}
