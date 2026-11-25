// Appears to shut down a service object: it tears down its tables and releases the
// four interfaces held in globals, clearing each pointer, plus an owned child object.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
extern void *w3d_held_804ae5dc;
extern void *w3d_held_804ae5d8;
extern void *w3d_held_804ae5e0;
extern void *w3d_held_804ae5e4;
extern int w3d_flag_804b17e0;
extern "C" int w3d_tables_destroy_800bb3a0(void *self);
extern "C" void w3d_auto_8002c490(void *object, int flags);
static inline void k8a_release(void *p)
{
    if (p)
        VCALL(p, void (*)(void *), 16)(p);
}
extern "C" void w3d_k8a_service_shutdown_800be980(void *self)
{
    void *none = 0;
    w3d_tables_destroy_800bb3a0(self);
    k8a_release(w3d_held_804ae5dc);
    w3d_held_804ae5dc = none;
    k8a_release(w3d_held_804ae5d8);
    w3d_held_804ae5d8 = none;
    k8a_release(w3d_held_804ae5e0);
    w3d_held_804ae5e0 = none;
    w3d_flag_804b17e0 = (int)none;
    if (*(void **)((char *)self + 12572))
        w3d_auto_8002c490(*(void **)((char *)self + 12572), 3);
    *(void **)((char *)self + 12572) = none;
    k8a_release(w3d_held_804ae5e4);
    w3d_held_804ae5e4 = none;
}
