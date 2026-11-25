// Compile and bind a shader program through the secondary interface of the
// renderer. Applies the link and reports the state; on failure returns that
// result. If the link has no compiled buffer, builds one from the code words
// (size is their sum plus two per word), hands it to the device and finishes the
// link. Marks the buffer in use. On success the return register holds whatever
// the last helper left, as in the original. GWMP8P rev0 0x8016b86c.
struct Buffer { char u[8]; int stamp; };
struct Header { char u[32]; unsigned short data[1]; };
struct Link { char u[20]; Buffer *compiled; };
struct Shader { char u[84]; unsigned count; char u58[4]; Link *link; Header *code; };
struct Device;
struct DeviceVt { void *u[9]; void (*bind)(Device *, Link *, Buffer *, int); };
struct Device { DeviceVt *vt; };
struct Global;
extern Global *global_804b1884;
struct Base { void *vtable; };
struct Sink { void *vtable; };
struct R : Base, Sink {
    char u[140]; Device *device; char u98[8]; int level; char ua4[124]; int state; int stamp;
};
extern "C" int fn_8016b5a0(Sink *, Shader *);
extern "C" int fn_8016797c(Global *, int, int, Sink *);
extern "C" Buffer *fn_80166fd0(Global *, int);
extern "C" int fn_8016aef0(Buffer *, int, unsigned short, R *);
extern "C" int fn_8016b384(int, int, unsigned, R *);
extern "C" int fn_8016afc8(Buffer *);
extern "C" int fn_8016b040(int, Shader *, R *);
extern "C" int fn_8016aec0(Buffer *);
extern "C" int d29j_compile_shader_8016b86c(Sink *sink, Shader *m)
{
    R *self = static_cast<R *>(sink);
    int hr = fn_8016b5a0(sink, m);
    int state = self->state;
    fn_8016797c(global_804b1884, state, 5, self);
    if (hr) return hr;
    Link *link = m->link;
    Buffer *c = link->compiled;
    Buffer *b;
    if (c == 0) {
        b = fn_80166fd0(global_804b1884, 16);
        unsigned n = m->count;
        unsigned short *d = m->code->data;
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
