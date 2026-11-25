#include "w3d_ptr.h"
#line 1 "d24j_load_buffer_8019805c.cpp"
// Load a buffered mesh payload (Worms 3D GameCube PAL, 0x8019805c).
//
// When the request at +12 is in state 2, allocates (count * 24 rounded up to
// 32 bytes) from the registry heap or prints "Not enough..." and returns 0,
// starts the read (0x8020f618), waits for state 3, then gives each list entry
// its span of the buffer. Returns 1.

extern "C" int fn_8020f3b0(Ptr32<void>);
extern "C" Ptr32<void> fn_80343810();
extern "C" unsigned fn_801981f8(Ptr32<void>);
extern "C" Ptr32<void> fn_801981d0(Ptr32<void>, unsigned);
extern "C" Ptr32<void> fn_80343944();
extern "C" int fn_8020f618(Ptr32<void>, Ptr32<void>, Ptr32<void>, unsigned);
extern "C" void fn_802fb7ac(Ptr32<const char>, ...);
extern char text_803a854c[];
struct Span { Ptr32<char> data; unsigned short count;
    unsigned short get() { return count; }
    void set(Ptr32<char> p, unsigned short n) { data = p; count = n; }
};
struct Entry { int u0; Span span; };
struct Owner { Ptr32<char> data; unsigned short total; unsigned short entries; int u8; char request[4]; };
struct List { Ptr32<Entry> items; };
inline void wait_done(Ptr32<void> r) { while (fn_8020f3b0(r) != 3) ; }
extern "C" int d24j_load_buffer_8019805c(Ptr32<Owner> self, Ptr32<List> list)
{
    if (fn_8020f3b0(self->request) == 2) {
        unsigned size = (self->total * 24 + 31) & ~31u;
        if (fn_801981f8(fn_80343810()) < size) {
            fn_802fb7ac(text_803a854c);
            return 0;
        }
        self->data = (Ptr32<char>)fn_801981d0(fn_80343810(), size);
        fn_8020f618(fn_80343944(), self->request, self->data, size);
        while (fn_8020f3b0(self->request) != 3) ;
        Ptr32<char> cursor = self->data;
        for (unsigned i = 0; i < self->entries; i++) {
            Ptr32<Entry> e = &list->items[i];
            Span &sp = e->span;
            sp.set(cursor, sp.get());
            cursor += sp.get() * 24;
        }
    }
    return 1;
}


