#include "w3d_ptr.h"
#line 1 "d33f_editor_key_dispatch_80278e38.cpp"
// GWMP8P rev0 0x80278e38. Interface editor key handler: arrow keys, delete
// and the letter commands that open each property page for the selected
// control.
struct D26fType { char pad[20]; Ptr32<D26fType> parent; };
struct D26fItem;
struct D26fItemTable { Ptr32<void> s0[4]; Ptr32<void (Ptr32<D26fItem>)> release; Ptr32<Ptr32<D26fType> (Ptr32<D26fItem>)> type; };
struct D26fItem { Ptr32<D26fItemTable> vt; };
template <D26fType *T> inline bool d26f_is_kind(Ptr32<D26fItem> o) {
    Ptr32<D26fType> c = o->vt->type(o);
    Ptr32<D26fType> t = T;
    while (c != t) {
        Ptr32<D26fType> p = c->parent;
        if (c == p) return false;
        c = p;
    }
    return true;
}
struct D26fList { char pad[24]; unsigned count; char pad28[4]; Ptr32<D26fItem> items[1]; };
struct D26fPage { char pad[20]; Ptr32<D26fList> list; };
inline bool Less(const unsigned &a, const unsigned &b) { return a < b; }
struct D26fEditor { char pad[88]; Ptr32<D26fPage> page; Ptr32<D26fItem> item; };
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern Ptr32<const char> lbl_804abb9c;
extern Ptr32<const char> lbl_804abba0;
extern "C" void fn_801ef380(Ptr32<D26fPage>, int, int, unsigned, int);
extern "C" void w3d_auto_8027a98c(Ptr32<D26fEditor>);
extern "C" void fn_802761b8(Ptr32<D26fEditor>, Ptr32<D26fItem>, int);
extern "C" void fn_8027aa3c(Ptr32<D26fEditor>);
extern "C" void fn_80271c94(Ptr32<D26fEditor>);
extern D26fType lbl_80365b78[];
extern "C" void fn_80272968(Ptr32<D26fEditor>);
extern D26fType lbl_80366028[];
extern "C" void fn_802757c0(Ptr32<D26fEditor>);
extern D26fType lbl_80365bc8[];
extern "C" void fn_80272cc0(Ptr32<D26fEditor>);
extern D26fType lbl_80365c18[];
extern "C" void fn_80272e28(Ptr32<D26fEditor>);
extern D26fType lbl_80365c68[];
extern "C" void fn_80273054(Ptr32<D26fEditor>);
extern D26fType lbl_80365b28[];
extern "C" void fn_80272644(Ptr32<D26fEditor>);
extern D26fType lbl_80365d58[];
extern "C" void fn_80273dc4(Ptr32<D26fEditor>);
extern D26fType lbl_80365d08[];
extern "C" void fn_8027410c(Ptr32<D26fEditor>);
extern D26fType lbl_80365fd8[];
extern "C" void fn_80275320(Ptr32<D26fEditor>);
extern D26fType lbl_80365da8[];
extern "C" void fn_80274328(Ptr32<D26fEditor>);
extern D26fType lbl_80365df8[];
extern "C" void fn_80274724(Ptr32<D26fEditor>);
extern D26fType lbl_80366078[];
extern "C" void fn_80275b08(Ptr32<D26fEditor>);
extern D26fType lbl_80365e48[];
extern "C" void fn_80274a4c(Ptr32<D26fEditor>);
extern D26fType lbl_80365e98[];
extern "C" void fn_80274e4c(Ptr32<D26fEditor>);
extern D26fType lbl_80365cb8[];
extern "C" void fn_80273560(Ptr32<D26fEditor>);
extern D26fType lbl_80365f38[];
extern "C" void fn_802737d8(Ptr32<D26fEditor>);
extern D26fType lbl_80365ee8[];
extern "C" void fn_80273af0(Ptr32<D26fEditor>);
extern D26fType lbl_80365f88[];
extern "C" void fn_8027ae70(Ptr32<D26fEditor>);
extern "C" void d33f_editor_key_dispatch_80278e38(Ptr32<D26fEditor> self, int key) {
    if (key == 27) {
        fn_80271c94(self);
    } else if (key == 32) {
        if (d26f_is_kind<lbl_80365b78>(self->item)) fn_80272968(self);
        else if (d26f_is_kind<lbl_80366028>(self->item)) fn_802757c0(self);
        else if (d26f_is_kind<lbl_80365bc8>(self->item)) fn_80272cc0(self);
        else if (d26f_is_kind<lbl_80365c18>(self->item)) fn_80272e28(self);
        else if (d26f_is_kind<lbl_80365c68>(self->item)) fn_80273054(self);
        else if (d26f_is_kind<lbl_80365b28>(self->item)) fn_80272644(self);
        else if (d26f_is_kind<lbl_80365d58>(self->item)) fn_80273dc4(self);
        else if (d26f_is_kind<lbl_80365d08>(self->item)) fn_8027410c(self);
        else if (d26f_is_kind<lbl_80365fd8>(self->item)) fn_80275320(self);
        else if (d26f_is_kind<lbl_80365da8>(self->item)) fn_80274328(self);
        else if (d26f_is_kind<lbl_80365df8>(self->item)) fn_80274724(self);
        else if (d26f_is_kind<lbl_80366078>(self->item)) fn_80275b08(self);
        else if (d26f_is_kind<lbl_80365e48>(self->item)) fn_80274a4c(self);
        else if (d26f_is_kind<lbl_80365e98>(self->item)) fn_80274e4c(self);
        else if (d26f_is_kind<lbl_80365cb8>(self->item)) fn_80273560(self);
        else if (d26f_is_kind<lbl_80365f38>(self->item)) fn_802737d8(self);
        else if (d26f_is_kind<lbl_80365ee8>(self->item)) fn_80273af0(self);
        else if (d26f_is_kind<lbl_80365f88>(self->item)) fn_8027ae70(self);
        else {
            if (self->item) self->item->vt->release(self->item);
            self->item = 0;
            fn_80271c94(self);
        }
    } else if (key == 127) {
        Ptr32<D26fList> list = self->page->list;
        unsigned count = list->count;
        Ptr32<Ptr32<D26fItem>> items = list->items;
        for (unsigned i = 0; Less(i, count); i++) {
            if (items[i] == self->item) {
                fn_801ef380(self->page, 20, 6, i, 1);
                fn_80271c94(self);
                w3d_auto_8027a98c(self);
                return;
            }
        }
    } else {
        Ptr32<const char> found = strchr(lbl_804abb9c, key);
        Ptr32<const char> base = lbl_804abb9c;
        if (!found) {
            found = strchr(lbl_804abba0, key);
            base = lbl_804abba0;
            if (!found) return;
        }
        unsigned index = found - base;
        switch (index) {
        case 0: fn_802761b8(self, self->item, 2); break;
        case 2: fn_802761b8(self, self->item, 3); break;
        case 3: fn_802761b8(self, self->item, 8); break;
        case 4: fn_802761b8(self, self->item, 9); break;
        case 5: fn_802761b8(self, self->item, 10); break;
        case 6: fn_802761b8(self, self->item, 11); break;
        case 7: fn_802761b8(self, self->item, 12); break;
        case 8: fn_802761b8(self, self->item, 13); break;
        case 9: fn_802761b8(self, self->item, 14); break;
        case 10: fn_802761b8(self, self->item, 15); break;
        case 11: fn_8027aa3c(self); break;
        }
    }
}


