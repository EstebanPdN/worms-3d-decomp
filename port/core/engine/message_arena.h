#ifndef W3D_REFERENCE_MESSAGE_ARENA_H
#define W3D_REFERENCE_MESSAGE_ARENA_H
typedef unsigned int ArenaSize;
typedef struct MessageArena {
    Ptr32<unsigned char> buffer;
    ArenaSize cursor;
    ArenaSize capacity;
    ArenaSize checkpoint;
} MessageArena;
extern Ptr32<MessageArena> w3d_message_storage;
/* Same signature as the independently recovered lua_platform.c wrapper. */
extern Ptr32<void> w3d_aligned_allocate(unsigned int, unsigned int);
extern void w3d_aligned_release(Ptr32<void>);
void w3d_message_arena_init(Ptr32<MessageArena>);
void w3d_message_arena_open(Ptr32<MessageArena>, ArenaSize);
void w3d_message_arena_close(Ptr32<MessageArena>);
Ptr32<void> w3d_message_allocate(Ptr32<MessageArena>, ArenaSize);
void w3d_message_arena_checkpoint(Ptr32<MessageArena>);
#endif
