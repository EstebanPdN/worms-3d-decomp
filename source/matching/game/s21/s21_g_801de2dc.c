extern int fn_8020b6e8(void *, int *);
int w3d_s21_query_value_801de2dc(void *self, int *out)
{
  int value;
  int *value_address;
  int status;
  int zero;
  value_address = &value;
  zero = 0;
  *out = (value = zero);
  value += zero;
  status = fn_8020b6e8(self, value_address);
  if (status >= zero)
  {
    *out = value;
  }
  return status;
}
