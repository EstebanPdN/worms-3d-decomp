// Colisión de una trayectoria parabólica contra la malla de colisión del terreno (0x800b53d8). La trayectoria se pasa al espacio
// del terreno, se recorta contra su caja (raíces de una cuadrática por cada plano) y se muestrea a pasos de medio voxel. Si un
// punto cae dentro de algo sólido, cinco bisecciones afinan el instante, y el resultado queda en los globales de impacto.
//
// v34: el barrido tiene dos caminos con los mismos resultados bit a bit. sweep_reference es el de siempre (llama a la prueba
// de punto 0x800b4da0 y a las raíces 0x8009ee18 del juego) y sweep_fast el que se usa: lleva en línea la prueba de punto,
// grid_test (0x8002c73c) y las raíces, con las mismas operaciones de coma flotante en el mismo orden; ordena los cruces por
// inserción; reutiliza las rotaciones entre trozos con la misma matriz, y en los trozos sin bordes deformados se ahorra las
// divisiones de cada muestra. W3D_COL_CHECK=1 hace los dos caminos en cada llamada y compara todo lo que escriben (col_check).
#include "native_common.h"
#include <stdlib.h>

namespace {
struct Vec3 { float x, y, z; };
struct LandGrid {
    char pad[0xc0];
    float axis[3][3];           // +0xc0: filas de la rotación mundo -> terreno
    Vec3 translation;           // +0xe4
    char pad2[0x120 - 0xf0];
    Vec3 offset;                // +0x120
    char pad3[0x15c - 0x12c];
    Vec3 box_min;               // +0x15c
    Vec3 box_max;               // +0x168
    char pad4[0x18c - 0x174];
    w3d_u32 materials;          // +0x18c
    w3d_u32 heights;            // +0x190
    char pad5[0x1a4 - 0x194];
    float cell_size;            // +0x1a4
    char pad6[0x1ac - 0x1a8];
    w3d_u32 columns;            // +0x1ac
    char pad7[0x1b8 - 0x1b0];
    w3d_u32 layer_table;        // +0x1b8
    char pad8[0x1c0 - 0x1bc];
    uint8_t layer_shift;        // +0x1c0
    char pad9[3];
    uint8_t column_shift_x;     // +0x1c4
    uint8_t column_shift_z;     // +0x1c5
    char pad10[3];
    int8_t scale_z, scale_y, scale_x;  // +0x1c9, +0x1ca, +0x1cb
    Ptr32<char> tiles;          // +0x1cc
};
struct LandObject {
    w3d_u32 table;
    Ptr32<LandGrid> grid;   // +4
    char pad[4];
    w3d_u32 id;             // +0xc
};
// Globales fijos de la consulta en curso.
struct GridAccess {
    w3d_u32 heights;   // 0x804ae4b8
    w3d_u32 materials; // 0x804ae4bc
    w3d_u32 columns;   // 0x804ae4c0
    w3d_u32 relief_row;                 // 0x804ae4c4: esquina del relieve de la última prueba de punto
    int8_t scale_x, scale_y, scale_z;   // 0x804ae4c8
    uint8_t hit_material[3];            // 0x804ae4cb: el último punto probado
    uint8_t shift_z, shift_x;           // 0x804ae4ce
    float scale[3];                     // 0x804ae4d0
};
struct TileAccess {
    w3d_u32 layer_table;   // 0x804ae4e8
    w3d_u32 tile_count;    // 0x804ae4ec
    w3d_u32 tiles;         // 0x804ae4f0
    uint8_t layer_shift;   // 0x804ae4f4
};
struct SweepHit {
    Vec3 inside;       // 0x8043ae08: último punto libre
    Vec3 solid;        // 0x8043ae14: primer punto sólido
    Vec3 position;     // 0x8043ae20
    Vec3 velocity;     // 0x8043ae2c
};
struct Motion { Vec3 start, velocity, half_accel; };
inline Vec3 at_time(const Motion &m, float t) {
    const float t2 = t * t;
    return {fused_madd(m.half_accel.x, t2, fused_madd(m.velocity.x, t, m.start.x)),
            fused_madd(m.half_accel.y, t2, fused_madd(m.velocity.y, t, m.start.y)),
            fused_madd(m.half_accel.z, t2, fused_madd(m.velocity.z, t, m.start.z))};
}
inline float rotate(const float axis[3][3], const Vec3 &v, int component) {
    return fused_madd(v.z, axis[2][component], fused_madd(v.x, axis[0][component], v.y * axis[1][component]));
}
inline Vec3 rotate(const float axis[3][3], const Vec3 &v) {
    return {rotate(axis, v, 0), rotate(axis, v, 1), rotate(axis, v, 2)};
}
inline Vec3 translated(const Vec3 &v, const Vec3 &by) { return {v.x + by.x, v.y + by.y, v.z + by.z}; }
// Como psq_st con GQR s8: satura y trunca, NaN da 0.
inline int8_t to_s8(float value) {
    if (value != value) return 0;
    if (value <= -128) return -128;
    if (value >= 127) return 127;
    return (int8_t)value;
}

// v34: lo que lee la prueba de punto de los globales de la consulta, tomado una vez por barrido. Nada lo cambia mientras se
// muestrea: A800b53d8 lo escribe antes y la prueba solo escribe sus temporales.
struct EdgePair { float x, z; };    // desplazamiento de un borde de la capa en x y en z (Pair{lo, hi} en la unidad del juego)
struct VoxelLevels { w3d_u32 offsets[5], widths[5], heights[5]; };   // cabecera de la rejilla jerárquica de grid_test
struct PointTest {
    const EdgePair *low_edge, *high_edge;   // 0x804ae4b8, 0x804ae4bc
    const float *relief;                    // 0x804ae4c0
    int layers, row;                        // 0x804ae4c9 y 0x804ae4ce, con signo como los lee la prueba
    float columns_x, columns_z;             // 0x804ae4d0 y 0x804ae4d8
    const VoxelLevels *voxels;              // 0x804ae4e8
    const uint8_t *corners;                 // 0x804ae4f0
    const uint8_t *blend_map;               // 0x804b1800
    bool blend;                             // +0x1c0 del terreno
    bool flat_x, flat_z;                    // bordes a +0 en x / en z (flat_edges)
};
struct RootConstants { float tolerance, zero, invalid, four; };   // las de 0x8009ee18, leídas de la imagen
}
extern "C" {
extern Vec3 A8043add8, A8043ade4, A8043adf0;      // Inicio, velocidad y aceleración de la consulta.
extern SweepHit A8043ae08;
extern GridAccess A804ae4b8;
extern TileAccess A804ae4e8;
extern float A8043b2fc[14];       // Instantes de cruce de los planos de la caja, ordenados.
extern uint8_t A8043b334[13];     // Bits de la máscara que cambian en cada cruce.
extern const uint8_t A803f4c58[13];
extern w3d_u32 A804b1764, A804b17a8, A804b17ac, A804b1810, A804b1814, A804b1820;
extern float A804b1818, A804b1824;
extern const float A803824ac, A803824b8, A803824bc, A803824c4, A803824d0, A80382450, A80382454, A80382460;
// v34: temporales de la prueba de punto (0x800b4da0) y de grid_test (0x8002c73c), que el camino en línea escribe igual.
extern float A804ae4b0, A804ae4b4, A804ae4dc, A804ae4e0, A804ae4e4, A804ae4fc, A804ae500, A804ae504, A804ae508, A804ae50c;
extern int A804ae4f8;
extern w3d_u32 A804accc0, A804accc4, A804accc8, A804acccc;
extern w3d_u32 A804b1800;                                   // tabla de mezcla de materiales de las esquinas
extern const w3d_u32 A80372724[5];                          // máscara de capa por nivel de grid_test
extern const float A8038252c[], A8038258c[], A8038264c[];   // alturas de esquina de la mezcla
extern const float A803806a4, A803806a8, A803806ac, A803806b0;
float A8009ee18(float *second_root, float c, float b, float a);
int A800b4da0(Ptr32<LandObject> land, Ptr32<Vec3> point);
int A800b5fc0(Ptr32<LandObject> land, Ptr32<Vec3> direction);
int A8002c73c(void *layers, int x, int y, int z, int shift);
float A802e82c0(float value);
void w3d_dbg(const char *, ...);
}

