/* Complete reconstructed native functions. Analyst-assigned names/types.
 * Original entries: high 0x802fa678, low 0x802fa680 (8 bytes each).
 * Only external declarations: original state ownership remains unproven. */
extern void *w3d_heap_arena_low_value;
extern void *w3d_heap_arena_high_value;
void w3d_arena_set_high(void *value) { w3d_heap_arena_high_value = value; }
void w3d_arena_set_low(void *value) { w3d_heap_arena_low_value = value; }
