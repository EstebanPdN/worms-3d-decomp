// Funciones sueltas del juego, cada una con su comentario.
#include "native_common.h"

// Altura de la capa dada en una columna del mapa de rutas (0x8001e07c): media de sus dos mapas de altura o el suelo por defecto.
namespace {
struct RouteCell {
    char pad[0x1c];
    int16_t origin_x, origin_z, end_x;   // +0x1c
    char pad2[0x44 - 0x22];
    struct { w3d_u32 low; char pad[0xc]; } lower[2];   // +0x44, cada 16 B
    struct { w3d_u32 high; char pad[0xc]; } upper[2];  // +0x64, cada 16 B
};
}
extern "C" {
w3d_u32 A8001df1c(void *, w3d_u32, w3d_u32);
extern const float A8036b818;
float A8001e07c(Ptr32<char> self, w3d_u32 x, w3d_u32 z, w3d_u32 layer) {
    const w3d_u32 found = A8001df1c(self.get(), x, z);
    if (!found) return *(float *)(self.get() + 0x6c);
    const RouteCell *cell = at<RouteCell>(found);
    const int width = cell->end_x - cell->origin_x;
    const int index = ((int16_t)z - cell->origin_z) * width + (int16_t)x - cell->origin_x;
    const float a = at<float>(*(const w3d_u32 *)((const char *)cell + 0x44 + layer * 16))[index];
    const float b = at<float>(*(const w3d_u32 *)((const char *)cell + 0x64 + layer * 16))[index];
    return (a + b) * A8036b818;
}

// 0x80004394: reinicia una búsqueda de camino: las dos listas, los dos resultados y el estado.
void A80005398(void *);
void A80015264(void *);
w3d_u32 A8000532c(void *);
struct PathSearch {
    w3d_u32 pad0;
    char open_list[0x4004];       // +0x4
    char closed_list[0x4004];     // +0x4008
    Ptr32<void> best_path;        // +0x800c
    Ptr32<void> partial_path;     // +0x8010
    w3d_u32 pad1;
    w3d_u32 steps;                // +0x8018
    int goal;                     // +0x801c
    w3d_u32 stage;                // +0x8020
    char route[0x8048 - 0x8024];  // +0x8024
    int16_t min_cost, max_cost;   // +0x8048
    w3d_u32 limit;                // +0x804c
    w3d_u32 remaining;            // +0x8050
};
w3d_u32 A80004394(Ptr32<PathSearch> self) {
    A80005398(self->open_list);
    A80005398(self->closed_list);
    self->remaining = self->limit;
    if (void *best = self->best_path) A80015264(best);
    void *partial = self->partial_path;
    self->best_path.v = 0;
    if (partial) A80015264(partial);
    self->partial_path.v = 0;
    self->steps = 0;
    self->goal = -1;
    const w3d_u32 result = A8000532c(self->route);
    self->min_cost = 0;
    self->max_cost = 0x7fff;
    self->stage = 0;
    return result;
}

// 0x8016aef0: abre una lista de pantalla en el búfer compartido, que se reserva la primera vez.
extern w3d_u32 A804ab534;
w3d_u32 A801fe2a8(w3d_u32, w3d_u32);
void A802fa95c(void *, w3d_u32);
w3d_u32 A8030bcb8(void *, w3d_u32);
w3d_u32 A803081d0(void *, w3d_u32);
struct DisplayListHeader { w3d_u32 triangles; w3d_u32 capacity; w3d_u32 used; w3d_u32 buffer; };
w3d_u32 A8016aef0(Ptr32<DisplayListHeader> out, w3d_u32, w3d_u32 indices) {
    const w3d_u32 size = 0x10000;
    if (!A804ab534) A804ab534 = A801fe2a8(size, 0x20);
    out->capacity = size;
    out->buffer = A804ab534;
    out->triangles = (indices / 3) & 0xffff;
    A802fa95c(g2h(A804ab534), size);
    const w3d_u32 opened = A8030bcb8(g2h(out->buffer), size);
    return A803081d0(arg(opened), size);
}

// 0x801e4074: arranca un flujo de sonido en una ranura. Rellena con silencio lo que falte del primer tramo.
void A802eefe0(void *, w3d_u32, w3d_u32);
struct StreamBlock { char pad[0xc]; w3d_u32 bytes; };
struct StreamSlot {
    uint8_t state;
    char pad[0xf];
    Ptr32<StreamBlock> block;  // +0x10
    uint8_t mode_a, mode_b;    // +0x14
    char pad2[0x58 - 0x16];
    w3d_u32 block_size;        // +0x58
    w3d_u32 first_bytes;       // +0x5c
    w3d_u32 buffer;            // +0x60
    w3d_u32 half_size;         // +0x64
    w3d_u32 total_size;        // +0x68
    uint8_t active;            // +0x6c
    char pad3[3];
    w3d_u32 playing;           // +0x70
    w3d_u32 finished;          // +0x74
    w3d_u32 volume_scale;      // +0x78
    w3d_u32 position;          // +0x7c
};
const w3d_u32 kStreamBlock = 0x6b40;
w3d_u32 A801e4074(Ptr32<StreamSlot> self, Ptr32<StreamBlock> block, w3d_u32 mode_a, w3d_u32 mode_b) {
    self->position = 0;
    self->mode_a = (uint8_t)mode_a;
    self->mode_b = (uint8_t)mode_b;
    self->active = 1;
    self->half_size = 2 * kStreamBlock;
    self->total_size = 0x17760;
    self->block_size = kStreamBlock;
    self->block = block;
    self->playing = 1;
    self->finished = 0;
    self->volume_scale = 1;
    const w3d_u32 bytes = block->bytes;
    self->first_bytes = bytes;
    w3d_u32 prepared = kStreamBlock;
    if (bytes < kStreamBlock) {
        A802eefe0(g2h(self->buffer + bytes), 0, kStreamBlock - bytes);
        prepared = bytes;
    }
    self->state = 2;
    return prepared;
}

// 0x801e5a60: constructor del canal de flujo; además limpia los dos bits altos de las 16 voces globales.
struct StreamVoice { char pad[0x3c]; w3d_u32 flags; };
extern StreamVoice A8045dbc8[16];
extern char A80416f78[];
struct StreamChannel {
    w3d_u32 table;
    int16_t voices[2];         // +4
    w3d_u32 flags;             // +8
    char pad[0x2c - 0xc];
    w3d_u32 a;                 // +0x2c
    w3d_u32 pad2;
    w3d_u32 b;                 // +0x34
    int owner;                 // +0x38
    w3d_u32 buffers[2];        // +0x3c
    char pad3[0xa4 - 0x44];
    w3d_u32 c;                 // +0xa4
    Ptr32<char> name;          // +0xa8
};
Ptr32<StreamChannel> A801e5a60(Ptr32<StreamChannel> self) {
    self->flags &= 0xff1fffffu;
    self->name = A80416f78;
    self->owner = -1;
    self->c = 0;
    self->a = 0;
    self->b = 0;
    for (int i = 0; i < 2; i++) {
        self->buffers[i] = 0;
        self->voices[i] = -1;
    }
    for (StreamVoice &voice : A8045dbc8) voice.flags &= 0x3fffffffu;
    return self;
}

// 0x801ef380: borra un tramo de un array XOM de objetos: libera sus referencias y cierra el hueco.
struct RefArray {
    w3d_u32 table;
    uint16_t references;  // +4
    char pad[0x12];
    int count;            // +0x18
    w3d_u32 pad2;
    Ptr32<void> items[1]; // +0x20
};
w3d_u32 A801ef048(void *, w3d_u32, w3d_u32, w3d_u32);
void A801ef380(Ptr32<char> self, int field, w3d_u32, w3d_u32 first, int count) {
    if (count == 0) return;
    Ptr32<RefArray> *array = (Ptr32<RefArray> *)(self.get() + field);
    if ((*array)->references != 1) A801ef048(array, (*array)->count, 4, 2);
    RefArray *a = *array;
    const int size = a->count;
    a->count = size - count;
    for (int i = 0; i < count; i++) call_virtual(a->items[first + i].get(), 0x10);
    Ptr32<void> *to = a->items + first, *from = a->items + first + count, *end = a->items + size;
    while (from != end) *to++ = *from++;
}

// 0x80209190: cambia el tamaño usado de un bloque del montón (montón por defecto si el objeto no tiene). Al tomarlo, comprueba
// que no se haya tomado ya; si el llamador conserva su búfer, solo anota el tamaño.
struct ByteHeap {
    w3d_u32 pad;
    w3d_u32 data;         // +4
    w3d_u32 capacity;     // +8
    w3d_u32 used;         // +0xc
    w3d_u32 high_water;   // +0x10
    char pad2[0x34 - 0x14];
    Ptr32<const char> name;  // +0x34
};
struct HeapUser { char pad[0x20]; Ptr32<ByteHeap> heap; };
extern Ptr32<ByteHeap> A804b0684;
extern char A803b2eac[];
void A803434d4(char *, const char *, const char *, w3d_u32);
void A801fcb64(char *, w3d_u32);
w3d_u32 A80209190(Ptr32<HeapUser> self, w3d_u32 buffer, w3d_u32 keep_buffer, w3d_u32 size) {
    ByteHeap *heap = self->heap;
    if (!heap) heap = A804b0684;
    if (keep_buffer != 0) {
        if (size != 0) {
            if (heap->capacity < size) return 0;
            heap->used = size;
            if (size > heap->high_water) heap->high_water = size;
        } else {
            heap->used = 0;
        }
        return buffer;
    }
    if (heap->capacity < size) return 0;
    if (heap->used != 0) {
        char message[128];
        A803434d4(message, A803b2eac, heap->name.get(), size);
        A801fcb64(message, size);
    }
    heap->used = size;
    if (size > heap->high_water) heap->high_water = size;
    return heap->data;
}

// 0x802a2e24: constructor de un icono de mensaje con su panel en +0x1c.
void A8015fef0(void *);
void A802afb20(void *);
extern char A8041c3e0[], A8041c430[];
extern w3d_u32 A803d2e04;
struct MessageIcon {
    w3d_u32 table;
    char pad[0xd0 - 4];
    w3d_u32 second_table;   // +0xd0
    w3d_u32 a, b, c, d;     // +0xd4
    w3d_u32 frame;          // +0xe4
    w3d_u32 scale;          // +0xe8
};
Ptr32<MessageIcon> A802a2e24(Ptr32<MessageIcon> self) {
    A8015fef0(self.get());
    A802afb20((char *)self.get() + 0x1c);
    self->frame = 0;
    self->scale = A803d2e04;
    self->c = 0;
    self->d = 0;
    self->second_table = h2g(A8041c3e0);
    self->table = h2g(A8041c430);
    self->a = 0;
    self->b = 0;
    return self;
}

// 0x8002c4ec: construye los niveles de la pirámide de bits del terreno. Cada celda de 2 bits de un nivel resume cuatro palabras del
// anterior: bit alto si todas están llenas y bit bajo si alguna lo está.
struct BitPyramid {
    w3d_u32 offset[4];   // +0: en palabras desde el inicio
    w3d_u32 pad;
    w3d_u32 width[5];    // +0x14
    w3d_u32 height[5];   // +0x28: índice con el mismo nivel
};
static inline w3d_u32 shift_right(w3d_u32 v, w3d_u32 n) { return (n & 32) ? 0 : v >> (n & 31); }
void A8002c4ec(Ptr32<w3d_u32> pyramid, w3d_u32 level, w3d_u32 shift) {
    w3d_u32 *base = pyramid;
    const w3d_u32 source_width = base[level + 4], next_width = base[level + 5], source_height = base[level + 9];
    w3d_u32 *out_row = base + base[level];
    const w3d_u32 *in_row = base + base[level - 1];
    for (w3d_u32 y = 0; y < source_height >> 1; y++) {
        const w3d_u32 *in = in_row;
        w3d_u32 *out = out_row;
        for (w3d_u32 x = 0; x < source_width >> 1; x++, in += 2) {
            const w3d_u32 all = in[0] & in[1] & in[source_width] & in[source_width + 1];
            const w3d_u32 any = in[0] | in[1] | in[source_width] | in[source_width + 1];
            // El primer nivel mira el vecino hacia arriba; los demás, hacia abajo según su tamaño de celda.
            const w3d_u32 full = level == 1 ? all & (all << 1) : all & shift_right(all, shift);
            const w3d_u32 used = level == 1 ? any | (any >> 1) : any | shift_right(any, shift);
            *out++ = (full & 0xaaaaaaaau) | (used & 0x55555555u);
        }
        in_row += source_width * 2;
        out_row += next_width;
    }
    if (level <= 3) A8002c4ec(pyramid, level + 1, shift << 1);
}

// 0x8016b040: cierra los flujos de una malla: fija la longitud de los arrays de índices según los bits de la lista y borra los contadores.
struct IndexArray { w3d_u32 table; uint16_t references; char pad[0x12]; int count; uint16_t locks; };
struct IndexHolder { char pad[0x18]; Ptr32<IndexArray> array; };
struct MeshStreams { char pad[0x18]; Ptr32<IndexHolder> stream[4]; };   // +0x18: el índice 0 es el último del original
struct ListState {
    char pad[0xa0];
    w3d_u32 single_count;      // +0xa0
    w3d_u32 stream_count[4];   // +0xa4
    w3d_u32 flags;             // +0xb4
    char pad2[4];
    w3d_u32 open;              // +0xbc
};
struct OpenMesh { char pad[0x5c]; Ptr32<MeshStreams> streams; };
// Deja el array sin índices para volver a llenarlo. El tamaño de elemento depende del formato del flujo.
static void empty_indices(Ptr32<IndexArray> *array, bool byte_indices) {
    if ((*array)->references == 1 && (*array)->count == 0) (*array)->locks++;
    else A801ef048(array, 0, byte_indices ? 1 : 2, 8);
}
void A8016b040(w3d_u32 mask, Ptr32<OpenMesh> mesh, Ptr32<ListState> list) {
    if (list->open == 0) return;
    if (list->flags >> 31) {
        MeshStreams *streams = mesh->streams;
        static const struct { w3d_u32 bits; int rotate, field, counter; } kStreams[4] = {{0x3, 3, 3, 0}, {0xc, 4, 2, 1}, {0x30, 5, 1, 2}, {0x180, 6, 0, 3}};
        for (const auto &s : kStreams) {
            if (!(mask & s.bits)) continue;
            empty_indices(&streams->stream[s.field]->array, (list->flags >> (32 - s.rotate)) & 1);
            list->stream_count[s.counter] = 0;
        }
    } else {
        IndexHolder *holder = (IndexHolder *)mesh->streams.get();
        if ((list->flags >> 30) & 1) {
            empty_indices(&holder->array, true);
        } else {
            if (holder->array->count != 0) empty_indices(&holder->array, false);
            list->single_count = 0;
        }
    }
    list->open = 0;
}

// 0x80122580: añade un punto a un rastro. Su anchura va en perpendicular al segmento y a la línea de visión, para que mire a la cámara.
struct Point3 { float x, y, z; };
struct Trail {
    char pad[0x3c];
    uint16_t started[0x20];   // +0x3c, por tramo
    int wide;                 // +0x7c: sin esto, rastro de anchura cero
    Point3 last[8];           // +0x80
};
extern w3d_u32 A804b1788;
extern const float A8039b7e8, A8039b7ec, A8039b7f0;
extern w3d_u32 A804ab8d0;
void A80122800(void *, const Point3 *, const Point3 *, w3d_u32);
void A80122580(Ptr32<Trail> self, Ptr32<Point3> point, w3d_u32 segment, w3d_u32, w3d_u32, w3d_u32, float width) {
    if (self->wide == 0) width = A8039b7e8;
    const Point3 p = *point;
    if (self->started[segment] == 0) {
        A80122800(self.get(), point.get(), point.get(), segment);
        self->last[segment] = *point;
        return;
    }
    const w3d_u32 camera = *at<w3d_u32>(A804b1788 + 0x30);
    const Point3 *eye = at<Point3>(call_virtual(g2h(camera), 0x38));
    const Point3 to_eye = {p.x - eye->x, p.y - eye->y, p.z - eye->z};
    const Point3 &previous = self->last[segment];
    const Point3 step = {p.x - previous.x, p.y - previous.y, p.z - previous.z};
    Point3 side = {fused_msub(step.y, to_eye.z, step.z * to_eye.y), fused_msub(step.z, to_eye.x, step.x * to_eye.z), fused_msub(step.x, to_eye.y, step.y * to_eye.x)};
    if (side.x != 0.0f || side.y != 0.0f || side.z != 0.0f) {
        // Inversa de la raíz por tabla y una iteración de Newton.
        const float length2 = fused_madd(side.z, side.z, fused_madd(side.x, side.x, side.y * side.y));
        w3d_u32 bits;
        memcpy(&bits, &length2, 4);
        const uint8_t mantissa = at<const uint8_t>(A804ab8d0)[(bits >> 17) & 0x7f];
        const w3d_u32 exponent = (380 - ((bits >> 23) & 0xff)) << 22;
        const w3d_u32 estimate_bits = (exponent & 0xff800000u) | ((w3d_u32)mantissa << 15);
        float estimate;
        memcpy(&estimate, &estimate_bits, 4);
        const float inverse = ((A8039b7ec - (estimate * estimate) * length2) * estimate) * A8039b7f0;
        side.x *= inverse;
        side.y *= inverse;
        side.z *= inverse;
    }
    const Point3 half = {side.x * width, side.y * width, side.z * width};
    const Point3 left = {p.x - half.x, p.y - half.y, p.z - half.z};
    const Point3 right = {p.x + half.x, p.y + half.y, p.z + half.z};
    A80122800(self.get(), &left, &right, segment);
    self->last[segment] = *point;
}
}

