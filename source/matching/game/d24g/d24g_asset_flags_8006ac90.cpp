/* Worms 3D GameCube PAL 0x8006ac90. Builds the asset-needed flag table 0x8042e59c: clears 356 bytes, sets entry 5, sets an entry by the mode at +212 (3, 0, 1, or 4); in mode 7 also sets the entry at +3336, reloads Land.Materials when changed, marks every table 0x803f477c entry whose name equals +3344, and marks the kind of each resolved item in 128 groups of six slots at +264. Returns the table. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Entry { const char *name; char u4[28]; int index; };
struct Item { struct V { void *u[18]; unsigned char *(*kind)(Item *); } *vtable; };
struct Key { const char *text; };
extern "C" void *memset(void *, int, unsigned);
extern "C" int strcmp(const char *, const char *);
extern "C" int read_800fc2b0(Key *, const char **);
extern "C" int load_materials_800b9c1c(const char *, void *);
extern "C" void *string_assign_8020bd38(void *, const char *);
extern "C" Item *lookup_8015ae3c(void *);
extern int flags_8042e59c[];
extern Entry table_803f477c[];
extern const char s_8037bbbc[];
inline int differs(const char *a, const char *b) { return strcmp(a, b) != 0; }
#define F(p, T, o) (*(T *)((char *)(p) + (o)))
extern "C" int *w3d_d24g_asset_flags_8006ac90(char *self)
{
    memset(flags_8042e59c, 0, 356);
    flags_8042e59c[5] = 1;
    switch (F(self, int, 212)) {
    case 0: flags_8042e59c[3] = 1; break;
    case 5: flags_8042e59c[0] = 1; break;
    case 6: flags_8042e59c[1] = 1; break;
    case 7:
    {
        flags_8042e59c[4] = 1;
        flags_8042e59c[F(self, int, 3336)] = 1;
        Key key;
        const char *materials;
        key.text = s_8037bbbc;
        read_800fc2b0(&key, &materials);
        char *name = self + 3340;
        if (differs(*(const char **)name, materials)) {
            load_materials_800b9c1c(materials, self + 264);
            string_assign_8020bd38(name, materials);
        }
        for (int i = 0; table_803f477c[i].name; i++)
            if (strcmp(F(self, const char *, 3344), table_803f477c[i].name) == 0)
                flags_8042e59c[table_803f477c[i].index] = 1;
        for (unsigned i = 0; i <= 127; i++) {
            char *slot = self + (i * 24 + 264);
            for (unsigned j = 0; j <= 5; j++) {
                Item *item = lookup_8015ae3c(slot);
                if (item) flags_8042e59c[*item->vtable->kind(item)] = 1;
                slot += 4;
            }
        }
    }
    case -1:
    case 1:
    case 8:
        break;
    }
    return flags_8042e59c;
}
