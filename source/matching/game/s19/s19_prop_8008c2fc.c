extern int s8_property_read_800fc550(void *name, void *output);
extern int s8_property_write_800fc3b0(void *name, int value);

void s19_chicken_setup_8008c2fc(void) {
    const char *spawn = "Chicken.Spawn";
    const char *hit;
    s8_property_read_800fc550(&spawn, "ChickenSpawn");
    hit = "Chicken.HitPoints";
    s8_property_write_800fc3b0(&hit, -1);
}
