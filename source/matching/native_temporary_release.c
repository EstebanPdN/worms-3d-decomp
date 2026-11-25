/* Complete compiler-matched native temporary release at801fe160..801fe1d8.
 * Names/types are analyst assignments. External state/strings remain unowned.
 * Requires the native32-bit reference ABI; no complete allocator runtime claim. */
typedef unsigned long u32;
typedef struct TemporaryRecord { void *address; u32 size; } TemporaryRecord;
extern u32 w3d_temporary_cursor;
extern u32 w3d_temporary_count;
extern TemporaryRecord w3d_temporary_records[];
extern const char w3d_temporary_wrong_order[];
extern void *w3d_heap_arena_high(void);
extern void w3d_heap_trace(const char *, ...);

void *w3d_temporary_release(void *address)
{
    w3d_temporary_count--;
    if (w3d_temporary_records[w3d_temporary_count].address != address)
        w3d_heap_trace(w3d_temporary_wrong_order);
    w3d_temporary_cursor += w3d_temporary_records[w3d_temporary_count].size;
    return w3d_heap_arena_high();
}
