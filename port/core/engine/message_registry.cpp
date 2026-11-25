#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "message_registry.c"
/* Reconstructed message-name registry and dispatch entry points, GWMP8P.
 * Global names and prefix types describe observed behavior, not debug symbols.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include <string.h>
typedef unsigned int W3dWord;
typedef unsigned short W3dMessageId;
typedef int W3dStatus;

extern W3dWord w3d_message_name_capacity;
extern Ptr32<Ptr32<const char>> w3d_message_name_slots;
typedef struct W3dMessageContext {
    unsigned char unknown_00[0x14];
    W3dWord recipient;
} W3dMessageContext;
extern Ptr32<W3dMessageContext> w3d_message_context;
extern W3dStatus w3d_message_dispatch_core(Ptr32<void>, W3dWord, int);
extern unsigned char w3d_message_diagnostics;
extern void w3d_message_report(Ptr32<void>, Ptr32<const char>, ...);

W3dWord w3d_message_hash_slot(Ptr32<const char> name);

W3dStatus w3d_message_register(Ptr32<void> unused, Ptr32<const char> name)
{
    W3dWord slot = w3d_message_hash_slot(name);
    W3dWord first = slot;
    while (w3d_message_name_slots[slot] != 0) {
        if (strcmp(w3d_message_name_slots[slot], name) == 0) {
            w3d_message_report(&w3d_message_diagnostics,
                "Message name already registered : %s\n", w3d::VA(name));
            return (W3dStatus)0x80004005u;
        }
        slot = (slot + 1) % w3d_message_name_capacity;
        if (slot == first) return (W3dStatus)0x80004005u;
    }
    w3d_message_name_slots[slot] = name;
    return 0;
}

W3dWord w3d_message_hash_slot(Ptr32<const char> name)
{
    W3dWord hash = 0;
    W3dWord high;
    while (*name) {
        int character = *name++;
        hash <<= 4;
        hash += character;
        high = hash & 0xf0000000u;
        if (high) {
            hash ^= high >> 24;
            hash ^= high;
        }
    }
    return hash % w3d_message_name_capacity;
}

W3dStatus w3d_message_find_id(Ptr32<const char> name, Ptr32<W3dMessageId> id)
{
    W3dWord slot = w3d_message_hash_slot(name);
    W3dWord first = slot;
    while (w3d_message_name_slots[slot] != 0) {
        if (strcmp(w3d_message_name_slots[slot], name) == 0) {
            *id = (W3dMessageId)slot | 0x8000;
            return 0;
        }
        slot = (slot + 1) % w3d_message_name_capacity;
        if (slot == first)
            break;
    }
    *id = 0xffff;
    return (W3dStatus)0x80004005u;
}

W3dStatus w3d_message_find_name(W3dMessageId id, Ptr32<Ptr32<const char>> name)
{
    *name = w3d_message_name_slots[id & 0x7fff];
    if (*name == 0)
        return (W3dStatus)0x80004005u;
    return 0;
}

W3dStatus w3d_message_dispatch(Ptr32<void> message, W3dWord recipient, int children)
{
    return w3d_message_dispatch_core(message, recipient, children);
}

int w3d_fe_spy(Ptr32<void> message);   /* core/native/fe_bridge.cpp (v28): último FE.HighlightItem para la UI de abajo; v42: 1 = retenido */
/* v28: el mismo buscador con un nombre que el reenlace por dirección no cambia (fe_bridge.cpp lo usa). */
W3dStatus w3d_fe_message_id(Ptr32<const char> name, Ptr32<W3dMessageId> id) { return w3d_message_find_id(name, id); }
W3dStatus w3d_message_post_current(Ptr32<void> message)
{
    W3dStatus result;
    if (w3d_fe_spy(message)) return 0;   /* v42: 1 = no se entrega (fe_bridge.cpp) */
    if (w3d_message_context != 0)
        result = w3d_message_dispatch(message, w3d_message_context->recipient, 0);
    else
        result = (W3dStatus)0x80004005u;
    return result;
}
#ifdef __cplusplus
}
#endif

}
