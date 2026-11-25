// Más inicializaciones sueltas, cada una con su comentario.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
// 0x80041d28: cámara del panel de comentarios: dos juegos de valores según el modo.
struct CommentaryPanel {
    char pad[0x1c];
    w3d_u32 enabled;     // +0x1c
    float fade[4];       // +0x20
    float fade_copy[4];  // +0x30
    char pad2[0x104 - 0x40];
    w3d_u32 pose;        // +0x104
};
}
extern "C" {
extern Vector3 A8042745c, A80427468;
extern w3d_u32 A804aa974, A804aa978, A804aa97c;
extern float A804aa980;
extern const float A80374d8c, A80374d90, A80374d94, A80374d98, A80374d9c, A80374da0;

void A80041d28(Ptr32<CommentaryPanel> self, w3d_u32 enabled) {
    self->enabled = enabled;
    if (enabled) {
        A8042745c = {A80374d90, A80374d94, A80374d90};
        A80427468 = {A80374d90, A80374d94, A80374d90};
        A804aa978 = 0x640;
        A804aa97c = 0;
        A804aa974 = 0;
        self->pose = 0x3e;
    } else {
        A8042745c = {A80374d90, A80374d9c, A80374d90};
        A80427468 = {A80374d90, A80374da0, A80374d90};
        A804aa978 = 0x4b0;
        A804aa97c = 0xfa;
        A804aa974 = 0xfa;
        self->pose = 0x24;
    }
    A804aa980 = A80374d8c;
    for (int i = 0; i < 4; i++) self->fade_copy[i] = self->fade[i] = A80374d98;
}
}

extern "C" {
// 0x800fbd48: relee las tablas de nombres de armas, herramientas y equipos de la tabla de ajustes.
extern const char A80398058[], A80398068[], A8039807c[], A80398090[], A803980a0[], A803980b4[], A803980cc[];
extern w3d_u32 A8044a524[16], A8044a584[16], A8044a5e4[16], A8044a564[4], A8044a5c4[4], A8044a574[4], A8044a5d4[4];
void A803426b8(GameString *string);
void A8020c510(GameString *string, const char *format, ...);
w3d_u32 A800fc1b0(void *key, void *out, ...);
void A80341588(GameString *string);

static void read_formatted(GameString *name, const char *format, int index, w3d_u32 *out) {
    A8020c510(name, format, (long)index);
    Ptr32<char> key = name->text;
    ((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, out);
}
void A800fbd48() {
    GameString name;
    A803426b8(&name);
    for (int i = 0; i < 16; i++) {
        read_formatted(&name, A80398058, i, &A8044a524[i]);
        read_formatted(&name, A80398068, i, &A8044a584[i]);
        read_formatted(&name, A8039807c, i, &A8044a5e4[i]);
    }
    for (int i = 0; i < 4; i++) {
        read_formatted(&name, A80398090, i, &A8044a564[i]);
        read_formatted(&name, A803980a0, i, &A8044a5c4[i]);
        read_formatted(&name, A803980b4, i, &A8044a574[i]);
    }
    for (int i = 0; i < 4; i++) read_formatted(&name, A803980cc, i, &A8044a5d4[i]);
    A80341588(&name);
}
}

namespace {
// 0x80104768: objeto de control del viento y la mira de la cámara, y la luz global de la partida la primera vez.
struct SceneLight {
    w3d_u32 table;
    char pad[4];
    uint8_t flags;     // +8
    char pad2[0x18 - 9];
    float intensity;   // +0x18
    w3d_u32 kind;      // +0x1c
    w3d_u32 enabled;   // +0x20
};
struct WindControl {
    w3d_u32 table;
    char pad[0x1c - 4];
    w3d_u32 first[2];       // +0x1c
    w3d_u32 second[2];      // +0x24
    w3d_u32 third, fourth, fifth;  // +0x2c
    char pad3[0x40 - 0x38];
    w3d_u32 state;          // +0x40
    char pad4[0x50 - 0x44];
    struct { w3d_u32 used; w3d_u32 pad[3]; } slots[30];  // +0x50
    w3d_u32 last;           // +0x230
};
}
extern "C" {
extern w3d_u32 A80410690;
extern char A80415bb0;
extern const float A804aafac, A80399808, A8039980c, A80399810;
extern Vector3 A8044b688;
extern Ptr32<void> A804aafa4;
extern Ptr32<SceneLight> A804af1e8;
w3d_u32 A8015fef0(void *self);
w3d_u32 A8020b680(void *type);

Ptr32<WindControl> A80104768(Ptr32<WindControl> self) {
    A8015fef0(self.get());
    self->table = h2g(&A80410690);
    self->first[0] = self->first[1] = 0;
    self->second[0] = self->second[1] = 0;
    self->last = 0;
    self->third = self->fourth = self->fifth = 0;
    A8044b688 = {A80399808, A8039980c, -A804aafac};
    A804aafa4 = self;
    for (auto &slot : self->slots) slot.used = 0;
    if (!A804af1e8) {
        SceneLight *light = at<SceneLight>(A8020b680(&A80415bb0));
        add_reference(light);
        A804af1e8 = light;
        light->kind = 4;
        light->enabled = 1;
        light->intensity = A80399810;
        light->flags |= 3;
    }
    self->state = 0;
    return self;
}
}
