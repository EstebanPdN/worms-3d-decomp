struct T264State {
    unsigned pad0;
    unsigned short slots[2];
    unsigned flags;
    char pad12[32];
    unsigned a;
    unsigned pad48;
    unsigned b;
    int c;
    unsigned values[2];
    char pad68[96];
    unsigned d;
    void *table;
};
struct T264Global { char pad[60]; unsigned flags; };
extern "C" char lbl_80416f78[];
extern "C" T264Global lbl_8045dbc8[];
extern "C" void t264_init_801e5a60(T264State *s)
{
    s->table = lbl_80416f78;
    s->c = -1;
    s->flags &= 0xff1fffff;
    s->a = 0;
    unsigned short *slots = s->slots;
    s->b = 0;
    s->d = 0;
    unsigned *values = s->values;
    unsigned i = 0;
    do {
        *values++ = 0;
        ++i;
        *slots++ = 0xffff;
    } while (i < 2);
    T264Global *p = lbl_8045dbc8;
    for (int n = 16; n != 0; --n, ++p)
        p->flags &= 0x3fffffff;
}
