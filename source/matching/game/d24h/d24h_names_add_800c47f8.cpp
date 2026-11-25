// Name list insert (Worms 3D GameCube PAL, 0x800c47f8, 644 bytes).
//
// A hand-written array template of 33-byte names. Growth computes its size
// in bytes and uses it as an element count, so capacity grows 33 times too
// fast; this is the original behaviour. The index is a local set before the
// intervening calls, which leaves the original's unfolded shift. Names are
// inferred.

extern "C" void *fn_80212fd4(unsigned);
extern "C" void fn_802134fc(void *);
extern "C" void *fn_802eee50(void *, const void *, unsigned, ...);
extern "C" void *fn_802eeef4(void *, const void *, unsigned);
extern "C" char *fn_802efbfc(char *, const char *, unsigned);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Name;
extern "C" void fn_80344360(Name *);
struct Name {
    char text[33];
    Name() { fn_80344360(this); }
};
struct Names {
    Name *start, *finish, *capacity;
    void InsertAt(int index, const Name &x) {
        Name *pos = start + index;
        if (finish == capacity) {
            unsigned size = (char *)finish - (char *)start;
            int want = size + 1;
            int more = size + size / 2;
            unsigned bytes = Max(want, more) * 33;
            Name *fresh = (Name *)fn_80212fd4(bytes);
            if (start) {
                fn_802eee50(fresh, start, Min(bytes, size));
                fn_802134fc(start);
            }
            start = fresh;
            finish = (Name *)((char *)fresh + size);
            capacity = (Name *)((char *)fresh + bytes);
            pos = fresh + index;
        }
        if (pos == finish) {
            *pos = x;
            finish++;
        } else {
            Name copy = x;
            fn_802eeef4(pos + 1, pos, (char *)finish - (char *)pos);
            finish++;
            *pos = copy;
        }
    }
};
struct Owner { int u0; Names names; };
extern "C" int w3d_d24h_names_add_800c47f8(Owner *self, const char *name) {
    int index = 0;
    Name rec;
    fn_802efbfc(rec.text, name, 33);
    self->names.InsertAt(index, rec);
    return 0;
}
