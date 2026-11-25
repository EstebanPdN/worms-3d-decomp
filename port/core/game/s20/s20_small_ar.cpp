#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
extern "C" {
#line 1 "s20_small_ar.c"
/* Vector set, table clearing and item registration. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj { Ptr32<Ptr32<void>> vtable; } S20Obj;
typedef Ptr32<void (Ptr32<S20Obj>)> S20Call0;
extern int fn_80178b5c(Ptr32<char>);
extern void fn_8020bd38(Ptr32<char>, int);
extern int lbl_804a8dd8[];
extern int fn_8017ce10(Ptr32<char>, Ptr32<unsigned char>);
extern int fn_8017d288(Ptr32<char>, Ptr32<unsigned char>);

int w3d_s20_set_vector_if_changed_80178fa4(Ptr32<char> self, Ptr32<S20V3> value) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 4);
    Ptr32<S20V3> current = (Ptr32<S20V3>)(owner + 28);
    int same = 0;
    if (value->x == current->x && value->y == current->y)
        same = value->z == current->z;
    if (same != 0)
        return 1;
    *(Ptr32<S20V3>)(*(Ptr32<Ptr32<char>>)(self + 4) + 28) = *value;
    fn_80178b5c(self);
    return 0;
}

int w3d_s20_clear_tables_8017ccdc(Ptr32<char> self) {
    unsigned int i;
    unsigned int j;
    Ptr32<Ptr32<S20Obj>> slot;
    Ptr32<S20Obj> empty;
    Ptr32<char> name;
    Ptr32<char> id;
    short none;
    // Port (v29): los huecos están en la tabla nativa (core/native/tabla_recursos.cpp).
    Ptr32<S20Obj> *native = (Ptr32<S20Obj> *)w3d_restab_slots(); (void)slot;
    for (i = 0, empty = 0; i < w3d_restab_cap(); i++) {
        if (native[i] != 0)
            ((S20Call0)native[i]->vtable[4])(native[i]);
        native[i] = empty;
    }
    j = 0;
    none = -1;
    id = self + 7708;
    name = self + 7704;
    for (; j < 256; j++) {
        fn_8020bd38(name, 0);
        *(Ptr32<short>)id = none;
        name += 8;
        id += 8;
    }
    *(Ptr32<int>)(self + 9752) = 0;
    return 0;
}

int w3d_s20_register_item_8017cd80(Ptr32<char> self, Ptr32<unsigned char> item) {
    int result;
    if (lbl_804a8dd8[*item] != 0)
        return 0x80004005;
    lbl_804a8dd8[*item] = 1;
    if (*(Ptr32<int>)(self + 9828) != 0)
        result = fn_8017ce10(self, item);
    else
        result = fn_8017d288(self, item);
    lbl_804a8dd8[*item] = 1;
    return result;
}

}
