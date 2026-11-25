#include "w3d_ptr.h"
#line 1 "d29j_compile_shader_8016b86c.cpp"
// Compile and bind a shader program through the secondary interface of the
// renderer. Applies the link and reports the state; on failure returns that
// result. If the link has no compiled buffer, builds one from the code words
// (size is their sum plus two per word), hands it to the device and finishes the
// link. Marks the buffer in use. On success the return register holds whatever
// the last helper left, as in the original. GWMP8P rev0 0x8016b86c.
struct Buffer { char u[8]; int stamp; };
struct Header { char u[32]; unsigned short data[1]; };
struct Link { char u[20]; Ptr32<Buffer> compiled; };
struct Shader { char u[84]; unsigned count; char u58[4]; Ptr32<Link> link; Ptr32<Header> code; };
struct Device;
struct DeviceVt { Ptr32<void> u[9]; Ptr32<void (Ptr32<Device>, Ptr32<Link>, Ptr32<Buffer>, int)> bind; };
struct Device { Ptr32<DeviceVt> vt; };
struct Global;
extern Ptr32<Global> global_804b1884;
struct Base { Ptr32<void> vtable; };
struct Sink { Ptr32<void> vtable; };
struct R : Base, Sink {
    char u[140] __attribute__((aligned(__alignof__(Base)), aligned(__alignof__(Sink)))); Ptr32<Device> device; char u98[8]; int level; char ua4[124]; int state; int stamp;
};
extern "C" int fn_8016b5a0(Ptr32<Sink>, Ptr32<Shader>);
extern "C" int fn_8016797c(Ptr32<Global>, int, int, Ptr32<Sink>);
extern "C" Ptr32<Buffer> fn_80166fd0(Ptr32<Global>, int);
extern "C" int fn_8016aef0(Ptr32<Buffer>, int, unsigned short, Ptr32<R>);
extern "C" int fn_8016b384(int, int, unsigned, Ptr32<R>);
extern "C" int fn_8016afc8(Ptr32<Buffer>);
extern "C" int fn_8016b040(int, Ptr32<Shader>, Ptr32<R>);
extern "C" int fn_8016aec0(Ptr32<Buffer>);
extern "C" int d29j_compile_shader_8016b86c(Ptr32<Sink> sink, Ptr32<Shader> m)
{
    Ptr32<R> self = w3d::sc<R *>(sink);
    int hr = fn_8016b5a0(sink, m);
    int state = self->state;
    fn_8016797c(global_804b1884, state, 5, self);
    if (hr) return hr;
    Ptr32<Link> link = m->link;
    Ptr32<Buffer> c = link->compiled;
    Ptr32<Buffer> b;
    if (c == 0) {
        b = fn_80166fd0(global_804b1884, 16);
        unsigned n = m->count;
        Ptr32<unsigned short> d = m->code->data;
        unsigned sum = 0;
        for (unsigned i = 0; i < n; ++i) sum += d[i];
        int level = self->level;
        sum += n * 2;
        fn_8016aef0(b, state, sum, self);
        for (unsigned i = 0; i < n; ++i) fn_8016b384(152, state, d[i], self);
        fn_8016afc8(b);
        self->level = level;
        b->stamp = self->stamp;
        link->compiled = b;
        self->device->vt->bind(self->device, link, b, 0);
        fn_8016b040(state, m, self);
    } else b = c;
    if (b) fn_8016aec0(b);
}


