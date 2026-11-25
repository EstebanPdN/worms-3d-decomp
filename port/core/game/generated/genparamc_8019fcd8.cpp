#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_8019fcd8.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (third session of the day, later batch). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
typedef Ptr32<Ptr32<void> (Ptr32<void>)> W3dGetState;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
float fn_802e86d4(float);
float fn_802e88ac(float);
Ptr32<Ptr32<void>> fn_802ce9d8(Ptr32<void>, int);
void fn_8019fdd8(Ptr32<void>);
int fn_802ce5ec(Ptr32<void>, int);
void fn_8019fe10(Ptr32<void>);

int w3d_push_lua_object_8019fcd8(Ptr32<void> self, Ptr32<void> object)
{
    Ptr32<void> owner = FIELD(self, void *, 20);
    Ptr32<void> state = (*(Ptr32<W3dGetState>)(*(Ptr32<Ptr32<char>>)owner + 36))(owner);
    Ptr32<Ptr32<void>> slot = fn_802ce9d8(state, 8);
    fn_8019fdd8(self);
    *slot = object;
    VCALL(object, 12);
    fn_802ce5ec(state, -2);
    return 0;
}

int w3d_push_lua_object_8019fd58(Ptr32<void> self, Ptr32<void> object)
{
    Ptr32<void> owner = FIELD(self, void *, 20);
    Ptr32<void> state = (*(Ptr32<W3dGetState>)(*(Ptr32<Ptr32<char>>)owner + 36))(owner);
    Ptr32<Ptr32<void>> slot = fn_802ce9d8(state, 8);
    fn_8019fe10(self);
    *slot = object;
    VCALL(object, 12);
    fn_802ce5ec(state, -2);
    return 0;
}

void w3d_rotate_rows_y_801f61a0(Ptr32<float> rows, float angle)
{
    float c = fn_802e86d4(angle);
    float s = fn_802e88ac(angle);
    float spare[4];
    Ptr32<float> row = rows;
    int i;
    for (i = 0; i < 3; i++) {
        float x = row[0];
        float z = row[2];
        row[0] = x * c + z * s;
        row[2] = z * c - x * s;
        row += 3;
    }
}

}
