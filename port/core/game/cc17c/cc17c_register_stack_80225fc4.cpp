#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17c_register_stack_80225fc4.c"
/* Same source shape as the admitted property registrations in s10param_801b6ce8.c: a static
 * 20-byte property description is filled once from a zeroed local, then registered.
 * Observed layout: name, 16-bit size, element type byte, type byte, descriptor, two words. */
typedef struct Cc17cPropertyInfo {
 Ptr32<const char> name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 Ptr32<void> descriptor;
 int unknown12;
 int unknown16;
} Cc17cPropertyInfo;
extern Cc17cPropertyInfo lbl_80464a40;
extern int lbl_804b07d8;
extern char lbl_803b7e8c[];
extern char lbl_803b7e9c[];
extern char lbl_8045ed94[];
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
int fn_801efff0(Ptr32<void>, Ptr32<Cc17cPropertyInfo>);
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const char>);
int fn_801e8d9c(Ptr32<void>);
int w3d_cc17c_register_stack_80225fc4(Ptr32<void> self)
{
 if (!lbl_804b07d8) {
 Ptr32<Cc17cPropertyInfo> target = &lbl_80464a40;
 Cc17cPropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803b7e8c;
 info.size = 24;
 info.type = 9;
 info.descriptor = lbl_8045ed94;
 *target = info;
 lbl_804b07d8 = 1;
 }
 fn_801efff0(self, &lbl_80464a40);
 fn_801ebf38(self, lbl_803b7e9c);
 fn_801e8d9c(self);
 return 0;
}

}
