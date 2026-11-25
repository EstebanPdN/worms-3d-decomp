#include "w3d_ptr.h"
#line 1 "f3c_update_transform_801a44ac.cpp"
// Structural names, math representations, and partial layouts inferred from original instructions.
struct Matrix {float v[10];};
struct Vec3 {float x,y,z;inline void assign(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct Tag {unsigned short a,b;unsigned char word[4];};
struct Node {Ptr32<void> vtable;Tag tag;unsigned pad[2];Matrix transform;Vec3 pad2,angles,pad3,position;unsigned mode;Vec3 scale,pivot;};
struct Service {unsigned pad[6];Ptr32<char> table;};
struct Global{unsigned pad[8];unsigned selector;};
extern Ptr32<Global> lbl_80363938[];
extern "C" void fn_801a3eb0(Ptr32<void>,unsigned,Ptr32<Matrix>);
extern "C" void fn_801f606c(Ptr32<Matrix>,Ptr32<const Matrix>,Ptr32<const Matrix>);
extern "C" void fn_801f6448(Ptr32<Matrix>,float,float,float);
extern "C" void f3c_update_transform_801a44ac(Ptr32<Service> service,Ptr32<Node> self){Ptr32<Tag> tag=&self->tag;if(tag->word[0]&2){tag->word[0]&=253;
Matrix a,b,c,d;
fn_801a3eb0((Ptr32<char>)self+84,*(Ptr32<unsigned int>)((Ptr32<char>)self+108),&a);
fn_801a3eb0((Ptr32<char>)self+124,0,&b);
fn_801a3eb0((Ptr32<char>)self+112,0,&c);
fn_801f606c(&d,&b,&a);Ptr32<Matrix> out=(Ptr32<Matrix>)((Ptr32<char>)self+20);fn_801f606c(out,&d,&c);
Ptr32<Vec3> angles=(Ptr32<Vec3>)((Ptr32<char>)self+72);fn_801f6448(out,angles->x,angles->y,angles->z);
((Ptr32<Vec3>)((Ptr32<char>)self+56))->assign(*(Ptr32<Vec3>)((Ptr32<char>)self+96));
}
unsigned offset=(lbl_80363938[0]->selector>>20)&0xffc;(*(Ptr32<Ptr32<void (Ptr32<Service>, Ptr32<Node>)>>)w3d::G((offset+(unsigned)w3d::H(service->table))))(service,self);}

