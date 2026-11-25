// desc: Appears to compare the element arrays of two objects at the descriptor offset: equal lengths are required, then all element bytes are compared, reporting equality.
struct S21Info
{
  char pad[4];
  unsigned short offset;
  char pad1[2];
  int size;
};
struct S21Field
{
  struct S21Info *info;
};
struct S21Array
{
  char pad[24];
  int count;
  char pad2[4];
  char data[1];
};
extern int fn_80200050(int);
extern int fn_802eedc0(const void *, const void *, int);
int w3d_s21_equal_arrays_801ef764(struct S21Field *field, char *first, char *second)
{
  struct S21Info *info = field->info;
  unsigned short offset = info->offset;
  struct S21Array *b;
  char *new_var2;
  struct S21Array *a = *((struct S21Array **) (first + offset));
  int other = (*((struct S21Array **) (second + offset)))->count;
  char *new_var;
  int count = a->count;
  if (count != other)
  {
    return 0;
  }
  new_var2 = a->data;
  new_var = new_var2;
  return fn_802eedc0(new_var, (*((struct S21Array **) (second + offset)))->data, count * fn_80200050(info->size)) == 0;
}
