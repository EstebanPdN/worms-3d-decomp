// GWMP8P rev0 0x80035388. Releases a camera's held objects, tells the
// service to drop two values, deletes its item list and empties it. Names
// are inferred from the original instructions.
struct Held {
    void **vtable;
    int Slot6() { return ((int (*)(Held *))vtable[6])(this); }
    int Slot9() { return ((int (*)(Held *))vtable[9])(this); }
    void Release() { ((void (*)(Held *))vtable[4])(this); }
};
struct Service {
    void **vtable;
    void Slot7(int v) { ((void (*)(Service *, int))vtable[7])(this, v); }
    void Slot10(int v) { ((void (*)(Service *, int))vtable[10])(this, v); }
};
struct Engine { char unknown00[48]; Service *service; };
struct Item {
    char unknown00[72];
    void **vtable;
    void Delete() { ((void (*)(Item *, int))vtable[2])(this, 3); }
};
struct ItemVector { Item **start, **finish; Item **end() { return finish; } void shrink(int n) { finish = (Item **)((char *)finish - n); } };
struct Camera {
    char unknown000[316];
    ItemVector items;       /* +316 */
    char unknown144[468];
    Held *primary;          /* +792 */
    Held *third;            /* +796 */
    Held *second;           /* +800 */
    Held *first;            /* +804 */
};
extern Engine *g_engine_804b1788;
extern int g_active_804aa8c8;
extern "C" void *memcpy_802eee50(void *, const void *, ...);
inline void Drop(Held *&p, Held *none) { if (p) p->Release(); p = none; }
extern "C" void w3d_d29a_camera_shutdown_80035388(Camera *self)
{
    if (self->primary) {
        Held *none = 0;
        { Service *s = g_engine_804b1788->service; void **t = s->vtable; ((void (*)(Service *, int))t[7])(s, self->primary->Slot6()); }
        { Service *s = g_engine_804b1788->service; void **t = s->vtable; ((void (*)(Service *, int))t[10])(s, self->primary->Slot9()); }
        Drop(self->primary, none);
        Drop(self->first, none);
        Drop(self->second, none);
        Drop(self->third, none);
    }
    g_active_804aa8c8 = 0;
    for (Item **it = self->items.start; it != self->items.end(); ++it) { Item *none = 0; if (*it) (*it)->Delete(); *it = none; }
    Item **last = self->items.end(); unsigned int n = (char *)last - (char *)self->items.start; memcpy_802eee50(self->items.start, last, 0); self->items.shrink(n);
}
