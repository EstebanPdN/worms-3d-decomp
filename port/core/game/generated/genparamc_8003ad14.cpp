#include "w3d_ptr.h"
#line 1 "genparamc_8003ad14.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): look up a named spawn point
 * in a copy of a global vector of groups; fall back to a default position. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern "C" Ptr32<void> memcpy(...);
extern "C" Ptr32<void> fn_80212fd4(unsigned int);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" int fn_802ef234(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern "C" void fn_8003af00(Ptr32<void>, Ptr32<const char>);
extern "C" char lbl_803742c8[];
struct W3dVec3 {
    float x, y, z;
    W3dVec3() {}
    W3dVec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct W3dPtrVector {
    Ptr32<Ptr32<void>> first;
    Ptr32<Ptr32<void>> last;
    Ptr32<Ptr32<void>> end_of_storage;
    unsigned int size() const { return last - first; }
    Ptr32<void> at(unsigned int index) const { return *(Ptr32<Ptr32<void>>)((Ptr32<char>)first + (index << 2)); }
    ~W3dPtrVector() { if (first) fn_802134fc(first); }
};
struct W3dString_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> W3dString_8020bb54(Ptr32<W3dU> w3d_p) : W3dString_8020bb54((const char *)w3d_p.get()) {}
 W3dString_8020bb54(const char *);
    ~W3dString_8020bb54() { fn_8020c5c4(this); fn_80341588(this); }
};
extern W3dPtrVector lbl_8043bb64;
extern W3dVec3 lbl_8045e788;
static inline W3dVec3 item_position(Ptr32<void> item)
{
    W3dVec3 &p = FIELD(item, W3dVec3, 4);
    return W3dVec3(p.x, p.y, p.z);
}
extern "C" void fn_8004a930(Ptr32<void>, Ptr32<const char>);
extern "C" char lbl_80376f30[];
extern "C" void fn_8012568c(Ptr32<void>, Ptr32<const char>);
extern "C" char lbl_8039ba80[];

extern "C" void w3d_find_spawn_point_8003ad14(Ptr32<void> self, Ptr32<const char> name)
{
    W3dPtrVector groups;
    unsigned int bytes = (Ptr32<char>)lbl_8043bb64.last - (Ptr32<char>)lbl_8043bb64.first;
    Ptr32<Ptr32<void>> storage = (Ptr32<Ptr32<void>>)fn_80212fd4(bytes);
    groups.first = storage;
    groups.last = (Ptr32<Ptr32<void>>)((Ptr32<char>)storage + bytes);
    groups.end_of_storage = (Ptr32<Ptr32<void>>)((Ptr32<char>)storage + bytes);
    memcpy(w3d::VA(storage), w3d::VA(lbl_8043bb64.first), bytes);
    for (unsigned int i = 0; i < groups.size(); i++) {
        W3dPtrVector &items = FIELD(groups.at(i), W3dPtrVector, 20);
        for (unsigned int j = 0; j < items.size(); j++) {
            W3dString_8020bb54 label(FIELD(items.at(j), const char *, 60));
            if (fn_802ef234(label.text, name) == 0) {
                FIELD(self, W3dVec3, 28) = item_position(items.at(j));
                return;
            }
        }
    }
    fn_8003af00(self, lbl_803742c8);
    fn_8003af00(self, name);
    FIELD(self, W3dVec3, 28) = lbl_8045e788;
}

extern "C" void w3d_find_spawn_point_8004a608(Ptr32<void> self, Ptr32<const char> name)
{
    W3dPtrVector groups;
    unsigned int bytes = (Ptr32<char>)lbl_8043bb64.last - (Ptr32<char>)lbl_8043bb64.first;
    Ptr32<Ptr32<void>> storage = (Ptr32<Ptr32<void>>)fn_80212fd4(bytes);
    groups.first = storage;
    groups.last = (Ptr32<Ptr32<void>>)((Ptr32<char>)storage + bytes);
    groups.end_of_storage = (Ptr32<Ptr32<void>>)((Ptr32<char>)storage + bytes);
    memcpy(w3d::VA(storage), w3d::VA(lbl_8043bb64.first), bytes);
    for (unsigned int i = 0; i < groups.size(); i++) {
        W3dPtrVector &items = FIELD(groups.at(i), W3dPtrVector, 20);
        for (unsigned int j = 0; j < items.size(); j++) {
            W3dString_8020bb54 label(FIELD(items.at(j), const char *, 60));
            if (fn_802ef234(label.text, name) == 0) {
                FIELD(self, W3dVec3, 40) = item_position(items.at(j));
                return;
            }
        }
    }
    fn_8004a930(self, lbl_80376f30);
    fn_8004a930(self, name);
    FIELD(self, W3dVec3, 40) = lbl_8045e788;
}

extern "C" void w3d_find_spawn_point_801254a0(Ptr32<void> self, Ptr32<const char> name)
{
    W3dPtrVector groups;
    unsigned int bytes = (Ptr32<char>)lbl_8043bb64.last - (Ptr32<char>)lbl_8043bb64.first;
    Ptr32<Ptr32<void>> storage = (Ptr32<Ptr32<void>>)fn_80212fd4(bytes);
    groups.first = storage;
    groups.last = (Ptr32<Ptr32<void>>)((Ptr32<char>)storage + bytes);
    groups.end_of_storage = (Ptr32<Ptr32<void>>)((Ptr32<char>)storage + bytes);
    memcpy(w3d::VA(storage), w3d::VA(lbl_8043bb64.first), bytes);
    for (unsigned int i = 0; i < groups.size(); i++) {
        W3dPtrVector &items = FIELD(groups.at(i), W3dPtrVector, 20);
        for (unsigned int j = 0; j < items.size(); j++) {
            W3dString_8020bb54 label(FIELD(items.at(j), const char *, 60));
            if (fn_802ef234(label.text, name) == 0) {
                FIELD(self, W3dVec3, 28) = item_position(items.at(j));
                return;
            }
        }
    }
    fn_8012568c(self, lbl_8039ba80);
    fn_8012568c(self, name);
    FIELD(self, W3dVec3, 28) = lbl_8045e788;
}


