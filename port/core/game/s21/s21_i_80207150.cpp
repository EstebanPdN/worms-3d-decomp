#include "w3d_ptr.h"
#line 1 "s21_i_80207150.cpp"
struct S21Named;
struct S21NamedMethods { Ptr32<void (void)> reserved[5]; Ptr32<Ptr32<const char> (Ptr32<S21Named>)> name; };
struct S21Named { Ptr32<S21NamedMethods> methods; };
struct S21NamedList { char pad[20]; int count; int reserved; Ptr32<Ptr32<S21Named>> items; };
extern int fn_802ef074(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<S21Named> w3d_s21_find_named_80207150(Ptr32<S21NamedList> list, Ptr32<const char> key)
{
    Ptr32<Ptr32<S21Named>> item = list->items;
    Ptr32<Ptr32<S21Named>> end = item + list->count;
    for (; item != end; item++) {
        Ptr32<const char> name = (*item)->methods->name(*item);
        if (fn_802ef074(name, key) == 0)
            return *item;
    }
    return 0;
}