// El barrido de siempre. v34: es el camino original, que se conserva tal cual para W3D_COL_CHECK y para las entradas no
// finitas (ver sweep_fast).
static w3d_u32 sweep_reference(Ptr32<LandObject> self) {
    const LandGrid *grid = self->grid;
    const Vec3 world_start = A8043add8, world_velocity = A8043ade4, world_accel = A8043adf0;
    const float half = A803824ac;
    float step = grid->cell_size * half;
    const float frame_time = A804b1818;
    const w3d_u32 only_first_contact = A804b1820;
    float end_time = (float)A804b1814 * frame_time;

    Motion local;
    local.start = translated(translated(rotate(grid->axis, world_start), grid->translation), grid->offset);
    local.velocity = rotate(grid->axis, world_velocity);
    local.half_accel = rotate(grid->axis, world_accel);
    local.half_accel.x *= half;
    local.half_accel.y *= half;
    local.half_accel.z *= half;

    A804ae4b8.heights = grid->heights + 0x20;
    A804ae4b8.materials = grid->materials + 0x20;
    A804ae4b8.scale_x = grid->scale_x;
    A804ae4b8.scale[0] = (float)(int)grid->scale_x;
    A804ae4b8.scale_y = grid->scale_y;
    A804ae4b8.scale[1] = (float)(int)grid->scale_y;
    A804ae4b8.scale_z = grid->scale_z;
    A804ae4b8.scale[2] = (float)(int)grid->scale_z;
    A804ae4b8.columns = grid->columns + 0x20;
    A804ae4b8.shift_z = grid->column_shift_z;
    A804ae4b8.shift_x = grid->column_shift_x;

    // Máscara de los planos de la caja por los que estamos fuera. 0x3f: dentro de todos, se puede muestrear.
    uint8_t outside = 0;
    const float long_step = end_time * A803824b8;
    if (step > long_step) {
        // Paso mayor que la trayectoria: sin recortar.
        A8043b2fc[0] = end_time;
        A8043b2fc[1] = end_time + end_time;
        step = long_step;
        outside = 0x3f;
    } else {
        memcpy(A8043b334, A803f4c58, 13);
        if (local.start.x >= grid->box_max.x) outside |= 0x01;
        if (local.start.y >= grid->box_max.y) outside |= 0x20;
        if (local.start.z >= grid->box_max.z) outside |= 0x04;
        if (local.start.x <= grid->box_min.x) outside |= 0x02;
        if (local.start.y <= grid->box_min.y) outside |= 0x10;
        if (local.start.z <= grid->box_min.z) outside |= 0x08;
        A8043b2fc[0] = A8009ee18(&A8043b2fc[1], local.start.x - grid->box_max.x, local.velocity.x, local.half_accel.x);
        A8043b2fc[2] = A8009ee18(&A8043b2fc[3], local.start.y - grid->box_max.y, local.velocity.y, local.half_accel.y);
        A8043b2fc[4] = A8009ee18(&A8043b2fc[5], local.start.z - grid->box_max.z, local.velocity.z, local.half_accel.z);
        A8043b2fc[6] = A8009ee18(&A8043b2fc[7], local.start.x - grid->box_min.x, local.velocity.x, local.half_accel.x);
        A8043b2fc[8] = A8009ee18(&A8043b2fc[9], local.start.y - grid->box_min.y, local.velocity.y, local.half_accel.y);
        A8043b2fc[10] = A8009ee18(&A8043b2fc[11], local.start.z - grid->box_min.z, local.velocity.z, local.half_accel.z);
        A8043b2fc[12] = end_time;
        // Ordena los cruces con sus máscaras.
        bool sorted;
        do {
            sorted = true;
            for (int i = 0; i < 12; i++) {
                if (A8043b2fc[i] > A8043b2fc[i + 1]) {
                    const float t = A8043b2fc[i];
                    A8043b2fc[i] = A8043b2fc[i + 1];
                    A8043b2fc[i + 1] = t;
                    const uint8_t m = A8043b334[i];
                    A8043b334[i] = A8043b334[i + 1];
                    A8043b334[i + 1] = m;
                    sorted = false;
                }
            }
        } while (!sorted);
    }

    // Empieza por el primer cruce en el futuro.
    int crossing = 0;
    while (A8043b2fc[crossing] <= 0.0f) crossing++;
    A804ae4e8.layer_table = grid->layer_table + 0x20;
    A804ae4e8.tile_count = *(const w3d_u32 *)(grid->tiles.get() + 0x18);
    A804ae4e8.tiles = grid->tiles.v + 0x20;
    A804ae4e8.layer_shift = grid->layer_shift;

    float time = 0.0f;
    if (!(time < end_time)) return 0;
    do {
        if (outside == 0x3f) {
            time -= step * A803824bc;
            if (time < 0.0f) time = 0.0f;
            float free_time = time;
            bool last_sample = false;
            while (time <= A8043b2fc[crossing] || last_sample) {
                Vec3 sample = at_time(local, time);
                if (!A800b4da0(self, Ptr32<Vec3>(&sample))) {
                    free_time = time;
                    time += step;
                    if (time >= end_time) {
                        if (last_sample) {
                            last_sample = false;
                        } else {
                            time = end_time;
                            last_sample = true;
                        }
                    }
                    continue;
                }
                Vec3 solid = sample;
                Vec3 inside;
                if (time > 0.0f && only_first_contact != 0) {
                    float low = time - step, high = time;
                    free_time = low;
                    inside = at_time(local, low);
                    A800b4da0(self, Ptr32<Vec3>(&inside));
                    for (int i = 0; i < 5; i++) {
                        const float middle = (free_time + high) * half;
                        sample = at_time(local, middle);
                        if (A800b4da0(self, Ptr32<Vec3>(&sample))) {
                            solid = sample;
                            high = middle;
                        } else {
                            inside = sample;
                            free_time = middle;
                        }
                    }
                } else {
                    inside = sample;
                    A804b1810 = 1;
                }
                if (free_time < 0.0f) free_time = 0.0f;

                const float frames = free_time / frame_time;
                const w3d_u32 frame = (w3d_u32)ppc_ftoi(frames);
                if (A804b1764 > frame) {
                    const float half_t2 = (free_time * free_time) * half;
                    Vec3 travel = {world_velocity.x * free_time, world_velocity.y * free_time, world_velocity.z * free_time};
                    Vec3 falling = {world_accel.x * half_t2, world_accel.y * half_t2, world_accel.z * half_t2};
                    A804b1824 = frames;
                    A804b1814 = frame;
                    A804b1764 = frame;
                    A8043ae08.solid = solid;
                    A8043ae08.position = {(world_start.x + travel.x) + falling.x, (world_start.y + travel.y) + falling.y, (world_start.z + travel.z) + falling.z};
                    A8043ae08.inside = inside;
                    A804b17ac = self->id;
                    A8043ae08.velocity = {world_velocity.x + world_accel.x * free_time, world_velocity.y + world_accel.y * free_time, world_velocity.z + world_accel.z * free_time};
                    A804b17a8 = A804ae4b8.hit_material[0] | (w3d_u32)A804ae4b8.hit_material[1] << 8 | (w3d_u32)A804ae4b8.hit_material[2] << 16;
                }
                return 1;
            }
        }
        // Siguiente tramo: aplica la máscara de este cruce y de los que coincidan con él.
        do {
            time = A8043b2fc[crossing];
            outside ^= A8043b334[crossing];
            crossing++;
        } while (time >= A8043b2fc[crossing] && crossing != 13);
    } while (time < end_time);
    return 0;
}

