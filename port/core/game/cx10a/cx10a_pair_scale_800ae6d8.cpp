#include "w3d_ptr.h"
#line 1 "cx10a_pair_scale_800ae6d8.cpp"
// PPC32 observed owner interfaces at +0x24/+0x28 and vtable slots +0x54/+0x58.
struct Cx10aPairInterface;
struct Cx10aPairVector {float x,y,z;Cx10aPairVector(float a,float b,float c){x=a;y=b;z=c;}};
struct Cx10aPairTable {Ptr32<void (void)> unused00[21];Ptr32<int (Ptr32<Cx10aPairInterface>, Ptr32<const Cx10aPairVector>, int)> scale;Ptr32<void (Ptr32<Cx10aPairInterface>, int)> enable;};
struct Cx10aPairInterface {Ptr32<Cx10aPairTable> table;};
struct Cx10aPairOwner {unsigned char unknown00[0x24];Ptr32<Cx10aPairInterface> first; Ptr32<Cx10aPairInterface> second;};
extern const float threshold_803821b8[],neutral_803821bc[];
extern "C" void w3d_cx10a_pair_scale_800ae6d8(Ptr32<Cx10aPairOwner> self,float amount){
 if(amount>threshold_803821b8[0]){
 self->first->table->enable(self->first,1);self->second->table->enable(self->second,1);
 Cx10aPairVector scale(neutral_803821bc[0],neutral_803821bc[0],amount);
 self->first->table->scale(self->first,&scale,0);self->second->table->scale(self->second,&scale,0);
 }else{self->first->table->enable(self->first,0);self->second->table->enable(self->second,0);}
}


