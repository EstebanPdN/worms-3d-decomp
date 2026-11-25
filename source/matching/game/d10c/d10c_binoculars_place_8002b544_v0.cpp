// d10c: 0x8002b544 (232 bytes), name the owner's handle "HUD.Binoculars" and
// place it at a blend of two screen positions by the global zoom fraction.
// Observed in the original DOL: a temporary engine string from the original
// literal "HUD.Binoculars" (0x803725a0) names the handle at +32 with flags 255
// and is destroyed (0x8020c5c4 then 0x80341588). The fraction is the float at
// +184 of the r13 object 0x804b1788. Pool constants decoded from the DOL:
// 0x803725b0 = 1.0f, 0x803725b4 = 360.0f, 0x803725b8 = 320.0f,
// 0x803725bc = 270.0f, 0x803725c0 = 240.0f (this function's own pool).
// The handle's virtual slot +84 receives the position and 0, then slot +88
// receives 0. All names and views are inferred; unknown words are partial views.
struct d10c_Vec3 {
    float x, y, z;
    d10c_Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
struct d10c_Handle;
struct d10c_HandleVtable {
    void *unknown00[21];
    void (*set_position)(d10c_Handle *, const d10c_Vec3 &, int);   // +84
    void (*set_state)(d10c_Handle *, int);                          // +88
};
struct d10c_Handle { d10c_HandleVtable *vtable; };
struct d10c_ZoomState {
    unsigned char unknown00[184];
    float fraction;                      // +184
};
extern "C" {
void d10c_string_from_text_8020bb54(void *, const char *);
void d10c_string_base_finish_8020c5c4(void *);
void d10c_string_release_80341588(void *);
extern const char d10c_hud_binoculars_803725a0[];
extern d10c_ZoomState *d10c_zoom_state_804b1788;
}
struct d10c_String {
    const char *text;
    int unknown04;
    d10c_String(const char *s) { d10c_string_from_text_8020bb54(this, s); }
    ~d10c_String() { d10c_string_base_finish_8020c5c4(this); d10c_string_release_80341588(this); }
};
struct d10c_BinocularsOwner {
    unsigned char unknown00[32];
    d10c_Handle *handle;                 // +32
};
extern "C" void d10c_handle_set_name_8015adf4(d10c_String *, d10c_Handle **, unsigned int);
static inline void d10c_name_handle(d10c_BinocularsOwner *owner, const char *text) {
    d10c_String name(text);
    d10c_handle_set_name_8015adf4(&name, &owner->handle, 255);
}
static inline void d10c_place(d10c_Handle *h, const d10c_Vec3 &p) {
    h->vtable->set_position(h, p, 0);
}
extern "C" void d10c_binoculars_place_8002b544(d10c_BinocularsOwner *self) {
    d10c_name_handle(self, d10c_hud_binoculars_803725a0);
    float t = d10c_zoom_state_804b1788->fraction;
    d10c_place(self->handle, d10c_Vec3(t * 360.0f + (1.0f - t) * 320.0f, t * 270.0f + (1.0f - t) * 240.0f, 1.0f));
    self->handle->vtable->set_state(self->handle, 0);
}
