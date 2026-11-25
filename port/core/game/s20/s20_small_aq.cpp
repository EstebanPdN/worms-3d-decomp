#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_aq.c"
/* Effect trigger, error-code check and global object initializer. */
extern short fn_800fc2b0(Ptr32<Ptr32<char>>, Ptr32<Ptr32<unsigned char>>);
extern Ptr32<void> fn_800fd4c8(int, int);
extern int fn_800fd504(Ptr32<unsigned char>, int, int);
extern char lbl_8038a62c[];
void w3d_s20_trigger_effect_800e64e8(void)
{
  Ptr32<char> key;
  Ptr32<unsigned char> flag;
  flag = 0;
  key = lbl_8038a62c;
  fn_800fc2b0(&key, &flag);
  fn_800fd4c8(6, 1);
  if ((flag != 0) && ((*flag) != 0))
  {
    fn_800fd504(flag, 6, 1);
  }
}

extern int fn_8016b488(Ptr32<char>, Ptr32<void>);
int w3d_s20_check_then_count_8016b6d8(Ptr32<char> self, Ptr32<char> item) {
    int result;
    unsigned int count;
    unsigned int i;
    result = fn_8016b488(self, (Ptr32<void>)item);
    if (result != 0)
        return result;
    count = *(Ptr32<unsigned int>)(item + 84);
    for (i = 0; i < count; i++) {
    }
    return 0;
}

extern char lbl_80455984[];
extern char lbl_80455980[];
extern char lbl_803a64ac[];
extern char lbl_8040ef68[];
extern void fn_80200a70(Ptr32<char>);
int w3d_s20_init_global_object_8016f574(void) {
    *(Ptr32<Ptr32<char>>)lbl_80455984 = lbl_803a64ac;
    *(Ptr32<int>)(lbl_80455984 + 4) = 1;
    *(Ptr32<Ptr32<char>>)(lbl_80455984 + 16) = lbl_8040ef68;
    *(Ptr32<Ptr32<char>>)(lbl_80455984 + 24) = lbl_80455980;
    *(Ptr32<int>)(lbl_80455984 + 12) = 0;
    *(Ptr32<int>)(lbl_80455984 + 36) = 0;
    fn_80200a70(lbl_80455984);
    return 0;
}

}
