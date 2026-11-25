#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d24j_apply_named_item_8017dd68.cpp"
// Apply values to a named item (Worms 3D GameCube PAL, 0x8017dd68).
//
// Finds the name (0x8017e22c). A missing name copies and discards the string
// and returns 0x80004005. An item not yet loaded is loaded through the owner
// (virtual slot 15) with its kind byte; kinds marked 1 in table 0x804a8fd8
// also copy the name string first. A negative load status is returned.
// Finally forwards the two arguments to the item (virtual slot 14).

extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
struct String {
    Ptr32<char> data;
    String(const String &x) { w3d_string_base_init(this); data = x.data; ++*w3d_string_header(this); }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Key { unsigned char kind; };
struct Item { Ptr32<Ptr32<void>> vtable;
    int loaded() { return ((Ptr32<int (Ptr32<Item>)>)vtable[16])(this); }
    Ptr32<unsigned char> kind() { return ((Ptr32<Ptr32<unsigned char> (Ptr32<Item>)>)vtable[18])(this); }
    int apply(int a, int b) { return ((Ptr32<int (Ptr32<Item>, int, int)>)vtable[14])(this, a, b); }
};
struct Owner { Ptr32<Ptr32<void>> vtable; char u[20]; Ptr32<Item> items[64];
    Ptr32<Item> at(unsigned i) { return ((Ptr32<Item> *)w3d_restab_slots())[i]; }   // port (v29): tabla nativa
    int load(Ptr32<Key> key) { return ((Ptr32<int (Ptr32<Owner>, Ptr32<Key>)>)vtable[15])(this, key); }
};
extern int table_804a8fd8[];
extern "C" void w3d_dbg(const char *, ...);
extern "C" int fn_8017e22c(Ptr32<Owner>, Ptr32<const String>, Ptr32<unsigned short>);
extern "C" int d24j_apply_named_item_8017dd68(Ptr32<Owner> self, Ptr32<const String> name, int a, int b)
{
    unsigned short index;
    if (fn_8017e22c(self, name, &index) < 0) {
        String s(*name);
        return 0x80004005;
    }
    if (self->at(index)->loaded() == 0) {
        Key key;
        unsigned kind = *self->at(index)->kind();
        key.kind = kind;
        if (table_804a8fd8[kind] == 1) {
            String s(*name);
        }
        int status = self->load(&key);
        if (status < 0) return status;
    }
    int r_ = self->at(index)->apply(a, b);
    { Ptr32<int> o_ = (Ptr32<int>)a; if (r_ < 0 || (o_ && *o_ == 0)) w3d_dbg("[T] apply idx=%u r=%x out=%x name=%s kind=%d item=%x\n", index, r_, o_ ? *o_ : -1, (const char *)name->data, *self->at(index)->kind(), (unsigned)w3d::H(self->at(index))); }
    return r_;
}


