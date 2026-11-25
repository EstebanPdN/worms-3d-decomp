extern void w3d_auto_800fc230(const char **, int *);
struct S19Rec { char pad0[196]; int mode; };
extern struct S19Rec *s8_index_query_800fc6dc(int);

int s19_artillery_mode_800154e0(int index) {
    const char *name = "GameLogic.ArtilleryMode";
    int value;
    w3d_auto_800fc230(&name, &value);
    if (value != 0)
        return 0;
    return s8_index_query_800fc6dc(index)->mode ^ 1;
}
