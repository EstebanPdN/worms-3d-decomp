#include "w3d_ptr.h"
#line 1 "d33b_item_info_80099dc0.cpp"
// GWMP8P rev0 0x80099dc0. Item information page: real STLport 4.5.3 vector
// of strings.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" Ptr32<void> w3d_string_assign_range_8020bdf4(Ptr32<String>, Ptr32<const char>, int);
extern "C" void w3d_string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_truncate_8020c3a0(Ptr32<String>, int);
extern "C" void w3d_string_free_header_8020bb2c(Ptr32<void>);
extern "C" void w3d_line_begin_802cd220(Ptr32<String>);
extern "C" void w3d_line_clear_802cd128(Ptr32<String>);
extern "C" void w3d_line_pos_802cd26c(Ptr32<String>, int, int);
extern "C" void w3d_line_text_802cbf2c(Ptr32<String>, Ptr32<const char>, int);
extern "C" void w3d_line_lines_802cc0ac(Ptr32<String>, Ptr32<const char>, int);
extern "C" void w3d_sink_write_802cbdf8(int, Ptr32<const char>, int);
extern "C" Ptr32<char> w3d_strchr_802ef198(Ptr32<const char>, int);
extern "C" Ptr32<void> w3d_alloc_80212fd4(unsigned);
extern "C" Ptr32<void> w3d_alloc_fallback_803413d8(unsigned);
extern "C" void w3d_free_802134fc(Ptr32<void>);
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &o) { w3d_string_init_8020c5c0(this); text = o.text; ++*w3d_string_header_80341884(this); }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
    void operator=(const String &o) {
        ++((Ptr32<unsigned short>)o.text)[-3];
        Ptr32<char> h = text - 6;
        if (--*(Ptr32<unsigned short>)h == 0) w3d_string_free_header_8020bb2c(h);
        text = o.text;
    }
};
extern "C" void w3d_tagged_construct_8020d318(Ptr32<void>, Ptr32<String>);
extern "C" void w3d_dtor_node_8020d36c(Ptr32<void>, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(Ptr32<void>);
struct Reader;
struct ReaderTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Reader>)> retain; Ptr32<void (Ptr32<Reader>)> release; };
struct Reader {
    Ptr32<ReaderTable> vt;
    unsigned words[6];
    Reader(String &t) { w3d_tagged_construct_8020d318(this, &t); }
    ~Reader() { w3d_dtor_node_8020d36c(this, 2); }
};
struct Descriptor {
    Ptr32<Reader> p;
    unsigned int tail:11; unsigned int format:5; unsigned int size:8; unsigned int flag:1; unsigned int type:7;
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
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Item2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Item2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Item2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Item2v3Ev"));
    void w3d_r_v4() __asm__(W3D_SYM("_ZN4Item2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN4Item2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN4Item2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN4Item2v7Ev"));
    Ptr32<const char> w3d_r_Desc() __asm__(W3D_SYM("_ZN4Item4DescEv"));
    void w3d_r_v9() __asm__(W3D_SYM("_ZN4Item2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN4Item3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN4Item3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN4Item3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN4Item3v13Ev"));
    int w3d_r_Locked() __asm__(W3D_SYM("_ZN4Item6LockedEv"));
    Ptr32<const String> w3d_r_Name() __asm__(W3D_SYM("_ZN4Item4NameEv"));
    Ptr32<unsigned char> w3d_r_Bytes() __asm__(W3D_SYM("_ZN4Item5BytesEv"));
    void w3d_r_v17() __asm__(W3D_SYM("_ZN4Item3v17Ev"));
    int w3d_r_Count() __asm__(W3D_SYM("_ZN4Item5CountEv"));
    Ptr32<void> w3d_r_First() __asm__(W3D_SYM("_ZN4Item5FirstEv"));
    Ptr32<struct Text> w3d_r_Next(Ptr32<Ptr32<void>>) __asm__(W3D_SYM("_ZN4Item4NextEPPv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const char> Desc() { return ((Ptr32<const char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Locked() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const String> Name() { return ((Ptr32<const String> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<unsigned char> Bytes() { return ((Ptr32<unsigned char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Count() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<void> First() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<struct Text> Next(Ptr32<Ptr32<void>> w3d_a0) { return ((Ptr32<struct Text> (*)(w3d_u32, Ptr32<Ptr32<void>>))w3d::vfn(this->w3d_vptr_Item, 22))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Item; };
struct Text { void w3d_r_v0() __asm__(W3D_SYM("_ZN4Text2v0Ev"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Text, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Text; };
struct Menu {
    char unknown00[32]; Ptr32<void> sink; int mode; int state; char unknown44[4]; int selected; int offset; char unknown56[8];
    Ptr32<Ptr32<Item>> begin;
    Ptr32<Item> At(unsigned i) { return *(Ptr32<Ptr32<Item>>)((Ptr32<char>)begin + (i << 2)); }
};
struct TextTarget { char pad[68]; };
extern Ptr32<const char> lbl_803f4bd0[];
extern char lbl_8037ff9c[];
extern Ptr32<const char> lbl_804aabd0;
extern "C" void w3d_text_read_00000000(Ptr32<void>, Ptr32<Descriptor>);
extern "C" void d33b_item_info_80099dc0(Ptr32<Menu> self) {
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
    Ptr32<void> cursor = self->At(self->selected)->First();
    int i = self->offset;
    Ptr32<Text> text = self->At(self->selected)->Next(&cursor);
    for (; i != 0; i--) text = self->At(self->selected)->Next(&cursor);
    String all;
    TextStream stream(all);
    ((Ptr32<Ptr32<void (Ptr32<Text>, Ptr32<Descriptor>)>>)*(Ptr32<Ptr32<Ptr32<void>>>)text)[17](text, &stream.descriptor);
    _STL::vector<String> rows;
    unsigned at = 0;
    while (at < all.Length()) {
        Ptr32<const char> from = all.text + at;
        Ptr32<char> nl = w3d_strchr_802ef198(from, 10);
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
        Ptr32<char> q = w3d_strchr_802ef198(r->text, 92);
        if (q) {
            for (;;) { Ptr32<char> m = w3d_strchr_802ef198(q, 92); if (m) q = m + 1; else break; }
            if (q) { String s(q); *r = s; }
        }
    }
    for (r = rows.begin(), e = rows.end(); r != e; r++) {
        Ptr32<char> q = w3d_strchr_802ef198(r->text, 43);
        if (q) w3d_string_truncate_8020c3a0(r, q - r->text);
    }
    unsigned n = 0;
    r = rows.begin();
    for (e = rows.end(); r != e; r++) {
        Ptr32<char> q = w3d_strchr_802ef198(r->text, 58);
        String s;
        w3d_string_assign_range_8020bdf4(&s, r->text, q - r->text);
        w3d_line_lines_802cc0ac(&line, s.text, 9);
        if (n++ <= 4) w3d_line_text_802cbf2c(&line, q, 9);
        else w3d_line_text_802cbf2c(&line, q, 7);
    }
    w3d_line_pos_802cd26c(&line, 0, 24);
    w3d_line_lines_802cc0ac(&line, lbl_804aabd0, 9);
    w3d_sink_write_802cbdf8((int)w3d::H(self->sink), line.text, 9);
    self->state = 3;
    self->mode = 0;
}


