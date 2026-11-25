// desc: Appears to set a mode on the embedded component and, when it changed, refresh the object and notify a text-bearing owner under flag conditions, then update the component again.
struct S21Info
{
  char pad[11];
  unsigned char flags;
  char pad1[140];
  char *text;
};
struct S21Object
{
  char pad[28];
  char component[12];
  struct S21Info *info;
  char pad1[96];
  int armed;
  char pad2[32];
  int mode;
};
extern void fn_802b0990(void *, int);
extern void fn_8026a16c(struct S21Object *);
extern void fn_802b1258(char *);
void w3d_s21_set_mode_80269884(struct S21Object *self, int mode)
{
  int changed = 1;
  void *component;
  if (mode == self->mode)
  {
    changed = 0;
  }
  fn_802b0990(component = (*self).component, mode);
  if (changed)
  {
    fn_8026a16c(self);
    if (mode)
    {
      struct S21Info *info = self->info;
      char *text = info->text;
      if (((*((unsigned short *) (text - 4))) && ((info->flags ^ 4) & 4)) && self->armed)
      {
        fn_802b1258(text);
      }
    }
  }
  fn_802b0990((*self).component, mode);
}
