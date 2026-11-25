#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9complex_8017c904.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Observed property and smart-reference shapes. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
typedef Ptr32<void (Ptr32<void>)> S9RefFn;
typedef struct S9PropertyHeader { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short refs; char unknown30[2]; char data[1]; } S9PropertyHeader;
extern Ptr32<void> fn_801ef048(Ptr32<void>,int,int,int);
extern char lbl_80412970[];
extern Ptr32<void> fn_8020b680(Ptr32<void>);
extern int fn_8017f000(Ptr32<void>,Ptr32<void>);
extern int fn_8017c464(Ptr32<void>,Ptr32<void>);
extern unsigned int lbl_804ab5e8;
typedef struct S9HeldReference { Ptr32<void> pointer; } S9HeldReference;
static inline Ptr32<void> s9_access_property(Ptr32<Ptr32<S9PropertyHeader>> slot, int count, int flags)
{
    Ptr32<S9PropertyHeader> h=*slot;
    Ptr32<void> result;
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
extern int fn_8018a218(Ptr32<void>,Ptr32<void>);
extern char lbl_80412a90[];
extern int fn_80182778(Ptr32<void>,Ptr32<void>);

int s9_import_descriptors_8017c904(Ptr32<void> self,Ptr32<char> descriptors,unsigned int count)
{
    volatile S9HeldReference held;
    int failed=0;
    unsigned int i;
    Ptr32<unsigned int> maximum;
    for(i=0;i<count;i++) {
        Ptr32<char> entry=descriptors+i*20;
        Ptr32<void> object=fn_8020b680(lbl_80412970);
        held.pointer=object;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,12)(object);
        fn_8017f000(held.pointer,entry);
        if(fn_8017c464(self,held.pointer)==0)failed=1;
        object=held.pointer;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,16)(object);
    }
    { Ptr32<unsigned int> current=(Ptr32<unsigned int>)((Ptr32<char>)self+9752);
      maximum = lbl_804ab5e8 < *current ? w3d::R(current) : w3d::R(&lbl_804ab5e8); }
    lbl_804ab5e8=*maximum;
    { int result=0x80004005; if(!failed)result=0; return result; }
}

int s9_import_descriptors_8017cafc(Ptr32<void> self,Ptr32<char> descriptors,unsigned int count)
{
    volatile S9HeldReference held;
    int failed=0;
    unsigned int i;
    Ptr32<unsigned int> maximum;
    for(i=0;i<count;i++) {
        Ptr32<char> entry=descriptors+i*24;
        Ptr32<void> object=fn_8020b680(lbl_80412ed0);
        held.pointer=object;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,12)(object);
        fn_8018a218(held.pointer,entry);
        if(fn_8017c464(self,held.pointer)==0)failed=1;
        object=held.pointer;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,16)(object);
    }
    { Ptr32<unsigned int> current=(Ptr32<unsigned int>)((Ptr32<char>)self+9752);
      maximum = lbl_804ab5e8 < *current ? w3d::R(current) : w3d::R(&lbl_804ab5e8); }
    lbl_804ab5e8=*maximum;
    { int result=0x80004005; if(!failed)result=0; return result; }
}

int s9_import_descriptors_8017cbec(Ptr32<void> self,Ptr32<char> descriptors,unsigned int count)
{
    volatile S9HeldReference held;
    int failed=0;
    unsigned int i;
    Ptr32<unsigned int> maximum;
    for(i=0;i<count;i++) {
        Ptr32<char> entry=descriptors+i*8;
        Ptr32<void> object=fn_8020b680(lbl_80412a90);
        held.pointer=object;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,12)(object);
        fn_80182778(held.pointer,entry);
        if(fn_8017c464(self,held.pointer)==0)failed=1;
        object=held.pointer;
        if(object)FIELD(FIELD(object,void *,0),S9RefFn,16)(object);
    }
    { Ptr32<unsigned int> current=(Ptr32<unsigned int>)((Ptr32<char>)self+9752);
      maximum = lbl_804ab5e8 < *current ? w3d::R(current) : w3d::R(&lbl_804ab5e8); }
    lbl_804ab5e8=*maximum;
    { int result=0x80004005; if(!failed)result=0; return result; }
}

}
