// Original horizontal airstrike direction normalization and three property writes.
struct cc27a_Vec19b8 {float x,y,z;cc27a_Vec19b8(float a,float b,float c){x=a;y=b;z=c;}float norm()const;void normalize();};
extern "C" float cc27a_sqrt_802e82c0(float);
inline float cc27a_Vec19b8::norm()const{return cc27a_sqrt_802e82c0(x*x+y*y+z*z);}
inline void cc27a_Vec19b8::normalize(){float scale=1.0f/norm();x*=scale;y*=scale;z*=scale;}
struct cc27a_Strike19b8 {unsigned int unknown;int state;char unknown8[12];cc27a_Vec19b8 direction;};
extern char cc27a_dir_8036c0a0[],cc27a_up_8036c0b4[],cc27a_air_8036c0c8[];
extern "C" int cc27a_property_800fc5dc(const char**,cc27a_Vec19b8*);
extern "C" int cc27a_planner_airstrike_direction_800219b8(cc27a_Strike19b8*self){
 cc27a_Vec19b8 up(0.0f,1.0f,0.0f);
 self->direction.y=0.0f;
 if(self->direction.x==0.0f && self->direction.z==0.0f)self->direction=cc27a_Vec19b8(1.0f,0.0f,0.0f);
 self->direction.normalize();
 const char*direction=cc27a_dir_8036c0a0;cc27a_property_800fc5dc(&direction,&self->direction);
 const char*upName=cc27a_up_8036c0b4;cc27a_property_800fc5dc(&upName,&up);
 const char*air=cc27a_air_8036c0c8;cc27a_property_800fc5dc(&air,&self->direction);
 self->state=1;return 0;
}