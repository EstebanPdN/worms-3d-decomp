// flags: -fvtable-thunks
struct K5bWriter;
struct K5bEnumNames { char pad[8]; const char **names; };
struct K5bEnumType { char pad[12]; K5bEnumNames *names; };
class K5bSource;
typedef unsigned int (K5bSource::*K5bGetter)();
struct K5bEnumBinding {
    K5bEnumType *type;
    char pad4[4];
    unsigned int fallback;
    K5bGetter getter;
};
extern char lbl_803b0c74[];
extern "C" void fn_8020d6bc(K5bWriter *writer, const char *format, ...);
extern "C" int w3d_s21_write_text_8020dbf8(K5bWriter *writer, const char *text);
extern "C" void * w3d_s10_format_number_8020da90(K5bWriter *writer, unsigned int value);
extern "C" void w3d_k5b_binding_write_enum_801ecff0(K5bEnumBinding *self, K5bWriter *writer, K5bSource *source)
{
    unsigned int value;
    if (source != 0)
        value = (source->*(self->getter))();
    else
        value = self->fallback;
    if (self->type->names != 0) {
        const char **names = self->type->names->names;
        unsigned int prefix = 0;
        unsigned int count = 1;
        int i;
        for (i = 0; names[i] != 0 && names[i + 1] != 0; count++, i++) {
            unsigned int j = 0;
            while (names[i][j] == names[i + 1][j] && names[i][j] != 0)
                j++;
            if (prefix == 0 || j < prefix)
                prefix = j;
        }
        if (value > count)
            fn_8020d6bc(writer, lbl_803b0c74, value);
        else
            w3d_s21_write_text_8020dbf8(writer, self->type->names->names[value] + prefix);
    } else {
        w3d_s10_format_number_8020da90(writer, value);
    }
}
// desc: w3d_k5b_binding_write_enum_801ecff0: Appears to read an enum value (getter or fallback) and write its name without the common prefix of the type's name list, a number when unnamed, or "Invalid (%d)".
