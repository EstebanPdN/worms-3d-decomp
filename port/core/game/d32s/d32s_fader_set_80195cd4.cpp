#include "w3d_ptr.h"
#line 1 "d32s_fader_set_80195cd4.cpp"
/* GWMP8P rev0 0x80195cd4. Sets one channel level: above zero it sizes the channel's real STLport 4.5.3
 * vector to the channel count when empty and resets the shared cache globals, otherwise it clears the
 * vector; it marks the owner dirty when the level's zero state changes (the float words are compared
 * as bits, because the original loads them as integers). Names and the element class are inferred. */
#include "compat/stlport_sn_oom.h"
#include "compat/module_allocator.h"
#include <vector>
struct D32sFadeWord { int v; D32sFadeWord() : v(0) {} ~D32sFadeWord() {} };
typedef _STL::vector<D32sFadeWord, ModuleAllocator<D32sFadeWord> > D32sFadeD32sFadeWords;
template <> void D32sFadeD32sFadeWords::_M_fill_insert(Ptr32<D32sFadeWord>, unsigned, const D32sFadeWord &);
struct D32sFadeEntry { int count; D32sFadeD32sFadeWords words; };
extern float lbl_804a91d8[];
extern float lbl_804a91e8[];
extern int lbl_804b18bc, lbl_804b18c0, lbl_804b18c4, lbl_804b18c8, lbl_804b18cc;
extern float lbl_804b18d0, lbl_804b18d4;
struct D32sLevel { union { float f; int word; }; int u4, u8; };
struct D32sLevels { Ptr32<D32sLevel> p; D32sLevel &operator[](int i) { return *(Ptr32<D32sLevel>)((Ptr32<char>)p + i * 12); } };
inline bool is_zero(const float &f) { return *(Ptr32<const int>)&f == 0; }
inline int word(const float &f) { return *(Ptr32<const int>)&f; }
struct D32sFader {
    char u0[40]; D32sLevels levels; char u44[36]; Ptr32<D32sFadeEntry> entries; char u84[36]; int dirty;
    int set(int k, float v);
};
int D32sFader::set(int k, float v) {
    if (v > 0.0f) {
        D32sFadeEntry &e = entries[k];
        if (e.words.empty()) {
            int n = e.count;
            D32sFadeWord w;
            lbl_804b18c8 = 0;
            lbl_804b18cc = -1;
            lbl_804b18bc = -1;
            lbl_804b18c0 = 0;
            lbl_804b18c4 = 1;
            lbl_804b18d0 = 0.0f;
            lbl_804b18d4 = 0.0f;
            lbl_804a91d8[3] = 0.0f;
            lbl_804a91d8[2] = 0.0f;
            lbl_804a91d8[1] = 0.0f;
            lbl_804a91e8[3] = 0.0f;
            lbl_804a91d8[0] = 0.0f;
            lbl_804a91e8[2] = 0.0f;
            lbl_804a91e8[1] = 0.0f;
            lbl_804a91e8[0] = 0.0f;
            e.words.resize(n, w);
        }
    } else {
        D32sFadeD32sFadeWords &w = entries[k].words;
        if (!w.empty()) w.clear();
    }
    if ((word(v) == 0 && levels[k].word != 0) || (word(v) != 0 && levels[k].word == 0)) dirty = 1;
    levels[k].f = v;
    return 0;
}


