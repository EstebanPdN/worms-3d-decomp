/* Recovered from original DOL 0x8020c43c..0x8020c510 (exclusive).
   Observed GC32 shared-string layout; semantic names are inferred.
   Keep the pre-call sum in its own local: folding it into the argument
   changes the reference compiler's temporary register allocation.
   No inline assembly, fixed registers or extra compiler flags are used. */
typedef unsigned short u16;
typedef unsigned int u32;
struct CxcHeader { u16 refs,length,capacity; };
struct CxcString { char *data; };
extern struct CxcHeader *fn_8020bc88(struct CxcString *,u32);
extern void fn_8020bb2c(struct CxcHeader *);
/* The original sets the varargs CR marker before both copy calls. */
extern void *fn_802eee50();
static inline struct CxcHeader *cxc_ensure(struct CxcString *self,u32 needed,u32 length,struct CxcHeader *old,u32 refs)
{
    struct CxcHeader *next;
    if (refs==1 && old->capacity>=needed) next=old;
    else {
        char *data=self->data;
        next=fn_8020bc88(self,needed);
        fn_802eee50(self->data,data,length);
        if (--old->refs==0) fn_8020bb2c(old);
    }
    return next;
}
void cxc_append_8020c43c(struct CxcString *self,const char *text,u32 count)
{
    struct CxcHeader *old=(struct CxcHeader *)(self->data-6);
    u32 refs=old->refs;
    u32 length=old->length;
    u32 total=count+length;
    struct CxcHeader *next=cxc_ensure(self,total+1,length,old,refs);
    fn_802eee50(self->data+length,text,count);
    next->length=length+count;
    self->data[length+count]=0;
}
