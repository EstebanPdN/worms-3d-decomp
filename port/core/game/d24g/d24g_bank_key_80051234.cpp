#include "w3d_ptr.h"
#line 1 "d24g_bank_key_80051234.cpp"
/* Worms 3D GameCube PAL 0x80051234. Load-table key handler: space selects all 14 banks and returns to the options page, escape returns, newline toggles the format (Binary or XML) and redraws, any other key is uppercased and looked up in the bank key string to select that bank. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Text {
    Ptr32<char> text;
    Text(Ptr32<const char>, unsigned, unsigned);
    ~Text();
    Text(const Text &);
};
extern "C" {
void string_finish_8020c5c4(Ptr32<void>);
void string_release_80341588(Ptr32<void>);
void upper_8020c2e8(Ptr32<Text>);
Ptr32<char> strchr(Ptr32<const char>, int);
Ptr32<void> bank_select_800fd4c8(unsigned char, int);
}
inline Text::~Text() { string_finish_8020c5c4(this); string_release_80341588(this); }
struct Console { char u0[56]; int format; };
extern "C" void page_setup_8004fe48(Ptr32<Console>);
extern "C" void load_menu_80050aa0(Ptr32<Console>);
extern Ptr32<const char> keys_804aa9fc;
extern "C" void w3d_d24g_bank_key_80051234(Ptr32<Console> self, char key)
{
    switch (key) {
    case ' ':
        for (unsigned i = 0; i <= 13; i++)
            bank_select_800fd4c8(i, self->format);
    case 27:
        page_setup_8004fe48(self);
        break;
    case '\n':
        switch (self->format) {
        case 1: self->format = 2; break;
        case 2: self->format = 1; break;
        default: self->format = 2; break;
        }
        load_menu_80050aa0(self);
        break;
    default: {
        Text s(&key, 0, 1);
        upper_8020c2e8(&s);
        Ptr32<const char> p = strchr(keys_804aa9fc, *s.text);
        if (!p) return;
        unsigned index = p - keys_804aa9fc;
        if (index <= 13) {
            bank_select_800fd4c8(index, self->format);
            page_setup_8004fe48(self);
        }
    }
    }
}


