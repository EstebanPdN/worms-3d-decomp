// Valores de partida guardados como recursos con nombre.
#include "native_game.h"

namespace {
struct TypeInfo { char pad[0x14]; Ptr32<TypeInfo> parent; };
struct Application { char pad[0xbc]; w3d_u32 flags; };
const w3d_u32 kFlagNoSettings = 0x10;
const int kKindResource = 5;
}
extern "C" {
extern Ptr32<Application> A804b1788;
extern TypeInfo A80366208;  // Tipo del recurso de valor.
w3d_u32 A800fc1b0(void *key, void *out, ...);
void A80341584();
w3d_u32 A801797b4(void *resource);

// 0x8028496c: valor del recurso con ese nombre, si existe y es del tipo esperado. Sin nombre o sin ajustes da 0.
// El original saca una copia temporal de la cadena en las dos rutas de fallo para un aviso que no llegó a la versión final.
w3d_u32 A8028496c(w3d_u32, Ptr32<GameString> name) {
    if (!name->header()->length || (A804b1788->flags & kFlagNoSettings)) return 0;
    Ptr32<char> key = name->text;
    Ptr32<void> resource{(void *)nullptr};
    w3d_u32 value = 0;
    if ((int)((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, &resource) >= 0 && call_virtual<int>(resource.get(), 0x18) == kKindResource) {
        A80341584();
        const char *object = (const char *)g2h(A801797b4(resource.get()));
        const TypeInfo *type = (const TypeInfo *)g2h(call_virtual(object, 0x14));
        bool matches = true;
        while (type != &A80366208) {
            const TypeInfo *parent = type->parent;
            if (parent == type) { matches = false; break; }
            type = parent;
        }
        if (matches) {
            A80341584();
            value = *(const w3d_u32 *)((const char *)g2h(A801797b4(resource.get())) + 0x1c);
        }
    }
    release_if_set(resource.get());
    return value;
}
}
