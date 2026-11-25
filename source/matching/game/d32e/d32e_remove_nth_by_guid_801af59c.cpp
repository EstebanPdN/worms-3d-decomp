// (Worms 3D GameCube PAL, 0x801af59c).
//
// Removes the index-th record whose 16-byte id equals the key from a vector
// of 24-byte records (interface, id, name): returns E_FAIL if there are too
// few, releases the interface, copies later records down one place and
// destroys the last name.

extern "C" int memcmp(const void *, const void *, unsigned);
struct Unk { virtual void v0(); virtual void AddRef(); virtual int Release(); };
struct Guid { int w[4]; };
extern "C" void w3d_string_release_header(void *);
struct Str;
extern "C" void w3d_string_base_finish(Str *);
extern "C" void w3d_string_release(Str *);
struct Str {
    char *p;
    ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
    Str &operator=(const Str &o) {
        ++*(unsigned short *)(o.p - 6);
        unsigned short *h = (unsigned short *)(p - 6);
        if (--*h == 0) w3d_string_release_header(h);
        p = o.p;
        return *this;
    }
};
struct Rec { Unk *obj; Guid id; Str name; };
static inline Rec *Copy(Rec *f, Rec *l, Rec *d) {
    for (int n = l - f; n > 0; --n) { *d = *f; ++f; ++d; }
    return d;
}
struct Vec {
    Rec *first, *last;
    Rec *end() { return last; }
    void erase(Rec *pos) {
        if (pos + 1 != last) Copy(pos + 1, last, pos);
        --last;
        last->~Rec();
    }
};
struct Owner { char u0[20]; Vec list; };
extern "C" int w3d_d32e_remove_nth_by_guid_801af59c(Owner *self, const void *key, unsigned index)
{
    Rec *it = self->list.first;
    for (unsigned i = 0; i <= index; i++) {
        for (; it != self->list.end(); it++)
            if (memcmp(it->id.w, key, 16) == 0) break;
        if (it == self->list.end()) return 0x80004005;
        if (i != index) it++;
    }
    it->obj->Release();
    self->list.erase(it);
    return 0;
}
