#include "w3d_ptr.h"
#line 1 "h2a_take_pool_item_callback_8017467c.cpp"
// Pointer-return ABI is independently witnessed in original 0x8025dffc.
// External pooled-item and request views. Pool item stride (172) is read from
// the original multiply; neither partial view is constructed locally.
struct PoolItem { Ptr32<Ptr32<void>> table; };
struct RequestView {unsigned char unknown0[26];unsigned char defaultMode,type;unsigned char unknown26[8];Ptr32<int (Ptr32<PoolItem>)> callback;};
extern "C" {
extern unsigned short count_804ab594;
extern Ptr32<unsigned short> free_804ab590;
extern Ptr32<unsigned char> pool_804ab588;
extern unsigned counts_804a89d8[];
int add_80190438(Ptr32<RequestView>,Ptr32<Ptr32<PoolItem>>,unsigned);
Ptr32<PoolItem> identity_8034bf4c(Ptr32<PoolItem>);
int h2a_take_pool_item_callback_8017467c(Ptr32<RequestView> request,Ptr32<Ptr32<PoolItem>> out,unsigned mode){
 if(!count_804ab594)return (int)0x80004005;
 if(mode==255)mode=request->defaultMode;
 unsigned next=count_804ab594-1;
 unsigned slot=*(Ptr32<unsigned short>)w3d::G(((next*2 & 0x1fffeu)+(unsigned)w3d::H(free_804ab590)));
 Ptr32<unsigned char> base=pool_804ab588;
 count_804ab594=next;
 unsigned offset=slot*172;
 Ptr32<PoolItem> item=(Ptr32<PoolItem>)w3d::G((offset+(unsigned)w3d::H(base)));
 if(item)((Ptr32<void (Ptr32<PoolItem>)>)item->table[3])(item);
 if(*out)((Ptr32<void (Ptr32<PoolItem>)>)(*out)->table[4])(*out);
 *out=item;
 int result=((Ptr32<int (Ptr32<PoolItem>, Ptr32<RequestView>, unsigned int)>)((Ptr32<PoolItem>)w3d::G((offset+(unsigned)w3d::H(base))))->table[10])(item,request,mode);
 if(result<0)return result;
 ++counts_804a89d8[request->type];
 result=add_80190438(request,out,255);
 if(request->callback){Ptr32<PoolItem> callbackItem=identity_8034bf4c(*out);result=request->callback(callbackItem);}
 return result;
}
}


