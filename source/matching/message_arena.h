#ifndef W3D_REFERENCE_MESSAGE_ARENA_H
#define W3D_REFERENCE_MESSAGE_ARENA_H
typedef unsigned int ArenaSize;
typedef struct MessageArena {
    unsigned char *buffer;
    ArenaSize cursor;
    ArenaSize capacity;
    ArenaSize checkpoint;
} MessageArena;
extern MessageArena *w3d_message_storage;
/* Same signature as the independently recovered lua_platform.c wrapper. */
extern void *w3d_aligned_allocate(unsigned long, unsigned int);
extern void w3d_aligned_release(void *);
void w3d_message_arena_init(MessageArena *);
void w3d_message_arena_open(MessageArena *, ArenaSize);
void w3d_message_arena_close(MessageArena *);
void *w3d_message_allocate(MessageArena *, ArenaSize);
void w3d_message_arena_checkpoint(MessageArena *);
#endif
