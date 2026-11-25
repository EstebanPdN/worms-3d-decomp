#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "d15e_descriptor_cache_801e88b0.c"
/* Original 0x801e88b0: lazily built table of three twelve-byte records kept in
 * one file-scope aggregate (0x8045e048) with a small-data ready flag
 * (0x804b0578). Each record is cleared with memset, called without a
 * prototype as in the original (the call sites clear CR1 bit 6 for an
 * unprototyped call). The first record receives a table pointer, its size
 * word (twelve) and a reference word (one); the second receives a base
 * address and a callback; the third stays zeroed. Returns the aggregate.
 *
 * The record size is held in a function-scope byte local, declared before
 * the ready test; that typed value is what reproduces the original
 * scheduling of the size store (a plain literal schedules the table-address
 * computation one instruction earlier).
 * Record field meanings are inferred; external storage remains unowned.
 */
typedef struct D15eRecord {
    Ptr32<void> table;
    unsigned int size;
    unsigned int refs;
} D15eRecord;

extern D15eRecord lbl_8045e048[];
extern int lbl_804b0578;
extern char lbl_8040c990[];
extern unsigned int lbl_804ac804;
extern void fn_8020b574();
extern Ptr32<void> memset(Ptr32<void>, int, unsigned int);

Ptr32<D15eRecord> w3d_d15e_descriptor_cache_801e88b0(void)
{
    unsigned char record_size = 12;

    if (!lbl_804b0578) {
        Ptr32<D15eRecord> records = lbl_8045e048;
        memset(records, 0, 12);
        records->table = lbl_8040c990;
        records->size = record_size;
        records->refs = 1;
        memset(records + 1, 0, 12);
        records[1].size = (unsigned int)w3d::H(&lbl_804ac804);
        records[1].refs = (unsigned int)w3d::H(fn_8020b574);
        memset(records + 2, 0, 12);
        lbl_804b0578 = 1;
    }
    return lbl_8045e048;
}

}