// ---- v34: camino rápido del barrido ----

static inline w3d_u32 float_bits(float value) { w3d_u32 bits; memcpy(&bits, &value, 4); return bits; }
static inline bool is_finite(float value) { return (float_bits(value) & 0x7f800000u) != 0x7f800000u; }
// Cero o normal: x - 0 y x / 1 lo devuelven tal cual. Un subnormal no siempre (la VFP de la 3DS puede vaciarlo a cero en la
// resta), y tampoco infinito ni NaN.
static inline bool is_normal_or_zero(float value) {
    const w3d_u32 bits = float_bits(value), exponent = bits & 0x7f800000u;
    return (exponent != 0 && exponent != 0x7f800000u) || (bits << 1) == 0;
}

// v34: grid_test (0x8002c73c) con nivel 4, en línea: las mismas lecturas, el mismo resultado. Sus cuatro temporales
// (0x804accc0-0x804acccc) solo los lee la propia función y cada nivel pisa los del anterior: se escriben una vez, al salir,
// con los valores del último nivel, que son los que deja el original. Se ahorra la llamada y las lecturas volátiles de Ptr32.
static inline int voxel_test(const VoxelLevels *grid, w3d_u32 x, w3d_u32 bit, w3d_u32 z) {
    if (x >= grid->widths[0] || z >= grid->heights[0]) return 0;
    const w3d_u32 *words = (const w3d_u32 *)grid;
    w3d_u32 level = 4, xx, zz, shift, word;
    do {
        zz = z >> level;
        xx = x >> level;
        shift = bit & A80372724[level];
        word = words[grid->offsets[level] + xx + zz * grid->widths[level]] >> shift;
        // Bit 1: lleno, se acaba en 1. Bit 0 a cero: vacío, se acaba en 0. Si no, se baja de nivel.
        if ((word & 2) || !(word & 1)) {
            A804accc0 = xx;
            A804accc4 = zz;
            A804accc8 = shift;
            A804acccc = word;
            return (word & 2) != 0;
        }
    } while (--level);
    word = words[grid->offsets[0] + x + z * grid->widths[0]];
    A804accc0 = xx;
    A804accc4 = zz;
    A804accc8 = shift;
    A804acccc = word;
    return (word & (1u << bit)) != 0;
}

// v34: la prueba de punto del juego (0x800b4da0, d40h_land_point_test) en línea: las mismas operaciones, en el mismo orden y
// sin fusionar (la unidad del juego se compila sin fma), los mismos cambios en p y las mismas escrituras en sus temporales
// (0x804ae4c4, 0x804ae4dc-0x804ae4e4, 0x804ae4f8-0x804ae50c, 0x804ae4b0/b4 y el vóxel del impacto en 0x804ae4cb). Se ahorra la
// llamada, la recarga de los globales de la consulta en cada muestra (con Ptr32 son lecturas volátiles) y la de grid_test.
// Atajo exacto: si los cuatro bordes que usa la muestra son +0, lo = hi = 0·fy + 0·inv = +0 para todo y finito (fy e inv son
// finitos y no pueden ser negativos a la vez), y x' = (x - 0) / (0 / sx + 1) = x / 1 = x si x es normal o cero: esa
// coordenada queda tal cual, sin sus dos divisiones (la VFP11 no las segmenta, 15 ciclos cada una).
static inline int point_test(const PointTest &k, Vec3 &p) {
    const float y = p.y;
    float x = p.x, z = p.z;
    bool keep_x = false, keep_z = false;
    if (k.flat_x || k.flat_z) {
        const bool y_finite = is_finite(y);
        keep_x = k.flat_x && y_finite && is_normal_or_zero(x);
        keep_z = k.flat_z && y_finite && is_normal_or_zero(z);
    }
    if (!keep_x || !keep_z) {
        // Fila de la capa por la altura y bordes interpolados entre esa capa y la siguiente.
        int iy = (int)y;
        if (iy < 0) iy = 0;
        const int top = k.layers - 1;
        if (iy > top) iy = top;
        const float fy = y - (float)iy;
        const float inv = 1.0f - fy;
        const EdgePair *low = k.low_edge + iy, *high = k.high_edge + iy;
        if (!keep_x) {
            const float lo = low[1].x * fy + low[0].x * inv;
            const float hi = high[1].x * fy + high[0].x * inv;
            x = (x - lo) / ((hi - lo) / k.columns_x + 1.0f);
        }
        if (!keep_z) {
            const float lo = low[1].z * fy + low[0].z * inv;
            const float hi = high[1].z * fy + high[0].z * inv;
            z = (z - lo) / ((hi - lo) / k.columns_z + 1.0f);
        }
    }
    p.x = x;
    p.z = z;
    const signed char ix = (signed char)x, iz = (signed char)z;
    if (!(x >= 0.0f && z >= 0.0f && x < k.columns_x && z < k.columns_z)) return 0;
    // La altura resta el relieve bilineal de la columna.
    const int row = k.row;
    const float fx = x - (float)ix, fz = z - (float)iz;
    A804ae4dc = fx;
    A804ae4e4 = fz;
    const float *corner = k.relief + ix + iz * row;
    A804ae4b8.relief_row = h2g(corner);
    const float ifx = 1.0f - fx, ifz = 1.0f - fz;
    const float cy = y - ((corner[0] * ifx + corner[1] * fx) * ifz + (corner[row] * ifx + corner[row + 1] * fx) * fz);
    p.y = cy;
    const int iv = (int)cy;
    const float frac = cy - (float)iv;
    A804ae4e0 = frac;
    if (!(cy >= 0.0f && iv < k.layers)) return 0;
    const signed char iv8 = (signed char)iv;
    if (!voxel_test(k.voxels, (w3d_u32)(int)ix, (w3d_u32)(int)iv8, (w3d_u32)(int)iz)) return 0;

    // Vóxel ocupado: materiales de las cuatro esquinas de la celda, por el triángulo en el que cae el punto.
    const int layers = k.layers;
    A804ae4f8 = 0;
    const int stride = layers + 1;
    const int i0 = iv8 + (ix + iz * row) * stride + 1;
    const int i1 = i0 + 1 + layers;
    const int i2 = i1 + row * stride;
    const int i3 = i2 - 1 - layers;
    const uint8_t *tile = k.corners;
    unsigned c0, c1, c2, c3;
    const float sum = fx + fz;
    if (sum < 0.5f) {
        c0 = tile[i0];
        if (!(c0 & 0xee)) { A804ae4f8 = 1; return 0; }
        c1 = tile[i1]; c3 = tile[i3]; c2 = tile[i2];
    } else if (fx - fz > 0.5f) {
        c1 = tile[i1];
        if (!(c1 & 0xdd)) { A804ae4f8 = 1; return 0; }
        c0 = tile[i0]; c3 = tile[i3]; c2 = tile[i2];
    } else if (fz - fx > 0.5f) {
        c3 = tile[i3];
        if (!(c3 & 0xbb)) { A804ae4f8 = 1; return 0; }
        c0 = tile[i0]; c1 = tile[i1]; c2 = tile[i2];
    } else if (sum > 1.5f) {
        c2 = tile[i2];
        if (!(c2 & 0x77)) { A804ae4f8 = 1; return 0; }
        c0 = tile[i0]; c1 = tile[i1]; c3 = tile[i3];
    } else {
        c0 = tile[i0]; c1 = tile[i1]; c3 = tile[i3]; c2 = tile[i2];
    }
    if (k.blend) {
        // Mezcla: altura del cuarto de celda por sus esquinas y comparación con la fracción de altura del punto.
        const uint8_t *map = k.blend_map;
        c0 = map[c0]; c1 = map[c1]; c3 = map[c3]; c2 = map[c2];
        float base, along_x, along_z, across, origin_x, origin_z;
        if (fx < 0.5f) {
            if (fz < 0.5f) {
                base = A8038252c[c0]; along_x = A8038258c[c0 + c1]; along_z = A8038258c[c0 + c3]; across = A8038264c[(c0 + c1 + c3 + c2) >> 1];
                origin_x = 0.0f; origin_z = 0.0f;
            } else {
                base = A8038258c[c0 + c3]; along_x = A8038264c[(c0 + c1 + c3 + c2) >> 1]; along_z = A8038252c[c3]; across = A8038258c[c3 + c2];
                origin_x = 0.0f; origin_z = 0.5f;
            }
        } else if (fz < 0.5f) {
            base = A8038258c[c0 + c1]; along_x = A8038252c[c1]; along_z = A8038264c[(c0 + c1 + c3 + c2) >> 1]; across = A8038258c[c1 + c2];
            origin_x = 0.5f; origin_z = 0.0f;
        } else {
            base = A8038264c[(c0 + c1 + c3 + c2) >> 1]; along_x = A8038258c[c1 + c2]; along_z = A8038258c[c3 + c2]; across = A8038252c[c2];
            origin_x = 0.5f; origin_z = 0.5f;
        }
        const float a = base;
        const float dx = along_x - a, dz = along_z - a;
        const float d = across - (dx + dz + a);
        const float u = (fx - origin_x) + (fx - origin_x);
        const float t2 = (fz - origin_z) + (fz - origin_z);
        const float val = u * t2 * d + (t2 * dz + (u * dx + a));
        A804ae4fc = a;
        A804ae500 = dx;
        A804ae504 = dz;
        A804ae508 = d;
        A804ae50c = val;
        A804ae4b0 = origin_x;
        A804ae4b4 = origin_z;
        if (frac > val) return 0;
    }
    A804ae4b8.hit_material[0] = (uint8_t)ix;
    A804ae4b8.hit_material[1] = (uint8_t)iv8;
    A804ae4b8.hit_material[2] = (uint8_t)iz;
    return 1;
}

