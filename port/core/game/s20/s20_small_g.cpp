#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_g.c"
/* Message creation, counted unregistration and small constructors. */
typedef struct S20Msg { short id; short pad; Ptr32<void> table; } S20Msg;
extern Ptr32<S20Msg> fn_801613f0(Ptr32<void>, int);
extern Ptr32<void> lbl_804b1754;
extern char lbl_8040db38[];

Ptr32<S20Msg> w3d_s20_make_message_800fb9e0(Ptr32<unsigned short> self) {
    Ptr32<S20Msg> message = fn_801613f0(lbl_804b1754, 8);
    unsigned short id = *self;
    message->table = lbl_8040db38;
    message->id = id;
    return message;
}

extern void fn_801656bc(Ptr32<char>);
extern void fn_8017b8f4(Ptr32<char>);
extern void fn_8020fd2c(Ptr32<char>, Ptr32<char>);
typedef struct S20List { unsigned char pad[0x20]; unsigned short count; unsigned short w3d_flags_high; } S20List;
extern S20List lbl_804552b0;
extern S20List lbl_80457014;

void w3d_s20_unregister_801655b0(Ptr32<char> self) {
    fn_801656bc(self);
    fn_8020fd2c((Ptr32<char>)&lbl_804552b0, self + 4);
    lbl_804552b0.count -= 1;
}

void w3d_s20_unregister_8017b7e8(Ptr32<char> self) {
    fn_8017b8f4(self);
    fn_8020fd2c((Ptr32<char>)&lbl_80457014, self + 4);
    lbl_80457014.count -= 1;
}

extern void fn_80308be8(int);
extern int lbl_803a54f4[];

int w3d_s20_select_entry_8016a570(Ptr32<char> self, Ptr32<char> item) {
    int index = *(Ptr32<int>)(item + 24);
    if (index == 0)
        fn_80308be8(0);
    else
        fn_80308be8(lbl_803a54f4[index]);
    return 0;
}

typedef struct S20FlagRec { char pad[20]; unsigned int rest:15; unsigned int flag:1; unsigned int low:16; } S20FlagRec;
extern Ptr32<S20FlagRec> fn_8019a2a8(Ptr32<char>, int);

/* El original hace rlwimi sobre la palabra big-endian en +20: el bit 0x8000 de esa palabra es el bit alto de la media
   palabra en +22, y el resto del código lee el registro por medias palabras (clave en +18). Con el campo de bits en una
   palabra little-endian la marca caía en la media palabra +20: la pista de bucle de la mirilla (Aimer_Loop) nunca
   tomaba el relevo de la intro y la mirilla desaparecía, en Mac y en 3DS (comparado con Dolphin, 2026-11-03). */
int w3d_s20_set_record_flag_80199fa4(Ptr32<char> self, int key, int value) {
    Ptr32<S20FlagRec> record = fn_8019a2a8(self, key);
    if (record == 0)
        return 0;
    Ptr32<unsigned short> half = (Ptr32<unsigned short>)((Ptr32<char>)record + 22);
    *half = (unsigned short)((*half & 0x7fff) | ((value & 1) << 15));
    return 1;
}

typedef struct S20Pair2 { int a; int b; } S20Pair2;
extern int fn_801b529c(Ptr32<char>, Ptr32<void>);
extern char lbl_80415320[];

Ptr32<char> w3d_s20_construct_pair_801bc394(Ptr32<char> self, Ptr32<void> arg_r4) {
    fn_801b529c(self, arg_r4);
    *(Ptr32<long long>)(self + 24) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80415320;
    return self;
}

}
