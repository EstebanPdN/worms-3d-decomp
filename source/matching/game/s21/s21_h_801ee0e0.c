struct S21Table { char pad[24]; unsigned count; int reserved; int items[1]; };
int w3d_s21_table_find_801ee0e0(struct S21Table *table, int value, unsigned *index)
{
    unsigned i = 0;
    int *item = table->items;
    if (i < table->count) {
        do {
            if (*item++ == value) {
                *index = i;
                return 0;
            }
            i++;
        } while (i < table->count);
    }
    return 0x80004005;
}
