// desc: Appears to rotate the first two columns of a three-by-three float matrix by an angle, using sine and cosine helpers.
struct S21Matrix3
{
  float m[3][3];
};
extern float fn_802e86d4(float);
extern float fn_802e88ac(float);
void w3d_s21_rotate_cols01_801f621c(struct S21Matrix3 *matrix, float angle)
{
  float sine = fn_802e86d4(angle);
  float cosine = fn_802e88ac(angle);
  int i;
  float new_var;
  for (i = 0; i < 3; i++)
  {
    float b = matrix->m[i][1];
    float a = matrix->m[i][0];
    new_var = (a * sine) - (b * cosine);
    matrix->m[i][1] = (a * cosine) + (b * sine);
    matrix->m[i][0] = new_var;
  }

}
