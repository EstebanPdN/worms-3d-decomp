// GWMP8P rev0 0x80009674. Builds a move queue between two points on the grid
// and discards it when empty or when the remaining turn time minus the
// search time falls below a minimum; then advances the turn clock by the
// search cost. Names are inferred from the original instructions.
inline void *operator new(unsigned int, void *place) { return place; }
struct Vec { float x, y, z; };
struct Grid;
struct Queue {
    char unknown00[16];
    void **vtable;   /* +16; slot +8 is the deleting destructor */
    void **start, **finish;
    Queue();
    void Delete() { ((void (*)(Queue *, int))vtable[2])(this, 3); }
};
extern float g_clock_804aa570;
extern Grid *w3d_grid_804b1758;
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void cc26a_grid_build_path_8001ebe0(Grid *, const Vec *, const Vec *, Queue *, int);
extern "C" int w3d_auto_8001ece8(Grid *);
extern "C" float w3d_auto_8001ecf8(Grid *);
extern "C" float w3d_d24a_turn_time_remaining_800155d0();
extern "C" int w3d_d28a_path_queue_build_timed_80009674(Queue **out, const Vec *from, const Vec *to, int limit, float least)
{
    *out = new (w3d_auto_8001523c(48)) Queue;
    g_clock_804aa570 += 100.0f;
    if (limit == -1) cc26a_grid_build_path_8001ebe0(w3d_grid_804b1758, from, to, *out, 150);
    else cc26a_grid_build_path_8001ebe0(w3d_grid_804b1758, from, to, *out, limit);
    int n = w3d_auto_8001ece8(w3d_grid_804b1758);
    Queue *q = *out;
    if (q) {
        if (q->start == q->finish) goto discard;
        {
            float used = w3d_auto_8001ecf8(w3d_grid_804b1758);
            if (!(w3d_d24a_turn_time_remaining_800155d0() - used < least)) goto done;
        }
        q = *out;
        if (q) {
discard:
            q->Delete();
        }
    }
    *out = 0;
done:
    g_clock_804aa570 += (float)n * 400.0f / 150.0f;
    return *out != 0;
}
