#include "w3d_ptr.h"
#line 1 "d24h_light_free_800c1004.cpp"
// Light release (Worms 3D GameCube PAL, 0x800c1004, 600 bytes).
//
// Lights are 60-byte records in a vector. The id lists use the same hand-made
// array template as d24h_names_add_800c47f8, including its byte-as-count
// growth. Names are inferred.

extern "C" Ptr32<void> fn_80212fd4(unsigned);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> capacity;
    Ptr32<T> begin() { return start; }
    Ptr32<T> end() { return finish; }
    void Grow() {
        unsigned size = (Ptr32<char>)finish - (Ptr32<char>)start;
        int want = size + 1;
        int more = size + size / 2;
        unsigned bytes = Max(want, more) * sizeof(T);
        Ptr32<T> fresh = (Ptr32<T>)fn_80212fd4(bytes);
        if (start) {
            fn_802eee50(fresh, start, Min(bytes, size));
            fn_802134fc(start);
        }
        start = fresh;
        finish = (Ptr32<T>)((Ptr32<char>)fresh + size);
        capacity = (Ptr32<T>)((Ptr32<char>)fresh + bytes);
    }
    void Add(const T &x) {
        if (finish == capacity) Grow();
        *finish = x;
        finish++;
    }
    void Erase(Ptr32<T> pos) {
        Ptr32<T> next = pos + 1;
        if (next != finish) { Ptr32<T> last = finish - 1; fn_802eee50(pos, next, (Ptr32<char>)last - (Ptr32<char>)pos); }
        finish--;
    }
};
struct Obj;
struct ObjVt { Ptr32<void> u[4]; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *o) { if (p) p->vt->release(p); p = o; }
};
struct Entry {
    unsigned char u0[12];
    Ref sound;
    Ref mesh;
    unsigned char u20[4];
    unsigned char volume; char w3d_tag_rest[3];
    unsigned char active;
    unsigned char u29[31];
};
struct Entries { Ptr32<Entry> start; Ptr32<Entry> finish; Ptr32<Entry> end_of_storage; int alloc; Entry &operator[](unsigned i) { return start[i]; } };
extern Entries lbl_8043c384;
struct Ids : Array<unsigned short> { int alloc __attribute__((aligned(__alignof__(Array<unsigned short>)))); };
extern Ids lbl_8043c394;
extern Ids lbl_8043c3a0;
extern int lbl_804aada8;
struct Bank;
struct BankVt { Ptr32<void> u[49]; Ptr32<void (Ptr32<Bank>, Ptr32<const char>, int)> load; };
struct Bank { Ptr32<BankVt> vt; };
struct Sound { unsigned char u[116]; Ptr32<Bank> bank; };
extern Ptr32<Sound> lbl_804b17ec;
extern const char lbl_80382f88[];
extern "C" int fn_803442b4(Ptr32<char>, Ptr32<const char>, ...);
extern "C" void w3d_d24h_light_free_800c1004(unsigned short id) {
    if (lbl_804aada8 == 0) return;
    lbl_8043c384[id].active = 0;
    lbl_8043c384[id].mesh = 0;
    lbl_8043c384[id].sound = 0;
    lbl_8043c394.Add(id);
    char name[32];
    Ptr32<Bank> bank = lbl_804b17ec->bank;
    Ptr32<BankVt> vt = bank->vt;
    fn_803442b4(name, lbl_80382f88, id);
    vt->load(bank, name, lbl_8043c384[id].volume);
    for (Ptr32<unsigned short> it = lbl_8043c3a0.begin(); it != lbl_8043c3a0.end(); it++) {
        if (*it == id) {
            lbl_8043c3a0.Erase(it);
            return;
        }
    }
}


