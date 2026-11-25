#include "w3d_ptr.h"
#line 1 "s4_scheme_query.cpp"
/* Inferred scheme-name classification; original objects remain external. */
extern "C" {
struct SchemeObject { Ptr32<Ptr32<void (Ptr32<SchemeObject>)>> vtable; char pad04[16]; Ptr32<char> schemeName; };
struct SchemeString { Ptr32<char> text; int reserved; };
struct SchemeRef { Ptr32<SchemeObject> object; int reserved; };
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<SchemeRef>);
Ptr32<SchemeObject> w3d_empty_80341584(Ptr32<SchemeObject>);
Ptr32<SchemeObject> w3d_auto_801797b4(Ptr32<SchemeObject>);
Ptr32<void> w3d_string_default(Ptr32<SchemeString>);
void w3d_string_release_header(Ptr32<void>);
void w3d_string_base_finish(Ptr32<SchemeString>);
void w3d_string_release(Ptr32<SchemeString>);
int w3d_lookup_text_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
extern const char w3d_str_803d0174[];
extern const char w3d_str_803d04a4[];
int w3d_s4_scheme_is_user_defined()
{
    struct { SchemeRef ref; SchemeString name; Ptr32<const char> query; Ptr32<const char> tip; Ptr32<const char> translated[2]; } local;
    local.ref.object = 0;
    local.query = w3d_str_803d0174;
    if (w3d_constructor_lookup_name(&local.query, &local.ref) >= 0) {
        Ptr32<SchemeObject> scheme = w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        w3d_string_default(&local.name);
        Ptr32<char> incoming = scheme->schemeName;
        ++*(Ptr32<unsigned short>)(incoming - 6);
        Ptr32<char> old = local.name.text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned int remaining = *(Ptr32<unsigned short>)(old - 6) - 1;
        *(Ptr32<unsigned short>)(old - 6) = remaining;
        if (!(unsigned short)remaining) w3d_string_release_header(header);
        Ptr32<char> text = scheme->schemeName;
        local.name.text = text;
        if (*text == '*') goto yes;
        local.tip = w3d_str_803d04a4;
        w3d_lookup_text_800fc2b0(&local.tip, local.translated);
        if (strcmp(text, local.translated[0]) == 0) {
        yes:
            w3d_string_base_finish(&local.name);
            w3d_string_release(&local.name);
            if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
            return 1;
        }
        w3d_string_base_finish(&local.name);
        w3d_string_release(&local.name);
    }
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return 0;
}
}


