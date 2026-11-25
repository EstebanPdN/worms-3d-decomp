/* Observed cached lookup/fallback. Names describe control flow, not unknown
   original class names. The two status constants come from original code. */
struct Cx16bCachedIface { void **vtable; };
struct Cx16bCacheOwner { void **vtable; char pad[16]; Cx16bCachedIface *fallback; char gap[44]; void **values; };
extern "C" int fn_801b40d0(Cx16bCacheOwner *,const char *);
extern "C" int w3d_cx16b_cached_interface_find_801b36f8(Cx16bCacheOwner *self,const char *key,void **out)
{
    if(out==0 || key==0)return (int)0x80070057U;
    *out=0;
    int index=fn_801b40d0(self,key);
    if(index!=-1){
        *out=*(void **)((index<<2)+(unsigned)self->values);
        return 0;
    }
    Cx16bCachedIface *fallback=self->fallback;
    if(fallback){
    int result=((int(*)(Cx16bCachedIface *,const char *,void **))fallback->vtable[6])(fallback,key,out);
    if(result>=0)((void(*)(Cx16bCacheOwner *,const char *,void *))self->vtable[7])(self,key,*out);
    return result;
    }
    return (int)0x80004005U;
}
