#include "w3d_ptr.h"
#line 1 "d24h_names_toggle_800c4b00.cpp"
// Name list toggle (Worms 3D GameCube PAL, 0x800c4b00, 568 bytes).
//
// Same 33-byte array as d24h_names_add_800c47f8, including the growth that
// uses a byte size as a count. The list's inline begin, end and size read
// through the object pointer; the partial redundancy pass then produces the
// original's register copy around the erase. Names are inferred.

extern "C" Ptr32<void> fn_80212fd4(unsigned);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
extern "C" Ptr32<void> fn_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<char> fn_802efbfc(Ptr32<char>, Ptr32<const char>, unsigned);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Name;
extern "C" void fn_80344360(Ptr32<Name>);
struct Name {
    char text[33];
    Name() { fn_80344360(this); }
};
struct Names {
    Ptr32<Name> start; Ptr32<Name> finish; Ptr32<Name> capacity;
    Ptr32<Name> begin() { return start; }
    Ptr32<Name> end() { return finish; }
    unsigned size() { return finish - start; }
    void Grow() {
        unsigned size = (Ptr32<char>)finish - (Ptr32<char>)start;
        int want = size + 1;
        int more = size + size / 2;
        unsigned bytes = Max(want, more) * 33;
        Ptr32<Name> fresh = (Ptr32<Name>)fn_80212fd4(bytes);
        if (start) {
            fn_802eee50(fresh, start, Min(bytes, size));
            fn_802134fc(start);
        }
        start = fresh;
        finish = (Ptr32<Name>)((Ptr32<char>)fresh + size);
        capacity = (Ptr32<Name>)((Ptr32<char>)fresh + bytes);
    }
    void Add(const Name &x) {
        if (finish == capacity) Grow();
        *finish = x;
        finish++;
    }
    void Erase(Ptr32<Name> pos) {
        Ptr32<Name> next = pos + 1;
        if (next != finish) { Ptr32<Name> last = finish - 1; fn_802eee50(pos, next, (Ptr32<char>)last - (Ptr32<char>)pos); }
        finish--;
    }
};
extern "C" int fn_802ef234(Ptr32<const char>, Ptr32<const char>);
struct Owner { int u0; Names names; };
extern "C" int w3d_d24h_names_toggle_800c4b00(Ptr32<Owner> self, Ptr32<const char> name) {
    Name rec;
    fn_802efbfc(rec.text, name, 33);
    bool found = false;
    if (self->names.size() != 0) {
        for (Ptr32<Name> it = self->names.begin(); it != self->names.end(); ) {
            if (!found) {
                if (fn_802ef234(it->text, name) == 0) found = true;
                it++;
            } else {
                self->names.Erase(it);
            }
        }
    }
    if (!found) self->names.Add(rec);
    return 0;
}


