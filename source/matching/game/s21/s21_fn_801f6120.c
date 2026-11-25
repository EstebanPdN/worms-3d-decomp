// desc: Appears to rotate the last two columns of a three-by-three float matrix by an angle, using sine and cosine helpers.
struct S21Matrix3
{
  float m[3][3];
};
extern float fn_802e86d4(float);
extern float fn_802e88ac(float);
void w3d_s21_rotate_cols12_801f6120(struct S21Matrix3 *matrix, float angle)
{
  float sine = fn_802e86d4(angle);
  float cosine = fn_802e88ac(angle);
  int i;
  for (i = 0; i < 3; i++)
  {
    float b = matrix->m[i][2];
    float a = matrix->m[i][1];
    matrix->m[i][1] = (a * sine) - (b * cosine);
    matrix->m[i][2] = (a * cosine) + (b * sine);
  }

}
