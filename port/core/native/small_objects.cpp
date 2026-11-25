// Constructores y preparaciones de objetos pequeños, cada uno con su comentario.
#include "native_game.h"

namespace {
// 0x800a5fdc: componente de control de la cámara libre.
struct FreeCameraComponent {
    w3d_u32 table;
    char pad[0x1c - 4];
    w3d_u32 velocity[5];       // +0x1c
    char pad2[0x38 - 0x30];
    float position[3];         // +0x38
    float target[3];           // +0x44
    float yaw, pitch;          // +0x50
    float roll, range;         // +0x58
    w3d_u32 flags;             // +0x60
    w3d_u32 timer;             // +0x64
    w3d_u32 clear[5];          // +0x68
    char pad3[0x84 - 0x7c];
    int buttons[8];            // +0x84
    char pad4[0xac - 0xa4];
    w3d_u32 state_a, state_b;  // +0xac
};
}
extern "C" {
extern w3d_u32 A8040f628;
extern const float A803812a8, A803812ac, A803812b0, A803812b4;
extern Ptr32<void> A804aac54;
w3d_u32 A801628b0(void *self);
void A800a7ee4(void *self);

Ptr32<FreeCameraComponent> A800a5fdc(Ptr32<FreeCameraComponent> self) {
    A801628b0(self.get());
    self->table = h2g(&A8040f628);
    for (w3d_u32 &value : self->velocity) value = 0;
    self->yaw = A803812a8;
    self->pitch = A803812ac;
    self->range = (float)(A803812b4 - A803812b0);
    self->flags = ((self->flags & 0x7fffffffu | 0x40000000u) & 0xc0ffffffu | 0x400000u) & 0xff7fffffu;
    for (w3d_u32 &value : self->clear) value = 0;
    for (float &value : self->position) *(w3d_u32 *)&value = 0;
    for (float &value : self->target) value = A803812a8;
    self->roll = A803812b0;
    self->timer = 0;
    for (int &button : self->buttons) button = -1;
    A800a7ee4(self.get());
    A804aac54 = self;
    self->state_b = 0;
    self->state_a = 0;
    return self;
}
}

namespace {
// 0x800f8804: mensajes que escucha la consola de chat, por identificador.
struct ChatConsole {
    char pad[0x19c];
    Ptr32<uint16_t> extra_begin, extra_end;  // +0x19c
    char pad2[0x1b4 - 0x1a4];
    Ptr32<uint16_t> messages;  // +0x1b4
    w3d_u32 message_count;     // +0x1b8
};
const int kChatMessages = 5;
}
extern "C" {
extern Ptr32<const char> A804aaf4c[];
extern const char A8038cae8[], A8038caf8[], A8038cb0c[], A8038cb20[], A8038cb2c[];
void A80346ef0(void *vector, void *at, w3d_u32 count, const uint16_t *value);
void A80161f54(const char *name, void *id);
void A802ede44(void *items, int count, w3d_u32 size, void *compare);
w3d_u32 A801fe220(w3d_u32 bytes);
void A800f87f4();

// Con mensajes extra en la tabla, el original no avanza el índice y no terminaría; la tabla está vacía en toda la partida.
void A800f8804(Ptr32<ChatConsole> self) {
    w3d_u32 count = 0;
    while (A804aaf4c[count]) count++;
    const w3d_u32 used = (w3d_u32)(self->extra_end - self->extra_begin);
    const uint16_t zero = 0;
    if (count < used) self->extra_end = self->extra_begin + (long)count;
    else A80346ef0(&self->extra_begin, self->extra_end.get(), count - used, &zero);
    for (w3d_u32 i = 0; i < count; i++) A80161f54(A804aaf4c[i], &self->extra_begin[i]);
    A802ede44(self->extra_begin.get(), self->extra_end - self->extra_begin, 2, (void *)A800f87f4);
    self->message_count = kChatMessages;
    self->messages.v = A801fe220(kChatMessages * 2);
    const char *const names[kChatMessages] = {A8038cae8, A8038caf8, A8038cb0c, A8038cb20, A8038cb2c};
    for (int i = 0; i < kChatMessages; i++) A80161f54(names[i], &self->messages[i]);
}
}