// v34: la misma prueba fuera de línea, para la bisección (seis pruebas por impacto): así solo el bucle de muestras lleva una
// copia en línea y el barrido no triplica su código en la caché de instrucciones (16 KB en el ARM11).
static __attribute__((noinline)) int point_test_call(const PointTest &k, Vec3 &p) { return point_test(k, p); }

// v34: ¿bordes de capa a +0? Se mira una vez por barrido, antes de la primera muestra, sobre las capas 0..layers de los dos
// bordes, que son todas las que la prueba puede leer (iy + 1 con iy <= layers - 1). Con sx = 0, 0 / sx da NaN y el atajo no
// valdría: entonces tampoco se usa.
static void flat_edges(PointTest &k) {
    k.flat_x = k.flat_z = false;
    if (k.layers < 1) return;
    w3d_u32 any_x = 0, any_z = 0;
    for (int i = 0; i <= k.layers && !(any_x && any_z); i++) {
        any_x |= float_bits(k.low_edge[i].x) | float_bits(k.high_edge[i].x);
        any_z |= float_bits(k.low_edge[i].z) | float_bits(k.high_edge[i].z);
    }
    k.flat_x = any_x == 0 && k.columns_x != 0.0f;
    k.flat_z = any_z == 0 && k.columns_z != 0.0f;
}

// v34: las raíces de 0x8009ee18 en línea, con sus operaciones en el mismo orden (b·b - (a·4)·c sin fusionar, la raíz con la
// misma función 0x802e82c0). Se ahorran seis llamadas por barrido; el compilador comparte b·b, a·4 y a + a entre los dos
// planos de cada eje, que dan el mismo valor.
static inline float crossing_roots(float *second, float constant, float linear, float quadratic, const RootConstants &k) {
    if (__builtin_fabsf(quadratic) < k.tolerance) {
        if (linear != k.zero) {
            *second = k.invalid;
            return -constant / linear;
        }
    } else {
        const float disc = linear * linear - (quadratic * k.four) * constant;
        if (!(disc < k.zero)) {
            const float root = A802e82c0(disc);
            const float twice = quadratic + quadratic;
            *second = (-linear + root) / twice;
            return (-linear - root) / twice;
        }
    }
    *second = k.invalid;
    return k.invalid;
}

// v34: ordena los cruces por inserción sobre copias locales y los globales se escriben al final. La burbuja del original solo
// cambia dos vecinos si el primero es estrictamente mayor: es estable, como la inserción. Sin NaN, «>» es un orden débil
// estricto (también si la VFP vacía los subnormales a cero, que entonces valen 0 para las dos) y la ordenación estable es
// única: mismos valores y mismas máscaras en las mismas posiciones. La burbuja hace hasta 12 pasadas de 12 comparaciones
// sobre memoria global; la inserción, unas 50 en registros y pila. Con algún NaN el barrido entero va por el original.
static inline void sort_crossings(float *times, uint8_t *flips, int count) {
    for (int i = 1; i < count; i++) {
        const float time = times[i];
        const uint8_t flip = flips[i];
        int j = i;
        for (; j > 0 && times[j - 1] > time; j--) {
            times[j] = times[j - 1];
            flips[j] = flips[j - 1];
        }
        times[j] = time;
        flips[j] = flip;
    }
}

// v34: las tres rotaciones al espacio del terreno dependen solo de la matriz (+0xc0) y de los tres vectores de la consulta.
// Los trozos de una isla suelen compartir la matriz, así que en una consulta los barridos que siguen al primero repetían las
// mismas 18 fma y 9 productos: se guardan las 18 palabras de entrada y, si coinciden bit a bit, se reutiliza el resultado.
// No hace falta invalidarlo: la clave es la entrada entera.
namespace {
struct RotatedQuery { w3d_u32 key[18]; Vec3 start, velocity, accel; bool valid; };
RotatedQuery g_rotated;
}
static inline void rotate_query(const float axis[3][3], const Vec3 &start, const Vec3 &velocity, const Vec3 &accel,
                                Vec3 &out_start, Vec3 &out_velocity, Vec3 &out_accel) {
    w3d_u32 key[18];
    memcpy(key, axis, 36);
    memcpy(key + 9, &start, 12);
    memcpy(key + 12, &velocity, 12);
    memcpy(key + 15, &accel, 12);
    bool same = g_rotated.valid;
    for (int i = 0; same && i < 18; i++) same = key[i] == g_rotated.key[i];
    if (!same) {
        g_rotated.start = rotate(axis, start);
        g_rotated.velocity = rotate(axis, velocity);
        g_rotated.accel = rotate(axis, accel);
        memcpy(g_rotated.key, key, sizeof key);
        g_rotated.valid = true;
    }
    out_start = g_rotated.start;
    out_velocity = g_rotated.velocity;
    out_accel = g_rotated.accel;
}

