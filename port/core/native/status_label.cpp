// Etiqueta de varias partes de la interfaz ("a,b,c"): carga una imagen por parte, con el color y la posición del estilo.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
struct LabelStyle {
    char pad[8];
    uint8_t flags;              // +8
    char pad2[0x14 - 9];
    float size_x, size_y;       // +0x14
    char pad3[0x74 - 0x1c];
    float scale;                // +0x74
    char pad4[0x7c - 0x78];
    GameString text;            // +0x7c
};
struct StatusLabel {
    char pad[0x1c];
    char loader[4];             // +0x1c
    uint8_t bank;               // +0x20
    char pad2[0x28 - 0x21];
    Ptr32<LabelStyle> style;    // +0x28
    char pad3[0x6c - 0x2c];
    GameString error;           // +0x6c
    Ptr32<void> canvas;         // +0x70
    char pad4[0xd8 - 0x74];
    w3d_u32 large;              // +0xd8
    char pad5[0xe8 - 0xdc];
    Ptr32<void> slots[3];       // +0xe8
};
const uint8_t kStyleThirdIcon = 4;
const int kParts = 3;
}
extern "C" {
extern const char A803cab9c[], A803cab14[];
extern const float A803caba0, A803caba4;
void A8020c3a0(GameString *string, w3d_u32 length);
w3d_u32 A802ef380(const char *text, const char *stops);
void A8020bd38(GameString *string, const char *text);
void A8025fd78(void *self);
void A8026026c(void *self);
int A802b1510(void *loader, const char *name, void *slot, w3d_u32 bank);
void A8020c510(GameString *string, const char *format, ...);

// 0x802602fc
void A802602fc(Ptr32<StatusLabel> self) {
    LabelStyle *style = self->style;
    GameString rest;
    rest.text = style->text.text;
    rest.header()->references++;
    if (rest.header()->length) {
        ScopedString parts[kParts];
        int count = 0;
        while (rest.header()->length && count < kParts) {
            parts[count].assign(rest);
            const w3d_u32 length = A802ef380(parts[count].text, A803cab9c);
            w3d_u32 consumed = length;
            if (parts[count].text[length] == ',') {
                A8020c3a0(&parts[count], length);
                consumed = length + 1;
            }
            count++;
            A8020bd38(&rest, rest.text.get() + consumed);
        }
        if (count <= 1) {
            A8025fd78(self.get());
        } else {
            for (int i = 0; i < count; i++) {
                const bool large = self->large != 0;
                int status;
                if (i == 1) {
                    status = A802b1510(self->loader, parts[1].text, &self->slots[1], (self->bank + (large ? 30 : 31)) & 0xff);
                } else if (i == 2 && (style->flags & kStyleThirdIcon)) {
                    status = A802b1510(self->loader, parts[2].text, &self->slots[2], (self->bank + 32) & 0xff);
                } else {
                    status = A802b1510(self->loader, parts[i].text, &self->slots[i], (self->bank + (large ? 29 : 31)) & 0xff);
                }
                if (status < 0) {
                    A8020c510(&self->error, A803cab14, rest.text.get());
                    continue;
                }
                call_virtual<void>(self->canvas.get(), 0x5c, self->slots[i].get(), (void *)0);
                if (i == 1) {
                    const float scale = style->scale;
                    if (scale == A803caba0) {
                        call_virtual<void>(self->slots[1].get(), 0x54, &self->style->size_x, (void *)0);
                    } else {
                        const Vector3 size = {(float)(self->style->size_x * scale), (float)(self->style->size_y * scale), A803caba4};
                        call_virtual<void>(self->slots[1].get(), 0x54, &size, (void *)0);
                    }
                } else {
                    call_virtual<void>(self->slots[i].get(), 0x54, &self->style->size_x, (void *)0);
                }
                call_virtual<void>(self->slots[i].get(), 0x58, (void *)0);
            }
            A8026026c(self.get());
        }
    }
    A80341588(&rest);
}
}
