/* Copies one record out of a table of 24-byte entries (an object pointer, a
   16-byte record and a shared string), stores the entry's object through the
   second output after taking a reference through its virtual slot 3, and, when
   a string output is supplied, retains the entry's string and releases the
   string previously held there. The entry index scales by 24 and the table
   pointer is reloaded for each use. Offsets are observed; field names and
   meanings are inferred. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct Iface { void **vtable; } Iface;
typedef struct { int a, b, c, d; } Rec;
typedef struct { Iface *obj; Rec rec; char *name; } Entry;
typedef struct { char p0[20]; Entry *entries; } Self;
extern void fn_8020bb2c(W3dStringHeader *);
#define E(s, off) ((Entry *)((char *)(s)->entries + (off)))
int tsonnet_b36_entry_copy_801af73c(Self *s, int idx, Rec *rec, Iface **obj, char **name) {
    int off = idx * 24;
    Iface *o;
    *rec = E(s, off)->rec;
    o = E(s, off)->obj;
    *obj = o;
    ((void (*)(Iface *))o->vtable[3])(o);
    if (name) {
        Entry *e = E(s, off);
        ++((W3dStringHeader *)(e->name - 6))->references;
        {
            W3dStringHeader *old = (W3dStringHeader *)(*name - 6);
            if (--old->references == 0)
                fn_8020bb2c(old);
        }
        *name = e->name;
    }
    return 0;
}
