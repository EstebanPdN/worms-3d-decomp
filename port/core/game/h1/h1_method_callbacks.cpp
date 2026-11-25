#include "w3d_ptr.h"
#line 1 "h1_method_callbacks.cpp"
/* Pointer-to-member callback objects (session b169b320). Each class holds
 * a target object and a GCC 2.95 pointer to member function (delta, index,
 * pfn or vtable offset; thunk-style 4-byte vtable entries) and has three
 * methods: call invokes (method)(object), clone copies the callback and
 * rebind copies it for another object. Five instantiations differ only in
 * their vtable. Callbacks are 16 bytes, allocated with the game heap. */

class W3dObject
{
public:
    void w3d_r_unused_slot() __asm__(W3D_SYM("_ZN9W3dObject11unused_slotEv"));
 __attribute__((always_inline)) inline void unused_slot() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_W3dObject, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_W3dObject; };
typedef w3d::Pmf<W3dObject, void()> W3dObjectMethod;

struct W3dMethodCallback
{
    Ptr32<void> vtable;
    Ptr32<W3dObject> object;
    W3dObjectMethod method;
};

extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);

#define W3D_METHOD_CALLBACK(VTABLE, CALL, CLONE, REBIND) \
extern void *VTABLE[]; \
extern "C" void CALL(W3dMethodCallback *self) \
{ \
    (self->method)(self->object); \
} \
extern "C" W3dMethodCallback *CLONE(const W3dMethodCallback *self) \
{ \
    W3dMethodCallback *copy = (W3dMethodCallback *)w3d_heap_allocate_entry_a(sizeof(W3dMethodCallback)); \
    W3dObject *object = self->object; \
    W3dObjectMethod method = self->method; \
    copy->method = method; \
    copy->vtable = VTABLE; \
    copy->object = object; \
    return copy; \
} \
extern "C" W3dMethodCallback *REBIND(const W3dMethodCallback *self, W3dObject *object) \
{ \
    W3dMethodCallback *copy = (W3dMethodCallback *)w3d_heap_allocate_entry_a(sizeof(W3dMethodCallback)); \
    W3dObjectMethod method = self->method; \
    copy->vtable = VTABLE; \
    copy->object = object; \
    copy->method = method; \
    return copy; \
}

W3D_METHOD_CALLBACK(w3d_method_callback_vtable_80413980, w3d_method_callback_call_803528b8, w3d_method_callback_clone_80352918, w3d_method_callback_rebind_80352970)
W3D_METHOD_CALLBACK(w3d_method_callback_vtable_804139a0, w3d_method_callback_call_803529d0, w3d_method_callback_clone_80352a30, w3d_method_callback_rebind_80352a88)
W3D_METHOD_CALLBACK(w3d_method_callback_vtable_80413c88, w3d_method_callback_call_803556f0, w3d_method_callback_clone_80355750, w3d_method_callback_rebind_803557a8)
W3D_METHOD_CALLBACK(w3d_method_callback_vtable_804170d8, w3d_method_callback_call_80356774, w3d_method_callback_clone_803567d4, w3d_method_callback_rebind_8035682c)
W3D_METHOD_CALLBACK(w3d_method_callback_vtable_80417130, w3d_method_callback_call_80356d18, w3d_method_callback_clone_80356d78, w3d_method_callback_rebind_80356dd0)


