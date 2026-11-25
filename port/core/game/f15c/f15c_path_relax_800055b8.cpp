#include "w3d_ptr.h"
#line 1 "f15c_path_relax_800055b8.cpp"
// Recovered from GWMP8P rev0 original instructions. Field meanings are inferred.
// F15cPathView is only an external receiver prefix, never a complete allocation.
// Range reset is the entire external constructor footprint: offsets 2,4,7,8,10,12,16.
// Node allocation is exactly 20 bytes in this original factory. No vptr observed.
// Location contains bucket/index at offsets 0/4; table buckets remain opaque.
// Exact observed allocation is twenty bytes; the reset helper writes through nineteen.
extern "C" Ptr32<void> allocate_8001523c(unsigned int);
inline void *operator new(__SIZE_TYPE__,void *place){return place;}
void operator delete(void *);
extern "C" void empty_80341448();
extern "C" void empty_8034144c();
struct F15cNode;
struct F15cRange {
 F15cRange();
 short unknown0,x,y; unsigned char z,mode; short estimate,cost,total,unknown14; Ptr32<F15cNode> previous;
};
struct F15cNode : F15cRange {
 inline F15cNode(short a,short b,unsigned char c,Ptr32<F15cNode> p) {x=a;y=b;z=c;empty_80341448();previous=p;}
 inline ~F15cNode(){empty_8034144c();}
};
struct F15cPathView {char observed_prefix[0x8010];Ptr32<F15cNode> goal;};
struct F15cLocation {int bucket,index;};
extern "C" {
short distance_8000443c(Ptr32<F15cNode>,Ptr32<F15cNode>);
Ptr32<F15cNode> find_800052d4(Ptr32<void>,Ptr32<F15cNode>,Ptr32<F15cLocation>);
void remove_800059dc(Ptr32<F15cPathView>,Ptr32<F15cNode>);
void queue_80005a98(Ptr32<F15cPathView>,Ptr32<F15cNode>);
void insert_800053e4(Ptr32<void>,Ptr32<F15cNode>);
void erase_8000553c(Ptr32<void>,Ptr32<F15cLocation>);
void f15c_path_relax_800055b8(Ptr32<F15cPathView> self,Ptr32<F15cNode> previous,short x,short y,unsigned char z,int mode){
 Ptr32<F15cNode> node=new (allocate_8001523c(sizeof(F15cNode))) F15cNode(x,y,z,previous);
 node->mode=mode;
 short old=previous->cost;
 short cost=distance_8000443c(node,previous)+old;
 if(mode!=0){switch(mode){case 3:cost+=40;break;case 4:cost+=60;break;}}
 Ptr32<void> open=(Ptr32<char>)self+4;
 Ptr32<F15cNode> found=find_800052d4(open,node,0);
 if(found){
  if(cost<found->cost){remove_800059dc(self,found);found->previous=previous;found->mode=mode;found->cost=cost;found->total=cost+found->estimate;queue_80005a98(self,found);}
 }else{
  F15cLocation location;
  Ptr32<void> closed=(Ptr32<char>)self+0x4008;
  found=find_800052d4(closed,node,&location);
  if(!found)goto fresh;
  if(cost<found->cost){found->previous=previous;found->mode=mode;found->cost=cost;found->total=cost+found->estimate;queue_80005a98(self,found);insert_800053e4(open,found);erase_8000553c(closed,&location);}
 } 
 delete node;
 return;
fresh:
 node->cost=cost;
 short estimate=distance_8000443c(node,self->goal);
 node->estimate=estimate;node->total=node->cost;node->total+=node->estimate;
 queue_80005a98(self,node);insert_800053e4(open,node);
}
}


