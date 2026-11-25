#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d22d_count_categories_8017d60c.cpp"
/* GWMP8P rev0 0x8017d60c: per-category pool census.
   Zeroes 1920 category counters, lets five pool counters fill them
   (0x80170b2c, 0x8017453c, 0x8017f540, 0x8018a800, 0x80187768), then for
   every non-empty category copies the name string returned by the
   category object's slot 17 (+68) into a temporary that is destroyed at
   once (its use was compiled out). The string copy follows the admitted
   reference-counted string shape (0x8020c5c0, ++*0x80341884, destructor
   0x8020c5c4 then 0x80341588). Category table at +24 is a partial view;
   names are inferred. */
extern "C" {
Ptr32<void> memset(Ptr32<void>,int,unsigned);
void fn_80170b2c(Ptr32<int>);
void fn_8017453c(Ptr32<int>);
void fn_8017f540(Ptr32<int>);
void fn_8018a800(Ptr32<int>);
void fn_80187768(Ptr32<int>);
void fn_8020c5c0(Ptr32<void>);
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
Ptr32<unsigned short> fn_80341884(Ptr32<void>);
}
struct D22dString {
    Ptr32<char> text;
    D22dString(const D22dString &other) { fn_8020c5c0(this); text=other.text; ++*fn_80341884(this); }
    ~D22dString() { fn_8020c5c4(this); fn_80341588(this); }
};
struct D22dCategory;
struct D22dCategoryTable { Ptr32<void> slots[17]; Ptr32<w3d::Ref32<const D22dString>(Ptr32<D22dCategory>)> name; };
struct D22dCategory { Ptr32<D22dCategoryTable> vtable; };
struct D22dPools { unsigned char pad[24]; Ptr32<D22dCategory> categories[1920]; };
extern "C" int w3d_d22d_count_categories_8017d60c(Ptr32<D22dPools> self)
{
    // Port (v29): un contador por hueco de la tabla nativa (4096); estático para no gastar 16 KB de pila.
    static int counts[4096];
    unsigned short i;
    memset(counts,0,sizeof counts);
    fn_80170b2c(counts);
    fn_8017453c(counts);
    fn_8017f540(counts);
    fn_8018a800(counts);
    fn_80187768(counts);
    i=0;
    do {
        if (counts[i]) {
            Ptr32<D22dCategory> category=((Ptr32<D22dCategory> *)w3d_restab_slots())[i];
            D22dString name(category->vtable->name(category));
        }
        i++;
    } while (i<w3d_restab_cap());
    return 0;
}


