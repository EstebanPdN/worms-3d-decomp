#include "w3d_ptr.h"
#line 1 "cxa_normalized_impulse_8003eb1c.cpp"
// Observed instruction contract at 0x8003eb1c; inferred operation names.
struct CxaImpulseVector {
 float x,y,z;
 CxaImpulseVector(const CxaImpulseVector &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
 float dot(const CxaImpulseVector &v) const {return x*v.x+y*v.y+z*v.z;}
 void multiply(float scale) {x*=scale;y*=scale;z*=scale;}
};
typedef char CxaImpulseVectorSize[(sizeof(CxaImpulseVector)==12)?1:-1];
struct CxaImpulseObject;
struct CxaImpulseTable {Ptr32<void (void)> unused[10];Ptr32<void (Ptr32<CxaImpulseObject>, int, int)> dispatch;};
struct CxaImpulseObject {Ptr32<CxaImpulseTable> table;};
extern "C" float sqrt_802e82c0(float);
extern "C" float one_80374670[],threshold_80374674[];
extern "C" void apply_8003ebdc(Ptr32<CxaImpulseObject>,Ptr32<const CxaImpulseVector>);
extern "C" void cxa_normalized_impulse_8003eb1c(Ptr32<CxaImpulseObject> self,int a,int b,Ptr32<const CxaImpulseVector> input) {
 self->table->dispatch(self,a,b);
 CxaImpulseVector direction(*input);
 // Preserve the original reciprocal-length path, including its zero-length behavior.
 direction.multiply(one_80374670[0]/sqrt_802e82c0(direction.dot(direction)));
 if(direction.y>threshold_80374674[0])apply_8003ebdc(self,&direction);
}


