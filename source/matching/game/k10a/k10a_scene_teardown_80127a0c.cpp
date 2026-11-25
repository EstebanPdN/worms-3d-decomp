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
    void (*slots0[8])();
    int (*notify)(K10aRenderer *renderer, int *value);   // +32
};
struct K10aRenderer
{
    K10aRendererTable *vtable;
};

struct K10aHeld
{
    void **vtable;
};

struct K10aScene
{
    char pad0[96];
    K10aRenderer *renderer;      // +96
    K10aHeld *heldB;             // +100
    char pad104[40];
    K10aHeld *heldA;             // +144
};

extern void *w3d_listener_804aaf88;
extern void *w3d_listener_804ab004;
extern void *w3d_listener_804aaabc;
extern void *w3d_listener_804aaba4;
extern void *w3d_listener_804aadcc;
extern "C" void w3d_auto_802cc58c(int listener);
extern "C" K10aContext *w3d_engine_get_context(void);
extern "C" int w3d_auto_8015fd1c(void *listener);
extern "C" void w3d_auto_80164f88(K10aRenderer *renderer);
extern "C" void fn_800fbf64(void);
extern "C" void w3d_empty_80128084(K10aScene *self);
extern "C" int w3d_runtime_owner_finish(K10aScene *self);

extern "C" void w3d_k10a_scene_teardown_80127a0c(K10aScene *self)
{
    w3d_auto_802cc58c((int)w3d_listener_804aaf88);
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
        ((int (*)(K10aHeld *))self->heldA->vtable[4])(self->heldA);
    self->heldA = (K10aHeld *)zero;
    w3d_auto_80164f88(self->renderer);
    fn_800fbf64();
    if (self->heldB)
        ((int (*)(K10aHeld *))self->heldB->vtable[4])(self->heldB);
    self->heldB = (K10aHeld *)zero;
    w3d_empty_80128084(self);
    w3d_runtime_owner_finish(self);
}
