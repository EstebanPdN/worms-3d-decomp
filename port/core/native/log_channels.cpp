// Canales de registro de Xom: cada bit de la máscara activa o apaga un nivel de un canal.
#include "native_common.h"

namespace {
struct LogChannel {
    char pad[0x10];
    struct { w3d_u32 enabled; w3d_u32 pad; } levels[3];  // +0x10, cada 8 B
};
struct ChannelRule { w3d_u32 mask; w3d_u32 level; w3d_u32 is_warning; };
const w3d_u32 kEveryLevel = 3;
}
extern "C" {
extern w3d_u32 A804ab92c, A804ab930;   // Máscara y "ya creados".
extern ChannelRule A803b1d58[6];
extern LogChannel A8045e944, A8045e970;
void A8035a32c(void *channel, w3d_u32 level);

// 0x801fcc48: guarda la máscara y, si los canales existen, aplica cada regla.
void A801fcc48(w3d_u32 mask) {
    A804ab92c = mask;
    if (!A804ab930) return;
    for (const ChannelRule &rule : A803b1d58) {
        LogChannel *channel = rule.is_warning ? &A8045e970 : &A8045e944;
        const w3d_u32 enabled = (mask & rule.mask) != 0;
        if (rule.level == kEveryLevel) {
            for (auto &level : channel->levels) level.enabled = enabled;
        } else {
            channel->levels[rule.level].enabled = enabled;
        }
        A8035a32c(channel, rule.level);
    }
}
}
