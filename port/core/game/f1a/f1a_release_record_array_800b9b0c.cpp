#include "w3d_ptr.h"
#line 1 "f1a_release_record_array_800b9b0c.cpp"
// Original 0x800b9b0c; observed slots and virtual table offsets only.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
typedef Ptr32<void (Ptr32<void>)> F1aReleaseFn;
inline void release_slot(Ptr32<Ptr32<void>> slot,Ptr32<void> zero) {
 if(*slot) ((F1aReleaseFn)(*(Ptr32<Ptr32<Ptr32<void>>>)*slot)[4])(*slot);
 *slot=zero;
}
extern "C" {
extern Ptr32<char> lbl_804b183c;
int w3d_f1a_release_record_array_800b9b0c(Ptr32<char> self) {
 unsigned i=0;Ptr32<void> zero=0;
 Ptr32<Ptr32<void>> e=(Ptr32<Ptr32<void>>)(self+3152);
Ptr32<Ptr32<void>> d=(Ptr32<Ptr32<void>>)(self+3148);
Ptr32<Ptr32<void>> c=(Ptr32<Ptr32<void>>)(self+3144);
Ptr32<Ptr32<void>> b=(Ptr32<Ptr32<void>>)(self+3140);
 do {
  release_slot(e-4,zero);
  if(e[-3])((F1aReleaseFn)(*(Ptr32<Ptr32<Ptr32<void>>>)e[-3])[4])(e[-3]);*b=zero;
  if(e[-2])((F1aReleaseFn)(*(Ptr32<Ptr32<Ptr32<void>>>)e[-2])[4])(e[-2]);*c=zero;
  if(e[-1])((F1aReleaseFn)(*(Ptr32<Ptr32<Ptr32<void>>>)e[-1])[4])(e[-1]);*d=zero;
  release_slot(e,zero);
  ++i;e+=6;d+=6;c+=6;b+=6;
 }while(i<128);
 ((F1aReleaseFn)FIELD(lbl_804b183c,void **,2792)[4])(lbl_804b183c);
 return 0;
}
}


