// GWMP8P rev0 0x800a1d4c. Game clock display update. Names are inferred.
// Writes the round time as digits, then by display mode blanks the turn
// digits or shows retreat or turn time with colours, warnings at 5 and 15
// seconds.
struct Object;
extern "C" Object *as_int_803426b4(Object *);
extern "C" int get_int_80178c48(Object *);
extern "C" Object *as_text_8034380c(Object *);
extern "C" Object *as_enum_80342a78(Object *);
extern "C" int get_enum_80178d1c(Object *);
extern "C" int *get_colour_80178f54(Object *);
extern "C" char *text_data_80189828(Object *);
extern "C" int *text_colours_80189760(Object *);
struct Clock;
extern "C" void clamp_seconds_800a2098(Clock *, int *);
extern "C" void warn_800a2e78(Clock *, int);
extern "C" void layout_800a30bc(Clock *);
extern "C" void strip_800a34f4(Clock *);
struct Clock {
    char u0[52];
    Object *turnText;     // +52
    Object *roundText;    // +56
    char u60[4];
    Object *turnTime;     // +64
    Object *roundTime;    // +68
    Object *retreatTime;  // +72
    Object *mode;         // +76
    char u80[4];
    int lastSeconds;      // +84
    char u88[36];
    Object *colourB;      // +124
    Object *colourA;      // +128
    Object *colourC;      // +132
    char u136[16];
    int displayMode;      // +152
};
struct Message { unsigned short id; void *vtable; };
extern "C" Message *arena_alloc_801613f0(void *, int);
extern "C" unsigned short message_id_8015f5a0(void *, int);
extern "C" int message_post_8016239c(Message *);
extern void *g_arena_804b1754;
extern unsigned char id_804ae174[8], id_804ae17c[8];
extern unsigned char vtable_8040db38[];
extern "C" int d27h_clock_display_update_800a1d4c(Clock *self) {
    int ms = get_int_80178c48(as_int_803426b4(self->roundTime));
    int total = ms / 1000;
    int minutes = total / 60;
    int seconds = total % 60;
    Object *text = as_text_8034380c(self->roundText);
    text_data_80189828(text)[0] = minutes / 10;
    text_data_80189828(text)[1] = minutes % 10;
    text_data_80189828(text)[3] = seconds / 10;
    text_data_80189828(text)[4] = seconds % 10;
    self->displayMode = get_enum_80178d1c(as_enum_80342a78(self->mode));
    Object *turn = as_text_8034380c(self->turnText);
    int colour = *get_colour_80178f54(self->colourA);
    switch (self->displayMode) {
    case 0:
        {
            int blank = 15;
            text_data_80189828(turn)[0] = blank;
            text_data_80189828(turn)[1] = blank;
        }
        break;
    case 1:
        seconds = get_int_80178c48(as_int_803426b4(self->retreatTime));
        clamp_seconds_800a2098(self, &seconds);
        colour = *get_colour_80178f54(self->colourB);
        break;
    case 2:
        {
            int flash = 1;
            seconds = get_int_80178c48(as_int_803426b4(self->turnTime));
            if ((seconds / 500 & 1) == 0) flash = 0;
            clamp_seconds_800a2098(self, &seconds);
            if (seconds < 6) {
                if (flash) colour = *get_colour_80178f54(self->colourC);
                if (seconds != self->lastSeconds) {
                    warn_800a2e78(self, seconds);
                    if (seconds == 5) {
                        Message *m = arena_alloc_801613f0(g_arena_804b1754, 8);
                        m->id = message_id_8015f5a0(id_804ae174, 1);
                        m->vtable = vtable_8040db38;
                        message_post_8016239c(m);
                    }
                }
            } else if (seconds != self->lastSeconds && seconds == 15) {
                Message *m = arena_alloc_801613f0(g_arena_804b1754, 8);
                m->id = message_id_8015f5a0(id_804ae17c, 1);
                m->vtable = vtable_8040db38;
                message_post_8016239c(m);
            }
            self->lastSeconds = seconds;
        }
        break;
    }
    if (self->displayMode != 0) {
        text_colours_80189760(turn)[0] = colour;
        text_colours_80189760(turn)[1] = colour;
        while (seconds > 99) seconds -= 100;
        text_data_80189828(turn)[0] = seconds / 10;
        text_data_80189828(turn)[1] = seconds % 10;
    }
    layout_800a30bc(self);
    strip_800a34f4(self);
    return 0;
}
