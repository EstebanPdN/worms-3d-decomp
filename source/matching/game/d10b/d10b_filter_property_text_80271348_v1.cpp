// Partial editor view; field identity and complete original sizeof are unknown.
struct d10b_TextEditor { unsigned char unknown00[36]; int kind; };
extern "C" void d10b_edit_string_802796d4(d10b_TextEditor *,const char *);
extern "C" void d10b_edit_vector_80279dc0(d10b_TextEditor *,const char *);
extern "C" void d10b_edit_integer_8027a248(d10b_TextEditor *,const char *);
extern "C" void d10b_edit_float_8027a2c4(d10b_TextEditor *,const char *);
extern "C" void d10b_edit_color_80279f54(d10b_TextEditor *,const char *);
extern "C" void d10b_edit_name_8027a8a4(d10b_TextEditor *,const char *);
extern "C" void d10b_filter_property_text_80271348(d10b_TextEditor *self,char *text) {
    int index=0;
    char *output=text;
    for (;;) {
        unsigned int value=static_cast<unsigned char>(text[index]);
        if (!value) break;
        if (value-32U<95U && value!=38U) *output++=value;
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
