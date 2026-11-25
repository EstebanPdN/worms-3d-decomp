// GWMP8P rev0 0x80289290. Memory card message page: resets any previous
// record, wraps the title into line records, then creates or refreshes a
// FE.Font text box for each title line and for each record entry, splitting
// an entry onto a shared extra box at its first newline, and finally sizes
// the page and sets up its border and navigation. Built with -mps-float.
// Names are inferred; the unit owns its literal pool from 0x803cfa00.
struct Vec3 { float x, y, z; void Set(float a, float b, float c) { Vec3 *p = this; x = a; p->y = b; p->z = c; } };
struct Colour { signed char r, g, b, a; void Set(int x, int y, int z, int w) { Colour *p = this; r = x; p->g = y; p->b = z; p->a = w; } };
struct Font;
struct FontVt { void *u[3]; void (*addref)(Font *); void (*release)(Font *); void *u20[14]; void (*place)(Font *, const Vec3 *, int); void *u80; void (*scale)(Font *, const Vec3 *, int); };
struct Font { FontVt *vt; };
struct FontRef {
    Font *p;
    FontRef() { p = 0; }
    FontRef(const FontRef &);
    ~FontRef() { if (p) p->vt->release(p); }
    operator Font *() const { return p; }
    Font *operator->() const { return p; }
    void operator=(Font *f) { if (f) f->vt->addref(f); if (p) p->vt->release(p); p = f; }
};
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    void *p;
    String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct Key { const char *text; };
struct Line { float x, y, width; int count; const unsigned char *text; };
struct Entry { Key key; int value; };
struct Record { int u0; Key title; unsigned count; int u12; Entry items[1]; };
struct Card {
    char u0[712];
    Line lines[8];
    FontRef boxes[8];
    FontRef extra[5];
    FontRef last;
    int lastIndex;
    char u932[956 - 932];
    unsigned lineCount;
    unsigned extraCount;
    char u964[968 - 964];
    Record *record;
    char u972[1000 - 972];
    float height, tall, width;
    float timer;
    unsigned flags;
};
extern const char lbl_803cf9f4[];
extern const float lbl_803cf9fc[];
extern int lbl_804abb5c;
extern void *lbl_804aaabc;
extern "C" int w3d_handle_load_8015adf4(const String *, FontRef *, int);
extern "C" Font *fn_80343580(Font *);
extern "C" int fn_8018c5b0(Font *, const char *);
extern "C" int fn_8018d35c(Font *, const Colour *);
extern "C" int fn_8018d434(Font *, const Colour *);
extern "C" void fn_80289914(Card *);
extern "C" void fn_8006ee88(void *, int);
extern "C" int fn_800fc2b0(const Key *, const char **);
extern "C" void fn_80289a34(Card *, const char *, int);
extern "C" void fn_8028a1c0(Card *, char *, const char *);
extern "C" int fn_8028a2b0(Card *, char *, char *);
extern "C" void fn_8028a784(Card *);
extern "C" void fn_80289a08(Card *);
// Loads a font by name into a retained handle.
inline void Into(FontRef &dst, const String &name, int id) { FontRef found; w3d_handle_load_8015adf4(&name, &found, id); dst = fn_80343580(found.p); }
extern "C" void d35f_card_build_text_boxes_80289290(Card *self, Record *record) {
    if (self->record)
        fn_80289914(self);
    fn_8006ee88(lbl_804aaabc, 0);
    lbl_804abb5c++;
    self->flags |= 0x08000000;
    float size = lbl_803cf9fc[0];
    Vec3 scale;
    scale.Set(size, size, 0.0f);
    const char *text;
    fn_800fc2b0(&record->title, &text);
    self->record = record;
    fn_80289a34(self, text, 52);
    Vec3 pos;
    pos.Set(0.0f, 0.0f, 0.0f);
    unsigned n = record->count;
    Colour white;
    white.Set(-1, -1, -1, 0);
    Colour black;
    black.Set(0, 0, 0, 0);
    char copy[128], line[128], second[128];
    float base = (float)(n + 1) * 0.5f * 23.0f;
    copy[0] = 0; line[0] = 0; second[0] = 0;
    self->extraCount = n;
    for (unsigned i = 0; i < self->lineCount; i++) {
        if (!self->boxes[i]) {
            String name(lbl_803cf9f4);
            Into(self->boxes[i], name, 52);
        }
        Line *l = &self->lines[i];
        int k;
        for (k = 0; k < l->count; k++) {
            unsigned char c = l->text[k];
            if (c == '$') copy[k] = ' ';
            else copy[k] = c;
        }
        copy[k] = 0;
        pos.y = l->y + base;
        fn_8028a1c0(self, line, copy);
        { Font *b = self->boxes[i]; b->vt->scale(b, &scale, 0); }
        fn_8018c5b0(self->boxes[i], line);
        { Font *b = self->boxes[i]; b->vt->place(b, &pos, 0); }
        fn_8018d35c(self->boxes[i], &white);
        fn_8018d434(self->boxes[i], &black);
    }
    if (self->extraCount) self->height = 11.5f; else self->height = 23.0f;
    pos.y -= 23.0f;
    int any = 0;
    for (unsigned j = 0; j < self->extraCount; j++) {
        int split = 0;
        if (!self->extra[j]) {
            String name(lbl_803cf9f4);
            Into(self->extra[j], name, 52);
        }
        pos.y -= 23.0f;
        fn_800fc2b0(&record->items[j].key, &text);
        fn_8028a1c0(self, line, text);
        if (fn_8028a2b0(self, second, line)) {
            if (!self->last) {
                String name(lbl_803cf9f4);
                Into(self->last, name, 52);
            }
            split = 1;
            any = 1;
        }
        self->extra[j]->vt->scale(self->extra[j], &scale, 0);
        fn_8018c5b0(self->extra[j], line);
        self->extra[j]->vt->place(self->extra[j], &pos, 0);
        fn_8018d35c(self->extra[j], &white);
        fn_8018d434(self->extra[j], &black);
        if (split) {
            pos.y -= 23.0f;
            self->last->vt->scale(self->last, &scale, 0);
            fn_8018c5b0(self->last, second);
            self->last->vt->place(self->last, &pos, 0);
            fn_8018d35c(self->last, &white);
            fn_8018d434(self->last, &black);
            self->lastIndex = j;
        }
    }
    unsigned total = self->extraCount + self->lineCount + 1;
    if (any) {
        self->height -= 11.5f;
        total++;
    }
    self->tall = 245.0f;
    self->width = (float)total * 23.0f * 0.5f;
    fn_8028a784(self);
    self->timer = 10.0f;
    fn_80289a08(self);
}
