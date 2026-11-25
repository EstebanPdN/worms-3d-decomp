#include "w3d_ptr.h"
#line 1 "s8hand_800dae1c.cpp"
/* Offsets are observed; the field meanings and identifier cache names remain inferred. */
struct s8_FieldOwner {
    char pad0[20];
    int objectId;
    char pad24[4];
    int field28, field32, field36, field40, field44;
    int field48, field52, field56, field60, field64;
};
extern "C" short fn_8015f5a0(Ptr32<int>,int);
extern "C" int fn_80162024(Ptr32<s8_FieldOwner>,Ptr32<short>,Ptr32<int>);
extern "C" Ptr32<void> fn_801613f0(Ptr32<void>,int);
extern "C" int fn_800c1620(Ptr32<void>,Ptr32<int>);
extern "C" int fn_8016239c(int);
extern int lbl_804aebc4, lbl_804aebcc, lbl_804aebd4, lbl_804aebdc, lbl_804aebe4;
extern int lbl_804aebec, lbl_804aebf4, lbl_804aebfc, lbl_804aec04, lbl_804aec0c;
extern Ptr32<void> lbl_804b1754;
extern "C" void s8_register_fields_800dae1c(Ptr32<s8_FieldOwner> owner) {
    short id28, id32, id36, id40, id64, id44, id48, id52, id56, id60;
    int objectId;
    id28=fn_8015f5a0(&lbl_804aebec,1);
    fn_80162024(owner,&id28,&owner->field28);
    id32=fn_8015f5a0(&lbl_804aebfc,1);
    fn_80162024(owner,&id32,&owner->field32);
    id36=fn_8015f5a0(&lbl_804aec04,1);
    fn_80162024(owner,&id36,&owner->field36);
    id40=fn_8015f5a0(&lbl_804aec0c,1);
    fn_80162024(owner,&id40,&owner->field40);
    id64=fn_8015f5a0(&lbl_804aebf4,1);
    fn_80162024(owner,&id64,&owner->field64);
    id44=fn_8015f5a0(&lbl_804aebc4,1);
    fn_80162024(owner,&id44,&owner->field44);
    id48=fn_8015f5a0(&lbl_804aebcc,1);
    fn_80162024(owner,&id48,&owner->field48);
    id52=fn_8015f5a0(&lbl_804aebd4,1);
    fn_80162024(owner,&id52,&owner->field52);
    id56=fn_8015f5a0(&lbl_804aebdc,1);
    fn_80162024(owner,&id56,&owner->field56);
    id60=fn_8015f5a0(&lbl_804aebe4,1);
    fn_80162024(owner,&id60,&owner->field60);
    Ptr32<void> message=fn_801613f0(lbl_804b1754,12);
    objectId=owner->objectId;
    fn_8016239c(fn_800c1620(message,&objectId));
}


