// GWMP8P rev0 0x80042004. Commentary destructor: sets the table, clears the
// string queue at +72 and the id list at +96, clears the current-commentary
// global, then the members die in reverse order: 32 held interfaces at
// +124..+248, the id list, the string queue and the base. The queue clear is
// the same vector erase as 0x80044638. Field and class names are inferred;
// the words between members are partial views.

struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" void w3d_storage_release_802134fc(void *);
struct String {
    const char *text;
    String &operator=(const String &o);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
inline void Distance(String *first, String *last, int &n) { n += last - first; }
inline String *CopyRange(String *first, String *last, String *result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
struct FalseType {};
inline void DestroyAux(String *first, String *last, const FalseType &)
{
    for (; first != last; ++first) first->~String();
}
inline void DestroyValue(String *first, String *last, String *) { DestroyAux(first, last, FalseType()); }
inline void DestroyRange(String *first, String *last) { DestroyValue(first, last, first); }
struct StringVector {
    String *first, *last, *end_;
    String *erase(String *from, String *to)
    {
        String *e = CopyRange(to, last, from);
        DestroyRange(e, last);
        last = e;
        return from;
    }
    void clear() { erase(first, last); }
    ~StringVector() { DestroyRange(first, last); if (first) w3d_storage_release_802134fc(first); }
};
struct IntVector {
    int *first, *last, *end_;
    void clear() { last = first; }
    ~IntVector() { if (first) w3d_storage_release_802134fc(first); }
};


typedef void (*Slot)(void *);
struct Iface { Slot *table; };
struct Ref { Iface *p; ~Ref() { if (p) p->table[4](p); } };
extern int g_804aa984;
extern void *vt_8040e938[];
struct CommentaryBase_8015ff2c { void **table; char unknown4[68]; ~CommentaryBase_8015ff2c(); };
struct Commentary_80042004 : CommentaryBase_8015ff2c {
    ~Commentary_80042004();
    StringVector queue;
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
