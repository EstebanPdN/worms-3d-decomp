#include "w3d_ptr.h"
#line 1 "d24h_names_add_800c47f8.cpp"
// Name list insert (Worms 3D GameCube PAL, 0x800c47f8, 644 bytes).
//
// A hand-written array template of 33-byte names. Growth computes its size
// in bytes and uses it as an element count, so capacity grows 33 times too
// fast; this is the original behaviour. The index is a local set before the
// intervening calls, which leaves the original's unfolded shift. Names are
// inferred.

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
    void InsertAt(int index, const Name &x) {
        Ptr32<Name> pos = start + index;
        if (finish == capacity) {
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
            pos = fresh + index;
        }
        if (pos == finish) {
            *pos = x;
            finish++;
        } else {
            Name copy = x;
            fn_802eeef4(pos + 1, pos, (Ptr32<char>)finish - (Ptr32<char>)pos);
            finish++;
            *pos = copy;
        }
    }
};
struct Owner { int u0; Names names; };
extern "C" int w3d_d24h_names_add_800c47f8(Ptr32<Owner> self, Ptr32<const char> name) {
    int index = 0;
    Name rec;
    fn_802efbfc(rec.text, name, 33);
    self->names.InsertAt(index, rec);
    return 0;
}


