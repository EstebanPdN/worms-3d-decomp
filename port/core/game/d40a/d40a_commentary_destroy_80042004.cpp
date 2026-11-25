#include "w3d_ptr.h"
#line 1 "d40a_commentary_destroy_80042004.cpp"
// GWMP8P rev0 0x80042004. Commentary destructor: sets the table, clears the
// string queue at +72 and the id list at +96, clears the current-commentary
// global, then the members die in reverse order: 32 held interfaces at
// +124..+248, the id list, the string queue and the base. The queue clear is
// the same vector erase as 0x80044638. Field and class names are inferred;
// the words between members are partial views.

struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" void w3d_storage_release_802134fc(Ptr32<void>);
struct String {
    Ptr32<const char> text;
    String &operator=(const String &o);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
inline void Distance(Ptr32<String> first, Ptr32<String> last, int &n) { n += last - first; }
inline Ptr32<String> CopyRange(Ptr32<String> first, Ptr32<String> last, Ptr32<String> result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
struct FalseType { char w3d_empty; };
inline void DestroyAux(Ptr32<String> first, Ptr32<String> last, const FalseType &)
{
    for (; first != last; ++first) first->~String();
}
inline void DestroyValue(Ptr32<String> first, Ptr32<String> last, Ptr32<String>) { DestroyAux(first, last, FalseType()); }
inline void DestroyRange(Ptr32<String> first, Ptr32<String> last) { DestroyValue(first, last, first); }
struct StringVector {
    Ptr32<String> first; Ptr32<String> last; Ptr32<String> end_;
    Ptr32<String> erase(Ptr32<String> from, Ptr32<String> to)
    {
        Ptr32<String> e = CopyRange(to, last, from);
        DestroyRange(e, last);
        last = e;
        return from;
    }
    void clear() { erase(first, last); }
    ~StringVector() { DestroyRange(first, last); if (first) w3d_storage_release_802134fc(first); }
};
struct IntVector {
    Ptr32<int> first; Ptr32<int> last; Ptr32<int> end_;
    void clear() { last = first; }
    ~IntVector() { if (first) w3d_storage_release_802134fc(first); }
};


typedef Ptr32<void (Ptr32<void>)> Slot;
struct Iface { Ptr32<Slot> table; };
struct Ref { Ptr32<Iface> p; ~Ref() { if (p) p->table[4](p); } };
extern int g_804aa984;
extern Ptr32<void> vt_8040e938[];
struct CommentaryBase_8015ff2c { Ptr32<Ptr32<void>> table; char unknown4[68]; ~CommentaryBase_8015ff2c(); };
struct Commentary_80042004 : CommentaryBase_8015ff2c {
    ~Commentary_80042004();
    StringVector queue __attribute__((aligned(__alignof__(CommentaryBase_8015ff2c))));
    int unknown84[3];
    IntVector ids;
    int unknown108[4];
    Ref r0;
    Ref r1;
    Ref r2;
    Ref r3;
    Ref r4;
    Ref r5;
    Ref r6;
    Ref r7;
    Ref r8;
    Ref r9;
    Ref r10;
    Ref r11;
    Ref r12;
    Ref r13;
    Ref r14;
    Ref r15;
    Ref r16;
    Ref r17;
    Ref r18;
    Ref r19;
    Ref r20;
    Ref r21;
    Ref r22;
    Ref r23;
    Ref r24;
    Ref r25;
    Ref r26;
    Ref r27;
    Ref r28;
    Ref r29;
    Ref r30;
    Ref r31;
};
Commentary_80042004::~Commentary_80042004()
{
    table = vt_8040e938;
    queue.clear();
    ids.clear();
    g_804aa984 = 0;
}


