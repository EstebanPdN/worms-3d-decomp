// desc: Appears to call a helper on every pointer of the embedded vector at offset 56.
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
extern void fn_802bd348(void *);
void w3d_s21_each_item_b_802bc5ac(struct S21Object *self)
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
      fn_802bd348(current);
    }
    while (item != new_var->end);
  }
}
