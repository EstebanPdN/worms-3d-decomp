#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_block_forward_8009ed90.c"
typedef struct K2aBlock { int words[9]; } K2aBlock;
extern void FUN_8009ea38(K2aBlock block, Ptr32<void>);

void k2a_block_forward_8009ed90(Ptr32<K2aBlock> block, Ptr32<void> arg_r4)
{
    FUN_8009ea38(*block, arg_r4);
}

}