// 0x800f235c: la IA prueba a lanzar un objeto en una dirección al azar en un cono y ve si la trayectoria acaba en suelo llano.
extern "C" {
struct ProbeVec { float x, y, z; };
extern const float A8038c43c, A8038c440, A8038c450, A8038c460, A8038c464, A8038c468, A8038c46c, A8038c470, A8038c474, A8038c478, A8038c47c;
extern const ProbeVec A8043ae20, A8043ae38;
extern w3d_u32 A804b1764, A804b1784;
w3d_u32 A8015ff5c();
float A802e83ec(float);
float A802e88ac(float);
float A802e86d4(float);
void A800b0824(void *, void *, void *, w3d_u32, w3d_u32, float);
void A800bd920();
w3d_u32 A800f235c(Ptr32<char> self, Ptr32<ProbeVec> out, Ptr32<const ProbeVec> origin, w3d_u32, Ptr32<const ProbeVec> direction) {
    const float zero = A8038c43c;
    ProbeVec gravity = {zero, A8038c440, zero}, wind = {zero, zero, zero};
    const float distance = (float)(A8015ff5c() % 500);
    // Altura de partida como entero sin signo, con la conversión de GCC.
    const double top = origin->y + A8038c450;
    const w3d_u32 frames = top >= 2147483648.0 ? (w3d_u32)ppc_ftoi(top - 2147483648.0) ^ 0x80000000u : (w3d_u32)ppc_ftoi(top);

    float angle;
    if (direction->z == zero) {
        angle = direction->x < zero ? A8038c460 : A8038c464;
    } else {
        angle = A802e83ec(direction->x / direction->z) + A8038c468;
        if (direction->z < zero) angle += A8038c468;
    }
    const float tilt = __builtin_fabsf(fused_madd(zero, direction->z, fused_madd(zero, direction->x, A8038c46c * direction->y)));
    const float spread = tilt > A8038c470 ? tilt * A8038c474 : A8038c478;
    const w3d_u32 range = (w3d_u32)ppc_ftoi(spread + spread);
    const w3d_u32 roll = A8015ff5c();
    const w3d_u32 offset = range ? roll % range : roll;
    angle += (((float)offset - spread) * A8038c468) / A8038c474;

    out->x = fused_madd(A802e88ac(angle), distance, origin->x);
    const float z = fused_madd(A802e86d4(angle), distance, origin->z);
    out->z = z;
    out->y = (float)frames;
    A800b0824(out.get(), &gravity, &wind, frames, 1, z);
    if (A804b1764 >= frames) {
        out->y = *(float *)(self.get() + 0x410) + A8038c47c;
        return 1;
    }
    if (A804b1784 == 0) A800bd920();
    const float ny = __builtin_fabsf(A8043ae38.y);
    if (ny > __builtin_fabsf(A8043ae38.x) && ny > __builtin_fabsf(A8043ae38.z)) {
        *out = A8043ae20;
        out->y += A8038c47c;
        return 1;
    }
    return 0;
}
}

