#include "w3d_ptr.h"
#line 1 "d28b_table_page_draw_800990a4.cpp"
/* Table list page draw (0x800990a4): for each of the 19 rows of the current page (+44 times 19
 * plus the row) either writes the end-of-list text in colour 2, or copies the item name, formats
 * its count and byte value with "%d", picks the Y or N flag, uses colour 7 when the count is not
 * zero and 9 otherwise, and places each field at the column table; name and description are cut
 * to the width table with "..." or padded with blanks. Finishes by positioning at line 24 and
 * writing the line to the sink at +32. Item is a partial view of the original virtual table with
 * 4-byte entries. Field names are inferred from the original instructions; strings and tables
 * are external views of original data. The unit owns no data. */
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" Ptr32<String> w3d_string_assign_8020bd38(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<void> w3d_string_assign_range_8020bdf4(Ptr32<String>, Ptr32<const char>, int);
extern "C" void w3d_string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_truncate_8020c3a0(Ptr32<String>, unsigned);
extern "C" Ptr32<void> w3d_string_append_8020bf2c(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_string_append_range_8020c43c(Ptr32<String>, Ptr32<const char>, unsigned);
extern "C" void w3d_line_pos_802cd26c(Ptr32<String>, int, int);
extern "C" void w3d_line_text_802cbf2c(Ptr32<String>, Ptr32<const char>, int);
extern "C" void w3d_line_lines_802cc0ac(Ptr32<String>, Ptr32<const char>, int);
struct String {
    Ptr32<char> text;
    String();
    String(const String &o) { w3d_string_init_8020c5c0(this); text = o.text; ++*w3d_string_header_80341884(this); }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
extern "C" void w3d_sink_write_802cbdf8(int, Ptr32<const char>, int);
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
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const char> Desc() { return ((Ptr32<const char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Locked() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const String> Name() { return ((Ptr32<const String> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<unsigned char> Bytes() { return ((Ptr32<unsigned char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Count() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 20))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Item; };
struct Menu {
    char unknown00[32]; Ptr32<void> sink; char unknown36[8]; unsigned page; char unknown48[16];
    Ptr32<Ptr32<Item>> begin; Ptr32<Ptr32<Item>> end;
    Ptr32<Item> & At(unsigned i) { return begin[i]; }
};
extern Ptr32<const char> lbl_803f4b90[];
extern int lbl_803f4ba0[];
extern unsigned lbl_803f4bb8[];
extern Ptr32<const char> lbl_804aabc8;
extern Ptr32<const char> lbl_804aabc4;
extern char lbl_8037ff64[], lbl_8037ff6c[], lbl_8037ff00[], lbl_8037ff70[];
extern "C" void w3d_d28b_table_page_draw_800990a4(Ptr32<Menu> self) {
    String line;
    for (unsigned i = 0; i <= 18; i++) {
        unsigned idx = i + self->page * 19;
        if (idx >= (unsigned)(self->end - self->begin)) {
            w3d_line_pos_802cd26c(&line, 0, i + 2);
            w3d_line_text_802cbf2c(&line, lbl_803f4b90[2], 2);
            continue;
        }
        String name(*self->At(idx)->Name());
        String desc;
        String unused;
        String key;
        String count;
        String bytes;
        String flag;
        int color = 9;
        w3d_string_assign_range_8020bdf4(&key, lbl_804aabc8 + i, 1);
        int n = self->At(idx)->Count();
        w3d_string_format_8020c510(&count, lbl_8037ff64, n);
        w3d_string_format_8020c510(&bytes, lbl_8037ff64, *self->At(idx)->Bytes());
        if (self->At(idx)->Locked()) w3d_string_assign_8020bd38(&flag, lbl_8037ff6c);
        else w3d_string_assign_8020bd38(&flag, lbl_8037ff00);
        if (n != 0) color = 7;

        w3d_line_pos_802cd26c(&line, lbl_803f4ba0[3], i + 2);
        w3d_line_lines_802cc0ac(&line, count.text, color);
        w3d_line_pos_802cd26c(&line, lbl_803f4ba0[4], i + 2);
        w3d_line_lines_802cc0ac(&line, bytes.text, color);
        w3d_line_pos_802cd26c(&line, lbl_803f4ba0[5], i + 2);
        w3d_line_lines_802cc0ac(&line, flag.text, color);
        w3d_line_pos_802cd26c(&line, lbl_803f4ba0[0], i + 2);
        w3d_line_lines_802cc0ac(&line, key.text, color);
        unsigned w = lbl_803f4bb8[1];
        if (name.Length() > w) {
            w3d_string_truncate_8020c3a0(&name, w - 3);
            w3d_string_append_8020bf2c(&name, lbl_8037ff70);
        } else w3d_string_append_range_8020c43c(&name, lbl_804aabc4, w - name.Length());
        w3d_line_pos_802cd26c(&line, lbl_803f4ba0[1], i + 2);
        w3d_line_lines_802cc0ac(&line, name.text, color);
        w3d_string_assign_8020bd38(&desc, self->At(idx)->Desc());
        w = lbl_803f4bb8[2];
        if (desc.Length() > w) {
            w3d_string_truncate_8020c3a0(&desc, w - 3);
            w3d_string_append_8020bf2c(&desc, lbl_8037ff70);
        } else w3d_string_append_range_8020c43c(&desc, lbl_804aabc4, w - desc.Length());
        w3d_line_pos_802cd26c(&line, lbl_803f4ba0[2], i + 2);
        w3d_line_lines_802cc0ac(&line, desc.text, color);
    }
    w3d_line_pos_802cd26c(&line, 0, 24);
    w3d_sink_write_802cbdf8((int)w3d::H(self->sink), line.text, 9);
}


