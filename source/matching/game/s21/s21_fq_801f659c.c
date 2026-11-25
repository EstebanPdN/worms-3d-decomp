// desc: Appears to report whether two three-by-three float matrices are equal within a tolerance by comparing the absolute difference of every element.
struct S21Matrix3 { float m[3][3]; };
int w3d_s21_matrix3_near_801f659c(const struct S21Matrix3 *a, const struct S21Matrix3 *b, float tolerance)
{
    int i, j;
    for (i = 0; i <= 2; i++)
        for (j = 0; j < 3; j++) {
            if (__builtin_fabs(b->m[i][j] - a->m[i][j]) > tolerance)
                return 0;
        }
    return 1;
}
