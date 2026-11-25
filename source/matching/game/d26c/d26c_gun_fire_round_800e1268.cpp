// d26c: 0x800e1268. Fire one round of an automatic weapon: count it, call the sub-object's fire, play the clip and sound
// when set; at the end of a burst take the ammo and randomize spread and gap. Names and Desc fields are inferred.
struct String { char *text; unsigned short length() const { return ((unsigned short *)text)[-2]; } };
struct Desc {
    char u0[328]; String clip;
    char u332[8]; String sound;
    char u344[44]; unsigned short spread;
    char u390[14]; unsigned short gap;
    unsigned short gap_range;
    char u408[8]; unsigned short ammo;
};
struct Sub { struct V { void *u[2]; void (*fire)(Sub *, void *, void *, int); }; };
struct Gun {
    char u0[20];
    void *h20;
    char u24[4];
    char sub[12];
    int ammo;
    char u44[12];
    int spread;
    char u60[48];
    char pos[12];
    int gap;
    int t124;
    int t128;
    char u132[24];
    void *h156;
    char u160[12];
    int state;
    char u176[80];
    Sub::V *vtable;
    char u260[4];
    void **clips;
};
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" void note_800dca14(void *, int);
extern "C" void clip_800e2464(Gun *, void *, char *);
extern "C" int play_800e5d4c(void *, int, char *, void *);
extern "C" float random_8015ff7c(Gun *);
inline float noise(Gun *self) { return (random_8015ff7c(self) - 0.5f) * 2.0f; }
extern "C" int d26c_gun_fire_round_800e1268(Gun *self, void *a, int idx, void *b) {
    self->t124++;
    self->t128++;
    int result = 1;
    self->vtable->fire((Sub *)self->sub, a, b, 1);
    note_800dca14(a, 1);
    Desc *d = desc_801797b4(empty_80341584(self->h156));
    if (self->state == 2 && d->clip.length()) clip_800e2464(self, self->clips[idx], d->clip.text);
    if (d->sound.length()) play_800e5d4c(self->h20, idx, d->sound.text, self->pos);
    if ((unsigned)self->t124 >= (unsigned)(d->gap + self->gap)) {
        self->ammo -= d->ammo + self->spread;
        result = 0;
        self->spread = (int)(noise(self) * d->spread);
        self->gap = (int)(noise(self) * d->gap_range);
    }
    return result;
}
