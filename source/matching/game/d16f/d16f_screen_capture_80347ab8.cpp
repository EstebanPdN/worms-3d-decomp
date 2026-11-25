// Screen capture to a bitmap file (two renderer controllers).
// GC32 reconstruction from the original instructions; class and field names
// are inferred. Each function obtains a retained surface from a service,
// sizes it to the renderer's current dimensions, prepares it and lets the
// renderer copy the frame into it. With no file path, it looks for the first
// free "Screen%03d.bmp" name by probing the file system (the counter is kept
// across calls); then it opens the file for writing and encodes the surface.
// It returns the open call's negative result on failure and 0 on success.
//
// The interfaces are COM-style classes observed through their vtable slots:
// 4-byte entries after an 8-byte header (offsets 12/16 retain/release), which
// is why this unit is built with -fvtable-thunks. The holder declares a copy
// constructor, so g++ 2.95 lays it out in memory (8-byte aligned stack slots
// at 8 and 16, as in the original). The class views are partial: no vtable
// or member is defined here.

struct D16fUnknown {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
};

// Observed surface layout: 16-bit height at +44 and width at +46.
struct D16fSurface : D16fUnknown {
    char pad_04[40];
    unsigned short height;
    unsigned short width;
};

struct D16fRenderer {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual void slot_20();
    virtual void slot_24();
    virtual int dimensions(unsigned *width, unsigned *height);
    virtual void slot_32();
    virtual void capture(int x, int y, unsigned width, unsigned height,
                         D16fSurface *surface, int a, int b);
};

struct D16fFiles {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual int open(const char *path, int mode, D16fUnknown **file);
    virtual int find(const char *path, int mode, D16fUnknown **file);
};

// Observed controller layout: renderer interface at +92.
struct D16fController {
    char pad_00[92];
    D16fRenderer *renderer;
};

// Retaining interface holder.
template <class T> struct D16fRef {
    T *p;
    D16fRef() : p(0) {}
    D16fRef(T *q) : p(q) { if (q) q->retain(); }
    D16fRef(const D16fRef &o) : p(o.p) { if (p) p->retain(); }
    ~D16fRef() { if (p) p->release(); }
    void reset(T *q) { if (p) p->release(); p = q; }
};

// Fixed 64-byte file name buffer, constructed empty.
struct D16fFileName {
    char text[64];
    D16fFileName() { text[0] = 0; }
};

extern char d16f_surface_descriptor_80415cc0[];
extern const char d16f_name_pattern_803a4514[];
extern const char d16f_name_pattern_803a4574[];
extern int d16f_capture_counter_804ab464;
extern int d16f_capture_counter_804ab470;
extern "C" D16fSurface *d16f_service_get_8020b680(void *descriptor);
extern "C" D16fFiles *d16f_file_system_8020b884();
extern "C" void d16f_surface_prepare_801afac0(D16fSurface *surface);
extern "C" int d16f_surface_encode_801a4d68(D16fSurface *surface, D16fUnknown *file, int a, int b);
extern "C" int d16f_format_into_80347a10(char *out, const char *format, ...);

// First controller (original 0x80347ab8).
extern "C" int d16f_screen_capture_a_80347ab8(D16fController *self, const char *path, D16fFiles *files)
{
    D16fRef<D16fSurface> surface(d16f_service_get_8020b680(d16f_surface_descriptor_80415cc0));
    unsigned width, height;
    self->renderer->dimensions(&width, &height);
    surface.p->width = width;
    surface.p->height = height;
    d16f_surface_prepare_801afac0(surface.p);
    self->renderer->capture(0, 0, width, height, surface.p, 0, 0);
    D16fRef<D16fUnknown> file;
    D16fFileName name;
    if (!files)
        files = d16f_file_system_8020b884();
    if (!path) {
        for (;;) {
            file.reset(0);
            d16f_format_into_80347a10(name.text, d16f_name_pattern_803a4514, d16f_capture_counter_804ab464);
            if (files->find(name.text, 1, &file.p) < 0) {
                path = name.text;
                break;
            }
            d16f_capture_counter_804ab464++;
        }
    }
    int result = files->open(path, 6, &file.p);
    if (result < 0)
        return result;
    d16f_surface_encode_801a4d68(surface.p, file.p, 0, 0);
    return 0;
}

// Second controller (original 0x80348f2c): same body, own name pattern and counter.
extern "C" int d16f_screen_capture_b_80348f2c(D16fController *self, const char *path, D16fFiles *files)
{
    D16fRef<D16fSurface> surface(d16f_service_get_8020b680(d16f_surface_descriptor_80415cc0));
    unsigned width, height;
    self->renderer->dimensions(&width, &height);
    surface.p->width = width;
    surface.p->height = height;
    d16f_surface_prepare_801afac0(surface.p);
    self->renderer->capture(0, 0, width, height, surface.p, 0, 0);
    D16fRef<D16fUnknown> file;
    D16fFileName name;
    if (!files)
        files = d16f_file_system_8020b884();
    if (!path) {
        for (;;) {
            file.reset(0);
            d16f_format_into_80347a10(name.text, d16f_name_pattern_803a4574, d16f_capture_counter_804ab470);
            if (files->find(name.text, 1, &file.p) < 0) {
                path = name.text;
                break;
            }
            d16f_capture_counter_804ab470++;
        }
    }
    int result = files->open(path, 6, &file.p);
    if (result < 0)
        return result;
    d16f_surface_encode_801a4d68(surface.p, file.p, 0, 0);
    return 0;
}