// v34: el camino rápido solo con entradas finitas. Con un NaN o un infinito en la trayectoria local, el paso o el final, los
// NaN que salgan pueden llevar cargas distintas según el orden de operandos que elija el compilador: ese caso, que en una
// partida no se da, va entero por el camino original. Con entradas finitas todo NaN que aparezca es el NaN por defecto.
static unsigned g_sweep_fallbacks;   // barridos que siguieron por el camino original (se cuentan en W3D_COL_CHECK)
static inline bool finite_query(const Motion &m, float step, float end_time) {
    const float values[11] = {m.start.x, m.start.y, m.start.z, m.velocity.x, m.velocity.y, m.velocity.z,
                              m.half_accel.x, m.half_accel.y, m.half_accel.z, step, end_time};
    for (float value : values)
        if (!is_finite(value)) return false;
    return true;
}

// v34: el barrido con todo lo anterior. La estructura (tramos, muestras, bisección y registro del impacto) es la de
// sweep_reference línea a línea; cambian la prueba de punto, las raíces, la ordenación y de dónde se leen los cruces (copias
// locales de A8043b2fc/A8043b334, que tienen los mismos valores y nadie cambia durante el barrido).
static w3d_u32 sweep_fast(Ptr32<LandObject> self) {
    const LandGrid *grid = self->grid;
    const Vec3 world_start = A8043add8, world_velocity = A8043ade4, world_accel = A8043adf0;
    const float half = A803824ac;
    float step = grid->cell_size * half;
    const float frame_time = A804b1818;
    const w3d_u32 only_first_contact = A804b1820;
    const float end_time = (float)A804b1814 * frame_time;

    Motion local;
    Vec3 start, velocity, accel;
    rotate_query(grid->axis, world_start, world_velocity, world_accel, start, velocity, accel);
    local.start = translated(translated(start, grid->translation), grid->offset);
    local.velocity = velocity;
    local.half_accel = accel;
    local.half_accel.x *= half;
    local.half_accel.y *= half;
    local.half_accel.z *= half;

    A804ae4b8.heights = grid->heights + 0x20;
    A804ae4b8.materials = grid->materials + 0x20;
    A804ae4b8.scale_x = grid->scale_x;
    A804ae4b8.scale[0] = (float)(int)grid->scale_x;
    A804ae4b8.scale_y = grid->scale_y;
    A804ae4b8.scale[1] = (float)(int)grid->scale_y;
    A804ae4b8.scale_z = grid->scale_z;
    A804ae4b8.scale[2] = (float)(int)grid->scale_z;
    A804ae4b8.columns = grid->columns + 0x20;
    A804ae4b8.shift_z = grid->column_shift_z;
    A804ae4b8.shift_x = grid->column_shift_x;
    // Lo escrito hasta aquí es lo mismo que escribe el original, así que puede seguir él desde el principio.
    if (!finite_query(local, step, end_time)) {
        g_sweep_fallbacks++;
        return sweep_reference(self);
    }

    uint8_t outside = 0;
    const float long_step = end_time * A803824b8;
    float times[13];
    uint8_t flips[13];
    if (step > long_step) {
        // Sin recortar: dos cruces, y el tramo solo lee la máscara del primero (la que dejó el barrido anterior, como antes).
        times[0] = end_time;
        times[1] = end_time + end_time;
        A8043b2fc[0] = times[0];
        A8043b2fc[1] = times[1];
        flips[0] = A8043b334[0];
        step = long_step;
        outside = 0x3f;
    } else {
        memcpy(flips, A803f4c58, 13);
        if (local.start.x >= grid->box_max.x) outside |= 0x01;
        if (local.start.y >= grid->box_max.y) outside |= 0x20;
        if (local.start.z >= grid->box_max.z) outside |= 0x04;
        if (local.start.x <= grid->box_min.x) outside |= 0x02;
        if (local.start.y <= grid->box_min.y) outside |= 0x10;
        if (local.start.z <= grid->box_min.z) outside |= 0x08;
        const RootConstants roots = {A803806a4, A803806a8, A803806ac, A803806b0};
        times[0] = crossing_roots(&times[1], local.start.x - grid->box_max.x, local.velocity.x, local.half_accel.x, roots);
        times[2] = crossing_roots(&times[3], local.start.y - grid->box_max.y, local.velocity.y, local.half_accel.y, roots);
        times[4] = crossing_roots(&times[5], local.start.z - grid->box_max.z, local.velocity.z, local.half_accel.z, roots);
        times[6] = crossing_roots(&times[7], local.start.x - grid->box_min.x, local.velocity.x, local.half_accel.x, roots);
        times[8] = crossing_roots(&times[9], local.start.y - grid->box_min.y, local.velocity.y, local.half_accel.y, roots);
        times[10] = crossing_roots(&times[11], local.start.z - grid->box_min.z, local.velocity.z, local.half_accel.z, roots);
        times[12] = end_time;
        for (int i = 0; i < 13; i++)
            if (times[i] != times[i]) {
                g_sweep_fallbacks++;
                return sweep_reference(self);
            }
        sort_crossings(times, flips, 13);
        memcpy(A8043b2fc, times, sizeof times);
        memcpy(A8043b334, flips, sizeof flips);
    }

    A804ae4e8.layer_table = grid->layer_table + 0x20;
    A804ae4e8.tile_count = *(const w3d_u32 *)(grid->tiles.get() + 0x18);
    A804ae4e8.tiles = grid->tiles.v + 0x20;
    A804ae4e8.layer_shift = grid->layer_shift;
    // El original busca aquí el primer cruce en el futuro y luego sale si el final no es positivo; esa búsqueda no escribe
    // nada, y con el final positivo (que está entre los cruces) siempre acaba dentro de las 13 entradas.
    float time = 0.0f;
    if (!(time < end_time)) return 0;
    int crossing = 0;
    while (times[crossing] <= 0.0f) crossing++;

    PointTest k;
    k.low_edge = at<const EdgePair>(A804ae4b8.heights);
    k.high_edge = at<const EdgePair>(A804ae4b8.materials);
    k.relief = at<const float>(A804ae4b8.columns);
    k.layers = A804ae4b8.scale_y;
    k.row = (int8_t)A804ae4b8.shift_z;
    k.columns_x = A804ae4b8.scale[0];
    k.columns_z = A804ae4b8.scale[2];
    k.voxels = at<const VoxelLevels>(A804ae4e8.layer_table);
    k.corners = at<const uint8_t>(A804ae4e8.tiles);
    k.blend_map = at<const uint8_t>(A804b1800);
    k.blend = grid->layer_shift != 0;
    k.flat_x = k.flat_z = false;
    bool edges_known = false;

    do {
        if (outside == 0x3f) {
            if (!edges_known) {
                flat_edges(k);
                edges_known = true;
            }
            time -= step * A803824bc;
            if (time < 0.0f) time = 0.0f;
            float free_time = time;
            bool last_sample = false;
            while (time <= times[crossing] || last_sample) {
                Vec3 sample = at_time(local, time);
                if (!point_test(k, sample)) {
                    free_time = time;
                    time += step;
                    if (time >= end_time) {
                        if (last_sample) {
                            last_sample = false;
                        } else {
                            time = end_time;
                            last_sample = true;
                        }
                    }
                    continue;
                }
                Vec3 solid = sample;
                Vec3 inside;
                if (time > 0.0f && only_first_contact != 0) {
                    float low = time - step, high = time;
                    free_time = low;
                    inside = at_time(local, low);
                    point_test_call(k, inside);
                    for (int i = 0; i < 5; i++) {
                        const float middle = (free_time + high) * half;
                        sample = at_time(local, middle);
                        if (point_test_call(k, sample)) {
                            solid = sample;
                            high = middle;
                        } else {
                            inside = sample;
                            free_time = middle;
                        }
                    }
                } else {
                    inside = sample;
                    A804b1810 = 1;
                }
                if (free_time < 0.0f) free_time = 0.0f;

                const float frames = free_time / frame_time;
                const w3d_u32 frame = (w3d_u32)ppc_ftoi(frames);
                if (A804b1764 > frame) {
                    const float half_t2 = (free_time * free_time) * half;
                    Vec3 travel = {world_velocity.x * free_time, world_velocity.y * free_time, world_velocity.z * free_time};
                    Vec3 falling = {world_accel.x * half_t2, world_accel.y * half_t2, world_accel.z * half_t2};
                    A804b1824 = frames;
                    A804b1814 = frame;
                    A804b1764 = frame;
                    A8043ae08.solid = solid;
                    A8043ae08.position = {(world_start.x + travel.x) + falling.x, (world_start.y + travel.y) + falling.y, (world_start.z + travel.z) + falling.z};
                    A8043ae08.inside = inside;
                    A804b17ac = self->id;
                    A8043ae08.velocity = {world_velocity.x + world_accel.x * free_time, world_velocity.y + world_accel.y * free_time, world_velocity.z + world_accel.z * free_time};
                    A804b17a8 = A804ae4b8.hit_material[0] | (w3d_u32)A804ae4b8.hit_material[1] << 8 | (w3d_u32)A804ae4b8.hit_material[2] << 16;
                }
                return 1;
            }
        }
        // El original compara también la entrada 13 (fuera de los cruces) antes de mirar el índice; da igual: con el índice
        // en 13 el bucle acaba de todos modos.
        do {
            time = times[crossing];
            outside ^= flips[crossing];
            crossing++;
        } while (crossing != 13 && time >= times[crossing]);
    } while (time < end_time);
    return 0;
}

