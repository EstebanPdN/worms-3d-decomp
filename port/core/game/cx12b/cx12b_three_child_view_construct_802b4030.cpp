#include "w3d_ptr.h"
#line 1 "cx12b_three_child_view_construct_802b4030.cpp"

struct Owner{Ptr32<void> vtable;unsigned char opaque[204];Ptr32<void> second;int a,b,c;Ptr32<void> children[3];int d,e,f,g,h,i,j;};extern "C" int base_8015fef0(Ptr32<Owner>);extern "C" Ptr32<void> member_802afb20(Ptr32<void>);extern "C" unsigned char table_8041c700[],table_8041c6b0[];
extern "C" Ptr32<Owner> w3d_cx12b_three_child_view_construct_802b4030(Ptr32<Owner> self){base_8015fef0(self);member_802afb20((Ptr32<unsigned char>)self+28);self->second=table_8041c6b0;self->vtable=table_8041c700;Ptr32<Ptr32<void>> p=self->children;int n=3;do{*p++=0;}while(--n);self->d=0;self->e=0;self->g=0;self->h=0;self->i=0;self->j=0;self->a=0;self->b=0;self->c=0;self->f=0;return self;}



