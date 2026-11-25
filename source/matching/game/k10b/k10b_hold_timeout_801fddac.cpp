// Partial view of a poll routine that debounces a status query. After ten
// calls it watches for status 2 held with a zero flag; the first time it sees
// that it stamps the time in milliseconds (timer ticks divided by the bus
// clock in kHz / 4 kept in low memory at offset 0xf8), and it reports failure
// once the condition has lasted more than 5000 ms. Any other result resets
// the counters. Global names are the original addresses.
struct K10bLowMemory_801fddac {
    char unknown0[0xf8];
    unsigned bus_clock;
};

extern "C" {
extern unsigned lbl_804ab940;  // number of polls
extern int lbl_804ab93c;       // extra condition, must be zero
extern int lbl_804ab944;       // start time in milliseconds
extern int lbl_804ab948;       // set while the timer is running
int fn_802f7694(void *query);
unsigned fn_80300ab8();

int w3d_k10b_hold_timeout_801fddac(int unused, int query) {
    unsigned count = lbl_804ab940 + 1;
    lbl_804ab940 = count;
    if (count > 10) {
        int zero;
        if (fn_802f7694((void *)query) == 2 && (zero = lbl_804ab93c) == 0) {
            if (lbl_804ab948) {
                unsigned ms = fn_80300ab8() / (((K10bLowMemory_801fddac *)0x80000000)->bus_clock / 4000);
                if (ms - lbl_804ab944 > 5000) {
                    lbl_804ab948 = zero;
                    return 0;
                }
            } else {
                unsigned ms = fn_80300ab8() / (((K10bLowMemory_801fddac *)0x80000000)->bus_clock / 4000);
                lbl_804ab948 = 1;
                lbl_804ab944 = ms;
            }
        } else {
            lbl_804ab940 = 0;
            lbl_804ab948 = 0;
        }
    }
    return 1;
}
}
