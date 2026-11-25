#include "w3d_ptr.h"
#line 1 "cx9c_append_interface.cpp"
/* Observed PPC32: count at +76, pointer array at +84; vtable retain/release
 * slots +12/+16. Class and method names are inferred. */
struct Cx9cInterface {Ptr32<Ptr32<void>> vtable;};
struct Cx9cArray {unsigned int count,unknown;Ptr32<Ptr32<Cx9cInterface>> begin;};
struct Cx9cOwner {unsigned char unknown[76];Cx9cArray array;};
extern "C" void cx9c_reserve_80210d54(Ptr32<Cx9cArray>,unsigned int);
extern "C" void w3d_cx9c_append_interface_8034b9bc(Ptr32<Cx9cOwner> self,Ptr32<Cx9cInterface> value) {
 Ptr32<Cx9cArray> array=&self->array;
 cx9c_reserve_80210d54(array,array->count+1);
 unsigned int offset=self->array.count<<2;Ptr32<Ptr32<Cx9cInterface>> base=array->begin;
 if(value)((Ptr32<void (Ptr32<Cx9cInterface>)>)value->vtable[3])(value);
 Ptr32<Cx9cInterface> old=*(Ptr32<Ptr32<Cx9cInterface>>)w3d::G((offset+(unsigned int)w3d::H(base)));
 if(old)((Ptr32<void (Ptr32<Cx9cInterface>)>)old->vtable[4])(old);
 *(Ptr32<Ptr32<Cx9cInterface>>)w3d::G((offset+(unsigned int)w3d::H(base)))=value;
 self->array.count++;
}


