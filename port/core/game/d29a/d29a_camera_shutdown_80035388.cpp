#include "w3d_ptr.h"
#line 1 "d29a_camera_shutdown_80035388.cpp"
// GWMP8P rev0 0x80035388. Releases a camera's held objects, tells the
// service to drop two values, deletes its item list and empties it. Names
// are inferred from the original instructions.
struct Held {
    Ptr32<Ptr32<void>> vtable;
    int Slot6() { return ((Ptr32<int (Ptr32<Held>)>)vtable[6])(this); }
    int Slot9() { return ((Ptr32<int (Ptr32<Held>)>)vtable[9])(this); }
    void Release() { ((Ptr32<void (Ptr32<Held>)>)vtable[4])(this); }
};
struct Service {
    Ptr32<Ptr32<void>> vtable;
    void Slot7(int v) { ((Ptr32<void (Ptr32<Service>, int)>)vtable[7])(this, v); }
    void Slot10(int v) { ((Ptr32<void (Ptr32<Service>, int)>)vtable[10])(this, v); }
};
struct Engine { char unknown00[48]; Ptr32<Service> service; };
struct Item {
    char unknown00[72];
    Ptr32<Ptr32<void>> vtable;
    void Delete() { ((Ptr32<void (Ptr32<Item>, int)>)vtable[2])(this, 3); }
};
struct ItemVector { Ptr32<Ptr32<Item>> start; Ptr32<Ptr32<Item>> finish; Ptr32<Ptr32<Item>> end() { return finish; } void shrink(int n) { finish = (Ptr32<Ptr32<Item>>)((Ptr32<char>)finish - n); } };
struct Camera {
    char unknown000[316];
    ItemVector items;       /* +316 */
    char unknown144[468];
    Ptr32<Held> primary;          /* +792 */
    Ptr32<Held> third;            /* +796 */
    Ptr32<Held> second;           /* +800 */
    Ptr32<Held> first;            /* +804 */
};
extern Ptr32<Engine> g_engine_804b1788;
extern int g_active_804aa8c8;
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, ...);
inline void Drop(Ptr32<Held> &p, Ptr32<Held> none) { if (p) p->Release(); p = none; }
extern "C" void w3d_d29a_camera_shutdown_80035388(Ptr32<Camera> self)
{
    if (self->primary) {
        Ptr32<Held> none = 0;
        { Ptr32<Service> s = g_engine_804b1788->service; Ptr32<Ptr32<void>> t = s->vtable; ((Ptr32<void (Ptr32<Service>, int)>)t[7])(s, self->primary->Slot6()); }
        { Ptr32<Service> s = g_engine_804b1788->service; Ptr32<Ptr32<void>> t = s->vtable; ((Ptr32<void (Ptr32<Service>, int)>)t[10])(s, self->primary->Slot9()); }
        Drop(self->primary, none);
        Drop(self->first, none);
        Drop(self->second, none);
        Drop(self->third, none);
    }
    g_active_804aa8c8 = 0;
    for (Ptr32<Ptr32<Item>> it = self->items.start; it != self->items.end(); ++it) { Ptr32<Item> none = 0; if (*it) (*it)->Delete(); *it = none; }
    Ptr32<Ptr32<Item>> last = self->items.end(); unsigned int n = (Ptr32<char>)last - (Ptr32<char>)self->items.start; memcpy_802eee50(self->items.start, last, 0); self->items.shrink(n);
}


