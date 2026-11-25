// Inicializadores estáticos que el compilador del anfitrión no puede reproducir, porque leen datos del DOL.
#include "w3d_ptr.h"
using namespace w3d;

extern "C" {
struct Vec3 { float x, y, z; };
extern Vec3 A80453030[10];
extern w3d_u32 A804ab3c8;
extern w3d_u32 A804afa48, A804afa4c, A804afa50, A804afa54, A804afa58, A804afa5c, A804afa60, A804afa64, A804afa68;

// 0x80141b14: punteros a una reserva externa y diez posiciones de referencia.
void A80141b14(int initialize, int priority) {
    if (priority != 0xffff || initialize == 0) return;
    const w3d_u32 base = A804ab3c8;
    A804afa48 = base + 0x4000;
    A804afa4c = base;
    A804afa50 = base + 0x2e0;
    A804afa54 = base + 0x3070;
    A804afa58 = base;
    A804afa5c = base + 0x3ff0;
    A804afa60 = base + 0x3fb0;
    A804afa64 = base + 0x3f30;
    A804afa68 = base;
    static const Vec3 points[10] = {
        {0, 20, 0}, {0, 10, 4}, {0, 10, -4}, {4, 10, 0}, {-4, 10, 0},
        {0, 0, 0}, {4, 0, 0}, {-4, 0, 0}, {0, 0, 4}, {0, 0, -4},
    };
    for (int i = 0; i < 10; i++) A80453030[i] = points[i];
}
}
