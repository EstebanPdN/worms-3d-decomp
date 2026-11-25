// Cálculo por partícula: envolvente de tamaño, alfa y color a lo largo de su vida.
#include "native_common.h"

namespace {
struct Emitter {
    char pad[0x3c];
    float grow_x;       // +0x3c
    float grow_y;       // +0x40
    float base_x;       // +0x44
    float base_y;       // +0x48
    float end_scale_x;  // +0x4c: si es negativa, tamaño fijado por el crecimiento.
    float end_scale_y;  // +0x50
    char pad2[0x5c - 0x54];
    int lifetime;       // +0x5c
    char pad3[0x64 - 0x60];
    w3d_u32 birth;      // +0x64
    char pad4[0x70 - 0x68];
    w3d_u32 alpha_table;  // +0x70: tabla secundaria, entrada +0x30 es el alfa.
};
struct XomFloats { char pad[0x18]; int count; char pad2[4]; float values[1]; };
struct ParticleSettings {
    char pad[0x8c];
    Ptr32<XomFloats> colors;      // +0x8c: ternas RGB
    char pad2[0x114 - 0x90];
    Ptr32<XomFloats> color_times; // +0x114
    char pad3[0x11c - 0x118];
    float alpha_rate;             // +0x11c
    char pad4[0x124 - 0x120];
    float start_alpha;            // +0x124
    char pad5[0x188 - 0x128];
    uint16_t hold_frames;         // +0x188
    char pad6[0x19a - 0x18a];
    uint16_t fade_in_frames;      // +0x19a
    char pad7[0x1a8 - 0x19c];
    uint16_t grow_delay;          // +0x1a8
    int8_t color_stages;          // +0x1aa
};
struct Rgb { float r, g, b; };
inline float frames_alive(const Emitter *emitter, w3d_u32 frame) { return (float)(frame - emitter->birth); }
// Como psq_st con GQR u8: satura y trunca, NaN da 0.
inline uint8_t to_byte(float value) {
    if (value != value || value <= 0) return 0;
    if (value >= 255) return 255;
    return (uint8_t)value;
}
}

