#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9cached_8014c89c.c"
/* Typed cached-property recovery; reference compiler verified. */

typedef struct S9LimitInterfaceC
{
  Ptr32<Ptr32<void>> vtable;
} S9LimitInterfaceC;
typedef struct S9LimitRefC
{
  Ptr32<S9LimitInterfaceC> pointer;
  int unknown;
} S9LimitRefC;
typedef struct S9LimitNameC
{
  Ptr32<char> text;
  int unknown[3];
} S9LimitNameC;
typedef struct S9LimitLocalsC
{
  S9LimitRefC reference;
  S9LimitNameC name;
} S9LimitLocalsC;
typedef Ptr32<void (Ptr32<S9LimitInterfaceC>)> S9LimitMethodC;
extern Ptr32<S9LimitInterfaceC> lbl_804afdf8;
extern char lbl_803a1230[];
extern unsigned char fn_800fc1b0(Ptr32<S9LimitNameC>, Ptr32<S9LimitRefC>);
extern Ptr32<S9LimitInterfaceC> fn_80342a74(Ptr32<S9LimitInterfaceC>);
extern float fn_8014ca54(Ptr32<void>);
extern float fn_80178df0(Ptr32<S9LimitInterfaceC>);
int s9_compare_cached_limit_8014c89c(Ptr32<void> self)
{
  Ptr32<S9LimitRefC> reference;
  float angle;
  if (!lbl_804afdf8)
  {
    S9LimitLocalsC locals;
    Ptr32<S9LimitInterfaceC> value;
    reference = &locals.reference;
    locals.reference.pointer = 0;
    locals.name.text = lbl_803a1230;
    fn_800fc1b0(&locals.name, &locals.reference);
    value = fn_80342a74((*reference).pointer);
    if (value)
    {
      ((S9LimitMethodC) value->vtable[3])(value);
    }
    if (lbl_804afdf8)
    {
      ((S9LimitMethodC) lbl_804afdf8->vtable[4])(lbl_804afdf8);
    }
    lbl_804afdf8 = value;
    if ((*reference).pointer)
    {
      ((S9LimitMethodC) (*reference).pointer->vtable[4])((*reference).pointer);
    }
  }
  angle = fn_8014ca54(self);
  return angle <= fn_80178df0(lbl_804afdf8);
}

}
