
extern "C" int fn_801fdfc8(int);
extern "C" int w3d_cx8b_heap_resize_contiguous_802155b0(void *,int base,int oldSize,int newSize) {
 if(oldSize && fn_801fdfc8(0)!=base+oldSize) return 0;
 int result=fn_801fdfc8(newSize-oldSize);
 if(result!=-1) {if(oldSize) return base;else return result;}else return 0;
}




