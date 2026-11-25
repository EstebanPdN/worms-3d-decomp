// Apply values to a named item (Worms 3D GameCube PAL, 0x8017dd68).
//
// Finds the name (0x8017e22c). A missing name copies and discards the string
// and returns 0x80004005. An item not yet loaded is loaded through the owner
// (virtual slot 15) with its kind byte; kinds marked 1 in table 0x804a8fd8
// also copy the name string first. A negative load status is returned.
// Finally forwards the two arguments to the item (virtual slot 14).

extern "C" void w3d_string_base_init(void *);
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" unsigned short *w3d_string_header(void *);
struct String {
    char *data;
    String(const String &x) { w3d_string_base_init(this); data = x.data; ++*w3d_string_header(this); }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Key { unsigned char kind; };
struct Item { void **vtable;
    int loaded() { return ((int (*)(Item *))vtable[16])(this); }
    unsigned char *kind() { return ((unsigned char *(*)(Item *))vtable[18])(this); }
    int apply(int a, int b) { return ((int (*)(Item *, int, int))vtable[14])(this, a, b); }
};
struct Owner { void **vtable; char u[20]; Item *items[64];
    Item *at(unsigned i) { return *(Item **)((i << 2) + (unsigned)this + 24); }
    int load(Key *key) { return ((int (*)(Owner *, Key *))vtable[15])(this, key); }
};
extern int table_804a8fd8[];
extern "C" int fn_8017e22c(Owner *, const String *, unsigned short *);
extern "C" int d24j_apply_named_item_8017dd68(Owner *self, const String *name, int a, int b)
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
    return self->at(index)->apply(a, b);
}
