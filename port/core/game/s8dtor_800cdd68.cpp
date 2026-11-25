#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800cdd68.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_8040fc08[];
void fn_80126230(Ptr32<void>, int);
void fn_802134fc(Ptr32<void>);
void fn_80161050(Ptr32<void>, int);

void s8_destroy_800cdd68(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8040fc08;
    fn_80126230((Ptr32<char>)self + 308, 2);
    if (FIELD(self, void *, 252)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 252)->vtable[4])(FIELD(self, W3dInterface *, 252));
    }
    if (FIELD(self, void *, 248)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 248)->vtable[4])(FIELD(self, W3dInterface *, 248));
    }
    if (FIELD(self, void *, 244)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 244)->vtable[4])(FIELD(self, W3dInterface *, 244));
    }
    if (FIELD(self, void *, 240)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 240)->vtable[4])(FIELD(self, W3dInterface *, 240));
    }
    if (FIELD(self, void *, 236)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 236)->vtable[4])(FIELD(self, W3dInterface *, 236));
    }
    if (FIELD(self, void *, 232)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 232)->vtable[4])(FIELD(self, W3dInterface *, 232));
    }
    if (FIELD(self, void *, 228)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 228)->vtable[4])(FIELD(self, W3dInterface *, 228));
    }
    if (FIELD(self, void *, 224)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 224)->vtable[4])(FIELD(self, W3dInterface *, 224));
    }
    if (FIELD(self, void *, 220)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 220)->vtable[4])(FIELD(self, W3dInterface *, 220));
    }
    if (FIELD(self, void *, 216)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 216)->vtable[4])(FIELD(self, W3dInterface *, 216));
    }
    if (FIELD(self, void *, 212)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 212)->vtable[4])(FIELD(self, W3dInterface *, 212));
    }
    if (FIELD(self, void *, 208)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 208)->vtable[4])(FIELD(self, W3dInterface *, 208));
    }
    if (FIELD(self, void *, 204)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 204)->vtable[4])(FIELD(self, W3dInterface *, 204));
    }
    if (FIELD(self, void *, 200)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 200)->vtable[4])(FIELD(self, W3dInterface *, 200));
    }
    if (FIELD(self, void *, 196)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 196)->vtable[4])(FIELD(self, W3dInterface *, 196));
    }
    if (FIELD(self, void *, 192)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 192)->vtable[4])(FIELD(self, W3dInterface *, 192));
    }
    if (FIELD(self, void *, 188)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 188)->vtable[4])(FIELD(self, W3dInterface *, 188));
    }
    if (FIELD(self, void *, 184)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 184)->vtable[4])(FIELD(self, W3dInterface *, 184));
    }
    if (FIELD(self, void *, 180)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 180)->vtable[4])(FIELD(self, W3dInterface *, 180));
    }
    if (FIELD(self, void *, 176)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 176)->vtable[4])(FIELD(self, W3dInterface *, 176));
    }
    if (FIELD(self, void *, 172)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 172)->vtable[4])(FIELD(self, W3dInterface *, 172));
    }
    if (FIELD(self, void *, 168)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 168)->vtable[4])(FIELD(self, W3dInterface *, 168));
    }
    if (FIELD(self, void *, 164)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 164)->vtable[4])(FIELD(self, W3dInterface *, 164));
    }
    if (FIELD(self, void *, 160)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 160)->vtable[4])(FIELD(self, W3dInterface *, 160));
    }
    if (FIELD(self, void *, 156)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 156)->vtable[4])(FIELD(self, W3dInterface *, 156));
    }
    if (FIELD(self, void *, 152)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 152)->vtable[4])(FIELD(self, W3dInterface *, 152));
    }
    if (FIELD(self, void *, 148)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 148)->vtable[4])(FIELD(self, W3dInterface *, 148));
    }
    if (FIELD(self, void *, 144)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 144)->vtable[4])(FIELD(self, W3dInterface *, 144));
    }
    if (FIELD(self, void *, 140)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 140)->vtable[4])(FIELD(self, W3dInterface *, 140));
    }
    if (FIELD(self, void *, 136)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 136)->vtable[4])(FIELD(self, W3dInterface *, 136));
    }
    if (FIELD(self, void *, 132)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 132)->vtable[4])(FIELD(self, W3dInterface *, 132));
    }
    if (FIELD(self, void *, 128)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 128)->vtable[4])(FIELD(self, W3dInterface *, 128));
    }
    if (FIELD(self, void *, 28)) {
        fn_802134fc(FIELD(self, void *, 28));
    }
    fn_80161050(self, flags);
}

}