// ---- v34: W3D_COL_CHECK ----
// W3D_COL_CHECK=1 (entorno en Mac, debug.ini en 3DS): cada barrido (0x800b53d8), cada recorrido del árbol (0x800bcdec,
// d32h_mesh_tree_cull) y cada visita de trozos marcados (0x800bd710, s19_visit) hace también el camino original, compara
// todo lo que escriben y el juego sigue con lo del original. Las primeras diferencias de cada uno van al registro con el
// dato que difiere; cada 16384 comparaciones, y con la primera diferencia, una línea con la cuenta.
// W3D_COL_CHECK=2: solo el camino original, sin comparar, para medir con el mismo ejecutable (zonas 2 y 3) lo que ahorra el
// nuevo.
namespace {
int g_col_check = -1;   // -1: sin leer el entorno todavía; 0: camino nuevo; 1: los dos y comparar; 2: solo el original
struct CheckCount { unsigned compared, differing; };
CheckCount g_col_counts[3];
unsigned g_flat_sweeps;   // barridos comprobados en trozos sin bordes deformados (donde actúa el atajo de point_test)
const char *const kColSite[3] = {"barrido 0x800b53d8", "árbol 0x800bcdec", "visita 0x800bd710"};
const unsigned kColLogged = 8;

// Todo lo que puede escribir un barrido, con la prueba de punto y grid_test.
struct SweepState {
    GridAccess access;      // 0x804ae4b8-0x804ae4db: tablas de la consulta, esquina del relieve y vóxel del impacto
    TileAccess tiles;       // 0x804ae4e8
    float point[3];         // 0x804ae4dc, 0x804ae4e0, 0x804ae4e4: fracciones de la última prueba
    int corner_empty;       // 0x804ae4f8
    float blend[7];         // 0x804ae4fc-0x804ae50c, 0x804ae4b0, 0x804ae4b4: mezcla de esquinas
    w3d_u32 voxel[4];       // 0x804accc0-0x804acccc: temporales de grid_test
    float crossings[14];    // 0x8043b2fc
    uint8_t flips[13];      // 0x8043b334
    SweepHit hit;           // 0x8043ae08
    w3d_u32 first_frame, steps, material, land, touched;   // 0x804b1764, 0x804b1814, 0x804b17a8, 0x804b17ac, 0x804b1810
    float frames;           // 0x804b1824
};
struct SweepSlot { void *global; unsigned offset, size; const char *name; };
#define W3D_SLOT(g, field, n, name) {(void *)&(g), (unsigned)__builtin_offsetof(SweepState, field), (unsigned)(n), name}
const SweepSlot kSweepSlots[] = {
    W3D_SLOT(A804ae4b8, access, sizeof(GridAccess), "0x804ae4b8 (tablas de la consulta y vóxel del impacto)"),
    W3D_SLOT(A804ae4e8, tiles, sizeof(TileAccess), "0x804ae4e8 (tablas de vóxeles y esquinas)"),
    W3D_SLOT(A804ae4dc, point[0], 4, "0x804ae4dc (fracción x)"),
    W3D_SLOT(A804ae4e0, point[1], 4, "0x804ae4e0 (fracción de altura)"),
    W3D_SLOT(A804ae4e4, point[2], 4, "0x804ae4e4 (fracción z)"),
    W3D_SLOT(A804ae4f8, corner_empty, 4, "0x804ae4f8 (esquina vacía)"),
    W3D_SLOT(A804ae4fc, blend[0], 4, "0x804ae4fc (mezcla)"),
    W3D_SLOT(A804ae500, blend[1], 4, "0x804ae500 (mezcla)"),
    W3D_SLOT(A804ae504, blend[2], 4, "0x804ae504 (mezcla)"),
    W3D_SLOT(A804ae508, blend[3], 4, "0x804ae508 (mezcla)"),
    W3D_SLOT(A804ae50c, blend[4], 4, "0x804ae50c (altura mezclada)"),
    W3D_SLOT(A804ae4b0, blend[5], 4, "0x804ae4b0 (origen x de la mezcla)"),
    W3D_SLOT(A804ae4b4, blend[6], 4, "0x804ae4b4 (origen z de la mezcla)"),
    W3D_SLOT(A804accc0, voxel[0], 4, "0x804accc0 (grid_test x)"),
    W3D_SLOT(A804accc4, voxel[1], 4, "0x804accc4 (grid_test z)"),
    W3D_SLOT(A804accc8, voxel[2], 4, "0x804accc8 (grid_test bit)"),
    W3D_SLOT(A804acccc, voxel[3], 4, "0x804acccc (grid_test palabra)"),
    W3D_SLOT(A8043b2fc, crossings, sizeof(float) * 14, "0x8043b2fc (cruces)"),
    W3D_SLOT(A8043b334, flips, 13, "0x8043b334 (máscaras de los cruces)"),
    W3D_SLOT(A8043ae08, hit, sizeof(SweepHit), "0x8043ae08 (punto libre, sólido, posición y velocidad)"),
    W3D_SLOT(A804b1764, first_frame, 4, "0x804b1764 (paso del impacto)"),
    W3D_SLOT(A804b1814, steps, 4, "0x804b1814 (pasos)"),
    W3D_SLOT(A804b17a8, material, 4, "0x804b17a8 (vóxel del impacto)"),
    W3D_SLOT(A804b17ac, land, 4, "0x804b17ac (trozo del impacto)"),
    W3D_SLOT(A804b1810, touched, 4, "0x804b1810 (contacto sin bisección)"),
    W3D_SLOT(A804b1824, frames, 4, "0x804b1824 (pasos con fracción)"),
};
#undef W3D_SLOT
}

