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

int s9_lookup_slot_80176974(void *self,void *key,void **out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_80178c48(fn_803426b4(*(void **)((index*4)+FIELD(self,int,24))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}
