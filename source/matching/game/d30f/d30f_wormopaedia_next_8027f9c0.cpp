// GWMP8P rev0 0x8027f9c0. Wormopaedia next page: reads the current index
// property, finds the next listed entry accepted by 0x8028496c, writes the
// index back and refreshes through 0x8027fca8. The empty do-while around the
// hit block and the gotos are chosen by instruction effect: the loop-end
// note stops CSE following the taken branch, so the list pointer is really
// reloaded.
struct D25fHeldTable { char pad[16]; void (*release)(void *); };
struct D25fHeld { D25fHeldTable *vt; };
struct D25fRef {
    D25fHeld *p;
    D25fRef() : p(0) {}
    ~D25fRef() { if (p) p->vt->release(p); }
};
extern "C" void w3d_string_base_init(void *);
extern "C" unsigned short *w3d_string_header(const void *);
struct D25fString {
    char *text;
    D25fString(const D25fString &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
};
struct D25fName { const char *text; D25fName(const char *t) : text(t) {} };
extern char lbl_803cee10[];
extern char lbl_803cee1c[];
struct D25fEntry { char pad[24]; D25fString name; };
struct D25fList { char pad[24]; unsigned count; char pad28[4]; D25fEntry *entries[1]; };
struct D25fData { char pad[20]; D25fList *list; };
extern "C" int w3d_auto_800fc230(const D25fName &, unsigned *);
extern "C" int s8_property_write_800fc43c(const D25fName &, unsigned);
extern "C" int w3d_constructor_lookup_name(const D25fName &, D25fRef *);
extern "C" void *w3d_empty_80341584(D25fHeld *);
extern "C" D25fData *w3d_auto_801797b4(void *);
struct D25fSelf;
extern "C" int f_8028496c(D25fSelf *self, D25fString name);
extern "C" void f_8027fca8(D25fSelf *self);
struct D25fSelf { char pad[160]; unsigned first, last, total; };
inline bool InRange(D25fData *d, unsigned n) { return d->list->count > n; }
inline D25fEntry **Items(D25fData *d) { return d->list->entries; }
extern "C" void d30f_wormopaedia_next_8027f9c0(D25fSelf *self) {
    unsigned current;
    w3d_auto_800fc230(D25fName(lbl_803cee10), &current);
    if (current < self->last) {
        D25fRef ref;
        D25fData *data;
        unsigned n, i;
        D25fEntry **entries;
        if (w3d_constructor_lookup_name(D25fName(lbl_803cee1c), &ref) < 0)
            goto fail;
        data = w3d_auto_801797b4(w3d_empty_80341584(ref.p));
        n = current;
        if (InRange(data, n))
            goto body;
    fail:
        return;
        do {
        hit:
            current = i;
            goto found;
        } while (0);
    body:
        entries = Items(data);
        for (i = n + 1; i <= self->last; i++) {
            if (f_8028496c(self, entries[i]->name) == 0)
                goto hit;
        }
        found:
        s8_property_write_800fc43c(D25fName(lbl_803cee10), current);
        f_8027fca8(self);
    }
}