static int col_check_read() {
    const char *e = getenv("W3D_COL_CHECK");
    g_col_check = !e || !e[0] || e[0] == '0' ? 0 : e[0] == '2' ? 2 : 1;
    if (g_col_check == 1) w3d_dbg("[colcheck] activo: cada consulta de colisión hace también el camino original y compara\n");
    if (g_col_check == 2) w3d_dbg("[colcheck] solo el camino original de la colisión (para medir)\n");
    return g_col_check;
}
static inline int col_check_on() {
    const int on = g_col_check;
    return on >= 0 ? on : col_check_read();
}
static void col_check_count(int site, bool differs) {
    CheckCount &count = g_col_counts[site];
    count.compared++;
    if (differs) count.differing++;
    if ((count.compared & 0x3fff) != 0 && !(differs && count.differing == 1)) return;
    if (site == 0)
        w3d_dbg("[colcheck] %s: %u comparaciones, %u con diferencias; %u en trozos sin bordes deformados, %u por el camino "
                "original (entradas no finitas)\n", kColSite[0], count.compared, count.differing, g_flat_sweeps, g_sweep_fallbacks);
    else
        w3d_dbg("[colcheck] %s: %u comparaciones, %u con diferencias\n", kColSite[site], count.compared, count.differing);
}
// Para las unidades del juego (su getenv es el de la libc del juego): 0, 1 o 2 como W3D_COL_CHECK.
extern "C" int w3d_col_check(void) { return col_check_on(); }
// Árbol: where = palabra de la máscara, o -1 si difiere
// la última palabra escrita. Visita: where = posición en el orden de visita y los valores son índices de trozo (-1: ninguno).
extern "C" void w3d_col_check_note(int site, int differs, int where, w3d_u32 original, w3d_u32 fast) {
    if (site != 1 && site != 2) return;
    if (differs && g_col_counts[site].differing < kColLogged) {
        if (site == 1 && where < 0)
            w3d_dbg("[colcheck] %s: última palabra escrita: original %u, v34 %u\n", kColSite[site], original, fast);
        else if (site == 1)
            w3d_dbg("[colcheck] %s: palabra %d de la máscara: original %08x, v34 %08x\n", kColSite[site], where, original, fast);
        else
            w3d_dbg("[colcheck] %s: trozo n.º %d de la visita: original %d, v34 %d\n", kColSite[site], where, (int)original, (int)fast);
    }
    col_check_count(site, differs != 0);
}

static void sweep_save(SweepState &s) {
    memset(&s, 0, sizeof s);
    for (const SweepSlot &slot : kSweepSlots) memcpy((char *)&s + slot.offset, slot.global, slot.size);
}
static void sweep_load(const SweepState &s) {
    for (const SweepSlot &slot : kSweepSlots) memcpy(slot.global, (const char *)&s + slot.offset, slot.size);
}
static void sweep_report(Ptr32<LandObject> self, w3d_u32 original_result, w3d_u32 fast_result, const SweepState &original,
                         const SweepState &fast) {
    const char *what = original_result != fast_result ? "el valor devuelto" : nullptr;
    unsigned at = 0;
    w3d_u32 was = original_result, now = fast_result;
    for (const SweepSlot &slot : kSweepSlots) {
        if (what) break;
        const uint8_t *a = (const uint8_t *)&original + slot.offset, *b = (const uint8_t *)&fast + slot.offset;
        for (unsigned i = 0; i < slot.size; i++) {
            if (a[i] == b[i]) continue;
            at = i & ~3u;
            const unsigned n = slot.size - at < 4 ? slot.size - at : 4;
            was = now = 0;
            memcpy(&was, a + at, n);
            memcpy(&now, b + at, n);
            what = slot.name;
            break;
        }
    }
    if (what && g_col_counts[0].differing < kColLogged)
        w3d_dbg("[colcheck] %s (trozo %u): difiere %s +%u: original %08x, v34 %08x\n", kColSite[0], self->id, what, at, was, now);
    col_check_count(0, what != nullptr);
}
// ¿Bordes de capa a +0 en x y en z? Lo mismo que mira sweep_fast, solo para la cuenta del registro.
static bool land_has_flat_edges(const LandGrid *grid) {
    PointTest k;
    k.low_edge = at<const EdgePair>(grid->heights + 0x20);
    k.high_edge = at<const EdgePair>(grid->materials + 0x20);
    k.layers = grid->scale_y;
    k.columns_x = (float)(int)grid->scale_x;
    k.columns_z = (float)(int)grid->scale_z;
    flat_edges(k);
    return k.flat_x && k.flat_z;
}
// Los dos caminos sobre el mismo estado de partida; el juego sigue con el estado y el resultado del original.
static w3d_u32 sweep_checked(Ptr32<LandObject> self) {
    if (land_has_flat_edges(self->grid)) g_flat_sweeps++;
    SweepState before, original, fast;
    sweep_save(before);
    const w3d_u32 original_result = sweep_reference(self);
    sweep_save(original);
    sweep_load(before);
    const w3d_u32 fast_result = sweep_fast(self);
    sweep_save(fast);
    sweep_report(self, original_result, fast_result, original, fast);
    sweep_load(original);
    return original_result;
}

extern "C" w3d_u32 A800b53d8(Ptr32<LandObject> self) {
    const int check = col_check_on();
    if (__builtin_expect(check != 0, 0)) return check == 2 ? sweep_reference(self) : sweep_checked(self);
    return sweep_fast(self);
}

