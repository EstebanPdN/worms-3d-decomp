// d16c: 0x800e2118 (160 bytes). Load the "NULL" resource into a text owner's
// handle, attach it to a target through the target's virtual slot +92, and
// mark the owner attached (+180 |= 16) and wide (|= 32) on request.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return; GCC 2.95 then loads the temporary string
// address last, as in the original.
struct d16c_Target;
struct d16c_TargetVtable {
    void *unknown00[23];
    void (*attach)(d16c_Target *, void *, int);   // +92
};
struct d16c_Target { d16c_TargetVtable *vtable; };

// Shared engine string; constructor and release are out of line.
struct d16c_String_8020bb54 {
 d16c_String_8020bb54(const d16c_String_8020bb54 &);
    char *text;
    d16c_String_8020bb54(const char *);
    ~d16c_String_8020bb54();
};
extern "C" void d16c_string_finish_8020c5c4(d16c_String_8020bb54 *);
extern "C" void d16c_string_release_80341588(d16c_String_8020bb54 *);
inline d16c_String_8020bb54::~d16c_String_8020bb54() {
    d16c_string_finish_8020c5c4(this);
    d16c_string_release_80341588(this);
}

extern const char d16c_null_text_80389efc[];   // "NULL"

struct d16c_TextOwner {
    unsigned char unknown000[180];
    unsigned int flags;                  // +180
    unsigned char unknown184[116];
    void *handle;                        // +300
};

extern "C" int d16c_handle_load_8015adf4(const d16c_String_8020bb54 *, void **, unsigned char);

extern "C" void d16c_text_attach_800e2118(d16c_TextOwner *self, d16c_Target *target, int *value, int wide) {
    {
        d16c_String_8020bb54 name(d16c_null_text_80389efc);
        d16c_handle_load_8015adf4(&name, &self->handle, 255);
    }
    target->vtable->attach(target, self->handle, *value);
    self->flags |= 16;
    if (wide) self->flags |= 32;
}
