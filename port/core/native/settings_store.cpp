// Lectura de ajustes por nombre: el almacén de ajustes cuelga de la aplicación y cada tipo tiene su método virtual.
// Cada lector recibe una referencia a la clave (un puntero al nombre) y el destino, y devuelve lo que devuelva el método.
#include "native_common.h"

namespace {
struct Application {
    char pad[0x64];
    Ptr32<void> settings;   // +0x64
    Ptr32<void> screens;    // +0x68, sin usar aquí
    Ptr32<void> service;    // +0x6c
};
}
extern "C" {
extern Ptr32<Application> A804b1788;  // La aplicación.
void A800fc110();

#define SETTING_READER(ADDR, OFFSET) \
    w3d_u32 A##ADDR(Ptr32<void> key, Ptr32<void> out, w3d_u32, REGS_D) { return call_virtual(A804b1788->settings.get(), OFFSET, key.get(), out.get(), PASS_D); }
SETTING_READER(800fc69c, 0x74)   // siguiente ajuste de una enumeración
SETTING_READER(800fc1b0, 0x7c)   // valor genérico: lo interpreta el recurso destino
SETTING_READER(800fc1f0, 0x84)   // entero
SETTING_READER(800fc230, 0x88)   // entero sin signo
SETTING_READER(800fc270, 0x8c)   // flotante
SETTING_READER(800fc2f0, 0x90)   // vector
SETTING_READER(800fc2b0, 0x94)   // texto
SETTING_READER(800fc330, 0x98)   // sin signo con nombre (armas)
SETTING_READER(800fc370, 0xa0)   // color
SETTING_READER(800fd488, 0xac)

// Enlazan un campo del objeto con el ajuste de ese nombre.
// v25: las cámaras enlazan aquí sus ajustes por nombre; camara_cerca.cpp anota cuáles se acercan con la opción CAM.
void w3d_cam_cerca_enlace(const char *name, w3d_u32 props);
w3d_u32 A800d31d8(Ptr32<char> self, Ptr32<const char> name, REGS_C) {
    Ptr32<const char> key = name;
    w3d_u32 r = A800fc1b0(Ptr32<void>(&key), Ptr32<void>(self + 0x88), c, d, e, f, g, h, PASS_FLOATS);
    w3d_cam_cerca_enlace(name.get(), *(const w3d_u32 *)(self + 0x88).get());
    return r;
}
w3d_u32 A800ee904(Ptr32<char> self, Ptr32<const char> name, REGS_C) {
    Ptr32<const char> key = name;
    return A800fc1b0(Ptr32<void>(&key), Ptr32<void>(self + 0x1c), c, d, e, f, g, h, PASS_FLOATS);
}
// Escribe un ajuste por nombre con los parámetros fijos 0xff y 5.
w3d_u32 A80289d70(w3d_u32, Ptr32<const char> name, Ptr32<void> value, w3d_u32, w3d_u32 e, w3d_u32 f) {
    Ptr32<const char> key = name;
    return ((w3d_u32 (*)(void *, void *, w3d_u32, w3d_u32, void *, void *))A800fc110)(&key, value.get(), 0xff, 5, arg(e), arg(f));
}
// Método 0x54 del servicio en +0x6c, con el valor 5.
w3d_u32 A80129738(w3d_u32, w3d_u32, REGS_C) { return call_virtual(A804b1788->service.get(), 0x54, (void *)5, PASS_C); }
}
