#include "w3d_ptr.h"
#line 1 "cx7p_endpoint_scan_control_802ccbfc.cpp"
// PPC32 endpoint vtable slots and global table layouts observed in the original.
struct Endpoint;struct Vtable {Ptr32<void> unused[8];Ptr32<int (Ptr32<Endpoint>, Ptr32<Ptr32<void>>, Ptr32<unsigned int>, Ptr32<Ptr32<void>>, Ptr32<unsigned int>)> buffers;Ptr32<void> gap[3];Ptr32<int (Ptr32<Endpoint>)> ready;};struct Endpoint{Ptr32<Vtable> vtable;};
extern "C" unsigned int active_80473724[];extern "C" Ptr32<Endpoint> endpoints_804738a4[];

extern "C" Ptr32<void> find_802eed00(Ptr32<const void>,int,unsigned int);extern "C" void control_802cccbc(unsigned int);
extern "C" void w3d_cx7p_endpoint_scan_control_802ccbfc(unsigned int index){if(*(Ptr32<unsigned int>)((index<<2)+(Ptr32<unsigned char>)active_80473724)){Ptr32<void> a; Ptr32<void> b;unsigned int na,nb;Ptr32<Endpoint> p=*(Ptr32<Ptr32<Endpoint>>)((index<<2)+(Ptr32<unsigned char>)endpoints_804738a4);if(p->vtable->buffers(p,&a,&na,&b,&nb)>=0){if(na||nb){if(find_802eed00(a,3,na)||find_802eed00(b,3,nb))control_802cccbc(index);}}}}



