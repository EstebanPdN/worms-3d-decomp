#include "w3d_ptr.h"
#line 1 "d24j_compile_mesh_data_8017fe2c.cpp"
// Serialize a mesh's source data (Worms 3D GameCube PAL, 0x8017fe2c).
//
// Only when state bit 5 at +36 is set: creates a shared writer (0x80418f78)
// and a stream (0x80208aac), writes the source's 0x8040e078 interface to the
// stream, copies the stream bytes to a 32-byte-aligned temporary, passes it to
// the request at +56 (0x8020f4b0), releases the temporary and calls 0x801801b0.
// Returns 0. Both handles are one word, each held in its own inline helper.

extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, unsigned);
struct Blob { Ptr32<void> data; unsigned size; };
struct Iface { Ptr32<Ptr32<void>> vtable;
    void retain() { ((Ptr32<void (Ptr32<Iface>)>)vtable[3])(this); }
    void release() { ((Ptr32<void (Ptr32<Iface>)>)vtable[4])(this); }
};
struct Handle { Ptr32<Iface> p;
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Iface *)w3d_p.get()) {}
 Handle(Iface *v) { p = v; if (v) v->retain(); }
    ~Handle() { if (p) p->release(); }
};
struct Mesh { char u[36]; unsigned short state; char u38[2]; Ptr32<Iface> source; char u44[12]; char request[4]; };
extern "C" Ptr32<Iface> fn_8020b680(Ptr32<char>);
extern "C" Ptr32<Iface> fn_80208aac(int);
extern "C" Ptr32<void> fn_801fe0b8(unsigned);
extern "C" void fn_801fe160(Ptr32<void>);
extern "C" Ptr32<void> fn_80343944();
extern "C" int fn_8020f4b0(Ptr32<void>, Ptr32<void>, unsigned, Ptr32<void>);
extern "C" int fn_801801b0(Ptr32<Mesh>);
extern char name_80418f78[];
extern char iid_8040e078[];
inline void write_stream(Ptr32<Mesh> m, Handle &writer)
{
    Handle stream(fn_80208aac(0));
    Ptr32<Iface> source;
    Blob blob;
    ((Ptr32<void (Ptr32<Iface>, Ptr32<void>, int, Ptr32<Ptr32<Iface>>)>)m->source->vtable[14])(m->source, iid_8040e078, 0, &source);
    ((Ptr32<void (Ptr32<Iface>, Ptr32<Iface>)>)writer.p->vtable[5])(writer.p, stream.p);
    ((Ptr32<void (Ptr32<Iface>, Ptr32<Iface>, int)>)writer.p->vtable[8])(writer.p, source, 0);
    source->release();
    Ptr32<Blob> b = &blob;
    ((Ptr32<void (Ptr32<Iface>, Ptr32<Blob>)>)stream.p->vtable[10])(stream.p, b);
    unsigned size = (b->size + 31) & ~31u;
    Ptr32<void> temp = fn_801fe0b8(size);
    memcpy(temp, blob.data, b->size);
    fn_8020f4b0(fn_80343944(), temp, size, m->request);
    fn_801fe160(temp);
    fn_801801b0(m);
}
inline void compile(Ptr32<Mesh> m)
{
    Handle writer(fn_8020b680(name_80418f78));
    write_stream(m, writer);
}
extern "C" int d24j_compile_mesh_data_8017fe2c(Ptr32<Mesh> m)
{
    return 0;
}


