// (Worms 3D GameCube PAL, 0x801a1e48).
//
// Assign a slot id to the object registered at the given index. The byte
// table at 0x8045ce40 is resized to the object table size for kinds 2 and 3;
// a kind 3 object with no id gets the largest id plus one, unless it is the
// special object at 0x803649b4. It creates the object's instance, stores it
// in the vector at +20, publishes the count at 0x804b18d8, registers it with
// each linked item through 0x801a2754 and attaches it to the named service.

extern "C" void *alloc_80212fd4(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned, ...);
extern "C" void *memmove_802eeef4(void *, const void *, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    char *begin, *end, *cap;
    unsigned size() const { return (T *)end - (T *)begin; }
    T &operator[](unsigned i) { return ((T *)begin)[i]; }
    void erase(char *first, char *last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(char *pos, unsigned n, const T &x) {
        unsigned at = (T *)pos - (T *)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned left = (T *)cap - (T *)pos; unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - left)), (int)(c + (c >> 1))) * sizeof(T);
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(T *)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(T *)pos = y;
        }
    }
    void resize(unsigned n, const T &x = T()) {
        if (n < size()) erase(begin + n * sizeof(T), end);
        else insert(end, n - size(), x);
    }
};
struct Obj;
struct Sub { char u[7]; unsigned char flags; };
struct Service;
struct ServiceTable { char u44[44]; void (*attach)(Service *, Obj *); char u48[44]; Service *(*find)(Service *, char *); };
struct Service { ServiceTable *table; };
struct ObjTable { char u12[12]; void (*init)(Obj *); char u16[72]; Obj *(*create)(Obj *); };
struct Obj {
    ObjTable *table; Sub sub; char u12[20]; unsigned index : 10; unsigned : 2; unsigned kind : 4; unsigned : 16;
    int Type() const { return kind; }
    unsigned Index() const { return index; }
};
extern Slots<Obj *> lbl_8045e080;
extern Slots<unsigned char> lbl_8045ce40;
extern Obj lbl_803649b4[];
extern char lbl_804143e0[];
extern unsigned lbl_804b18d8;
struct Self { char u[20]; Slots<Obj *> items; };
struct Link { char u[32]; Link *next; };
extern Link *lbl_804ab750;
extern "C" unsigned char *r23c_max_byte_80352828(unsigned char *, unsigned char *);
extern "C" int w3d_auto_801ffea8(Obj *);
extern "C" void fn_801a2754(Link *, Obj *, Obj *);
extern "C" Service *w3d_auto_8020b648();
extern "C" int w3d_d28e_assign_object_id_801a1e48(Self *self, unsigned idx)
{
    Obj *o = lbl_8045e080[idx];
    unsigned count = 0;
    if (o->Type() == 3 || o->Type() == 2) count = lbl_8045e080.size();
    if (count) lbl_8045ce40.resize(count);
    if (o->Type() == 3) {
        unsigned at = o->Index();
        if (lbl_8045ce40[at] == 0 && o != lbl_803649b4) {
            unsigned id = *r23c_max_byte_80352828((unsigned char *)lbl_8045ce40.begin, (unsigned char *)lbl_8045ce40.end) ;
            lbl_8045ce40[at] = ++id;
            w3d_auto_801ffea8(o);
            self->items.resize(id + 1);
            Obj *c = o->table->create(o);
            c->table->init(c);
            Sub *sub = &c->sub; sub->flags |= 1;
            self->items[id] = c;
            lbl_804b18d8 = id + 1;
            for (Link *p = lbl_804ab750; p; p = p->next) fn_801a2754(p, o, self->items[id]);
            char *name = lbl_804143e0; Service *s = w3d_auto_8020b648(); s = s->table->find(s, name); s->table->attach(s, c);
        }
    }
    return 0;
}