namespace {
// 0x8011a1c8: dos recursos de mira con nombre fijo.
struct AimMarkers { char pad[0x1c]; Ptr32<void> first, second; };
}
extern "C" {
extern const char A8039adb4[], A8039adbc[];
void A8020bb54(GameString *string, const char *text);
void A80341588(GameString *string);
void A8015adf4(GameString *name, void *out, w3d_u32 kind);
void A80343580();

void A8011a1c8(Ptr32<AimMarkers> self) {
    release_if_set(self->first.get());
    self->first = (void *)nullptr;
    release_if_set(self->second.get());
    self->second = (void *)nullptr;
    GameString name;
    A8020bb54(&name, A8039adb4);
    Ptr32<void> found{(void *)nullptr};
    A8015adf4(&name, &found, 0x3a);
    A80343580();
    if (found) add_reference(found.get());
    release_if_set(self->first.get());
    self->first = found;
    release_if_set(found.get());
    A80341588(&name);
    A8020bb54(&name, A8039adbc);
    A8015adf4(&name, &self->second, 0x38);
    A80341588(&name);
}
}

namespace {
// 0x80165924: lista de asas con centinela, enganchada al servicio de mensajes.
struct ListNode { Ptr32<ListNode> next, previous; };
struct MessageWatcher {
    w3d_u32 table;
    uint16_t a, b;              // +4
    w3d_u32 mode;               // +8
    w3d_u32 c, d;               // +0xc
    Ptr32<void> handler;        // +0x14
    w3d_u32 pad;
    Ptr32<ListNode> nodes;      // +0x1c
};
}
extern "C" {
extern w3d_u32 A80411a30;
extern char A804191b0, A803a4ba0, A804119f0;
w3d_u32 A803413d8(w3d_u32 bytes);
w3d_u32 A8020b648();

Ptr32<MessageWatcher> A80165924(Ptr32<MessageWatcher> self) {
    self->mode = 2;
    self->c = self->d = 0;
    self->a = self->b = 0;
    self->table = h2g(&A80411a30);
    self->handler = (void *)nullptr;
    self->nodes = (ListNode *)nullptr;
    w3d_u32 block = A80212fd4(0x30);
    if (!block) block = A803413d8(0x30);
    ListNode *sentinel = at<ListNode>(block);
    sentinel->next = sentinel;
    sentinel->previous = sentinel;
    self->nodes = sentinel;
    void *services = g2h(call_virtual(g2h(A8020b648()), 0x5c, &A804191b0));
    Ptr32<void> handler{(void *)nullptr};
    if (void *existing = g2h(call_virtual(services, 0x14, &A803a4ba0))) call_virtual<void>(existing, 8, &A804119f0, &handler);
    void *chosen = handler;
    if (chosen) add_reference(chosen);
    else if ((chosen = g2h(call_virtual(services, 0x30, &A803a4ba0)))) add_reference(chosen);
    release_if_set(self->handler.get());
    self->handler = chosen;
    release_if_set(handler.get());
    return self;
}
}

