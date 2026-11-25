#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_props_h.c"
/* Registration with a vector default and a lazily initialized property descriptor. */
typedef struct S20PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int reserved16;
} S20PropertyInfo;
typedef struct S20Vec3 { float x; float y; float z; } S20Vec3;
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
extern int lbl_804b03f0;
extern S20PropertyInfo lbl_8045d19c;
extern char lbl_803abbac[];
extern float lbl_803abbd8[];
extern char lbl_803abbd0[];
extern char lbl_8045ed7c[];
Ptr32<char> fn_801f0504(Ptr32<void>, Ptr32<char>);
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S20PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);

int w3d_s20_register_range_property_801bd79c(Ptr32<void> object)
{
    Ptr32<char> property;
    S20Vec3 value;
    Ptr32<volatile float> words;
    S20PropertyInfo info;
    property = fn_801f0504(object, lbl_803abbac);
    words = (Ptr32<volatile float>)&value;
    words[0] = lbl_803abbd8[0];
    words[2] = lbl_803abbd8[0];
    words[1] = lbl_803abbd8[0];
    *(Ptr32<S20Vec3>)(property + 8) = value;
    if (!lbl_804b03f0) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d19c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abbd0;
        info.size = 40;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b03f0 = 1;
    }
    fn_801efec4(object, &lbl_8045d19c);
    fn_801e8d9c(object);
    return 0;
}

}
