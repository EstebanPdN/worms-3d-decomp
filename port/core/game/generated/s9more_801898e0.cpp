#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9more_801898e0.c"
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

Ptr32<void> s9_property_data_801898e0(Ptr32<void> self)
{
    Ptr32<void> parent=FIELD(self,void *,168);
    Ptr32<void> owner=FIELD(parent,void *,52);
    Ptr32<Ptr32<S9PropertyHeader>> slot=(Ptr32<Ptr32<S9PropertyHeader>>)((Ptr32<char>)owner+36);
    Ptr32<S9PropertyHeader> h=*slot;
    int kind=h->kind;
    int count=h->count;
    Ptr32<void> result;
    if(kind!=1) goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,8,2);
done:
    return result;
}

unsigned char s9_virtual_byte_8018c57c(Ptr32<void> self)
{
    Ptr32<void> inner=FIELD(self,void *,116);
    return *FIELD(FIELD(inner,void *,0),S9ByteMethod,72)(inner);
}

}
