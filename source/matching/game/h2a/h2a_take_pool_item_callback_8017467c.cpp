// Pointer-return ABI is independently witnessed in original 0x8025dffc.
// External pooled-item and request views. Pool item stride (172) is read from
// the original multiply; neither partial view is constructed locally.
struct PoolItem { void **table; };
struct RequestView {unsigned char unknown0[24];unsigned char type,defaultMode;unsigned char unknown26[10];int(*callback)(PoolItem*);};
extern "C" {
extern unsigned short count_804ab594;
extern unsigned short *free_804ab590;
extern unsigned char *pool_804ab588;
extern unsigned counts_804a89d8[];
int add_80190438(RequestView*,PoolItem**,unsigned);
PoolItem *identity_8034bf4c(PoolItem*);
int h2a_take_pool_item_callback_8017467c(RequestView *request,PoolItem **out,unsigned mode){
 if(!count_804ab594)return (int)0x80004005;
 if(mode==255)mode=request->defaultMode;
 unsigned next=count_804ab594-1;
 unsigned slot=*(unsigned short*)((next*2 & 0x1fffeu)+(unsigned)free_804ab590);
 unsigned char *base=pool_804ab588;
 count_804ab594=next;
 unsigned offset=slot*172;
 PoolItem *item=(PoolItem*)(offset+(unsigned)base);
 if(item)((void(*)(PoolItem*))item->table[3])(item);
 if(*out)((void(*)(PoolItem*))(*out)->table[4])(*out);
 *out=item;
 int result=((int(*)(PoolItem*,RequestView*,unsigned))((PoolItem*)(offset+(unsigned)base))->table[10])(item,request,mode);
 if(result<0)return result;
 ++counts_804a89d8[request->type];
 result=add_80190438(request,out,255);
 if(request->callback){PoolItem *callbackItem=identity_8034bf4c(*out);result=request->callback(callbackItem);}
 return result;
}
}
