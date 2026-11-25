/* HUD text setup, transforms and backing geometry. */
extern "C" {
struct S2HudObject { void **vtable; };
struct S2HudVec2 { float x, y; void set(float a, float b) { x = a; y = b; } };
struct S2HudVec3 { float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    S2HudVec3() {}
    S2HudVec3(float a, float b, float c) { x = a; y = b; z = c; }
    S2HudVec3(const S2HudVec3 &v) { x = v.x; y = v.y; z = v.z; }
    S2HudVec3 operator+(const S2HudVec3 &v) const { return S2HudVec3(x + v.x, y + v.y, z + v.z); }
};
struct S2Hud { void *vtable; unsigned char pad04[24]; S2HudObject *font, *backing; S2HudVec3 offset; S2HudObject *resource; S2HudVec3 scale; int enabled; unsigned int color, style; S2HudObject *maximum, *minimum; };
struct S2HudString { char *text; int reserved; };
struct S2HudKey { const char *text; };
struct S2HudRef { S2HudObject *value; int reserved;
    S2HudRef() { value = 0; }
    ~S2HudRef() { if (value) ((void (*)(S2HudObject *))value->vtable[4])(value); }
};
inline void s2_hud_assign(S2HudObject *&slot, S2HudObject *replacement) {
    if (replacement) ((void (*)(S2HudObject *))replacement->vtable[3])(replacement);
    if (slot) ((void (*)(S2HudObject *))slot->vtable[4])(slot);
    slot = replacement;
}
int w3d_actor_base_initialize(S2Hud *);
void w3d_actor_base_destroy(S2Hud *, int);
void w3d_hud_text_destroy_8011aa98(S2Hud *, int);
void w3d_ctor_8015fef0(S2Hud *);
void w3d_base_destroy_8015ff2c(S2Hud *, int);
void w3d_string_from_text(S2HudString *, const char *);
void w3d_string_base_finish(S2HudString *);
void w3d_string_release(S2HudString *);
void w3d_handle_set_name(S2HudString *, S2HudObject **, unsigned int);
S2HudObject *w3d_empty_80343580(S2HudObject *);
S2HudObject *w3d_empty_8034380c(S2HudObject *);
S2HudObject *w3d_empty_80342a74(S2HudObject *);
void w3d_constructor_lookup_name(S2HudKey *, S2HudObject **);
int w3d_auto_8018c5b0(S2HudObject *, void *);
int w3d_fn_8018d35c(S2HudObject *, unsigned int *);
int w3d_fn_8018d434(S2HudObject *, unsigned int *);
float w3d_fn_8018c8bc(S2HudObject *);
float w3d_getf_8018ca14(S2HudObject *);
S2HudVec2 *w3d_fn_8018963c(S2HudObject *);
S2HudVec3 *w3d_fn_80189518(S2HudObject *);
int w3d_fn_80189450(S2HudObject *, int);
int w3d_fn_8018920c(S2HudObject *, int);
unsigned char *w3d_fn_80189828(S2HudObject *);
S2HudVec2 *w3d_fn_80189884(S2HudObject *);
S2HudVec2 *w3d_fn_801898e0(S2HudObject *);
extern unsigned char w3d_obj_80410990[], w3d_obj_804109d0[], w3d_obj_80410a20[];
extern S2Hud *w3d_obj_804ab004;
extern unsigned int w3d_obj_804af3b0, w3d_obj_804af3b4;
extern const char w3d_str_8039adb4[], w3d_str_8039adbc[], w3d_str_8039ae48[], w3d_str_8039ae64[];
extern const float w3d_f32_8039adcc[];
extern const float w3d_f32_8039ae80[];


S2Hud *w3d_hud_manager_construct_80119e10(S2Hud *self)
{
    struct { int a, b; } scratch;
    w3d_actor_base_initialize(self);
    self->vtable = w3d_obj_80410990;
    w3d_obj_804ab004 = self;
    return self;
}


void w3d_hud_manager_destroy_80119e50(S2Hud *self, int flags)
{
    self->vtable = w3d_obj_80410990;
    w3d_obj_804ab004 = 0;
    w3d_actor_base_destroy(self, flags);
}


void w3d_hud_derived_destroy_8011a108(S2Hud *self, int flags)
{
    S2Hud *object = self;
    object->vtable = w3d_obj_804109d0;
    w3d_hud_text_destroy_8011aa98(self, flags);
}


#if 0 /* 2 attempts; string and reference temporary stack layout differs */
void w3d_hud_load_assets_8011a1c8(S2Hud *self)
{
    s2_hud_assign(self->font, 0);
    S2HudObject **backing = &self->backing;
    s2_hud_assign(*backing, 0);
    struct { S2HudString name; S2HudObject *temporary; int reserved; } local;
    w3d_string_from_text(&local.name, w3d_str_8039adb4);
    local.temporary = 0;
    w3d_handle_set_name(&local.name, &local.temporary, 58);
    S2HudObject *font = w3d_empty_80343580(local.temporary);
    if (font) ((void (*)(S2HudObject *))font->vtable[3])(font);
    if (self->font) ((void (*)(S2HudObject *))self->font->vtable[4])(self->font);
    self->font = font;
    if (local.temporary) ((void (*)(S2HudObject *))local.temporary->vtable[4])(local.temporary);
    w3d_string_base_finish(&local.name);
    w3d_string_release(&local.name);
    w3d_string_from_text(&local.name, w3d_str_8039adbc);
    w3d_handle_set_name(&local.name, backing, 56);
    w3d_string_base_finish(&local.name);
    w3d_string_release(&local.name);
}
#endif


/* This file's literal pool is proved from 0x8039add0 on. The zero at 0x8039adcc
   sits 4 past an 8-byte boundary, after strings still referenced as externs, so
   it stays extern until those strings are owned here. 0x8011a5c8 needs the pool
   head in one object: its conversion double at 0x8039ae00 fixes the alignment. */
void w3d_hud_reset_transform_8011a304(S2Hud *self)
{
    float zero = w3d_f32_8039adcc[0];
    float size = 20.0f;
    self->offset.set(zero, zero, zero);
    S2HudVec3 scale(size, size, size);
    ((void (*)(S2HudObject *, S2HudVec3 *, int))self->font->vtable[21])(self->font, &scale, 0);
}


void w3d_hud_clear_assets_8011a370(S2Hud *self)
{
    s2_hud_assign(self->font, 0);
    s2_hud_assign(self->backing, 0);
}


void w3d_hud_update_backing_8011a3dc(S2Hud *self, void * arg_r4)
{
    w3d_auto_8018c5b0(self->font, arg_r4);
    w3d_fn_8018d35c(self->font, &self->color);
    w3d_fn_8018d434(self->font, &self->style);
    float extent = (w3d_fn_8018c8bc(self->font) + 1.0f) * 0.5f;
    w3d_getf_8018ca14(self->font);
    S2HudObject *mesh = w3d_empty_8034380c(self->backing);
    S2HudVec2 *first = w3d_fn_8018963c(mesh);
    float u = 5.0f, v = 16.0f;
    first[0].set(u, v);
    w3d_fn_8018963c(mesh)[1].set(extent, v);
    w3d_fn_8018963c(mesh)[2].set(u, v);
    S2HudVec3 *vertices = w3d_fn_80189518(mesh);
    float left = -5.0f, zero = 0.0f;
    vertices[0].set(left - extent, zero, zero);
    w3d_fn_80189518(mesh)[1].set(zero, zero, zero);
    w3d_fn_80189518(mesh)[2].set(extent + u, zero, zero);
}


#if 0 /* 2 attempts; vector temporary copying and load scheduling differ */
void w3d_hud_set_position_8011a51c(S2Hud *self, const S2HudVec3 *position)
{
    if (self->backing) {
        ((void (*)(S2HudObject *, const S2HudVec3 *, int))self->backing->vtable[19])(self->backing, position, 0);
        S2HudVec3 temporary;
        temporary.x = position->x + self->offset.x;
        temporary.y = position->y + self->offset.y;
        temporary.z = position->z + self->offset.z;
        S2HudVec3 sum(temporary);
        ((void (*)(S2HudObject *, const S2HudVec3 *, int))self->font->vtable[19])(self->font, &sum, 0);
    }
}
#endif


void w3d_d43p_hud_build_backing_8011a5c8(S2Hud *self)
{
    S2HudObject *mesh = w3d_empty_8034380c(self->backing);
    w3d_fn_80189450(mesh, 3);
    w3d_fn_8018920c(mesh, 3);
    S2HudVec3 v;
    S2HudVec3 *pv = &v;
    v.x = 1.0f;
    pv->y = 1.0f;
    pv->z = 1.0f;
    ((void (*)(S2HudObject *, S2HudVec3 *, int))mesh->vtable[21])(mesh, pv, 0);
    for (unsigned i = 0; i < 3; i++) {
        w3d_fn_80189828(mesh)[i] = i;
        S2HudVec2 *a = &w3d_fn_8018963c(mesh)[i];
        a->x = 5.0f;
        a->y = 16.0f;
        w3d_fn_80189518(mesh)[i].set(15.0f, 0.0f, 0.0f);
        S2HudVec2 *b = &w3d_fn_80189884(mesh)[i];
        b->x = (float)i * 10.0f * 0.03125f;
        b->y = 0.0f;
        S2HudVec2 *c = &w3d_fn_801898e0(mesh)[i];
        c->set(0.3125f, 1.0f);
    }
}


#if 0 /* 2 attempts; field initialization and property-key setup scheduling differ */
S2Hud *w3d_hud_text_construct_8011a918(S2Hud *self)
{
    w3d_ctor_8015fef0(self);
    self->vtable = w3d_obj_80410a20;
    self->scale.set(w3d_f32_8039ae80[0], w3d_f32_8039ae80[0], w3d_f32_8039ae80[0]);
    self->font = 0;
    self->backing = 0;
    self->resource = 0;
    self->maximum = 0;
    self->minimum = 0;
    self->color = w3d_obj_804af3b0;
    self->style = w3d_obj_804af3b4;
    {
        S2HudRef temporary;
        S2HudKey key;
        key.text = w3d_str_8039ae48;
        w3d_constructor_lookup_name(&key, &temporary.value);
        s2_hud_assign(self->maximum, w3d_empty_80342a74(temporary.value));
    }
    {
        S2HudRef temporary;
        S2HudKey key;
        key.text = w3d_str_8039ae64;
        w3d_constructor_lookup_name(&key, &temporary.value);
        s2_hud_assign(self->minimum, w3d_empty_80342a74(temporary.value));
    }
    self->enabled = 1;
    return self;
}
#endif


void w3d_hud_text_destroy_8011aa98(S2Hud *self, int flags)
{
    self->vtable = w3d_obj_80410a20;
    if (self->minimum) ((void (*)(S2HudObject *))self->minimum->vtable[4])(self->minimum);
    if (self->maximum) ((void (*)(S2HudObject *))self->maximum->vtable[4])(self->maximum);
    if (self->resource) ((void (*)(S2HudObject *))self->resource->vtable[4])(self->resource);
    if (self->backing) ((void (*)(S2HudObject *))self->backing->vtable[4])(self->backing);
    if (self->font) ((void (*)(S2HudObject *))self->font->vtable[4])(self->font);
    w3d_base_destroy_8015ff2c(self, flags);
}

}
