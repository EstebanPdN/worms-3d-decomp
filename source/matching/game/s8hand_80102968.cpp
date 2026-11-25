struct s8_ItemOwner { char pad0[40]; void *items; };
extern "C" int fn_800ffca4(void *,int,int *);
extern "C" int fn_800ffb58(void *,int);
extern "C" int s8_apply_item_80102968(s8_ItemOwner *self,int key,int value) {
    int item;
    if(!self->items) return (int)0x80004005;
    int status=fn_800ffca4(self->items,key,&item);
    if(status>=0) { fn_800ffb58((void *)item,value); status=0; }
    return status;
}
