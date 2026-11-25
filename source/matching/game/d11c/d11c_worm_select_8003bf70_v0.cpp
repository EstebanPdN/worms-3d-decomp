// d11c: 0x8003bf70 (384 bytes), set up the worm-select HUD handle and its arrow.
// Observed in the original DOL: the word at +92 is set to 1; the handle at +28
// is named from a temporary engine string of "HUD.WormSelect" (0x803743c4) (flags 255 through
// 0x8015adf4; the string is destroyed by 0x8020c5c4 then 0x80341588) and its
// virtual slot +84 receives a stack vector filled through a pointer with the
// float 0x803743f4 (5.0f) in all three words, and 0; the handle at +36 is named "HUD.SelectWormArrow" (0x803743d4)
// and slot +84 receives the vector object 0x804273c8 and 0. A third temporary string
// of the same literal is resolved through 0x8015ae3c and cast through
// 0x80343808; the two pooled pairs from 0x80171ff8 and 0x80171fa0 receive
// (0x803743f8 = 1.0f, 0x803743fc = 2.0f) and (0x80374400 = 0.0f, 0x80374404 = -1.0f). Finally slot +92 of
// the +28 handle receives the +36 handle and 0x803743e8 "Locator1". Float values were
// decoded from the DOL; the vector object is referenced as an unowned external.
// All names and views are inferred; unknown words are partial views.
struct d11c_Vec3 {
    float x, y, z;
};
struct d11c_Handle;
struct d11c_HandleVtable {
    void *unknown00[21];
    void (*set_scale)(d11c_Handle *, const d11c_Vec3 &, int);   // +84
    void *unknown58;
    void (*attach)(d11c_Handle *, d11c_Handle *, const char *);  // +92
};
struct d11c_Handle { d11c_HandleVtable *vtable; };
struct d11c_WormSelect {
    unsigned char unknown00[28];
    d11c_Handle *select;                 // +28
    unsigned char unknown20[4];
    d11c_Handle *arrow;                  // +36
    unsigned char unknown28[52];
    int active;                          // +92
};
struct d11c_String_8020bb54 {
 d11c_String_8020bb54(const d11c_String_8020bb54 &);
    const char *text;
    d11c_String_8020bb54(const char *s);
    ~d11c_String_8020bb54();
};
extern "C" {
void d11c_string_base_finish_8020c5c4(void *);
void d11c_string_release_80341588(void *);
void * d11c_handle_set_name_8015adf4(d11c_String_8020bb54 *, d11c_Handle **, unsigned int);
void *d11c_service_lookup_8015ae3c(d11c_String_8020bb54 *);
void *d11c_cast_80343808(void *);
float *d11c_pooled_a_80171ff8(void *);
float *d11c_pooled_b_80171fa0(void *);
extern char d11c_worm_select_803743c4[], d11c_select_arrow_803743d4[], d11c_locator1_803743e8[];
extern const float d11c_f32_803743f4[], d11c_f32_803743f8[], d11c_f32_803743fc[], d11c_f32_80374400[], d11c_f32_80374404[];
extern d11c_Vec3 d11c_arrow_scale_804273c8;
}
inline d11c_String_8020bb54::~d11c_String_8020bb54() { d11c_string_base_finish_8020c5c4(this); d11c_string_release_80341588(this); }
extern "C" void d11c_worm_select_8003bf70(d11c_WormSelect *self) {
    self->active = 1;
    {
        d11c_String_8020bb54 name(d11c_worm_select_803743c4);
        d11c_handle_set_name_8015adf4(&name, &self->select, 255);
    }
    d11c_Vec3 scale;
    d11c_Vec3 *p = &scale;
    p->x = d11c_f32_803743f4[0];
    p->y = d11c_f32_803743f4[0];
    p->z = d11c_f32_803743f4[0];
    self->select->vtable->set_scale(self->select, scale, 0);
    {
        d11c_String_8020bb54 name(d11c_select_arrow_803743d4);
        d11c_handle_set_name_8015adf4(&name, &self->arrow, 255);
    }
    self->arrow->vtable->set_scale(self->arrow, d11c_arrow_scale_804273c8, 0);
    void *service;
    {
        d11c_String_8020bb54 name(d11c_select_arrow_803743d4);
        service = d11c_service_lookup_8015ae3c(&name);
    }
    void *object = d11c_cast_80343808(service);
    float *a = d11c_pooled_a_80171ff8(object);
    a[0] = d11c_f32_803743f8[0];
    a[1] = d11c_f32_803743fc[0];
    float *b = d11c_pooled_b_80171fa0(object);
    b[0] = d11c_f32_80374400[0];
    b[1] = d11c_f32_80374404[0];
    self->select->vtable->attach(self->select, self->arrow, d11c_locator1_803743e8);
}
