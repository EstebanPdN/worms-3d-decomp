#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_c.c"
/* Methods that run on the secondary base subobject of an object (this - 4, null-checked). */
typedef struct S20Temp { int words[6]; } S20Temp;
typedef Ptr32<void (Ptr32<void>, Ptr32<char>)> S20SlotPut;
extern void fn_801f5c1c(Ptr32<S20Temp>, Ptr32<char>, int);
extern void fn_801f57d4(Ptr32<S20Temp>, Ptr32<char>, int, Ptr32<char>);
extern void fn_801f5970(Ptr32<S20Temp>, Ptr32<char>, int, int);

int w3d_s20_dispatch_temp_801a5cb0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    S20Temp temp;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 24);
    Ptr32<char> tp = (Ptr32<char>)&temp;
    fn_801f5c1c((Ptr32<S20Temp>)tp, record + 32, *(Ptr32<int>)(record + 24));
    ((S20SlotPut)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)base + 76))(base, tp);
    return 0;
}

int w3d_s20_dispatch_temp_801a5d18(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    S20Temp temp;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    Ptr32<char> tp = (Ptr32<char>)&temp;
    fn_801f57d4((Ptr32<S20Temp>)tp, record + 32, *(Ptr32<int>)(record + 24), item + 24);
    ((S20SlotPut)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)base + 76))(base, tp);
    return 0;
}

int w3d_s20_dispatch_temp_801a5d88(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    S20Temp temp;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    Ptr32<char> tp = (Ptr32<char>)&temp;
    fn_801f5970((Ptr32<S20Temp>)tp, record + 32, *(Ptr32<int>)(record + 24), *(Ptr32<unsigned char>)(item + 24));
    ((S20SlotPut)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)base + 76))(base, tp);
    return 0;
}

int w3d_s20_attach_record_80168e28(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 24);
    int link = *(Ptr32<int>)(record + 24);
    Ptr32<char> range = record + 32;
    if (range == 0)
        return 0;
    *(Ptr32<int>)(base + 188) = link;
    if (link != 0) {
        *(Ptr32<Ptr32<char>>)(base + 160) = range;
        *(Ptr32<unsigned int>)(base + 180) |= 0x40000000;
    } else {
        *(Ptr32<int>)(base + 160) = link;
        *(Ptr32<unsigned int>)(base + 180) &= ~0x40000000u;
    }
    *(Ptr32<unsigned int>)(base + 180) &= 0x7fffffff;
    *(Ptr32<int>)(base + 292) = 0;
    return 0;
}

extern int fn_801a4874(Ptr32<char>, Ptr32<char>);
extern int fn_801a3ba0(Ptr32<char>, Ptr32<char>);
extern int fn_801a3d90(Ptr32<char>, Ptr32<char>);
extern int fn_801aa79c(Ptr32<char>, Ptr32<char>);
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20Handler;

int w3d_s20_apply_item_mode_801d5730(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result;
    *(Ptr32<int>)(base + 44) = 0;
    result = fn_801a4874(self, item);
    if (*(Ptr32<int>)(base + 48) != 0)
        *(Ptr32<unsigned int>)(item + 88) = (*(Ptr32<unsigned int>)(item + 88) & ~6u) | 2;
    else
        *(Ptr32<unsigned int>)(item + 88) = (*(Ptr32<unsigned int>)(item + 88) & ~6u) | (*(Ptr32<int>)(base + 44) << 1);
    return result;
}

int w3d_s20_apply_item_mode_801d567c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result;
    *(Ptr32<int>)(base + 44) = 0;
    result = fn_801a3ba0(self, item);
    if (result >= 0) {
        if (*(Ptr32<int>)(base + 48) != 0)
            *(Ptr32<unsigned int>)(item + 24) = (*(Ptr32<unsigned int>)(item + 24) & ~6u) | 2;
        else
            *(Ptr32<unsigned int>)(item + 24) = (*(Ptr32<unsigned int>)(item + 24) & ~6u) | (*(Ptr32<int>)(base + 44) << 1);
    }
    return result;
}

int w3d_s20_apply_item_mode_801d59d0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result;
    *(Ptr32<int>)(base + 44) = 0;
    result = fn_801a3d90(self, item);
    if (result >= 0) {
        if (*(Ptr32<int>)(base + 48) != 0)
            *(Ptr32<unsigned int>)(item + 24) = (*(Ptr32<unsigned int>)(item + 24) & ~6u) | 2;
        else
            *(Ptr32<unsigned int>)(item + 24) = (*(Ptr32<unsigned int>)(item + 24) & ~6u) | (*(Ptr32<int>)(base +

 44) << 1);
    }
    return result;
}

int w3d_s20_handle_item_target_801aaee8(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0) {
        int saved = *(Ptr32<int>)(base + 44);
        Ptr32<char> sub = base + 4;
        *(Ptr32<int>)(base + 44) = 0;
        ((S20Handler)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        *(Ptr32<int>)(base + 44) = saved;
    }
    return fn_801aa79c(self, item);
}

}
