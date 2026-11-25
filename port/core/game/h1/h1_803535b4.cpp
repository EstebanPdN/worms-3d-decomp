#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_803535b4.c"
/* STL deque internals with 128-byte buffers (session 47b5d14a, hand-matched).
 * Each template appears in two translation units (two instances). The deque
 * keeps its start iterator at 0, its finish iterator at 16 and its node map
 * at 36; names follow the SGI STL shipped with ProDG. */

typedef struct W3dDequeIterator {
    Ptr32<char> cur;
    Ptr32<char> first;                    /* +4 */
    Ptr32<char> last;                     /* +8 */
    Ptr32<Ptr32<char>> node;                    /* +12 */
} W3dDequeIterator;
void w3d_handle_storage_release(Ptr32<void> block);
void w3d_actor_member_delete_backend(Ptr32<void> self);

void w3d_h1_deque_destroy_nodes_803535b4(Ptr32<void> self, Ptr32<Ptr32<char>> start, Ptr32<Ptr32<char>> finish)
{
    Ptr32<Ptr32<char>> node;
    for (node = start; node < finish; node++)
        if (*node)
            w3d_handle_storage_release(*node);
}

void w3d_h1_deque_base_destroy_80353604(Ptr32<void> self, int flags)
{
    if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 36)) {
        w3d_h1_deque_destroy_nodes_803535b4(self, *(Ptr32<Ptr32<Ptr32<char>>>)((Ptr32<char>)self + 12), *(Ptr32<Ptr32<Ptr32<char>>>)((Ptr32<char>)self + 28) + 1);
        if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 36))
            w3d_handle_storage_release(*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 36));
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

void w3d_h1_deque_next_buffer_8035eec4(Ptr32<W3dDequeIterator> it)
{
    Ptr32<Ptr32<char>> node;
    if (it->first)
        w3d_handle_storage_release(it->first);
    node = it->node;
    it->node = node + 1;
    it->first = node[1];
    it->last = it->first + 128;
    it->cur = it->first;
}

/* Second instances of the node-destroy and base-destructor templates. */
void w3d_h1_deque_destroy_nodes_8035ed6c(Ptr32<void> self, Ptr32<Ptr32<char>> start, Ptr32<Ptr32<char>> finish)
{
    Ptr32<Ptr32<char>> node;
    for (node = start; node < finish; node++)
        if (*node)
            w3d_handle_storage_release(*node);
}

void w3d_h1_deque_base_destroy_8035edbc(Ptr32<void> self, int flags)
{
    if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 36)) {
        w3d_h1_deque_destroy_nodes_8035ed6c(self, *(Ptr32<Ptr32<Ptr32<char>>>)((Ptr32<char>)self + 12), *(Ptr32<Ptr32<Ptr32<char>>>)((Ptr32<char>)self + 28) + 1);
        if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 36))
            w3d_handle_storage_release(*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 36));
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
