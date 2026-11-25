// Llamada de los objetos de retrollamada a método (0x803528b8, 0x803529d0, 0x803556f0, 0x80356774, 0x80356d18).
// El objeto guarda {tabla, destino, puntero a método de GCC 2.95}. El original no menciona más argumento que el
// objeto, pero r4 y siguientes llegan vivos al método: aquí se reenvían de forma explícita.
#include "w3d_ptr.h"

namespace {
struct Callback {
    w3d_u32 vtable, object;
    w3d::PmfData method;
};
typedef unsigned long (*Target)(void *, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
inline unsigned long invoke(w3d_u32 self, unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long e, unsigned long f, unsigned long g) {
    const Callback *cb = (const Callback *)w3d::g2h(self);
    void *object;
    Target fn = (Target)cb->method.target(w3d::g2h(cb->object), &object);
    return fn(object, a, b, c, d, e, f, g);
}
}

#define CALLBACK_CALL(ADDR) \
    extern "C" unsigned long ADDR(w3d_u32 self, unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long e, unsigned long f, unsigned long g) { \
        return invoke(self, a, b, c, d, e, f, g); \
    }
CALLBACK_CALL(A803528b8)
CALLBACK_CALL(A803529d0)
CALLBACK_CALL(A803556f0)
CALLBACK_CALL(A80356774)
CALLBACK_CALL(A80356d18)
