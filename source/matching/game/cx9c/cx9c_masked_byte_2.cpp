/* Inferred masked conversion from floats to unsigned bytes through the native
 * ProDG thunk member-pointer ABI. A full mask skips the getter; masked-out
 * components retain the getter value. Quantized stores require -mfast-cast.
 */
class Cx9cByteObject{public:virtual void unused();};
struct Cx9cByteValue {unsigned char data[4];};
typedef void (Cx9cByteObject::*Cx9cByteSetter)(const Cx9cByteValue &);
typedef const Cx9cByteValue &(Cx9cByteObject::*Cx9cByteGetter)();
extern "C" void w3d_cx9c_masked_byte_2_803593fc(Cx9cByteObject *object,int mask,const float *values,Cx9cByteSetter setter,Cx9cByteGetter getter)
{
 const Cx9cByteValue *current;
 if(mask!=3)current=&(object->*getter)();
 Cx9cByteValue result;
 int bit=1,index=0;
 do{
  if(mask&bit)result.data[index]=(unsigned char)values[index];
  else result.data[index]=current->data[index];
  bit<<=1;++index;
 }while(bit&3);
 (object->*setter)(result);
}
