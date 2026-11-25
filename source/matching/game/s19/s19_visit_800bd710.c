extern struct { void **begin; void **end; int pad[2]; } lbl_8043bb64;
extern int FUN_800b53d8(void *);
extern void FUN_800bcdec(void *, float);

void s19_refresh_marked_800bd710(void *self)
{
    void **it;
    void **end;
    unsigned mask = 1;
    unsigned *word;
    FUN_800bcdec(self, 0.0f);
    it = lbl_8043bb64.begin;
    end = lbl_8043bb64.end;
    if (it != end) {
        word = (unsigned *)((char *)self + 128);
        do {
            if (*word & mask)
                FUN_800b53d8(*it);
            mask <<= 1;
            if (mask == 0) {
                mask = 1;
                word++;
            }
            it++;
        } while (it != end);
    }
}
