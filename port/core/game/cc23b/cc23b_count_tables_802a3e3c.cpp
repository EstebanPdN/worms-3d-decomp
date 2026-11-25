#include "w3d_ptr.h"
#line 1 "cc23b_count_tables_802a3e3c.cpp"
struct Cc23bNamed20 {Ptr32<const char> name;unsigned int unknown[4];};
struct Cc23bNamed24 {Ptr32<const char> name;unsigned int unknown[5];};
struct Cc23bPair8 {unsigned int key,value;};
extern "C" {
extern Cc23bNamed20 lbl_804021e8[],lbl_804024a4[];
extern Cc23bNamed24 lbl_80403980[],lbl_804039b0[];
extern Cc23bPair8 lbl_804abc28[];
extern unsigned int lbl_804b0eb4,lbl_804b0eb8,lbl_804b0ebc,lbl_804b0ec0,lbl_804b0ec4;
}
template<class T> static inline unsigned int cc23bCount(T *table) {
 unsigned int count=0;
 while(table[count].name)++count;
 return count;
}
static inline unsigned int cc23bCountPairs(Ptr32<Cc23bPair8> table) {
 unsigned int count=0;
 while(table[count].key)++count;
 return count;
}
extern "C" void w3d_cc23b_count_tables_802a3e3c(int initialize,int priority) {
 if(priority!=65535)return;
 if(!initialize)return;
 lbl_804b0eb4=cc23bCount(w3d::R(lbl_804021e8));
 lbl_804b0eb8=cc23bCount(w3d::R(lbl_804024a4));
 lbl_804b0ebc=cc23bCount(w3d::R(lbl_80403980));
 lbl_804b0ec0=cc23bCount(w3d::R(lbl_804039b0));
 lbl_804b0ec4=cc23bCountPairs(lbl_804abc28);
}


