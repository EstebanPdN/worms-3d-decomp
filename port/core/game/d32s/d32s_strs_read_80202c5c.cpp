#include "w3d_ptr.h"
#line 1 "d32s_strs_read_80202c5c.cpp"
/* GWMP8P rev0 0x80202c5c. Reads a big-endian STRS string table: 12-byte header, an offset table and a text block
 * into real STLport 4.5.3 vectors, then assigns each string of the owner's name vector. Names are inferred;
 * the writer of this format is 0x80205258. */
#include "compat/stlport_sn_oom.h"
#include <vector>
#include <stl/_algobase.h>
#include <string.h>
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" Ptr32<void> w3d_string_assign(Ptr32<void>, Ptr32<const char>);
struct D32sStrsName {
    Ptr32<char> text;
    D32sStrsName();
    D32sStrsName(const D32sStrsName &);
    ~D32sStrsName() { w3d_string_base_finish(this); w3d_string_release(this); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 D32sStrsName &operator=(const char *s) { w3d_string_assign(this, s); return *this; }
};
typedef _STL::vector<D32sStrsName> D32sStrsNames;
template <> void D32sStrsNames::_M_fill_insert(Ptr32<D32sStrsName>, unsigned, const D32sStrsName &);
inline unsigned sw32(unsigned v) { return v; }
struct D32sStrsStream { void w3d_r_s0() __asm__(W3D_SYM("_ZN14D32sStrsStream2s0Ev")); void w3d_r_s1() __asm__(W3D_SYM("_ZN14D32sStrsStream2s1Ev")); void w3d_r_s2() __asm__(W3D_SYM("_ZN14D32sStrsStream2s2Ev")); int w3d_r_read(Ptr32<void>, int, int) __asm__(W3D_SYM("_ZN14D32sStrsStream4readEPvii"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sStrsStream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sStrsStream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D32sStrsStream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int read(Ptr32<void> w3d_a0, int w3d_a1, int w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, int))w3d::vfn(this->w3d_vptr_D32sStrsStream, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_D32sStrsStream; };
struct D32sStrsHeader { unsigned tag, count, bytes; };
struct D32sStrsReader {
    char u0[20]; Ptr32<D32sStrsStream> stream; char u24[116]; D32sStrsNames names;
    int get(Ptr32<void>, int);
    int strs();
};
int D32sStrsReader::strs() {
    D32sStrsHeader h;
    get(&h, 12);
    h.bytes = sw32(h.bytes);
    h.count = sw32(h.count);
    _STL::vector<char> text(h.bytes);
    _STL::vector<int> offsets(h.count);
    names.resize(h.count);
    stream->read(offsets.begin(), h.count * 4, 0);
    stream->read(text.begin(), h.bytes, 0);
    for (unsigned i = 0; i < h.count; i++) {
        offsets[i] = sw32(offsets[i]);
        names[i] = text.begin() + offsets[i];
    }
    return 0;
}


