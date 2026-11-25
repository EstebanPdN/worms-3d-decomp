#include "w3d_ptr.h"
#line 1 "f1p_construct_categories_8027b528.cpp"
// Partial category state and pair layouts inferred from original stores.
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct Tail{int a,b;Tail(){b=0;}};struct Pair{int a,b;Pair(){a=0;b=0;}};
struct Owner{char base[28];int zero28,zero32;Tail a;Pair b;Tail c;Pair d;Tail e;Pair f;Tail g;Pair h;Tail i;int state108,state112,state116;int zero120,zero124,zero128,zero132,zero136,zero140,zero144,zero148,zero152,zero156;};
extern char vt_8041bec0[];extern Ptr32<Owner> instance_804abbac;extern "C" Ptr32<void> fn_801628b0(Ptr32<void>);
extern "C" Ptr32<Owner> w3d_construct_categories_8027b528(Ptr32<Owner> self){fn_801628b0(self);self->zero28=0;*(Ptr32<Ptr32<void>>)self=vt_8041bec0;self->zero32=0;new(&self->a)Tail;new(&self->b)Pair;new(&self->c)Tail;new(&self->d)Pair;new(&self->e)Tail;new(&self->f)Pair;new(&self->g)Tail;new(&self->h)Pair;new(&self->i)Tail;self->zero120=0;self->zero124=0;self->zero128=0;self->zero132=0;self->zero136=0;self->zero140=0;self->zero144=0;self->zero148=0;self->zero152=0;self->zero156=0;instance_804abbac=self;self->state108=17;self->state112=17;self->state116=17;// Forty original frame bytes have unknown purpose.
volatile char unknown_frame[40];return self;}


