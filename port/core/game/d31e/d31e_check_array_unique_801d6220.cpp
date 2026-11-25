#include "w3d_ptr.h"
#line 1 "d31e_check_array_unique_801d6220.cpp"
// (Worms 3D GameCube PAL, 0x801d6220).
//
// Validates an object array property: for every pair of elements logs an
// error and clears the result when both have the same class, and logs a
// warning when one class derives from the other (walking parents at +20),
// each with lines naming both elements. Returns 1 when no exact duplicate
// was found. Names are inferred; the strings at 0x803af3c8.. are the log
// formats.

struct Class { char u[20]; Ptr32<Class> parent; };
struct Object { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Object2v0Ev")), w3d_r_v1() __asm__(W3D_SYM("_ZN6Object2v1Ev")), w3d_r_v2() __asm__(W3D_SYM("_ZN6Object2v2Ev")); Ptr32<Class> w3d_r_GetClass() __asm__(W3D_SYM("_ZN6Object8GetClassEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Class> GetClass() { return ((Ptr32<Class> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Object; };
struct Prop { Ptr32<const char> name; };
struct Item {
    Ptr32<Prop> prop;
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Item2v0Ev")), w3d_r_v1() __asm__(W3D_SYM("_ZN4Item2v1Ev")), w3d_r_v2() __asm__(W3D_SYM("_ZN4Item2v2Ev")), w3d_r_v3() __asm__(W3D_SYM("_ZN4Item2v3Ev")), w3d_r_v4() __asm__(W3D_SYM("_ZN4Item2v4Ev")), w3d_r_v5() __asm__(W3D_SYM("_ZN4Item2v5Ev"));
    Ptr32<Ptr32<Object>> w3d_r_get(Ptr32<Object>, Ptr32<unsigned int>) __asm__(W3D_SYM("_ZN4Item3getEP6ObjectPj"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Ptr32<Object>> get(Ptr32<Object> w3d_a0, Ptr32<unsigned int> w3d_a1) { return ((Ptr32<Ptr32<Object>> (*)(w3d_u32, Ptr32<Object>, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Item; };
struct Log;
extern "C" Ptr32<Item> w3d_s21_vector_get_801e9db8(Ptr32<Class>, int);
extern "C" Ptr32<const char> w3d_auto_801ffea8(Ptr32<Class>);
extern "C" void w3d_cx16b_stream_format_801d6000(Ptr32<Log>, Ptr32<const char>, ...);
extern const char s_same[], s_kind[], s_first[], s_second[];
static inline bool IsA(Ptr32<Class> c, Ptr32<Class> base)
{
    while (c != base) {
        Ptr32<Class> p = c->parent;
        if (c == p) return false;
        c = p;
    }
    return true;
}
extern "C" int w3d_d31e_check_array_unique_801d6220(Ptr32<Log> log, int index, Ptr32<Object> obj)
{
    int ok = 1;
    Ptr32<Item> item = w3d_s21_vector_get_801e9db8(obj->GetClass(), index);
    unsigned n;
    Ptr32<Ptr32<Object>> arr = item->get(obj, &n);
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = i + 1; j < n; j++) {
            if (arr[j]->GetClass() == arr[i]->GetClass()) {
                ok = 0;
                w3d_cx16b_stream_format_801d6000(log, s_same, w3d::VA(item->prop->name), w3d::VA(w3d_auto_801ffea8(obj->GetClass())), w3d::VA(obj), i, j);
                w3d_cx16b_stream_format_801d6000(log, s_first, w3d::VA(w3d_auto_801ffea8(arr[i]->GetClass())), w3d::VA(arr[i]));
                w3d_cx16b_stream_format_801d6000(log, s_second, w3d::VA(w3d_auto_801ffea8(arr[i]->GetClass())), w3d::VA(arr[j]));
            } else if (IsA(arr[j]->GetClass(), arr[i]->GetClass()) || IsA(arr[i]->GetClass(), arr[j]->GetClass())) {
                w3d_cx16b_stream_format_801d6000(log, s_kind, w3d::VA(item->prop->name), w3d::VA(w3d_auto_801ffea8(obj->GetClass())), w3d::VA(obj), i, j);
                w3d_cx16b_stream_format_801d6000(log, s_first, w3d::VA(w3d_auto_801ffea8(arr[i]->GetClass())), w3d::VA(arr[i]));
                w3d_cx16b_stream_format_801d6000(log, s_second, w3d::VA(w3d_auto_801ffea8(arr[i]->GetClass())), w3d::VA(arr[j]));
            }
        }
    }
    return ok;
}


