#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "terra_only_c5_check_801d60cc.c"
typedef unsigned int u32;
typedef struct Obj Obj;
struct Obj { Ptr32<Ptr32<void>> v; };
extern Ptr32<void> fn_801e9db8(Ptr32<void>, int);
extern Ptr32<void> fn_801ffea8(Ptr32<void>);
extern int fn_801d6000(Ptr32<void>, Ptr32<const char>, ...);
extern char lbl_803af340[];
extern char lbl_803af394[];

int terra_only_c5_check_801d60cc(Ptr32<void> out, int index, Ptr32<Obj> obj)
{
    u32 count, i, j;
    int ok;
    Ptr32<void> type;
    Ptr32<void> container;
    Ptr32<Ptr32<Obj>> items;
    i = 0;
    ok = 1;
    type = ((Ptr32<Ptr32<void> (Ptr32<Obj>)>)obj->v[5])(obj);
    container = fn_801e9db8(type, index);
    items = ((Ptr32<Ptr32<Ptr32<Obj>> (Ptr32<void>, Ptr32<Obj>, Ptr32<u32>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)((Ptr32<char>)container + 4))[8])(container, obj, &count);
    while (i < count) {
        j = i + 1;
        while (j < count) {
            if (items[j] == items[i]) {
                Ptr32<void> name = **(Ptr32<Ptr32<Ptr32<void>>>)container;
                ok = 0;
                type = ((Ptr32<Ptr32<void> (Ptr32<Obj>)>)obj->v[5])(obj);
                fn_801d6000(out, lbl_803af340, w3d::VA(name), w3d::VA(fn_801ffea8(type)), w3d::VA(obj), i, j);
                type = ((Ptr32<Ptr32<void> (Ptr32<Obj>)>)items[i]->v[5])(items[i]);
                fn_801d6000(out, lbl_803af394, w3d::VA(fn_801ffea8(type)), w3d::VA(items[i]));
            }
            j++;
        }
        i++;
    }
    return ok;
}

}
