/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (third session of the day, later batch). */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethod)(void *);
typedef void *(*W3dGetState)(void *);
#define VCALL(p, o) ((*(W3dMethod *)(*(char **)(p) + (o)))(p))
float fn_802e86d4(float);
float fn_802e88ac(float);
void **fn_802ce9d8(void *, int);
void fn_8019fdd8(void *);
int fn_802ce5ec(void *, int);
void fn_8019fe10(void *);

int w3d_push_lua_object_8019fcd8(void *self, void *object)
{
    void *owner = FIELD(self, void *, 20);
    void *state = (*(W3dGetState *)(*(char **)owner + 36))(owner);
    void **slot = fn_802ce9d8(state, 8);
    fn_8019fdd8(self);
    *slot = object;
    VCALL(object, 12);
    fn_802ce5ec(state, -2);
    return 0;
}

int w3d_push_lua_object_8019fd58(void *self, void *object)
{
    void *owner = FIELD(self, void *, 20);
    void *state = (*(W3dGetState *)(*(char **)owner + 36))(owner);
    void **slot = fn_802ce9d8(state, 8);
    fn_8019fe10(self);
    *slot = object;
    VCALL(object, 12);
    fn_802ce5ec(state, -2);
    return 0;
}

void w3d_rotate_rows_y_801f61a0(float *rows, float angle)
{
    float c = fn_802e86d4(angle);
    float s = fn_802e88ac(angle);
    float spare[4];
    float *row = rows;
    int i;
    for (i = 0; i < 3; i++) {
        float x = row[0];
        float z = row[2];
        row[0] = x * c + z * s;
        row[2] = z * c - x * s;
        row += 3;
    }
}
