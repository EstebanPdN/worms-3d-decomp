// d24d: 0x8015a0d4 (712 bytes). Constructor of a water-target camera object: named
// text (+60, one-word string, default ctor 0x803426b8, assign 0x8020bd38 returns the
// string), value +48, three vectors (+4, +16, +28), and four retained settings: the
// camera mode and water target through 0x80342a78, the active worm through 0x803426b4
// and the water level through 0x80342a74. Each lookup (0x800fc1b0) uses a one-word
// holder; the slots at +8 and +16 follow from the first three sitting in an inline
// helper (d24c recipe), so no second word is needed. Real polymorphic class with
// data first, so the vtable 0x80410ff0 sits at +72. Pool at 0x803a41fc.
struct d24d_Object { void **vtable; };
struct d24d_Vec3 { float x, y, z; void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct d24d_Ptr { d24d_Object *value; d24d_Ptr() { value = 0; }
  void operator=(d24d_Object *o) { if (o) ((void (*)(d24d_Object *))o->vtable[3])(o); if (value) ((void (*)(d24d_Object *))value->vtable[4])(value); value = o; } };
struct d24d_Ref { d24d_Object *value; d24d_Ref() { value = 0; } ~d24d_Ref() { if (value) ((void (*)(d24d_Object *))value->vtable[4])(value); } };
struct d24d_String_803426b8 { char *text; d24d_String_803426b8(); d24d_String_803426b8 &assign(const char *); };
struct d24d_SettingKey { const char *name; };
extern "C" int d24d_setting_lookup_800fc1b0(d24d_SettingKey *, d24d_Ref *);
extern "C" d24d_Object *d24d_view_a_80342a78(d24d_Object *);
extern "C" d24d_Object *d24d_view_b_803426b4(d24d_Object *);
extern "C" d24d_Object *d24d_view_c_80342a74(d24d_Object *);
extern const char d24d_camera_mode_803a41b4[], d24d_active_worm_803a41c8[], d24d_water_target_803a41d8[], d24d_water_level_803a41f0[];
struct d24d_WaterTarget {
    int f0;
    d24d_Vec3 a, b, c;
    d24d_Ptr p40;
    int f44;
    int f48;
    int f52;
    d24d_Ptr p56;
    d24d_String_803426b8 name;
    d24d_Ptr p64;
    d24d_Ptr p68;
    d24d_WaterTarget(const char *text, int v);
    virtual void key();
};
template<d24d_Object *(*cast)(d24d_Object *)> inline void d24d_bind_setting(d24d_Ptr &dest, const char *name) {
    d24d_Ref t;
    d24d_SettingKey k; k.name = name;
    d24d_setting_lookup_800fc1b0(&k, &t);
    dest = cast(t.value);
}
d24d_WaterTarget::d24d_WaterTarget(const char *text, int v) {
    f48 = v;
    name.assign(text);
    f52 = 0;
    a.set(0.0f, 40.0f, 200.0f);
    b.set(0.0f, 40.0f, 300.0f);
    c.set(0.0f, 1.0f, 0.0f);
    d24d_Ref last;
    d24d_bind_setting<d24d_view_a_80342a78>(p40, d24d_camera_mode_803a41b4);
    d24d_bind_setting<d24d_view_b_803426b4>(p56, d24d_active_worm_803a41c8);
    d24d_bind_setting<d24d_view_a_80342a78>(p68, d24d_water_target_803a41d8);
    d24d_SettingKey k; k.name = d24d_water_level_803a41f0;
    d24d_setting_lookup_800fc1b0(&k, &last);
    p64 = d24d_view_c_80342a74(last.value);
}
