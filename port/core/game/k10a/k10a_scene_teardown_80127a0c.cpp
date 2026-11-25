#include "w3d_ptr.h"
#line 1 "k10a_scene_teardown_80127a0c.cpp"
// Appears to tear down a scene object: it re-notifies four global listeners (three
// of them optional), each time telling the object's renderer about the engine
// context value, then releases two held interfaces and finishes the owner.
struct K10aContext
{
    char pad0[48];
    int value;                   // +48
};

struct K10aRenderer;
struct K10aRendererTable
{
    Ptr32<void (void)> slots0[8];
    Ptr32<int (Ptr32<K10aRenderer>, Ptr32<int>)> notify;   // +32
};
struct K10aRenderer
{
    Ptr32<K10aRendererTable> vtable;
};

struct K10aHeld
{
    Ptr32<Ptr32<void>> vtable;
};

struct K10aScene
{
    char pad0[96];
    Ptr32<K10aRenderer> renderer;      // +96
    Ptr32<K10aHeld> heldB;             // +100
    char pad104[40];
    Ptr32<K10aHeld> heldA;             // +144
};

extern Ptr32<void> w3d_listener_804aaf88;
extern Ptr32<void> w3d_listener_804ab004;
extern Ptr32<void> w3d_listener_804aaabc;
extern Ptr32<void> w3d_listener_804aaba4;
extern Ptr32<void> w3d_listener_804aadcc;
extern "C" void w3d_auto_802cc58c(int listener);
extern "C" Ptr32<K10aContext> w3d_engine_get_context(void);
extern "C" int w3d_auto_8015fd1c(Ptr32<void> listener);
extern "C" void w3d_auto_80164f88(Ptr32<K10aRenderer> renderer);
extern "C" void fn_800fbf64(void);
extern "C" void w3d_empty_80128084(Ptr32<K10aScene> self);
extern "C" int w3d_runtime_owner_finish(Ptr32<K10aScene> self);

extern "C" void w3d_k10a_scene_teardown_80127a0c(Ptr32<K10aScene> self)
{
    w3d_auto_802cc58c((int)w3d::H(w3d_listener_804aaf88));
    int value = w3d_engine_get_context()->value;
    if (w3d_listener_804ab004)
        w3d_auto_8015fd1c(w3d_listener_804ab004);
    self->renderer->vtable->notify(self->renderer, &value);
    if (w3d_listener_804aaabc)
        w3d_auto_8015fd1c(w3d_listener_804aaabc);
    self->renderer->vtable->notify(self->renderer, &value);
    if (w3d_listener_804aaba4)
        w3d_auto_8015fd1c(w3d_listener_804aaba4);
    int zero = 0;
    self->renderer->vtable->notify(self->renderer, &value);
    w3d_auto_8015fd1c(w3d_listener_804aadcc);
    self->renderer->vtable->notify(self->renderer, &value);
    if (self->heldA)
        ((Ptr32<int (Ptr32<K10aHeld>)>)self->heldA->vtable[4])(self->heldA);
    self->heldA = (Ptr32<K10aHeld>)w3d::G(zero);
    w3d_auto_80164f88(self->renderer);
    fn_800fbf64();
    if (self->heldB)
        ((Ptr32<int (Ptr32<K10aHeld>)>)self->heldB->vtable[4])(self->heldB);
    self->heldB = (Ptr32<K10aHeld>)w3d::G(zero);
    w3d_empty_80128084(self);
    w3d_runtime_owner_finish(self);
}


