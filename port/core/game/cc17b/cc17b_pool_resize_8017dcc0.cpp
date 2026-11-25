#include "w3d_ptr.h"
#line 1 "cc17b_pool_resize_8017dcc0.cpp"
/* Observed signed owner guard at +20 and seven original category services. */
struct Cc17bPoolGuard { char pad[20]; int active; };
extern "C" {
unsigned fn_801709b0(unsigned),fn_801743b4(unsigned),fn_8017f3b8(unsigned),fn_801875e0(unsigned),fn_8018a678(unsigned),fn_80182850(unsigned),fn_80183d48(unsigned);
unsigned w3d_cc17b_pool_resize_8017dcc0(Ptr32<Cc17bPoolGuard> self,int category,unsigned count) {
 if(self->active>=0) {
  switch(category) {
  case 0:return fn_801709b0(count);
  case 2:return fn_801743b4(count);
  case 1:return fn_8017f3b8(count);
  case 3:return fn_801875e0(count);
  case 5:return fn_8018a678(count);
  case 6:return fn_80182850(count);
  case 4:return fn_80183d48(count);
  }
 }
 return 0x80004005u;
}
}


