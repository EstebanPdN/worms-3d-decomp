#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "terra_only_c10_zip_801f8568.c"
typedef unsigned int u32;
typedef struct Obj Obj;
typedef struct Vtable { Ptr32<void> pad[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; Ptr32<void> pad2[2]; Ptr32<void (Ptr32<Obj>, u32, int, int)> seek; } Vtable;
struct Obj { Ptr32<Vtable> vtable; };
typedef struct { char pad[52]; u32 a,b,c; } Entry;
typedef struct { char pad[20]; Ptr32<Obj> stream; } Owner;
extern Ptr32<char> strncpy(Ptr32<char>,Ptr32<const char>,u32);
extern Ptr32<Entry> fn_801f8d6c(Ptr32<Owner>,Ptr32<const char>);
extern Ptr32<void> fn_801fe1d8(u32);
extern Ptr32<Obj> fn_801f9290(Ptr32<void>);
extern int fn_801f937c(Ptr32<Obj>,Ptr32<Owner>,u32,u32,u32);
extern int printf(Ptr32<const char>,...);
extern char lbl_803b18d8[],lbl_803b18fc[],lbl_803b191c[];
int terra_only_c10_zip_801f8568(Ptr32<Owner> owner,Ptr32<const char> name,int unused,Ptr32<Ptr32<Obj>> out) {
 char buf[256]; Ptr32<char> p; Ptr32<Entry> entry; Ptr32<Obj> obj; int result;
 *out=0;
 strncpy(buf,name,255); buf[255]=0;
 p=buf;
 while (*p) { if (*p=='\\') *p='/'; p++; }
 entry=fn_801f8d6c(owner,buf);
 if (!entry) { printf(lbl_803b18d8,w3d::VA(name)); return 0x80004005; }
 owner->stream->vtable->seek(owner->stream,entry->a,0,0);
 obj=fn_801f9290(fn_801fe1d8(0x8064));
 obj->vtable->retain(obj);
 result=fn_801f937c(obj,owner,entry->a,entry->b,entry->c);
 if (result<0) { obj->vtable->release(obj); printf(lbl_803b18fc,w3d::VA(name)); return result; }
 *out=obj; printf(lbl_803b191c,w3d::VA(name)); return 0;
}

}
