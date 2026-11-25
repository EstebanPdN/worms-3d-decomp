#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b36_entry_copy_801af73c.c"
/* Copies one record out of a table of 24-byte entries (an object pointer, a
   16-byte record and a shared string), stores the entry's object through the
   second output after taking a reference through its virtual slot 3, and, when
   a string output is supplied, retains the entry's string and releases the
   string previously held there. The entry index scales by 24 and the table
   pointer is reloaded for each use. Offsets are observed; field names and
   meanings are inferred. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct Iface { Ptr32<Ptr32<void>> vtable; } Iface;
typedef struct { int a, b, c, d; } Rec;
typedef struct { Ptr32<Iface> obj; Rec rec; Ptr32<char> name; } Entry;
typedef struct { char p0[20]; Ptr32<Entry> entries; } Self;
extern void fn_8020bb2c(Ptr32<W3dStringHeader>);
#define E(s, off) ((Entry *)w3d::AG((char *)(s)->entries + (off)))
int tsonnet_b36_entry_copy_801af73c(Ptr32<Self> s, int idx, Ptr32<Rec> rec, Ptr32<Ptr32<Iface>> obj, Ptr32<Ptr32<char>> name) {
    int off = idx * 24;
    Ptr32<Iface> o;
    *rec = E(s, off)->rec;
    o = E(s, off)->obj;
    *obj = o;
    ((Ptr32<void (Ptr32<Iface>)>)o->vtable[3])(o);
    if (name) {
        Ptr32<Entry> e = E(s, off);
        ++((Ptr32<W3dStringHeader>)(e->name - 6))->references;
        {
            Ptr32<W3dStringHeader> old = (Ptr32<W3dStringHeader>)(*name - 6);
            if (--old->references == 0)
                fn_8020bb2c(old);
        }
        *name = e->name;
    }
    return 0;
}

}
