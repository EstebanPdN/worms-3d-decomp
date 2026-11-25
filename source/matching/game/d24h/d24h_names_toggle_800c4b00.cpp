// Name list toggle (Worms 3D GameCube PAL, 0x800c4b00, 568 bytes).
//
// Same 33-byte array as d24h_names_add_800c47f8, including the growth that
// uses a byte size as a count. The list's inline begin, end and size read
// through the object pointer; the partial redundancy pass then produces the
// original's register copy around the erase. Names are inferred.

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
    Name *begin() { return start; }
    Name *end() { return finish; }
    unsigned size() { return finish - start; }
    void Grow() {
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
    }
    void Add(const Name &x) {
        if (finish == capacity) Grow();
        *finish = x;
        finish++;
    }
    void Erase(Name *pos) {
        Name *next = pos + 1;
        if (next != finish) { Name *last = finish - 1; fn_802eee50(pos, next, (char *)last - (char *)pos); }
        finish--;
    }
};
extern "C" int fn_802ef234(const char *, const char *);
struct Owner { int u0; Names names; };
extern "C" int w3d_d24h_names_toggle_800c4b00(Owner *self, const char *name) {
    Name rec;
    fn_802efbfc(rec.text, name, 33);
    bool found = false;
    if (self->names.size() != 0) {
        for (Name *it = self->names.begin(); it != self->names.end(); ) {
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
