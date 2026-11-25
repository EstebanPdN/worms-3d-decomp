// desc: Appears to call a helper on every pointer of the embedded vector at offset 56 and return zero.
struct S21Vector
{
  void **begin;
  void **end;
};
struct S21Object
{
  char pad[56];
  struct S21Vector items;
};
extern void fn_802c0064(void *);
int w3d_s21_each_item_802bbfc8(struct S21Object *self)
{
  struct S21Vector *items = &self->items;
  void **item = items->begin;
  struct S21Vector *new_var;
  if (item != items->end)
  {
 do { } while (0);
    new_var = &self->items;
    do
    {
      void *current = *item;
      item++;
      fn_802c0064(current);
    }
    while (item != new_var->end);
  }
  return 0;
}
