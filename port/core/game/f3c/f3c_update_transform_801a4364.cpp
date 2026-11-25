#include "w3d_ptr.h"
#line 1 "f3c_update_transform_801a4364.cpp"
// Structural names, math representations, and partial layouts inferred from original instructions.
struct Vec3 {float x,y,z;inline void init(float f){x=f;y=f;z=f;}};
struct Matrix {float values[9];Vec3 pos;};
struct Tag {unsigned short a,b;unsigned char word[4];inline int dirty(){return word[0]&2;}inline void clear(){word[0]&=253;}};
struct Node {Ptr32<void> vtable;Tag tag;unsigned pad[2];Matrix transform;Vec3 angles,extra,position;unsigned mode;Vec3 scale,pivot;};
struct Service {unsigned pad[6];Ptr32<char> table;};
struct Global{unsigned pad[8];unsigned selector;};
extern Ptr32<Global> lbl_80363938[];
extern const float lbl_803a9c1c[];
extern "C" void fn_801a3eb0(Ptr32<void>,unsigned,Ptr32<Matrix>);
extern "C" void fn_801f7854(Ptr32<Matrix>,float,float,float);
extern "C" void fn_801f77f4(Ptr32<Matrix>,float,float,float);
extern "C" void fn_801f6298(Ptr32<Matrix>,float,float,float);
inline void update(Ptr32<Matrix> temp,Ptr32<Node> self,float zero){temp->pos.init(zero);
fn_801a3eb0((Ptr32<char>)self+84,*(Ptr32<unsigned int>)((Ptr32<char>)self+108),temp);
Ptr32<Vec3> pivot=(Ptr32<Vec3>)((Ptr32<char>)self+124);fn_801f7854(temp,-pivot->x,-pivot->y,-pivot->z);fn_801f77f4(temp,pivot->x,pivot->y,pivot->z);
Ptr32<Vec3> angles=(Ptr32<Vec3>)((Ptr32<char>)self+72);fn_801f6298(temp,angles->x,angles->y,angles->z);
Ptr32<Vec3> pos=(Ptr32<Vec3>)((Ptr32<char>)self+96);fn_801f77f4(temp,pos->x,pos->y,pos->z);
*(Ptr32<Matrix>)((Ptr32<char>)self+20)=*temp;}
extern "C" void f3c_update_transform_801a4364(Ptr32<Service> service,Ptr32<Node> self){Ptr32<Tag> tag=&self->tag;if(tag->dirty()){tag->word[0]&=253;float zero=lbl_803a9c1c[0];Matrix temp;update(&temp,self,zero);
}
unsigned offset=(lbl_80363938[0]->selector>>20)&0xffc;(*(Ptr32<Ptr32<void (Ptr32<Service>, Ptr32<Node>)>>)w3d::G((offset+(unsigned)w3d::H(service->table))))(service,self);}

