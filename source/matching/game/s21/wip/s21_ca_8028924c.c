// desc: Appears to search a table of 56-byte records terminated by the key minus 128 and return the record whose first word equals the key, or zero.
struct S21Record { int key; char pad[52]; };
extern struct S21Record lbl_80401340[];
struct S21Record *w3d_s21_find_record_8028924c(int unused, int key)
{
    struct S21Record *record = lbl_80401340;
    if (record->key != -128) {
        int offset = 0;
        do {
            if (*(int *)((char *)lbl_80401340 + offset) == key)
                return record;
            offset += 56;
            record++;
        } while (*(int *)((char *)lbl_80401340 + offset) != -128);
    }
    return 0;
}
