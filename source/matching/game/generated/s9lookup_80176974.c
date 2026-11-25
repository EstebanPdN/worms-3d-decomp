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
extern void *fn_80342a78(void *);
extern void *fn_80178d1c(void *);
extern void *fn_80341584(void *);
extern void *fn_801797b4(void *);
extern void *fn_80343858(void *);
extern void *fn_8017941c(void *);

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

int s9_lookup_slot_801769dc(void *self,void *key,void **out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_80178d1c(fn_80342a78(*(void **)((index*4)+FIELD(self,int,24))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}

int s9_lookup_slot_80176b98(void *self,void *key,void **out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_801797b4(fn_80341584(*(void **)((index*4)+FIELD(self,int,24))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}

int s9_lookup_slot_80176c00(void *self,void *key,void **out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_8017941c(fn_80343858(*(void **)((index*4)+FIELD(self,int,24))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}
