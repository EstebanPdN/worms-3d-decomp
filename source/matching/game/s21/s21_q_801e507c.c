// desc: Appears to forward a held object pointer to a helper, or return zero when none is held.
struct S21Holder
{
  int pad;
  void *held;
};
extern int fn_801df1ac(void *);
int w3d_s21_query_held_801e507c(struct S21Holder *self)
{
  if (self->held)
  {
    if (self || self->held)
    {
      return fn_801df1ac(self->held);
    }
    else
    {
      return fn_801df1ac(self->held);
    }
  }
  return 0;
}
