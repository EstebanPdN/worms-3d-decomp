#include "w3d_ptr.h"
#line 1 "cxc2_records_8020fac8.cpp"
/* Original 0x8020fac8. Three observed twelve-byte records in one aggregate.
 * Initialization zeroes each record, installs the first two table pointers,
 * sets their size/ref words to twelve/one, and sets the global ready flag.
 * Compute the second member address before clearing the first record; the
 * original retains the aggregate base through all three calls.
 * Record/table meanings are inferred. External storage remains unowned.
 */
typedef unsigned int u32;
extern "C" int lbl_804b06b4;
extern "C" char lbl_8040c980[],lbl_8040c990[];
extern "C" Ptr32<void> fn_802eefe0(Ptr32<void>,...);
inline void *operator new(__SIZE_TYPE__, void *p) {return p;}
struct Cxc2RawRecord { Ptr32<void> table; u32 size,refs; };
struct Cxc2Records {
 Cxc2RawRecord a,b,c;
 void first(u32 size,u32 refs){a.size=size;a.refs=refs;}
 void second(u32 size,u32 refs){b.size=size;b.refs=refs;}
 Cxc2Records(){
Ptr32<Cxc2RawRecord> next=&b;
  fn_802eefe0(&a,0,12);
  first(12,1);a.table=lbl_8040c980;
  fn_802eefe0(next,0,12);
  second(12,1);b.table=lbl_8040c990;
  fn_802eefe0(&c,0,12);
 }
};
extern "C" Cxc2Records lbl_80463bbc;
extern "C" Ptr32<void> cxc2_records_8020fac8(){
 if(!lbl_804b06b4){ new (&lbl_80463bbc) Cxc2Records;lbl_804b06b4=1; }
 return &lbl_80463bbc;
}


