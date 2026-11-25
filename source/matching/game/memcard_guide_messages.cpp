/* Memory-card guideline message selection (0x802c522c..), from ./NGC/memguidefig2.c.
 *
 * Each routine maps the card status at +0x04 to a message identifier stored
 * at +0x0c; an unexpected status reaches the SDK panic routine with the
 * original file, line and diagnostic text. Names are inferred from those
 * diagnostics; message identifiers are kept as observed numbers. The strings
 * stay external original data until this unit's .rodata is recovered whole.
 */
extern "C" {

typedef struct W3dCardGuide {
    int unknown_00;
    int status;
    int unknown_08;
    int message;
    int unknown_10;
    int encoding;
} W3dCardGuide;

void w3d_os_panic_802fb82c(const char *file, int line, const char *format, ...);
extern const char w3d_str_memguidefig2_803d8888[];
extern const char w3d_str_mesg_damaged_803d8940[];
extern const char w3d_str_mesg_nosupport_803d896c[];
extern const char w3d_str_mesg_nocard_803d8998[];
extern const char w3d_str_mesg_corrupt_803d89c0[];
extern const char w3d_str_mesg_wrongdevice_803d89ec[];
extern const char w3d_str_mesg_encoding_803d8a20[];
extern const char w3d_str_mesg_format_failed_803d8a4c[];

void w3d_card_guide_message_177(W3dCardGuide *guide)
{
    guide->message = 177;
}

void w3d_card_guide_message_by_encoding(W3dCardGuide *guide)
{
    if (guide->encoding == 0x2000)
        guide->message = 178;
    else
        guide->message = -18;
}

void w3d_card_guide_message_damaged(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 4: guide->message = 176; break;
    case 3: guide->message = 2; break;
    case 0: guide->message = -19; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 439, w3d_str_mesg_damaged_803d8940);
    }
}

void w3d_card_guide_message_nosupport(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 4: guide->message = 176; break;
    case 3: guide->message = 2; break;
    case 0: guide->message = -18; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 474, w3d_str_mesg_nosupport_803d896c);
    }
}

void w3d_card_guide_message_nocard(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 4: guide->message = 176; break;
    case 3: guide->message = 2; break;
    case 0: guide->message = -17; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 508, w3d_str_mesg_nocard_803d8998);
    }
}

void w3d_card_guide_message_corrupt(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 2: guide->message = 2; break;
    case 4: guide->message = 176; break;
    case 1: guide->message = -13; break;
    case 0: guide->message = -16; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 545, w3d_str_mesg_corrupt_803d89c0);
    }
}

void w3d_card_guide_message_wrong_device(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 4: guide->message = 176; break;
    case 3: guide->message = 2; break;
    case 0: guide->message = -15; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 581, w3d_str_mesg_wrongdevice_803d89ec);
    }
}

void w3d_card_guide_message_encoding(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 1: guide->message = -13; break;
    case 3: guide->message = 2; break;
    case 4: guide->message = 176; break;
    case 0: guide->message = -14; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 618, w3d_str_mesg_encoding_803d8a20);
    }
}

void w3d_card_guide_message_encoding_retry(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 1: guide->message = 181; break;
    case 2: guide->message = 176; break;
    case 0: guide->message = -13; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 650, w3d_str_mesg_encoding_803d8a20);
    }
}

void w3d_card_guide_message_format_failed(W3dCardGuide *guide)
{
    switch (guide->status) {
    case 1: guide->message = 176; break;
    case 0: guide->message = -12; break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 676, w3d_str_mesg_format_failed_803d8a4c);
    }
}

}
