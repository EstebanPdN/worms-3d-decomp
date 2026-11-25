#include "w3d_ptr.h"
#line 1 "f4b_normalized_snapshot_80067770.cpp"
// Observed message allocation, global vector snapshot and normalization; semantic message and direction names are inferred.
extern "C" float sqrt_802e82c0(float);extern const float zero_8037a0ec[],one_8037a0f0[];
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}float length2()const{return x*x+y*y+z*z;}void scale(float f){float a=x*f,b=y*f,c=z*f;x=a;y=b;z=c;}void setZ(float f){z=f;}void setY(float f){y=f;}void setX(float f){x=f;}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Message{unsigned short id;unsigned short pad;Ptr32<void> value;};extern Ptr32<void> queue_804b1754;extern int ready_804b1784;extern int name_804ad5d4;extern char value_8040db38[];extern Vec3 vector_8043ae38;
extern "C" Ptr32<Message> allocate_801613f0(Ptr32<void>,int);extern "C" unsigned int name_8015f5a0(Ptr32<int>,int);extern "C" int post_8016239c(Ptr32<Message>);extern "C" void refresh_800bd920();
extern "C" Vec3 f4b_normalized_snapshot_80067770(){Ptr32<Message> m=allocate_801613f0(queue_804b1754,8);m->id=name_8015f5a0(&name_804ad5d4,1);m->value=value_8040db38;post_8016239c(m);if(!ready_804b1784)refresh_800bd920();Vec3 v;v=vector_8043ae38;if(v.length2()>zero_8037a0ec[0])v.scale(one_8037a0f0[0]/sqrt_802e82c0(v.length2()));else {float one=one_8037a0f0[0];v.x=zero_8037a0ec[0];v.setZ(zero_8037a0ec[0]);v.setY(one);}return v;}


