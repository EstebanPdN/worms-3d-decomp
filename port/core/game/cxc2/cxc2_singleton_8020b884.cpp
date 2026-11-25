#include "w3d_ptr.h"
#line 1 "cxc2_singleton_8020b884.cpp"
/* Original 0x8020b884. Observed lazy interface slot with a shared fallback.
 * The assignment returns whether its supplied pointer is null. This preserves
 * the condition across retain/release calls in the original nonvolatile CR.
 * Interface meanings and names are inferred; vtable byte offsets are observed.
 */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
extern "C" Ptr32<void> lbl_804abaa4;
extern "C" Ptr32<void> lbl_804b0698;
extern "C" Ptr32<void> fn_801fe1d8(unsigned int);
extern "C" Ptr32<void> fn_80218284(Ptr32<void>);
static inline bool cxc2_assign(Ptr32<Ptr32<void>> slot, Ptr32<void> p) {
 if (p) (*(Ptr32<Ptr32<void (Ptr32<void>)>>)((char *)FIELD(p,void *,0)+12))(p);
 if (*slot) {Ptr32<void> old=*slot; (*(Ptr32<Ptr32<void (Ptr32<void>)>>)((char *)FIELD(old,void *,0)+16))(old);}
 *slot=p; return p==0;
}
extern "C" Ptr32<void> cxc2_singleton_8020b884(void) {
 if (!lbl_804b0698) {
  Ptr32<void> fallback=lbl_804abaa4;
  bool missing=cxc2_assign(&lbl_804b0698,fallback);
  if (missing) cxc2_assign(&lbl_804b0698,fn_80218284(fn_801fe1d8(28)));
 }
 return lbl_804b0698;
}


