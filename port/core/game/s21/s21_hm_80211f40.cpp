#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_hm_80211f40.c"
// desc: Appears to ask its embedded inner object for a related object through a virtual slot and then invoke another virtual slot on the result.
struct S21Target;
struct S21TargetMethods { Ptr32<void (void)> reserved[22]; Ptr32<void (Ptr32<struct S21Target>)> run; };
struct S21Target { Ptr32<struct S21TargetMethods> methods; };
struct S21Inner;
struct S21InnerMethods { Ptr32<void (void)> reserved[6]; Ptr32<Ptr32<struct S21Target> (Ptr32<struct S21Inner>)> get_target; };
struct S21Inner { Ptr32<struct S21InnerMethods> methods; };
struct S21Owner { char pad[20]; struct S21Inner inner; };
void w3d_s21_run_inner_target_80211f40(Ptr32<struct S21Owner> self)
{
    Ptr32<struct S21Target> target = self->inner.methods->get_target(&self->inner);
    target->methods->run(target);
}

}
