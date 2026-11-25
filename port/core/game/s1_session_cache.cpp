#include "w3d_ptr.h"
#line 1 "s1_session_cache.cpp"
/* Applies the observed resource-use table to the shared cache. */
extern "C" {
struct W3dS1ApplyCache;
struct W3dS1ApplyTable {Ptr32<void (void)> unused[3];Ptr32<void (Ptr32<W3dS1ApplyCache>)> retain;Ptr32<void (Ptr32<W3dS1ApplyCache>)> release;Ptr32<void (void)> unused5[10];Ptr32<void (Ptr32<W3dS1ApplyCache>, Ptr32<unsigned char>)> load;Ptr32<void (Ptr32<W3dS1ApplyCache>, Ptr32<unsigned char>)> unload;Ptr32<void (void)> unused17[3];Ptr32<void (Ptr32<W3dS1ApplyCache>, Ptr32<unsigned char>, Ptr32<int>)> available;};
struct W3dS1ApplyCache {Ptr32<W3dS1ApplyTable> vtable;};
struct W3dS1ApplyContext {char unknown[116];Ptr32<W3dS1ApplyCache> cache;};
struct W3dS1ApplyRef {
    Ptr32<W3dS1ApplyCache> value;int unknown;
    W3dS1ApplyRef(Ptr32<W3dS1ApplyCache> w3d_p) : W3dS1ApplyRef((W3dS1ApplyCache *)w3d_p.get()) {}
 W3dS1ApplyRef(W3dS1ApplyCache *v):value(v) {if(value)value->vtable->retain(value);}
    ~W3dS1ApplyRef() {if(value)value->vtable->release(value);}
};
extern Ptr32<W3dS1ApplyContext> w3d_context_804b17ec;
extern int w3d_busy_804aaab0;
static inline void apply_retain(W3dS1ApplyRef &ref,Ptr32<W3dS1ApplyCache> value) {ref.value=value;if(value)value->vtable->retain(value);}
void w3d_fn_8006bce4(Ptr32<int> used)
{
    unsigned char index;int available;
    w3d_busy_804aaab0=1;W3dS1ApplyRef held(w3d_context_804b17ec->cache);
    index=0;
    Ptr32<unsigned char> key=&index;Ptr32<int> state=&available;
    do {
        held.value->vtable->available(held.value,key,state);
        if(used[index]!=available) {
            if(used[index])held.value->vtable->load(held.value,key);
            else held.value->vtable->unload(held.value,key);
        }
        ++index;
    }while(index<=88);
    w3d_busy_804aaab0=0;
}
}


