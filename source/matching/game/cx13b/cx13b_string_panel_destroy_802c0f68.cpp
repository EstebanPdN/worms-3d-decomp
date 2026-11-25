// PPC32 vtable slots +12/+16 are retain/release; object field meanings inferred.
struct Interface;struct Vtable{void(*slots[5])(Interface*);};struct Interface{Vtable*vtable;};inline void release(Interface*p){if(p)p->vtable->slots[4](p);}

struct String{char*data;};struct Object{void*table;unsigned char opaque[24];Interface*a,*b,*c;float state;String text;unsigned char gap[20];Interface*d;};extern "C" unsigned char table_8041c8a0[];extern "C" void finish_8020c5c4(String*);extern "C" void string_80341588(String*);extern "C" void base_8015ff2c(Object*,int);
extern "C" void w3d_cx13b_string_panel_destroy_802c0f68(Object*self,int flags){self->table=table_8041c8a0;release(self->d);String*s=&self->text;finish_8020c5c4(s);string_80341588(s);release(self->c);release(self->b);release(self->a);base_8015ff2c(self,flags);}

