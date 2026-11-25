#include "w3d_ptr.h"
#line 1 "d29j_bind_texture_8016c338.cpp"
// Bind a texture on a stage through the renderer's secondary interface. Returns
// 0 with no header. Drops a stale GX object when the header's dirty bit is set,
// records the size, and when there is no object loads one with the wrap modes
// from the table at 0x803a569c through the loader table at +24 of the interface,
// indexed by the header's format index, then hands it to the device. Palette
// formats 19 and 20 load their palette; a new object is loaded on the stage and
// the stage count advances. GWMP8P rev0 0x8016c338.
struct Object;
extern "C" void fn_8030a21c(Ptr32<Object>, int);
struct Header { char u[6]; unsigned short index; char u8[12]; int palette; int format; unsigned short u1c; char u1e[14]; unsigned short height, width; };
struct Loader;
struct Texture { char u[36]; int wrapT; int wrapS; char u2c[4]; Ptr32<Object> object; char u34[8]; Ptr32<Header> header; };
struct DeviceVt { Ptr32<void> u[5]; Ptr32<void (Ptr32<struct Device>, Ptr32<Texture>, Ptr32<Object>)> make; };
struct Device { Ptr32<DeviceVt> vt; };
struct Global;
extern Ptr32<Global> global_804b1884;
extern Ptr32<Object> current_804ab544;
extern const int wrap_803a569c[];
struct Flags { char u[4]; unsigned char bits; char w3d_tag_rest[3]; };
struct Base { Ptr32<void> vtable; };
struct Sink { Ptr32<Ptr32<void>> loaders_at_20; };
struct R : Base, Sink { char u[140] __attribute__((aligned(__alignof__(Base)), aligned(__alignof__(Sink)))); Ptr32<Device> device; char u98[40]; unsigned short h, w; char uc4[20]; int stage; char udc[76]; int wrapS; int wrapT; char u130[8]; Ptr32<Object> result; };
extern "C" int fn_8016c4f4(Ptr32<Sink>, Ptr32<void>);
extern "C" void fn_8016803c(Ptr32<Global>, int);
extern "C" int d29j_bind_texture_8016c338(Ptr32<Sink> sink, Ptr32<Texture> t)
{
    Ptr32<R> self = w3d::sc<R *>(sink);
    Ptr32<Header> h = t->header;
    if (h == 0) return 0;
    Ptr32<Object> o = t->object;
    if (o) {
        Ptr32<Flags> f = (Ptr32<Flags>)((Ptr32<char>)h + 4);
        if (f->bits & 2) {
            t->object = 0;
            o = 0;
            f->bits &= ~2;
        }
    }
    self->h = t->header->width;
    self->w = t->header->height;
    if (o == 0) {
        self->wrapS = wrap_803a569c[t->wrapS];
        self->wrapT = wrap_803a569c[t->wrapT];
        Ptr32<Sink> s = (Ptr32<Sink>)((Ptr32<char>)self + 4);
        ((Ptr32<void (Ptr32<Sink>, Ptr32<Header>)>)((Ptr32<Ptr32<Ptr32<void>>>)s)[6][h->index])(s, h);
        o = self->result;
        self->result = 0;
        self->device->vt->make(self->device, t, o);
        t->object = o;
    }
    {
        int format = h->format;
        if (format == 19) goto palette;
        if (format == 20) {
        palette:
            { int pal = h->palette; fn_8016c4f4(self, (Ptr32<void>)w3d::G(pal)); }
        }
    }
    if (o) {
        if (current_804ab544 != o) {
            fn_8030a21c(o, self->stage);
            current_804ab544 = o;
        }
        fn_8016803c(global_804b1884, 32);
    }
    self->stage++;
    return 1;
}


