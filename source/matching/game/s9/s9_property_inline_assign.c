/* Observed property and smart-reference shapes. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef void (*S9RefFn)(void *);
typedef struct S9PropertyHeader { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short refs; char unknown30[2]; char data[1]; } S9PropertyHeader;
extern void *fn_801ef048(void *,int,int,int);
extern char lbl_80412970[];
extern void *fn_8020b680(void *);
extern void fn_8017f000(void *,void *);
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

void *s9_property_fallback_80189574(void *self)
{
    void *owner=FIELD(FIELD(self,void *,168),void *,48);
    int count;
    void *result=s9_access_property((S9PropertyHeader **)((char *)owner+88),count=FIELD(FIELD(owner,S9PropertyHeader *,88),int,24),2);
    int alternate_count;
    if(count)goto done;
    alternate_count=FIELD(FIELD(owner,void *,96),int,24);
    if(!alternate_count)return 0;
    result=s9_access_property((S9PropertyHeader **)((char *)owner+88),alternate_count,0);
done:
    return result;
}
