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
extern const char **w3d_message_name_slots;
typedef struct W3dMessageContext {
    unsigned char unknown_00[0x14];
    W3dWord recipient;
} W3dMessageContext;
extern W3dMessageContext *w3d_message_context;
extern W3dStatus w3d_message_dispatch_core(void *, W3dWord, int);
extern unsigned char w3d_message_diagnostics;
extern void w3d_message_report(void *, const char *, ...);

W3dWord w3d_message_hash_slot(const char *name);

W3dStatus w3d_message_register(void *unused, const char *name)
{
    W3dWord slot = w3d_message_hash_slot(name);
    W3dWord first = slot;
    while (w3d_message_name_slots[slot] != 0) {
        if (strcmp(w3d_message_name_slots[slot], name) == 0) {
            w3d_message_report(&w3d_message_diagnostics,
                "Message name already registered : %s\n", name);
            return (W3dStatus)0x80004005u;
        }
        slot = (slot + 1) % w3d_message_name_capacity;
        if (slot == first) return (W3dStatus)0x80004005u;
    }
    w3d_message_name_slots[slot] = name;
    return 0;
}

W3dWord w3d_message_hash_slot(const char *name)
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

W3dStatus w3d_message_find_id(const char *name, W3dMessageId *id)
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

W3dStatus w3d_message_find_name(W3dMessageId id, const char **name)
{
    *name = w3d_message_name_slots[id & 0x7fff];
    if (*name == 0)
        return (W3dStatus)0x80004005u;
    return 0;
}

W3dStatus w3d_message_dispatch(void *message, W3dWord recipient, int children)
{
    return w3d_message_dispatch_core(message, recipient, children);
}

W3dStatus w3d_message_post_current(void *message)
{
    W3dStatus result;
    if (w3d_message_context != 0)
        result = w3d_message_dispatch(message, w3d_message_context->recipient, 0);
    else
        result = (W3dStatus)0x80004005u;
    return result;
}
#ifdef __cplusplus
}
#endif
