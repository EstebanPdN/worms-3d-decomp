#include "w3d_ptr.h"
#line 1 "cx16a_rebuild_path_80005d4c.cpp"
// Observed path rebuild control flow; far fields and release lifetimes are explicit.
#define FIELD(p,T,o) (*(w3d::slot_t<T>)((char*)w3d::AG(p)+(o)))
extern int enabled_804aa794;
extern "C" int call_80004394(Ptr32<void>),call_80005398(Ptr32<void>),call_80005e1c(Ptr32<void>),call_80015264(int),call_8034144c();
extern "C" int call_80005858(Ptr32<void>,int);
extern "C" void w3d_cx16a_rebuild_path_80005d4c(Ptr32<void> arg0) {
    int temp_r29;
    int temp_r3;
    Ptr32<void> temp_r27;
    Ptr32<void> var_r30;
    Ptr32<void> var_r9;

    if ((int) enabled_804aa794 != 0) {
        goto block_2;
    }
    var_r9 = (Ptr32<char>)arg0 + 0x10000;
    FIELD(arg0, int *, 0x800C) = (int) enabled_804aa794;
    var_r30 = var_r9;
    call_80004394(arg0);
    goto block_8;
block_2:
    temp_r27 = (Ptr32<char>)arg0 + 0x4008;
    temp_r3 = call_80005858(temp_r27, 1);
    if (temp_r3 != 0) {
        goto block_5;
    }
    var_r9 = (Ptr32<char>)arg0 + 0x10000;
    FIELD(arg0, int *, 0x800C) = temp_r3;
block_4:
    var_r30 = var_r9;
    call_80004394(arg0);
    goto block_8;
block_5:
    temp_r29 = FIELD(arg0, int *, 0x8010);
    var_r30 = (Ptr32<char>)arg0 + 0x10000;
    if (temp_r29 == 0) {
        goto block_7;
    }
    call_8034144c();
    call_80015264(temp_r29);
block_7:
    FIELD(arg0, int *, 0x8010) = temp_r3;
    FIELD(arg0, int *, 0x8018) = 1;
    call_80005e1c(arg0);
    call_80005398((Ptr32<char>)arg0 + 4);
    call_80005398(temp_r27);
    FIELD(arg0, int *, 0x8050) = (int) FIELD(arg0, int *, 0x804C);
block_8:
    FIELD(var_r30, int *, -0x7FE8) = 1;
    return;
}


