#include "w3d_ptr.h"
#line 1 "terra_only_c6_process_8021bffc.cpp"
/* Provisional ABI reconstruction: virtual signatures and object identities are
 * unknown. The second Ref word accounts for the observed stack layout; its
 * meaning and even its membership in this type are not established. The
 * buffer size is provisional and must not be treated as a proven contract. */
struct Obj { Ptr32<Ptr32<void>> v; };
extern "C" unsigned fn_80240b84(Ptr32<void>);
extern "C" Ptr32<Obj> fn_8020b680(Ptr32<void>);
extern "C" char lbl_80418de0[];
#define CALL(o,n,t) ((w3d::slot_t<t>)((o)->v[n]))
struct Ref { Ptr32<Obj> p; int unknown; template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *x):p(x) { if(p) CALL(p,3,void (*)(Obj *))(p); } ~Ref(){if(p) CALL(p,4,void (*)(Obj *))(p);} };
extern "C" void terra_only_c6_process_8021bffc(Ptr32<char> self, Ptr32<char> arg)
{
 if ((fn_80240b84(arg) & 64) && *(Ptr32<int>)(self + 156) == 0) {
  Ref service(fn_8020b680(lbl_80418de0));
  Ptr32<Obj> stream = *(Ptr32<Ptr32<Obj>>)(arg + 60);
  CALL(service.p,5,void (*)(Obj *,Obj *))(service.p,stream);
  char buf[8];
  while (CALL(stream,18,int (*)(Obj *,void *))(stream,buf)) {
   int temp; Ptr32<Obj> item;
   *(Ptr32<int>)(arg + 28) = 0;
   CALL(stream,5,int (*)(Obj *,void *,int,int))(stream,&temp,4,0);
   if (CALL(service.p,8,int (*)(Obj *,Obj **,int))(service.p,&item,0) < 0) goto done;
   CALL(item,8,void (*)(Obj *,void *))(item,arg);
   CALL(item,4,void (*)(Obj *))(item);
  }
 done:;
 }
}


