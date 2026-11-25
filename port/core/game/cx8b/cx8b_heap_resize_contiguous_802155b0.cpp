#include "w3d_ptr.h"
#line 1 "cx8b_heap_resize_contiguous_802155b0.cpp"

extern "C" int fn_801fdfc8(int);
extern "C" int w3d_cx8b_heap_resize_contiguous_802155b0(Ptr32<void>,int base,int oldSize,int newSize) {
 if(oldSize && fn_801fdfc8(0)!=base+oldSize) return 0;
 int result=fn_801fdfc8(newSize-oldSize);
 if(result!=-1) {if(oldSize) return base;else return result;}else return 0;
}






