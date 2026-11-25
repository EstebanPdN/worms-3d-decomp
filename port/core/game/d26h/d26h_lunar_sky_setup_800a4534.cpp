#include "w3d_ptr.h"
#line 1 "d26h_lunar_sky_setup_800a4534.cpp"
// GWMP8P rev0 0x800a4534. Sky and water resource names for the lunar day
// set. Names are inferred. String is one word with a user copy constructor.
// The float assignment 0x800fc4c8 returns a value in r3, so it is declared
// returning int.
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<const char> text;
    String();
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
extern "C" void w3d_string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) { name = n; } };
extern "C" int property_read_800fc550(Ptr32<Key>, Ptr32<const char>);
extern "C" int float_assign_800fc4c8(Ptr32<Key>, float);
extern "C" Ptr32<void> service_forward_8020b680(Ptr32<void>);
extern "C" int submit_80164514(Ptr32<void>, Ptr32<void>, int);
extern unsigned char g_80410680[], g_8040fb28[];
extern Ptr32<void> g_804b178c;
struct Level { unsigned char u[20]; int id; };
extern "C" void d26h_lunar_sky_setup_800a4534(Ptr32<Level> self) {
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
    unsigned short initial = (unsigned char)world.text[0];
    w3d_string_format_8020c510(&sky, "%s.%sSky", w3d::VA(world.text), w3d::VA(time.text));
    w3d_string_format_8020c510(&water, "%s.%sWater", w3d::VA(world.text), w3d::VA(time.text));
    w3d_string_format_8020c510(&offs, "%s.%sWaterOffs", w3d::VA(world.text), w3d::VA(time.text));
    w3d_string_format_8020c510(&gradient, "LightGradient_%s_%s", w3d::VA(&initial), w3d::VA(time.text));
    w3d_string_format_8020c510(&tweak, "Water.%s.%s", w3d::VA(world.text), w3d::VA(time.text));
    w3d_string_format_8020c510(&detail, "%s.%sWaterDetail", w3d::VA(world.text), w3d::VA(time.text));
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
        Ptr32<void> a = service_forward_8020b680(g_80410680);
        submit_80164514(g_804b178c, a, self->id);
    }
    {
        Ptr32<void> b = service_forward_8020b680(g_8040fb28);
        submit_80164514(g_804b178c, b, self->id);
    }
}


