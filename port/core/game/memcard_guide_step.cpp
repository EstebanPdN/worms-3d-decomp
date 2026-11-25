#include "w3d_ptr.h"
#line 1 "memcard_guide_step.cpp"
/* Memory-card guideline state machine step (0x802c501c), ./NGC/memguidefig2.c.
 *
 * The current message at +0x0c is reported, then selects the next action:
 * positive messages run a CARD operation and continue (-1); negative ones
 * show their failure message and return that failure; 0, 1 and 2 reset the
 * flow to message 176 and return the finished state. Any other value is an
 * illegal state and panics. All handlers are admitted in the memcard_guide_*
 * units; the reporter at 0x802c59e8 is still external.
 */
extern "C" {

typedef struct W3dCardGuideState {
    int channel;
    int status;
    int unknown_08;
    int message;
} W3dCardGuideState;

void w3d_card_guide_show_message_802c59e8(int message);
void w3d_os_panic_802fb82c(Ptr32<const char> file, int line, Ptr32<const char> format, ...);
extern const char w3d_str_memguidefig2_803d8888[];
extern const char w3d_str_illegal_state_803d88a0[];

void w3d_card_guide_message_177(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_probe(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_by_encoding(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_mount(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_check(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_format(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_unformat(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_damaged(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_nosupport(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_nocard(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_corrupt(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_wrong_device(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_encoding(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_encoding_retry(Ptr32<W3dCardGuideState> guide);
void w3d_card_guide_message_format_failed(Ptr32<W3dCardGuideState> guide);

int w3d_card_guide_step(Ptr32<W3dCardGuideState> guide)
{
    w3d_card_guide_show_message_802c59e8(guide->message);
    switch (guide->message) {
    case 176: w3d_card_guide_message_177(guide); return -1;
    case 177: w3d_card_guide_probe(guide); return -1;
    case 180: w3d_card_guide_message_by_encoding(guide); return -1;
    case 178: w3d_card_guide_mount(guide); return -1;
    case 179: w3d_card_guide_check(guide); return -1;
    case 181: w3d_card_guide_format(guide); return -1;
    case 182: w3d_card_guide_unformat(guide); return -1;
    case -19: w3d_card_guide_message_damaged(guide); return -19;
    case -18: w3d_card_guide_message_nosupport(guide); return -18;
    case -17: w3d_card_guide_message_nocard(guide); return -17;
    case -16: w3d_card_guide_message_corrupt(guide); return -16;
    case -15: w3d_card_guide_message_wrong_device(guide); return -15;
    case -14: w3d_card_guide_message_encoding(guide); return -14;
    case -13: w3d_card_guide_message_encoding_retry(guide); return -13;
    case -12: w3d_card_guide_message_format_failed(guide); return -12;
    case 1: guide->message = 176; return 1;
    case 2: guide->message = 176; return 2;
    case 0: guide->message = 176; return 0;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 171, w3d_str_illegal_state_803d88a0);
        return 2;
    }
}

}


