#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1k_table_find_8028924c.c"
/* Appears to search a table of 56-byte records keyed by their first word. */
struct K1kKeyedRecord {
    int key;            /* -128 terminates the table */
    char pad04[52];
};

extern struct K1kKeyedRecord lbl_80401340[];

Ptr32<struct K1kKeyedRecord> w3d_table_find_record_8028924c(Ptr32<void> self, int key)
{
    int i;
    for (i = 0; lbl_80401340[i].key != -128; i++) {
        if (lbl_80401340[i].key == key)
            return &lbl_80401340[i];
    }
    return 0;
}

}
