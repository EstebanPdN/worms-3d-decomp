// desc: Appears to rotate the last two rows of a three-by-three float matrix by an angle, using sine and cosine helpers.
struct S21Matrix3 { float m[3][3]; };
extern float fn_802e86d4(float);
extern float fn_802e88ac(float);
void w3d_s21_rotate_rows12_801f62d0(struct S21Matrix3 *matrix, float angle)
{
    float sine = fn_802e86d4(angle);
    float cosine = fn_802e88ac(angle);
    volatile char frame_pad[16];
    int j;
    for (j = 0; j < 3; j++) {
        float b = matrix->m[2][j];
        float a = matrix->m[1][j];
        matrix->m[2][j] = b * sine - a * cosine;
        matrix->m[1][j] = a * sine + b * cosine;
    }
}
