// External pooled-item and request views. Pool item stride (172) is read from
// the original multiply; neither partial view is constructed locally.
struct PoolItem { void **table; };
struct RequestView {unsigned char unknown0[24];unsigned char type,defaultMode;unsigned char unknown26[10];int(*callback)();};
extern "C" {
extern unsigned short count_804ab594;
extern unsigned short *free_804ab590;
extern unsigned char *pool_804ab588;
extern unsigned counts_804a89d8[];
int add_80190438(RequestView*,PoolItem**,unsigned);
void empty_8034bf4c(PoolItem*);
int h1a_take_pool_item_8017467c(RequestView *request,PoolItem **out,unsigned mode){
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
 if(request->callback){empty_8034bf4c(*out);result=request->callback();}
 return result;
}
}
