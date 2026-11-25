/* GWMP8P rev0 0x80211a14. Stores a service in the map at +64, appends it to the list selected
 * by a 4-bit field at +32 (twelve-byte lists from +92), and forwards to the table slot at +20.
 * Real STLport 4.5.3 hash_map. The list class is hand-written from the original: its growth
 * works in bytes (capacity max(size + 1, size * 3 / 2) * 4) with no allocation fallback, and it
 * is not an STLport member. memcpy is declared variadic because the original clears cr1 first. */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistryBase { virtual int s0(); virtual int s1(); virtual int s2(); virtual int attach(D30sIface *); virtual int detach(D30sIface *); };
extern "C" void *w3d_handle_storage_allocate(unsigned);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *d30s_memcpy_802eee50(...);
template <class T> inline const T &d30s_max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &d30s_min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct D30sList {
    T *start, *finish, *storage;
    void grow() {
        unsigned size = (char *)finish - (char *)start;
        unsigned capacity = d30s_max<int>(size + 1, size + (size >> 1)) * 4;
        char *fresh = (char *)w3d_handle_storage_allocate(capacity);
        if (start) {
            d30s_memcpy_802eee50(fresh, start, d30s_min(capacity, size));
            w3d_handle_storage_release(start);
        }
        start = (T *)fresh;
        finish = (T *)(fresh + size);
        storage = (T *)(fresh + capacity);
    }
    void push(const T &v) {
        if (finish == storage) grow();
        *finish = v;
        ++finish;
    }
};
struct D30sMember : D30sIface { char u[28]; unsigned reserved : 12; unsigned kind : 4; unsigned rest : 16; };
struct D30sRegistry64 : D30sRegistryBase { char unknown[60]; D30sIfaceMap services; char u2[28 - 28]; D30sList<D30sMember *> lists[16]; };
extern "C" int d30s_guid_map_attach_80211a14(D30sRegistry64 *self, D30sMember *s) {
    self->services[w3d_auto_801fff3c(s)] = s;
    self->lists[s->kind].push(s);
    return self->attach(s);
}
