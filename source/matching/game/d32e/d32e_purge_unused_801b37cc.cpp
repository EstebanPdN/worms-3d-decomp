// (Worms 3D GameCube PAL, 0x801b37cc).
//
// Garbage collects a cache: optionally releases the lists first, then
// repeatedly scans the three object lists and removes every object whose
// reference count is one (probed with AddRef and Release), together with its
// parallel name where it has one, until a full pass removes nothing. Returns
// 0.

extern "C" void *memmove(void *, const void *, unsigned);
struct Obj { virtual void v0(); virtual void AddRef(); virtual int Release(); };
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
static inline Str *Copy(Str *f, Str *l, Str *d) {
    for (int n = l - f; n > 0; --n) { *d = *f; ++f; ++d; }
    return d;
}
struct Names {
    Str *first, *last;
    void erase(Str *pos) {
        if (pos + 1 != last) Copy(pos + 1, last, pos);
        --last;
        last->~Str();
    }
};
struct Objs {
    Obj **first, **last;
    Obj **end() { return last; }
    void erase(Obj **pos) {
        Obj **n = pos + 1;
        if (n != last) {
            if (last != n) memmove(pos, n, (char *)last - (char *)n);
        }
        --last;
    }
};
struct Arr;
extern "C" void f4c_erase_80210dd8(Arr *, Obj **, Obj **);
struct Arr { int count; int u4; Obj **data; Obj **begin() { return data; } void Erase(Obj **p) { f4c_erase_80210dd8(this, p, p + 1); } };
struct Mgr;
extern "C" void w3d_d25e_release_lists_801b4140(Mgr *);
struct Mgr {
    char u0[28];
    Names n1; char u36[8];
    Objs a; char u52[8];
    Arr c;
    Names n2; char u80[8];
    Objs b;
};
extern "C" int w3d_d32e_purge_unused_801b37cc(Mgr *self, int purge)
{
    if (purge) w3d_d25e_release_lists_801b4140(self);
    bool changed;
    bool again;
    do {
        changed = false;
        do {
            again = false;
            Obj **it = self->a.first;
            Obj **e = self->a.end();
            for (; it != e; it++) {
                (*it)->AddRef();
                if ((*it)->Release() == 1) {
                    self->n1.erase(self->n1.first + (it - self->a.first));
                    (*it)->Release();
                    self->a.erase(it);
                    again = true;
                    changed = true;
                    break;
                }
            }
        } while (again);
        do {
            again = false;
            Obj **it = self->b.first;
            Obj **e = self->b.end();
            for (; it != e; it++) {
                (*it)->AddRef();
                if ((*it)->Release() == 1) {
                    (*it)->Release();
                    self->b.erase(it);
                    again = true;
                    changed = true;
                    break;
                }
            }
        } while (again);
        do {
            again = false;
            Obj **it = self->c.begin();
            Obj **e = self->c.begin() + self->c.count;
            for (; it != e; it++) {
                (*it)->AddRef();
                if ((*it)->Release() == 1) {
                    self->c.Erase(it);
                    self->n2.erase(self->n2.first + (it - self->c.begin()));
                    again = true;
                    changed = true;
                    break;
                }
            }
        } while (again);
    } while (changed);
    return 0;
}
