#include "w3d_ptr.h"
#line 1 "memcard_guide_report.cpp"
/* Memory-card guideline debug reporter (0x802c59e8), ./NGC/memguidefig2.c.
 *
 * Logs the name of a guide message once, when it differs from the last one
 * reported (kept in a small-data global). An unknown message panics with the
 * original "DEBUGPrintState" diagnostic. Strings and the global stay external
 * original data.
 */
extern "C" {

void w3d_os_report_802fb7ac(Ptr32<const char> format, ...);
void w3d_os_panic_802fb82c(Ptr32<const char> file, int line, Ptr32<const char> format, ...);
extern int w3d_card_guide_last_message_804abc98;
extern const char w3d_str_memguidefig2_803d8888[];
extern const char w3d_str_stat_start_803d8a7c[];
extern const char w3d_str_stat_probe_803d8a9c[];
extern const char w3d_str_stat_mount_803d8abc[];
extern const char w3d_str_stat_check_803d8adc[];
extern const char w3d_str_stat_sector_803d8afc[];
extern const char w3d_str_stat_format_803d8b1c[];
extern const char w3d_str_stat_unmount_803d8b3c[];
extern const char w3d_str_rtrn_done_803d8b5c[];
extern const char w3d_str_rtrn_continue_803d8b74[];
extern const char w3d_str_mesg_corrupt_803d8b90[];
extern const char w3d_str_mesg_damaged_803d8bb0[];
extern const char w3d_str_mesg_nosupport_803d8bd0[];
extern const char w3d_str_mesg_wrongdevice_803d8bf4[];
extern const char w3d_str_mesg_nocard_803d8c18[];
extern const char w3d_str_mesg_encoding_803d8c38[];
extern const char w3d_str_mesg_format_sure_803d8c58[];
extern const char w3d_str_mesg_format_failed_803d8c7c[];
extern const char w3d_str_illegal_print_state_803d8ca4[];

void w3d_card_guide_show_message(int message)
{
    if (message == w3d_card_guide_last_message_804abc98)
        return;
    w3d_card_guide_last_message_804abc98 = message;
    switch (message) {
    case 176: w3d_os_report_802fb7ac(w3d_str_stat_start_803d8a7c); break;
    case 177: w3d_os_report_802fb7ac(w3d_str_stat_probe_803d8a9c); break;
    case 178: w3d_os_report_802fb7ac(w3d_str_stat_mount_803d8abc); break;
    case 179: w3d_os_report_802fb7ac(w3d_str_stat_check_803d8adc); break;
    case 180: w3d_os_report_802fb7ac(w3d_str_stat_sector_803d8afc); break;
    case 181: w3d_os_report_802fb7ac(w3d_str_stat_format_803d8b1c); break;
    case 182: w3d_os_report_802fb7ac(w3d_str_stat_unmount_803d8b3c); break;
    case 1: w3d_os_report_802fb7ac(w3d_str_rtrn_done_803d8b5c); break;
    case 2: w3d_os_report_802fb7ac(w3d_str_rtrn_continue_803d8b74); break;
    case -16: w3d_os_report_802fb7ac(w3d_str_mesg_corrupt_803d8b90); break;
    case -19: w3d_os_report_802fb7ac(w3d_str_mesg_damaged_803d8bb0); break;
    case -18: w3d_os_report_802fb7ac(w3d_str_mesg_nosupport_803d8bd0); break;
    case -15: w3d_os_report_802fb7ac(w3d_str_mesg_wrongdevice_803d8bf4); break;
    case -17: w3d_os_report_802fb7ac(w3d_str_mesg_nocard_803d8c18); break;
    case -14: w3d_os_report_802fb7ac(w3d_str_mesg_encoding_803d8c38); break;
    case -13: w3d_os_report_802fb7ac(w3d_str_mesg_format_sure_803d8c58); break;
    case -12: w3d_os_report_802fb7ac(w3d_str_mesg_format_failed_803d8c7c); break;
    default:
        w3d_os_panic_802fb82c(w3d_str_memguidefig2_803d8888, 755, w3d_str_illegal_print_state_803d8ca4);
    }
}

}


