typedef unsigned int u32;
typedef struct Obj Obj;
typedef struct Vtable { void *pad[3]; void (*retain)(Obj *); void (*release)(Obj *); void *pad2[2]; void (*seek)(Obj *,u32,int,int); } Vtable;
struct Obj { Vtable *vtable; };
typedef struct { char pad[52]; u32 a,b,c; } Entry;
typedef struct { char pad[20]; Obj *stream; } Owner;
extern char *strncpy(char *,const char *,u32);
extern Entry *fn_801f8d6c(Owner *,const char *);
extern void *fn_801fe1d8(u32);
extern Obj *fn_801f9290(void *);
extern int fn_801f937c(Obj *,Owner *,u32,u32,u32);
extern int printf(const char *,...);
extern char lbl_803b18d8[],lbl_803b18fc[],lbl_803b191c[];
int terra_only_c10_zip_801f8568(Owner *owner,const char *name,int unused,Obj **out) {
 char buf[256]; char *p; Entry *entry; Obj *obj; int result;
 *out=0;
 strncpy(buf,name,255); buf[255]=0;
 p=buf;
 while (*p) { if (*p=='\\') *p='/'; p++; }
 entry=fn_801f8d6c(owner,buf);
 if (!entry) { printf(lbl_803b18d8,name); return 0x80004005; }
 owner->stream->vtable->seek(owner->stream,entry->a,0,0);
 obj=fn_801f9290(fn_801fe1d8(0x8064));
 obj->vtable->retain(obj);
 result=fn_801f937c(obj,owner,entry->a,entry->b,entry->c);
 if (result<0) { obj->vtable->release(obj); printf(lbl_803b18fc,name); return result; }
 *out=obj; printf(lbl_803b191c,name); return 0;
}
