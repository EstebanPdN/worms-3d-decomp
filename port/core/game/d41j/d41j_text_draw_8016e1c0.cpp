#include "w3d_ptr.h"
#line 1 "d41j_text_draw_8016e1c0.cpp"
// Text drawing, GWMP8P rev0 0x8016e1c0. With x == -1 it splits the string into
// centred lines (at newlines, and at spaces when the next word would pass the
// frame buffer width less 64), lays them out around the screen centre at 32
// pixels per line and draws each, showing '$' as a space. Otherwise it draws the
// string in one run at (x, y). Returns the width of the last run drawn. Field and
// type names are inferred; the line table size is a partial view.
extern "C" {
Ptr32<const char> next_char_802fd9c4(Ptr32<const char>, Ptr32<int>, Ptr32<int>, Ptr32<int>, Ptr32<int>);
}
struct Line { int x, y, width, count; Ptr32<const char> text; };
struct Mode { int r0; unsigned short fb_width, efb_height; };
struct Gx { char p[40]; Ptr32<Mode> mode; };
extern Ptr32<Gx> gx_804b1888;
struct Text { char p0[388]; Line lines[8]; int line_count;
};
extern "C" Ptr32<Line> append_8016e908(Ptr32<Text>);
extern "C" void glyph_8016e09c(Ptr32<Text>, int);
extern "C" void quad_8016dfcc(Ptr32<Text>, int, int, int, int);
extern "C" int w3d_d41j_text_draw_8016e1c0(Ptr32<Text> self, int x, int y, Ptr32<const char> s) {
  int total = 0;
  bool centred = false;
  int code, u, v, adv;
  if (x == -1) {
    self->line_count = 0;
    Ptr32<const char> p = s;
    Ptr32<Line> line = append_8016e908(self);
    line->text = s;
    int limit = gx_804b1888->mode->fb_width - 64;
    while (*p) {
      Ptr32<const char> next;
      if ((signed char)*p == '\n') {
        line = append_8016e908(self);
        line->text = p + 1;
        next = p + 1;
        line->y += 32;
      } else {
        bool fits = true;
        next = p + 1;
        if ((signed char)*p == ' ') {
          int w = 0;
          Ptr32<const char> q = next;
          while ((signed char)*q != ' ' && (signed char)*q != 0 && (signed char)*q != '\n' && (signed char)*q != 0) {
            next_char_802fd9c4(q, &code, &u, &v, &adv);
            q++;
            w += adv;
          }
          if (line->width + w > limit) {
            fits = false;
            line = append_8016e908(self);
            line->text = next;
            line->y += 32;
          }
        }
        if (fits) {
          next_char_802fd9c4(p, &code, &u, &v, &adv);
          line->count++;
          line->width += adv;
        }
      }
      p = next;
    }
    centred = true;
    for (unsigned i = 0; i < (unsigned)self->line_count; i++) {
      Ptr32<Line> l = &self->lines[i];
      l->x = (gx_804b1888->mode->fb_width >> 1) - l->width / 2;
    }
    unsigned n = self->line_count;
    int h = (int)((float)(int)n * 0.5f * 32.0f);
    int yy = gx_804b1888->mode->efb_height >> 1; yy -= h;
    for (unsigned i = 0; i < (unsigned)self->line_count; i++) {
      self->lines[i].y = yy; yy += 32;
    }
  }
  char space = ' ';
  if (centred) {
    for (int i = 0; i < self->line_count; i++) {
      Ptr32<Line> l = &self->lines[i];
      total = 0;
      for (int j = 0; j < l->count; j++) {
        if (l->text[j] == '$') next_char_802fd9c4(&space, &code, &u, &v, &adv);
        else next_char_802fd9c4(l->text + j, &code, &u, &v, &adv);
        glyph_8016e09c(self, code);
        quad_8016dfcc(self, l->x + total, l->y, u, v);
        total += adv;
      }
    }
  } else {
    Ptr32<const char> p = s;
    while (*p) {
      p = next_char_802fd9c4(p, &code, &u, &v, &adv);
      glyph_8016e09c(self, code);
      quad_8016dfcc(self, x + total, y, u, v);
      total += adv;
    }
  }
  return total;
}


