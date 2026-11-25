#include "w3d_ptr.h"
#line 1 "cx16b_interface_key_nth_801af870.cpp"
/* Observed twenty-four-byte lookup records have an interface pointer +0
   and a sixteen-byte comparison key +4. Failure is original 0x80004005. */
struct Cx16bLookupIface { Ptr32<Ptr32<void>> vtable; };
struct Cx16bLookupRecord { Ptr32<Cx16bLookupIface> held; unsigned char key[16]; unsigned tail; };
struct Cx16bLookupRange { Ptr32<Cx16bLookupRecord> begin; Ptr32<Cx16bLookupRecord> end; Ptr32<Cx16bLookupRecord> capacity; };
struct Cx16bLookupOwner { char pad[20]; Cx16bLookupRange records; };
extern "C" int fn_802eedc0(Ptr32<const void>,Ptr32<const void>,unsigned);
extern "C" unsigned w3d_cx16b_interface_key_nth_801af870(Ptr32<Cx16bLookupOwner> self,Ptr32<const void> key,unsigned nth,Ptr32<Ptr32<Cx16bLookupIface>> out)
{
    unsigned found=0;
    Ptr32<Cx16bLookupRecord> record=self->records.begin;
    if(found<=nth){
        Ptr32<Cx16bLookupRange> range=&self->records;
        Ptr32<Cx16bLookupIface> zero=0;
        do{
            for(;record!=range->end;++record)if(fn_802eedc0(record->key,key,16)==0)break;
            if(record==range->end){*out=zero;return 0x80004005U;}
            if(found!=nth)++record;
            ++found;
        }while(found<=nth);
    }
    Ptr32<Cx16bLookupIface> item=record->held;
    *out=item;
    ((Ptr32<void (Ptr32<Cx16bLookupIface>)>)item->vtable[3])(item);
    return 0;
}


