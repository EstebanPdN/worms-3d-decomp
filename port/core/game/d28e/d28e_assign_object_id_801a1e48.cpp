#include "w3d_ptr.h"
#line 1 "d28e_assign_object_id_801a1e48.cpp"
// (Worms 3D GameCube PAL, 0x801a1e48).
//
// Assign a slot id to the object registered at the given index. The byte
// table at 0x8045ce40 is resized to the object table size for kinds 2 and 3;
// a kind 3 object with no id gets the largest id plus one, unless it is the
// special object at 0x803649b4. It creates the object's instance, stores it
// in the vector at +20, publishes the count at 0x804b18d8, registers it with
// each linked item through 0x801a2754 and attaches it to the named service.

extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
extern "C" Ptr32<void> memmove_802eeef4(Ptr32<void>, Ptr32<const void>, unsigned);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
template<class T> struct Slots {
    Ptr32<char> begin; Ptr32<char> end; Ptr32<char> cap;
    unsigned size() const { return (Ptr32<T>)end - (Ptr32<T>)begin; }
    T &operator[](unsigned i) { return ((Ptr32<T>)begin)[i]; }
    void erase(Ptr32<char> first, Ptr32<char> last) {
        unsigned gone = last - first;
        memcpy_802eee50(first, last, end - last);
        end -= gone;
    }
    void insert(Ptr32<char> pos, unsigned n, const T &x) {
        unsigned at = (Ptr32<T>)pos - (Ptr32<T>)begin;
        if (pos + n * sizeof(T) > cap) {
            unsigned used = end - begin;
            unsigned left = (Ptr32<T>)cap - (Ptr32<T>)pos; unsigned c = cap - begin;
            unsigned bytes = v_max((int)(c + (n - left)), (int)(c + (c >> 1))) * sizeof(T);
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
            pos = begin + at * sizeof(T);
        }
        if (pos == end) {
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)(end + i * sizeof(T)) = x;
            end += n * sizeof(T);
        } else {
            T y = x;
            memmove_802eeef4(pos + n * sizeof(T), pos, end - pos);
            end += n * sizeof(T);
            for (unsigned i = 0; i < n; i++) *(Ptr32<T>)pos = y;
        }
    }
    void resize(unsigned n, const T &x = T()) {
        if (n < size()) erase(begin + n * sizeof(T), end);
        else insert(end, n - size(), x);
    }
};
struct Obj;
struct Sub { char u[4]; unsigned char flags; char w3d_tag_rest[3]; };
struct Service;
struct ServiceTable { char u44[44]; Ptr32<void (Ptr32<Service>, Ptr32<Obj>)> attach; char u48[44]; Ptr32<Ptr32<Service> (Ptr32<Service>, Ptr32<char>)> find; };
struct Service { Ptr32<ServiceTable> table; };
struct ObjTable { char u12[12]; Ptr32<void (Ptr32<Obj>)> init; char u16[72]; Ptr32<Ptr32<Obj> (Ptr32<Obj>)> create; };
struct Obj {
    Ptr32<ObjTable> table; Sub sub; char u12[20]; unsigned int :16; unsigned int kind:4; unsigned int :2; unsigned int index:10;
    int Type() const { return kind; }
    unsigned Index() const { return index; }
};
extern Slots <Ptr32<Obj> > lbl_8045e080;
extern Slots<unsigned char> lbl_8045ce40;
extern Obj lbl_803649b4[];
extern char lbl_804143e0[];
extern unsigned lbl_804b18d8;
struct Self { char u[20]; Slots <Ptr32<Obj> > items; };
struct Link { char u[32]; Ptr32<Link> next; };
extern Ptr32<Link> lbl_804ab750;
extern "C" Ptr32<unsigned char> r23c_max_byte_80352828(Ptr32<unsigned char>, Ptr32<unsigned char>);
extern "C" int w3d_auto_801ffea8(Ptr32<Obj>);
extern "C" void fn_801a2754(Ptr32<Link>, Ptr32<Obj>, Ptr32<Obj>);
extern "C" Ptr32<Service> w3d_auto_8020b648();
extern "C" int w3d_d28e_assign_object_id_801a1e48(Ptr32<Self> self, unsigned idx)
{
    Ptr32<Obj> o = lbl_8045e080[idx];
    unsigned count = 0;
    if (o->Type() == 3 || o->Type() == 2) count = lbl_8045e080.size();
    if (count) lbl_8045ce40.resize(count);
    if (o->Type() == 3) {
        unsigned at = o->Index();
        if (lbl_8045ce40[at] == 0 && o != lbl_803649b4) {
            unsigned id = *r23c_max_byte_80352828((Ptr32<unsigned char>)lbl_8045ce40.begin, (Ptr32<unsigned char>)lbl_8045ce40.end) ;
            lbl_8045ce40[at] = ++id;
            w3d_auto_801ffea8(o);
            self->items.resize(id + 1);
            Ptr32<Obj> c = o->table->create(o);
            c->table->init(c);
            Ptr32<Sub> sub = &c->sub; sub->flags |= 1;
            self->items[id] = c;
            lbl_804b18d8 = id + 1;
            for (Ptr32<Link> p = lbl_804ab750; p; p = p->next) fn_801a2754(p, o, self->items[id]);
            Ptr32<char> name = lbl_804143e0; Ptr32<Service> s = w3d_auto_8020b648(); s = s->table->find(s, name); s->table->attach(s, c);
        }
    }
    return 0;
}


