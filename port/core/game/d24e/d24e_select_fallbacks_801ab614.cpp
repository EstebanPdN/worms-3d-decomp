#include "w3d_ptr.h"
#line 1 "d24e_select_fallbacks_801ab614.cpp"
// Builds a table of fallback codes from a list of supported ones (Worms 3D GameCube PAL, 0x801ab614).
//
// The eleven 27-byte rows at 0x803aa2b0 each hold a code and its alternates,
// ended by 26. For each row the entry of the map at +124 indexed by the code
// receives the first candidate present in used[0..count), or the last one tried
// (26 when the row has no alternates). Returns 0.
struct d24e_FormatRow { unsigned char first; unsigned char others[26]; };
extern const d24e_FormatRow table_803aa2b0[];
struct d24e_FormatOwner { char u[124]; int map[1]; };
extern "C" int w3d_d24e_select_fallbacks_801ab614(Ptr32<d24e_FormatOwner> self, Ptr32<const int> used, unsigned count) {
    for (unsigned i = 0; i <= 10; ++i) {
        int first = table_803aa2b0[i].first;
        int result = 26;
        int missing = 1;
        for (unsigned j = 0; j < count; ++j) {
            if (first == used[j]) { result = first; missing = 0; break; }
        }
        unsigned k = 0;
        while (missing && table_803aa2b0[i].others[k] != 26) {
            unsigned n = k + 1;
            result = table_803aa2b0[i].others[k];
            for (unsigned j = 0; j < count; ++j) {
                if (result == used[j]) { missing = 0; break; }
            }
            k = n;
        }
        self->map[first] = result;
    }
    return 0;
}


