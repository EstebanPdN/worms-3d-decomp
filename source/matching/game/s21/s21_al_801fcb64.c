// desc: Appears to pack its two arguments into a stack pair and pass the pair to a helper, returning its result.
struct S21Pair { int first; int second; };
extern int fn_801fcb90(struct S21Pair *);
int w3d_s21_pack_pair_801fcb64(int first, int second)
{
    struct S21Pair pair;
    pair.first = first;
    pair.second = second;
    return fn_801fcb90(&pair);
}
