// Componente de entrada de la cámara libre: reparte los mensajes del ratón y guarda los que llegan mientras se procesa uno.
#include "native_game.h"

namespace {
struct PendingToggle {
    char pad;
    char name[35];       // +1
    w3d_u32 active;      // +0x24
};
static_assert(sizeof(PendingToggle) == 40, "cada aviso ocupa 40 B");
struct ToggleQueue { w3d_u32 pad; OddVector<PendingToggle> pending; };
struct InputComponent {
    char pad[0x60];
    w3d_u32 flags;              // +0x60
    char pad2[0xac - 0x64];
    Ptr32<ToggleQueue> queue;   // +0xac
    char pad3[0xb4 - 0xb0];
    w3d_u32 paused;             // +0xb4
};
const w3d_u32 kEnabled = 0x400000, kHandling = 0x2000000;
const w3d_u32 kFailed = 0x80004005u;
struct InputMessage { uint16_t id; char pad[6]; w3d_u32 key; };
enum { kMessageCreate = 64, kMessageKey = 4096, kMessageMouseMove = 4098, kMessageMouseButton = 4099, kMessageMouseWheel = 4100 };
const w3d_u32 kKeyEscape = 183;
}
extern "C" {
extern Ptr32<void> A804b1788;
extern char A804ae2d0, A804ae2d8;
w3d_u32 A8015ccbc(void *app);
int A8016293c(void *self, void *message);
void A800a6740(void *self);
void A800a6b04(void *self, void *message);
void A800a6c80(void *self, void *message);
void A800a6ff4(void *self, void *message);
void A800a7148(void *self, void *message);
void A800a7964(void *self);
w3d_u32 A8015f65c(w3d_u32 id, void *name);
w3d_u32 A8010a8fc(void *message);
void A802ef2fc(char *to, const char *from);
void A800a76a4(void *self, void *name, w3d_u32 active);

static void set_toggle(InputComponent *self, InputMessage *message, w3d_u32 active) {
    if (self->flags & kHandling) {
        PendingToggle pending = {};
        A802ef2fc(pending.name, (const char *)g2h(A8010a8fc(message)));
        pending.active = active;
        self->queue->pending.push_back(pending);
    } else {
        A800a76a4(self, g2h(A8010a8fc(message)), active);
    }
}
// 0x800a6238
w3d_u32 A800a6238(Ptr32<InputComponent> self, Ptr32<InputMessage> message) {
    self->paused = A8015ccbc(A804b1788.get());
    void (*handler)(void *, void *) = nullptr;
    switch (message->id) {
    case kMessageCreate:
        if (A8016293c(self.get(), message.get()) < 0) return kFailed;
        A800a6740(self.get());
        return 0;
    case kMessageKey:
        if (!(self->flags & kEnabled)) return 0;
        if (message->key == kKeyEscape) {
            call_virtual<void>(A804b1788.get(), 0x5c, (void *)0, (void *)0);
            return 0;
        }
        handler = A800a6b04;
        break;
    case kMessageMouseWheel: handler = A800a6c80; break;
    case kMessageMouseMove: handler = A800a6ff4; break;
    case kMessageMouseButton: handler = A800a7148; break;
    }
    if (handler) {
        if (!(self->flags & kEnabled)) return 0;
        self->flags |= kHandling;
        handler(self.get(), message.get());
        self->flags &= ~kHandling;
        A800a7964(self.get());
        return 0;
    }
    if (A8015f65c(message->id, &A804ae2d0)) set_toggle(self, message, 1);
    else if (A8015f65c(message->id, &A804ae2d8)) set_toggle(self, message, 0);
    return (w3d_u32)A8016293c(self.get(), message.get());
}
}
