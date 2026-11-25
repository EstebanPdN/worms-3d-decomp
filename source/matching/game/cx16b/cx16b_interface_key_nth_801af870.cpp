/* Observed twenty-four-byte lookup records have an interface pointer +0
   and a sixteen-byte comparison key +4. Failure is original 0x80004005. */
struct Cx16bLookupIface { void **vtable; };
struct Cx16bLookupRecord { Cx16bLookupIface *held; unsigned char key[16]; unsigned tail; };
struct Cx16bLookupRange { Cx16bLookupRecord *begin,*end,*capacity; };
struct Cx16bLookupOwner { char pad[20]; Cx16bLookupRange records; };
extern "C" int fn_802eedc0(const void *,const void *,unsigned);
extern "C" unsigned w3d_cx16b_interface_key_nth_801af870(Cx16bLookupOwner *self,const void *key,unsigned nth,Cx16bLookupIface **out)
{
    unsigned found=0;
    Cx16bLookupRecord *record=self->records.begin;
    if(found<=nth){
        Cx16bLookupRange *range=&self->records;
        Cx16bLookupIface *zero=0;
        do{
            for(;record!=range->end;++record)if(fn_802eedc0(record->key,key,16)==0)break;
            if(record==range->end){*out=zero;return 0x80004005U;}
            if(found!=nth)++record;
            ++found;
        }while(found<=nth);
    }
    Cx16bLookupIface *item=record->held;
    *out=item;
    ((void(*)(Cx16bLookupIface *))item->vtable[3])(item);
    return 0;
}
