// d24d: 0x8015c154 (336 bytes). Open a resource package by path: take the
// path's last 4 characters as a lower-case extension. A ".zip" path goes through
// the service object 0x8020b648 (virtual slot 23 finds the interface for the
// 16-byte id 0x80418070, whose slot 5 opens the path); any other path through
// the manager at +20 (slot 8, mode 1), whose negative status is returned at once.
// The opened handle is passed to the store at +16 (slot 12), and the function
// returns 0. The string has a user copy constructor, like the admitted string family
// (d16c, d17d).
struct d24d_String_803426b8 {
 d24d_String_803426b8(const d24d_String_803426b8 &);
    char *text;
    d24d_String_803426b8();
    ~d24d_String_803426b8();
};
extern "C" void d24d_string_finish_8020c5c4(d24d_String_803426b8 *);
extern "C" void d24d_string_release_80341588(d24d_String_803426b8 *);
inline d24d_String_803426b8::~d24d_String_803426b8() {
    d24d_string_finish_8020c5c4(this);
    d24d_string_release_80341588(this);
}
struct d24d_Object { void **vtable; };
struct d24d_Ref {
    d24d_Object *value;
    ~d24d_Ref() { if (value) ((void (*)(d24d_Object *))value->vtable[4])(value); }
};
struct d24d_PackageLoader {
    unsigned char unknown00[16];
    d24d_Object *store;                  // +16
    d24d_Object *manager;                // +20
};
extern "C" d24d_String_803426b8 *d24d_string_suffix_8020c0fc(d24d_String_803426b8 *, const d24d_String_803426b8 *, int);
extern "C" void d24d_string_to_lower_8020c230(d24d_String_803426b8 *);
extern "C" int strcmp(const char *, const char *);
extern "C" d24d_Object *d24d_service_8020b648();
extern const char d24d_zip_suffix_803a4360[];        // ".zip"
extern unsigned char d24d_archive_id_80418070[];     // 16-byte interface id
inline bool d24d_same(const char *a, const char *b) { return strcmp(a, b) == 0; }
inline d24d_Object *d24d_find_interface(unsigned char *id) {
    d24d_Object *service = d24d_service_8020b648();
    return ((d24d_Object *(*)(d24d_Object *, unsigned char *))service->vtable[23])(service, id);
}

extern "C" int d24d_open_package_8015c154(d24d_PackageLoader *self, const d24d_String_803426b8 *path) {
    d24d_Ref handle;
    handle.value = 0;
    d24d_String_803426b8 suffix;
    d24d_Ref *out = &handle;
    d24d_string_to_lower_8020c230(d24d_string_suffix_8020c0fc(&suffix, path, 4));
    if (d24d_same(suffix.text, d24d_zip_suffix_803a4360)) {
        d24d_Object *archive = d24d_find_interface(d24d_archive_id_80418070);
        ((void (*)(d24d_Object *, char *, d24d_Ref *))archive->vtable[5])(archive, path->text, out);
    } else {
        int status = ((int (*)(d24d_Object *, char *, int, d24d_Ref *))self->manager->vtable[8])(self->manager, path->text, 1, out);
        if (status < 0) return status;
    }
    ((void (*)(d24d_Object *, d24d_Object *))self->store->vtable[12])(self->store, handle.value);
    return 0;
}
