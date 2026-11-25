// Remaps object references held in property fields (Worms 3D GameCube PAL, 0x801ea59c).
//
// Walks the type list from 0x8020ff3c. For each type whose 4-bit kind (bits
// 16-19 of the word at +32) is 2, visits each object (0x8020fe00, 0x8020fe18)
// and each property (0x801e9db8). When bit 0 of the property's flag byte is
// set, a field at the property's offset equal to from[j] becomes to[j]; stops
// at the first hit for that field. Returns the number of fields changed.
//
// Partial views of external objects. Kind is a bit-field read as int: a shift
// and mask on the whole word is narrowed to a halfword load.
struct d24e_Property {
    unsigned unknown;
    unsigned short offset;
    unsigned char unknown6, flags;
};
struct d24e_Type {
    unsigned unknown0;
    d24e_Type *next;
    unsigned unknown8[6];
    unsigned high : 12;
    unsigned kind : 4;
    unsigned low : 16;
    unsigned unknown36[6];
    void **begin, **end;
};
extern "C" d24e_Type *fn_8020ff3c();
extern "C" char *fn_8020fe00(d24e_Type *);
extern "C" char *fn_8020fe18(d24e_Type *, char *);
extern "C" d24e_Property **fn_801e9db8(d24e_Type *, unsigned);

extern "C" int w3d_d24e_remap_properties_801ea59c(const unsigned *from, const unsigned *to, unsigned count) {
    int changed = 0;
    for (d24e_Type *type = fn_8020ff3c(); type; type = type->next) {
        if ((int)type->kind == 2) {
            unsigned properties = type->end - type->begin;
            for (char *object = fn_8020fe00(type); object; object = fn_8020fe18(type, object)) {
                for (unsigned i = 0; i < properties; ++i) {
                    d24e_Property *p = *fn_801e9db8(type, i);
                    if (p->flags & 1) {
                        unsigned *field = (unsigned *)(object + p->offset);
                        for (unsigned j = 0; j < count; ++j)
                            if (*field == from[j]) { ++changed; *field = to[j]; break; }
                    }
                }
            }
        }
    }
    return changed;
}
