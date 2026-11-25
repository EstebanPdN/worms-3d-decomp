#include "w3d_ptr.h"
#line 1 "cx9c_masked_byte_4.cpp"
/* Inferred masked conversion from floats to unsigned bytes through the native
 * ProDG thunk member-pointer ABI. A full mask skips the getter; masked-out
 * components retain the getter value. Quantized stores require -mfast-cast.
 */
class Cx9cByteObject{public:void w3d_r_unused() __asm__(W3D_SYM("_ZN14Cx9cByteObject6unusedEv")); __attribute__((always_inline)) inline void unused() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Cx9cByteObject, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Cx9cByteObject; };
struct Cx9cByteValue {unsigned char data[4];};
typedef w3d::Pmf<Cx9cByteObject, void(const Cx9cByteValue &)> Cx9cByteSetter;
typedef w3d::Pmf<Cx9cByteObject, const Cx9cByteValue &()> Cx9cByteGetter;
extern "C" void w3d_cx9c_masked_byte_4_80359604(Ptr32<Cx9cByteObject> object,int mask,Ptr32<const float> values,Cx9cByteSetter setter,Cx9cByteGetter getter)
{
 Ptr32<const Cx9cByteValue> current;
 if(mask!=15)current=&(getter)(object);
 Cx9cByteValue result;
 int bit=1,index=0;
 do{
  if(mask&bit)result.data[index]=(unsigned char)values[index];
  else result.data[index]=current->data[index];
  bit<<=1;++index;
 }while(bit&15);
 (setter)(object, result);
}


