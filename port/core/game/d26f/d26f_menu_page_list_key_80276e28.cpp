#include "w3d_ptr.h"
#line 1 "d26f_menu_page_list_key_80276e28.cpp"
// GWMP8P rev0 0x80276e28. Debug editor key handler for the list of menu
// pages: space creates a new page with a numbered free name and shows it,
// escape leaves, S saves the page files under Data/ (and the mod directory
// when set), L loads them, n and p change the list page, and a key from the
// key tables selects a page, either to list its items or to edit its name.
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" void w3d_string_release_header(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
extern "C" Ptr32<void> w3d_string_append(Ptr32<void>, Ptr32<const char>);
extern "C" void w3d_string_assign(Ptr32<void>, Ptr32<const char>);
struct D26fText_803426b8 {
    Ptr32<char> text;
    D26fText_803426b8();
    template <class W3dU> D26fText_803426b8(Ptr32<W3dU> w3d_p) : D26fText_803426b8((const char *)w3d_p.get()) {}
 D26fText_803426b8(const char *);
    D26fText_803426b8(const D26fText_803426b8 &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    unsigned short length() const { return *(Ptr32<unsigned short>)(text - 4); }
    D26fText_803426b8 &operator=(const D26fText_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
inline D26fText_803426b8 operator+(const D26fText_803426b8 &a, const char *b) {
    D26fText_803426b8 r = a;
    w3d_string_append(&r, b);
    return D26fText_803426b8(r);
}
struct D26fItem;
struct D26fItemTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<D26fItem>)> retain; Ptr32<void (Ptr32<D26fItem>)> release; };
struct D26fItem { Ptr32<D26fItemTable> vt; char pad[24]; D26fText_803426b8 name; };
struct D26fHeld {
    Ptr32<D26fItem> value;
    template <class W3dU> D26fHeld(Ptr32<W3dU> w3d_p) : D26fHeld((D26fItem *)w3d_p.get()) {}
 D26fHeld(D26fItem *v) : value(v) { if (value) value->vt->retain(value); }
    D26fHeld(const D26fHeld &);
    ~D26fHeld() { if (value) value->vt->release(value); }
};
struct D26fKey { Ptr32<char> name; };
struct D26fNames { Ptr32<Ptr32<const char>> begin; Ptr32<Ptr32<const char>> end; Ptr32<const char> & operator[](unsigned i) { return begin[i]; } };
struct D26fItemArray { unsigned count; unsigned capacity; Ptr32<Ptr32<D26fItem>> data; };
struct D26fEditor {
    char pad[28];
    Ptr32<void> group;       // +28
    char pad32[20];
    D26fItemArray items; // +52
    D26fNames names;   // +64
    char pad72[8];
    unsigned page;     // +80
    char pad84[4];
    Ptr32<D26fItem> item;    // +88
};
struct D26fGame { char pad[148]; D26fText_803426b8 mod; };
extern Ptr32<D26fGame> lbl_804b1788;
extern Ptr32<const char> lbl_804abb9c;
extern Ptr32<const char> lbl_804abba0;
extern Ptr32<const char> lbl_803fccf4[];
extern char lbl_80419e28[], lbl_803ce3e0[], lbl_803ce3f0[], lbl_803ce3f8[], lbl_803ce400[], lbl_803ce408[], lbl_803ce410[];
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<D26fItem> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_string_format(Ptr32<D26fText_803426b8>, Ptr32<const char>, ...);
extern "C" int w3d_s20_service_call4_800fc160(Ptr32<D26fKey>, Ptr32<D26fItem>, int, int);
extern "C" Ptr32<void> w3d_empty_80343744(Ptr32<void>);
extern "C" int d24d_rename_item_801790bc(Ptr32<void>, Ptr32<const char>);
extern "C" void w3d_auto_8027a98c(Ptr32<D26fEditor>);
extern "C" void fn_80271518(Ptr32<D26fEditor>, Ptr32<const char>);
extern "C" void fn_80271420(Ptr32<D26fEditor>);
extern "C" void fn_80271c94(Ptr32<D26fEditor>);
extern "C" void fn_80276d14(Ptr32<D26fEditor>);
extern "C" void w3d_auto_8027a9e4(Ptr32<D26fEditor>, Ptr32<const char>);
extern "C" void w3d_s20_service_call3_800fd440(Ptr32<const char>, int, int);
extern "C" Ptr32<void> w3d_s20_forward_indexed_800fd4c8(int, int);
extern "C" int d25c_resource_load_800fd504(Ptr32<const char>, int, int);
template <class T> inline const T &d26f_min(const T &a, const T &b) { return b < a ? b : a; }
extern "C" void d26f_menu_page_list_key_80276e28(Ptr32<D26fEditor> self, int key) {
    switch (key) {
    case 32: {
        D26fHeld item(w3d_s10_service_forward_8020b680(lbl_80419e28));
        D26fText_803426b8 name;
        int i = 0;
        int group = 5;
        if (lbl_804b1788->mod.length()) group = 9;
        D26fKey k;
        do {
            w3d_string_format(&name, lbl_803ce3e0, i++);
            k.name = name.text;
        } while (w3d_s20_service_call4_800fc160(&k, item.value, group, 0) < 0);
        item.value->name = name;
        d24d_rename_item_801790bc(w3d_empty_80343744(self->group), name.text);
        w3d_auto_8027a98c(self);
        fn_80271518(self, 0);
        unsigned index = 0;
        D26fNames &names = self->names;
        Ptr32<Ptr32<const char>> p = names.begin;
        if (p != names.end) {
            do {
            if (!strcmp(*p, name.text)) {
                unsigned page = index / 20;
                if (page != self->page) {
                    self->page = page;
                    fn_80271518(self, 0);
                }
                break;
            }
            p++;
            index++;
            } while (p != names.end);
        }
        break;
    }
    case 27:
        fn_80271420(self);
        break;
    case 83: {
        D26fText_803426b8 path(lbl_803ce3f0);
        w3d_string_append(&path, lbl_803fccf4[0]);
        Ptr32<const char> xml = lbl_803ce3f8;
        w3d_s20_service_call3_800fd440((path + xml).text, 5, 2);
        Ptr32<const char> xom = lbl_803ce400;
        w3d_s20_service_call3_800fd440((path + xom).text, 5, 1);
        if (lbl_804b1788->mod.length()) {
            w3d_string_assign(&path, lbl_803ce3f0);
            w3d_string_append(&path, lbl_804b1788->mod.text);
            w3d_s20_service_call3_800fd440((path + xml).text, 9, 2);
            w3d_s20_service_call3_800fd440((path + xom).text, 9, 1);
        }
        fn_80271518(self, lbl_803ce408);
        break;
    }
    case 76:
        w3d_s20_forward_indexed_800fd4c8(5, 2);
        if (lbl_804b1788->mod.length())
            d25c_resource_load_800fd504(lbl_804b1788->mod.text, 9, 2);
        fn_80271518(self, lbl_803ce410);
        break;
    case 110:
        self->page++;
        self->page = d26f_min(self->page, (self->items.count - 1) / 20);
        fn_80271518(self, 0);
        break;
    case 112:
        self->page--;
        self->page = d26f_min(self->page, (self->items.count - 1) / 20);
        fn_80271518(self, 0);
        break;
    default: {
        Ptr32<const char> found = strchr(lbl_804abb9c, key);
        Ptr32<const char> base = lbl_804abb9c;
        if (!found) {
            found = strchr(lbl_804abba0, key);
            base = lbl_804abba0;
            if (!found) return;
        }
        unsigned index = (found - base) + self->page * 20;
        D26fItemArray &items = self->items;
        if (index < items.count) {
            Ptr32<Ptr32<D26fItem>> data = items.data;
            if (data[index]) data[index]->vt->retain(data[index]);
            if (self->item) self->item->vt->release(self->item);
            self->item = data[index];
            if (base == lbl_804abba0) {
                fn_80271c94(self);
                w3d_auto_8027a9e4(self, self->names[index]);
            } else {
                fn_80276d14(self);
            }
        }
        break;
    }
    }
}


