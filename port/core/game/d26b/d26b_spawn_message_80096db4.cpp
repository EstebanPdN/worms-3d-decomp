#include "w3d_ptr.h"
#line 1 "d26b_spawn_message_80096db4.cpp"
/* Script object replication (0x80096db4): looks up the object named by the message
 * (0x80164fc8), reads its type through slot +20 and, for each known type record, creates
 * the matching replica object through 0x8020b680, fills it (id, held references passed by
 * value, vectors, value triple) and posts it to the system 0x804b178c with the id
 * (0x80164514). Type and field names are inferred from the original instructions. Owns
 * no data. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;  /* +12 */
    Ptr32<void> unknown16;
    Ptr32<Ptr32<void> (Ptr32<Object>)> type;   /* +20 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Held {
    Ptr32<Object> object;
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Object *)w3d_p.get()) {}
 Held(Object *o) { object = o; if (o) o->vtable->retain(o); }
    Held(const Held &o);
};
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct Source : Object {
    char unknown04[16] __attribute__((aligned(__alignof__(Object))));
    int id;              /* +20 */
    char unknown24[4];
    Ptr32<Object> held28;      /* +28 */
    Vec3 a;              /* +32 */
    Vec3 b;              /* +44 */
    char unknown56[60];
    unsigned char flag;  /* +116 */
    char unknown117[3];
    int triple[3];       /* +120 */
    int value132;        /* +132 */
    char unknown136[56];
    Ptr32<Object> held192;     /* +192 */
    char unknown196[388];
    int value584;        /* +584 */
};
struct Copy3 { int v[3]; };
struct Spawn5 {
    char unknown00[32];
    int id;              /* +32 */
    char unknown36[4];
    unsigned char flag;  /* +40 */
    char unknown41[3];
    Copy3 triple;        /* +44 */
    int value56;         /* +56 */
};
struct Message { char unknown00[8]; int id; };
struct Self { char unknown00[20]; int id; };
extern "C" Ptr32<Source> w3d_lookup_80164fc8(int);
extern "C" Ptr32<void> w3d_service_forward_8020b680(Ptr32<void>);
extern "C" int w3d_post_80164514(Ptr32<void>, Ptr32<void>, int);
extern "C" void w3d_assign_800e8fb4(Ptr32<void>, Held);
extern "C" void w3d_set_80133d64(Ptr32<void>, int);
extern "C" void w3d_set_pair_8002e558(Ptr32<void>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" void w3d_assign_8009afe8(Ptr32<void>, Held);
extern Ptr32<void> w3d_system_804b178c;
extern char w3d_type_80360c60[];
extern char w3d_type_80360690[];
extern char w3d_type_80361470[];
extern char w3d_type_80360240[];
extern char w3d_type_803608a0[];
extern char w3d_type_80360210[];
extern char w3d_type_80360480[];
extern char w3d_type_803615f0[];
extern char w3d_type_8035fe20[];
extern char w3d_type_80360c30[];
extern char w3d_type_80360ba0[];
extern char w3d_type_80360840[];
extern char w3d_type_80360390[];
extern char w3d_type_80361440[];
extern char w3d_type_80360cc0[];
extern char w3d_type_803605d0[];
extern char w3d_type_80360660[];
extern char w3d_type_803600c0[];
extern char w3d_type_80360540[];
extern char w3d_type_8035ff70[];
extern char w3d_type_80360d50[];
extern char w3d_type_80361620[];
extern char w3d_type_8035fd90[];
extern char w3d_class_804101a0[];
extern char w3d_class_8040eff0[];
extern char w3d_class_80410e70[];
extern char w3d_class_8040e468[];
extern char w3d_class_8040fcb8[];
extern char w3d_class_8040fbb8[];
extern char w3d_class_8040f6e8[];
extern char w3d_class_8040ee30[];
extern char w3d_class_80410b88[];
extern char w3d_class_8040fdf0[];
extern char w3d_class_8040f280[];
extern char w3d_class_8040f340[];
extern char w3d_class_8040e968[];
extern char w3d_class_8040f1a8[];
extern char w3d_class_8040e6c8[];
extern char w3d_class_80410008[];
extern char w3d_class_8040e748[];
extern char w3d_class_8040e358[];
extern "C" void w3d_d26b_spawn_message_80096db4(Ptr32<Self> self, Ptr32<Message> m)
{
    Ptr32<Source> obj = w3d_lookup_80164fc8(m->id);
    if (!obj) return;
    Ptr32<void> type = obj->vtable->type(obj);
    if (type == w3d_type_80360c60 || type == w3d_type_80360690 || type == w3d_type_80361470 || type == w3d_type_80360240 || type == w3d_type_803608a0 || type == w3d_type_80360210) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_804101a0);
        w3d_assign_800e8fb4(n, Held(obj->held192));
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 192) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360480) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040eff0);
        w3d_assign_800e8fb4(n, Held(obj->held192));
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 192) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_803615f0) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_80410e70);
        w3d_set_80133d64(n, obj->value584);
        w3d_post_80164514(w3d_system_804b178c, n, obj->id);
    }
    else if (type == w3d_type_8035fe20) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040e468);
        Vec3 a(obj->a);
        Vec3 b(obj->b);
        w3d_set_pair_8002e558(n, &a, &b);
        w3d_post_80164514(w3d_system_804b178c, n, self->id);
    }
    else if (type == w3d_type_80360c30) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040fcb8);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360ba0) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040fbb8);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360840) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040f6e8);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360390) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040ee30);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80361440) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_80410b88);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360cc0) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040fdf0);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_803605d0) {
        Ptr32<Spawn5> n = (Ptr32<Spawn5>)w3d_service_forward_8020b680(w3d_class_8040f280);
        n->id = obj->id;
        n->flag = obj->flag;
        n->triple = *(Ptr32<Copy3>)obj->triple;
        Ptr32<void> sys = w3d_system_804b178c;
        n->value56 = obj->value132;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360660) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040f340);
        *(Ptr32<int>)(n + 36) = obj->id;
        w3d_assign_8009afe8(n, Held(obj->held28));
        w3d_post_80164514(w3d_system_804b178c, n, obj->id);
    }
    else if (type == w3d_type_803600c0) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040e968);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360540) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040f1a8);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_8035ff70) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040e6c8);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 32) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80360d50) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_80410008);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
    else if (type == w3d_type_80361620) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040e748);
        w3d_post_80164514(w3d_system_804b178c, n, obj->id);
    }
    else if (type == w3d_type_8035fd90) {
        Ptr32<char> n = (Ptr32<char>)w3d_service_forward_8020b680(w3d_class_8040e358);
        Ptr32<void> sys = w3d_system_804b178c;
        *(Ptr32<int>)(n + 28) = obj->id;
        w3d_post_80164514(sys, n, obj->id);
    }
}


