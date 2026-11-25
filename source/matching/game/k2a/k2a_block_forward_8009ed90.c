typedef struct K2aBlock { int words[9]; } K2aBlock;
extern void FUN_8009ea38(K2aBlock block, void *);

void k2a_block_forward_8009ed90(K2aBlock *block, void * arg_r4)
{
    FUN_8009ea38(*block, arg_r4);
}
