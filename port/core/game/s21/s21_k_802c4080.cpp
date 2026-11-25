#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_k_802c4080.c"
struct S21Cycler { char pad[332]; int index; };
extern void fn_802c38cc(Ptr32<struct S21Cycler>, int);
void w3d_s21_cycle_index_802c4080(Ptr32<struct S21Cycler> self){ int c = self->index; int next; if (c == 5) next = 0; else next = c+1; fn_802c38cc(self,next);}
}
