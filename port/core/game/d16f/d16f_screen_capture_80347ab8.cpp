#include "w3d_ptr.h"
#line 1 "d16f_screen_capture_80347ab8.cpp"
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
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN11D16fUnknown15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN11D16fUnknown6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN11D16fUnknown7releaseEv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fUnknown, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fUnknown, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fUnknown, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D16fUnknown; };

// Observed surface layout: 16-bit height at +44 and width at +46.
struct D16fSurface : D16fUnknown {
    char pad_04[40] __attribute__((aligned(__alignof__(D16fUnknown))));
    unsigned short height;
    unsigned short width;
};

struct D16fRenderer {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN12D16fRenderer15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN12D16fRenderer6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN12D16fRenderer7releaseEv"));
    void w3d_r_slot_20() __asm__(W3D_SYM("_ZN12D16fRenderer7slot_20Ev"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN12D16fRenderer7slot_24Ev"));
    int w3d_r_dimensions(Ptr32<unsigned int> width, Ptr32<unsigned int> height) __asm__(W3D_SYM("_ZN12D16fRenderer10dimensionsEPjS0_"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN12D16fRenderer7slot_32Ev"));
    void w3d_r_capture(int x, int y, unsigned width, unsigned height,
                         Ptr32<D16fSurface> surface, int a, int b) __asm__(W3D_SYM("_ZN12D16fRenderer7captureEiijjP11D16fSurfaceii"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fRenderer, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fRenderer, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fRenderer, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fRenderer, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fRenderer, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int dimensions(Ptr32<unsigned int> w3d_a0, Ptr32<unsigned int> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<unsigned int>, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_D16fRenderer, 7))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fRenderer, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void capture(int w3d_a0, int w3d_a1, unsigned int w3d_a2, unsigned int w3d_a3, Ptr32<D16fSurface> w3d_a4, int w3d_a5, int w3d_a6) { ((void (*)(w3d_u32, int, int, unsigned int, unsigned int, Ptr32<D16fSurface>, int, int))w3d::vfn(this->w3d_vptr_D16fRenderer, 9))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3, w3d_a4, w3d_a5, w3d_a6); }  Ptr32<void> w3d_vptr_D16fRenderer; };

struct D16fFiles {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN9D16fFiles15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN9D16fFiles6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN9D16fFiles7releaseEv"));
    int w3d_r_open(Ptr32<const char> path, int mode, Ptr32<Ptr32<D16fUnknown>> file) __asm__(W3D_SYM("_ZN9D16fFiles4openEPKciPP11D16fUnknown"));
    int w3d_r_find(Ptr32<const char> path, int mode, Ptr32<Ptr32<D16fUnknown>> file) __asm__(W3D_SYM("_ZN9D16fFiles4findEPKciPP11D16fUnknown"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fFiles, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fFiles, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D16fFiles, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int open(Ptr32<const char> w3d_a0, int w3d_a1, Ptr32<Ptr32<D16fUnknown>> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<const char>, int, Ptr32<Ptr32<D16fUnknown>>))w3d::vfn(this->w3d_vptr_D16fFiles, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline int find(Ptr32<const char> w3d_a0, int w3d_a1, Ptr32<Ptr32<D16fUnknown>> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<const char>, int, Ptr32<Ptr32<D16fUnknown>>))w3d::vfn(this->w3d_vptr_D16fFiles, 6))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_D16fFiles; };

// Observed controller layout: renderer interface at +92.
struct D16fController {
    char pad_00[92];
    Ptr32<D16fRenderer> renderer;
};

// Retaining interface holder.
template <class T> struct D16fRef {
    Ptr32<T> p;
    D16fRef() : p(0) {}
    template <class W3dU> D16fRef<T>(Ptr32<W3dU> w3d_p) : D16fRef<T>((T *)w3d_p.get()) {}
 D16fRef(T *q) : p(q) { if (q) q->retain(); }
    D16fRef(const D16fRef &o) : p(o.p) { if (p) p->retain(); }
    ~D16fRef() { if (p) p->release(); }
    void reset(Ptr32<T> q) { if (p) p->release(); p = q; }
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
extern "C" Ptr32<D16fSurface> d16f_service_get_8020b680(Ptr32<void> descriptor);
extern "C" Ptr32<D16fFiles> d16f_file_system_8020b884();
extern "C" void d16f_surface_prepare_801afac0(Ptr32<D16fSurface> surface);
extern "C" int d16f_surface_encode_801a4d68(Ptr32<D16fSurface> surface, Ptr32<D16fUnknown> file, int a, int b);
extern "C" int d16f_format_into_80347a10(Ptr32<char> out, Ptr32<const char> format, ...);

// First controller (original 0x80347ab8).
extern "C" int d16f_screen_capture_a_80347ab8(Ptr32<D16fController> self, Ptr32<const char> path, Ptr32<D16fFiles> files)
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
extern "C" int d16f_screen_capture_b_80348f2c(Ptr32<D16fController> self, Ptr32<const char> path, Ptr32<D16fFiles> files)
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


