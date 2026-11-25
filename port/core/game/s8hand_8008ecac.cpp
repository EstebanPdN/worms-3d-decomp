#include "w3d_ptr.h"
#line 1 "s8hand_8008ecac.cpp"
struct s8_Interface { Ptr32<Ptr32<void>> vtable; };
struct s8_PairOwner { char pad0[556]; Ptr32<s8_Interface> first; Ptr32<s8_Interface> second; };
extern "C" void s8_clear_pair_8008ecac(Ptr32<s8_PairOwner> self) {
    Ptr32<s8_Interface> zero=0;
    Ptr32<s8_Interface> first=self->first;
    if(first) ((Ptr32<void (Ptr32<s8_Interface>)>)first->vtable[4])(first);
    self->first=zero;
    Ptr32<s8_Interface> second=self->second;
    if(second) ((Ptr32<void (Ptr32<s8_Interface>)>)second->vtable[4])(second);
    self->second=zero;
}


