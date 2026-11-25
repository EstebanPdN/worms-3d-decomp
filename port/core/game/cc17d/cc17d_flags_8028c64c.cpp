#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17d_flags_8028c64c.c"
/* cc17d: flag update leaf at 0x8028c64c.
   Observed layout: words at +176 and +312 are tested; +312 is used as a 0/1
   value (xor with 1).  Pointers at +252, +256 and +272 reach objects whose word
   at +16 receives the computed 0/1 flags.  Field meanings are inferred. */
struct Cc17dFlagTarget { char pad00[16]; int enabled; };
struct Cc17dFlagOwner {
    char pad000[176];
    int item;                          /* +176, tested for nonzero */
    char pad0b4[252 - 180];
    Ptr32<struct Cc17dFlagTarget> a;         /* +252 */
    Ptr32<struct Cc17dFlagTarget> b;         /* +256 */
    char pad104[272 - 260];
    Ptr32<struct Cc17dFlagTarget> c;         /* +272 */
    char pad114[312 - 276];
    int mode;                          /* +312, 0/1 */
};

/* The item word is read through an inline accessor: GCC 2.95 keeps the copy
   in its own register, as the original does. */
static inline int cc17d_item(Ptr32<struct Cc17dFlagOwner> self) { return self->item; }

void w3d_cc17d_update_flags_8028c64c(Ptr32<struct Cc17dFlagOwner> self)
{
    int mode = self->mode;
    int item = cc17d_item(self);
    int both = (mode != 0) & (item != 0);
    int other = ((mode ^ 1) & item) != 0;
    self->a->enabled = other;
    self->b->enabled = other;
    self->c->enabled = both;
}

}
