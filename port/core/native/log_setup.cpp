// Crea los canales de registro de Xom (Xom.Log y sus prefijos de aviso y error) con sus salidas.
#include "native_game.h"

namespace {
struct LogChannel {
    Ptr32<void> sinks[3];                                     // +0
    struct { w3d_u32 created; w3d_u32 enabled; } levels[3];   // +0xc
    Ptr32<void> formatter;                                    // +0x24
    Ptr32<void> output;                                       // +0x28
};
// Los cuatro flujos de cada canal, en el orden en que los usa el registro.
struct LogStreams { w3d_u32 first, second, third, fourth; };
void set_owned(Ptr32<void> &slot, void *object) {
    if (object) add_reference(object);
    release_if_set(slot.get());
    slot = object;
}
}
extern "C" {
extern Ptr32<void> A804b05e0, A804b05e4, A804b05e8;
extern Ptr32<void> A804b05fc;
extern uint16_t A804b05f4;
extern LogChannel A8045e944, A8045e970;
extern LogStreams A8045e99c, A8045e9ac;
extern w3d_u32 A804ab92c, A804ab930;
extern const char A803b1da0[], A803b1da8[], A803b1db8[], A803b1dc8[], A803b1dcc[], A803b1dd0[], A803b1dd4[];
w3d_u32 A801fe1d8(w3d_u32 bytes);
w3d_u32 A8020b058(void *memory);
w3d_u32 A80206af4(void *memory);
w3d_u32 A8020881c(void *memory, void *sink);
w3d_u32 A80207c0c(const char *name);
w3d_u32 A8020b208();
w3d_u32 A8020aad0(void *memory);
void A8020abe0(void *sink, void *formatter);
void A8035a32c(void *channel, w3d_u32 level);
w3d_u32 A80208a4c(void *memory, void *sink);
void A8020bb54(GameString *string, const char *text);
void A80208768(w3d_u32 stream, GameString *prefix);
void A801fcc48(w3d_u32 mask);

static void make_sinks(LogChannel &channel) {
    for (int i = 0; i < 3; i++) {
        void *sink = g2h(A8020aad0(g2h(A801fe1d8(0x20))));
        set_owned(channel.sinks[i], sink);
        A8020abe0(sink, channel.formatter.get());
        channel.levels[i].created = 1;
    }
}
static w3d_u32 new_stream(void *sink) { return A80208a4c(g2h(A801fe1d8(0x28)), sink); }
static void set_prefix(w3d_u32 stream, const char *prefix) {
    GameString text;
    A8020bb54(&text, prefix);
    A80208768(stream, &text);
}
// 0x801fcd74
w3d_u32 A801fcd74() {
    set_owned(A804b05e0, g2h(A8020b058(g2h(A801fe1d8(0x14)))));
    set_owned(A804b05e8, g2h(A80206af4(g2h(A801fe1d8(0x14)))));
    A804b05fc.v = A8020881c(g2h(A801fe1d8(0x20)), A804b05e8.get());
    set_owned(A804b05e4, A804b05e8.get());
    A804b05f4 = (uint16_t)A80207c0c(A803b1da0);
    set_owned(A8045e944.formatter, g2h(A8020b208()));
    set_owned(A8045e970.formatter, g2h(A8020b208()));
    set_owned(A8045e944.output, A804b05fc.get());
    set_owned(A8045e970.output, A804b05fc.get());
    make_sinks(A8045e944);
    make_sinks(A8045e970);
    A8045e944.levels[0].enabled = 1;
    A8035a32c(&A8045e944, 0);
    A8045e970.levels[0].enabled = 1;
    A8035a32c(&A8045e970, 0);
    A8045e9ac.second = new_stream(A804b05e4.get());
    A8045e9ac.first = new_stream(A8045e944.sinks[0].get());
    A8045e9ac.third = new_stream(A8045e944.sinks[1].get());
    A8045e9ac.fourth = new_stream(A8045e944.sinks[2].get());
    set_prefix(A8045e9ac.third, A803b1da8);
    set_prefix(A8045e9ac.fourth, A803b1db8);
    A8045e99c.second = new_stream(A804b05e4.get());
    A8045e99c.first = new_stream(A8045e970.sinks[0].get());
    A8045e99c.third = new_stream(A8045e970.sinks[1].get());
    A8045e99c.fourth = new_stream(A8045e970.sinks[2].get());
    set_prefix(A8045e99c.first, A803b1dc8);
    set_prefix(A8045e99c.second, A803b1dcc);
    set_prefix(A8045e99c.third, A803b1dd0);
    set_prefix(A8045e99c.fourth, A803b1dd4);
    A804ab930 = 1;
    A801fcc48(A804ab92c);
    return 0;
}
}
