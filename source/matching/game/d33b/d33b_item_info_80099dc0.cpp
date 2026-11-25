// GWMP8P rev0 0x80099dc0. Item information page: real STLport 4.5.3 vector
// of strings.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" void * w3d_string_assign_range_8020bdf4(String *, const char *, int);
extern "C" void w3d_string_format_8020c510(String *, const char *, ...);
extern "C" void w3d_string_truncate_8020c3a0(String *, int);
extern "C" void w3d_string_free_header_8020bb2c(void *);
extern "C" void w3d_line_begin_802cd220(String *);
extern "C" void w3d_line_clear_802cd128(String *);
extern "C" void w3d_line_pos_802cd26c(String *, int, int);
extern "C" void w3d_line_text_802cbf2c(String *, const char *, int);
extern "C" void w3d_line_lines_802cc0ac(String *, const char *, int);
extern "C" void w3d_sink_write_802cbdf8(int, const char *, int);
extern "C" char *w3d_strchr_802ef198(const char *, int);
extern "C" void *w3d_alloc_80212fd4(unsigned);
extern "C" void *w3d_alloc_fallback_803413d8(unsigned);
extern "C" void w3d_free_802134fc(void *);
struct String {
    char *text;
    String();
    String(const char *);
    String(const String &o) { w3d_string_init_8020c5c0(this); text = o.text; ++*w3d_string_header_80341884(this); }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
    void operator=(const String &o) {
        ++((unsigned short *)o.text)[-3];
        char *h = text - 6;
        if (--*(unsigned short *)h == 0) w3d_string_free_header_8020bb2c(h);
        text = o.text;
    }
};
extern "C" void w3d_tagged_construct_8020d318(void *, String *);
extern "C" void w3d_dtor_node_8020d36c(void *, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(void *);
struct Reader;
struct ReaderTable { void *s0[3]; void (*retain)(Reader *); void (*release)(Reader *); };
struct Reader {
    ReaderTable *vt;
    unsigned words[6];
    Reader(String &t) { w3d_tagged_construct_8020d318(this, &t); }
    ~Reader() { w3d_dtor_node_8020d36c(this, 2); }
};
struct Descriptor {
    Reader *p;
    unsigned type : 7;
    unsigned flag : 1;
    unsigned size : 8;
    unsigned format : 5;
    unsigned tail : 11;
    Descriptor(const Descriptor &);
    Descriptor(Reader &r) : p(&r) {
        if (p) p->vt->retain(p);
        type = 10;
        flag = 0;
        size = 0;
        format = 6;
        w3d_registry_retain_8020d2b8(&r);
    }
    ~Descriptor() { if (p) p->vt->release(p); }
};
struct TextStream {
    Reader reader;
    Descriptor descriptor;
    TextStream(String &t) : reader(t), descriptor(reader) {}
};
struct Item {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual const char *Desc();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual int Locked();
    virtual const String *Name();
    virtual unsigned char *Bytes();
    virtual void v17();
    virtual int Count();
    virtual void *First();
    virtual struct Text *Next(void **);
};
struct Text { virtual void v0(); };
struct Menu {
    char unknown00[32]; void *sink; int mode; int state; char unknown44[4]; int selected; int offset; char unknown56[8];
    Item **begin;
    Item *At(unsigned i) { return *(Item **)((char *)begin + (i << 2)); }
};
struct TextTarget { char pad[68]; };
extern const char *lbl_803f4bd0[];
extern char lbl_8037ff9c[];
extern const char *lbl_804aabd0;
extern "C" void w3d_text_read_00000000(void *, Descriptor *);
extern "C" void d33b_item_info_80099dc0(Menu *self) {
    String line;
    w3d_line_begin_802cd220(&line);
    w3d_line_clear_802cd128(&line);
    for (int i = 0; lbl_803f4bd0[i]; ) w3d_line_text_802cbf2c(&line, lbl_803f4bd0[i++], 7);
    String a;
    String b;
    w3d_string_format_8020c510(&a, lbl_8037ff9c, self->offset);
    w3d_string_format_8020c510(&b, lbl_8037ff9c, self->At(self->selected)->Count());
    w3d_line_pos_802cd26c(&line, 19, 0);
    w3d_line_lines_802cc0ac(&line, self->At(self->selected)->Name()->text, 9);
    w3d_line_pos_802cd26c(&line, 19, 1);
    w3d_line_lines_802cc0ac(&line, self->At(self->selected)->Desc(), 9);
    w3d_line_pos_802cd26c(&line, 19, 2);
    w3d_line_lines_802cc0ac(&line, b.text, 9);
    w3d_line_pos_802cd26c(&line, 19, 3);
    w3d_line_lines_802cc0ac(&line, a.text, 9);
    w3d_line_pos_802cd26c(&line, 0, 5);
    void *cursor = self->At(self->selected)->First();
    int i = self->offset;
    Text *text = self->At(self->selected)->Next(&cursor);
    for (; i != 0; i--) text = self->At(self->selected)->Next(&cursor);
    String all;
    TextStream stream(all);
    ((void (**)(Text *, Descriptor *))*(void ***)text)[17](text, &stream.descriptor);
    _STL::vector<String> rows;
    unsigned at = 0;
    while (at < all.Length()) {
        const char *from = all.text + at;
        char *nl = w3d_strchr_802ef198(from, 10);
        if (!nl) {
            rows.push_back(String(from));
            break;
        }
        String s;
        w3d_string_assign_range_8020bdf4(&s, from, nl - from);
        rows.push_back(s);
        at++;
        at += s.Length();
    }
    _STL::vector<String>::iterator r, e;
    for (r = rows.begin(), e = rows.end(); r != e; r++) {
        char *q = w3d_strchr_802ef198(r->text, 92);
        if (q) {
            for (;;) { char *m = w3d_strchr_802ef198(q, 92); if (m) q = m + 1; else break; }
            if (q) { String s(q); *r = s; }
        }
    }
    for (r = rows.begin(), e = rows.end(); r != e; r++) {
        char *q = w3d_strchr_802ef198(r->text, 43);
        if (q) w3d_string_truncate_8020c3a0(r, q - r->text);
    }
    unsigned n = 0;
    r = rows.begin();
    for (e = rows.end(); r != e; r++) {
        char *q = w3d_strchr_802ef198(r->text, 58);
        String s;
        w3d_string_assign_range_8020bdf4(&s, r->text, q - r->text);
        w3d_line_lines_802cc0ac(&line, s.text, 9);
        if (n++ <= 4) w3d_line_text_802cbf2c(&line, q, 9);
        else w3d_line_text_802cbf2c(&line, q, 7);
    }
    w3d_line_pos_802cd26c(&line, 0, 24);
    w3d_line_lines_802cc0ac(&line, lbl_804aabd0, 9);
    w3d_sink_write_802cbdf8((int)self->sink, line.text, 9);
    self->state = 3;
    self->mode = 0;
}