// 0x8014b8ec: empuje de la mochila propulsora. La entrada del mando se proyecta en el plano horizontal según los ejes del gusano,
// con la mirada como respaldo si el eje frontal sale vertical, y el motor aplica el resultado.
extern "C" {
struct Rigid { ProbeVec axis[3]; ProbeVec translation; };
void A8014c260(ProbeVec *, void *, float);
void A8014be44(void *, float *);
void A801f76e0(Rigid *, const float *);
float A802e82c0(float);
void A8014be84();
void w3d_open_sret(void *fn, w3d_uptr dst, w3d_uptr a0, w3d_uptr a1, w3d_uptr a2, w3d_uptr a3, w3d_uptr a4, w3d_uptr a5,
                   float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);
extern const float A803a1464, A803a146c, A803a1470, A803a1474, A803a1478;
}
namespace {
inline ProbeVec transform(const Rigid &m, float x, float y, float z) {
    return {fused_madd(z, m.axis[2].x, fused_madd(x, m.axis[0].x, y * m.axis[1].x)) + m.translation.x,
            fused_madd(z, m.axis[2].y, fused_madd(x, m.axis[0].y, y * m.axis[1].y)) + m.translation.y,
            fused_madd(z, m.axis[2].z, fused_madd(x, m.axis[0].z, y * m.axis[1].z)) + m.translation.z};
}
inline float squared(const ProbeVec &v) { return fused_madd(v.z, v.z, fused_madd(v.x, v.x, v.y * v.y)); }
}
extern "C" Ptr32<ProbeVec> A8014b8ec(Ptr32<ProbeVec> out, Ptr32<void> worm, float dt) {
    ProbeVec input;
    A8014c260(&input, worm.get(), dt);
    const float zero = A803a1464;
    const float strength = A802e82c0(squared(input));
    if (input.x == zero && input.z == zero) {
        *out = {zero, zero, zero};
        return out;
    }
    float world[4][4];
    A8014be44(worm.get(), &world[0][0]);
    // La matriz en forma 3x3 + traslación que espera la inversa.
    Rigid packed;
    packed.axis[0] = {world[0][0], world[0][1], world[0][2]};
    packed.axis[1] = {world[1][0], world[1][1], world[1][2]};
    packed.axis[2] = {world[2][0], world[2][1], world[2][2]};
    packed.translation = {world[3][0], world[3][1], world[3][2]};
    Rigid inverse;
    A801f76e0(&inverse, &packed.axis[0].x);

    const float unit = A803a1470;
    const ProbeVec origin = inverse.translation;
    const ProbeVec front_point = transform(inverse, zero, zero, A803a146c);
    const ProbeVec side_point = transform(inverse, unit, zero, zero);
    ProbeVec side = {side_point.x - origin.x, zero, side_point.z - origin.z};
    ProbeVec front = {front_point.x - origin.x, zero, front_point.z - origin.z};
    if (squared(front) < A803a1474) {
        const ProbeVec up_point = transform(inverse, zero, unit, zero);
        front = {up_point.x - origin.x, zero, up_point.z - origin.z};
    }
    const float one = A803a1478;
    const float front_scale = one / A802e82c0(squared(front));
    front = {front.x * front_scale, front.y * front_scale, front.z * front_scale};
    const float side_scale = one / A802e82c0(squared(side));
    side = {side.x * side_scale, side.y * side_scale, side.z * side_scale};

    ProbeVec push = {fused_madd(input.x, side.x, input.z * front.x), zero, fused_madd(input.x, side.z, input.z * front.z)};
    w3d_open_sret((void *)A8014be84, (w3d_uptr)out.get(), (w3d_uptr)worm.get(), (w3d_uptr)&push, 0, 0, 0, 0, strength, 0, 0, 0, 0, 0, 0, 0);
    return out;
}

