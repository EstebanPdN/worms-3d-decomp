/* Observed interface pointer at 28 and four 16-bit options at 20..26. */
#define S9_FIELD(p,T,o) (*(T)((char *)(p)+(o)))
int s9_set_interface_options_8016f3b4(void *self, void **value, int unused, short a, short b, short c, short d) {
    void **previous;
    void *table;

    if (value == 0) {
        goto block_2;
    }
    table = *value;
    S9_FIELD(table, int (**)(void **), 0xC)(value);
block_2:
    previous = S9_FIELD(self, void ***, 0x1C);
    if (previous == 0) {
        goto block_4;
    }
    S9_FIELD(*previous, int (**)(void *), 0x10)(previous);
block_4:
    S9_FIELD(self, void ***, 0x1C) = value;
    S9_FIELD(self, short *, 0x14) = a;
    S9_FIELD(self, short *, 0x16) = b;
    S9_FIELD(self, short *, 0x18) = c;
S9_FIELD(self, short *, 0x1A) = d;
    return 0;
}
