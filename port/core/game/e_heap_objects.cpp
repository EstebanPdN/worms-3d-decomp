#include "w3d_ptr.h"
#line 1 "e_heap_objects.cpp"
/* Heap-allocated interface holders, lazy singletons and helpers (0x80343740..0x8034492c).
 *
 * Names are inferred from behavior; no original symbols survive. The deleting
 * destructors release held interfaces in reverse member order (4-byte-entry
 * vtable at +0, release slot at +0x10), run the base destructor at 0x8015a39c
 * with flag 0, and return the storage to the object heap at 0x804b0044 when
 * bit 0 of the flags is set. Observed layouts:
 *   panel:  +0x88 held interface, +0xcc..+0xd8 four more held slots
 *   widget: +0x4c..+0x5c five held interface slots
 * Lazy singletons keep a ready flag next to the object in small data.
 */
#include <stdarg.h>
#include <sn-inline-stdarg.h>

extern "C" {

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    Ptr32<void> unknown_00[4];
    Ptr32<void (Ptr32<W3dInterface>)> release;
} W3dInterfaceTable;

struct W3dInterface {
    Ptr32<W3dInterfaceTable> vtable;
};

typedef struct W3dHeapPanel {
    unsigned char unknown_00[0x88];
    Ptr32<W3dInterface> base_held;
    unsigned char unknown_8c[0xcc - 0x8c];
    Ptr32<W3dInterface> held[4];
} W3dHeapPanel;

typedef struct W3dHeapWidget {
    unsigned char unknown_00[0x4c];
    Ptr32<W3dInterface> held[5];
} W3dHeapWidget;

typedef struct W3dMotionState {
    unsigned int flags;
    float scale;
    int value_08;
    int value_0c;
    int time;
} W3dMotionState;

typedef struct W3dSingleSlot {
    int value;
} W3dSingleSlot;

typedef struct W3dPointerPair {
    Ptr32<void> first;
    Ptr32<void> second;
} W3dPointerPair;

typedef struct W3dRecord12 {
    unsigned char unknown_00[12];
} W3dRecord12;

typedef struct W3dService {
    unsigned char unknown_00[4];
} W3dService;

typedef struct W3dHeap {
    unsigned char unknown_00[4];
} W3dHeap;

extern W3dHeap w3d_object_heap_804b0044;
extern const float w3d_f32_80373c20[];
extern W3dSingleSlot w3d_registry_804ad2d4;
extern int w3d_registry_ready_804ad2d8;
extern W3dPointerPair w3d_pair_8042df94[];
extern int w3d_pair_ready_804ad674;
extern W3dService w3d_service_804ae550;
extern int w3d_service_ready_804ae554;

void w3d_heap_object_base_destroy_8015a39c(Ptr32<void> object, int flags);
void w3d_heap_release(Ptr32<W3dHeap> heap, Ptr32<void> object);
void w3d_handle_storage_release(Ptr32<void> storage);
void w3d_service_init_801fe300(Ptr32<W3dService> service);
int w3d_text_vformat_802ed5e0(Ptr32<char> target, Ptr32<const char> format, va_list arguments);
void w3d_single_slot_init_8034384c(Ptr32<W3dSingleSlot> slot);
Ptr32<W3dPointerPair> w3d_pointer_pair_init_80343a48(Ptr32<W3dPointerPair> pair);

void w3d_empty_80343740(void)
{
}

void w3d_empty_80343744(void)
{
}

#if 0 /* 0x80343748: store order matches, but register choice differs (r10/r11 vs r11/r9). */
void w3d_motion_state_reset(W3dMotionState *state)
{
    state->time = 0;
    state->flags &= 0x1fffff;
    state->scale = w3d_f32_80373c20[0];
    state->value_08 = 0;
    state->value_0c = 0;
}
#endif

void w3d_heap_object_destroy_80343774(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->held[2])
        w3d_handle_storage_release(object->held[2]);
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_empty_80343808(void)
{
}

void w3d_empty_8034380c(void)
{
}

Ptr32<W3dSingleSlot> w3d_registry_instance_80343810(void)
{
    if (!w3d_registry_ready_804ad2d8) {
        w3d_single_slot_init_8034384c(&w3d_registry_804ad2d4);
        w3d_registry_ready_804ad2d8 = 1;
    }
    return &w3d_registry_804ad2d4;
}

