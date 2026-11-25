// GWMP8P rev0 0x80042d04. Appends a string to the name vector at +72 and a
// value to the vector at +96 with unmodified STLport push_back; a zero value
// is replaced by the default held in a global. The by-value string is
// destroyed by this function. Names are inferred from the original
// instructions.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
    const char *text;
    String(const String &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &);
};
struct Self { char pad[72]; std::vector<String> names; char pad2[8]; std::vector<int> values; };
extern int g_default_804aa978;
extern "C" void w3d_d32a_name_value_append_80042d04(Self *self, String name, int value)
{
    self->names.push_back(name);
    if (value == 0)
        self->values.push_back(g_default_804aa978);
    else
        self->values.push_back(value);
}
