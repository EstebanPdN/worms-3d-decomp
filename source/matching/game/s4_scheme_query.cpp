/* Inferred scheme-name classification; original objects remain external. */
extern "C" {
struct SchemeObject { void (**vtable)(SchemeObject *); char pad04[16]; char *schemeName; };
struct SchemeString { char *text; int reserved; };
struct SchemeRef { SchemeObject *object; int reserved; };
int w3d_constructor_lookup_name(const char **, SchemeRef *);
SchemeObject *w3d_empty_80341584(SchemeObject *);
SchemeObject *w3d_auto_801797b4(SchemeObject *);
void * w3d_string_default(SchemeString *);
void w3d_string_release_header(void *);
void w3d_string_base_finish(SchemeString *);
void w3d_string_release(SchemeString *);
int w3d_lookup_text_800fc2b0(const char **, const char **);
int strcmp(const char *, const char *);
extern const char w3d_str_803d0174[];
extern const char w3d_str_803d04a4[];
int w3d_s4_scheme_is_user_defined()
{
    struct { SchemeRef ref; SchemeString name; const char *query; const char *tip; const char *translated[2]; } local;
    local.ref.object = 0;
    local.query = w3d_str_803d0174;
    if (w3d_constructor_lookup_name(&local.query, &local.ref) >= 0) {
        SchemeObject *scheme = w3d_auto_801797b4(w3d_empty_80341584(local.ref.object));
        w3d_string_default(&local.name);
        char *incoming = scheme->schemeName;
        ++*(unsigned short *)(incoming - 6);
        char *old = local.name.text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned int remaining = *(unsigned short *)(old - 6) - 1;
        *(unsigned short *)(old - 6) = remaining;
        if (!(unsigned short)remaining) w3d_string_release_header(header);
        char *text = scheme->schemeName;
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
