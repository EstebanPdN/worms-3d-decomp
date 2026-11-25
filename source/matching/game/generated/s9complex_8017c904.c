/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Observed property and smart-reference shapes. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef void (*S9RefFn)(void *);
typedef struct S9PropertyHeader { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short refs; char unknown30[2]; char data[1]; } S9PropertyHeader;
extern void *fn_801ef048(void *,int,int,int);
extern char lbl_80412970[];
extern void *fn_8020b680(void *);
extern int fn_8017f000(void *,void *);
extern int fn_8017c464(void *,void *);
extern unsigned int lbl_804ab5e8;
typedef struct S9HeldReference { void *pointer; } S9HeldReference;
static inline void *s9_access_property(S9PropertyHeader **slot, int count, int flags)
{
    S9PropertyHeader *h=*slot;
    void *result;
    if(h->kind!=1)goto slow;
    if(!flags && count!=h->count)goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,4,flags);
done:
    return result;
}
extern char lbl_80412ed0[];
extern int fn_8018a218(void *,void *);
extern char lbl_80412a90[];
extern int fn_80182778(void *,void *);

int s9_import_descriptors_8017c904(void *self,char *descriptors,unsigned int count)
{
    volatile S9HeldReference held;
    int failed=0;
    unsigned int i;
    unsigned int *maximum;
    for(i=0;i<count;i++) {
        char *entry=descriptors+i*20;
        void *object=fn_8020b680(lbl_80412970);
        held.pointer=object;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,12)(object);
        fn_8017f000(held.pointer,entry);
        if(fn_8017c464(self,held.pointer)==0)failed=1;
        object=held.pointer;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,16)(object);
    }
    { unsigned int *current=(unsigned int *)((char *)self+9752);
      maximum = lbl_804ab5e8 < *current ? current : &lbl_804ab5e8; }
    lbl_804ab5e8=*maximum;
    { int result=0x80004005; if(!failed)result=0; return result; }
}

int s9_import_descriptors_8017cafc(void *self,char *descriptors,unsigned int count)
{
    volatile S9HeldReference held;
    int failed=0;
    unsigned int i;
    unsigned int *maximum;
    for(i=0;i<count;i++) {
        char *entry=descriptors+i*24;
        void *object=fn_8020b680(lbl_80412ed0);
        held.pointer=object;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,12)(object);
        fn_8018a218(held.pointer,entry);
        if(fn_8017c464(self,held.pointer)==0)failed=1;
        object=held.pointer;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,16)(object);
    }
    { unsigned int *current=(unsigned int *)((char *)self+9752);
      maximum = lbl_804ab5e8 < *current ? current : &lbl_804ab5e8; }
    lbl_804ab5e8=*maximum;
    { int result=0x80004005; if(!failed)result=0; return result; }
}

int s9_import_descriptors_8017cbec(void *self,char *descriptors,unsigned int count)
{
    volatile S9HeldReference held;
    int failed=0;
    unsigned int i;
    unsigned int *maximum;
    for(i=0;i<count;i++) {
        char *entry=descriptors+i*8;
        void *object=fn_8020b680(lbl_80412a90);
        held.pointer=object;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,12)(object);
        fn_80182778(held.pointer,entry);
        if(fn_8017c464(self,held.pointer)==0)failed=1;
        object=held.pointer;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,16)(object);
    }
    { unsigned int *current=(unsigned int *)((char *)self+9752);
      maximum = lbl_804ab5e8 < *current ? current : &lbl_804ab5e8; }
    lbl_804ab5e8=*maximum;
    { int result=0x80004005; if(!failed)result=0; return result; }
}
