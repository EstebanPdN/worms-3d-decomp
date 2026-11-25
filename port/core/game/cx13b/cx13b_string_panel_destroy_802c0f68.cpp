#include "w3d_ptr.h"
#line 1 "cx13b_string_panel_destroy_802c0f68.cpp"
// PPC32 vtable slots +12/+16 are retain/release; object field meanings inferred.
struct Interface;struct Vtable{Ptr32<void (Ptr32<Interface>)> slots[5];};struct Interface{Ptr32<Vtable> vtable;};inline void release(Ptr32<Interface> p){if(p)p->vtable->slots[4](p);}

struct String{Ptr32<char> data;};struct Object{Ptr32<void> table;unsigned char opaque[24];Ptr32<Interface> a; Ptr32<Interface> b; Ptr32<Interface> c;float state;String text;unsigned char gap[20];Ptr32<Interface> d;};extern "C" unsigned char table_8041c8a0[];extern "C" void finish_8020c5c4(Ptr32<String>);extern "C" void string_80341588(Ptr32<String>);extern "C" void base_8015ff2c(Ptr32<Object>,int);
extern "C" void w3d_cx13b_string_panel_destroy_802c0f68(Ptr32<Object> self,int flags){self->table=table_8041c8a0;release(self->d);Ptr32<String> s=&self->text;finish_8020c5c4(s);string_80341588(s);release(self->c);release(self->b);release(self->a);base_8015ff2c(self,flags);}



