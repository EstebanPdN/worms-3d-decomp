#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_t_801fe688.c"
// desc: Appears to parse a name into a boolean output (first literal gives one, second gives zero) or return the failure status 0x80004005.
extern const char lbl_803b298c[];
extern const char lbl_803b2994[];
extern int fn_802ef074(Ptr32<const char>, Ptr32<const char>);
int w3d_s21_parse_flag_name_801fe688(Ptr32<void> self, Ptr32<int> out, Ptr32<const char> name)
{
    int result;
    if (fn_802ef074(lbl_803b298c, name) == 0) {
        *out = 1;
        return 0;
    }
    result = fn_802ef074(lbl_803b2994, name);
    if (result != 0)
        return 0x80004005;
    *out = result;
    return 0;
}

}
