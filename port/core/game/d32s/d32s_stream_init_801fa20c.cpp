#include "w3d_ptr.h"
#line 1 "d32s_stream_init_801fa20c.cpp"
/* GWMP8P rev0 0x801fa20c. Sets up a stream for one channel: sizes six real STLport 4.5.3 vectors, zeroes them
 * pair by pair, polls the SDK device at 0x80301e04 and waits (at most about a thousand polls) while the channel's
 * status is -3 or -2; status -1 or a timeout fails with 0x80004005. Names are inferred. */
#include "compat/stlport_sn_oom.h"
#include <vector>
typedef _STL::vector<float> D32sStreamFloats;
typedef _STL::vector<unsigned char> D32sStreamBytes;
template <> void D32sStreamFloats::_M_fill_insert(Ptr32<float>, unsigned, const float &);
template <> void D32sStreamBytes::_M_fill_insert(Ptr32<unsigned char>, unsigned, const unsigned char &);
extern "C" int fn_80301e04(Ptr32<void>);
struct D32sStreamCard { char u[10]; signed char status; char pad; };
extern D32sStreamCard lbl_8045e824[];
struct D32sStream {
    char u0[32]; D32sStreamBytes a; D32sStreamFloats b; char u64[16]; D32sStreamFloats c; char u96[128 - 96]; int card; char u132[208 - 132]; D32sStreamBytes a2; D32sStreamFloats b2; D32sStreamFloats c2;
    int init(int unused, int index);
};
int D32sStream::init(int unused, int index) {
    unsigned i = 0;
    card = index;
    a.resize(16, (unsigned char)i);
    a2.resize(16, (unsigned char)0);
    b.resize(8, 0.0f);
    b2.resize(8, 0.0f);
    c.resize(4, 0.0f);
    c2.resize(4, 0.0f);
    for (i = 0; i < a.size(); i++) { a[i] = 0; a2[i] = 0; }
    for (i = 0; i < b.size(); i++) { b[i] = 0.0f; b2[i] = 0.0f; }
    for (i = 0; i < c.size(); i++) { c[i] = 0.0f; c2[i] = 0.0f; }
    Ptr32<D32sStreamCard> k = &lbl_8045e824[card];
    fn_80301e04(lbl_8045e824);
    if (k->status == -1) return 0x80004005;
    while ((unsigned char)(k->status + 3) <= 1) {
        fn_80301e04(lbl_8045e824);
        if (i++ > 1000) return 0x80004005;
    }
    return 0;
}


