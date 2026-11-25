#include "w3d_ptr.h"
#line 1 "d30g_weapon_slots_80068eac.cpp"
/* Worms 3D GameCube PAL 0x80068eac. Copies a weapon property record's eight slot names to the first person view: for each slot clears its two state flags and names, then takes the slot's two names from the record and marks a slot that has them. Field names are inferred from the original instructions; strings and globals are external views of original data. */
struct String;
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" void string_release_header_8020bb2c(Ptr32<void>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 String &operator=(const char *);
    void operator=(const String &o) {
        ((Ptr32<unsigned short>)o.text)[-3]++;
        Ptr32<char> old = text;
        Ptr32<void> header = old - 6;
        if (--((Ptr32<unsigned short>)old)[-3] == 0)
            string_release_header_8020bb2c(header);
        text = o.text;
    }
    bool operator!=(const char *t) const { return strcmp(text, t) != 0; }
};
struct Prop { char u0[44]; String n1; char u48[52]; String n2; String s6b, s7b, s5b, s4b, s3b, s2b, s1b; String s6a, s7a, s5a, s4a, s3a; };
struct Slots {
    char u0[120]; int on[10]; String names[10]; int a[10]; int on2[10]; String names2[10]; int b[10];
};
extern const char s_8037a894[];
#define PAIR(x, y) a = p->x; b = p->y; break;
extern "C" void w3d_d30g_weapon_slots_80068eac(Ptr32<Slots> self, Ptr32<Prop> p)
{
    String a;
    String b;
    a = s_8037a894;
    b = s_8037a894;
    int i = 0;
    int n = 0;
    for (; i != 8; i = ++n) {
        self->on[i] = 0;
        *(Ptr32<String>)((Ptr32<char>)self + ((i << 2) + 160)) = s_8037a894;
        self->a[i] = -1;
        self->on2[i] = 0;
        *(Ptr32<String>)((Ptr32<char>)self + ((i << 2) + 280)) = s_8037a894;
        self->b[i] = -1;
        switch (i) {
        case 1: PAIR(n1, s1b)
        case 2: PAIR(n2, s2b)
        case 3: PAIR(s3a, s3b)
        case 4: PAIR(s4a, s4b)
        case 5: PAIR(s5a, s5b)
        case 7: PAIR(s7a, s7b)
        case 6: PAIR(s6a, s6b)
        default:
            a = s_8037a894;
            b = s_8037a894;
        }
        if (a != s_8037a894) {
            self->on[i] = 1;
            self->names[i] = a;
        }
        if (b != s_8037a894) {
            self->on2[i] = 1;
            self->names2[i] = b;
        }
    }
}


