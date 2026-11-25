#include "w3d_ptr.h"
#line 1 "s1_session_transition.cpp"
/* Observed session transition flags and unused resource release. */
extern "C" {
struct W3dS1SessionRef;
struct W3dS1SessionRefTable {Ptr32<void (void)> unused[4];Ptr32<void (Ptr32<W3dS1SessionRef>)> release;};
struct W3dS1SessionRef {Ptr32<W3dS1SessionRefTable> vtable;};
struct W3dS1SessionMessage {unsigned short id,reserved;Ptr32<void> vtable;};
struct W3dS1SessionCache;
struct W3dS1SessionCacheTable {Ptr32<void (void)> unused[16];Ptr32<void (Ptr32<W3dS1SessionCache>, Ptr32<unsigned char>)> release;Ptr32<void (void)> unused17[2];Ptr32<void (Ptr32<W3dS1SessionCache>, Ptr32<unsigned char>, Ptr32<int>)> ready;Ptr32<void (Ptr32<W3dS1SessionCache>, Ptr32<unsigned char>, Ptr32<int>)> available;};
struct W3dS1SessionCache {Ptr32<W3dS1SessionCacheTable> vtable;};
struct W3dS1SessionCacheContext {char unknown[116];Ptr32<W3dS1SessionCache> cache;};
extern Ptr32<W3dS1SessionCacheContext> w3d_cache_context_804b17ec;
extern Ptr32<void> w3d_queue_804b1754;
extern unsigned int w3d_message_804ad81c;
extern unsigned char w3d_vtable_8040db38[];
Ptr32<W3dS1SessionMessage> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
int w3d_message_post_current(Ptr32<void>);
void w3d_fn_8006ac40(Ptr32<void>);
void w3d_fn_8006af38(Ptr32<void>);
Ptr32<unsigned int> w3d_fn_8006ac90(Ptr32<void>);
union W3dS1SessionFlags {unsigned int raw;struct {unsigned int rest:30; unsigned int deferred:1; unsigned int first:1;} bits;};
struct W3dS1SessionTransition {char unknown[212];unsigned int state;char unknownD8[24];W3dS1SessionFlags flags;char unknownF4[12];Ptr32<W3dS1SessionRef> held;};
void w3d_fn_8006ab48(Ptr32<W3dS1SessionTransition> self,unsigned int state,unsigned int deferred,int unused3,int unused4)
{
    self->flags.raw&=~0x0c000000U;
    Ptr32<W3dS1SessionRef> held=(Ptr32<W3dS1SessionRef>)self->held;
    if(held)held->vtable->release(held);
    self->held=0;
    unsigned int flags=self->flags.raw;
    if(flags&0x04000000U) {
        self->state=state;
        flags=(flags&~0x04000000U)|0x20000000U;
        self->flags.raw=flags;
        self->flags.bits.deferred=deferred;
        Ptr32<W3dS1SessionMessage> message=w3d_fn_801613f0(w3d_queue_804b1754,8);
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
int w3d_fn_8006ae58(Ptr32<void> self)
{
    unsigned char index;int available,ready;
    Ptr32<unsigned int> used=w3d_fn_8006ac90(self);
    index=0;
    do {
        if(!used[index]) {
            Ptr32<W3dS1SessionCache> cache=w3d_cache_context_804b17ec->cache;
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


