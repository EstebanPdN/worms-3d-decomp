#include "w3d_ptr.h"
#line 1 "h1_text_handle_factory.cpp"
/* Text-handle factories of two sibling widgets (session b169b320, from the
 * Codex cx9c near-miss layout). Each builds its text object (56 bytes,
 * constructed at 0x8015d0a8 and filled at 0x8015d2f4), wraps a retained
 * handle to it in a 32-bit tagged handle (type 10, mode 6), stores it at
 * +0x2c, refreshes itself through vtable slot 0x88 and returns the handle.
 * The handle is allocated with the global operator new (game heap). */

struct W3dInterface
{
    Ptr32<Ptr32<void>> vtable;
};
struct W3dText;
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
extern "C" Ptr32<W3dText> w3d_text_construct_8015d0a8(Ptr32<void> storage);
extern "C" void w3d_text_set_8015d2f4(Ptr32<W3dText> text, Ptr32<void> source);

/* Retained interface pointer: copies retain (slot 0x0c), destruction releases (slot 0x10). */
struct W3dHeld
{
    Ptr32<W3dInterface> p;
    W3dHeld(const W3dHeld &other) : p(other.p) { if (p) ((Ptr32<void (Ptr32<W3dInterface>)>)p->vtable[3])(p); }
    ~W3dHeld() { if (p) ((Ptr32<void (Ptr32<W3dInterface>)>)p->vtable[4])(p); }
};
extern "C" W3dHeld w3d_text_owner_make_handle(Ptr32<W3dText> text);

struct W3dTaggedHandle
{
    W3dHeld held;
    unsigned int other:11; unsigned int mode:5; unsigned int user:8; unsigned int flag:1; unsigned int type:7;
    W3dTaggedHandle(const W3dHeld &r) : held(r) { type = 10; flag = 0; user = 0; mode = 6; }
};

struct W3dTextWidget
{
    Ptr32<Ptr32<void>> vtable;
    unsigned char unknown_04[36];
    Ptr32<W3dText> text;                 /* 0x28 */
    Ptr32<W3dTaggedHandle> handle;       /* 0x2c */
};

#define W3D_TEXT_HANDLE_FACTORY(NAME) \
extern "C" W3dTaggedHandle *NAME(W3dTextWidget *self, void *source) \
{ \
    self->text = w3d_text_construct_8015d0a8(w3d_heap_allocate_entry_a(56)); \
    w3d_text_set_8015d2f4(self->text, source); \
    self->handle = new W3dTaggedHandle(w3d_text_owner_make_handle(self->text)); \
    ((void (*)(W3dTextWidget *, int))self->vtable[34])(self, 1); \
    return self->handle; \
}

W3D_TEXT_HANDLE_FACTORY(w3d_text_handle_make_80348e34)
W3D_TEXT_HANDLE_FACTORY(w3d_text_handle_make_8034a128)


