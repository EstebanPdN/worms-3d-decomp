// desc: Appears to copy a three-by-three float matrix from the second argument into the first with rows and columns exchanged.
struct S21Matrix3 { float m[3][3]; };
void w3d_s21_transpose3_801f60dc(struct S21Matrix3 *dst, const struct S21Matrix3 *src)
{
    int i, j;
    for (i = 0; i <= 2; i++)
        for (j = 0; j < 3; j++)
            dst->m[i][j] = src->m[j][i];
}
