// Parte un texto en las líneas de un cuadro según el ancho, cortando por espacios o guiones y sin romper una secuencia UTF-8.
#include "native_game.h"

namespace {
struct TextLine {
    Ptr32<void> owner;   // +0
    w3d_u32 consumed;    // +4
    GameString text;     // +8
    float height;        // +0xc
    w3d_u32 number;      // +0x10
};
struct TextBox {
    char pad[0x28];
    w3d_u32 style;       // +0x28
    char pad2[0x10c - 0x2c];
    float total_height;  // +0x10c
    char pad3[0x150 - 0x110];
    StlWordVector lines; // +0x150
};
const w3d_u32 kFontOffset = 140;
const char kSpace = ' ', kHyphen = '-';
}
extern "C" {
extern const char A803d0f78[], A803d1db8[];
extern const float A803d1ddc, A803d1de0;
w3d_u32 A8015ae3c(void *name);
void A8034435c();
void A8015aee8(w3d_u32 scope);
int A8018b524(void *font, const char *text, float width, float height);
w3d_u32 A801fe1d8(w3d_u32 bytes);
void A803426b8(GameString *string);
void A8020bd38(GameString *string, const char *text);
w3d_u32 A802ef9c0(const char *text);
void A8020c43c(GameString *string, const char *text, w3d_u32 length);
void A8020bf2c(GameString *string, const char *text);
void A80341588(GameString *string);

// 0x8029f714
void A8029f714(Ptr32<TextBox> self, Ptr32<const char> text_ptr, float line_height, float width) {
    void *font = g2h(A8015ae3c(arg(self->style + kFontOffset)));
    A8034435c();
    if (!call_virtual(font, 0x40)) A8015aee8(*at<uint8_t>(call_virtual(font, 0x48)));
    const char *text = text_ptr;
    for (;;) {
        int fits = A8018b524(font, text, width, line_height);
        if (!fits) break;
        TextLine *line = at<TextLine>(A801fe1d8(0x14));
        A803426b8(&line->text);
        line->owner = (void *)nullptr;
        line->consumed = 0;
        A8020bd38(&line->text, A803d0f78);
        line->number = 0;
        line->height = line_height;
        self->lines.push_back(h2g(line));
        line->number = (w3d_u32)self->lines.size();
        const char *const limit = text + fits;
        if (A802ef9c0(text) == (w3d_u32)fits) {
            A8020bd38(&line->text, text);
            line->consumed = fits;
            text = limit;
        } else {
            const char *cut = limit;
            while (cut > text && *cut != kSpace && *cut != kHyphen) cut--;
            GameString piece;
            A803426b8(&piece);
            if (cut == text) {
                // Sin punto de corte: se corta la palabra y se añade un guion.
                if (fits == 1) {
                    A8020c43c(&piece, text, 1);
                    text += 1;
                    line->consumed = 1;
                } else {
                    if (((uint8_t)limit[-1] & 0xc0) == 0x80) {
                        const char *p = limit - 1;
                        do {
                            p--;
                            fits--;
                        } while (((uint8_t)*p & 0xc0) == 0x80);
                    }
                    const w3d_u32 taken = fits - 1;
                    A8020c43c(&piece, text, taken);
                    text += taken;
                    A8020bf2c(&piece, A803d1db8);
                    line->consumed = taken;
                }
            } else {
                const w3d_u32 taken = (w3d_u32)(cut - text);
                A8020c43c(&piece, text, taken);
                if (*cut == kHyphen) A8020bf2c(&piece, A803d1db8);
                line->consumed = taken + 1;
                text = cut + 1;
            }
            line->text.assign(piece);
            A80341588(&piece);
        }
        if (!*text) break;
    }
    self->total_height = A803d1de0;
    for (const Ptr32<w3d_u32> *entry = (const Ptr32<w3d_u32> *)self->lines.begin.get(); (const void *)entry != self->lines.end.get(); entry++) {
        self->total_height += ((const TextLine *)entry->get())->height;
    }
}
}
