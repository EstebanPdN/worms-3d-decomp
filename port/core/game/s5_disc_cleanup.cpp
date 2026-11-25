#include "w3d_ptr.h"
#line 1 "s5_disc_cleanup.cpp"
/* Releases the disc screen's held interfaces and then its service base. */
extern "C" {
struct S5DiscIface;
struct S5DiscVtable { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<S5DiscIface>)> release; };
struct S5DiscIface { Ptr32<S5DiscVtable> vtable; };
struct S5DiscScreen { Ptr32<void> vtable; unsigned char reserved[188]; Ptr32<S5DiscIface> items[8]; unsigned char field224[12]; Ptr32<S5DiscIface> field236; Ptr32<S5DiscIface> field240; Ptr32<S5DiscIface> field244; };
extern unsigned char w3d_disc_vtable_8040faa8[];
void w3d_service_destroy_801628ec(Ptr32<void>,int);
void w3d_disc_screen_destroy_800c6f20(Ptr32<S5DiscScreen> screen,int flags)
{
    screen->vtable=w3d_disc_vtable_8040faa8;
    if (screen->field244) screen->field244->vtable->release(screen->field244);
    screen->field244=0;
    Ptr32<Ptr32<S5DiscIface>> items=screen->items;
    Ptr32<S5DiscIface> replacement=0;
    Ptr32<Ptr32<S5DiscIface>> at=items;
    int remaining=8;
    do { if (*at) (*at)->vtable->release(*at); *at=replacement; ++at; } while (--remaining);
    if (screen->field244) screen->field244->vtable->release(screen->field244);
    if (screen->field240) screen->field240->vtable->release(screen->field240);
    if (screen->field236) screen->field236->vtable->release(screen->field236);
    if (items) {
        Ptr32<Ptr32<S5DiscIface>> end=screen->items+8;
        while (items!=end) { --end; if (*end) (*end)->vtable->release(*end); }
    }
    w3d_service_destroy_801628ec(screen,flags);
}
}


