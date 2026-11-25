// d29c: 0x800da4e4. Part tint: reads the active index, gets the part resource by descriptor, locks its colour array and writes the entry's colour as floats (byte over 255), then starts the part's effect once. Names are inferred; classes are partial views.
struct Object;
struct ObjectVtable { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Header { char u0[4]; unsigned short kind; char u6[18]; int count; unsigned short locks; char u30[2]; char data[1]; };
struct ArrayRef {
    Header *header;
    void *lock();
};
extern "C" void *reserve_801ef048(ArrayRef *, int, int, int);
inline void *ArrayRef::lock() {
    Header *h = header;
    int kind = h->kind;
    if (kind == 1 && kind == h->count) {
        ++h->locks;
        return h->data;
    }
    return reserve_801ef048(this, 1, 12, 0);
}
struct Tint : Object { char u4[136]; ArrayRef colours; };
struct Held {
    Held(const Held &);
    Tint *value;
    Held() : value(0) {}
    Held(Tint *next) : value(next) { if (value) value->vtable->retain(value); }
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Tint *next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Key { const char *name; };
struct Vec { float x, y, z; };
struct Colour { unsigned char r, g, b, a; };
struct Part { char u0[32]; void *h32; void *effect; };
extern char active_8038976c[], part_8038977c[];
extern int group_804aae7c;
extern "C" int readInt_800fc1f0(Key *, unsigned *);
extern "C" int query_800fc6dc(unsigned);
extern "C" int readRes_800fc1b0(Key *, Object **);
extern "C" void *identity_80341584(Object *);
extern "C" Tint *cast_80179598(void *, Descriptor_80178474 *);
extern "C" void * entry_800fd388(...);
extern "C" void *empty_80343584(void *);
extern "C" void *forward_800e5cf0(void *, int, const char *, int, int);
extern "C" void d29c_part_team_tint_800da4e4(Part *self) {
    unsigned count;
    {
        Key k;
        k.name = active_8038976c;
        readInt_800fc1f0(&k, &count);
    }
    if (count <= 15) {
        query_800fc6dc(count);
        {
            Descriptor_80178474 descriptor;
            Handle handle;
            handle.value = 0;
            {
                Key k;
                k.name = part_8038977c;
                readRes_800fc1b0(&k, &handle.value);
            }
            Held current;
            {
                Held acquired(cast_80179598(identity_80341584(handle.value), &descriptor));
                current.assign(acquired.value);
            }
            Vec *v = (Vec *)current.value->colours.lock();
            Colour c;
            entry_800fd388(&c, count);
            float r = c.r / 255.0f;
            float g = c.g / 255.0f;
            float b = c.b / 255.0f;
            v->x = r;
            v->z = b;
            v->y = g;
        }
        if (self->effect == 0) self->effect = forward_800e5cf0(empty_80343584(self->h32), group_804aae7c, part_8038977c, -1, 0);
    }
}