// 0x8004b958: recorre los contactos de la cápsula del gusano en su movimiento. Según el tipo de cada contacto se engancha a una
// superficie, se aplica un tramo de deslizamiento o se detiene en un borde; al final elige el estado de movimiento.
namespace {
struct Contact { ProbeVec point; char pad[8]; int type; w3d_u32 object; };   // +0x14, +0x18
struct ContactEntity { w3d_u32 table; char pad[0x60]; w3d_u32 a, b; char pad2[0xac - 0x6c]; w3d_u32 c; };
struct ContactType { char pad[0x14]; w3d_u32 parent; };
struct WormMotion {
    char pad[0x28];
    ProbeVec position;       // +0x28
    ProbeVec velocity;       // +0x34
    char pad3[0x68 - 0x40];
    w3d_u32 stopped;         // +0x68
    char pad4[4];
    w3d_u32 grounded;        // +0x70
    char pad5[0x7c - 0x74];
    w3d_u32 busy_a;          // +0x7c
    char pad6[4];
    w3d_u32 busy_b;          // +0x84
    char pad7[0x9c - 0x88];
    w3d_u32 busy_c;          // +0x9c
    w3d_u32 busy_d;          // +0xa0
    char pad8[0xec - 0xa4];
    char iterator[8];        // +0xec
    Ptr32<void> attached;    // +0xf4
    w3d_u32 surface;         // +0xf8
};
inline bool in_motion(const WormMotion *w) { return !w->busy_a && !w->busy_b && !w->busy_d && !w->busy_c; }
}
extern "C" {
extern uint16_t A804aa95e;
extern const float A80377268, A8037726c, A80377270, A80377274, A80377278, A804b17a4;
extern const ProbeVec A8045e788;
extern char A803600c0[];
void A80126384(void *, void *, w3d_u32);
w3d_u32 A801264fc(REGS_A);
void A80126524(void *);
w3d_u32 A8003f240(w3d_u32);
w3d_u32 A800418ac();
w3d_u32 A80164fc8(void *);
void A8004c2f0(void *, void *);
void A8004c29c(void *);
void A8004ce58(void *);
void A8004c378(void *);
void A8004c850(void *);
void A8004d54c(void *);
float A802e79e0(float);

void A8004b958(Ptr32<WormMotion> self) {
    WormMotion *worm = self;
    worm->stopped = 0;
    A80126384(worm->iterator, &worm->velocity, 0x14);
    const auto next = [&] { return ((w3d_u32 (*)(void *))A801264fc)(worm->iterator); };
    w3d_u32 hit = next();
    while (hit != 0xffff && in_motion(worm)) {
        const int type = at<Contact>(A8003f240(A804aa95e))->type;
        // La normal del contacto; sin normal se toma la vertical.
        ProbeVec normal = *at<ProbeVec>(A800418ac());
        const float normal2 = squared(normal);
        if (normal2 == A80377268) {
            normal = {A80377268, A8037726c, A80377268};
        } else {
            const float scale = A8037726c / A802e82c0(normal2);
            normal = {normal.x * scale, normal.y * scale, normal.z * scale};
        }
        if (type == 1) {
            const w3d_u32 entity = A80164fc8(arg(at<Contact>(A8003f240(A804aa95e))->object));
            A8004c2f0(worm, arg(*at<w3d_u32>(entity + 0x248)));
        } else if (type == 136) {
            A8004c29c(worm);
        } else {
            const w3d_u32 entity = A80164fc8(arg(at<Contact>(A8003f240(A804aa95e))->object));
            bool solid = false;
            if (entity) {
                w3d_u32 kind = call_virtual(g2h(entity), 0x14);
                while (kind != h2g(A803600c0) && at<ContactType>(kind)->parent != kind) kind = at<ContactType>(kind)->parent;
                const ContactEntity *e = at<ContactEntity>(entity);
                solid = kind == h2g(A803600c0) && !e->a && !e->b && !e->c;
            }
            if (solid) {
                const float speed = A802e82c0(squared(worm->velocity));
                if (speed > A80377270) {
                    worm->stopped = 1;
                    const float scale = A8037726c / A802e82c0(squared(worm->velocity));
                    const ProbeVec direction = {worm->velocity.x * scale, worm->velocity.y * scale, worm->velocity.z * scale};
                    float cosine = fused_madd(direction.z, normal.z, fused_madd(direction.x, normal.x, direction.y * normal.y));
                    if (!(cosine < A8037726c)) cosine = A8037726c;
                    if (cosine < A80377274) cosine = A80377274;
                    if (A802e79e0(cosine) >= A80377278) {
                        worm->position.x += worm->velocity.x * A804b17a4;
                        worm->position.y += worm->velocity.y * A804b17a4;
                        worm->position.z += worm->velocity.z * A804b17a4;
                        A8004ce58(worm);
                    }
                } else if (at<Contact>(A8003f240(A804aa95e))->point.y < worm->position.y) {
                    worm->stopped = 1;
                    worm->surface = at<Contact>(A8003f240(A804aa95e))->object;
                    worm->velocity = A8045e788;
                    worm->grounded = 1;
                    if (worm->attached) call_virtual(worm->attached.get(), 0x10);
                    worm->attached.v = 1;
                }
            }
        }
        hit = next();
    }
    A80126524(worm->iterator);
    if (worm->busy_c) A8004c378(worm);
    else if (worm->busy_d) A8004c850(worm);
    else A8004d54c(worm);
}
}

