#include "w3d_ptr.h"
#line 1 "sol35b_pool_init_800c1580.cpp"
struct Sol35bSlot { Ptr32<unsigned char> pointer; inline void clear() { pointer = 0; } };
// Partially observed view of the engine pool whose section table this
// initializer fills. The pool object is reached through one small-data
// pointer; only the section base addresses are observed.
extern Ptr32<unsigned char> sol35b_pool_804aadb4;
extern Sol35bSlot sol35b_section_804ae63c;
extern Sol35bSlot sol35b_section_804ae64c;
extern Sol35bSlot sol35b_section_804ae644;
extern Sol35bSlot sol35b_section_804ae648;
extern Sol35bSlot sol35b_section_804ae65c;
extern Sol35bSlot sol35b_section_804ae650;
extern Sol35bSlot sol35b_section_804ae654;
extern Sol35bSlot sol35b_section_804ae658;
extern Sol35bSlot sol35b_section_804ae640;
extern Sol35bSlot sol35b_section_804ae668;
extern Sol35bSlot sol35b_section_804ae664;
extern Sol35bSlot sol35b_section_804ae660;

// Static-initialization entry: the priority test runs first and the
// initialize flag second. The body publishes the base pointers of the pool's
// eleven sections and clears the three that are built later.
extern "C" void sol35b_pool_init_800c1580(int initialize, int priority)
{
  if (priority != 0xffff)
    return;
  if (!initialize)
    return;
  Ptr32<unsigned char> pool = sol35b_pool_804aadb4;
sol35b_section_804ae63c.pointer = pool + 16384;
sol35b_section_804ae644.pointer = pool + 736;
sol35b_section_804ae648.pointer = pool + 12400;
sol35b_section_804ae650.pointer = pool + 16368;
sol35b_section_804ae654.pointer = pool + 16304;
sol35b_section_804ae658.pointer = pool + 16176;
sol35b_section_804ae640.pointer = pool;
sol35b_section_804ae64c.pointer = pool;
sol35b_section_804ae660.clear();
sol35b_section_804ae65c.pointer = pool;
sol35b_section_804ae664.clear();
sol35b_section_804ae668.pointer = 0;
}


