// Worms 3D GameCube PAL, 0x800c6100 (216 bytes). Movie category lookup: picks
// the table for the TV format, then scans 12-byte records until an empty name
// or category 29 and returns the category of the record whose name matches
// (0x802ef074), or 29 when none does. An unknown format panics with the
// source name and line 300. Record and field names are inferred.
//
// The index is initialized before the switch. The loop pass then derives its
// scaled start from a register and leaves the original's unfolded
// "li r0,0; mulli r0,r0,12" in the preheader.
struct Movie { const char *name; int category; const char *file; };
extern Movie lbl_803f5728[];
extern Movie lbl_803f58b4[];
extern const char lbl_803876ac[];   // "MoviePlayerService.cpp"
extern const char lbl_803876c4[];   // "XGXScreen: invalid TV format\n"
extern "C" unsigned fn_80304de0();
extern "C" unsigned fn_802ef9c0(const char *);
extern "C" int fn_802ef074(const char *, const char *);
extern "C" void fn_802fb82c(const char *, int, const char *, ...);

extern "C" int w3d_d24h_find_movie_800c6100(void *self, const char *name) {
    int i = 0;
    Movie *table;
    switch (fn_80304de0()) {
    case 1: table = lbl_803f5728; break;
    case 0: case 2: table = lbl_803f58b4; break;
    default: fn_802fb82c(lbl_803876ac, 300, lbl_803876c4); break;
    }
    for (; fn_802ef9c0(table[i].name) != 0 && table[i].category != 29; i++) {
        if (fn_802ef074(table[i].name, name) == 0) return table[i].category;
    }
    return 29;
}
