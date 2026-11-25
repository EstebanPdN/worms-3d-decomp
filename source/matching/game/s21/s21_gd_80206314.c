// desc: Appears to read fields of a twelve-byte record selected by index: it stores the second and third words through optional output pointers and returns the first word.
struct S21Object
{
  char pad[20];
  char *records;
};
int w3d_s21_get_record_80206314(struct S21Object *self, int index, int *second, int *third)
{
  int offset;
  int new_var;
  if (second)
  {
    *second = *((int *) ((self->records + (index * 12)) + (new_var = 4)));
  }
  offset = index * 12;
  if (third)
  {
    *third = *((int *) ((self->records + offset) + 8));
  }
  return *((int *) (self->records + offset));
}
