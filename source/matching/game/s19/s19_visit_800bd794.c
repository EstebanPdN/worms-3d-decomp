extern struct { void **begin; void **end; int pad[2]; } lbl_8043bb64;
extern int FUN_800b53d8(void *);

void s19_visit_marked_800bd794(void *self)
{
    void **it = lbl_8043bb64.begin;
    void **end = lbl_8043bb64.end;
    unsigned mask = 1;
    unsigned *word;
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
