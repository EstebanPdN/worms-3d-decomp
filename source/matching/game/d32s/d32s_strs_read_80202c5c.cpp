/* GWMP8P rev0 0x80202c5c. Reads a big-endian STRS string table: 12-byte header, an offset table and a text block
 * into real STLport 4.5.3 vectors, then assigns each string of the owner's name vector. Names are inferred;
 * the writer of this format is 0x80205258. */
#include "compat/stlport_sn_oom.h"
#include <vector>
#include <stl/_algobase.h>
#include <string.h>
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" void *w3d_string_assign(void *, const char *);
struct D32sStrsName {
    char *text;
    D32sStrsName();
    D32sStrsName(const D32sStrsName &);
    ~D32sStrsName() { w3d_string_base_finish(this); w3d_string_release(this); }
    D32sStrsName &operator=(const char *s) { w3d_string_assign(this, s); return *this; }
};
typedef _STL::vector<D32sStrsName> D32sStrsNames;
template <> void D32sStrsNames::_M_fill_insert(D32sStrsName *, unsigned, const D32sStrsName &);
inline unsigned sw32(unsigned v) { return (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24); }
struct D32sStrsStream { virtual void s0(); virtual void s1(); virtual void s2(); virtual int read(void *, int, int); };
struct D32sStrsHeader { unsigned tag, count, bytes; };
struct D32sStrsReader {
    char u0[20]; D32sStrsStream *stream; char u24[116]; D32sStrsNames names;
    int get(void *, int);
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
