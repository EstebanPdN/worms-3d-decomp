#include "w3d_ptr.h"
#line 1 "d27l_movie_open_802e04e0.cpp"
// GWMP8P rev0 0x802e04e0. Movie player open: appends .thp to the name, opens
// the file, reads the 48-byte header and 20-byte component record into the
// stream, checks magic and version, reads the component headers, resets
// stream state, allocates the frame buffer, sets texture planes and quad
// placement. Strings are one word with a base class holding the out-of-line
// init; Player, Stream field names are inferred; 60.0f is the literal at
// 0x803db224.
// partial views
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct Base { Base() { fn_8020c5c0(this); } Ptr32<char> p; };
struct Str : Base {
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        p = o.p;
        Ptr32<unsigned short> h = fn_80341884(this);
        ++*h;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
};
extern "C" Ptr32<void> fn_8020bf2c(Ptr32<Str>, Ptr32<const char>);
inline Str operator+(const Str &a, const char *b) {
    Str r(a);
    fn_8020bf2c(&r, b);
    return r;
}
struct Header { int magic, version, w8, w12; float w16; int w20; int w24, w28, w32, w36, w40, w44; };
struct Comp { int w0, w4, w8, w12, w16; };
struct Stream {
    char file[60];
    Header hdr;
    Comp comp;
    unsigned width, height;
    int w136;
    int audio[4];
    char u156[4];
    int open, w164, w168, w172, w176, w180, w184;
    char u188[4];
    int w192, w196, w200, w204;
    char u208[136];
    Ptr32<void> plane0; Ptr32<void> plane1; Ptr32<void> plane2;
    int w356;
    char u360[48];
    int w408, w412;
};
struct Player {
    Ptr32<void> vt;
    Ptr32<Stream> stream;
    Ptr32<void> tex;
    int init;
    char u16[28];
    short x, y, w, h;
    int w52;
    Ptr32<void> buffer;
    int w60, w64;
    char u68[4];
    unsigned sw, sh;
    char u80[4];
    int state;
};
extern char s_803db090[], s_803db10c[], s_803db144[], s_803db14c[], s_803db15c[], s_803db184[], s_803db188[], s_803db1a0[], s_803db1bc[], s_803db1f8[], s_803db208[];
extern "C" int fn_802ebfbc(Ptr32<const char>, ...);
extern "C" int fn_802fb7ac(Ptr32<const char>, ...);
extern "C" int fn_802fb82c(Ptr32<const char>, int, Ptr32<const char>, ...);
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int fn_802f5258(Ptr32<const char>, Ptr32<Stream>);
extern "C" int fn_802f5320(Ptr32<Stream>);
extern "C" Ptr32<void> fn_80343994();
extern "C" int fn_801fdcac(Ptr32<void>, Ptr32<Stream>, Ptr32<char>, int, int);
extern "C" int fn_802e09c4(Ptr32<Player>, Ptr32<char>, Ptr32<int>);
extern "C" int fn_802e10b8(Ptr32<Player>);
extern "C" void fn_80209920(Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<void> fn_802098fc(Ptr32<void>, int, int);
extern "C" int fn_802e1134(Ptr32<Player>, Ptr32<void>);
extern "C" void fn_802e22c0(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, unsigned short, unsigned short);
extern "C" int fn_80304c00();
extern Ptr32<void> heap_804ab8b4;
extern "C" int d27l_movie_open_802e04e0(Ptr32<Player> self, Ptr32<const char> name) {
    char raw[95];
    if (!self->init) {
        fn_802ebfbc(s_803db090);
        return 0;
    }
    Ptr32<char> buf = (Ptr32<char>)w3d::G(((unsigned)w3d::H((raw + 31)) & ~31));
    if (self->stream->open) {
        fn_802fb7ac(s_803db10c);
        self->state = 7;
        return 0;
    }
    memset(&self->stream->width, 0, 12);
    memset(self->stream->audio, 0, 16);
    Str path = Str(name) + s_803db144;
    if (!fn_802f5258(path.p, self->stream)) {
        fn_802fb7ac(s_803db14c, w3d::VA(name));
        self->state = 7;
        return 0;
    }
    if (fn_801fdcac(fn_80343994(), self->stream, buf, 64, 0)) {
        fn_802fb7ac(s_803db15c);
        fn_802f5320(self->stream);
        self->state = 7;
        return 0;
    }
    self->stream->hdr = *(Ptr32<Header>)buf;
    if (strcmp((Ptr32<char>)&self->stream->hdr, s_803db184)) {
        fn_802fb7ac(s_803db188);
        fn_802f5320(self->stream);
        self->state = 7;
        return 0;
    }
    if (self->stream->hdr.version != 0x11000) {
        fn_802fb7ac(s_803db1a0);
        fn_802f5320(self->stream);
        self->state = 7;
        return 0;
    }
    int offset = self->stream->hdr.w32;
    int err = fn_801fdcac(fn_80343994(), self->stream, buf, 32, offset);
    if (err) {
        fn_802fb7ac(s_803db1bc);
        fn_802f5320(self->stream);
        self->state = 7;
        return 0;
    }
    self->stream->comp = *(Ptr32<Comp>)buf;
    offset += 20;
    self->stream->w172 = 0;
    if (!fn_802e09c4(self, buf, &offset))
        return 0;
    self->stream->w184 = self->stream->hdr.w40;
    self->stream->w200 = self->stream->hdr.w24;
    self->stream->w196 = 0;
    self->stream->w204 = 0;
    self->stream->w176 = 0;
    self->stream->w356 = -1;
    self->stream->w192 = 0;
    self->stream->w408 = 0;
    self->stream->w412 = 0;
    self->stream->w164 = 0;
    self->stream->w168 = 0;
    self->stream->w180 = 0;
    self->stream->open = 1;
    int size = fn_802e10b8(self);
    if (self->buffer)
        fn_80209920(heap_804ab8b4, self->buffer);
    Ptr32<void> mem = fn_802098fc(heap_804ab8b4, size, 32);
    self->buffer = mem;
    if (!mem)
        fn_802fb82c(s_803db1f8, 378, s_803db208);
    fn_802e1134(self, self->buffer);
    fn_802e22c0(self->tex, self->stream->plane0, self->stream->plane1, self->stream->plane2, self->stream->width, self->stream->height);
    self->x = (self->sw - self->stream->width) / 2;
    self->y = (self->sh - self->stream->height) / 2;
    self->w = self->stream->width;
    self->h = self->stream->height;
    self->w60 = fn_80304c00() - 2;
    self->w64 = (int)(60.0f / self->stream->hdr.w16) - 1;
    self->state = 1;
    self->w52 = 0;
    return 1;
}


