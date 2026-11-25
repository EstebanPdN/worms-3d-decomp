#include "w3d_ptr.h"
#line 1 "d24d_open_package_8015c154.cpp"
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
    Ptr32<char> text;
    d24d_String_803426b8();
    ~d24d_String_803426b8();
};
extern "C" void d24d_string_finish_8020c5c4(Ptr32<d24d_String_803426b8>);
extern "C" void d24d_string_release_80341588(Ptr32<d24d_String_803426b8>);
inline d24d_String_803426b8::~d24d_String_803426b8() {
    d24d_string_finish_8020c5c4(this);
    d24d_string_release_80341588(this);
}
struct d24d_Object { Ptr32<Ptr32<void>> vtable; };
struct d24d_Ref {
    Ptr32<d24d_Object> value;
    ~d24d_Ref() { if (value) ((Ptr32<void (Ptr32<d24d_Object>)>)value->vtable[4])(value); }
};
struct d24d_PackageLoader {
    unsigned char unknown00[16];
    Ptr32<d24d_Object> store;                  // +16
    Ptr32<d24d_Object> manager;                // +20
};
extern "C" Ptr32<d24d_String_803426b8> d24d_string_suffix_8020c0fc(Ptr32<d24d_String_803426b8>, Ptr32<const d24d_String_803426b8>, int);
extern "C" void d24d_string_to_lower_8020c230(Ptr32<d24d_String_803426b8>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<d24d_Object> d24d_service_8020b648();
extern const char d24d_zip_suffix_803a4360[];        // ".zip"
extern unsigned char d24d_archive_id_80418070[];     // 16-byte interface id
inline bool d24d_same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
inline Ptr32<d24d_Object> d24d_find_interface(Ptr32<unsigned char> id) {
    Ptr32<d24d_Object> service = d24d_service_8020b648();
    return ((Ptr32<Ptr32<d24d_Object> (Ptr32<d24d_Object>, Ptr32<unsigned char>)>)service->vtable[23])(service, id);
}

extern "C" int d24d_open_package_8015c154(Ptr32<d24d_PackageLoader> self, Ptr32<const d24d_String_803426b8> path) {
    d24d_Ref handle;
    handle.value = 0;
    d24d_String_803426b8 suffix;
    Ptr32<d24d_Ref> out = &handle;
    d24d_string_to_lower_8020c230(d24d_string_suffix_8020c0fc(&suffix, path, 4));
    if (d24d_same(suffix.text, d24d_zip_suffix_803a4360)) {
        Ptr32<d24d_Object> archive = d24d_find_interface(d24d_archive_id_80418070);
        ((Ptr32<void (Ptr32<d24d_Object>, Ptr32<char>, Ptr32<d24d_Ref>)>)archive->vtable[5])(archive, path->text, out);
    } else {
        int status = ((Ptr32<int (Ptr32<d24d_Object>, Ptr32<char>, int, Ptr32<d24d_Ref>)>)self->manager->vtable[8])(self->manager, path->text, 1, out);
        if (status < 0) return status;
    }
    ((Ptr32<void (Ptr32<d24d_Object>, Ptr32<d24d_Object>)>)self->store->vtable[12])(self->store, handle.value);
    return 0;
}


