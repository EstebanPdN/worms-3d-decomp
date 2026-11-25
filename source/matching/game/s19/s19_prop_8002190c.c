extern int s8_property_read_800fc5dc(const char **, void *);
struct S19Task { char pad0[4]; int done; char pad8[12]; float launch; };

int s19_read_launch_velocity_8002190c(struct S19Task *p) {
    const char *name = "AI.LaunchVelocity";
    s8_property_read_800fc5dc(&name, &p->launch);
    p->done = 1;
    return 0;
}