extern "C" {
// 0x800b5fc0: lo mismo en línea recta hasta el punto dado. Los bordes del terreno están deformados en altura: x y z se pasan a
// celda interpolando entre dos filas de la tabla por la fila de la capa, y la altura resta el relieve bilineal de esa columna.
int A800b5fc0(Ptr32<LandObject> self, Ptr32<Vec3> direction) {
    const LandGrid *grid = self->grid;
    const Vec3 direction_copy = *direction;
    const float frame_time = A804b1818;
    const Vec3 origin = translated(translated(rotate(grid->axis, A8043add8), grid->translation), grid->offset);
    float step = grid->cell_size * A803824c4;
    const float end_time = (float)A804b1764 * frame_time;
    const float long_step = end_time * A803824d0;

    const float columns_x = (float)(int)grid->scale_x, columns_z = (float)(int)grid->scale_z;
    const int layers = grid->scale_y;
    // Bordes por capa: {x, z} en filas de 8 B, y cada capa interpola con la siguiente.
    const float *low_edges = at<float>(grid->heights + 0x20), *high_edges = at<float>(grid->materials + 0x20);
    const float *relief = at<float>(grid->columns + 0x20);
    const int row = (int8_t)grid->column_shift_z;

    uint8_t outside = 0;
    if (step > long_step) {
        A8043b2fc[0] = end_time;
        A8043b2fc[1] = end_time + end_time;
        step = long_step;
        outside = 0x3f;
    } else {
        if (origin.x >= grid->box_max.x) outside |= 0x01;
        if (origin.y >= grid->box_max.y) outside |= 0x20;
        if (origin.z >= grid->box_max.z) outside |= 0x04;
        if (origin.x <= grid->box_min.x) outside |= 0x02;
        if (origin.y <= grid->box_min.y) outside |= 0x10;
        if (origin.z <= grid->box_min.z) outside |= 0x08;
        float *const unused_root = &A8043b2fc[11];
        A8043b2fc[0] = A8009ee18(unused_root, origin.x - grid->box_max.x, direction_copy.x, 0.0f);
        A8043b2fc[1] = A8009ee18(unused_root, origin.y - grid->box_max.y, direction_copy.y, 0.0f);
        A8043b2fc[2] = A8009ee18(unused_root, origin.z - grid->box_max.z, direction_copy.z, 0.0f);
        A8043b2fc[3] = A8009ee18(unused_root, origin.x - grid->box_min.x, direction_copy.x, 0.0f);
        A8043b2fc[4] = A8009ee18(unused_root, origin.y - grid->box_min.y, direction_copy.y, 0.0f);
        A8043b2fc[5] = A8009ee18(unused_root, origin.z - grid->box_min.z, direction_copy.z, 0.0f);
        A8043b2fc[6] = end_time;
        // La tabla de máscaras tiene los seis planos en sus posiciones pares.
        for (int i = 0; i < 7; i++) A8043b334[i] = A803f4c58[i * 2];
        bool sorted;
        do {
            sorted = true;
            for (int i = 0; i < 6; i++) {
                if (A8043b2fc[i] > A8043b2fc[i + 1]) {
                    const float t = A8043b2fc[i];
                    A8043b2fc[i] = A8043b2fc[i + 1];
                    A8043b2fc[i + 1] = t;
                    const uint8_t m = A8043b334[i];
                    A8043b334[i] = A8043b334[i + 1];
                    A8043b334[i + 1] = m;
                    sorted = false;
                }
            }
        } while (!sorted);
    }
    int crossing = 0;
    while (A8043b2fc[crossing] < 0.0f) crossing++;
    void *const layer_table = at<void>(grid->layer_table + 0x20);

    float time = 0.0f, free_time = 0.0f;
    if (!(time < end_time)) return 0;
    do {
        if (outside == 0x3f && time < A8043b2fc[crossing]) {
            free_time = time;
            do {
                const Vec3 point = {origin.x + direction_copy.x * time, origin.y + direction_copy.y * time, origin.z + direction_copy.z * time};
                int layer = ppc_ftoi(point.y);
                if (layer < 0) layer = 0;
                if (layer > layers - 1) layer = layers - 1;
                // Fracción dentro de la capa, para interpolar los bordes.
                const float above = point.y - (float)layer, below = 1.0f - above;
                const float *low = low_edges + layer * 2, *high = high_edges + layer * 2;
                const float edge_x = fused_madd(low[2], above, low[0] * below);
                const float cell_x = (point.x - edge_x) / ((fused_madd(high[2], above, high[0] * below) - edge_x) / columns_x + 1.0f);
                const float edge_z = fused_madd(low[3], above, low[1] * below);
                const float cell_z = (point.z - edge_z) / ((fused_madd(high[3], above, high[1] * below) - edge_z) / columns_z + 1.0f);
                const int8_t ix = to_s8(cell_x), iz = to_s8(cell_z);
                bool hit = false;
                if (cell_x >= 0.0f && cell_z >= 0.0f && cell_x < columns_x && cell_z < columns_z) {
                    const float *corner = relief + ix + iz * row;
                    const float fx = cell_x - (float)ix, fz = cell_z - (float)iz;
                    const float fx1 = 1.0f - fx;
                    const float far_row = fused_madd(corner[row], fx1, corner[row + 1] * fx);
                    const float near_row = fused_madd(corner[0], fx1, corner[1] * fx);
                    const float height = point.y - fused_madd(near_row, 1.0f - fz, far_row * fz);
                    const int level = ppc_ftoi(height);
                    if (level >= 0 && level < layers && A8002c73c(layer_table, ix, (int8_t)level, iz, 4) != 0) hit = true;
                }
                if (hit) {
                    const w3d_u32 frame = (w3d_u32)ppc_ftoi(free_time / frame_time);
                    if (A804b1764 > frame) A804b1764 = frame;
                    return 1;
                }
                free_time = time;
                time += step;
            } while (time < A8043b2fc[crossing]);
        }
        do {
            time = A8043b2fc[crossing];
            outside ^= A8043b334[crossing];
            crossing++;
        } while (time >= A8043b2fc[crossing] && crossing != 7);
    } while (time < end_time);
    return 0;
}
}

// De coordenadas de celda a coordenadas locales: x y z se interpolan entre los bordes de la capa, y el desplazamiento del terreno se resta.
namespace {
Vec3 cell_to_local(const LandGrid *grid, Vec3 point) {
    int layer = ppc_ftoi(point.y);
    if (layer < 0) layer = 0;
    const int top = (uint8_t)grid->scale_y - 1;
    if (layer > top) layer = top;
    const float above = point.y - (float)layer, below = 1.0f - above;
    const float *low = at<float>(grid->heights + 0x20) + layer * 2, *high = at<float>(grid->materials + 0x20) + layer * 2;
    const float edge_x = fused_madd(low[2], above, low[0] * below);
    const float span_x = fused_madd(high[2], above, high[0] * below) - edge_x;
    point.x += edge_x + (point.x * span_x) / (float)(uint8_t)grid->scale_x;
    const float edge_z = fused_madd(low[3], above, low[1] * below);
    const float span_z = fused_madd(high[3], above, high[1] * below) - edge_z;
    point.z += edge_z + (point.z * span_z) / (float)(uint8_t)grid->scale_z;
    return {point.x - grid->offset.x, point.y - grid->offset.y, point.z - grid->offset.z};
}
}

// 0x800b41c4: centro en el mundo local de la celda (x, y, z) del terreno, con el relieve de la columna y los bordes deformados.
extern "C" w3d_u32 A800b41c4(Ptr32<LandObject> self, w3d_u32 cell_x, w3d_u32 cell_y, w3d_u32 cell_z, Ptr32<Vec3> out) {
    const LandGrid *grid = self->grid;
    const float half = A80382450;
    Vec3 point = {(float)(uint8_t)cell_x + half, (float)(uint8_t)cell_y + half, (float)(uint8_t)cell_z + half};
    const uint8_t row = (uint8_t)grid->column_shift_z;
    const float *relief = at<float>(grid->columns + 0x20) + cell_x + row * cell_z;
    if (cell_x < (uint8_t)grid->scale_x && cell_z < (uint8_t)grid->scale_z) {
        // Se suma la media de las cuatro esquinas.
        const float sum = ((relief[0] + relief[1]) + relief[row]) + relief[row + 1];
        point.y = fused_madd(sum, A80382454, point.y);
    }
    *out = cell_to_local(grid, point);
    return self->grid.v;
}

// 0x800b43f8: como 0x800b41c4 con una posición fraccionaria: el relieve es bilineal, si el punto cae dentro de la rejilla.
extern "C" {
extern const float A80382464;
Ptr32<Vec3> A800b43f8(Ptr32<Vec3> out, Ptr32<LandObject> self, Ptr32<Vec3> cell) {
    const LandGrid *grid = self->grid;
    Vec3 point = *cell;
    const int8_t ix = to_s8(point.x), iz = to_s8(point.z);
    const int row = (uint8_t)grid->column_shift_z;
    const float *corner = at<float>(grid->columns + 0x20) + iz * row + ix;
    if (point.x >= A80382464 && point.z >= A80382464 && point.x < (float)(row - 1) && point.z < (float)((uint8_t)grid->column_shift_x - 1)) {
        const float fx = point.x - (float)ix, fz = point.z - (float)iz;
        const float fx1 = 1.0f - fx;
        const float far_row = fused_madd(corner[row], fx1, corner[row + 1] * fx);
        const float near_row = fused_madd(corner[0], fx1, corner[1] * fx);
        point.y += fused_madd(near_row, 1.0f - fz, far_row * fz);
    }
    *out = cell_to_local(grid, point);
    return out;
}
}
