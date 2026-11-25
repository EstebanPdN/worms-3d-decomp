#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_d.c"
struct S19RcObj;
struct S19RcVT { char pad0[20]; Ptr32<void (Ptr32<struct S19RcObj>)> destroy; };
struct S19RcObj { Ptr32<struct S19RcVT> vt; int pad4; int refs; };

int s19_release_ref_80023200(Ptr32<struct S19RcObj> p) {
    int n = --p->refs;
    if (n == 0)
        p->vt->destroy(p);
    return n;
}

struct S19Notify;
struct S19NotifyVT { char pad0[56]; Ptr32<void (Ptr32<struct S19Notify>)> fire; };
struct S19Notify { Ptr32<struct S19NotifyVT> vt; char pad4[44]; int fired; };

void s19_fire_once_8002ad9c(Ptr32<struct S19Notify> p) {
    if (p->fired == 0) {
        p->fired = 1;
        p->vt->fire(p);
    }
}

struct S19V3 { float x, y, z; };
struct S19Pose2 { char pad0[52]; struct S19V3 a; struct S19V3 b; int valid; };

void s19_set_pose_8002e558(Ptr32<struct S19Pose2> p, Ptr32<struct S19V3> vb, Ptr32<struct S19V3> va) {
    p->b = *vb;
    p->a = *va;
    p->valid = 1;
}

struct S19Cell;
struct S19CellVT { char pad0[20]; Ptr32<void (Ptr32<struct S19Cell>)> slot5; };
struct S19Cell { char pad0[4]; int a; int b; char pad12[4]; Ptr32<struct S19CellVT> vt; };
struct S19CellRef { Ptr32<struct S19Cell> cell; };
struct S19CellOwner { char pad0[28]; Ptr32<struct S19CellRef> ref; };

void s19_reset_cell_80022704(Ptr32<struct S19CellOwner> p) {
    Ptr32<struct S19Cell> c = p->ref->cell;
    c->a = 0;
    c->b = 1;
    c->vt->slot5(c);
}

}
