struct K6bString { char *text; };
struct K6bStringHeader { unsigned short refs; unsigned short length; };
extern void w3d_string_base_init(struct K6bString *string);
extern int sprintf(char *buffer, const char *format, ...);
extern struct K6bStringHeader *w3d_string_allocate(struct K6bString *string, int size);
extern void *w3d_memcpy_802eee50();
extern char lbl_803b3168[];
struct K6bString *w3d_k6b_string_from_int_8020bcc0(struct K6bString *self, int value)
{
    char buffer[16];
    int length;
    w3d_string_base_init(self);
    length = sprintf(buffer, lbl_803b3168, value);
    w3d_string_allocate(self, length + 1)->length = length;
    w3d_memcpy_802eee50(self->text, buffer, length + 1);
    return self;
}
// desc: w3d_k6b_string_from_int_8020bcc0: Appears to construct a shared string from an integer formatted with 0x803b3168 through sprintf.
