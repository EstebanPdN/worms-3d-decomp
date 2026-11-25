#include "w3d_ptr.h"
#line 1 "d24g_console_ctor_8004f9f4.cpp"
/* Worms 3D GameCube PAL 0x8004f9f4. Debug options console constructor: base constructor 0x801628b0, vtable 0x8040eae0, list at +44 (0x802109dc), registers itself in 0x804aaa04, clears +32 and +36, sets +56 to 2, and copies the composed key-help line into 0x803f3ff4. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Text {
    Ptr32<char> text;
    Text();
    ~Text();
    Text(const Text &);
};
extern "C" {
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_lines_802cc0ac(Ptr32<void>, Ptr32<const char>, int);
Ptr32<void> w3d_base_801628b0(Ptr32<void>);
void w3d_list_802109dc(Ptr32<void>);
Ptr32<char> strcpy(Ptr32<char>, Ptr32<const char>);
}
inline Text::~Text() { w3d_string_base_finish(this); w3d_string_release(this); }
extern char vt_8040eae0[];
extern const char s_80377ec0[],s_80377ecc[],s_80377ed0[],s_80377edc[],s_80377ee0[],s_80377ef0[],s_80377ef4[],s_80377f00[],s_80377f04[],s_80377f0c[],s_80377f10[],s_80377f1c[],s_80377f20[],s_80377f28[],s_80377f2c[];
extern char buf_803f3ff4[];
struct Console { Ptr32<void> vt; char u[28]; unsigned a, b; };
extern Ptr32<Console> g_804aaa04;
extern "C" Ptr32<Console> w3d_d24g_console_ctor_8004f9f4(Ptr32<Console> self)
{
    w3d_base_801628b0(self);
    self->vt = vt_8040eae0;
    w3d_list_802109dc((Ptr32<char>)self + 44);
    g_804aaa04 = self;
    self->a = 0;
    *(Ptr32<unsigned int>)((Ptr32<char>)self + 56) = 2;
    self->b = 0;
    Text t;
    w3d_lines_802cc0ac(&t, s_80377ec0, 9);
    w3d_lines_802cc0ac(&t, s_80377ecc, 7);
    w3d_lines_802cc0ac(&t, s_80377ed0, 9);
    w3d_lines_802cc0ac(&t, s_80377edc, 7);
    w3d_lines_802cc0ac(&t, s_80377ee0, 9);
    w3d_lines_802cc0ac(&t, s_80377ef0, 7);
    w3d_lines_802cc0ac(&t, s_80377ef4, 9);
    w3d_lines_802cc0ac(&t, s_80377f00, 7);
    w3d_lines_802cc0ac(&t, s_80377f04, 9);
    w3d_lines_802cc0ac(&t, s_80377f0c, 7);
    w3d_lines_802cc0ac(&t, s_80377f10, 9);
    w3d_lines_802cc0ac(&t, s_80377f1c, 7);
    w3d_lines_802cc0ac(&t, s_80377f20, 9);
    w3d_lines_802cc0ac(&t, s_80377f28, 7);
    w3d_lines_802cc0ac(&t, s_80377f2c, 9);
    strcpy(buf_803f3ff4, t.text);
    return self;
}


