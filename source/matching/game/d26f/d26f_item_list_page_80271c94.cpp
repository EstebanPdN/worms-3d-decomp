// GWMP8P rev0 0x80271c94. Debug editor page listing the items of the current
// menu page, twenty at a time: title with page counts, an underline of the
// same length, then one line per item with its key letter, name and a kind
// name found by walking the item's type chain. Lines for the selected item
// use another colour. Finally releases the held help object.
struct D26fType { char pad[20]; D26fType *parent; };
struct D26fItem;
struct D26fItemTable { void *s0[5]; D26fType *(*type)(D26fItem *); };
struct D26fItem { D26fItemTable *vt; char pad[84]; const char *name; };
template <D26fType *T> inline bool d26f_is_kind(D26fItem *o) {
    D26fType *c = o->vt->type(o);
    D26fType *t = T;
    while (c != t) {
        D26fType *p = c->parent;
        if (c == p) return false;
        c = p;
    }
    return true;
}
struct D26fList { char pad[24]; unsigned count; char pad28[4]; D26fItem *items[1]; };
struct D26fPage { char pad[20]; D26fList *list; unsigned pad24; const char *title; char pad32[8]; const char *selected; };
struct D26fHelp;
struct D26fHelpTable { void *s0[4]; void (*release)(D26fHelp *); };
struct D26fHelp { D26fHelpTable *vt; };
struct D26fEditor { char pad[32]; void *sink; int mode; char pad40[44]; int page_index; D26fPage *page; D26fHelp *help; };
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" void w3d_string_release_header(void *);
struct D26fText_803426b8 {
    char *text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    const char *c_str() const { return text; }
    unsigned short length() const { return *(unsigned short *)(text - 4); }
    D26fText_803426b8 &operator=(const D26fText_803426b8 &other) {
        ++*(unsigned short *)(other.text - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
extern D26fText_803426b8 lbl_804b06a0[];
extern const char *lbl_804abba4;
extern char *lbl_804abba0;
extern "C" void w3d_cx7b_script_flag_set_8027a934(D26fEditor *, int);
extern "C" void fn_80271518(D26fEditor *, int);
extern "C" void w3d_s21_repeat_request_802cd220(D26fText_803426b8 *);
extern "C" void w3d_auto_802cd128(D26fText_803426b8 *);
extern "C" void w3d_auto_802cbf2c(D26fText_803426b8 *, const char *, int);
extern "C" void w3d_cc32b_append_lines_v2_802cc0ac(D26fText_803426b8 *, const char *, int);
extern "C" void w3d_s21_append_position_802cd26c(D26fText_803426b8 *, int, int);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(int, const char *, int);
extern "C" void w3d_string_format(D26fText_803426b8 *, const char *, ...);
extern "C" void w3d_string_assign(D26fText_803426b8 *, const char *);
extern "C" void cxc_append_8020c43c(D26fText_803426b8 *, const char *, int);
extern "C" int strcmp(const char *, const char *);
extern D26fType lbl_80366028[];
extern char lbl_803cc5d8[];
extern D26fType lbl_80365b28[];
extern char lbl_803cc5e4[];
extern D26fType lbl_80365d58[];
extern char lbl_803cc5ec[];
extern D26fType lbl_80365d08[];
extern char lbl_803cc600[];
extern D26fType lbl_80365fd8[];
extern char lbl_803cc60c[];
extern D26fType lbl_80365da8[];
extern char lbl_803cc61c[];
extern D26fType lbl_80365df8[];
extern char lbl_803cc628[];
extern D26fType lbl_80366078[];
extern char lbl_803cc634[];
extern D26fType lbl_80365e48[];
extern char lbl_803cc640[];
extern D26fType lbl_80365e98[];
extern char lbl_803cc650[];
extern D26fType lbl_80365cb8[];
extern char lbl_803cc65c[];
extern D26fType lbl_80365f38[];
extern char lbl_803cc66c[];
extern D26fType lbl_80365ee8[];
extern char lbl_803cc67c[];
extern D26fType lbl_80365f88[];
extern char lbl_803cc68c[];
extern D26fType lbl_80365b78[];
extern char lbl_803cc69c[];
extern D26fType lbl_80365bc8[];
extern char lbl_803cc6ac[];
extern D26fType lbl_80365c18[];
extern char lbl_803cc6bc[];
extern D26fType lbl_80365c68[];
extern char lbl_803cc6c4[];
extern char lbl_803cc5b4[], lbl_803cc6dc[], lbl_803cc6ec[], lbl_803cc73c[], lbl_803cc528[];
extern "C" void d26f_item_list_page_80271c94(D26fEditor *self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    if (!self->page) {
        fn_80271518(self, 0);
        return;
    }
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 2;
    D26fList *list = self->page->list;
    unsigned count = list->count;
    D26fItem **items = list->items;
    D26fText_803426b8 line;
    w3d_string_format(&line, lbl_803cc5b4, self->page->title, self->page_index + 1, count / 20 + 1);
    w3d_auto_802cbf2c(&text, line.c_str(), 7);
    unsigned length = line.length();
    line = lbl_804b06a0[0];
    cxc_append_8020c43c(&line, lbl_804abba4, length);
    w3d_auto_802cbf2c(&text, line.c_str(), 7);
    unsigned last = count;
    unsigned first = self->page_index * 20;
    if (last > first + 20) last = first + 20;
    for (unsigned i = first; i < last; i++) {
        D26fText_803426b8 type;
        int colour = 9;
        if (!strcmp(items[i]->name, self->page->selected)) colour = 7;
        if (d26f_is_kind<lbl_80366028>(items[i])) w3d_string_assign(&type, lbl_803cc5d8);
        else if (d26f_is_kind<lbl_80365b28>(items[i])) w3d_string_assign(&type, lbl_803cc5e4);
        else if (d26f_is_kind<lbl_80365d58>(items[i])) w3d_string_assign(&type, lbl_803cc5ec);
        else if (d26f_is_kind<lbl_80365d08>(items[i])) w3d_string_assign(&type, lbl_803cc600);
        else if (d26f_is_kind<lbl_80365fd8>(items[i])) w3d_string_assign(&type, lbl_803cc60c);
        else if (d26f_is_kind<lbl_80365da8>(items[i])) w3d_string_assign(&type, lbl_803cc61c);
        else if (d26f_is_kind<lbl_80365df8>(items[i])) w3d_string_assign(&type, lbl_803cc628);
        else if (d26f_is_kind<lbl_80366078>(items[i])) w3d_string_assign(&type, lbl_803cc634);
        else if (d26f_is_kind<lbl_80365e48>(items[i])) w3d_string_assign(&type, lbl_803cc640);
        else if (d26f_is_kind<lbl_80365e98>(items[i])) w3d_string_assign(&type, lbl_803cc650);
        else if (d26f_is_kind<lbl_80365cb8>(items[i])) w3d_string_assign(&type, lbl_803cc65c);
        else if (d26f_is_kind<lbl_80365f38>(items[i])) w3d_string_assign(&type, lbl_803cc66c);
        else if (d26f_is_kind<lbl_80365ee8>(items[i])) w3d_string_assign(&type, lbl_803cc67c);
        else if (d26f_is_kind<lbl_80365f88>(items[i])) w3d_string_assign(&type, lbl_803cc68c);
        else if (d26f_is_kind<lbl_80365b78>(items[i])) w3d_string_assign(&type, lbl_803cc69c);
        else if (d26f_is_kind<lbl_80365bc8>(items[i])) w3d_string_assign(&type, lbl_803cc6ac);
        else if (d26f_is_kind<lbl_80365c18>(items[i])) w3d_string_assign(&type, lbl_803cc6bc);
        else if (d26f_is_kind<lbl_80365c68>(items[i])) w3d_string_assign(&type, lbl_803cc6c4);
        else w3d_cc32b_append_lines_v2_802cc0ac(&type, lbl_803cc6dc, 1);
        w3d_string_format(&line, lbl_803cc528, lbl_804abba0[i - self->page_index * 20], items[i]->name, type.c_str());
        w3d_auto_802cbf2c(&text, line.c_str(), colour);
    }
    w3d_s21_append_position_802cd26c(&text, 0, 23);
    w3d_auto_802cbf2c(&text, lbl_803cc6ec, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc73c, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, text.c_str(), 9);
    if (self->help) self->help->vt->release(self->help);
    self->help = 0;
}
