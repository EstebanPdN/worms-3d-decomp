/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Structural family templates; only observed fields and calls are named. */
#define FIELD(p,T,o) (*(T *)((char *)(p) + (o)))
typedef int (*S9Method)(void *);
typedef void (*S9VoidMethod)(void *);
typedef unsigned char *(*S9ByteMethod)(void *);
typedef int (*S9SubmitMethod)(void *, void *, int, int, int);
extern unsigned short lbl_804b18a4;
extern char *lbl_804b189c;
extern int fn_80185b0c(void *);
extern int fn_80185b24(void *);
extern void fn_80178b5c(void *,int);
typedef struct S9PropertyHeader { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short refs; char unknown30[2]; char data[1]; } S9PropertyHeader;
extern void *fn_801ef048(void *,int,int,int);
extern int fn_80177eb0(void *,void *,unsigned short *);
extern void *fn_803426b4(void *);
extern void *fn_80178c48(void *);

void *s9_property_data_801898e0(void *self)
{
    void *parent=FIELD(self,void *,168);
    void *owner=FIELD(parent,void *,52);
    S9PropertyHeader **slot=(S9PropertyHeader **)((char *)owner+36);
    S9PropertyHeader *h=*slot;
    int kind=h->kind;
    int count=h->count;
    void *result;
    if(kind!=1) goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,8,2);
done:
    return result;
}

unsigned char s9_virtual_byte_8018c57c(void *self)
{
    void *inner=FIELD(self,void *,116);
    return *FIELD(FIELD(inner,void *,0),S9ByteMethod,72)(inner);
}
