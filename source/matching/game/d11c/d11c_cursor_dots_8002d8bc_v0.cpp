// d11c: 0x8002d8bc (320 bytes), set up the airstrike cursor resources and its
// five dot handles.
// Observed in the original DOL: 0x8004e0dc receives the cursor and the original
// literals "Airstrike.Cursor.Mesh" (0x80372a94), "Airstrike.Cursor.Bitmap"
// (0x80372aac), "Aimer_Null" (0x80372ac4), "Airstrike_Intro" (0x80372ad0),
// "Cursor_Loop" (0x80372ae0) and "Cursor_Error" (0x80372aec). Then, five
// times, a zeroed handle is named from a temporary engine string of
// "Airstrike.Cursor.Dot" (0x80372afc) through 0x8015adf4 (flags 255; string
// destroyed by 0x8020c5c4 then 0x80341588), cast through 0x8034357c, retained
// (slot +12) into dots[i] at +92 releasing the previous one (slot +16), and
// passed with the i-th word of the table 0x803f3c68 ("Dot_Null_01".."05") to
// slot +92 of the object at +28; the handle is released (slot +16) at the end
// of each iteration. All names and views are inferred; unknown words are
// partial views.
struct d11c_Ref;
struct d11c_RefVtable {
    void *unknown00[3];
    void (*retain)(d11c_Ref *);          // +12
    void (*release)(d11c_Ref *);         // +16
};
struct d11c_Ref { d11c_RefVtable *vtable; };
struct d11c_Mesh;
struct d11c_MeshVtable {
    void *unknown00[23];
    void (*attach)(d11c_Mesh *, d11c_Ref *, const char *);   // +92
};
struct d11c_Mesh { d11c_MeshVtable *vtable; };
struct d11c_Cursor {
    unsigned char unknown00[28];
    d11c_Mesh *mesh;                     // +28
    unsigned char unknown20[60];
    d11c_Ref *dots[5];                   // +92..+108
};
extern "C" {
void d11c_string_base_finish_8020c5c4(void *);
void d11c_string_release_80341588(void *);
void d11c_cursor_setup_8004e0dc(d11c_Cursor *, const char *, const char *, const char *, const char *, const char *, const char *);
d11c_Ref *d11c_cast_8034357c(d11c_Ref *);
extern char d11c_mesh_80372a94[], d11c_bitmap_80372aac[], d11c_aimer_80372ac4[], d11c_intro_80372ad0[], d11c_loop_80372ae0[], d11c_error_80372aec[];
extern char d11c_dot_80372afc[];
extern const char *d11c_dot_nulls_803f3c68[];
}
struct d11c_String_8020bb54 {
 d11c_String_8020bb54(const d11c_String_8020bb54 &);
    const char *text;
    d11c_String_8020bb54(const char *s);
    ~d11c_String_8020bb54() { d11c_string_base_finish_8020c5c4(this); d11c_string_release_80341588(this); }
};
struct d11c_Handle {
    d11c_Ref *object;
    d11c_Handle() : object(0) {}
    ~d11c_Handle() { if (object) object->vtable->release(object); }
};
extern "C" void * d11c_handle_set_name_8015adf4(d11c_String_8020bb54 *, d11c_Handle *, unsigned int);
static inline void d11c_assign(d11c_Ref **slot, d11c_Ref *value) {
    if (value) value->vtable->retain(value);
    if (*slot) (*slot)->vtable->release(*slot);
    *slot = value;
}
extern "C" void d11c_cursor_dots_8002d8bc(d11c_Cursor *self) {
    d11c_cursor_setup_8004e0dc(self, d11c_mesh_80372a94, d11c_bitmap_80372aac, d11c_aimer_80372ac4, d11c_intro_80372ad0, d11c_loop_80372ae0, d11c_error_80372aec);
    for (unsigned int i = 0; i < 5; i++) {
        d11c_Handle handle;
        {
            d11c_String_8020bb54 name(d11c_dot_80372afc);
            d11c_handle_set_name_8015adf4(&name, &handle, 255);
        }
        d11c_Ref *dot = d11c_cast_8034357c(handle.object);
        d11c_assign(&self->dots[i], dot);
        self->mesh->vtable->attach(self->mesh, dot, d11c_dot_nulls_803f3c68[i]);
    }
}
