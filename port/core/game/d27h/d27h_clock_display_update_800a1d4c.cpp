#include "w3d_ptr.h"
#line 1 "d27h_clock_display_update_800a1d4c.cpp"
// GWMP8P rev0 0x800a1d4c. Game clock display update. Names are inferred.
// Writes the round time as digits, then by display mode blanks the turn
// digits or shows retreat or turn time with colours, warnings at 5 and 15
// seconds.
struct Object;
extern "C" Ptr32<Object> as_int_803426b4(Ptr32<Object>);
extern "C" int get_int_80178c48(Ptr32<Object>);
extern "C" Ptr32<Object> as_text_8034380c(Ptr32<Object>);
extern "C" Ptr32<Object> as_enum_80342a78(Ptr32<Object>);
extern "C" int get_enum_80178d1c(Ptr32<Object>);
extern "C" Ptr32<int> get_colour_80178f54(Ptr32<Object>);
extern "C" Ptr32<char> text_data_80189828(Ptr32<Object>);
extern "C" Ptr32<int> text_colours_80189760(Ptr32<Object>);
struct Clock;
extern "C" void clamp_seconds_800a2098(Ptr32<Clock>, Ptr32<int>);
extern "C" void warn_800a2e78(Ptr32<Clock>, int);
extern "C" void layout_800a30bc(Ptr32<Clock>);
extern "C" void strip_800a34f4(Ptr32<Clock>);
struct Clock {
    char u0[52];
    Ptr32<Object> turnText;     // +52
    Ptr32<Object> roundText;    // +56
    char u60[4];
    Ptr32<Object> turnTime;     // +64
    Ptr32<Object> roundTime;    // +68
    Ptr32<Object> retreatTime;  // +72
    Ptr32<Object> mode;         // +76
    char u80[4];
    int lastSeconds;      // +84
    char u88[36];
    Ptr32<Object> colourB;      // +124
    Ptr32<Object> colourA;      // +128
    Ptr32<Object> colourC;      // +132
    char u136[16];
    int displayMode;      // +152
};
struct Message { unsigned short id; Ptr32<void> vtable; };
extern "C" Ptr32<Message> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned short message_id_8015f5a0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> g_arena_804b1754;
extern unsigned char id_804ae174[8], id_804ae17c[8];
extern unsigned char vtable_8040db38[];
extern "C" int d27h_clock_display_update_800a1d4c(Ptr32<Clock> self) {
    int ms = get_int_80178c48(as_int_803426b4(self->roundTime));
    int total = ms / 1000;
    int minutes = total / 60;
    int seconds = total % 60;
    Ptr32<Object> text = as_text_8034380c(self->roundText);
    text_data_80189828(text)[0] = minutes / 10;
    text_data_80189828(text)[1] = minutes % 10;
    text_data_80189828(text)[3] = seconds / 10;
    text_data_80189828(text)[4] = seconds % 10;
    self->displayMode = get_enum_80178d1c(as_enum_80342a78(self->mode));
    Ptr32<Object> turn = as_text_8034380c(self->turnText);
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
                        Ptr32<Message> m = arena_alloc_801613f0(g_arena_804b1754, 8);
                        m->id = message_id_8015f5a0(id_804ae174, 1);
                        m->vtable = vtable_8040db38;
                        message_post_8016239c(m);
                    }
                }
            } else if (seconds != self->lastSeconds && seconds == 15) {
                Ptr32<Message> m = arena_alloc_801613f0(g_arena_804b1754, 8);
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


