/* Memory-card guideline probes (0x802c5238..), from ./NGC/memguidefig2.c.
 *
 * Each routine calls one Dolphin SDK CARD operation on the guide's channel,
 * logs the result code with OSReport and maps it to a guide message stored
 * at +0x0c. Unexpected codes are logged and mapped to the generic failure
 * message. CARDProbeEx fills the memory size at +0x18 and the sector size at
 * +0x14; CARDMount receives the work area at +0x10. SDK routines and strings
 * stay external original code/data.
 */
extern "C" {

typedef struct W3dCardProbe {
    int channel;
    int status;
    int unknown_08;
    int message;
    void *work_area;
    int sector_size;
    int memory_size;
} W3dCardProbe;

int w3d_card_probe_ex_803162a8(int channel, int *memory_size, int *sector_size);
int w3d_card_mount_80316b0c(int channel, void *work_area, void *detach_callback);
int w3d_card_check_80316150(int channel);
int w3d_card_format_80317438(int channel);
int w3d_card_unformat_80316bf0(int channel);
void w3d_os_report_802fb7ac(const char *format, ...);
extern const char w3d_str_card_probe_ex_803d88c0[];
extern const char w3d_str_unexpected_error_803d88d4[];
extern const char w3d_str_card_mount_803d88ec[];
extern const char w3d_str_card_check_803d8900[];
extern const char w3d_str_card_format_803d8914[];
extern const char w3d_str_card_unformat_803d8928[];
extern unsigned char w3d_card_guide_80368bd8[];

void w3d_card_guide_probe(W3dCardProbe *guide)
{
    int result = w3d_card_probe_ex_803162a8(guide->channel, &guide->memory_size, &guide->sector_size);
    w3d_os_report_802fb7ac(w3d_str_card_probe_ex_803d88c0, result);
    switch (result) {
    case -3: guide->message = -17; break;
    case -1: guide->message = 177; break;
    case -2: guide->message = -15; break;
    case 0: guide->message = 180; break;
    default:
        w3d_os_report_802fb7ac(w3d_str_unexpected_error_803d88d4, result);
        guide->message = -19;
    }
}

void w3d_card_guide_mount(W3dCardProbe *guide)
{
    int result = w3d_card_mount_80316b0c(guide->channel, guide->work_area, 0);
    w3d_os_report_802fb7ac(w3d_str_card_mount_803d88ec, result);
    switch (result) {
    case -2: guide->message = -15; break;
    case -3: guide->message = 176; break;
    case -1: guide->message = 178; break;
    case -6:
    case 0: guide->message = 179; break;
    case -13: guide->message = -14; break;
    default:
        w3d_os_report_802fb7ac(w3d_str_unexpected_error_803d88d4, result);
    case -5:
    case -128:
        guide->message = -19;
    }
}

void w3d_card_guide_check(W3dCardProbe *guide)
{
    int result = w3d_card_check_80316150(guide->channel);
    w3d_os_report_802fb7ac(w3d_str_card_check_803d8900, result);
    switch (result) {
    case -3: guide->message = 176; break;
    case -1: guide->message = 179; break;
    case -6: guide->message = -16; break;
    case -13: guide->message = -14; break;
    case 0: guide->message = 1; break;
    default:
        w3d_os_report_802fb7ac(w3d_str_unexpected_error_803d88d4, result);
    case -5:
        guide->message = -19;
    }
}

void w3d_card_guide_format(W3dCardProbe *guide)
{
    int result = w3d_card_format_80317438(guide->channel);
    w3d_os_report_802fb7ac(w3d_str_card_format_803d8914, result);
    switch (result) {
    case -1: guide->message = 181; break;
    case 0: guide->message = 1; break;
    default:
        w3d_os_report_802fb7ac(w3d_str_unexpected_error_803d88d4, result);
    case -3:
        guide->message = -12;
    }
}

void w3d_card_guide_unformat(W3dCardProbe *guide)
{
    int result = w3d_card_unformat_80316bf0(guide->channel);
    w3d_os_report_802fb7ac(w3d_str_card_unformat_803d8928, result);
    switch (result) {
    case -1: guide->message = 182; break;
    default:
        w3d_os_report_802fb7ac(w3d_str_unexpected_error_803d88d4, result);
    case 0:
        guide->message = -19;
    }
}

unsigned char *w3d_card_guide_get(void)
{
    return w3d_card_guide_80368bd8;
}

}
