#include "w3d_ptr.h"
#line 1 "cx9c_copy_transform_record.cpp"
/* Observed 184-byte record: three float triples +0/+12/+24, vptr word +36,
 * byte +40, triple +44, two raw 36-byte members +56/+92, three triples
 * +128/+140/+152 and five floats +164. Names are structural inferences.
 * The two vtable addresses are original external objects, not owned data. */
inline void *operator new(__SIZE_TYPE__,void *p){return p;}
extern "C" unsigned int cx9c_vtable_8040fd60[],cx9c_vtable_804108d8[];
struct Cx9cFirstTriple {float x,y,z;Cx9cFirstTriple(){} Cx9cFirstTriple(const Cx9cFirstTriple &o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}};
struct Cx9cTriple {float x,y,z;Cx9cTriple(){} Cx9cTriple(const Cx9cTriple &o){float a=o.x,c=o.z,b=o.y;x=a;z=c;y=b;} Cx9cTriple &operator=(const Cx9cTriple &o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;return *this;}};
struct Cx9cBlock {unsigned int words[9];};
struct Cx9cBase {
 Cx9cFirstTriple first;Cx9cTriple second,third;Ptr32<unsigned int> vtable;
 Cx9cBase(const Cx9cBase &o){vtable=cx9c_vtable_8040fd60;new(&first)Cx9cFirstTriple(o.first);second=o.second;third=o.third;}
};
struct Cx9cRecord:Cx9cBase {
 unsigned char flag __attribute__((aligned(__alignof__(Cx9cBase)))),pad[3];Cx9cTriple fourth;Cx9cBlock a,b;Cx9cTriple fifth,sixth,seventh;float tail[5];
 Cx9cRecord(const Cx9cRecord &o):Cx9cBase(o){
  vtable=cx9c_vtable_804108d8;flag=o.flag;fourth=o.fourth;a=o.a;b=o.b;
  fifth=o.fifth;sixth=o.sixth;seventh=o.seventh;
  tail[0]=o.tail[0];tail[1]=o.tail[1];tail[2]=o.tail[2];tail[3]=o.tail[3];tail[4]=o.tail[4];
 }
};
extern "C" Ptr32<Cx9cRecord> w3d_cx9c_copy_transform_record_8034736c(Ptr32<Cx9cRecord> self,Ptr32<const Cx9cRecord> other){return new(self) Cx9cRecord(*other);}


