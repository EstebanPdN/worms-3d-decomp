#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9lookup_80176974.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Structural family templates; only observed fields and calls are named. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<int (Ptr32<void>)> S9Method;
typedef Ptr32<void (Ptr32<void>)> S9VoidMethod;
typedef Ptr32<Ptr32<unsigned char> (Ptr32<void>)> S9ByteMethod;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int, int, int)> S9SubmitMethod;
extern unsigned short lbl_804b18a4;
extern Ptr32<char> lbl_804b189c;
extern int fn_80185b0c(Ptr32<void>);
extern int fn_80185b24(Ptr32<void>);
extern void fn_80178b5c(Ptr32<void>,int);
typedef struct S9PropertyHeader { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short refs; char unknown30[2]; char data[1]; } S9PropertyHeader;
extern Ptr32<void> fn_801ef048(Ptr32<void>,int,int,int);
extern int fn_80177eb0(Ptr32<void>,Ptr32<void>,Ptr32<unsigned short>);
extern Ptr32<void> fn_803426b4(Ptr32<void>);
extern Ptr32<void> fn_80178c48(Ptr32<void>);
extern Ptr32<void> fn_80342a78(Ptr32<void>);
extern Ptr32<void> fn_80178d1c(Ptr32<void>);
extern Ptr32<void> fn_80341584(Ptr32<void>);
extern Ptr32<void> fn_801797b4(Ptr32<void>);
extern Ptr32<void> fn_80343858(Ptr32<void>);
extern Ptr32<void> fn_8017941c(Ptr32<void>);

int s9_lookup_slot_80176974(Ptr32<void> self,Ptr32<void> key,Ptr32<Ptr32<void>> out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_80178c48(fn_803426b4(*(Ptr32<Ptr32<void>>)w3d::G(((index*4)+FIELD(self,int,24)))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}

int s9_lookup_slot_801769dc(Ptr32<void> self,Ptr32<void> key,Ptr32<Ptr32<void>> out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_80178d1c(fn_80342a78(*(Ptr32<Ptr32<void>>)w3d::G(((index*4)+FIELD(self,int,24)))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}

int s9_lookup_slot_80176b98(Ptr32<void> self,Ptr32<void> key,Ptr32<Ptr32<void>> out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_801797b4(fn_80341584(*(Ptr32<Ptr32<void>>)w3d::G(((index*4)+FIELD(self,int,24)))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}

int s9_lookup_slot_80176c00(Ptr32<void> self,Ptr32<void> key,Ptr32<Ptr32<void>> out)
{
    unsigned short index;
    int result;
    if(fn_80177eb0(self,key,&index)<0) goto fail;
    *out=fn_8017941c(fn_80343858(*(Ptr32<Ptr32<void>>)w3d::G(((index*4)+FIELD(self,int,24)))));
    result=0;
    goto done;
fail:
    result=0x80004005;
done:
    return result;
}

}
