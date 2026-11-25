#include "w3d_ptr.h"
#line 1 "d26c_gun_fire_round_800e1268.cpp"
// d26c: 0x800e1268. Fire one round of an automatic weapon: count it, call the sub-object's fire, play the clip and sound
// when set; at the end of a burst take the ammo and randomize spread and gap. Names and Desc fields are inferred.
struct String { Ptr32<char> text; unsigned short length() const { return ((Ptr32<unsigned short>)text)[-2]; } };
struct Desc {
    char u0[328]; String clip;
    char u332[8]; String sound;
    char u344[44]; unsigned short spread;
    char u390[14]; unsigned short gap;
    unsigned short gap_range;
    char u408[8]; unsigned short ammo;
};
struct Sub { struct V { Ptr32<void> u[2]; Ptr32<void (Ptr32<Sub>, Ptr32<void>, Ptr32<void>, int)> fire; };  char w3d_empty; };
struct Gun {
    char u0[20];
    Ptr32<void> h20;
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
    Ptr32<void> h156;
    char u160[12];
    int state;
    char u176[80];
    Ptr32<Sub::V> vtable;
    char u260[4];
    Ptr32<Ptr32<void>> clips;
};
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void note_800dca14(Ptr32<void>, int);
extern "C" void clip_800e2464(Ptr32<Gun>, Ptr32<void>, Ptr32<char>);
extern "C" int play_800e5d4c(Ptr32<void>, int, Ptr32<char>, Ptr32<void>);
extern "C" float random_8015ff7c(Ptr32<Gun>);
inline float noise(Ptr32<Gun> self) { return (random_8015ff7c(self) - 0.5f) * 2.0f; }
extern "C" int d26c_gun_fire_round_800e1268(Ptr32<Gun> self, Ptr32<void> a, int idx, Ptr32<void> b) {
    self->t124++;
    self->t128++;
    int result = 1;
    self->vtable->fire((Ptr32<Sub>)self->sub, a, b, 1);
    note_800dca14(a, 1);
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h156));
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


