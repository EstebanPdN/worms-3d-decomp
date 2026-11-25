#include "w3d_ptr.h"
#line 1 "d26f_new_item_key_8027865c.cpp"
// GWMP8P rev0 0x8027865c. Debug editor key handler that creates a new menu
// item: the key's index in either key table picks one of eighteen item
// prototypes and a default name; the new item takes the name and is appended
// to the current page's item array, then the list page redraws.
struct D26fItem;
struct D26fItemTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<D26fItem>)> retain; Ptr32<void (Ptr32<D26fItem>)> release; };
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" void w3d_string_release_header(Ptr32<void>);
struct D26fText_803426b8 {
    Ptr32<char> text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
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
struct D26fItem { Ptr32<D26fItemTable> vt; char pad[84]; D26fText_803426b8 name; };
struct D26fHeld {
    Ptr32<D26fItem> value;
    D26fHeld() : value(0) {}
    D26fHeld(const D26fHeld &);
    ~D26fHeld() { if (value) value->vt->release(value); }
    void assign(Ptr32<D26fItem> next) {
        if (next) next->vt->retain(next);
        if (value) value->vt->release(value);
        value = next;
    }
};
struct D26fPage;
struct D26fEditor { char pad[88]; Ptr32<D26fPage> page; };
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern Ptr32<const char> lbl_804abb9c;
extern Ptr32<const char> lbl_804abba0;
extern "C" Ptr32<D26fItem> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_string_assign(Ptr32<D26fText_803426b8>, Ptr32<const char>);
extern "C" void fn_801ef174(Ptr32<D26fPage>, int, int, Ptr32<D26fItem>);
extern "C" void w3d_auto_8027a98c(Ptr32<D26fEditor>);
extern "C" void fn_80271c94(Ptr32<D26fEditor>);
extern char lbl_80419cf8[];
extern char lbl_80419d08[];
extern char lbl_80419d18[];
extern char lbl_80419d28[];
extern char lbl_80419d38[];
extern char lbl_80419d48[];
extern char lbl_80419d58[];
extern char lbl_80419d68[];
extern char lbl_80419d78[];
extern char lbl_80419d88[];
extern char lbl_80419d98[];
extern char lbl_80419da8[];
extern char lbl_80419db8[];
extern char lbl_80419dc8[];
extern char lbl_80419dd8[];
extern char lbl_80419de8[];
extern char lbl_80419df8[];
extern char lbl_80419e08[];
extern char lbl_803ce418[];
extern char lbl_803ce424[];
extern char lbl_803ce434[];
extern char lbl_803ce440[];
extern char lbl_803ce44c[];
extern char lbl_803ce45c[];
extern char lbl_803ce46c[];
extern char lbl_803ce478[];
extern char lbl_803ce488[];
extern char lbl_803ce49c[];
extern char lbl_803ce4b0[];
extern char lbl_803ce4c0[];
extern char lbl_803ce4d4[];
extern char lbl_803ce4e8[];
extern char lbl_803ce4f4[];
extern char lbl_803ce504[];
extern char lbl_803ce518[];
extern char lbl_803ce530[];
extern char lbl_803ce53c[];
extern "C" void d26f_new_item_key_8027865c(Ptr32<D26fEditor> self, int key) {
    if (key == 32 || key == 27) {
        fn_80271c94(self);
        return;
    }
    Ptr32<const char> found = strchr(lbl_804abb9c, key);
    Ptr32<const char> base = lbl_804abb9c;
    if (!found) {
        found = strchr(lbl_804abba0, key);
        base = lbl_804abba0;
        if (!found) return;
    }
    D26fHeld item;
    D26fText_803426b8 name;
    switch (found - base) {
    case 0:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419cf8));
        w3d_string_assign(&name, lbl_803ce418);
        break;
    case 1:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d68));
        w3d_string_assign(&name, lbl_803ce424);
        break;
    case 2:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d58));
        w3d_string_assign(&name, lbl_803ce434);
        break;
    case 3:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d78));
        w3d_string_assign(&name, lbl_803ce440);
        break;
    case 4:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419de8));
        w3d_string_assign(&name, lbl_803ce44c);
        break;
    case 5:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419df8));
        w3d_string_assign(&name, lbl_803ce45c);
        break;
    case 6:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419e08));
        w3d_string_assign(&name, lbl_803ce46c);
        break;
    case 7:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d98));
        w3d_string_assign(&name, lbl_803ce478);
        break;
    case 8:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419dd8));
        w3d_string_assign(&name, lbl_803ce488);
        break;
    case 9:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419da8));
        w3d_string_assign(&name, lbl_803ce49c);
        break;
    case 10:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419db8));
        w3d_string_assign(&name, lbl_803ce4b0);
        break;
    case 11:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419dc8));
        w3d_string_assign(&name, lbl_803ce4c0);
        break;
    case 12:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d88));
        w3d_string_assign(&name, lbl_803ce4d4);
        break;
    case 13:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d48));
        w3d_string_assign(&name, lbl_803ce4e8);
        break;
    case 14:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d08));
        w3d_string_assign(&name, lbl_803ce4f4);
        break;
    case 15:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d18));
        w3d_string_assign(&name, lbl_803ce504);
        break;
    case 16:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d38));
        w3d_string_assign(&name, lbl_803ce518);
        break;
    case 17:
        item.assign(w3d_s10_service_forward_8020b680(lbl_80419d28));
        w3d_string_assign(&name, lbl_803ce530);
        break;
    }
    if (item.value) {
        if (!name.length()) w3d_string_assign(&name, lbl_803ce53c);
        item.value->name = name;
        fn_801ef174(self->page, 20, 6, item.value);
        w3d_auto_8027a98c(self);
        fn_80271c94(self);
    }
}


