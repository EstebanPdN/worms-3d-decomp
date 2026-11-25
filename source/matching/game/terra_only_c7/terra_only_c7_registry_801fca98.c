
typedef struct 
{
  void *a;
  void *b;
  void *c;
} Slot;
typedef struct 
{
  void *a;
  const char *name;
  void *zero;
  void *callback;
  int n;
  void *tail;
} Registry;
extern Slot lbl_8045e890[];
extern Registry lbl_8045e92c[];
extern char lbl_803b1d2c[];
extern char lbl_80463308[];
extern int fn_801fc7b0(void);
extern void fn_80200af8(Registry *);
inline static void init(Registry *r, const char *name, void *zero, void *callback, int n, void *tail)
{
  r->name = name;
  r->zero = zero;
  r->callback = callback;
  r->n = n;
  r->tail = tail;
}

void terra_only_c7_registry_801fca98(int initialize, int priority)
{
  int new_var2;
  Slot *new_var;
  int i;
  Slot *p;
  if ((priority == 0xffff) && initialize)
  {
    new_var = lbl_8045e890;
    p = new_var;
    for (i = 13; i != 0; --i, ++p)
    {
      p->c = 0;
      p->b = 0;
      p->a = 0;
    }

    new_var2 = 10;
    init(lbl_8045e92c, lbl_803b1d2c, 0, (void *) fn_801fc7b0, new_var2, lbl_80463308);
    fn_80200af8(lbl_8045e92c);
  }
}
