/* Original message buffer lifecycle. Caller owns reservation lifetimes.
 * No capacity/collision failure check is invented for the native allocator.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "message_arena.h"

void w3d_message_arena_init(MessageArena *arena)
{
    arena->checkpoint = 0;
    arena->buffer = 0;
    arena->cursor = 0;
    arena->capacity = 0;
    w3d_message_storage = arena;
}

void w3d_message_arena_open(MessageArena *arena, ArenaSize capacity)
{
    arena->buffer = (unsigned char *)w3d_aligned_allocate(capacity, 64);
    arena->cursor = 0;
    arena->checkpoint = capacity;
    arena->capacity = capacity;
}

void w3d_message_arena_close(MessageArena *arena)
{
    w3d_aligned_release(arena->buffer);
    arena->buffer = 0;
}

void *w3d_message_allocate(MessageArena *arena, ArenaSize payload_size)
{
    ArenaSize chunk_size = ((payload_size + 3u) & ~3u) + 4u;
    ArenaSize *chunk;
    if (arena->capacity - arena->cursor < chunk_size)
        arena->cursor = 0;
    chunk = (ArenaSize *)(arena->buffer + arena->cursor);
    arena->cursor += chunk_size;
    *chunk = chunk_size;
    return chunk + 1;
}

void w3d_message_arena_checkpoint(MessageArena *arena)
{
    arena->checkpoint = arena->cursor;
}
#ifdef __cplusplus
}
#endif
