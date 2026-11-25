struct S21Pair { int first; int second; };
extern struct S21Pair lbl_804b0554;
static inline void s21_reset(struct S21Pair *p)
{
    p->first = 0;
    p->second = 0;
}
void w3d_s21_static_reset_pair_801d9844(int initialize, int priority)
{
    if (priority == 0xffff && initialize)
        s21_reset(&lbl_804b0554);
}