extern "C" {
void A800dec4c(Rgb *out, const float *from, const float *to, float t);

// 0x800ddb28: tamaño en el instante t. Hasta grow_delay es el base; luego crece a ritmo fijo o interpola a la escala final.
w3d_u32 A800ddb28(Ptr32<Emitter> self, Ptr32<float> out, Ptr32<ParticleSettings> settings, int fixed_rate, Ptr32<float> remaining, float t) {
    const Emitter *e = self;
    const int delay = settings->grow_delay;
    if (t < (float)delay) {
        out[0] = e->base_x;
        out[1] = e->base_y;
        return self.v;
    }
    const float u = (t - (float)delay) / (float)(e->lifetime - delay);
    const float rest = 1.0f - u;
    if (e->end_scale_x >= 0.0f) {
        out[0] = fused_madd(rest, e->base_x, u * (e->base_x * e->end_scale_x));
        out[1] = fused_madd(rest, e->base_y, u * (e->base_y * e->end_scale_y));
    } else {
        if (e->grow_x < 0.0f || fixed_rate != 0) out[0] = e->base_x * rest;
        else out[0] = fused_madd(e->grow_x, t, e->base_x);
        if (e->grow_y < 0.0f || fixed_rate != 0) out[1] = e->base_y * rest;
        else out[1] = fused_madd(e->grow_y, t, e->base_y);
    }
    if (remaining) {
        const float dx = e->base_x - out[0];
        remaining[0] = dx;
        remaining[2] = dx;
        remaining[1] = e->base_y - out[1];
    }
    return self.v;
}

// 0x800ddfe4: alfa según los cuadros vividos: entrada, espera y salida, proporcional a lo que queda de vida o a ritmo fijo.
// Devuelve float: core/open lo declaró entero y el valor se perdía (ver docs/port-sustitucion-open.md).
float A800ddfe4(Ptr32<Emitter> self, w3d_u32 frame, Ptr32<ParticleSettings> settings) {
    const float age = frames_alive(self, frame);
    const int fade_in = settings->fade_in_frames;
    float alpha = settings->start_alpha;
    if (age < (float)fade_in) {
        alpha *= age / (float)settings->fade_in_frames;
    } else {
        const int fade_start = settings->hold_frames + fade_in;
        const float rate = settings->alpha_rate;
        if (age > (float)fade_start) {
            if (rate < 0.0f) {
                const float start = (float)fade_start;
                alpha -= alpha * ((age - start) / ((float)self->lifetime - start));
            } else {
                alpha -= rate * (age - (float)fade_start);
            }
        }
    }
    if (alpha < 0.0f) return 0.0f;
    if (alpha > 1.0f) return 1.0f;
    return alpha;
}

// 0x800de16c: color RGBA en bytes de la partícula en este cuadro. Rampa de color con hasta color_stages paradas.
w3d_u32 A800de16c(Ptr32<Emitter> self, w3d_u32 frame, Ptr32<uint8_t> out, Ptr32<ParticleSettings> settings) {
    const float age = frames_alive(self, frame);
    const float alpha = call_in_table<float>(self.get(), self->alpha_table, 0x30, arg(frame), settings.get());
    const float life = age / (float)self->lifetime;

    const XomFloats *ramp = settings->colors;
    const float *colors = ramp->values;
    const float *times = settings->color_times->values;
    // El original compara como bytes con signo.
    const int8_t count = (int8_t)ramp->count;
    const int8_t stages = settings->color_stages;

    Rgb color;
    const int8_t usable = stages > count ? count : stages;
    if (usable == 0) {
        color.r = color.g = color.b = 1.0f;
    } else if (usable == 1) {
        color.r = colors[0];
        color.g = colors[1];
        color.b = colors[2];
    } else if (usable == 2) {
        A800dec4c(&color, colors, colors + 3, life);
    } else {
        bool found = false;
        for (int i = 0; i < stages - 2; i++) {
            const float stop = times[i];
            if (life < stop) {
                const float u = i == 0 ? life / times[0] : (life - times[i - 1]) / (stop - times[i - 1]);
                A800dec4c(&color, colors + i * 3, colors + (i + 1) * 3, u);
                found = true;
                break;
            }
        }
        if (!found) {
            const float last = times[stages - 3];
            A800dec4c(&color, colors + (stages - 2) * 3, colors + (stages - 1) * 3, (life - last) / (1.0f - last));
        }
    }
    out[0] = to_byte(color.r * 255.0f);
    out[1] = to_byte(color.g * 255.0f);
    out[2] = to_byte(color.b * 255.0f);
    out[3] = to_byte(alpha * 255.0f);
    return out.v;
}
}

