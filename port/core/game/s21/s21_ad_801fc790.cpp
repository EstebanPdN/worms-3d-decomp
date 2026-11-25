#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ad_801fc790.c"
// desc: Appears to store a value and a global sequence number into a record, increment the sequence counter and return the record.
struct S21Record { int value; int serial; };
extern int lbl_804b05d4;
Ptr32<struct S21Record> w3d_s21_stamp_record_801fc790(Ptr32<struct S21Record> record, int value)
{
    record->value = value;
    record->serial = lbl_804b05d4++;
    return record;
}

}
