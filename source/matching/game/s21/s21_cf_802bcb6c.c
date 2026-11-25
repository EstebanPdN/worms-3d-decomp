// desc: Appears to store a changed value at offset 84 and push it to every pointer of the embedded vector at offset 56 through a helper.
struct S21Vector
{
  void **begin;
  void **end;
};
struct S21Object
{
  char pad[56];
  struct S21Vector items;
  char pad1[20];
  int value;
};
extern void fn_802bfb2c(void *, int);
void w3d_s21_set_value_all_802bcb6c(struct S21Object *self, int value)
{
  struct S21Object *new_var3;
  new_var3 = self;
  if (new_var3->value != value)
  {
    new_var3->value = value;
    {
      struct S21Vector *items = &self->items;
      void **item = items->begin;
      struct S21Vector *new_var;
      if (item != items->end)
      {
        new_var3 = self;
        new_var = &new_var3->items;
        do
        {
          void *current = *item;
          item++;
          fn_802bfb2c(current, new_var3->value);
        }
        while (item != new_var->end);
      }
    }
  }
}
