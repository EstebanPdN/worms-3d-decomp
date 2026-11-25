// d10c: 0x8003a6e8 (136 bytes), name an owner's handle "Pigeon" and hand the
// handle a member view of a looked-up object.
// Observed in the original DOL: a temporary engine string built from the
// original literal "Pigeon" (0x8037424c) names the handle at +28 with flags 255
// and is destroyed (0x8020c5c4 then 0x80341588); the id word at +32 is resolved
// through 0x80164fc8 (returns the slot's object pointer or 0); 0x8003af58
// returns that object's address plus 28; the handle object's virtual slot +76
// then receives that address and 0.
// All names and views are inferred; unknown words are not recovered layout.
struct d10c_Object;
struct d10c_ObjectVtable {
    void *unknown00[19];
    void (*attach)(d10c_Object *, void *, int);   // +76
};
struct d10c_Object { d10c_ObjectVtable *vtable; };
struct d10c_Target;
extern "C" {
void * d10c_string_from_text_8020bb54(void *, const char *);
void d10c_string_base_finish_8020c5c4(void *);
void d10c_string_release_80341588(void *);
d10c_Target *d10c_lookup_handle_object_80164fc8(int);
void *d10c_target_member_8003af58(d10c_Target *);
extern const char d10c_pigeon_8037424c[];
}
struct d10c_String {
 d10c_String(const d10c_String &);
    const char *text;
    d10c_String(const char *s) { d10c_string_from_text_8020bb54(this, s); }
    ~d10c_String() { d10c_string_base_finish_8020c5c4(this); d10c_string_release_80341588(this); }
};
struct d10c_PigeonOwner {
    unsigned char unknown00[28];
    d10c_Object *handle;                 // +28
    int target_id;                       // +32
};
extern "C" void * d10c_handle_set_name_8015adf4(d10c_String *, d10c_Object **, unsigned int);
static inline void d10c_name_handle(d10c_PigeonOwner *owner, const char *text) {
    d10c_String name(text);
    d10c_handle_set_name_8015adf4(&name, &owner->handle, 255);
}
extern "C" void d10c_pigeon_name_8003a6e8(d10c_PigeonOwner *self) {
    d10c_name_handle(self, d10c_pigeon_8037424c);
    d10c_Target *target = d10c_lookup_handle_object_80164fc8(self->target_id);
    d10c_Object *handle = self->handle;
    handle->vtable->attach(handle, d10c_target_member_8003af58(target), 0);
}
