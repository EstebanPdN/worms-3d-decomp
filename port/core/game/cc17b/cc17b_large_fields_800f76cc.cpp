#include "w3d_ptr.h"
#line 1 "cc17b_large_fields_800f76cc.cpp"
/* Observed repeated sixteen-byte blocks: one untouched word, followed by
   three zero-initialized words. Inline subobject constructors preserve the
   original address lifetimes; member meanings remain unresolved. */
inline void *operator new(__SIZE_TYPE__,void *place) { return place; }
struct Cc17bWordPair { unsigned first,second; Cc17bWordPair() {first=0;second=0;} };
struct Cc17bOffsetWord { unsigned untouched,value; Cc17bOffsetWord() {value=0;} };
struct Cc17bFieldBlock { Cc17bOffsetWord first; Cc17bWordPair second; };
struct Cc17bLargeFields { char base[28]; Cc17bWordPair initial;
 Cc17bFieldBlock block00;
 Cc17bFieldBlock block01;
 Cc17bFieldBlock block02;
 Cc17bFieldBlock block03;
 Cc17bFieldBlock block04;
 Cc17bFieldBlock block05;
 Cc17bFieldBlock block06;
 Cc17bFieldBlock block07;
 Cc17bFieldBlock block08;
 Cc17bFieldBlock block09;
 Cc17bFieldBlock block10;
 Cc17bFieldBlock block11;
 Cc17bFieldBlock block12;
 Cc17bFieldBlock block13;
 Cc17bFieldBlock block14;
 Cc17bFieldBlock block15;
 Cc17bFieldBlock block16;
 Cc17bFieldBlock block17;
 Cc17bFieldBlock block18;
 Cc17bFieldBlock block19;
 Cc17bFieldBlock block20;
 Cc17bFieldBlock block21;
 Cc17bFieldBlock block22;
 Cc17bFieldBlock block23;
 Cc17bFieldBlock block24;
};
extern "C" {
int fn_801628b0(Ptr32<void>);
extern unsigned vtable_80410480[];
extern Ptr32<Cc17bLargeFields> owner_804aaf48;
Ptr32<Cc17bLargeFields> w3d_cc17b_large_fields_800f76cc(Ptr32<Cc17bLargeFields> self) {
 /* The original reserves 200 additional bytes before saved registers.
    Their source role is unknown; keep the observed unused workspace explicit. */
 volatile unsigned char cc17b_observed_workspace[200];
 fn_801628b0(self);
 *(Ptr32<Ptr32<unsigned int>>)self=vtable_80410480;
 new(&self->initial) Cc17bWordPair;
 new(&self->block00) Cc17bFieldBlock;
 new(&self->block01) Cc17bFieldBlock;
 new(&self->block02) Cc17bFieldBlock;
 new(&self->block03) Cc17bFieldBlock;
 new(&self->block04) Cc17bFieldBlock;
 new(&self->block05) Cc17bFieldBlock;
 new(&self->block06) Cc17bFieldBlock;
 new(&self->block07) Cc17bFieldBlock;
 new(&self->block08) Cc17bFieldBlock;
 new(&self->block09) Cc17bFieldBlock;
 new(&self->block10) Cc17bFieldBlock;
 new(&self->block11) Cc17bFieldBlock;
 new(&self->block12) Cc17bFieldBlock;
 new(&self->block13) Cc17bFieldBlock;
 new(&self->block14) Cc17bFieldBlock;
 new(&self->block15) Cc17bFieldBlock;
 new(&self->block16) Cc17bFieldBlock;
 new(&self->block17) Cc17bFieldBlock;
 new(&self->block18) Cc17bFieldBlock;
 new(&self->block19) Cc17bFieldBlock;
 new(&self->block20) Cc17bFieldBlock;
 new(&self->block21) Cc17bFieldBlock;
 new(&self->block22) Cc17bFieldBlock;
 new(&self->block23) Cc17bFieldBlock;
 new(&self->block24.first) Cc17bOffsetWord;
 owner_804aaf48=self;self->block24.second.first=0;self->block24.second.second=0;return self;
}
}


