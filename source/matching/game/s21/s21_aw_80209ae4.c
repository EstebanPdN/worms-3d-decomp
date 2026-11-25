// desc: Appears to clear a table of 256 words and return the table.
int *w3d_s21_clear_table_80209ae4(int *table)
{
    int i;
    int *item = table;
    for (i = 0; i < 256; i++)
        *item++ = 0;
    return table;
}
