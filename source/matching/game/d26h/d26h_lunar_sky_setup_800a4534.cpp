// GWMP8P rev0 0x800a4534. Sky and water resource names for the lunar day
// set. Names are inferred. String is one word with a user copy constructor.
// The float assignment 0x800fc4c8 returns a value in r3, so it is declared
// returning int.
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    const char *text;
    String();
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
extern "C" void w3d_string_format_8020c510(String *, const char *, ...);
struct Key { const char *name; Key(const char *n) { name = n; } };
extern "C" int property_read_800fc550(Key *, const char *);
extern "C" int float_assign_800fc4c8(Key *, float);
extern "C" void *service_forward_8020b680(void *);
extern "C" int submit_80164514(void *, void *, int);
extern unsigned char g_80410680[], g_8040fb28[];
extern void *g_804b178c;
struct Level { unsigned char u[20]; int id; };
extern "C" void d26h_lunar_sky_setup_800a4534(Level *self) {
    String world;
    String time;
    w3d_string_format_8020c510(&world, "LUNAR");
    w3d_string_format_8020c510(&time, "DAY");
    String sky;
    String water;
    String offs;
    String gradient;
    String tweak;
    String detail;
    unsigned short initial = (unsigned char)world.text[0] << 8;
    w3d_string_format_8020c510(&sky, "%s.%sSky", world.text, time.text);
    w3d_string_format_8020c510(&water, "%s.%sWater", world.text, time.text);
    w3d_string_format_8020c510(&offs, "%s.%sWaterOffs", world.text, time.text);
    w3d_string_format_8020c510(&gradient, "LightGradient_%s_%s", &initial, time.text);
    w3d_string_format_8020c510(&tweak, "Water.%s.%s", world.text, time.text);
    w3d_string_format_8020c510(&detail, "%s.%sWaterDetail", world.text, time.text);
    Key k1("Land.SkyBoxResource");
    property_read_800fc550(&k1, sky.text);
    Key k2("Land.WaterResource");
    property_read_800fc550(&k2, water.text);
    Key k3("Land.WaterOffsetResource");
    property_read_800fc550(&k3, offs.text);
    Key k4("Land.LightGradientResource");
    property_read_800fc550(&k4, gradient.text);
    Key k5("Water.TweakName");
    property_read_800fc550(&k5, tweak.text);
    Key k6("Land.WaterDetailResource");
    property_read_800fc550(&k6, detail.text);
    Key k7("Water.Level");
    float_assign_800fc4c8(&k7, -15.0f);
    {
        void *a = service_forward_8020b680(g_80410680);
        submit_80164514(g_804b178c, a, self->id);
    }
    {
        void *b = service_forward_8020b680(g_8040fb28);
        submit_80164514(g_804b178c, b, self->id);
    }
}
