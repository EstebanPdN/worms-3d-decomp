#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "message_arena.c"
/* Original message buffer lifecycle. Caller owns reservation lifetimes.
 * No capacity/collision failure check is invented for the native allocator.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "message_arena.h"

void w3d_message_arena_init(Ptr32<MessageArena> arena)
{
    arena->checkpoint = 0;
    arena->buffer = 0;
    arena->cursor = 0;
    arena->capacity = 0;
    w3d_message_storage = arena;
}

void w3d_message_arena_open(Ptr32<MessageArena> arena, ArenaSize capacity)
{
    arena->buffer = (Ptr32<unsigned char>)w3d_aligned_allocate(capacity, 64);
    arena->cursor = 0;
    arena->checkpoint = capacity;
    arena->capacity = capacity;
}

void w3d_message_arena_close(Ptr32<MessageArena> arena)
{
    w3d_aligned_release(arena->buffer);
    arena->buffer = 0;
}

Ptr32<void> w3d_message_allocate(Ptr32<MessageArena> arena, ArenaSize payload_size)
{
    ArenaSize chunk_size = ((payload_size + 3u) & ~3u) + 4u;
    Ptr32<ArenaSize> chunk;
    if (arena->capacity - arena->cursor < chunk_size)
        arena->cursor = 0;
    chunk = (Ptr32<ArenaSize>)(arena->buffer + arena->cursor);
    arena->cursor += chunk_size;
    *chunk = chunk_size;
    return chunk + 1;
}

void w3d_message_arena_checkpoint(Ptr32<MessageArena> arena)
{
    arena->checkpoint = arena->cursor;
}
#ifdef __cplusplus
}
#endif

}
