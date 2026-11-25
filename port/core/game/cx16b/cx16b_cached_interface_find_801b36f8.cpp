#include "w3d_ptr.h"
#line 1 "cx16b_cached_interface_find_801b36f8.cpp"
/* Observed cached lookup/fallback. Names describe control flow, not unknown
   original class names. The two status constants come from original code. */
struct Cx16bCachedIface { Ptr32<Ptr32<void>> vtable; };
struct Cx16bCacheOwner { Ptr32<Ptr32<void>> vtable; char pad[16]; Ptr32<Cx16bCachedIface> fallback; char gap[44]; Ptr32<Ptr32<void>> values; };
extern "C" int fn_801b40d0(Ptr32<Cx16bCacheOwner>,Ptr32<const char>);
extern "C" int w3d_cx16b_cached_interface_find_801b36f8(Ptr32<Cx16bCacheOwner> self,Ptr32<const char> key,Ptr32<Ptr32<void>> out)
{
    if(out==0 || key==0)return (int)0x80070057U;
    *out=0;
    int index=fn_801b40d0(self,key);
    if(index!=-1){
        *out=*(Ptr32<Ptr32<void>>)w3d::G(((index<<2)+(unsigned)w3d::H(self->values)));
        return 0;
    }
    Ptr32<Cx16bCachedIface> fallback=self->fallback;
    if(fallback){
    int result=((Ptr32<int (Ptr32<Cx16bCachedIface>, Ptr32<const char>, Ptr32<Ptr32<void>>)>)fallback->vtable[6])(fallback,key,out);
    if(result>=0)((Ptr32<void (Ptr32<Cx16bCacheOwner>, Ptr32<const char>, Ptr32<void>)>)self->vtable[7])(self,key,*out);
    return result;
    }
    return (int)0x80004005U;
}


