#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_8034883c.c"
/* Runtime-library helpers (session 47b5d14a, hand-matched from m2c near
 * misses). Offsets come from the original instructions; meanings are
 * inferred. */

Ptr32<void> w3d_handle_storage_allocate(int size);
Ptr32<void> w3d_handle_storage_fallback(int size);
int fn_80210b90(Ptr32<void> list, int value);
void w3d_string_base_finish(Ptr32<void> text);
void w3d_string_release(Ptr32<void> text);
void w3d_handle_storage_release(Ptr32<void> block);

typedef struct W3dStringTreeNode {
    int color;
    Ptr32<struct W3dStringTreeNode> parent;
    Ptr32<struct W3dStringTreeNode> left;     /* +8 */
    Ptr32<struct W3dStringTreeNode> right;    /* +12 */
    unsigned char value[4];             /* +16 */
} W3dStringTreeNode;

static inline Ptr32<void> w3d_h1_storage_allocate_or_fallback(int size)
{
    Ptr32<void> block = w3d_handle_storage_allocate(size);
    if (!block)
        block = w3d_handle_storage_fallback(size);
    return block;
}

static inline void w3d_string_destroy(Ptr32<void> text)
{
    w3d_string_base_finish(text);
    w3d_string_release(text);
}

static inline void w3d_string_tree_destroy_node(Ptr32<W3dStringTreeNode> node)
{
    w3d_string_destroy(node->value);
    if (node)
        w3d_handle_storage_release(node);
}

int w3d_h1_set_and_register_8034883c(Ptr32<void> self, int value)
{
    *(Ptr32<int>)((Ptr32<char>)self + 84) = value;
    fn_80210b90((Ptr32<char>)self + 72, value);
    return 0;
}

void w3d_h1_fill_allocated_blocks_80353454(Ptr32<void> unused, Ptr32<Ptr32<void>> begin, Ptr32<Ptr32<void>> end)
{
    Ptr32<Ptr32<void>> slot;
    for (slot = begin; slot < end; slot++)
        *slot = w3d_h1_storage_allocate_or_fallback(128);
}

/* Second instance of the same template in another translation unit. */
int w3d_h1_set_and_register_80349b20(Ptr32<void> self, int value)
{
    *(Ptr32<int>)((Ptr32<char>)self + 84) = value;
    fn_80210b90((Ptr32<char>)self + 72, value);
    return 0;
}

/* Red-black tree erase (STL _M_erase) for nodes holding a string. */
void w3d_h1_string_tree_erase_8035a3f8(Ptr32<void> tree, Ptr32<W3dStringTreeNode> node)
{
    while (node) {
        Ptr32<W3dStringTreeNode> left;
        w3d_h1_string_tree_erase_8035a3f8(tree, node->right);
        left = node->left;
        w3d_string_tree_destroy_node(node);
        node = left;
    }
}

/* Second instance of the block fill template. */
void w3d_h1_fill_allocated_blocks_8035ec0c(Ptr32<void> unused, Ptr32<Ptr32<void>> begin, Ptr32<Ptr32<void>> end)
{
    Ptr32<Ptr32<void>> slot;
    for (slot = begin; slot < end; slot++)
        *slot = w3d_h1_storage_allocate_or_fallback(128);
}

}
