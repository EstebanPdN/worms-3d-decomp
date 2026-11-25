extern double fn_802ed878(int);
int w3d_s21_read_float_801ff100(void *self, float *out, int value)
{
    *out = (float)fn_802ed878(value);
    return 0;
}
