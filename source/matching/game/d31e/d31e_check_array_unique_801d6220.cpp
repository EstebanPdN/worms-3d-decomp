// (Worms 3D GameCube PAL, 0x801d6220).
//
// Validates an object array property: for every pair of elements logs an
// error and clears the result when both have the same class, and logs a
// warning when one class derives from the other (walking parents at +20),
// each with lines naming both elements. Returns 1 when no exact duplicate
// was found. Names are inferred; the strings at 0x803af3c8.. are the log
// formats.

struct Class { char u[20]; Class *parent; };
struct Object { virtual void v0(), v1(), v2(); virtual Class *GetClass(); };
struct Prop { const char *name; };
struct Item {
    Prop *prop;
    virtual void v0(), v1(), v2(), v3(), v4(), v5();
    virtual Object **get(Object *, unsigned *);
};
struct Log;
extern "C" Item *w3d_s21_vector_get_801e9db8(Class *, int);
extern "C" const char *w3d_auto_801ffea8(Class *);
extern "C" void w3d_cx16b_stream_format_801d6000(Log *, const char *, ...);
extern const char s_same[], s_kind[], s_first[], s_second[];
static inline bool IsA(Class *c, Class *base)
{
    while (c != base) {
        Class *p = c->parent;
        if (c == p) return false;
        c = p;
    }
    return true;
}
extern "C" int w3d_d31e_check_array_unique_801d6220(Log *log, int index, Object *obj)
{
    int ok = 1;
    Item *item = w3d_s21_vector_get_801e9db8(obj->GetClass(), index);
    unsigned n;
    Object **arr = item->get(obj, &n);
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = i + 1; j < n; j++) {
            if (arr[j]->GetClass() == arr[i]->GetClass()) {
                ok = 0;
                w3d_cx16b_stream_format_801d6000(log, s_same, item->prop->name, w3d_auto_801ffea8(obj->GetClass()), obj, i, j);
                w3d_cx16b_stream_format_801d6000(log, s_first, w3d_auto_801ffea8(arr[i]->GetClass()), arr[i]);
                w3d_cx16b_stream_format_801d6000(log, s_second, w3d_auto_801ffea8(arr[i]->GetClass()), arr[j]);
            } else if (IsA(arr[j]->GetClass(), arr[i]->GetClass()) || IsA(arr[i]->GetClass(), arr[j]->GetClass())) {
                w3d_cx16b_stream_format_801d6000(log, s_kind, item->prop->name, w3d_auto_801ffea8(obj->GetClass()), obj, i, j);
                w3d_cx16b_stream_format_801d6000(log, s_first, w3d_auto_801ffea8(arr[i]->GetClass()), arr[i]);
                w3d_cx16b_stream_format_801d6000(log, s_second, w3d_auto_801ffea8(arr[i]->GetClass()), arr[j]);
            }
        }
    }
    return ok;
}
