#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "terra_only_c7_registry_801fca98.c"

typedef struct 
{
  Ptr32<void> a;
  Ptr32<void> b;
  Ptr32<void> c;
} Slot;
typedef struct 
{
  Ptr32<void> a;
  Ptr32<const char> name;
  Ptr32<void> zero;
  Ptr32<void> callback;
  int n;
  Ptr32<void> tail;
} Registry;
extern Slot lbl_8045e890[];
extern Registry lbl_8045e92c[];
extern char lbl_803b1d2c[];
extern char lbl_80463308[];
extern int fn_801fc7b0(void);
extern void fn_80200af8(Ptr32<Registry>);
inline static void init(Ptr32<Registry> r, Ptr32<const char> name, Ptr32<void> zero, Ptr32<void> callback, int n, Ptr32<void> tail)
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
  Ptr32<Slot> new_var;
  int i;
  Ptr32<Slot> p;
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
    init(lbl_8045e92c, lbl_803b1d2c, 0, (Ptr32<void>) fn_801fc7b0, new_var2, lbl_80463308);
    fn_80200af8(lbl_8045e92c);
  }
}

}
