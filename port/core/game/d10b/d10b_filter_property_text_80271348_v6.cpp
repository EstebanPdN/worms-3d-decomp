#include "w3d_ptr.h"
#line 1 "d10b_filter_property_text_80271348_v6.cpp"
// Partial editor view; field identity and complete original sizeof are unknown.
struct d10b_TextEditor { unsigned char unknown00[36]; int kind; };
extern "C" void d10b_edit_string_802796d4(Ptr32<d10b_TextEditor>,Ptr32<const char>);
extern "C" void d10b_edit_vector_80279dc0(Ptr32<d10b_TextEditor>,Ptr32<const char>);
extern "C" void d10b_edit_integer_8027a248(Ptr32<d10b_TextEditor>,Ptr32<const char>);
extern "C" void d10b_edit_float_8027a2c4(Ptr32<d10b_TextEditor>,Ptr32<const char>);
extern "C" void d10b_edit_color_80279f54(Ptr32<d10b_TextEditor>,Ptr32<const char>);
extern "C" void d10b_edit_name_8027a8a4(Ptr32<d10b_TextEditor>,Ptr32<const char>);
extern "C" void d10b_filter_property_text_80271348(Ptr32<d10b_TextEditor> self,Ptr32<char> text) {
    int index=0;
    Ptr32<char> output=text;
    while (text[index]) {
        if (static_cast<unsigned char>(text[index])>=32 && static_cast<unsigned char>(text[index])<127 && text[index]!=38) *output++=text[index];
        ++index;
    }
    if (index) *output=0;
    switch (self->kind) {
    case 20: d10b_edit_string_802796d4(self,text); break;
    case 21: d10b_edit_vector_80279dc0(self,text); break;
    case 24: d10b_edit_integer_8027a248(self,text); break;
    case 25: d10b_edit_float_8027a2c4(self,text); break;
    case 22: d10b_edit_color_80279f54(self,text); break;
    case 34: d10b_edit_name_8027a8a4(self,text); break;
    }
}


