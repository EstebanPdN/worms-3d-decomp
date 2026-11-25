// desc: Appears to copy a four-by-four float matrix from the second argument into the first with rows and columns exchanged.
struct S21Matrix4 { float m[4][4]; };
void w3d_s21_transpose4_801f69a8(struct S21Matrix4 *dst, const struct S21Matrix4 *src)
{
    int i, j;
    for (i = 0; i <= 3; i++)
        for (j = 0; j < 4; j++)
            dst->m[i][j] = src->m[j][i];
}
