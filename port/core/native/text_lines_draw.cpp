// Coloca las líneas de un cuadro de texto: alineación, desplazamiento, fundido en los bordes y un nodo de texto por línea visible.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
struct Rgba { uint8_t r, g, b, a; };
struct TextStyle {
    char pad[0x28];
    float depth;              // +0x28
    char pad2[0x74 - 0x2c];
    Rgba colour;              // +0x74
    char pad3[0x7c - 0x78];
    w3d_u32 alignment;        // +0x7c
    w3d_u32 pad4;
    GameString colour_name;   // +0x84
    char pad5[0x8c - 0x88];
    GameString font;          // +0x8c
};
struct TextLine {
    Ptr32<void> node;         // +0
    w3d_u32 pad;
    Ptr32<const char> text;   // +8
    w3d_u32 pad2;
    w3d_u32 number;           // +0x10
};
struct Spinner { char pad[0x44]; w3d_u32 snaps; };
struct TextBox {
    char pad[0x20];
    uint8_t bank;             // +0x20
    char pad2[0x28 - 0x21];
    Ptr32<TextStyle> style;   // +0x28
    char pad3[0xd8 - 0x2c];
    uint8_t large;            // +0xd8
    char pad4[0x120 - 0xd9];
    w3d_u32 auto_scroll;      // +0x120
    char pad5[0x134 - 0x124];
    Ptr32<void> canvas;       // +0x134
    char pad6[0x150 - 0x138];
    StlWordVector lines;      // +0x150
    char pad7[0x178 - 0x160];
    Ptr32<Spinner> attached;  // +0x178
    float position;           // +0x17c
};
// El alfa de una línea según lo que sobresale del área visible.
struct FadeArea { float top, bottom, line_height, full, none; };
float line_alpha(const FadeArea &area, float scroll, Vector3 &where) {
    const float y = (float)(where.y + scroll);
    float alpha;
    if (y > area.top) {
        alpha = (float)(area.full - (float)((float)(y - area.top) / area.line_height));
        if (alpha >= area.none && alpha <= area.full) where.y = (float)(where.y - (float)(area.line_height - (float)(area.line_height * alpha)));
    } else if (y < area.bottom) {
        alpha = (float)(area.full - (float)((float)(area.bottom - y) / area.line_height));
    } else {
        alpha = area.full;
    }
    return alpha > area.full ? area.full : alpha;
}
inline uint8_t alpha_byte(float value) {
    if (value != value || value <= 0) return 0;
    if (value >= 255) return 255;
    return (uint8_t)value;
}
const uint8_t kAlignXMask = 0xc, kAlignYMask = 3;
}
extern "C" {
extern const w3d_u32 A80401c50[];
extern const char A803d1e5c[];
extern const float A803d1e70, A803d1e74, A803d1e80, A803d1e84, A803d1e88, A803d1e8c, A803d1e90, A803d1e94;
void A8020bb54(GameString *string, const char *text);
w3d_u32 A800fc370(void *key, void *out, ...);
void A8015adf4(GameString *name, void *out, w3d_u32 kind);
void A80343580();
void A8018c5b0(void *node, const char *text);
void A8018d324(void *node, w3d_u32 alignment);
void A8018d35c(void *node, const void *colour);
void A8018d434(void *node, const void *colour);

static void hide_line(TextBox *self, TextLine *line) {
    if (!line->node) return;
    call_virtual<void>(self->canvas.get(), 0x60, line->node.get());
    release_reference(line->node.get());
    line->node = (void *)nullptr;
}
static void show_line(TextBox *self, TextLine *line) {
    if (line->node) return;
    Ptr32<void> font{(void *)nullptr};
    A8015adf4(&self->style->font, &font, (self->bank + self->large + 30) & 0xff);
    A80343580();
    if (font) add_reference(font.get());
    release_if_set(line->node.get());
    line->node = font;
    call_virtual<void>(self->canvas.get(), 0x5c, line->node.get(), (void *)0);
    A8018c5b0(line->node.get(), line->text.get());
    release_if_set(font.get());
}
// El color del estilo manda; el ajuste con nombre se lee igual, como en el original.
static Rgba read_colours(TextStyle *style, ScopedString &name) {
    if (style->colour_name.header()->length) name.assign(style->colour_name);
    Ptr32<char> key = name.text;
    Rgba colour;
    ((w3d_u32 (*)(void *, void *))A800fc370)(&key, &colour);
    return style->colour;
}
static inline float horizontal(w3d_u32 alignment, float width, float half, float centre) {
    switch (alignment & kAlignXMask) {
    case 4: return (float)(centre - (float)(width * half));
    case 8: return (float)(width * half);
    default: return centre;
    }
}

// 0x802a06ac: en reposo la alineación vertical viene del estilo; con desplazamiento, de la posición.
void A802a06ac(Ptr32<TextBox> self, float line_height, float width, float height) {
    TextStyle *style = self->style;
    float top = (float)(height * A803d1e74);
    float bottom = -top;
    const float total = (float)((float)(w3d_u32)self->lines.size() * line_height);
    w3d_u32 alignment = A80401c50[style->alignment];
    Vector3 origin = {A803d1e70, A803d1e70, style->depth};
    if (!self->attached && !self->auto_scroll) {
        switch (alignment & kAlignYMask) {
        case 1:
            origin.y = top;
            bottom = (float)(bottom + line_height);
            break;
        case 0: {
            if (total != A803d1e70) origin.y = (float)((float)(total - line_height) * A803d1e74);
            const float half_line = (float)(line_height * A803d1e74);
            top = (float)(top - half_line);
            bottom = (float)(bottom + half_line);
            break;
        }
        case 2:
            origin.y = (float)((float)(bottom + total) - line_height);
            top = (float)(top - line_height);
            break;
        }
    } else {
        alignment = (alignment & kAlignXMask) + 1;
        bottom = (float)(bottom + line_height);
        origin.y = fused_madd(self->position, line_height, top);
    }
    origin.x = horizontal(alignment, width, A803d1e74, A803d1e70);
    ScopedString colour_name(A803d1e5c);
    Rgba colour = read_colours(style, colour_name);
    Rgba outline = {0, 0, 0, 0xff};
    Vector3 cursor = {A803d1e70, A803d1e70, style->depth};
    const FadeArea area = {top, bottom, line_height, A803d1e80, A803d1e70};
    for (const w3d_u32 *entry = self->lines.begin.get(); entry != self->lines.end.get(); entry++) {
        TextLine *line = at<TextLine>(*entry);
        Vector3 where = cursor;
        const float alpha = line_alpha(area, origin.y, where);
        if (alpha <= A803d1e70) {
            hide_line(self, line);
        } else {
            show_line(self, line);
            A8018d324(line->node.get(), alignment);
            call_virtual<void>(line->node.get(), 0x4c, &where, (void *)0);
            colour.a = alpha_byte((float)(alpha * A803d1e84));
            outline.a = alpha_byte((float)(alpha * A803d1e84));
            A8018d35c(line->node.get(), &colour);
            A8018d434(line->node.get(), &outline);
            const Vector3 scale = {line_height, (float)(line_height * alpha), A803d1e80};
            call_virtual<void>(line->node.get(), 0x54, &scale, (void *)0);
        }
        cursor.y = (float)(cursor.y - line_height);
    }
    call_virtual<void>(self->canvas.get(), 0x4c, &origin, (void *)0);
}

// 0x802a0f98: lista desplazable: la línea 0 es un título con otra alineación y un color algo más oscuro.
void A802a0f98(Ptr32<TextBox> self, float line_height, float width, float height) {
    TextStyle *style = self->style;
    const float top = (float)(height * A803d1e8c);
    const float bottom = (float)(-top + line_height);
    const w3d_u32 alignment = (A80401c50[style->alignment] & kAlignXMask) + 1;
    Vector3 origin = {A803d1e88, fused_madd(self->position, line_height, top), style->depth};
    origin.x = horizontal(alignment, width, A803d1e8c, A803d1e88);
    ScopedString colour_name(A803d1e5c);
    Rgba colour = read_colours(style, colour_name);
    Rgba outline = {0, 0, 0, 0xff};
    Vector3 cursor = {A803d1e88, A803d1e88, style->depth};
    const FadeArea area = {top, bottom, line_height, A803d1e90, A803d1e88};
    for (const w3d_u32 *entry = self->lines.begin.get(); entry != self->lines.end.get(); entry++) {
        TextLine *line = at<TextLine>(*entry);
        Vector3 where = cursor;
        const float alpha = line_alpha(area, origin.y, where);
        if (alpha <= A803d1e88) {
            hide_line(self, line);
        } else {
            show_line(self, line);
            if (!line->number) {
                Vector3 title = where;
                if ((alignment & kAlignXMask) == 4) title.x = fused_madd(width, A803d1e8c, title.x);
                if ((alignment & kAlignXMask) == 8) title.x = (float)(title.x - (float)(width * A803d1e8c));
                A8018d324(line->node.get(), alignment & kAlignYMask);
                call_virtual<void>(line->node.get(), 0x4c, &title, (void *)0);
            } else {
                A8018d324(line->node.get(), alignment);
                call_virtual<void>(line->node.get(), 0x4c, &where, (void *)0);
            }
            colour.a = alpha_byte((float)(alpha * A803d1e94));
            outline.a = alpha_byte((float)(alpha * A803d1e94));
            if (!line->number) {
                // El primer byte se calcula con el alfa, no con el rojo: en el anfitrión el original (y core/open) miran la palabra entera.
                Rgba title_colour = colour;
                if (colour.a > 30) title_colour.r = colour.a - 30;
                if (title_colour.g > 30) title_colour.g -= 30;
                if (title_colour.b > 30) title_colour.b -= 30;
                A8018d35c(line->node.get(), &title_colour);
            } else {
                A8018d35c(line->node.get(), &colour);
            }
            A8018d434(line->node.get(), &outline);
            const Vector3 scale = {line_height, (float)(line_height * alpha), A803d1e90};
            call_virtual<void>(line->node.get(), 0x54, &scale, (void *)0);
        }
        cursor.y = (float)(cursor.y - line_height);
    }
    call_virtual<void>(self->canvas.get(), 0x4c, &origin, (void *)0);
}
}
