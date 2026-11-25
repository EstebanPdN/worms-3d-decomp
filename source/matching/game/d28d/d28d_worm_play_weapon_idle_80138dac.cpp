// GWMP8P rev0 0x80138dac. Play a worm's weapon idle animation set. Names are
// inferred from use. The argument order of the two play callees is chosen
// for the argument moves.
struct Mesh;
struct Info { char u0[80]; const char *f80; char u54[4]; const char *f88; const char *f92; };
struct Worm { char u0[28]; Mesh *mesh; char u20[132]; Mesh *f164; Mesh *f168; char uac[300]; float cue472[3]; float cue484; float cue488; float cue492; char u1f0[84]; float f580; char u248[60]; int f644; int f648; int f652; char f656[28]; int weapon; };
extern "C" int current_80139158(Worm *);
extern "C" int control_801817e0(Mesh *, int);
extern "C" int play_801359ec(Worm *, Mesh *, const char *, float, float, float *, float);
extern "C" int play_index_80135a70(Worm *, Mesh *, int, float, float, float *, float);
extern "C" void * read_800fc330(void *, Info **);
extern "C" void draw_8013d730(Worm *, Mesh *, int);
extern "C" int strcmp_802ef234(const char *, const char *);
extern "C" const char *strstr_802efd14(const char *, const char *);
extern "C" int find_80181598(Mesh *, const char *, int *);
extern "C" float length_80181de4(Mesh *, int);
extern "C" void assign_8020bd38(char *, const char *);
extern "C" void effect_8013d8f8(Worm *, int);
extern char *idle_804ab100;
extern char table_803eb63c[];
extern const char empty_8039f59c[];
extern "C" void d28d_worm_play_weapon_idle_80138dac(Worm *self, int check) {
    if (check && !current_80139158(self)) return;
    control_801817e0(self->mesh, -1);
    play_801359ec(self, self->mesh, idle_804ab100, 1.0f, 0.0f, &self->cue492, 0.0f);
    float zero = 0.0f;
    self->f580 = zero;
    if (self->f652) return;
    Info *got;
    read_800fc330(table_803eb63c + self->weapon * 4, &got);
    Info *info = got;
    draw_8013d730(self, self->mesh, self->weapon);
    const char *none = empty_8039f59c;
    bool a = strcmp_802ef234(info->f92, none) != 0;
    if (a) play_801359ec(self, self->mesh, info->f92, 1.0f, -1.0f, self->cue472, zero);
    bool b = strcmp_802ef234(info->f88, none) != 0;
    if (b) {
        const char *n = info->f88;
        find_80181598(self->mesh, n, &self->f644);
        assign_8020bd38(self->f656, n);
        const char *hit = strstr_802efd14(n, "Aim");
        if (hit) self->f648 = 1;
        else self->f648 = (int)hit;
    } else {
        control_801817e0(self->mesh, -1);
        play_801359ec(self, self->mesh, idle_804ab100, 1.0f, zero, &self->cue492, zero);
        play_801359ec(self, self->mesh, idle_804ab100, 1.0f, zero, &self->cue488, zero);
        find_80181598(self->mesh, idle_804ab100, &self->f644);
        self->f648 = b;
    }
    if (self->f168) {
        int idx = 0;
        if (find_80181598(self->f168, info->f92, &idx) >= 0) {
            float k = 0.0f;
            float len = length_80181de4(self->f168, idx);
            play_index_80135a70(self, self->f168, idx, 1.0f, 0.0f, &self->cue484, len * 0.5f);
        }
    }
    if (self->f164) {
        switch ((unsigned)self->weapon) {
        case 50:
            play_801359ec(self, self->f164, info->f80, 1.0f, 0.0f, &self->cue488, 0.0f);
            break;
        case 43: case 47:
            play_801359ec(self, self->f164, info->f92, 1.0f, 0.0f, &self->cue488, 0.0f);
            break;
        }
    }
    effect_8013d8f8(self, self->weapon);
}