void w3d_single_slot_init_8034384c(Ptr32<W3dSingleSlot> slot)
{
    slot->value = 0;
}

void w3d_empty_80343858(void)
{
}

void w3d_heap_object_destroy_8034385c(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->held[1])
        object->held[1]->vtable->release(object->held[1]);
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_heap_object_destroy_803438fc(Ptr32<W3dHeapPanel> object, int flags)
{
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

Ptr32<W3dPointerPair> w3d_pair_instance_80343994(void)
{
    if (!w3d_pair_ready_804ad674) {
        w3d_pointer_pair_init_80343a48(w3d_pair_8042df94);
        w3d_pair_ready_804ad674 = 1;
    }
    return w3d_pair_8042df94;
}

Ptr32<W3dPointerPair> w3d_pointer_pair_init_80343a48(Ptr32<W3dPointerPair> pair)
{
    Ptr32<W3dPointerPair> self = pair;
    self->first = 0;
    self->second = 0;
    return self;
}

void w3d_heap_object_destroy_80343a5c(Ptr32<W3dHeapPanel> object, int flags)
{
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_heap_object_destroy_80343aa4(Ptr32<W3dHeapWidget> object, int flags)
{
    if (object->held[4])
        object->held[4]->vtable->release(object->held[4]);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

Ptr32<char> w3d_text_format_80343b0c(Ptr32<char> target, Ptr32<const char> format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    w3d_text_vformat_802ed5e0(target, format, arguments);
    return target;
}

Ptr32<W3dRecord12> w3d_record12_at_80343bb4(Ptr32<W3dRecord12> records, int index)
{
    return &records[index];
}

void w3d_heap_object_destroy_80343c7c(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->held[3])
        object->held[3]->vtable->release(object->held[3]);
    if (object->held[2])
        object->held[2]->vtable->release(object->held[2]);
    if (object->held[1])
        object->held[1]->vtable->release(object->held[1]);
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_heap_object_destroy_80343d54(Ptr32<W3dHeapWidget> object, int flags)
{
    if (object->held[2])
        object->held[2]->vtable->release(object->held[2]);
    if (object->held[1])
        object->held[1]->vtable->release(object->held[1]);
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_empty_80343df4(void)
{
}

void w3d_heap_object_destroy_803441d8(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->held[1])
        object->held[1]->vtable->release(object->held[1]);
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

Ptr32<W3dService> w3d_service_instance_80344278(void)
{
    if (!w3d_service_ready_804ae554) {
        w3d_service_init_801fe300(&w3d_service_804ae550);
        w3d_service_ready_804ae554 = 1;
    }
    return &w3d_service_804ae550;
}

Ptr32<char> w3d_text_format_803442b4(Ptr32<char> target, Ptr32<const char> format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    w3d_text_vformat_802ed5e0(target, format, arguments);
    return target;
}

void w3d_empty_8034435c(void)
{
}

void w3d_digits_fill_zero(Ptr32<char> digits)
{
    Ptr32<char> digit = digits + 32;
    int i;
    for (i = 0; i < 33; i++)
        *digit-- = '0';
}

void w3d_heap_object_destroy_803446e8(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_heap_object_destroy_80344750(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_heap_object_destroy_803447d4(Ptr32<W3dHeapPanel> object, int flags)
{
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    if (object->base_held)
        object->base_held->vtable->release(object->base_held);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

void w3d_heap_object_destroy_80344858(Ptr32<W3dHeapWidget> object, int flags)
{
    if (object->held[4])
        object->held[4]->vtable->release(object->held[4]);
    if (object->held[3])
        object->held[3]->vtable->release(object->held[3]);
    if (object->held[2])
        object->held[2]->vtable->release(object->held[2]);
    if (object->held[1])
        object->held[1]->vtable->release(object->held[1]);
    if (object->held[0])
        object->held[0]->vtable->release(object->held[0]);
    w3d_heap_object_base_destroy_8015a39c(object, 0);
    if (flags & 1)
        w3d_heap_release(&w3d_object_heap_804b0044, object);
}

}