// Reinicio y creación de partículas.
namespace {
struct ParticleResource { char pad[0x13c]; };
struct Particle {
    char pad[0xc];
    float direction[3];   // +0xc
    char pad2[0x6c - 0x18];
    w3d_u32 frame;        // +0x6c
    w3d_u32 table;        // +0x70
};
struct SpawnerState {
    char pad[0x10];
    int spawned;              // +0x10
    char pad2[0x50 - 0x14];
    float position[3];        // +0x50
    char pad3[0x6c - 0x5c];
    int next_tail;            // +0x6c
    w3d_u32 tail_period;      // +0x70
    char pad4[0x80 - 0x74];
    w3d_u32 resource;         // +0x80
    char pad5[0x98 - 0x84];
    w3d_u32 flags;            // +0x98
    char pad6[0xe4 - 0x9c];
    w3d_u32 table;            // +0xe4
};
inline const float *fields(const char *settings, int offset) { return (const float *)(settings + offset); }
inline w3d_u32 u32_field(const char *settings, int offset) { return *(const w3d_u32 *)(settings + offset); }
inline uint16_t u16_field(const char *settings, int offset) { return *(const uint16_t *)(settings + offset); }
}
extern "C" {
w3d_u32 A801797b4(void *);
extern const float A80389cd8, A80389cdc, A80389ce0, A80389ce4;
void A800dcbe0(void *, const void *, const void *, float, void *);
void A800dd158(void *, const void *, const void *, float);
void A800dcfc0(void *, const void *, float);
void A800dce48(void *, const void *, const void *, float);
void A800dd424(void *, const void *, const void *, w3d_u32, float);
void A800dd648(void *, const void *, const void *, w3d_u32);
void A800dd828(void *, w3d_u32, w3d_u32);
void A800dd918(void *, w3d_u32, w3d_u32);
void A800dd998(void *, float, float);
void A800dda48(void *, float, float, float);
void A800dd07c(void *, const void *, float);
void A800dfe20(void *, float *);

// 0x800dfa00: prepara una partícula nueva a partir de su emisor y de los ajustes del recurso.
void A800dfa00(Ptr32<SpawnerState> self, Ptr32<Particle> particle, w3d_u32 frame, int counted) {
    const char *settings = at<char>(A801797b4(arg(self->resource)));
    Particle *p = particle;
    call_in_table(p, p->table, 8, arg(p->frame));
    call_in_table(self.get(), self->table, 0xc, p, arg(frame));

    const float scale_step = (float)self->spawned;
    float blend[2];
    const float unit = A80389cd8;
    blend[0] = fused_madd(*fields(settings, 0xf4) * scale_step, unit, *fields(settings, 0xfc));
    blend[1] = fused_madd(*fields(settings, 0xf8) * scale_step, unit, *fields(settings, 0x100));
    call_in_table(p, p->table, 0x18, self->position, settings + 0x68);
    A800dcbe0(p, settings + 0x90, settings + 0xc0, unit, arg(u32_field(settings, 0x1c8)));
    A800dd158(p, settings + 0x5c, settings + 0x50, A80389cdc);
    A800dcfc0(p, blend, *fields(settings, 0x174));
    A800dce48(p, settings + 0x104, settings + 0xec, unit);
    call_in_table(p, p->table, 0x1c, (w3d_u32)u16_field(settings, 0x1a4), (w3d_u32)u16_field(settings, 0x1a2));
    A800dd424(p, settings + 0xcc, settings + 0xd8, 1, unit);
    A800dd648(p, settings + 0xb4, settings + 0x20, 1);
    A800dd828(p, u16_field(settings, 0x18c), u16_field(settings, 0x186));
    A800dd918(p, *(const uint8_t *)(settings + 0x1e4), *(const uint8_t *)(settings + 0x1ed));
    A800dd998(p, *fields(settings, 0x170), *fields(settings, 0x16c));
    A800dda48(p, *fields(settings, 0x168), *fields(settings, 0x164), unit);

    const float *spread = fields(settings, 0xe4);
    if (spread[0] == A80389ce0 && spread[1] == A80389ce0) {
        const float full[2] = {A80389ce4, A80389ce4};
        A800dd07c(p, full, *fields(settings, 0x13c));
    } else {
        A800dd07c(p, spread, *fields(settings, 0x13c));
    }
    if (self->flags & 0x200) {
        float m[3][3];
        A800dfe20(self.get(), &m[0][0]);
        const float x = p->direction[0], y = p->direction[1], z = p->direction[2];
        p->direction[0] = fused_madd(z, m[2][0], fused_madd(x, m[0][0], y * m[1][0]));
        p->direction[1] = fused_madd(z, m[2][1], fused_madd(x, m[0][1], y * m[1][1]));
        p->direction[2] = fused_madd(z, m[2][2], fused_madd(x, m[0][2], y * m[1][2]));
    }
    if ((self->flags & 4) && counted != 0 && --self->next_tail == 0) {
        call_in_table(p, p->table, 0x34, settings);
        const w3d_u32 period = self->tail_period;
        const w3d_u32 divisor = u16_field(settings, 0x192) > period ? period : u16_field(settings, 0x192);
        self->next_tail = divisor ? period / divisor : 0;
    }
}

extern char A80389ecc[], A80389ee4[], A8040db38[];
extern w3d_u32 A804b1754;
extern w3d_u32 A804aed08;
w3d_u32 A800fc4c8(float, void *);
w3d_u32 A800fc3b0(void *, w3d_u32);
w3d_u32 A801613f0(void *, w3d_u32);
w3d_u32 A8015f5a0(void *, w3d_u32);
w3d_u32 A8016239c(void *);
w3d_u32 A80165254();
w3d_u32 A80178ec4(void *);
w3d_u32 A80342a78(void *);
w3d_u32 A80178d1c(void *);
float A800de5b4(void *, w3d_u32);
void A800dfe84(void *, void *, w3d_u32, void *, void *);
void A800dff7c(void *, void *, float, const void *);
void A800e5ca4(void *, void *, w3d_u32, float);
extern const float A80389ef8;

struct DyingEmitter {
    char pad[0x20];
    Ptr32<void> world;         // +0x20
    char pad2[0x6c - 0x24];
    float trail[1];            // +0x6c
    char pad3[0x9c - 0x70];
    w3d_u32 resource;          // +0x9c
    char pad4[0xb4 - 0xa0];
    w3d_u32 flags;             // +0xb4
    char pad5[0xf0 - 0xb8];
    w3d_u32 mesh_resource;     // +0xf0
    w3d_u32 skin_resource;     // +0xf4
};
struct ScriptMessage { uint16_t id; char pad[2]; w3d_u32 name; };
// 0x800e1f40: cuando un proyectil muere, lanza la sacudida de cámara si procede y su nube final de partículas.
void A800e1f40(Ptr32<DyingEmitter> self, Ptr32<void> entity) {
    const char *settings = at<char>(A801797b4(arg(self->resource)));
    if (*(const int *)(settings + 0x17c) == 1) {
        void *world = g2h(call_virtual(self->world.get(), 0x14, entity.get()));
        const w3d_u32 table = *(const w3d_u32 *)((char *)world + 0x70);
        if (call_in_table(world, table, 0x3c) == 0) return;
    }
    const float shake = *fields(settings, 0x120);
    if (shake > A80389ef8 && u16_field(settings, 0x1a6) != 0) {
        Ptr32<char> magnitude_key(A80389ecc), duration_key(A80389ee4);
        A800fc4c8(shake, &magnitude_key);
        A800fc3b0(&duration_key, u16_field(settings, 0x1a6));
        ScriptMessage *message = at<ScriptMessage>(A801613f0(arg(A804b1754), 8));
        message->id = (uint16_t)A8015f5a0(&A804aed08, 1);
        message->name = h2g(A8040db38);
        A8016239c(message);
    }
    const w3d_u32 cloud = u32_field(settings, 0x134);
    if (*at<const uint16_t>(cloud - 4) == 0) return;

    void *world = g2h(call_virtual(self->world.get(), 0x14, entity.get()));
    const w3d_u32 now = *at<const w3d_u32>(A80165254() + 0x34);
    const w3d_u32 table = *(const w3d_u32 *)((char *)world + 0x70);
    char spawn[0x18];
    call_in_table(world, table, 0x24, arg(now), spawn, settings, (void *)0);
    if (self->flags & 8) {
        void *mesh = g2h(A80178ec4(arg(self->mesh_resource)));
        void *skin = g2h(A80178d1c(g2h(A80342a78(arg(self->skin_resource)))));
        A800dfe84(world, spawn, now, mesh, skin);
    }
    if (self->flags & 0x400) {
        const float life = A800de5b4(world, now);
        A800dff7c(spawn, self->trail, life, settings);
    }
    A800e5ca4(spawn, g2h(u32_field(settings, 0x134)), 0, A80389ef8);
}
}
