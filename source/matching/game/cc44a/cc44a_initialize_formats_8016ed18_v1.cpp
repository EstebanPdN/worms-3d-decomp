// Observed layout-only views, with unresolved class identities and callback results.
struct cc44a_Format;
struct cc44a_FormatVtable { unsigned int unknown[3]; void (*retain)(cc44a_Format *); void (*release)(cc44a_Format *); };
struct cc44a_Format { cc44a_FormatVtable *vtable; };
struct cc44a_FormatArray { unsigned int count; unsigned short capacity; unsigned short unknown6; cc44a_Format **data; };
struct cc44a_FormatHolder { unsigned char unknown[20]; cc44a_FormatArray formats; };
struct cc44a_FormatSpec { unsigned short width, height; unsigned char mode, flags; };
struct cc44a_Factory;
extern cc44a_Factory cc44a_factory_80361ad8[];
extern const cc44a_FormatSpec cc44a_specs_803a645c[];
// Resize has no defined return on its observed paths; factory returns the callback pointer.
extern "C" void cc44a_resize_80210b90(cc44a_FormatArray *, int);
extern "C" cc44a_Format *cc44a_create_8020fcb4(cc44a_Factory *);
// Full-width arguments are narrowed by original stores. Original result is not defined.
extern "C" void cc44a_set_format_8016f8a0(cc44a_Format *, unsigned int, unsigned int, unsigned int, unsigned int);
struct cc44a_ArrayCursor { cc44a_FormatArray *array; cc44a_ArrayCursor(cc44a_FormatArray *p):array(p){} };
extern "C" cc44a_Format **cc44a_initialize_formats_8016ed18(cc44a_FormatHolder *self, unsigned int *count) {
    *count = 4;
    cc44a_FormatArray *formats = &self->formats;
    cc44a_ArrayCursor cursor(formats);
    cc44a_resize_80210b90(formats, 4);
    unsigned int index = 0;
    const cc44a_FormatSpec *spec = cc44a_specs_803a645c;
    const cc44a_FormatSpec *end = spec + 4;
    do {
        cc44a_Format *created = cc44a_create_8020fcb4(cc44a_factory_80361ad8);
        cc44a_Format **data = cursor.array->data;
        if (created) created->vtable->retain(created);
        cc44a_Format *old = data[index];
        if (old) old->vtable->release(old);
        data[index++] = created;
        cc44a_set_format_8016f8a0(created, spec->width, spec->height, spec->mode, spec->flags);
        ++spec;
    } while (spec < end);
    return formats->data;
}
