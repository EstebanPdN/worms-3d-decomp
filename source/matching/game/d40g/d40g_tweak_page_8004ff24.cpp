// GWMP8P rev0 0x8004ff24. Debug tweak page: for the twenty rows of the
// current page prints each tweakable's name, type, value and description in
// fixed-width columns, prints a closing line for rows past the end, and
// writes the page to the output. Field and type names are inferred from the
// original instructions; strings and globals are external views of original
// data.
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_release_header_8020bb2c(void *);
extern "C" void string_format_8020c510(String *, const char *, ...);
extern "C" void string_truncate_8020c3a0(String *, unsigned);
extern "C" void * string_append_8020bf2c(String *, const char *);
extern "C" void string_pad_8020c43c(String *, const char *, unsigned);
extern "C" void text_position_802cd26c(String *, int, int);
extern "C" void text_add_802cc0ac(String *, const char *, int);
extern "C" void text_line_802cbf2c(String *, const char *, int);
extern "C" void sink_write_802cbdf8(int, const char *, int);
struct String {
    char *text;
    String();
    String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String &operator=(const char *);
    void operator=(const String &o) {
        ((unsigned short *)o.text)[-3]++;
        char *old = text;
        void *header = old - 6;
        if (--((unsigned short *)old)[-3] == 0)
            string_release_header_8020bb2c(header);
        text = o.text;
    }
    unsigned length() const { return ((unsigned short *)text)[-2]; }
};
struct Vec { float x, y, z; Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Tweak;
struct TweakVtable { void *u[6]; int (*kind)(Tweak *); const char *(*typeName)(Tweak *); const char *(*name)(Tweak *); };
struct Tweak { TweakVtable *vtable; };
struct List { unsigned count; int u4; Tweak **items; };
struct Self { char u0[28]; void *sink; char u32[8]; unsigned page; List list; };
extern const char *pad_804aaa00;
extern const char *closing_803f3fcc[];
extern int columns_803f3fd4[];
extern unsigned widths_803f3fe4[];
extern const char s_80377f3c[], s_80377f40[], s_80377f48[], s_80377f4c[], s_80377f54[], s_80377f5c[], s_80377f68[];
extern "C" void *as_ptr_80341584(Tweak *);
extern "C" unsigned value_ptr_801797b4(void *);
extern "C" void *as_float_80342a74(Tweak *);
extern "C" float value_float_80178df0(void *);
extern "C" void *as_int_803426b4(Tweak *);
extern "C" int value_int_80178c48(void *);
extern "C" void *as_string_80343744(Tweak *);
extern "C" const String *value_string_80179170(void *);
extern "C" void *as_hex_80343858(Tweak *);
extern "C" unsigned value_hex_8017941c(void *);
extern "C" void *as_uint_80342a78(Tweak *);
extern "C" unsigned value_uint_80178d1c(void *);
extern "C" void *as_vec_80342fa4(Tweak *);
extern "C" const Vec *value_vec_80178ec4(void *);
inline void fit(String &s, unsigned w)
{
    String *p = &s;
    unsigned n = p->length();
    if (n > w) {
        string_truncate_8020c3a0(p, w - 3);
        string_append_8020bf2c(p, s_80377f3c);
    } else {
        string_pad_8020c43c(p, pad_804aaa00, w - n);
    }
}
extern "C" void d40g_tweak_page_8004ff24(Self *self)
{
    unsigned i;
    String page;
    List *list = &self->list;
    for (i = 0; i <= 19; i++) {
        unsigned row = i + self->page * 20;
        if (row >= self->list.count) {
            text_position_802cd26c(&page, 0, i + 2);
            text_line_802cbf2c(&page, closing_803f3fcc[0], 2);
            continue;
        }
        Tweak *first = list->items[row];
        String name(first->vtable->name(first));
        String type;
        String value;
        String help;
        fit(name, widths_803f3fe4[0]);
        text_position_802cd26c(&page, columns_803f3fd4[0], i + 2);
        text_add_802cc0ac(&page, name.text, 9);
#define ITEM (list->items[row])
#define TYPE { Tweak *t = ITEM; type = t->vtable->typeName(t); }
        Tweak *item = ITEM;
        switch (item->vtable->kind(item)) {
        case 5: {
            TYPE
            unsigned v = value_ptr_801797b4(as_ptr_80341584(ITEM));
            string_format_8020c510(&value, s_80377f40, v);
            break;
        }
        case 2:
            TYPE
            string_format_8020c510(&value, s_80377f48, (double)value_float_80178df0(as_float_80342a74(ITEM)));
            break;
        case 0: {
            TYPE
            int v = value_int_80178c48(as_int_803426b4(ITEM));
            string_format_8020c510(&value, s_80377f4c, v);
            break;
        }
        case 4:
            TYPE
            value = *value_string_80179170(as_string_80343744(ITEM));
            break;
        case 6: {
            TYPE
            unsigned v = value_hex_8017941c(as_hex_80343858(ITEM));
            string_format_8020c510(&value, s_80377f40, v);
            break;
        }
        case 1: {
            TYPE
            unsigned v = value_uint_80178d1c(as_uint_80342a78(ITEM));
            string_format_8020c510(&value, s_80377f54, v);
            break;
        }
        case 3: {
            TYPE
            Vec v = *value_vec_80178ec4(as_vec_80342fa4(ITEM));
            string_format_8020c510(&value, s_80377f5c, v.x, v.y, v.z);
            break;
        }
        default:
            type = s_80377f68;
            break;
        }
        fit(type, widths_803f3fe4[2]);
        text_position_802cd26c(&page, columns_803f3fd4[2], i + 2);
        text_add_802cc0ac(&page, type.text, 9);
        fit(value, widths_803f3fe4[3]);
        fit(help, widths_803f3fe4[1]);
        text_position_802cd26c(&page, columns_803f3fd4[3], i + 2);
        text_add_802cc0ac(&page, value.text, 9);
        text_position_802cd26c(&page, columns_803f3fd4[1], i + 2);
        text_add_802cc0ac(&page, help.text, 9);
    }
    text_position_802cd26c(&page, 0, 24);
    sink_write_802cbdf8((int)self->sink, page.text, 9);
}
