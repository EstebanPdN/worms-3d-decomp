// Mapa de relieve: de la imagen de alturas a un mapa de pendientes (dos bytes por texel) y de ahí a bloques de 32 B de textura.
#include "native_common.h"

namespace {
inline uint8_t slope(int from, int to) { return (uint8_t)(((from - to) >> 2) + 128); }
}
extern "C" {
w3d_u32 A801fe0b8(w3d_u32 bytes);
void A801fe160(void *block);
void A801d7d78(void *slopes, w3d_u32 pitch, w3d_u32 width, w3d_u32 height, w3d_u32 x, w3d_u32 y, void *out);

// 0x801d8a54: la última columna se resuelve con el paso de fila y no con el ancho, como en el original.
w3d_u32 A801d8a54(Ptr32<const uint8_t> heights_ptr, w3d_u32, w3d_u32 stride, w3d_u32 width, w3d_u32 height, Ptr32<char> out, w3d_u32, w3d_u32, Ptr32<w3d_u32> written) {
    const uint8_t *heights = heights_ptr;
    const w3d_u32 pitch = stride * 2;
    uint8_t *slopes = at<uint8_t>(A801fe0b8(width * height * 2));
    for (w3d_u32 y = 0; y + 1 < height; y++) {
        const uint8_t *row = heights + y * stride;
        uint8_t *line = slopes + y * pitch;
        for (w3d_u32 x = 0; x + 1 < width; x++) {
            *line++ = slope(row[x], row[x + 1]);
            *line++ = slope(row[x], row[x + stride]);
        }
    }
    for (w3d_u32 y = 0; y + 1 < height; y++) {
        const uint8_t *row = heights + y * stride;
        const int last = row[stride - 1];
        uint8_t *texel = slopes + (y + 1) * pitch - 2;
        texel[0] = slope(last, row[0]);
        texel[1] = slope(last, row[stride - 1 + stride]);
    }
    const w3d_u32 last_row = height - 1;
    const uint8_t *row = heights + last_row * stride;
    uint8_t *line = slopes + last_row * pitch;
    for (w3d_u32 x = 0; x + 1 < width; x++) {
        *line++ = 0x7f;
        *line++ = slope(row[x], heights[x]);
    }
    const uint8_t *corner = row + width - 1;
    uint8_t *corner_texel = slopes + last_row * pitch + width - 1;
    corner_texel[0] = 0x80;
    corner_texel[1] = slope(corner[0], corner[-(int)stride]);
    *written = 0;
    const w3d_u32 rows = (height + 3) >> 2, columns = (width + 3) >> 2;
    char *block = out;
    for (w3d_u32 r = 0; r < rows; r++) {
        for (w3d_u32 c = 0; c < columns; c++) {
            A801d7d78(slopes, pitch, width, height, c * 4, r * 4, block);
            block += 32;
            *written += 32;
        }
    }
    A801fe160(slopes);
    return 0;
}
}
