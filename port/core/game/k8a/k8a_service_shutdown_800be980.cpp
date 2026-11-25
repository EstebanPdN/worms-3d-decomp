#include "w3d_ptr.h"
#line 1 "k8a_service_shutdown_800be980.cpp"
// Appears to shut down a service object: it tears down its tables and releases the
// four interfaces held in globals, clearing each pointer, plus an owned child object.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern Ptr32<void> w3d_held_804ae5dc;
extern Ptr32<void> w3d_held_804ae5d8;
extern Ptr32<void> w3d_held_804ae5e0;
extern Ptr32<void> w3d_held_804ae5e4;
extern int w3d_flag_804b17e0;
extern "C" int w3d_tables_destroy_800bb3a0(Ptr32<void> self);
extern "C" void w3d_auto_8002c490(Ptr32<void> object, int flags);
static inline void k8a_release(Ptr32<void> p)
{
    if (p)
        VCALL(p, void (*)(void *), 16)(p);
}
extern "C" void w3d_k8a_service_shutdown_800be980(Ptr32<void> self)
{
    Ptr32<void> none = 0;
    w3d_tables_destroy_800bb3a0(self);
    k8a_release(w3d_held_804ae5dc);
    w3d_held_804ae5dc = none;
    k8a_release(w3d_held_804ae5d8);
    w3d_held_804ae5d8 = none;
    k8a_release(w3d_held_804ae5e0);
    w3d_held_804ae5e0 = none;
    w3d_flag_804b17e0 = (int)w3d::H(none);
    if (*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 12572))
        w3d_auto_8002c490(*(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 12572), 3);
    *(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 12572) = none;
    k8a_release(w3d_held_804ae5e4);
    w3d_held_804ae5e4 = none;
}


