#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_lua_a.c"
/* Lua binding helpers. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_802ddd14(Ptr32<void>, int, int, Ptr32<char>);
extern char lbl_803a991c[];

int w3d_s20_load_script_8019e1a8(Ptr32<char> self, int a, int b) {
    return fn_802ddd14(*(Ptr32<Ptr32<void>>)(self + 20), a, b, lbl_803a991c) != 0 ? 0x80004005 : 0;
}

extern Ptr32<int> fn_8019e68c(Ptr32<char>, int);
extern int fn_801ea470(Ptr32<void>);

int w3d_s20_apply_user_value_8019f9ec(Ptr32<char> self) {
    Ptr32<int> value = fn_8019e68c(self, 1);
    int converted = fn_801ea470(w3d::G(*value));
    Ptr32<S20Object> target = *(Ptr32<Ptr32<S20Object>>)(*(Ptr32<Ptr32<char>>)(self + 88) + 36);
    ((Ptr32<void (Ptr32<S20Object>, int)>)target->vtable[7])(target, converted);
    return 1;
}

extern Ptr32<void> fn_802cde08(Ptr32<void>, int);
typedef struct S20Record { char pad[4]; unsigned short half; unsigned char byte; } S20Record;
typedef struct S20Holder { Ptr32<S20Record> record; } S20Holder;
extern Ptr32<S20Holder> lbl_804ab728;
extern int fn_801ef174(int, int, int, Ptr32<void>);

int w3d_s20_forward_user_values_8019e7e8(Ptr32<void> L) {
    int first = *(Ptr32<int>)fn_802cde08(L, 1);
    int second = *(Ptr32<int>)fn_802cde08(L, -1);
    Ptr32<S20Record> record = lbl_804ab728->record;
    fn_801ef174(first, record->half, record->byte, w3d::G(second));
    return 0;
}

int w3d_s20_query_object_8019dd80(Ptr32<char> self, Ptr32<char> object, Ptr32<int> out) {
    int local;
    Ptr32<char> sub = object + 4;
    Ptr32<S20Object> first = *(Ptr32<Ptr32<S20Object>>)object;
    int status = ((Ptr32<int (Ptr32<S20Object>, Ptr32<char>, int, Ptr32<int>)>)first->vtable[5])(first, sub, 16384, &local);
    *out = local;
    if (status < 0)
        return 0;
    return local != 0 ? (int)w3d::H(sub) : 0;
}

}
