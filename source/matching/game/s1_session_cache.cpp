/* Applies the observed resource-use table to the shared cache. */
extern "C" {
struct W3dS1ApplyCache;
struct W3dS1ApplyTable {void (*unused[3])();void (*retain)(W3dS1ApplyCache *);void (*release)(W3dS1ApplyCache *);void (*unused5[10])();void (*load)(W3dS1ApplyCache *,unsigned char *);void (*unload)(W3dS1ApplyCache *,unsigned char *);void (*unused17[3])();void (*available)(W3dS1ApplyCache *,unsigned char *,int *);};
struct W3dS1ApplyCache {W3dS1ApplyTable *vtable;};
struct W3dS1ApplyContext {char unknown[116];W3dS1ApplyCache *cache;};
struct W3dS1ApplyRef {
    W3dS1ApplyCache *value;int unknown;
    W3dS1ApplyRef(W3dS1ApplyCache *v):value(v) {if(value)value->vtable->retain(value);}
    ~W3dS1ApplyRef() {if(value)value->vtable->release(value);}
};
extern W3dS1ApplyContext *w3d_context_804b17ec;
extern int w3d_busy_804aaab0;
static inline void apply_retain(W3dS1ApplyRef &ref,W3dS1ApplyCache *value) {ref.value=value;if(value)value->vtable->retain(value);}
void w3d_fn_8006bce4(int *used)
{
    unsigned char index;int available;
    w3d_busy_804aaab0=1;W3dS1ApplyRef held(w3d_context_804b17ec->cache);
    index=0;
    unsigned char *key=&index;int *state=&available;
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
