// desc: Appears to multiply two three-by-three float matrices and store the product in the first argument.
struct S21Matrix3 { float m[3][3]; };
void w3d_s21_multiply3_801f606c(struct S21Matrix3 *result, const struct S21Matrix3 *a, const struct S21Matrix3 *b)
{
    int i, j;
    for (i = 0; i <= 2; i++)
        for (j = 0; j < 3; j++)
            result->m[i][j] = a->m[i][0] * b->m[0][j] + a->m[i][1] * b->m[1][j] + a->m[i][2] * b->m[2][j];
}
