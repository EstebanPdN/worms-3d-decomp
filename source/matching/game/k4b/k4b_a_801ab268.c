struct K4bPair { int first; int second; };
struct K4bChannelSet {
    void **vtable;
    char base[36];
    int field_28;
    int field_2c;
    int channel_count;
    struct K4bPair size_a;
    struct K4bPair size_b;
    int mode_44;
    int mode_48;
    int mode_4c;
    int field_50;
    int mode_54;
    int field_58;
    int field_5c;
    char pad60[16];
    int field_70;
    float scale;
    int field_78;
    int order[26];
    char pad_e4[20];
    int map_a[4];
    int map_b[4];
    int map_c[4];
};
extern void *lbl_80413eb8[];
extern void *lbl_80413dc0[];
extern void * fn_801e81c8(void *member);
struct K4bChannelSet *w3d_k4b_channel_set_construct_801ab268(struct K4bChannelSet *self)
{
    int i;
    self->vtable = lbl_80413eb8;
    fn_801e81c8(self->base);
    self->vtable = lbl_80413dc0;
    self->field_28 = 0;
    self->field_2c = 0;
    self->size_a.first = 8;
    self->size_a.second = 256;
    self->size_b.first = 8;
    self->size_b.second = 256;
    self->channel_count = 4;
    self->mode_48 = 1;
    self->field_58 = 0;
    self->mode_44 = 2;
    self->mode_4c = 2;
    self->mode_54 = 2;
    self->field_50 = 0;
    self->field_5c = 0;
    for (i = 0; i < 4; i++) {
        self->map_a[i] = i;
        self->map_b[i] = i;
        self->map_c[i] = i;
    }
    self->field_70 = 0;
    self->scale = 1.0f;
    { unsigned int j; for (j = 0; j < 26; j++)
        self->order[j] = j; }
    self->field_78 = 0;
    return self;
}
// desc: w3d_k4b_channel_set_construct_801ab268: Appears to construct a four-channel set: vtables, member at +4 via 0x801e81c8, size pairs 8x256, modes, identity maps for 4 and 26 entries and a unit scale.
