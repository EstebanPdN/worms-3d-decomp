// Sprites sobre una malla compartida por textura. Cada grupo tiene un conjunto de bits con las celdas ocupadas y seis arrays
// paralelos en la geometría. Pedir un sprite reutiliza la primera celda libre o añade una al final.
#include "native_common.h"

namespace {
struct XomArray {
    w3d_u32 table;
    uint16_t references;  // +4
    char pad[0x18 - 6];
    int count;            // +0x18
    uint16_t locks;       // +0x1c
    uint16_t pad2;
    char data[1];         // +0x20
};
struct Rgba { uint8_t r, g, b, a; };
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct SpriteGeometry {
    char pad[8];
    w3d_u32 flags;                // +0x08. PPC toca el byte bajo en +0xb.
    char pad2[0x40 - 0xc];
    Ptr32<XomArray> positions;    // +0x40
    Ptr32<XomArray> uvs;          // +0x44
    char pad3[0x54 - 0x48];
    Ptr32<XomArray> colors;       // +0x54: opcional
    Ptr32<XomArray> weights;      // +0x58: opcional
    char pad4[0x60 - 0x5c];
    Ptr32<XomArray> visibility;   // +0x60
    Ptr32<XomArray> rotation;     // +0x64
};
struct SpriteGroup { char pad[0x30]; Ptr32<SpriteGeometry> geometry; };
struct BitSet {
    Ptr32<w3d_u32> begin, end, capacity;
    w3d_u32 count;
};
struct TextureInfo { char pad[0x28]; uint16_t width; uint16_t height; };
struct Sprite {
    char pad[8];
    w3d_u32 flags;         // +0x08
    Vec3 position;         // +0x0c
    Vec3 rotation;         // +0x18
    Vec2 size;             // +0x24
    float depth;           // +0x2c
    w3d_u32 pad2;          // +0x30
    char pad3[0x74 - 0x34];
    Ptr32<void> texture;   // +0x74
    Rgba color;            // +0x78
    w3d_u32 slot;          // +0x7c
    Ptr32<void> group;     // +0x80
    uint8_t hidden;        // +0x84
};
const unsigned kAddRef = 0xc, kRelease = 0x10;
}
extern "C" {
void A80185af0(void *, w3d_u32, w3d_u32);
w3d_u32 A80172050(void *, w3d_u32);
w3d_u32 A801720c0(void *, w3d_u32);
w3d_u32 A801ef048(void *reference, int count, int element, int mode);
w3d_u32 A80212fd4(w3d_u32);
void A802134fc(void *);
}
namespace {
// Acceso de escritura a un array XOM con esa longitud: sin copia si solo lo usa este objeto y la longitud ya es esa.
char *lock_array(Ptr32<XomArray> &array, int count, int element) {
    if (array->references == 1 && count == array->count) {
        array->locks++;
        return array->data;
    }
    return at<char>(A801ef048(&array, count, element, 2));
}
int find_free_cell(const BitSet *bits) {
    const w3d_u32 words = (bits->end.v - bits->begin.v) >> 2;
    for (w3d_u32 i = 0; i < words; i++) {
        w3d_u32 word = bits->begin[i];
        if (word == 0xffffffffu) continue;
        int bit = 0;
        while (word & 1) { word >>= 1; bit++; }
        const w3d_u32 cell = i * 32 + bit;
        return cell < bits->count ? (int)cell : -1;
    }
    return -1;
}
// Añade una celda ocupada, ampliando los bits si hace falta. El crecimiento en palabras es del original: mide en bytes y multiplica por 4.
int append_cell(BitSet *bits) {
    const w3d_u32 used = bits->end.v - bits->begin.v;
    if ((w3d_u32)((int)used >> 2) < (bits->count >> 5) + 1) {
        if (bits->end.v == bits->capacity.v) {
            const int grown = used + (used >> 1), next = used + 1;
            const w3d_u32 bytes = (w3d_u32)(next < grown ? grown : next) << 2;
            const w3d_u32 storage = A80212fd4(bytes);
            if (bits->begin) {
                memcpy(g2h(storage), bits->begin.get(), used < bytes ? used : bytes);
                A802134fc(bits->begin.get());
            }
            bits->begin.v = storage;
            bits->end.v = storage + used;
            bits->capacity.v = storage + bytes;
        }
        *bits->end = 0;
        bits->end.v += 4;
    }
    const w3d_u32 cell = bits->count++;
    bits->begin[cell >> 5] |= 1u << (cell & 31);
    return cell;
}
}

extern "C" w3d_u32 A80172be4(Ptr32<Sprite> self, Ptr32<void> texture, w3d_u32 key) {
    A80185af0(self.get(), texture.v, key);
    if (texture) call_virtual(texture.get(), kAddRef);
    if (self->texture) call_virtual(self->texture.get(), kRelease);
    self->texture = texture;

    TextureInfo *info = (TextureInfo *)texture.get();
    SpriteGeometry *geometry = at<SpriteGroup>(A80172050(info, key))->geometry;
    BitSet *bits = at<BitSet>(A801720c0(info, key));

    // Si no hay celda libre, los arrays principales crecen en una.
    int cell = find_free_cell(bits);
    const bool reused = cell >= 0;
    int extra;
    if (reused) {
        bits->begin[(w3d_u32)cell >> 5] |= 1u << (cell & 31);
        extra = 0;
    } else {
        cell = append_cell(bits);
        extra = 1;
    }
    uint8_t *rotation = (uint8_t *)lock_array(geometry->rotation, geometry->rotation->count + extra, 1);
    Vec3 *positions = (Vec3 *)lock_array(geometry->positions, geometry->positions->count + extra, 12);
    const int weights_count = geometry->weights->count;
    float *weights = (float *)lock_array(geometry->weights, weights_count, 4);
    uint8_t *visibility = (uint8_t *)lock_array(geometry->visibility, geometry->visibility->count + extra, 1);
    const int colors_count = geometry->colors->count;
    Rgba *colors = (Rgba *)lock_array(geometry->colors, colors_count, 4);
    Vec2 *uvs = (Vec2 *)lock_array(geometry->uvs, geometry->uvs->count + extra, 8);
    geometry->flags &= ~4u;
    if (weights_count != 0) {
        if (extra) weights = (float *)lock_array(geometry->weights, geometry->weights->count + 1, 4);
        weights[cell] = 0.0f;
    }
    if (colors_count != 0) {
        if (extra) colors = (Rgba *)lock_array(geometry->colors, geometry->colors->count + 1, 4);
        colors[cell] = {0xff, 0xff, 0xff, 0xff};
    }
    rotation[cell] = 0;
    positions[cell] = {0.0f, 0.0f, 0.0f};
    visibility[cell] = 1;
    uvs[cell].x = (float)(int)info->width * 0.5f;
    uvs[cell].y = (float)(int)info->height * 0.5f;
    geometry->flags &= ~4u;

    self->size = uvs[cell];
    self->depth = 0.0f;
    self->position = {0.0f, 0.0f, 0.0f};
    self->rotation = {0.0f, 0.0f, 0.0f};
    // El original lee la mitad baja del índice, que en PPC está en +2 y aquí en +0.
    self->slot = (uint16_t)cell;
    self->flags |= 1;

    Ptr32<void> group(A80172050(info, key));
    if (group) call_virtual(group.get(), kAddRef);
    if (self->group) call_virtual(self->group.get(), kRelease);
    self->group = group;
    self->color = {0xff, 0xff, 0xff, 0xff};
    self->pad2 = 0;
    self->hidden = 0;
    return 0;
}
