// Load a buffered mesh payload (Worms 3D GameCube PAL, 0x8019805c).
//
// When the request at +12 is in state 2, allocates (count * 24 rounded up to
// 32 bytes) from the registry heap or prints "Not enough..." and returns 0,
// starts the read (0x8020f618), waits for state 3, then gives each list entry
// its span of the buffer. Returns 1.

extern "C" int fn_8020f3b0(void *);
extern "C" void *fn_80343810();
extern "C" unsigned fn_801981f8(void *);
extern "C" void *fn_801981d0(void *, unsigned);
extern "C" void *fn_80343944();
extern "C" int fn_8020f618(void *, void *, void *, unsigned);
extern "C" void fn_802fb7ac(const char *, ...);
extern char text_803a854c[];
struct Span { char *data; unsigned short count;
    unsigned short get() { return count; }
    void set(char *p, unsigned short n) { data = p; count = n; }
};
struct Entry { int u0; Span span; };
struct Owner { char *data; unsigned short total; unsigned short entries; int u8; char request[4]; };
struct List { Entry *items; };
inline void wait_done(void *r) { while (fn_8020f3b0(r) != 3) ; }
extern "C" int d24j_load_buffer_8019805c(Owner *self, List *list)
{
    if (fn_8020f3b0(self->request) == 2) {
        unsigned size = (self->total * 24 + 31) & ~31u;
        if (fn_801981f8(fn_80343810()) < size) {
            fn_802fb7ac(text_803a854c);
            return 0;
        }
        self->data = (char *)fn_801981d0(fn_80343810(), size);
        fn_8020f618(fn_80343944(), self->request, self->data, size);
        while (fn_8020f3b0(self->request) != 3) ;
        char *cursor = self->data;
        for (unsigned i = 0; i < self->entries; i++) {
            Entry *e = &list->items[i];
            Span &sp = e->span;
            sp.set(cursor, sp.get());
            cursor += sp.get() * 24;
        }
    }
    return 1;
}
