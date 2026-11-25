#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cd_802b21ec.c"
// desc: Appears to call the error callback of the owner with this object and a text when the text at offset 48 of the linked record is not empty.
struct S21Callbacks { char pad[28]; Ptr32<void (Ptr32<void>, Ptr32<const char>)> report; };
struct S21Record { char pad[48]; Ptr32<const char> text; };
struct S21Object { char pad[12]; Ptr32<struct S21Record> record; char pad1[164]; Ptr32<struct S21Callbacks> callbacks; };
void w3d_s21_report_text_802b21ec(Ptr32<struct S21Object> self)
{
    Ptr32<const char> text = self->record->text;
    if (*(Ptr32<unsigned short>)(text - 4))
        self->callbacks->report(self, text);
}

}
