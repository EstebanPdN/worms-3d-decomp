#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_8008c2fc.c"
extern int s8_property_read_800fc550(Ptr32<void> name, Ptr32<void> output);
extern int s8_property_write_800fc3b0(Ptr32<void> name, int value);

void s19_chicken_setup_8008c2fc(void) {
    Ptr32<const char> spawn = "Chicken.Spawn";
    Ptr32<const char> hit;
    s8_property_read_800fc550(&spawn, "ChickenSpawn");
    hit = "Chicken.HitPoints";
    s8_property_write_800fc3b0(&hit, -1);
}

}