namespace {
// 0x8028a570: tarjeta de memoria: prepara el comando de inserción, pide tarjeta y formato si hace falta, y deja los búferes listos.
struct CardBlock { char pad[0x24]; w3d_u32 sector_size; };
struct CardCommand { w3d_u32 buffer; w3d_u32 error; char pad[8]; Ptr32<CardBlock> block; w3d_u32 mounted; };
struct MemoryCard {
    char pad[0x78];
    CardCommand command;   // +0x78
    w3d_u32 a;             // +0x90
    char pad2[0x9c - 0x94];
    w3d_u32 b;             // +0x9c
    char pad3[0xac - 0xa0];
    w3d_u32 c, d;          // +0xac
    char pad4[0xb8 - 0xb4];
    w3d_u32 e;             // +0xb8
    char pad5[0x120 - 0xbc];
    w3d_u32 f;             // +0x120
    char pad6[0x218 - 0x124];
    w3d_u32 g, h;          // +0x218
    char pad7[0x224 - 0x220];
    w3d_u32 i;             // +0x224
};
const int kBusy = -1, kNoSpace = -34, kNeedsFormat = -37;
const w3d_u32 kErrorBusy = 161;
}
extern "C" {
extern const char A803cfb34[];
void A802aba18(void *command, w3d_u32 mode);
void A802aba0c(void *command);
int A802aba68(void *command, w3d_u32 wait);
void A80289eec(void *card, w3d_u32 bytes);
w3d_u32 A800fc230(void *key, void *out, ...);

w3d_u32 A8028a570(Ptr32<MemoryCard> self) {
    A802aba18(&self->command, 1);
    A802aba0c(&self->command);
    bool present = false;
    while (self->command.mounted) {
        const int status = A802aba68(&self->command, 0);
        if (status == kBusy) continue;
        present = status == 1;
        break;
    }
    if (present) {
        A802aba18(&self->command, 2);
        A802aba0c(&self->command);
        while (self->command.mounted) {
            const int status = A802aba68(&self->command, 1);
            if (status == kBusy) {
                if (self->command.error == kErrorBusy) break;
                continue;
            }
            if (status == kNoSpace) continue;
            if (status == kNeedsFormat) A80289eec(self.get(), self->command.block->sector_size + 8268);
            break;
        }
    }
    const w3d_u32 buffer = self->command.buffer, block = self->command.block.v;
    self->command.mounted = 0;
    self->b = 0xb0;
    self->e = 0xd0;
    self->i = 0xc0;
    self->g = buffer;
    self->h = block;
    self->a = buffer;
    self->c = buffer;
    self->f = 0;
    self->d = block;
    Ptr32<const char> key(A803cfb34);
    w3d_u32 retries = 10;
    return ((w3d_u32 (*)(void *, void *))A800fc230)(&key, &retries);
}
}

namespace {
// 0x802bce10: elemento de lista de menú.
struct ListElement {
    int selected;              // +0
    uint8_t highlighted;       // +4
    char pad[3];
    float fade;                // +8
    w3d_u32 a, b, c;           // +0xc
    float position, length;    // +0x18
    w3d_u32 alignment;         // +0x20
    float width;               // +0x24
    w3d_u32 colour[3];         // +0x28
    float height;              // +0x34
    char pad2[4];
    float scale_y, scale_x;    // +0x3c
    w3d_u32 d;                 // +0x44
    Ptr32<void> text;          // +0x48
    w3d_u32 pad3;
    w3d_u32 e, f;              // +0x50
    w3d_u32 pad4;
    w3d_u32 g;                 // +0x5c
    w3d_u32 h, i, j, k, l, m, n, q; // +0x60
    w3d_u32 enabled;           // +0x80
    w3d_u32 o, p;              // +0x84
};
}
extern "C" {
extern const float A803d8344, A803d8348, A803d834c, A803d8350;
extern w3d_u32 A8045e788[3];
extern const char A803d8328[];
w3d_u32 A800fc1b0(void *key, void *out, ...);
w3d_u32 A80342a78(void *found);
w3d_u32 A80178d1c(void *text);

Ptr32<ListElement> A802bce10(Ptr32<ListElement> self) {
    self->d = 0;
    self->text = (void *)nullptr;
    self->e = self->f = self->g = 0;
    self->h = self->i = self->j = self->k = self->l = self->m = self->n = self->q = 0;
    self->selected = -1;
    self->height = A803d8344;
    self->scale_x = self->scale_y = A803d8348;
    self->width = A803d834c;
    self->fade = A803d8350;
    self->a = self->b = self->c = self->o = 0;
    self->alignment = 3;
    for (int i = 0; i < 3; i++) self->colour[i] = A8045e788[i];
    self->enabled = 1;
    self->highlighted = 0;
    self->p = 0;
    Ptr32<const char> key(A803d8328);
    Ptr32<void> found{(void *)nullptr};
    ((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, &found);
    void *text = g2h(A80342a78(found.get()));
    if (text) add_reference(text);
    release_if_set(self->text.get());
    self->text = text;
    self->position = self->length = (float)A80178d1c(text);
    release_if_set(found.get());
    return self;
}
}
