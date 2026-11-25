// Pantalla de la partida al arrancar: recursos del HUD, mensajes que escucha y ajustes iniciales.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
struct GameScreen {
    char pad[0x14];
    Ptr32<void> scene;           // +0x14
    char pad2[0x20 - 0x18];
    Ptr32<void> hud_text;        // +0x20
    Ptr32<void> hud_font;        // +0x24
    char pad3[0xb4 - 0x28];
    Ptr32<void> crosshair;       // +0xb4
    char pad4[0xc0 - 0xb8];
    float countdown;             // +0xc0
};
struct Application { char pad[0x6c]; Ptr32<void> music; Ptr32<void> listener; char pad2[0xbc - 0x74]; w3d_u32 flags; };
const w3d_u32 kFlagTrace = 0x40000000;
struct Subscription { char *name; w3d_u32 member; };
struct Rules { char pad[0xd0]; w3d_u32 mode; };
const w3d_u32 kModeDemo = 6;
struct CameraFlags { char pad[0x60]; w3d_u32 flags; };
}
extern "C" {
extern char A804b0984, A804b097c, A804b09ac, A804b098c, A804b0994, A804b099c, A804b09a4, A804b09cc, A804b09d4, A804b09bc, A804b09c4, A804b0a34, A804b0a2c, A804b0a14,
    A804b0a1c, A804b0a24, A804b09dc, A804b0a04, A804b0a4c, A804b0a54, A804b0a5c, A804b0a64, A804b09e4, A804b0a6c, A804b0a74, A804b0a84, A804b0a7c, A804b0a8c;
extern const char A803caeb8[], A803caec4[], A803cac08[], A803caed4[], A803caee4[], A803caef8[], A803caf0c[];
extern const float A803caf24, A803caf28, A803caf2c, A803caf30, A803caf34;
extern char A8041be70, A803f2c28, A803f3328;
extern Ptr32<Application> A804b1788;
extern Ptr32<void> A804b178c;
extern Ptr32<CameraFlags> A804aac54;
extern Ptr32<Rules> A804aaabc;
extern w3d_u32 A804aa83c, A804aa840, A804aa858;
extern uint8_t A804abb60;
w3d_u32 A800fc1b0(void *key, void *out, ...);
w3d_u32 A800fc270(void *key, void *out, ...);
w3d_u32 A800fc1f0(void *key, void *out, ...);
void A80343744();
void A801790bc(void *object, const char *name);
uint16_t A8015f5a0(void *name, w3d_u32 create);
void A80162024(void *self, const uint16_t *id, void *member);
w3d_u32 A8020b680(void *type);
void A80164514(void *owner, void *object, void *scene);
void A8015adf4(GameString *name, void *out, w3d_u32 kind);
void A80263e18(void *self);
void A802644a8(void *self, const char *name);
w3d_u32 A80262a58(void *self);

static void load_named(const char *name, Ptr32<void> &slot) {
    Ptr32<const char> key(name);
    Ptr32<void> found{(void *)nullptr};
    ((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, &found);
    A80343744();
    if (found) add_reference(found.get());
    release_if_set(slot.get());
    slot = found;
    release_if_set(found.get());
}
// 0x802622fc
w3d_u32 A802622fc(Ptr32<GameScreen> self) {
    load_named(A803caeb8, self->hud_font);
    load_named(A803caec4, self->hud_text);
    A801790bc(self->hud_text.get(), A803cac08);
    A804aac54->flags &= 0xfeffffffu;
    const Subscription subscriptions[] = {
        {&A804b0984, 40},  {&A804b097c, 44},  {&A804b09ac, 80},  {&A804b098c, 48},  {&A804b0994, 52},  {&A804b099c, 56},  {&A804b09a4, 60},
        {&A804b09cc, 64},  {&A804b09d4, 68},  {&A804b09bc, 72},  {&A804b09c4, 76},  {&A804b0a34, 84},  {&A804b0a2c, 88},  {&A804b0a14, 124},
        {&A804b0a1c, 128}, {&A804b0a24, 132}, {&A804b09dc, 112}, {&A804b0a04, 172}, {&A804b0a4c, 136}, {&A804b0a54, 140}, {&A804b0a5c, 144},
        {&A804b0a64, 148}, {&A804b09e4, 108}, {&A804b0a6c, 152}, {&A804b0a74, 156}, {&A804b0a84, 160}, {&A804b0a7c, 164}, {&A804b0a8c, 168},
    };
    uint16_t ids[28];
    int n = 0;
    for (const Subscription &subscription : subscriptions) {
        ids[n] = A8015f5a0(subscription.name, 1);
        A80162024(self.get(), &ids[n], (char *)self.get() + subscription.member);
        n++;
    }
    {
        Ptr32<const char> key(A803caed4);
        ((w3d_u32 (*)(void *, void *))A800fc270)(&key, &self->countdown);
    }
    if (A804b1788->flags & kFlagTrace) A80164514(A804b178c.get(), g2h(A8020b680(&A8041be70)), self->scene.get());
    Ptr32<const char> key(A803caee4);
    int crosshair_size = 0;
    ((w3d_u32 (*)(void *, void *))A800fc1f0)(&key, &crosshair_size);
    if (crosshair_size) {
        const Vector3 where = {A803caf24, A803caf28, A803caf2c};
        GameString name;
        A8020bb54(&name, A803caef8);
        A8015adf4(&name, &self->crosshair, (A804abb60 + 26) & 0xff);
        if (self->crosshair) call_virtual<void>(self->crosshair.get(), 0x54, &where, (void *)0);
    }
    A80263e18(self.get());
    void *music = A804b1788->music;
    if (music) {
        call_virtual<void>(music, 0x3c, arg(A804aa840), &A803f2c28);
        call_virtual<void>(A804b1788->music.get(), 0x40, arg(A804aa83c), &A803f3328);
        if (A804aaabc->mode == kModeDemo) {
            if (A804aa858) A802644a8(self.get(), A803caf0c);
            const Vector3 position = {A803caf2c, A803caf2c, A803caf30};
            const Vector3 up = {A803caf2c, A803caf30, A803caf2c};
            const Vector3 forward = {A803caf2c, A803caf2c, A803caf34};
            call_virtual<void>(A804b1788->listener.get(), 0x18, &position, &up);
            call_virtual<void>(A804b1788->listener.get(), 0x14, &forward);
        }
    }
    return A80262a58(self.get());
}
}
