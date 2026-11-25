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

extern const float multiplier_80389a68[],center_80389a6c[],neutral_80389a70[];extern unsigned int seed_804aec54;extern "C" float random_80162bc8();
struct Cx11aRandomPair {unsigned char unknown00[0x3c];float first,second;unsigned char unknown44[0x28];int externalRandom;};
extern "C" void w3d_cx11a_random_pair_800dce48(Cx11aRandomPair *self,const float *base,const float *range,float scale){float r;if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389a68[0];}float d=((r-center_80389a6c[0])+(r-center_80389a6c[0]))*range[0];self->first=base[0]+d;if(range[1]<neutral_80389a70[0])self->second=base[1]+d;else{if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389a68[0];}self->second=((r-center_80389a6c[0])+(r-center_80389a6c[0]))*range[1]+base[1];}if(scale!=neutral_80389a70[0]){self->first*=scale;self->second*=scale;}}
