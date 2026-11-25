// Superficies de textura: desplazamiento y paso de cada nivel de detalle según el formato, y reserva de los datos.
#include "native_game.h"

namespace {
struct Surface {
    char pad[0x18];
    int format;                        // +0x18
    Ptr32<XomArray<w3d_u32>> offsets;  // +0x1c
    Ptr32<XomArray<w3d_u32>> pitches;  // +0x20
    char pad2[0x2a - 0x24];
    uint16_t mip_count;                // +0x2a
    uint16_t height;                   // +0x2c
    uint16_t width;                    // +0x2e
    Ptr32<XomArray<char>> pixels;      // +0x30
};
int bits_per_pixel(int format) {
    switch (format) {
    case 0: return 24;
    case 1: case 2: case 11: return 32;
    case 8: case 9: case 24: return 4;
    case 3: case 4: case 5: case 12: case 13: case 14: case 18: case 22: return 16;
    case 6: case 7: case 10: case 15: case 16: case 19: case 23: return 8;
    default: return 0;
    }
}
// Los formatos de bloques de GX redondean ancho y alto del nivel al tamaño del bloque.
void block_size(int format, int &block_width, int &block_height) {
    block_width = block_height = 1;
    switch (format) {
    case 11: case 12: case 13: case 14: case 18: case 22: block_width = 4; block_height = 4; break;
    case 15: case 16: case 19: block_width = 8; block_height = 4; break;
    case 17: case 20: block_width = 8; block_height = 8; break;
    }
}
}
extern "C" {
// 0x801afac0. Los formatos 17 y 20 no tienen tamaño de píxel en el original: su rama cae en una trampa; aquí no se reserva nada para ellos.
void A801afac0(Ptr32<Surface> self) {
    const int bits = bits_per_pixel(self->format);
    if (!bits) return;
    const int mips = self->mip_count;
    w3d_u32 *pitches = lock_xom_array(self->pitches, mips, 4, 1);
    w3d_u32 *offsets = lock_xom_array(self->offsets, mips, 4, 1);
    int block_width, block_height;
    block_size(self->format, block_width, block_height);
    w3d_u32 width = self->width, height = self->height, total = 0;
    for (int i = 0; i < mips; i++) {
        const w3d_u32 rounded_width = (width + block_width - 1) & -block_width;
        const w3d_u32 rounded_height = (height + block_height - 1) & -block_height;
        const w3d_u32 pitch = (w3d_u32)((int)rounded_width * bits) >> 3;
        pitches[i] = pitch;
        offsets[i] = total;
        total += pitch * rounded_height;
        width >>= 1;
        height >>= 1;
        if (!width) width = 1;
        if (!height) height = 1;
    }
    lock_xom_array(self->pixels, (int)total, 1, 0);
}
}
