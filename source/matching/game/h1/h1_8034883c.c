/* Runtime-library helpers (session 47b5d14a, hand-matched from m2c near
 * misses). Offsets come from the original instructions; meanings are
 * inferred. */

void *w3d_handle_storage_allocate(int size);
void *w3d_handle_storage_fallback(int size);
int fn_80210b90(void *list, int value);
void w3d_string_base_finish(void *text);
void w3d_string_release(void *text);
void w3d_handle_storage_release(void *block);

typedef struct W3dStringTreeNode {
    int color;
    struct W3dStringTreeNode *parent;
    struct W3dStringTreeNode *left;     /* +8 */
    struct W3dStringTreeNode *right;    /* +12 */
    unsigned char value[4];             /* +16 */
} W3dStringTreeNode;

static inline void *w3d_h1_storage_allocate_or_fallback(int size)
{
    void *block = w3d_handle_storage_allocate(size);
    if (!block)
        block = w3d_handle_storage_fallback(size);
    return block;
}

static inline void w3d_string_destroy(void *text)
{
    w3d_string_base_finish(text);
    w3d_string_release(text);
}

static inline void w3d_string_tree_destroy_node(W3dStringTreeNode *node)
{
    w3d_string_destroy(node->value);
    if (node)
        w3d_handle_storage_release(node);
}

int w3d_h1_set_and_register_8034883c(void *self, int value)
{
    *(int *)((char *)self + 84) = value;
    fn_80210b90((char *)self + 72, value);
    return 0;
}

void w3d_h1_fill_allocated_blocks_80353454(void *unused, void **begin, void **end)
{
    void **slot;
    for (slot = begin; slot < end; slot++)
        *slot = w3d_h1_storage_allocate_or_fallback(128);
}

/* Second instance of the same template in another translation unit. */
int w3d_h1_set_and_register_80349b20(void *self, int value)
{
    *(int *)((char *)self + 84) = value;
    fn_80210b90((char *)self + 72, value);
    return 0;
}

/* Red-black tree erase (STL _M_erase) for nodes holding a string. */
void w3d_h1_string_tree_erase_8035a3f8(void *tree, W3dStringTreeNode *node)
{
    while (node) {
        W3dStringTreeNode *left;
        w3d_h1_string_tree_erase_8035a3f8(tree, node->right);
        left = node->left;
        w3d_string_tree_destroy_node(node);
        node = left;
    }
}

/* Second instance of the block fill template. */
void w3d_h1_fill_allocated_blocks_8035ec0c(void *unused, void **begin, void **end)
{
    void **slot;
    for (slot = begin; slot < end; slot++)
        *slot = w3d_h1_storage_allocate_or_fallback(128);
}
