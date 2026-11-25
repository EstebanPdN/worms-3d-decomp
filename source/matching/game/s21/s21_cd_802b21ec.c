// desc: Appears to call the error callback of the owner with this object and a text when the text at offset 48 of the linked record is not empty.
struct S21Callbacks { char pad[28]; void (*report)(void *, const char *); };
struct S21Record { char pad[48]; const char *text; };
struct S21Object { char pad[12]; struct S21Record *record; char pad1[164]; struct S21Callbacks *callbacks; };
void w3d_s21_report_text_802b21ec(struct S21Object *self)
{
    const char *text = self->record->text;
    if (*(unsigned short *)(text - 4))
        self->callbacks->report(self, text);
}
