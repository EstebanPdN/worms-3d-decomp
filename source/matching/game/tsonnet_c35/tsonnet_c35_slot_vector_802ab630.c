/* Reference-only: for the object held in pointer slot `index` of a table at
   +1364, does nothing when the slot is empty. Otherwise it calls a virtual
   query (vtable +36); if that returns non-zero it calls a virtual at +24, then
   sends the 3-float vector (a, a, b) with count 3 to the virtual at +56 and
   calls the virtual at +20. a and b are constants at 0x803d6ae0 and
   0x803d6ae4. Offsets and meanings are inferred from the observed accesses;
   the vector local is only addressed through a pointer. */
struct Obj { int pad[341]; void *slots[8]; };
extern const float w3d_f32_803d6ae0[];
extern const float w3d_f32_803d6ae4[];
#define F(p, T, o) (*(T *)((char *)(p) + (o)))
#define CALL0(o, off) (*(void (**)(void *))(*(char **)(o) + (off)))(o)
void tsonnet_c35_slot_vector_802ab630(struct Obj *self, int index) {
    struct Obj *o = self; int i = index;
    if (o->slots[i] != 0) {
        if ((*(int (**)(void *))(*(char **)o->slots[i] + 36))(o->slots[i]))
            CALL0(o->slots[i], 24);
        {
            float v[3];
            float *p = v;
            v[0] = w3d_f32_803d6ae0[0];
            p[1] = w3d_f32_803d6ae0[0];
            p[2] = w3d_f32_803d6ae4[0];
            (*(void (**)(void *, int, float *))(*(char **)o->slots[i] + 56))(o->slots[i], 3, p);
            CALL0(o->slots[i], 20);
        }
    }
}
