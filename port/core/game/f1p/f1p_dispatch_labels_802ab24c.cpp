#include "w3d_ptr.h"
#line 1 "f1p_dispatch_labels_802ab24c.cpp"
// Partial observed labels and owner state; semantic roles inferred.
extern "C" void fn_8020c5c0(Ptr32<void>);extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct String{Ptr32<char> text;String(const String&o){fn_8020c5c0(this);text=o.text;Ptr32<unsigned short> h=fn_80341884(this);++*h;}};
struct Context{char pad[144];String c,b,a;};
struct Owner{char pad[40];Ptr32<Context> context;char pad44[184];int a,b,c;char pad240[1076];int ia,ib,ic;char pad1328[48];int updating;};
extern const int table_803d6b7c[],table_803d6bd0[],table_803d6c24[];
extern "C" void fn_802aa71c(Ptr32<Owner>,String,int);
extern "C" void w3d_dispatch_labels_802ab24c(Ptr32<Owner> self){if(!self->updating){self->a=table_803d6b7c[self->ia];self->b=table_803d6bd0[self->ib];self->c=table_803d6c24[self->ic];Ptr32<Context> ctx=self->context;fn_802aa71c(self,ctx->a,self->a);fn_802aa71c(self,ctx->b,self->b);fn_802aa71c(self,ctx->c,self->c);}}


