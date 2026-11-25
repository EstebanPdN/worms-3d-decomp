#include "w3d_ptr.h"
#line 1 "k5b_a_801ecff0.cpp"
// flags: -fvtable-thunks
struct K5bWriter;
struct K5bEnumNames { char pad[8]; Ptr32<Ptr32<const char>> names; };
struct K5bEnumType { char pad[12]; Ptr32<K5bEnumNames> names; };
class K5bSource;
typedef w3d::Pmf<K5bSource, unsigned int()> K5bGetter;
struct K5bEnumBinding {
    Ptr32<K5bEnumType> type;
    char pad4[4];
    unsigned int fallback;
    K5bGetter getter;
};
extern char lbl_803b0c74[];
extern "C" void fn_8020d6bc(Ptr32<K5bWriter> writer, Ptr32<const char> format, ...);
extern "C" int w3d_s21_write_text_8020dbf8(Ptr32<K5bWriter> writer, Ptr32<const char> text);
extern "C" Ptr32<void> w3d_s10_format_number_8020da90(Ptr32<K5bWriter> writer, unsigned int value);
extern "C" void w3d_k5b_binding_write_enum_801ecff0(Ptr32<K5bEnumBinding> self, Ptr32<K5bWriter> writer, Ptr32<K5bSource> source)
{
    unsigned int value;
    if (source != 0)
        value = ((self->getter))(source);
    else
        value = self->fallback;
    if (self->type->names != 0) {
        Ptr32<Ptr32<const char>> names = self->type->names->names;
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


