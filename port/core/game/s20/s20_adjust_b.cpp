#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_b.c"
/* Methods that run on the secondary base subobject of an object (this - 4, null-checked). */
extern void fn_801f6834(Ptr32<void>, Ptr32<void>, int);
extern int fn_801aa79c(Ptr32<void>, Ptr32<char>);

void w3d_s20_forward_base_pair_801aab20(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    fn_801f6834(item + 48, item + 112, *(Ptr32<int>)(base + 56));
    fn_801aa79c(self, item);
}

int w3d_s20_set_base_mode_801d5700(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    unsigned int flags = *(Ptr32<unsigned short>)(item + 40);
    if (*(Ptr32<int>)(base + 44) != 1)
        *(Ptr32<int>)(base + 44) = (flags >> 1) & 3;
    return 0;
}

typedef Ptr32<void (Ptr32<void>, Ptr32<char>)> S20Slot2;

int w3d_s20_virtual_item_801ac378(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> vtable = *(Ptr32<Ptr32<char>>)base;
    ((S20Slot2)*(Ptr32<Ptr32<void>>)(vtable + 64))(base, item + 20);
    return 0;
}


extern int fn_8016beac(Ptr32<char>, Ptr32<char>);
typedef Ptr32<int (Ptr32<char>)> S20Flush1;
int w3d_s20_flush_base_8016bf68(Ptr32<char> self) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(base + 200) == 0)
        return 0;
    ((S20Flush1)fn_8016beac)(base);
    return 0;
}

extern int fn_801a3944(Ptr32<void>, int);

int w3d_s20_call_keep_base_field_801aaf6c(Ptr32<char> self, int arg) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int saved = *(Ptr32<int>)(base + 164);
    int result;
    *(Ptr32<int>)(base + 164) = arg;
    result = fn_801a3944(self, arg);
    *(Ptr32<int>)(base + 164) = saved;
    return result;
}

extern int fn_801689e4(Ptr32<char>, Ptr32<void>);

void w3d_s20_scoped_base_range_80168a9c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> range = *(Ptr32<Ptr32<char>>)(item + 60);
    *(Ptr32<int>)(base + 132) = *(Ptr32<int>)(range + 24);
    *(Ptr32<Ptr32<char>>)(base + 128) = range + 32;
    fn_801689e4(self, (Ptr32<void>)item);
    *(Ptr32<Ptr32<char>>)(base + 128) = 0;
}

typedef Ptr32<void (Ptr32<void>)> S20Slot0;
typedef Ptr32<Ptr32<void> (Ptr32<void>)> S20SlotObj;
typedef Ptr32<void (Ptr32<void>, Ptr32<char>)> S20SlotPut;

int w3d_s20_dispatch_base_target_80166b14(Ptr32<char> self) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (base != 0) {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(base + 44);
        if (target != 0) {
            ((S20Slot0)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)target + 24))(target);
            return 0;
        }
    }
    return 1;
}

int w3d_s20_virtual_chain_item_801ac3bc(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> object = (Ptr32<char>)((S20SlotObj)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)base + 52))(base);
    ((S20SlotPut)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)object + 84))(object, item + 20);
    return 0;
}

extern void fn_80309404(int, float, int);

int w3d_s20_flush_base_scaled_8016bfb0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(base + 200) == 0)
        return 0;
    fn_80309404(fn_8016beac(base, item), *(Ptr32<float>)(item + 200), 2);
    return 0;
}

typedef struct S20Temp { int words[6]; } S20Temp;
extern void fn_801f5b0c(Ptr32<S20Temp>, Ptr32<char>, int);

int w3d_s20_dispatch_temp_801a5c48(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    S20Temp temp;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    Ptr32<char> tp = (Ptr32<char>)&temp;
    fn_801f5b0c((Ptr32<S20Temp>)tp, record + 32, *(Ptr32<int>)(record + 24));
    ((S20SlotPut)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)base + 76))(base, tp);
    return 0;
}

}
