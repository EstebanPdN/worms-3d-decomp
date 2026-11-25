#include "w3d_ptr.h"
#line 1 "f1p_setup_flag_802707f0.cpp"
// Ignored helper result types are inferred from observed call scheduling.
// Partial observed flag-control and context layouts; semantic roles inferred.
struct String_8020bb54{
 String_8020bb54(const String_8020bb54 &);Ptr32<char> text;template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char*);~String_8020bb54();};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
inline String_8020bb54::~String_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}
struct Vec3{float x,y,z;};
struct Item{Ptr32<Ptr32<void>> v;};struct Context{char pad[20];Vec3 size,position;};struct Owner{char pad[40];Ptr32<Context> context;char pad44[168];Ptr32<Item> flag;};
extern const char name_803cc024[];extern const float zero_803cc02c[];
extern "C" Ptr32<char> fn_80165254();extern "C" int fn_802b0b84(Ptr32<void>,Ptr32<Owner>,int),fn_8015adf4(Ptr32<String_8020bb54>,Ptr32<Ptr32<Item>>,int);
extern "C" void w3d_setup_flag_802707f0(Ptr32<Owner> self){fn_802b0b84((Ptr32<char>)self+28,self,*(Ptr32<int>)(fn_80165254()+52));{String_8020bb54 name(name_803cc024);fn_8015adf4(&name,&self->flag,255);}((Ptr32<void (Ptr32<Item>, Ptr32<const Vec3>, int)>)self->flag->v[19])(self->flag,&self->context->position,0);((Ptr32<void (Ptr32<Item>, Ptr32<const Vec3>, int)>)self->flag->v[21])(self->flag,&self->context->size,0);Vec3 zero;Ptr32<Vec3> p=&zero;p->x=zero_803cc02c[0];p->y=zero_803cc02c[0];p->z=zero_803cc02c[0];((Ptr32<void (Ptr32<Item>, Ptr32<Vec3>, int)>)self->flag->v[20])(self->flag,&zero,0);}


