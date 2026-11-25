#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_80277a10.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), eleventh batch: a key
 * handler mapping a character's position in one of two sets to a command. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))

extern Ptr32<char> lbl_804abb9c;
extern Ptr32<char> lbl_804abba0;
Ptr32<char> fn_802ef198(Ptr32<const char>, int);
void fn_80275f18(Ptr32<void>);
void fn_802761b8(Ptr32<void>, Ptr32<void>, int);

void w3d_handle_key_80277a10(Ptr32<void> self, int key)
{
    Ptr32<char> set;
    Ptr32<char> found;
    if (key == 27) {
        fn_80275f18(self);
        return;
    }
    found = fn_802ef198(lbl_804abb9c, key);
    set = lbl_804abb9c;
    if (!found) {
        set = lbl_804abba0;
        found = fn_802ef198(set, key);
        if (!found)
            return;
    }
    switch (found - set) {
    case 0: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 20); break;
    case 1: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 21); break;
    case 2: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 22); break;
    case 3: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 23); break;
    case 4: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 24); break;
    case 5: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 25); break;
    case 6: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 26); break;
    case 7: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 27); break;
    case 8: fn_802761b8(self, w3d::G(FIELD(self, int, 92)), 28); break;
    }
}

}
