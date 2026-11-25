/* Observed session transition flags and unused resource release. */
extern "C" {
struct W3dS1SessionRef;
struct W3dS1SessionRefTable {void (*unused[4])();void (*release)(W3dS1SessionRef *);};
struct W3dS1SessionRef {W3dS1SessionRefTable *vtable;};
struct W3dS1SessionMessage {unsigned short id,reserved;void *vtable;};
struct W3dS1SessionCache;
struct W3dS1SessionCacheTable {void (*unused[16])();void (*release)(W3dS1SessionCache *,unsigned char *);void (*unused17[2])();void (*ready)(W3dS1SessionCache *,unsigned char *,int *);void (*available)(W3dS1SessionCache *,unsigned char *,int *);};
struct W3dS1SessionCache {W3dS1SessionCacheTable *vtable;};
struct W3dS1SessionCacheContext {char unknown[116];W3dS1SessionCache *cache;};
extern W3dS1SessionCacheContext *w3d_cache_context_804b17ec;
extern void *w3d_queue_804b1754;
extern unsigned int w3d_message_804ad81c;
extern unsigned char w3d_vtable_8040db38[];
W3dS1SessionMessage *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
int w3d_message_post_current(void *);
void w3d_fn_8006ac40(void *);
void w3d_fn_8006af38(void *);
unsigned int *w3d_fn_8006ac90(void *);
union W3dS1SessionFlags {unsigned int raw;struct {unsigned int first:1;unsigned int deferred:1;unsigned int rest:30;} bits;};
struct W3dS1SessionTransition {char unknown[212];unsigned int state;char unknownD8[24];W3dS1SessionFlags flags;char unknownF4[12];W3dS1SessionRef *held;};
void w3d_fn_8006ab48(W3dS1SessionTransition *self,unsigned int state,unsigned int deferred,int unused3,int unused4)
{
    self->flags.raw&=~0x0c000000U;
    W3dS1SessionRef *held=(W3dS1SessionRef *)self->held;
    if(held)held->vtable->release(held);
    self->held=0;
    unsigned int flags=self->flags.raw;
    if(flags&0x04000000U) {
        self->state=state;
        flags=(flags&~0x04000000U)|0x20000000U;
        self->flags.raw=flags;
        self->flags.bits.deferred=deferred;
        W3dS1SessionMessage *message=w3d_fn_801613f0(w3d_queue_804b1754,8);
        message->id=w3d_cached_message_id(&w3d_message_804ad81c,1);message->vtable=w3d_vtable_8040db38;
        w3d_message_post_current(message);
    } else {
        self->flags.raw=flags&~0x40000000U;
        if(deferred) {
            w3d_fn_8006ac40(self);self->state=state;self->flags.raw&=~0x60000000U;
        } else {
            self->state=state;self->flags.raw=flags&~0x60000000U;w3d_fn_8006af38(self);
        }
    }
}
int w3d_fn_8006ae58(void *self)
{
    unsigned char index;int available,ready;
    unsigned int *used=w3d_fn_8006ac90(self);
    index=0;
    do {
        if(!used[index]) {
            W3dS1SessionCache *cache=w3d_cache_context_804b17ec->cache;
            cache->vtable->available(cache,&index,&available);
            if(available) {
                cache=w3d_cache_context_804b17ec->cache;
                cache->vtable->ready(cache,&index,&ready);
                if(!ready)return 0;
                cache=w3d_cache_context_804b17ec->cache;
                cache->vtable->release(cache,&index);
            }
        }
        ++index;
    }while(index<=88);
    return 1;
}
}
