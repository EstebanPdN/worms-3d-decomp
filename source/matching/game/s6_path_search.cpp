/* Path search workspace fields are named from their observed uses. */
extern "C" {
struct S6Bucket { void **begin; void **end; void **reserved; void **limit; };
struct S6Table { S6Bucket buckets[1024]; int count; };
struct S6PointerRange { void **begin; void **end; void **limit; };
struct S6Search {
    int unknown_0;
    S6Table open;
    S6Table closed;
    void *start;
    void *goal;
    int steps;
    int finished;
    int state;
    int unknown_8024;
    S6PointerRange path;
    int unknown_8030[2];
    float height;
    int step_limit;
    int unknown_803c[2];
    short largest;
    short rejected;
    S6Bucket candidates;
};
void w3d_path_table_clear_80005398(S6Table *);
void w3d_path_bucket_clear_8000532c(S6PointerRange *);
void w3d_empty_8034144c();
void w3d_auto_80015264(void *);
extern void *w3d_path_grid_804b1758;
struct S6Vec3 { float x,y,z; };
S6Vec3 *w3d_fn_8001e11c(void *);
S6Vec3 *w3d_fn_8001e1a0(void *, int, int, int);
static inline void s6_bucket_reset(S6Bucket *bucket) { bucket->end = bucket->begin; }
static inline void *s6_pop(S6PointerRange *range) {
    void **end = range->end - 1;
    void *entry = *end;
    range->end = end;
    return entry;
}
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_path_search_reset_80004394(S6Search *search) {
    w3d_path_table_clear_80005398(&search->open);
    w3d_path_table_clear_80005398(&search->closed);
    s6_bucket_reset(&search->candidates);
    void *entry = search->start;
    if (entry) { w3d_empty_8034144c(); w3d_auto_80015264(entry); }
    search->start = 0;
    entry = search->goal;
    if (entry) { w3d_empty_8034144c(); w3d_auto_80015264(entry); }
    search->goal = 0;
    search->finished = 0;
    search->state = -1;
    w3d_path_bucket_clear_8000532c(&search->path);
    search->unknown_8024 = 0;
    search->largest = 0;
    search->rejected = 32767;
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
int w3d_path_height_reachable_8000519c(S6Search *search, int x, int y, int layer, float low, float high) {
    void *grid = w3d_path_grid_804b1758;
    S6Vec3 floor;
    floor.x = w3d_fn_8001e11c(grid)->x;
    S6Vec3 ceiling;
    ceiling.x = w3d_fn_8001e1a0(grid, x, y, layer)->x;
    if (ceiling.x - low > search->height) return 0;
    if (high - floor.x > search->height) return 0;
    return 1;
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_path_release_reverse_800062ec(S6Search *search) {
    while (search->path.begin != search->path.end) {
        void *entry = s6_pop(&search->path);
        if (entry) { w3d_empty_8034144c(); w3d_auto_80015264(entry); }
    }
}
#endif
}