// 0x800438d4: avanza el comentario. Toma el siguiente texto de la cola con su color, o la cadena vacía si no queda ninguno.
namespace {
struct Commentary {
    char pad[0x30];
    float color[4];                       // +0x30
    w3d_u32 showing;                      // +0x40
    w3d_u32 label;                        // +0x44
    Ptr32<w3d_u32> texts, texts_end;      // +0x48
    char pad3[0x58 - 0x50];
    w3d_u32 frame;                        // +0x58
    w3d_u32 current_sound;                // +0x5c
    Ptr32<w3d_u32> sounds, sounds_end;    // +0x60
};
inline void retain_string(w3d_u32 s) { (*(uint16_t *)g2h(s - 6))++; }

}
extern "C" {
extern char A80374dd8[];
void A803426b8(w3d_u32 *);
void A8020bb2c(void *);
void A8020bd58(w3d_u32 *, const char *);
void A8020c5c4(void *);
void A80341588(void *);
void A802eeef4(void *, const void *, w3d_u32);
}
static inline void release_string(w3d_u32 s) {
    uint16_t *references = (uint16_t *)g2h(s - 6);
    if (--*references == 0) A8020bb2c(references);
}
extern "C" void A800438d4(Ptr32<Commentary> self, w3d_u32 frame) {
    w3d_u32 text;
    A803426b8(&text);
    void *label = g2h(A80164fc8(arg(self->label)));
    Commentary *c = self;
    if ((c->texts_end.v - c->texts.v) >> 2) {
        retain_string(c->texts[0]);
        release_string(text);
        text = c->texts[0];
        // Quita el primero de la cola: cada texto baja una posición, ajustando sus referencias.
        w3d_u32 *to = c->texts.get(), *from = to + 1, *const end = c->texts_end.get();
        for (; from < end; to++, from++) {
            retain_string(*from);
            release_string(*to);
            *to = *from;
        }
        c->texts_end.v -= 4;
        A8020c5c4(c->texts_end.get());
        A80341588(c->texts_end.get());
        c->current_sound = c->sounds[0];
        char *first = (char *)c->sounds.get() + 4, *last = (char *)c->sounds_end.get();
        if (first != last && last != first) A802eeef4(c->sounds.get(), first, last - first);
        c->sounds_end.v -= 4;
        call_virtual(label, 0x2c, arg(text));   // El original calcula aquí el color en bytes, pero no llega a pasarlo.
        c->frame = frame;
        c->showing = 1;
    } else {
        A8020bd58(&text, A80374dd8);
        call_virtual(label, 0x2c, arg(text));   // El original calcula aquí el color en bytes, pero no llega a pasarlo.
    }
    A8020c5c4(&text);
    A80341588(&text);
}
