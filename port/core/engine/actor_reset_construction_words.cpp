#include "w3d_ptr.h"
#line 1 "actor_reset_construction_words.cpp"
extern "C" {
#include "actor_construction.h"
}
/* FUN_8015286c, original range [0x8015286c, 0x8015287c).
 * A single chained assignment gives the observed +0x134, +0x130 store order. */
extern "C" void w3d_actor_reset_construction_words(Ptr32<ActorConstructionPrefix> actor)
{
    actor->unknown_134 = actor->unknown_130 = 0;
}


