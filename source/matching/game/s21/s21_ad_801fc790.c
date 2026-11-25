// desc: Appears to store a value and a global sequence number into a record, increment the sequence counter and return the record.
struct S21Record { int value; int serial; };
extern int lbl_804b05d4;
struct S21Record *w3d_s21_stamp_record_801fc790(struct S21Record *record, int value)
{
    record->value = value;
    record->serial = lbl_804b05d4++;
    return record;
}
