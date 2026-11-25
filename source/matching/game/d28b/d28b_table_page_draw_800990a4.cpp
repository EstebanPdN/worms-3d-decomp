/* Table list page draw (0x800990a4): for each of the 19 rows of the current page (+44 times 19
 * plus the row) either writes the end-of-list text in colour 2, or copies the item name, formats
 * its count and byte value with "%d", picks the Y or N flag, uses colour 7 when the count is not
 * zero and 9 otherwise, and places each field at the column table; name and description are cut
 * to the width table with "..." or padded with blanks. Finishes by positioning at line 24 and
 * writing the line to the sink at +32. Item is a partial view of the original virtual table with
 * 4-byte entries. Field names are inferred from the original instructions; strings and tables
 * are external views of original data. The unit owns no data. */
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" String *w3d_string_assign_8020bd38(String *, const char *);
extern "C" void * w3d_string_assign_range_8020bdf4(String *, const char *, int);
extern "C" void w3d_string_format_8020c510(String *, const char *, ...);
extern "C" void w3d_string_truncate_8020c3a0(String *, unsigned);
extern "C" void * w3d_string_append_8020bf2c(String *, const char *);
extern "C" void w3d_string_append_range_8020c43c(String *, const char *, unsigned);
extern "C" void w3d_line_pos_802cd26c(String *, int, int);
extern "C" void w3d_line_text_802cbf2c(String *, const char *, int);
extern "C" void w3d_line_lines_802cc0ac(String *, const char *, int);
struct String {
    char *text;
    String();
    String(const String &o) { w3d_string_init_8020c5c0(this); text = o.text; ++*w3d_string_header_80341884(this); }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
};
extern "C" void w3d_sink_write_802cbdf8(int, const char *, int);
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
};
struct Menu {
    char unknown00[32]; void *sink; char unknown36[8]; unsigned page; char unknown48[16];
    Item **begin; Item **end;
    Item *&At(unsigned i) { return begin[i]; }
};
extern const char *lbl_803f4b90[];
extern int lbl_803f4ba0[];
extern unsigned lbl_803f4bb8[];
extern const char *lbl_804aabc8;
extern const char *lbl_804aabc4;
extern char lbl_8037ff64[], lbl_8037ff6c[], lbl_8037ff00[], lbl_8037ff70[];
extern "C" void w3d_d28b_table_page_draw_800990a4(Menu *self) {
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
    w3d_sink_write_802cbdf8((int)self->sink, line.text, 9);
}
