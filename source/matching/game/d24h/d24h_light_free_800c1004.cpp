// Light release (Worms 3D GameCube PAL, 0x800c1004, 600 bytes).
//
// Lights are 60-byte records in a vector. The id lists use the same hand-made
// array template as d24h_names_add_800c47f8, including its byte-as-count
// growth. Names are inferred.

extern "C" void *fn_80212fd4(unsigned);
extern "C" void fn_802134fc(void *);
extern "C" void *fn_802eee50(void *, const void *, unsigned, ...);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *capacity;
    T *begin() { return start; }
    T *end() { return finish; }
    void Grow() {
        unsigned size = (char *)finish - (char *)start;
        int want = size + 1;
        int more = size + size / 2;
        unsigned bytes = Max(want, more) * sizeof(T);
        T *fresh = (T *)fn_80212fd4(bytes);
        if (start) {
            fn_802eee50(fresh, start, Min(bytes, size));
            fn_802134fc(start);
        }
        start = fresh;
        finish = (T *)((char *)fresh + size);
        capacity = (T *)((char *)fresh + bytes);
    }
    void Add(const T &x) {
        if (finish == capacity) Grow();
        *finish = x;
        finish++;
    }
    void Erase(T *pos) {
        T *next = pos + 1;
        if (next != finish) { T *last = finish - 1; fn_802eee50(pos, next, (char *)last - (char *)pos); }
        finish--;
    }
};
struct Obj;
struct ObjVt { void *u[4]; void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    void operator=(Obj *o) { if (p) p->vt->release(p); p = o; }
};
struct Entry {
    unsigned char u0[12];
    Ref sound;
    Ref mesh;
    unsigned char u20[7];
    unsigned char volume;
    unsigned char active;
    unsigned char u29[31];
};
struct Entries { Entry *start, *finish, *end_of_storage; int alloc; Entry &operator[](unsigned i) { return start[i]; } };
extern Entries lbl_8043c384;
struct Ids : Array<unsigned short> { int alloc; };
extern Ids lbl_8043c394;
extern Ids lbl_8043c3a0;
extern int lbl_804aada8;
struct Bank;
struct BankVt { void *u[49]; void (*load)(Bank *, const char *, int); };
struct Bank { BankVt *vt; };
struct Sound { unsigned char u[116]; Bank *bank; };
extern Sound *lbl_804b17ec;
extern const char lbl_80382f88[];
extern "C" int fn_803442b4(char *, const char *, ...);
extern "C" void w3d_d24h_light_free_800c1004(unsigned short id) {
    if (lbl_804aada8 == 0) return;
    lbl_8043c384[id].active = 0;
    lbl_8043c384[id].mesh = 0;
    lbl_8043c384[id].sound = 0;
    lbl_8043c394.Add(id);
    char name[32];
    Bank *bank = lbl_804b17ec->bank;
    BankVt *vt = bank->vt;
    fn_803442b4(name, lbl_80382f88, id);
    vt->load(bank, name, lbl_8043c384[id].volume);
    for (unsigned short *it = lbl_8043c3a0.begin(); it != lbl_8043c3a0.end(); it++) {
        if (*it == id) {
            lbl_8043c3a0.Erase(it);
            return;
        }
    }
}
